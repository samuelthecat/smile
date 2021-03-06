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
#include <smile/smiletypes/text/smilesymbol.h>
#include <smile/parsing/parsemessage.h>
#include <smile/parsing/internal/parsedecl.h>
#include <smile/parsing/internal/parsescope.h>

// Form: [$dot object symbol]
CompiledBlock Compiler_CompileDot(Compiler compiler, SmileList args, CompileFlags compileFlags)
{
	Int oldSourceLocation;
	CompiledBlock compiledBlock;

	oldSourceLocation = compiler->currentFunction->currentSourceLocation;
	Compiler_SetSourceLocationFromList(compiler, args);
	compiledBlock = Compiler_CompileLoadProperty(compiler, args, compileFlags);
	compiler->currentFunction->currentSourceLocation = oldSourceLocation;
	return compiledBlock;
}

// Form: [$index object index]
CompiledBlock Compiler_CompileIndex(Compiler compiler, SmileList args, CompileFlags compileFlags)
{
	Int oldSourceLocation;
	CompiledBlock compiledBlock;

	oldSourceLocation = compiler->currentFunction->currentSourceLocation;
	Compiler_SetSourceLocationFromList(compiler, args);
	compiledBlock = Compiler_CompileLoadMember(compiler, args, compileFlags);
	compiler->currentFunction->currentSourceLocation = oldSourceLocation;
	return compiledBlock;
}
