//---------------------------------------------------------------------------------------
//  Smile Programming Language Interpreter
//  Copyright 2004-2015 Sean Werkema
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

#include <smile/smiletypes/smileobject.h>
#include <smile/smiletypes/smilelist.h>
#include <smile/smiletypes/smilenull.h>
#include <smile/smiletypes/text/smilesymbol.h>

SmileNull SmileNull_Create(SmileEnv env)
{
	SmileNull smileNull = GC_MALLOC_STRUCT(struct SmileListInt);
	if (smileNull == NULL) Smile_Abort_OutOfMemory();
	smileNull->base = env->knownObjects.Object;
	smileNull->env = env;
	smileNull->kind = SMILE_KIND_NULL;
	smileNull->vtable = SmileNull_VTable;
	smileNull->a = (SmileObject)smileNull;
	smileNull->d = (SmileObject)smileNull;
	return smileNull;
}

Bool SmileNull_CompareEqual(SmileNull self, SmileObject other)
{
	UNUSED(self);
	return (other->kind == SMILE_KIND_NULL);
}

UInt32 SmileNull_Hash(SmileNull self)
{
	UNUSED(self);
	return 0;
}

void SmileNull_SetSecurity(SmileNull self, Int security)
{
	UNUSED(self);
	UNUSED(security);
	SmileEnv_ThrowException(self->env, self->env->knownSymbols.object_security_error,
		String_Format("Cannot alter security on null, which is read-only."));
}

Int SmileNull_GetSecurity(SmileNull self)
{
	UNUSED(self);
	return 0;
}

SmileObject SmileNull_GetProperty(SmileNull self, Symbol propertyName)
{
	return self->base->vtable->getProperty((SmileObject)self, propertyName);
}

void SmileNull_SetProperty(SmileNull self, Symbol propertyName, SmileObject value)
{
	UNUSED(self);
	UNUSED(propertyName);
	UNUSED(value);
	SmileEnv_ThrowException(self->env, self->env->knownSymbols.property_error,
		String_Format("Cannot set property \"%S\" on null; null is read-only.",
		SymbolTable_GetName(self->env->symbolTable, propertyName)));
}

Bool SmileNull_HasProperty(SmileNull self, Symbol propertyName)
{
	UNUSED(self);
	UNUSED(propertyName);
	return False;
}

SmileList SmileNull_GetPropertyNames(SmileNull self)
{
	return (SmileList)(self->env->knownObjects.Null);
}

Bool SmileNull_ToBool(SmileNull self)
{
	UNUSED(self);
	return False;
}

Int32 SmileNull_ToInteger32(SmileNull self)
{
	UNUSED(self);
	return 0;
}

Real64 SmileNull_ToReal64(SmileNull self)
{
	UNUSED(self);
	return 0;
}

String SmileNull_ToString(SmileNull self)
{
	UNUSED(self);
	return String_Format("null");
}

SMILE_VTABLE(SmileNull_VTable, SmileNull)
{
	SmileNull_CompareEqual,
	SmileNull_Hash,
	SmileNull_SetSecurity,
	SmileNull_GetSecurity,

	SmileNull_GetProperty,
	SmileNull_SetProperty,
	SmileNull_HasProperty,
	SmileNull_GetPropertyNames,

	SmileNull_ToBool,
	SmileNull_ToInteger32,
	SmileNull_ToReal64,
	SmileNull_ToString,
};