//---------------------------------------------------------------------------------------
//  Smile Programming Language Interpreter
//  Copyright 2004-2017 Sean Werkema
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//---------------------------------------------------------------------------------------

#include <smile/eval/compiler.h>
#include <smile/eval/compiler_internal.h>
#include <smile/smiletypes/smilelist.h>
#include <smile/smiletypes/smilepair.h>
#include <smile/smiletypes/text/smilesymbol.h>
#include <smile/parsing/parsemessage.h>
#include <smile/parsing/internal/parsedecl.h>
#include <smile/parsing/internal/parsescope.h>

// Form: [$and x y z ...]
void Compiler_CompileAnd(Compiler compiler, SmileList args)
{
	ByteCodeSegment segment = compiler->currentFunction->byteCodeSegment;
	SmileList temp;
	Int i, length;
	SmileObject condition;
	Bool not;

	Int localBfs[16];
	Int *bfs;
	Int falseOffset;
	Int jmp, jmpLabel, jmpDelta;
	Int offset;

	// Must be a well-formed expression of the form [$and x y z ...].
	if ((length = SmileList_Length(args)) <= 0) {
		Compiler_AddMessage(compiler, ParseMessage_Create(PARSEMESSAGE_ERROR, SMILE_VCALL(args, getSourceLocation),
			String_FromC("Cannot compile [and]: Expression is not well-formed.")));
		return;
	}

	// Create somewhere to store the byte-code branches, if there are a lot of them.
	if (length > 16) {
		bfs = (Int *)GC_MALLOC_ATOMIC(sizeof(Int) * length);
		if (bfs == NULL)
			Smile_Abort_OutOfMemory();
	}
	else {
		bfs = localBfs;
	}

	// Emit all of the conditionals.
	for (i = 0, temp = args; SMILE_KIND(temp) == SMILE_KIND_LIST; temp = (SmileList)temp->d, i++) {

		// Extract off any [$not] operators, and if there were any, invert the branch below.
		condition = temp->a;
		not = Compiler_StripNots(&condition);

		// Compile the next expression.
		Compiler_CompileExpr(compiler, condition);

		// If falsy, branch to result in 'false'.
		bfs[i] = EMIT0(not ? Op_Bt : Op_Bf, -1);

		// It's truthy, so keep going.
	}

	// We passed all the tests, so the result is true.
	EMIT1(Op_LdBool, +1, boolean = True);
	jmp = EMIT0(Op_Jmp, 0);

	// Now handle the falsy case.
	falseOffset = segment->numByteCodes;
	EMIT1(Op_LdBool, +1, boolean = False);

	// Add a branch target for the jump.
	jmpLabel = EMIT0(Op_Label, 0);

	// Now fill in all the branch deltas for the conditional branches.
	for (i = 0; i < length; i++) {
		FIX_BRANCH(bfs[i], falseOffset - bfs[i]);
	}

	// And fill in the branch delta for the unconditional branch.
	jmpDelta = jmpLabel - jmp;
	FIX_BRANCH(jmp, jmpDelta);
	FIX_BRANCH(jmpLabel, -jmpDelta);

	compiler->currentFunction->currentStackDepth--;	// We actually have one fewer on the stack than the automatic count.
}