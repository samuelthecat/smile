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

#include <smile/numeric/real.h>
#include <smile/smiletypes/smileobject.h>
#include <smile/smiletypes/smilehandle.h>
#include <smile/smiletypes/text/smilesymbol.h>
#include <smile/smiletypes/numeric/smileinteger64.h>
#include <smile/smiletypes/smilelist.h>
#include <smile/stringbuilder.h>
#include <smile/internal/staticstring.h>
#include <smile/smiletypes/easyobject.h>

SMILE_IGNORE_UNUSED_VARIABLES

SMILE_EASY_OBJECT_VTABLE(SmileHandle);

SmileHandle SmileHandle_Create(SmileObject base, SmileHandleEnd end, Symbol handleKind, Int32 costEstimate, void *ptr)
{
	SmileHandle smileHandleInt = GC_MALLOC_STRUCT(struct SmileHandleInt);
	if (smileHandleInt == NULL) Smile_Abort_OutOfMemory();

	smileHandleInt->base = base;
	smileHandleInt->kind = SMILE_KIND_HANDLE;
	smileHandleInt->vtable = SmileHandle_VTable;
	smileHandleInt->end = end;
	smileHandleInt->handleKind = handleKind;
	smileHandleInt->costEstimate = costEstimate;
	smileHandleInt->ptr = ptr;

	return smileHandleInt;
}

SMILE_EASY_OBJECT_READONLY_SECURITY(SmileHandle)
SMILE_EASY_OBJECT_NO_CALL(SmileHandle, "A Handle object")
SMILE_EASY_OBJECT_NO_SOURCE(SmileHandle)
SMILE_EASY_OBJECT_NO_PROPERTIES(SmileHandle)
SMILE_EASY_OBJECT_NO_UNBOX(SmileHandle)

SMILE_EASY_OBJECT_HASH(SmileHandle, (UInt32)(PtrInt)obj->ptr ^ Smile_HashOracle)
SMILE_EASY_OBJECT_TOBOOL(SmileHandle, True)
SMILE_EASY_OBJECT_TOSTRING(SmileHandle, SymbolTable_GetName(Smile_SymbolTable, obj->handleKind))

static Bool SmileHandle_CompareEqual(SmileHandle a, SmileUnboxedData aData, SmileObject b, SmileUnboxedData bData)
{
	if (SMILE_KIND(b) == SMILE_KIND_HANDLE) {
		return ((SmileHandle)a)->handleKind == ((SmileHandle)b)->handleKind
			&& ((SmileHandle)a)->ptr == ((SmileHandle)b)->ptr;
	}
	else return False;
}

static Bool SmileHandle_DeepEqual(SmileHandle a, SmileUnboxedData aData, SmileObject b, SmileUnboxedData bData, PointerSet visitedPointers)
{
	UNUSED(visitedPointers);

	if (SMILE_KIND(b) == SMILE_KIND_HANDLE) {
		return ((SmileHandle)a)->handleKind == ((SmileHandle)b)->handleKind
			&& ((SmileHandle)a)->ptr == ((SmileHandle)b)->ptr;
	}
	else return False;
}
