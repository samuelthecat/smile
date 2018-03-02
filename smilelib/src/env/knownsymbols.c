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

#include <smile/internal/staticstring.h>
#include <smile/env/knownsymbols.h>

//-------------------------------------------------------------------------------------------------
//  Special symbols.

// The twenty core special forms.
STATIC_STRING(_Set, "$set");
STATIC_STRING(_OpSet, "$opset");
STATIC_STRING(_Include, "$include");
STATIC_STRING(_If, "$if");
STATIC_STRING(_While, "$while");
STATIC_STRING(_Till, "$till");
STATIC_STRING(_Catch, "$catch");
STATIC_STRING(_Fn, "$fn");
STATIC_STRING(_Quote, "$quote");
STATIC_STRING(_Scope, "$scope");
STATIC_STRING(_Prog1, "$prog1");
STATIC_STRING(_Progn, "$progn");
STATIC_STRING(_Return, "$return");
STATIC_STRING(_Not, "$not");
STATIC_STRING(_Or, "$or");
STATIC_STRING(_And, "$and");
STATIC_STRING(_Eq, "$eq");
STATIC_STRING(_Ne, "$ne");
STATIC_STRING(_New, "$new");
STATIC_STRING(_Dot, "$dot");
STATIC_STRING(_Index, "$index");
STATIC_STRING(_Is, "$is");
STATIC_STRING(_Typeof, "$typeof");

// Special keywords.
STATIC_STRING(Var_, "var");
STATIC_STRING(Const_, "const");
STATIC_STRING(Auto_, "auto");
STATIC_STRING(Keyword_, "keyword");
STATIC_STRING(If_, "if");
STATIC_STRING(Unless_, "unless");
STATIC_STRING(Then_, "then");
STATIC_STRING(Else_, "else");
STATIC_STRING(Do_, "do");
STATIC_STRING(While_, "while");
STATIC_STRING(Until_, "until");
STATIC_STRING(Till_, "till");
STATIC_STRING(When_, "when");
STATIC_STRING(Return_, "return");
STATIC_STRING(Try_, "try");
STATIC_STRING(Catch_, "catch");
STATIC_STRING(Not_, "not");
STATIC_STRING(Or_, "or");
STATIC_STRING(And_, "and");
STATIC_STRING(New_, "new");
STATIC_STRING(Is_, "is");
STATIC_STRING(Typeof_, "typeof");

// Comparison punctuation.
STATIC_STRING(SuperEq_, "===");
STATIC_STRING(SuperNe_, "!==");
STATIC_STRING(Eq_, "==");
STATIC_STRING(Ne_, "!=");
STATIC_STRING(Lt_, "<");
STATIC_STRING(Gt_, ">");
STATIC_STRING(Le_, "<=");
STATIC_STRING(Ge_, ">=");

// Arithmetic.
STATIC_STRING(Plus_, "+");
STATIC_STRING(Minus_, "-");
STATIC_STRING(Star_, "*");
STATIC_STRING(Slash_, "/");

// Braces and brackets.
STATIC_STRING(LeftParenthesis, "(");
STATIC_STRING(RightParenthesis, ")");
STATIC_STRING(LeftBracket, "[");
STATIC_STRING(RightBracket, "]");
STATIC_STRING(LeftBrace, "{");
STATIC_STRING(RightBrace, "}");

// Other punctuation.
STATIC_STRING(Comma, ",");
STATIC_STRING(Semicolon, ";");
STATIC_STRING(Colon, ":");
STATIC_STRING(QuestionMark, "?");
STATIC_STRING(Implies, "=>");
STATIC_STRING(Caret, "^");
STATIC_STRING(AtSign, "@");
STATIC_STRING(ShiftLeft, "<<<");
STATIC_STRING(ShiftRight, ">>>");
STATIC_STRING(ArithmeticShiftLeft, "<<");
STATIC_STRING(ArithmeticShiftRight, ">>");
STATIC_STRING(RotateLeft, "<<+");
STATIC_STRING(RotateRight, "+>>");

// Special #syntax classes.
STATIC_STRING(STMT_, "STMT");
STATIC_STRING(EXPR_, "EXPR");
STATIC_STRING(CMPEXPR_, "CMPEXPR");
STATIC_STRING(ADDEXPR_, "ADDEXPR");
STATIC_STRING(MULEXPR_, "MULEXPR");
STATIC_STRING(BINARYEXPR_, "BINARYEXPR");
STATIC_STRING(RANGEEXPR_, "RANGEEXPR");
STATIC_STRING(COLONEXPR_, "COLONEXPR");
STATIC_STRING(PREFIXEXPR_, "PREFIXEXPR");
STATIC_STRING(POSTFIXEXPR_, "POSTFIXEXPR");
STATIC_STRING(CONSEXPR_, "CONSEXPR");
STATIC_STRING(DOTEXPR_, "DOTEXPR");
STATIC_STRING(TERM_, "TERM");
STATIC_STRING(NAME_, "NAME");

// The special get-member and set-member methods.
STATIC_STRING(get_member, "get-member");
STATIC_STRING(set_member, "set-member");

// Miscellaneous.
STATIC_STRING(as, "as");

Inline Symbol AddSpecialSymbol(SymbolTable symbolTable, String name, Symbol expectedValue)
{
	Symbol actualValue = SymbolTableInt_AddFast(symbolTable, name);

	if (actualValue != expectedValue) {
		Smile_Abort_FatalError(String_ToC(String_Format("Special symbols were not added to the symbol table in the correct order.  Bad symbol was: \"%S\".", name)));
	}

	return actualValue;
}

static void KnownSymbolsInt_PreloadSpecials(SymbolTable symbolTable, KnownSymbols knownSymbols)
{
	// The twenty-three core special forms.
	knownSymbols->_set = AddSpecialSymbol(symbolTable, _Set, SMILE_SPECIAL_SYMBOL__SET);
	knownSymbols->_opset = AddSpecialSymbol(symbolTable, _OpSet, SMILE_SPECIAL_SYMBOL__OPSET);
	knownSymbols->_include = AddSpecialSymbol(symbolTable, _Include, SMILE_SPECIAL_SYMBOL__INCLUDE);
	knownSymbols->_if = AddSpecialSymbol(symbolTable, _If, SMILE_SPECIAL_SYMBOL__IF);
	knownSymbols->_while = AddSpecialSymbol(symbolTable, _While, SMILE_SPECIAL_SYMBOL__WHILE);
	knownSymbols->_till = AddSpecialSymbol(symbolTable, _Till, SMILE_SPECIAL_SYMBOL__TILL);
	knownSymbols->_fn = AddSpecialSymbol(symbolTable, _Fn, SMILE_SPECIAL_SYMBOL__FN);
	knownSymbols->_quote = AddSpecialSymbol(symbolTable, _Quote, SMILE_SPECIAL_SYMBOL__QUOTE);
	knownSymbols->_scope = AddSpecialSymbol(symbolTable, _Scope, SMILE_SPECIAL_SYMBOL__SCOPE);
	knownSymbols->_prog1 = AddSpecialSymbol(symbolTable, _Prog1, SMILE_SPECIAL_SYMBOL__PROG1);
	knownSymbols->_progn = AddSpecialSymbol(symbolTable, _Progn, SMILE_SPECIAL_SYMBOL__PROGN);
	knownSymbols->_return = AddSpecialSymbol(symbolTable, _Return, SMILE_SPECIAL_SYMBOL__RETURN);
	knownSymbols->_catch = AddSpecialSymbol(symbolTable, _Catch, SMILE_SPECIAL_SYMBOL__CATCH);
	knownSymbols->_not = AddSpecialSymbol(symbolTable, _Not, SMILE_SPECIAL_SYMBOL__NOT);
	knownSymbols->_or = AddSpecialSymbol(symbolTable, _Or, SMILE_SPECIAL_SYMBOL__OR);
	knownSymbols->_and = AddSpecialSymbol(symbolTable, _And, SMILE_SPECIAL_SYMBOL__AND);
	knownSymbols->_eq = AddSpecialSymbol(symbolTable, _Eq, SMILE_SPECIAL_SYMBOL__EQ);
	knownSymbols->_ne = AddSpecialSymbol(symbolTable, _Ne, SMILE_SPECIAL_SYMBOL__NE);
	knownSymbols->_new = AddSpecialSymbol(symbolTable, _New, SMILE_SPECIAL_SYMBOL__NEW);
	knownSymbols->_dot = AddSpecialSymbol(symbolTable, _Dot, SMILE_SPECIAL_SYMBOL__DOT);
	knownSymbols->_index = AddSpecialSymbol(symbolTable, _Index, SMILE_SPECIAL_SYMBOL__INDEX);
	knownSymbols->_is = AddSpecialSymbol(symbolTable, _Is, SMILE_SPECIAL_SYMBOL__IS);
	knownSymbols->_typeof = AddSpecialSymbol(symbolTable, _Typeof, SMILE_SPECIAL_SYMBOL__TYPEOF);

	// Special keywords.
	knownSymbols->var_ = AddSpecialSymbol(symbolTable, Var_, SMILE_SPECIAL_SYMBOL_VAR);
	knownSymbols->const_ = AddSpecialSymbol(symbolTable, Const_, SMILE_SPECIAL_SYMBOL_CONST);
	knownSymbols->auto_ = AddSpecialSymbol(symbolTable, Auto_, SMILE_SPECIAL_SYMBOL_AUTO);
	knownSymbols->keyword_ = AddSpecialSymbol(symbolTable, Keyword_, SMILE_SPECIAL_SYMBOL_KEYWORD);

	knownSymbols->if_ = AddSpecialSymbol(symbolTable, If_, SMILE_SPECIAL_SYMBOL_IF);
	knownSymbols->unless_ = AddSpecialSymbol(symbolTable, Unless_, SMILE_SPECIAL_SYMBOL_UNLESS);
	knownSymbols->then_ = AddSpecialSymbol(symbolTable, Then_, SMILE_SPECIAL_SYMBOL_THEN);
	knownSymbols->else_ = AddSpecialSymbol(symbolTable, Else_, SMILE_SPECIAL_SYMBOL_ELSE);
	knownSymbols->do_ = AddSpecialSymbol(symbolTable, Do_, SMILE_SPECIAL_SYMBOL_DO);
	knownSymbols->while_ = AddSpecialSymbol(symbolTable, While_, SMILE_SPECIAL_SYMBOL_WHILE);
	knownSymbols->until_ = AddSpecialSymbol(symbolTable, Until_, SMILE_SPECIAL_SYMBOL_UNTIL);
	knownSymbols->till_ = AddSpecialSymbol(symbolTable, Till_, SMILE_SPECIAL_SYMBOL_TILL);
	knownSymbols->when_ = AddSpecialSymbol(symbolTable, When_, SMILE_SPECIAL_SYMBOL_WHEN);
	knownSymbols->return_ = AddSpecialSymbol(symbolTable, Return_, SMILE_SPECIAL_SYMBOL_RETURN);
	knownSymbols->try_ = AddSpecialSymbol(symbolTable, Try_, SMILE_SPECIAL_SYMBOL_TRY);
	knownSymbols->catch_ = AddSpecialSymbol(symbolTable, Catch_, SMILE_SPECIAL_SYMBOL_CATCH);

	knownSymbols->not_ = AddSpecialSymbol(symbolTable, Not_, SMILE_SPECIAL_SYMBOL_NOT);
	knownSymbols->or_ = AddSpecialSymbol(symbolTable, Or_, SMILE_SPECIAL_SYMBOL_OR);
	knownSymbols->and_ = AddSpecialSymbol(symbolTable, And_, SMILE_SPECIAL_SYMBOL_AND);
	knownSymbols->new_ = AddSpecialSymbol(symbolTable, New_, SMILE_SPECIAL_SYMBOL_NEW);
	knownSymbols->is_ = AddSpecialSymbol(symbolTable, Is_, SMILE_SPECIAL_SYMBOL_IS);
	knownSymbols->typeof_ = AddSpecialSymbol(symbolTable, Typeof_, SMILE_SPECIAL_SYMBOL_TYPEOF);

	// Comparison punctuation.
	knownSymbols->supereq_ = AddSpecialSymbol(symbolTable, SuperEq_, SMILE_SPECIAL_SYMBOL_SUPEREQ);
	knownSymbols->superne_ = AddSpecialSymbol(symbolTable, SuperNe_, SMILE_SPECIAL_SYMBOL_SUPERNE);
	knownSymbols->eq = AddSpecialSymbol(symbolTable, Eq_, SMILE_SPECIAL_SYMBOL_EQ);
	knownSymbols->ne = AddSpecialSymbol(symbolTable, Ne_, SMILE_SPECIAL_SYMBOL_NE);
	knownSymbols->lt = AddSpecialSymbol(symbolTable, Lt_, SMILE_SPECIAL_SYMBOL_LT);
	knownSymbols->gt = AddSpecialSymbol(symbolTable, Gt_, SMILE_SPECIAL_SYMBOL_GT);
	knownSymbols->le = AddSpecialSymbol(symbolTable, Le_, SMILE_SPECIAL_SYMBOL_LE);
	knownSymbols->ge = AddSpecialSymbol(symbolTable, Ge_, SMILE_SPECIAL_SYMBOL_GE);

	// Arithmetic.
	knownSymbols->plus = AddSpecialSymbol(symbolTable, Plus_, SMILE_SPECIAL_SYMBOL_PLUS);
	knownSymbols->minus = AddSpecialSymbol(symbolTable, Minus_, SMILE_SPECIAL_SYMBOL_MINUS);
	knownSymbols->star = AddSpecialSymbol(symbolTable, Star_, SMILE_SPECIAL_SYMBOL_STAR);
	knownSymbols->slash = AddSpecialSymbol(symbolTable, Slash_, SMILE_SPECIAL_SYMBOL_SLASH);

	// Braces and brackets.
	knownSymbols->left_parenthesis = AddSpecialSymbol(symbolTable, LeftParenthesis, SMILE_SPECIAL_SYMBOL_LEFTPARENTHESIS);
	knownSymbols->right_parenthesis = AddSpecialSymbol(symbolTable, RightParenthesis, SMILE_SPECIAL_SYMBOL_RIGHTPARENTHESIS);
	knownSymbols->left_bracket = AddSpecialSymbol(symbolTable, LeftBracket, SMILE_SPECIAL_SYMBOL_LEFTBRACKET);
	knownSymbols->right_bracket = AddSpecialSymbol(symbolTable, RightBracket, SMILE_SPECIAL_SYMBOL_RIGHTBRACKET);
	knownSymbols->left_brace = AddSpecialSymbol(symbolTable, LeftBrace, SMILE_SPECIAL_SYMBOL_LEFTBRACE);
	knownSymbols->right_brace = AddSpecialSymbol(symbolTable, RightBrace, SMILE_SPECIAL_SYMBOL_RIGHTBRACE);

	// Other punctuation.
	knownSymbols->comma = AddSpecialSymbol(symbolTable, Comma, SMILE_SPECIAL_SYMBOL_COMMA);
	knownSymbols->semicolon = AddSpecialSymbol(symbolTable, Semicolon, SMILE_SPECIAL_SYMBOL_SEMICOLON);
	knownSymbols->colon = AddSpecialSymbol(symbolTable, Colon, SMILE_SPECIAL_SYMBOL_COLON);
	knownSymbols->question_mark = AddSpecialSymbol(symbolTable, QuestionMark, SMILE_SPECIAL_SYMBOL_QUESTIONMARK);
	knownSymbols->implies = AddSpecialSymbol(symbolTable, Implies, SMILE_SPECIAL_SYMBOL_IMPLIES);
	knownSymbols->caret = AddSpecialSymbol(symbolTable, Caret, SMILE_SPECIAL_SYMBOL_CARET);
	knownSymbols->at_sign = AddSpecialSymbol(symbolTable, AtSign, SMILE_SPECIAL_SYMBOL_ATSIGN);
	knownSymbols->shift_left = AddSpecialSymbol(symbolTable, ShiftLeft, SMILE_SPECIAL_SYMBOL_SHL);
	knownSymbols->shift_right = AddSpecialSymbol(symbolTable, ShiftRight, SMILE_SPECIAL_SYMBOL_SHR);
	knownSymbols->arithmetic_shift_left = AddSpecialSymbol(symbolTable, ArithmeticShiftLeft, SMILE_SPECIAL_SYMBOL_SAL);
	knownSymbols->arithmetic_shift_right = AddSpecialSymbol(symbolTable, ArithmeticShiftRight, SMILE_SPECIAL_SYMBOL_SAR);
	knownSymbols->rotate_left = AddSpecialSymbol(symbolTable, RotateLeft, SMILE_SPECIAL_SYMBOL_ROL);
	knownSymbols->rotate_right = AddSpecialSymbol(symbolTable, RotateRight, SMILE_SPECIAL_SYMBOL_ROR);

	// Special #syntax classes.
	knownSymbols->STMT = AddSpecialSymbol(symbolTable, STMT_, SMILE_SPECIAL_SYMBOL_STMT);
	knownSymbols->EXPR = AddSpecialSymbol(symbolTable, EXPR_, SMILE_SPECIAL_SYMBOL_EXPR);
	knownSymbols->CMPEXPR = AddSpecialSymbol(symbolTable, CMPEXPR_, SMILE_SPECIAL_SYMBOL_CMPEXPR);
	knownSymbols->ADDEXPR = AddSpecialSymbol(symbolTable, ADDEXPR_, SMILE_SPECIAL_SYMBOL_ADDEXPR);
	knownSymbols->MULEXPR = AddSpecialSymbol(symbolTable, MULEXPR_, SMILE_SPECIAL_SYMBOL_MULEXPR);
	knownSymbols->BINARYEXPR = AddSpecialSymbol(symbolTable, BINARYEXPR_, SMILE_SPECIAL_SYMBOL_BINARYEXPR);
	knownSymbols->COLONEXPR = AddSpecialSymbol(symbolTable, COLONEXPR_, SMILE_SPECIAL_SYMBOL_COLONEXPR);
	knownSymbols->RANGEEXPR = AddSpecialSymbol(symbolTable, RANGEEXPR_, SMILE_SPECIAL_SYMBOL_RANGEEXPR);
	knownSymbols->PREFIXEXPR = AddSpecialSymbol(symbolTable, PREFIXEXPR_, SMILE_SPECIAL_SYMBOL_PREFIXEXPR);
	knownSymbols->POSTFIXEXPR = AddSpecialSymbol(symbolTable, POSTFIXEXPR_, SMILE_SPECIAL_SYMBOL_POSTFIXEXPR);
	knownSymbols->CONSEXPR = AddSpecialSymbol(symbolTable, CONSEXPR_, SMILE_SPECIAL_SYMBOL_CONSEXPR);
	knownSymbols->DOTEXPR = AddSpecialSymbol(symbolTable, DOTEXPR_, SMILE_SPECIAL_SYMBOL_DOTEXPR);
	knownSymbols->TERM = AddSpecialSymbol(symbolTable, TERM_, SMILE_SPECIAL_SYMBOL_TERM);
	knownSymbols->NAME = AddSpecialSymbol(symbolTable, NAME_, SMILE_SPECIAL_SYMBOL_NAME);

	knownSymbols->get_member = AddSpecialSymbol(symbolTable, get_member, SMILE_SPECIAL_SYMBOL_GET_MEMBER);
	knownSymbols->set_member = AddSpecialSymbol(symbolTable, set_member, SMILE_SPECIAL_SYMBOL_SET_MEMBER);
	knownSymbols->as = AddSpecialSymbol(symbolTable, as, SMILE_SPECIAL_SYMBOL_AS);
}

//-------------------------------------------------------------------------------------------------
//  Typename symbols.

STATIC_STRING(Actor_, "Actor");
STATIC_STRING(Array_, "Array");
STATIC_STRING(ArrayBase_, "ArrayBase");
STATIC_STRING(Bool_, "Bool");
STATIC_STRING(BoolArray_, "BoolArray");
STATIC_STRING(Char_, "Char");
STATIC_STRING(Closure_, "Closure");
STATIC_STRING(Enumerable_, "Enumerable");
STATIC_STRING(Exception_, "Exception");
STATIC_STRING(Facade_, "Facade");
STATIC_STRING(FacadeProper_, "Fa" "\xC3\xA7" "ade");
STATIC_STRING(Fn_, "Fn");
STATIC_STRING(Handle_, "Handle");
STATIC_STRING(List_, "List");
STATIC_STRING(Map_, "Map");
STATIC_STRING(MapBase_, "MapBase");
STATIC_STRING(MathException, "MathException");
STATIC_STRING(Null_, "Null");
STATIC_STRING(Object_, "Object");
STATIC_STRING(Program_, "Program");
STATIC_STRING(Random_, "Random");
STATIC_STRING(Range_, "Range");
STATIC_STRING(Regex_, "Regex");
STATIC_STRING(String_, "String");
STATIC_STRING(StringArray_, "StringArray");
STATIC_STRING(StringMap_, "StringMap");
STATIC_STRING(Symbol_, "Symbol");
STATIC_STRING(SymbolArray_, "SymbolArray");
STATIC_STRING(SymbolMap_, "SymbolMap");
STATIC_STRING(Uni_, "Uni");
STATIC_STRING(UserObject_, "UserObject");

STATIC_STRING(Number_, "Number");
STATIC_STRING(NumericArray_, "NumericArray");
STATIC_STRING(NumericRange_, "NumericRange");
STATIC_STRING(NumericMap_, "NumericMap");

STATIC_STRING(Integer_, "Integer");
STATIC_STRING(IntegerBase_, "IntegerBase");
STATIC_STRING(IntegerArrayBase_, "IntegerArrayBase");
STATIC_STRING(IntegerRange_, "IntegerRange");
STATIC_STRING(IntegerRangeBase_, "IntegerRangeBase");
STATIC_STRING(IntegerMap_, "IntegerMap");
STATIC_STRING(IntegerMapBase_, "IntegerMapBase");
STATIC_STRING(Byte_, "Byte");
STATIC_STRING(ByteArray_, "ByteArray");
STATIC_STRING(ByteRange_, "ByteRange");
STATIC_STRING(ByteMap_, "ByteMap");
STATIC_STRING(Integer16_, "Integer16");
STATIC_STRING(Integer16Array_, "Integer16Array");
STATIC_STRING(Integer16Range_, "Integer16Range");
STATIC_STRING(Integer16Map_, "Integer16Map");
STATIC_STRING(Integer32_, "Integer32");
STATIC_STRING(Integer32Array_, "Integer32Array");
STATIC_STRING(Integer32Range_, "Integer32Range");
STATIC_STRING(Integer32Map_, "Integer32Map");
STATIC_STRING(Integer64_, "Integer64");
STATIC_STRING(Integer64Array_, "Integer64Array");
STATIC_STRING(Integer64Range_, "Integer64Range");
STATIC_STRING(Integer64Map_, "Integer64Map");
STATIC_STRING(Integer128_, "Integer128");
STATIC_STRING(Integer128Array_, "Integer128Array");
STATIC_STRING(Integer128Range_, "Integer128Range");
STATIC_STRING(Integer128Map_, "Integer128Map");

STATIC_STRING(Real_, "Real");
STATIC_STRING(RealBase_, "RealBase");
STATIC_STRING(RealArrayBase_, "RealArrayBase");
STATIC_STRING(RealRange_, "RealRange");
STATIC_STRING(RealRangeBase_, "RealRangeBase");
STATIC_STRING(RealMap_, "RealMap");
STATIC_STRING(RealMapBase_, "RealMapBase");
STATIC_STRING(Real32_, "Real32");
STATIC_STRING(Real32Array_, "Real32Array");
STATIC_STRING(Real32Range_, "Real32Range");
STATIC_STRING(Real32Map_, "Real32Map");
STATIC_STRING(Real64_, "Real64");
STATIC_STRING(Real64Array_, "Real64Array");
STATIC_STRING(Real64Range_, "Real64Range");
STATIC_STRING(Real64Map_, "Real64Map");
STATIC_STRING(Real128_, "Real128");
STATIC_STRING(Real128Array_, "Real128Array");
STATIC_STRING(Real128Range_, "Real128Range");
STATIC_STRING(Real128Map_, "Real128Map");

STATIC_STRING(Float_, "Float");
STATIC_STRING(FloatBase_, "FloatBase");
STATIC_STRING(FloatArrayBase_, "FloatArrayBase");
STATIC_STRING(FloatRange_, "FloatRange");
STATIC_STRING(FloatRangeBase_, "FloatRangeBase");
STATIC_STRING(FloatMap_, "FloatMap");
STATIC_STRING(FloatMapBase_, "FloatMapBase");
STATIC_STRING(Float32_, "Float32");
STATIC_STRING(Float32Array_, "Float32Array");
STATIC_STRING(Float32Range_, "Float32Range");
STATIC_STRING(Float32Map_, "Float32Map");
STATIC_STRING(Float64_, "Float64");
STATIC_STRING(Float64Array_, "Float64Array");
STATIC_STRING(Float64Range_, "Float64Range");
STATIC_STRING(Float64Map_, "Float64Map");
STATIC_STRING(Float128_, "Float128");
STATIC_STRING(Float128Array_, "Float128Array");
STATIC_STRING(Float128Range_, "Float128Range");
STATIC_STRING(Float128Map_, "Float128Map");

static void KnownSymbolsInt_PreloadTypenames(SymbolTable symbolTable, KnownSymbols knownSymbols)
{
	knownSymbols->Actor_ = SymbolTableInt_AddFast(symbolTable, Actor_);
	knownSymbols->Array_ = SymbolTableInt_AddFast(symbolTable, Array_);
	knownSymbols->ArrayBase_ = SymbolTableInt_AddFast(symbolTable, ArrayBase_);
	knownSymbols->Bool_ = SymbolTableInt_AddFast(symbolTable, Bool_);
	knownSymbols->BoolArray_ = SymbolTableInt_AddFast(symbolTable, BoolArray_);
	knownSymbols->Char_ = SymbolTableInt_AddFast(symbolTable, Char_);
	knownSymbols->Closure = SymbolTableInt_AddFast(symbolTable, Closure_);
	knownSymbols->Enumerable_ = SymbolTableInt_AddFast(symbolTable, Enumerable_);
	knownSymbols->Exception_ = SymbolTableInt_AddFast(symbolTable, Exception_);
	knownSymbols->Facade_ = SymbolTableInt_AddFast(symbolTable, Facade_);
	knownSymbols->FacadeProper_ = SymbolTableInt_AddFast(symbolTable, FacadeProper_);
	knownSymbols->Fn_ = SymbolTableInt_AddFast(symbolTable, Fn_);
	knownSymbols->Handle_ = SymbolTableInt_AddFast(symbolTable, Handle_);
	knownSymbols->List_ = SymbolTableInt_AddFast(symbolTable, List_);
	knownSymbols->Map_ = SymbolTableInt_AddFast(symbolTable, Map_);
	knownSymbols->MapBase_ = SymbolTableInt_AddFast(symbolTable, MapBase_);
	knownSymbols->MathException = SymbolTableInt_AddFast(symbolTable, MathException);
	knownSymbols->Null_ = SymbolTableInt_AddFast(symbolTable, Null_);
	knownSymbols->Object_ = SymbolTableInt_AddFast(symbolTable, Object_);
	knownSymbols->Program_ = SymbolTableInt_AddFast(symbolTable, Program_);
	knownSymbols->Random_ = SymbolTableInt_AddFast(symbolTable, Random_);
	knownSymbols->Range_ = SymbolTableInt_AddFast(symbolTable, Range_);
	knownSymbols->Regex_ = SymbolTableInt_AddFast(symbolTable, Regex_);
	knownSymbols->String_ = SymbolTableInt_AddFast(symbolTable, String_);
	knownSymbols->StringArray_ = SymbolTableInt_AddFast(symbolTable, StringArray_);
	knownSymbols->StringMap_ = SymbolTableInt_AddFast(symbolTable, StringMap_);
	knownSymbols->Symbol_ = SymbolTableInt_AddFast(symbolTable, Symbol_);
	knownSymbols->SymbolArray_ = SymbolTableInt_AddFast(symbolTable, SymbolArray_);
	knownSymbols->SymbolMap_ = SymbolTableInt_AddFast(symbolTable, SymbolMap_);
	knownSymbols->Uni_ = SymbolTableInt_AddFast(symbolTable, Uni_);
	knownSymbols->UserObject_ = SymbolTableInt_AddFast(symbolTable, UserObject_);

	knownSymbols->Number_ = SymbolTableInt_AddFast(symbolTable, Number_);
	knownSymbols->NumericArray_ = SymbolTableInt_AddFast(symbolTable, NumericArray_);
	knownSymbols->NumericRange_ = SymbolTableInt_AddFast(symbolTable, NumericRange_);
	knownSymbols->NumericMap_ = SymbolTableInt_AddFast(symbolTable, NumericMap_);

	knownSymbols->Integer_ = SymbolTableInt_AddFast(symbolTable, Integer_);
	knownSymbols->IntegerBase_ = SymbolTableInt_AddFast(symbolTable, IntegerBase_);
	knownSymbols->IntegerArrayBase_ = SymbolTableInt_AddFast(symbolTable, IntegerArrayBase_);
	knownSymbols->IntegerRange_ = SymbolTableInt_AddFast(symbolTable, IntegerRange_);
	knownSymbols->IntegerRangeBase_ = SymbolTableInt_AddFast(symbolTable, IntegerRangeBase_);
	knownSymbols->IntegerMap_ = SymbolTableInt_AddFast(symbolTable, IntegerMap_);
	knownSymbols->IntegerMapBase_ = SymbolTableInt_AddFast(symbolTable, IntegerMapBase_);
	knownSymbols->Byte_ = SymbolTableInt_AddFast(symbolTable, Byte_);
	knownSymbols->ByteArray_ = SymbolTableInt_AddFast(symbolTable, ByteArray_);
	knownSymbols->ByteRange_ = SymbolTableInt_AddFast(symbolTable, ByteRange_);
	knownSymbols->ByteMap_ = SymbolTableInt_AddFast(symbolTable, ByteMap_);
	knownSymbols->Integer16_ = SymbolTableInt_AddFast(symbolTable, Integer16_);
	knownSymbols->Integer16Array_ = SymbolTableInt_AddFast(symbolTable, Integer16Array_);
	knownSymbols->Integer16Range_ = SymbolTableInt_AddFast(symbolTable, Integer16Range_);
	knownSymbols->Integer16Map_ = SymbolTableInt_AddFast(symbolTable, Integer16Map_);
	knownSymbols->Integer32_ = SymbolTableInt_AddFast(symbolTable, Integer32_);
	knownSymbols->Integer32Array_ = SymbolTableInt_AddFast(symbolTable, Integer32Array_);
	knownSymbols->Integer32Range_ = SymbolTableInt_AddFast(symbolTable, Integer32Range_);
	knownSymbols->Integer32Map_ = SymbolTableInt_AddFast(symbolTable, Integer32Map_);
	knownSymbols->Integer64_ = SymbolTableInt_AddFast(symbolTable, Integer64_);
	knownSymbols->Integer64Array_ = SymbolTableInt_AddFast(symbolTable, Integer64Array_);
	knownSymbols->Integer64Range_ = SymbolTableInt_AddFast(symbolTable, Integer64Range_);
	knownSymbols->Integer64Map_ = SymbolTableInt_AddFast(symbolTable, Integer64Map_);
	knownSymbols->Integer128_ = SymbolTableInt_AddFast(symbolTable, Integer128_);
	knownSymbols->Integer128Array_ = SymbolTableInt_AddFast(symbolTable, Integer128Array_);
	knownSymbols->Integer128Range_ = SymbolTableInt_AddFast(symbolTable, Integer128Range_);
	knownSymbols->Integer128Map_ = SymbolTableInt_AddFast(symbolTable, Integer128Map_);

	knownSymbols->Real_ = SymbolTableInt_AddFast(symbolTable, Real_);
	knownSymbols->RealBase_ = SymbolTableInt_AddFast(symbolTable, RealBase_);
	knownSymbols->RealArrayBase_ = SymbolTableInt_AddFast(symbolTable, RealArrayBase_);
	knownSymbols->RealRange_ = SymbolTableInt_AddFast(symbolTable, RealRange_);
	knownSymbols->RealRangeBase_ = SymbolTableInt_AddFast(symbolTable, RealRangeBase_);
	knownSymbols->RealMap_ = SymbolTableInt_AddFast(symbolTable, RealMap_);
	knownSymbols->RealMapBase_ = SymbolTableInt_AddFast(symbolTable, RealMapBase_);
	knownSymbols->Real32_ = SymbolTableInt_AddFast(symbolTable, Real32_);
	knownSymbols->Real32Array_ = SymbolTableInt_AddFast(symbolTable, Real32Array_);
	knownSymbols->Real32Range_ = SymbolTableInt_AddFast(symbolTable, Real32Range_);
	knownSymbols->Real32Map_ = SymbolTableInt_AddFast(symbolTable, Real32Map_);
	knownSymbols->Real64_ = SymbolTableInt_AddFast(symbolTable, Real64_);
	knownSymbols->Real64Array_ = SymbolTableInt_AddFast(symbolTable, Real64Array_);
	knownSymbols->Real64Range_ = SymbolTableInt_AddFast(symbolTable, Real64Range_);
	knownSymbols->Real64Map_ = SymbolTableInt_AddFast(symbolTable, Real64Map_);
	knownSymbols->Real128_ = SymbolTableInt_AddFast(symbolTable, Real128_);
	knownSymbols->Real128Array_ = SymbolTableInt_AddFast(symbolTable, Real128Array_);
	knownSymbols->Real128Range_ = SymbolTableInt_AddFast(symbolTable, Real128Range_);
	knownSymbols->Real128Map_ = SymbolTableInt_AddFast(symbolTable, Real128Map_);

	knownSymbols->Float_ = SymbolTableInt_AddFast(symbolTable, Float_);
	knownSymbols->FloatBase_ = SymbolTableInt_AddFast(symbolTable, FloatBase_);
	knownSymbols->FloatArrayBase_ = SymbolTableInt_AddFast(symbolTable, FloatArrayBase_);
	knownSymbols->FloatRange_ = SymbolTableInt_AddFast(symbolTable, FloatRange_);
	knownSymbols->FloatRangeBase_ = SymbolTableInt_AddFast(symbolTable, FloatRangeBase_);
	knownSymbols->FloatMap_ = SymbolTableInt_AddFast(symbolTable, FloatMap_);
	knownSymbols->FloatMapBase_ = SymbolTableInt_AddFast(symbolTable, FloatMapBase_);
	knownSymbols->Float32_ = SymbolTableInt_AddFast(symbolTable, Float32_);
	knownSymbols->Float32Array_ = SymbolTableInt_AddFast(symbolTable, Float32Array_);
	knownSymbols->Float32Range_ = SymbolTableInt_AddFast(symbolTable, Float32Range_);
	knownSymbols->Float32Map_ = SymbolTableInt_AddFast(symbolTable, Float32Map_);
	knownSymbols->Float64_ = SymbolTableInt_AddFast(symbolTable, Float64_);
	knownSymbols->Float64Array_ = SymbolTableInt_AddFast(symbolTable, Float64Array_);
	knownSymbols->Float64Range_ = SymbolTableInt_AddFast(symbolTable, Float64Range_);
	knownSymbols->Float64Map_ = SymbolTableInt_AddFast(symbolTable, Float64Map_);
	knownSymbols->Float128_ = SymbolTableInt_AddFast(symbolTable, Float128_);
	knownSymbols->Float128Array_ = SymbolTableInt_AddFast(symbolTable, Float128Array_);
	knownSymbols->Float128Range_ = SymbolTableInt_AddFast(symbolTable, Float128Range_);
	knownSymbols->Float128Map_ = SymbolTableInt_AddFast(symbolTable, Float128Map_);
}

//-------------------------------------------------------------------------------------------------
//  General symbols.

STATIC_STRING(a, "a");
STATIC_STRING(abs_, "abs");
STATIC_STRING(acos_, "acos");
STATIC_STRING(add_c_slashes, "add-c-slashes");
STATIC_STRING(alnum_q, "alnum?");
STATIC_STRING(alpha_q, "alpha?");
STATIC_STRING(apply, "apply");
STATIC_STRING(apply_method, "apply-method");
STATIC_STRING(arguments, "arguments");
STATIC_STRING(asin_, "asin");
STATIC_STRING(assertions, "assertions");
STATIC_STRING(assigned_name, "assigned-name");
STATIC_STRING(atan_, "atan");
STATIC_STRING(atan2_, "atan2");
STATIC_STRING(base_, "base");
STATIC_STRING(bit_not, "~");
STATIC_STRING(bit_and, "band");
STATIC_STRING(bit_or, "bor");
STATIC_STRING(bit_xor, "bxor");
STATIC_STRING(body, "body");
STATIC_STRING(bool_, "bool");
STATIC_STRING(byte_, "byte");
STATIC_STRING(byte_array, "byte-array");
STATIC_STRING(call, "call");
STATIC_STRING(call_method, "call-method");
STATIC_STRING(camelCase, "camelCase");
STATIC_STRING(CamelCase, "CamelCase");
STATIC_STRING(case_fold, "case-fold");
STATIC_STRING(case_insensitive, "case-insensitive");
STATIC_STRING(case_sensitive, "case-sensitive");
STATIC_STRING(category, "category");
STATIC_STRING(ceil_, "ceil");
STATIC_STRING(char_, "char");
STATIC_STRING(chip, "chip");
STATIC_STRING(chop, "chop");
STATIC_STRING(cident_q, "cident?");
STATIC_STRING(clip, "clip");
STATIC_STRING(clone, "clone");
STATIC_STRING(cmp, "cmp");
STATIC_STRING(code_at, "code-at");
STATIC_STRING(code_length, "code-length");
STATIC_STRING(column, "column");
STATIC_STRING(combine, "combine");
STATIC_STRING(compare, "compare");
STATIC_STRING(compare_i, "compare-i");
STATIC_STRING(compose, "compose");
STATIC_STRING(composed_q, "composed?");
STATIC_STRING(cons, "cons");
STATIC_STRING(contains, "contains");
STATIC_STRING(contains_i, "contains-i");
STATIC_STRING(context, "context");
STATIC_STRING(control_q, "control?");
STATIC_STRING(cos_, "cos");
STATIC_STRING(count, "count");
STATIC_STRING(count64, "count64");
STATIC_STRING(count_left_ones, "count-left-ones");
STATIC_STRING(count_left_zeros, "count-left-zeros");
STATIC_STRING(count_of, "count-of");
STATIC_STRING(count_of_i, "count-of-i");
STATIC_STRING(count_ones, "count-ones");
STATIC_STRING(count_right_ones, "count-right-ones");
STATIC_STRING(count_right_zeros, "count-right-zeros");
STATIC_STRING(count_zeros, "count-zeros");
STATIC_STRING(crc32, "crc32");
STATIC_STRING(create, "create");
STATIC_STRING(create_child_closure, "create-child-closure");
STATIC_STRING(d, "d");
STATIC_STRING(decompose, "decompose");
STATIC_STRING(default_, "default");
STATIC_STRING(diacritic_q, "diacritic?");
STATIC_STRING(digit_q, "digit?");
STATIC_STRING(div, "div");
STATIC_STRING(divide_by_zero, "divide-by-zero");
STATIC_STRING(does_not_understand, "does-not-understand");
STATIC_STRING(each, "each");
STATIC_STRING(end, "end");
STATIC_STRING(ends_with, "ends-with");
STATIC_STRING(ends_with_i, "ends-with-i");
STATIC_STRING(escape, "escape");
STATIC_STRING(even_q, "even?");
STATIC_STRING(eval, "eval");
STATIC_STRING(exit_, "exit");
STATIC_STRING(extend_object, "extend-object");
STATIC_STRING(extend_where_new, "extend-where-new");
STATIC_STRING(exp_, "exp");
STATIC_STRING(false_, "false");
STATIC_STRING(filename, "filename");
STATIC_STRING(filename_mode, "filename-mode");
STATIC_STRING(first, "first");
STATIC_STRING(floor_, "floor");
STATIC_STRING(fold, "fold");
STATIC_STRING(from_seed, "from-seed");
STATIC_STRING(get_object_security, "get-object-security");
STATIC_STRING(get_property, "get-property");
STATIC_STRING(handle_kind, "handle-kind");
STATIC_STRING(hash, "hash");
STATIC_STRING(has_property, "has-property");
STATIC_STRING(hex_string, "hex-string");
STATIC_STRING(hex_string_pretty, "hex-string-pretty");
STATIC_STRING(html_decode, "html-decode");
STATIC_STRING(html_encode, "html-encode");
STATIC_STRING(hyphenize, "hyphenize");
STATIC_STRING(id, "id");
STATIC_STRING(in_, "in");
STATIC_STRING(include, "include");
STATIC_STRING(index_of, "index-of");
STATIC_STRING(index_of_i, "index-of-i");
STATIC_STRING(int_, "int");
STATIC_STRING(int16_, "int16");
STATIC_STRING(int32_, "int32");
STATIC_STRING(int64_, "int64");
STATIC_STRING(int_lg, "int-lg");
STATIC_STRING(last_index_of, "last-index-of");
STATIC_STRING(last_index_of_i, "last-index-of-i");
STATIC_STRING(latin1_to_utf8, "latin1-to-utf8");
STATIC_STRING(left, "left");
STATIC_STRING(length, "length");
STATIC_STRING(letter, "letter");
STATIC_STRING(letter_q, "letter?");
STATIC_STRING(letter_lowercase, "letter-lowercase");
STATIC_STRING(letter_modifier, "letter-modifier");
STATIC_STRING(letter_other, "letter-other");
STATIC_STRING(letter_titlecase, "letter-titlecase");
STATIC_STRING(letter_uppercase, "letter-uppercase");
STATIC_STRING(lg, "lg");
STATIC_STRING(line, "line");
STATIC_STRING(list, "list");
STATIC_STRING(load, "load");
STATIC_STRING(log_, "log");
STATIC_STRING(log_domain, "log-domain");
STATIC_STRING(lower, "lower");
STATIC_STRING(lowercase, "lowercase");
STATIC_STRING(lowercase_q, "lowercase?");
STATIC_STRING(ln, "ln");
STATIC_STRING(join, "join");
STATIC_STRING(keys, "keys");
STATIC_STRING(kind, "kind");
STATIC_STRING(map, "map");
STATIC_STRING(mark, "mark");
STATIC_STRING(mark_enclosing, "mark-enclosing");
STATIC_STRING(mark_non_spacing, "mark-non-spacing");
STATIC_STRING(mark_spacing_combining, "mark-spacing-combining");
STATIC_STRING(match, "match");
STATIC_STRING(matches, "matches?");
STATIC_STRING(max, "max");
STATIC_STRING(message, "message");
STATIC_STRING(mid, "mid");
STATIC_STRING(min, "min");
STATIC_STRING(mod, "mod");
STATIC_STRING(name, "name");
STATIC_STRING(neg_q, "neg?");
STATIC_STRING(newline_q, "newline?");
STATIC_STRING(next_pow2, "next-pow2");
STATIC_STRING(normalize_diacritics, "normalize-diacritics");
STATIC_STRING(nonterminal, "nonterminal");
STATIC_STRING(nth, "nth");
STATIC_STRING(nth_cell, "nth-cell");
STATIC_STRING(null_, "null");
STATIC_STRING(number, "number");
STATIC_STRING(number_decimal_digit, "number-decimal-digit");
STATIC_STRING(number_letter, "number-letter");
STATIC_STRING(number_other, "number-other");
STATIC_STRING(numeric_q, "numeric?");
STATIC_STRING(octal_q, "octal?");
STATIC_STRING(of, "of");
STATIC_STRING(of_size, "of-size");
STATIC_STRING(offset, "offset");
STATIC_STRING(odd_q, "odd?");
STATIC_STRING(one_q, "one?");
STATIC_STRING(options, "options");
STATIC_STRING(other, "other");
STATIC_STRING(other_control, "other-control");
STATIC_STRING(other_format, "other-format");
STATIC_STRING(other_not_assigned, "other-not-assigned");
STATIC_STRING(other_private_use, "other-private-use");
STATIC_STRING(other_surrogate, "other-surrogate");
STATIC_STRING(parity, "parity");
STATIC_STRING(parse, "parse");
STATIC_STRING(parse_and_eval, "parse-and-eval");
STATIC_STRING(pattern, "pattern");
STATIC_STRING(pos_q, "pos?");
STATIC_STRING(post, "post");
STATIC_STRING(pow2_q, "pow2?");
STATIC_STRING(pre, "pre");
STATIC_STRING(primary_category, "primary-category");
STATIC_STRING(printf, "printf");
STATIC_STRING(process_id, "process-id");
STATIC_STRING(property_names, "property-names");
STATIC_STRING(punct_q, "punct?");
STATIC_STRING(punctuation, "punctuation");
STATIC_STRING(punctuation_close, "punctuation-close");
STATIC_STRING(punctuation_connector, "punctuation-connector");
STATIC_STRING(punctuation_dash, "punctuation-dash");
STATIC_STRING(punctuation_final_quote, "punctuation-final-quote");
STATIC_STRING(punctuation_initial_quote, "punctuation-initial-quote");
STATIC_STRING(punctuation_open, "punctuation-open");
STATIC_STRING(punctuation_other, "punctuation-other");
STATIC_STRING(raw_reverse, "raw-reverse");
STATIC_STRING(range_to, "range-to");
STATIC_STRING(read_append, "read-append");
STATIC_STRING(read_only, "read-only");
STATIC_STRING(read_write, "read-write");
STATIC_STRING(read_write_append, "read-write-append");
STATIC_STRING(real_, "real");
STATIC_STRING(real32_, "real32");
STATIC_STRING(real64_, "real64");
STATIC_STRING(rem, "rem");
STATIC_STRING(repeat, "repeat");
STATIC_STRING(replace, "replace");
STATIC_STRING(replacement, "replacement");
STATIC_STRING(resize, "resize");
STATIC_STRING(rest, "rest");
STATIC_STRING(reverse, "reverse");
STATIC_STRING(reverse_bits, "reverse-bits");
STATIC_STRING(reverse_bytes, "reverse-bytes");
STATIC_STRING(right, "right");
STATIC_STRING(rot_13, "rot-13");
STATIC_STRING(result, "result");
STATIC_STRING(separator, "separator");
STATIC_STRING(separator_line, "separator-line");
STATIC_STRING(separator_paragraph, "separator-paragraph");
STATIC_STRING(separator_space, "separator-space");
STATIC_STRING(set_object_security, "set-object-security");
STATIC_STRING(set_property, "set-property");
STATIC_STRING(sign, "sign");
STATIC_STRING(sin_, "sin");
STATIC_STRING(space_q, "space?");
STATIC_STRING(splice, "splice");
STATIC_STRING(split, "split");
STATIC_STRING(sprintf, "sprintf");
STATIC_STRING(sqrt_, "sqrt");
STATIC_STRING(sqrt_domain, "sqrt-domain");
STATIC_STRING(stack_trace, "stack-trace");
STATIC_STRING(start, "start");
STATIC_STRING(starts_with, "starts-with");
STATIC_STRING(starts_with_i, "starts-with-i");
STATIC_STRING(step, "step");
STATIC_STRING(stepping, "stepping");
STATIC_STRING(strip_c_slashes, "strip-c-slashes");
STATIC_STRING(string_, "string");
STATIC_STRING(studied_, "studied?");
STATIC_STRING(study, "study");
STATIC_STRING(substr, "substr");
STATIC_STRING(substring, "substring");
STATIC_STRING(symbol, "symbol");
STATIC_STRING(symbol_currency, "symbol-currency");
STATIC_STRING(symbol_math, "symbol-math");
STATIC_STRING(symbol_modifier, "symbol-modifier");
STATIC_STRING(symbol_other, "symbol-other");
STATIC_STRING(tan_, "tan");
STATIC_STRING(text, "text");
STATIC_STRING(this_, "this");
STATIC_STRING(this_closure, "this-closure");
STATIC_STRING(throw_, "throw");
STATIC_STRING(title, "title");
STATIC_STRING(titlecase, "titlecase");
STATIC_STRING(titlecase_q, "titlecase?");
STATIC_STRING(trim, "trim");
STATIC_STRING(trim_end, "trim-end");
STATIC_STRING(trim_start, "trim-start");
STATIC_STRING(true_, "true");
STATIC_STRING(type, "type");
STATIC_STRING(underscorize, "underscorize");
STATIC_STRING(unknown, "unknown");
STATIC_STRING(upper, "upper");
STATIC_STRING(uppercase, "uppercase");
STATIC_STRING(uppercase_q, "uppercase?");
STATIC_STRING(url_decode, "url-decode");
STATIC_STRING(url_encode, "url-encode");
STATIC_STRING(url_query_encode, "url-query-encode");
STATIC_STRING(utf8_to_latin1, "utf8-to-latin1");
STATIC_STRING(values, "values");
STATIC_STRING(where_, "where");
STATIC_STRING(whitespace_q, "whitespace?");
STATIC_STRING(wildcard_matches, "wildcard-matches?");
STATIC_STRING(without, "without");
STATIC_STRING(xdigit_q, "xdigit?");
STATIC_STRING(xor, "xor");
STATIC_STRING(zero_q, "zero?");

static void KnownSymbolsInt_PreloadGeneralSymbols(SymbolTable symbolTable, KnownSymbols knownSymbols)
{
	knownSymbols->a = SymbolTableInt_AddFast(symbolTable, a);
	knownSymbols->abs = SymbolTableInt_AddFast(symbolTable, abs_);
	knownSymbols->acos = SymbolTableInt_AddFast(symbolTable, acos_);
	knownSymbols->add_c_slashes = SymbolTableInt_AddFast(symbolTable, add_c_slashes);
	knownSymbols->alnum_q = SymbolTableInt_AddFast(symbolTable, alnum_q);
	knownSymbols->alpha_q = SymbolTableInt_AddFast(symbolTable, alpha_q);
	knownSymbols->apply = SymbolTableInt_AddFast(symbolTable, apply);
	knownSymbols->apply_method = SymbolTableInt_AddFast(symbolTable, apply_method);
	knownSymbols->arguments = SymbolTableInt_AddFast(symbolTable, arguments);
	knownSymbols->asin = SymbolTableInt_AddFast(symbolTable, asin_);
	knownSymbols->assertions = SymbolTableInt_AddFast(symbolTable, assertions);
	knownSymbols->assigned_name = SymbolTableInt_AddFast(symbolTable, assigned_name);
	knownSymbols->atan = SymbolTableInt_AddFast(symbolTable, atan_);
	knownSymbols->atan2 = SymbolTableInt_AddFast(symbolTable, atan2_);
	knownSymbols->base_ = SymbolTableInt_AddFast(symbolTable, base_);
	knownSymbols->bit_not = SymbolTableInt_AddFast(symbolTable, bit_not);
	knownSymbols->bit_and = SymbolTableInt_AddFast(symbolTable, bit_and);
	knownSymbols->bit_or = SymbolTableInt_AddFast(symbolTable, bit_or);
	knownSymbols->bit_xor = SymbolTableInt_AddFast(symbolTable, bit_xor);
	knownSymbols->body = SymbolTableInt_AddFast(symbolTable, body);
	knownSymbols->bool_ = SymbolTableInt_AddFast(symbolTable, bool_);
	knownSymbols->byte_ = SymbolTableInt_AddFast(symbolTable, byte_);
	knownSymbols->byte_array = SymbolTableInt_AddFast(symbolTable, byte_array);
	knownSymbols->call = SymbolTableInt_AddFast(symbolTable, call);
	knownSymbols->call_method = SymbolTableInt_AddFast(symbolTable, call_method);
	knownSymbols->camelCase = SymbolTableInt_AddFast(symbolTable, camelCase);
	knownSymbols->CamelCase = SymbolTableInt_AddFast(symbolTable, CamelCase);
	knownSymbols->case_fold = SymbolTableInt_AddFast(symbolTable, case_fold);
	knownSymbols->case_insensitive = SymbolTableInt_AddFast(symbolTable, case_insensitive);
	knownSymbols->case_sensitive = SymbolTableInt_AddFast(symbolTable, case_sensitive);
	knownSymbols->category = SymbolTableInt_AddFast(symbolTable, category);
	knownSymbols->ceil = SymbolTableInt_AddFast(symbolTable, ceil_);
	knownSymbols->char_ = SymbolTableInt_AddFast(symbolTable, char_);
	knownSymbols->chip = SymbolTableInt_AddFast(symbolTable, chip);
	knownSymbols->chop = SymbolTableInt_AddFast(symbolTable, chop);
	knownSymbols->cident_q = SymbolTableInt_AddFast(symbolTable, cident_q);
	knownSymbols->clip = SymbolTableInt_AddFast(symbolTable, clip);
	knownSymbols->clone = SymbolTableInt_AddFast(symbolTable, clone);
	knownSymbols->cmp = SymbolTableInt_AddFast(symbolTable, cmp);
	knownSymbols->code_at = SymbolTableInt_AddFast(symbolTable, code_at);
	knownSymbols->code_length = SymbolTableInt_AddFast(symbolTable, code_length);
	knownSymbols->column = SymbolTableInt_AddFast(symbolTable, column);
	knownSymbols->combine = SymbolTableInt_AddFast(symbolTable, combine);
	knownSymbols->compare = SymbolTableInt_AddFast(symbolTable, compare);
	knownSymbols->compare_i = SymbolTableInt_AddFast(symbolTable, compare_i);
	knownSymbols->compose = SymbolTableInt_AddFast(symbolTable, compose);
	knownSymbols->composed_q = SymbolTableInt_AddFast(symbolTable, composed_q);
	knownSymbols->cons = SymbolTableInt_AddFast(symbolTable, cons);
	knownSymbols->contains = SymbolTableInt_AddFast(symbolTable, contains);
	knownSymbols->contains_i = SymbolTableInt_AddFast(symbolTable, contains_i);
	knownSymbols->context = SymbolTableInt_AddFast(symbolTable, context);
	knownSymbols->control_q = SymbolTableInt_AddFast(symbolTable, control_q);
	knownSymbols->cos = SymbolTableInt_AddFast(symbolTable, cos_);
	knownSymbols->count = SymbolTableInt_AddFast(symbolTable, count);
	knownSymbols->count64 = SymbolTableInt_AddFast(symbolTable, count64);
	knownSymbols->count_left_ones = SymbolTableInt_AddFast(symbolTable, count_left_ones);
	knownSymbols->count_left_zeros = SymbolTableInt_AddFast(symbolTable, count_left_zeros);
	knownSymbols->count_of = SymbolTableInt_AddFast(symbolTable, count_of);
	knownSymbols->count_of_i = SymbolTableInt_AddFast(symbolTable, count_of_i);
	knownSymbols->count_ones = SymbolTableInt_AddFast(symbolTable, count_ones);
	knownSymbols->count_right_ones = SymbolTableInt_AddFast(symbolTable, count_right_ones);
	knownSymbols->count_right_zeros = SymbolTableInt_AddFast(symbolTable, count_right_zeros);
	knownSymbols->count_zeros = SymbolTableInt_AddFast(symbolTable, count_zeros);
	knownSymbols->crc32 = SymbolTableInt_AddFast(symbolTable, crc32);
	knownSymbols->create = SymbolTableInt_AddFast(symbolTable, create);
	knownSymbols->create_child_closure = SymbolTableInt_AddFast(symbolTable, create_child_closure);
	knownSymbols->d = SymbolTableInt_AddFast(symbolTable, d);
	knownSymbols->decompose = SymbolTableInt_AddFast(symbolTable, decompose);
	knownSymbols->default_ = SymbolTableInt_AddFast(symbolTable, default_);
	knownSymbols->diacritic_q = SymbolTableInt_AddFast(symbolTable, diacritic_q);
	knownSymbols->digit_q = SymbolTableInt_AddFast(symbolTable, digit_q);
	knownSymbols->div = SymbolTableInt_AddFast(symbolTable, div);
	knownSymbols->divide_by_zero = SymbolTableInt_AddFast(symbolTable, divide_by_zero);
	knownSymbols->does_not_understand = SymbolTableInt_AddFast(symbolTable, does_not_understand);
	knownSymbols->each = SymbolTableInt_AddFast(symbolTable, each);
	knownSymbols->end = SymbolTableInt_AddFast(symbolTable, end);
	knownSymbols->ends_with = SymbolTableInt_AddFast(symbolTable, ends_with);
	knownSymbols->ends_with_i = SymbolTableInt_AddFast(symbolTable, ends_with_i);
	knownSymbols->escape = SymbolTableInt_AddFast(symbolTable, escape);
	knownSymbols->even_q = SymbolTableInt_AddFast(symbolTable, even_q);
	knownSymbols->eval = SymbolTableInt_AddFast(symbolTable, eval);
	knownSymbols->exit = SymbolTableInt_AddFast(symbolTable, exit_);
	knownSymbols->extend_object = SymbolTableInt_AddFast(symbolTable, extend_object);
	knownSymbols->extend_where_new = SymbolTableInt_AddFast(symbolTable, extend_where_new);
	knownSymbols->exp = SymbolTableInt_AddFast(symbolTable, exp_);
	knownSymbols->false_ = SymbolTableInt_AddFast(symbolTable, false_);
	knownSymbols->filename = SymbolTableInt_AddFast(symbolTable, filename);
	knownSymbols->filename_mode = SymbolTableInt_AddFast(symbolTable, filename_mode);
	knownSymbols->first = SymbolTableInt_AddFast(symbolTable, first);
	knownSymbols->floor = SymbolTableInt_AddFast(symbolTable, floor_);
	knownSymbols->fold = SymbolTableInt_AddFast(symbolTable, fold);
	knownSymbols->from_seed = SymbolTableInt_AddFast(symbolTable, from_seed);
	knownSymbols->get_object_security = SymbolTableInt_AddFast(symbolTable, get_object_security);
	knownSymbols->get_property = SymbolTableInt_AddFast(symbolTable, get_property);
	knownSymbols->handle_kind = SymbolTableInt_AddFast(symbolTable, handle_kind);
	knownSymbols->hash = SymbolTableInt_AddFast(symbolTable, hash);
	knownSymbols->has_property = SymbolTableInt_AddFast(symbolTable, has_property);
	knownSymbols->hex_string = SymbolTableInt_AddFast(symbolTable, hex_string);
	knownSymbols->hex_string_pretty = SymbolTableInt_AddFast(symbolTable, hex_string_pretty);
	knownSymbols->html_decode = SymbolTableInt_AddFast(symbolTable, html_decode);
	knownSymbols->html_encode = SymbolTableInt_AddFast(symbolTable, html_encode);
	knownSymbols->hyphenize = SymbolTableInt_AddFast(symbolTable, hyphenize);
	knownSymbols->id = SymbolTableInt_AddFast(symbolTable, id);
	knownSymbols->in_ = SymbolTableInt_AddFast(symbolTable, in_);
	knownSymbols->include = SymbolTableInt_AddFast(symbolTable, include);
	knownSymbols->index_of = SymbolTableInt_AddFast(symbolTable, index_of);
	knownSymbols->index_of_i = SymbolTableInt_AddFast(symbolTable, index_of_i);
	knownSymbols->int_ = SymbolTableInt_AddFast(symbolTable, int_);
	knownSymbols->int16_ = SymbolTableInt_AddFast(symbolTable, int16_);
	knownSymbols->int32_ = SymbolTableInt_AddFast(symbolTable, int32_);
	knownSymbols->int64_ = SymbolTableInt_AddFast(symbolTable, int64_);
	knownSymbols->int_lg = SymbolTableInt_AddFast(symbolTable, int_lg);
	knownSymbols->last_index_of = SymbolTableInt_AddFast(symbolTable, last_index_of);
	knownSymbols->last_index_of_i = SymbolTableInt_AddFast(symbolTable, last_index_of_i);
	knownSymbols->latin1_to_utf8 = SymbolTableInt_AddFast(symbolTable, latin1_to_utf8);
	knownSymbols->left = SymbolTableInt_AddFast(symbolTable, left);
	knownSymbols->length = SymbolTableInt_AddFast(symbolTable, length);
	knownSymbols->letter = SymbolTableInt_AddFast(symbolTable, letter);
	knownSymbols->letter_q = SymbolTableInt_AddFast(symbolTable, letter_q);
	knownSymbols->letter_lowercase = SymbolTableInt_AddFast(symbolTable, letter_lowercase);
	knownSymbols->letter_modifier = SymbolTableInt_AddFast(symbolTable, letter_modifier);
	knownSymbols->letter_other = SymbolTableInt_AddFast(symbolTable, letter_other);
	knownSymbols->letter_titlecase = SymbolTableInt_AddFast(symbolTable, letter_titlecase);
	knownSymbols->letter_uppercase = SymbolTableInt_AddFast(symbolTable, letter_uppercase);
	knownSymbols->lg = SymbolTableInt_AddFast(symbolTable, lg);
	knownSymbols->line = SymbolTableInt_AddFast(symbolTable, line);
	knownSymbols->list = SymbolTableInt_AddFast(symbolTable, list);
	knownSymbols->load = SymbolTableInt_AddFast(symbolTable, load);
	knownSymbols->log = SymbolTableInt_AddFast(symbolTable, log_);
	knownSymbols->log_domain = SymbolTableInt_AddFast(symbolTable, log_domain);
	knownSymbols->lower = SymbolTableInt_AddFast(symbolTable, lower);
	knownSymbols->lowercase = SymbolTableInt_AddFast(symbolTable, lowercase);
	knownSymbols->lowercase_q = SymbolTableInt_AddFast(symbolTable, lowercase_q);
	knownSymbols->ln = SymbolTableInt_AddFast(symbolTable, ln);
	knownSymbols->join = SymbolTableInt_AddFast(symbolTable, join);
	knownSymbols->keys = SymbolTableInt_AddFast(symbolTable, keys);
	knownSymbols->kind = SymbolTableInt_AddFast(symbolTable, kind);
	knownSymbols->map = SymbolTableInt_AddFast(symbolTable, map);
	knownSymbols->mark = SymbolTableInt_AddFast(symbolTable, mark);
	knownSymbols->mark_enclosing = SymbolTableInt_AddFast(symbolTable, mark_enclosing);
	knownSymbols->mark_non_spacing = SymbolTableInt_AddFast(symbolTable, mark_non_spacing);
	knownSymbols->mark_spacing_combining = SymbolTableInt_AddFast(symbolTable, mark_spacing_combining);
	knownSymbols->match = SymbolTableInt_AddFast(symbolTable, match);
	knownSymbols->matches = SymbolTableInt_AddFast(symbolTable, matches);
	knownSymbols->max = SymbolTableInt_AddFast(symbolTable, max);
	knownSymbols->message = SymbolTableInt_AddFast(symbolTable, message);
	knownSymbols->mid = SymbolTableInt_AddFast(symbolTable, mid);
	knownSymbols->min = SymbolTableInt_AddFast(symbolTable, min);
	knownSymbols->mod = SymbolTableInt_AddFast(symbolTable, mod);
	knownSymbols->name = SymbolTableInt_AddFast(symbolTable, name);
	knownSymbols->neg_q = SymbolTableInt_AddFast(symbolTable, neg_q);
	knownSymbols->newline_q = SymbolTableInt_AddFast(symbolTable, newline_q);
	knownSymbols->next_pow2 = SymbolTableInt_AddFast(symbolTable, next_pow2);
	knownSymbols->normalize_diacritics = SymbolTableInt_AddFast(symbolTable, normalize_diacritics);
	knownSymbols->nonterminal = SymbolTableInt_AddFast(symbolTable, nonterminal);
	knownSymbols->nth = SymbolTableInt_AddFast(symbolTable, nth);
	knownSymbols->nth_cell = SymbolTableInt_AddFast(symbolTable, nth_cell);
	knownSymbols->null_ = SymbolTableInt_AddFast(symbolTable, null_);
	knownSymbols->number = SymbolTableInt_AddFast(symbolTable, number);
	knownSymbols->number_decimal_digit = SymbolTableInt_AddFast(symbolTable, number_decimal_digit);
	knownSymbols->number_letter = SymbolTableInt_AddFast(symbolTable, number_letter);
	knownSymbols->number_other = SymbolTableInt_AddFast(symbolTable, number_other);
	knownSymbols->numeric_q = SymbolTableInt_AddFast(symbolTable, numeric_q);
	knownSymbols->octal_q = SymbolTableInt_AddFast(symbolTable, octal_q);
	knownSymbols->of = SymbolTableInt_AddFast(symbolTable, of);
	knownSymbols->of_size = SymbolTableInt_AddFast(symbolTable, of_size);
	knownSymbols->offset = SymbolTableInt_AddFast(symbolTable, offset);
	knownSymbols->odd_q = SymbolTableInt_AddFast(symbolTable, odd_q);
	knownSymbols->one_q = SymbolTableInt_AddFast(symbolTable, one_q);
	knownSymbols->options = SymbolTableInt_AddFast(symbolTable, options);
	knownSymbols->other = SymbolTableInt_AddFast(symbolTable, other);
	knownSymbols->other_control = SymbolTableInt_AddFast(symbolTable, other_control);
	knownSymbols->other_format = SymbolTableInt_AddFast(symbolTable, other_format);
	knownSymbols->other_not_assigned = SymbolTableInt_AddFast(symbolTable, other_not_assigned);
	knownSymbols->other_private_use = SymbolTableInt_AddFast(symbolTable, other_private_use);
	knownSymbols->other_surrogate = SymbolTableInt_AddFast(symbolTable, other_surrogate);
	knownSymbols->parity = SymbolTableInt_AddFast(symbolTable, parity);
	knownSymbols->parse = SymbolTableInt_AddFast(symbolTable, parse);
	knownSymbols->parse_and_eval = SymbolTableInt_AddFast(symbolTable, parse_and_eval);
	knownSymbols->pattern = SymbolTableInt_AddFast(symbolTable, pattern);
	knownSymbols->pos_q = SymbolTableInt_AddFast(symbolTable, pos_q);
	knownSymbols->post = SymbolTableInt_AddFast(symbolTable, post);
	knownSymbols->pow2_q = SymbolTableInt_AddFast(symbolTable, pow2_q);
	knownSymbols->pre = SymbolTableInt_AddFast(symbolTable, pre);
	knownSymbols->primary_category = SymbolTableInt_AddFast(symbolTable, primary_category);
	knownSymbols->printf = SymbolTableInt_AddFast(symbolTable, printf);
	knownSymbols->process_id = SymbolTableInt_AddFast(symbolTable, process_id);
	knownSymbols->property_names = SymbolTableInt_AddFast(symbolTable, property_names);
	knownSymbols->punct_q = SymbolTableInt_AddFast(symbolTable, punct_q);
	knownSymbols->punctuation = SymbolTableInt_AddFast(symbolTable, punctuation);
	knownSymbols->punctuation_close = SymbolTableInt_AddFast(symbolTable, punctuation_close);
	knownSymbols->punctuation_connector = SymbolTableInt_AddFast(symbolTable, punctuation_connector);
	knownSymbols->punctuation_dash = SymbolTableInt_AddFast(symbolTable, punctuation_dash);
	knownSymbols->punctuation_final_quote = SymbolTableInt_AddFast(symbolTable, punctuation_final_quote);
	knownSymbols->punctuation_initial_quote = SymbolTableInt_AddFast(symbolTable, punctuation_initial_quote);
	knownSymbols->punctuation_open = SymbolTableInt_AddFast(symbolTable, punctuation_open);
	knownSymbols->punctuation_other = SymbolTableInt_AddFast(symbolTable, punctuation_other);
	knownSymbols->range_to = SymbolTableInt_AddFast(symbolTable, range_to);
	knownSymbols->raw_reverse = SymbolTableInt_AddFast(symbolTable, raw_reverse);
	knownSymbols->read_append = SymbolTableInt_AddFast(symbolTable, read_append);
	knownSymbols->read_only = SymbolTableInt_AddFast(symbolTable, read_only);
	knownSymbols->read_write = SymbolTableInt_AddFast(symbolTable, read_write);
	knownSymbols->read_write_append = SymbolTableInt_AddFast(symbolTable, read_write_append);
	knownSymbols->real_ = SymbolTableInt_AddFast(symbolTable, real_);
	knownSymbols->real32_ = SymbolTableInt_AddFast(symbolTable, real32_);
	knownSymbols->real64_ = SymbolTableInt_AddFast(symbolTable, real64_);
	knownSymbols->rem = SymbolTableInt_AddFast(symbolTable, rem);
	knownSymbols->repeat = SymbolTableInt_AddFast(symbolTable, repeat);
	knownSymbols->replace = SymbolTableInt_AddFast(symbolTable, replace);
	knownSymbols->replacement = SymbolTableInt_AddFast(symbolTable, replacement);
	knownSymbols->resize = SymbolTableInt_AddFast(symbolTable, resize);
	knownSymbols->rest = SymbolTableInt_AddFast(symbolTable, rest);
	knownSymbols->reverse = SymbolTableInt_AddFast(symbolTable, reverse);
	knownSymbols->reverse_bits = SymbolTableInt_AddFast(symbolTable, reverse_bits);
	knownSymbols->reverse_bytes = SymbolTableInt_AddFast(symbolTable, reverse_bytes);
	knownSymbols->right = SymbolTableInt_AddFast(symbolTable, right);
	knownSymbols->rot_13 = SymbolTableInt_AddFast(symbolTable, rot_13);
	knownSymbols->result = SymbolTableInt_AddFast(symbolTable, result);
	knownSymbols->separator = SymbolTableInt_AddFast(symbolTable, separator);
	knownSymbols->separator_line = SymbolTableInt_AddFast(symbolTable, separator_line);
	knownSymbols->separator_paragraph = SymbolTableInt_AddFast(symbolTable, separator_paragraph);
	knownSymbols->separator_space = SymbolTableInt_AddFast(symbolTable, separator_space);
	knownSymbols->set_object_security = SymbolTableInt_AddFast(symbolTable, set_object_security);
	knownSymbols->set_property = SymbolTableInt_AddFast(symbolTable, set_property);
	knownSymbols->sign = SymbolTableInt_AddFast(symbolTable, sign);
	knownSymbols->sin = SymbolTableInt_AddFast(symbolTable, sin_);
	knownSymbols->space_q = SymbolTableInt_AddFast(symbolTable, space_q);
	knownSymbols->splice = SymbolTableInt_AddFast(symbolTable, splice);
	knownSymbols->split = SymbolTableInt_AddFast(symbolTable, split);
	knownSymbols->sprintf = SymbolTableInt_AddFast(symbolTable, sprintf);
	knownSymbols->sqrt = SymbolTableInt_AddFast(symbolTable, sqrt_);
	knownSymbols->sqrt_domain = SymbolTableInt_AddFast(symbolTable, sqrt_domain);
	knownSymbols->start = SymbolTableInt_AddFast(symbolTable, start);
	knownSymbols->starts_with = SymbolTableInt_AddFast(symbolTable, starts_with);
	knownSymbols->starts_with_i = SymbolTableInt_AddFast(symbolTable, starts_with_i);
	knownSymbols->step = SymbolTableInt_AddFast(symbolTable, step);
	knownSymbols->stepping = SymbolTableInt_AddFast(symbolTable, stepping);
	knownSymbols->strip_c_slashes = SymbolTableInt_AddFast(symbolTable, strip_c_slashes);
	knownSymbols->string_ = SymbolTableInt_AddFast(symbolTable, string_);
	knownSymbols->studied_ = SymbolTableInt_AddFast(symbolTable, studied_);
	knownSymbols->study = SymbolTableInt_AddFast(symbolTable, study);
	knownSymbols->substr = SymbolTableInt_AddFast(symbolTable, substr);
	knownSymbols->substring = SymbolTableInt_AddFast(symbolTable, substring);
	knownSymbols->symbol = SymbolTableInt_AddFast(symbolTable, symbol);
	knownSymbols->symbol_currency = SymbolTableInt_AddFast(symbolTable, symbol_currency);
	knownSymbols->symbol_math = SymbolTableInt_AddFast(symbolTable, symbol_math);
	knownSymbols->symbol_modifier = SymbolTableInt_AddFast(symbolTable, symbol_modifier);
	knownSymbols->symbol_other = SymbolTableInt_AddFast(symbolTable, symbol_other);
	knownSymbols->tan = SymbolTableInt_AddFast(symbolTable, tan_);
	knownSymbols->text = SymbolTableInt_AddFast(symbolTable, text);
	knownSymbols->this_ = SymbolTableInt_AddFast(symbolTable, this_);
	knownSymbols->this_closure = SymbolTableInt_AddFast(symbolTable, this_closure);
	knownSymbols->throw_ = SymbolTableInt_AddFast(symbolTable, throw_);
	knownSymbols->title = SymbolTableInt_AddFast(symbolTable, title);
	knownSymbols->titlecase = SymbolTableInt_AddFast(symbolTable, titlecase);
	knownSymbols->titlecase_q = SymbolTableInt_AddFast(symbolTable, titlecase_q);
	knownSymbols->trim = SymbolTableInt_AddFast(symbolTable, trim);
	knownSymbols->trim_end = SymbolTableInt_AddFast(symbolTable, trim_end);
	knownSymbols->trim_start = SymbolTableInt_AddFast(symbolTable, trim_start);
	knownSymbols->true_ = SymbolTableInt_AddFast(symbolTable, true_);
	knownSymbols->type = SymbolTableInt_AddFast(symbolTable, type);
	knownSymbols->underscorize = SymbolTableInt_AddFast(symbolTable, underscorize);
	knownSymbols->unknown = SymbolTableInt_AddFast(symbolTable, unknown);
	knownSymbols->upper = SymbolTableInt_AddFast(symbolTable, upper);
	knownSymbols->uppercase = SymbolTableInt_AddFast(symbolTable, uppercase);
	knownSymbols->uppercase_q = SymbolTableInt_AddFast(symbolTable, uppercase_q);
	knownSymbols->url_decode = SymbolTableInt_AddFast(symbolTable, url_decode);
	knownSymbols->url_encode = SymbolTableInt_AddFast(symbolTable, url_encode);
	knownSymbols->url_query_encode = SymbolTableInt_AddFast(symbolTable, url_query_encode);
	knownSymbols->utf8_to_latin1 = SymbolTableInt_AddFast(symbolTable, utf8_to_latin1);
	knownSymbols->values = SymbolTableInt_AddFast(symbolTable, values);
	knownSymbols->where_ = SymbolTableInt_AddFast(symbolTable, where_);
	knownSymbols->whitespace_q = SymbolTableInt_AddFast(symbolTable, whitespace_q);
	knownSymbols->wildcard_matches = SymbolTableInt_AddFast(symbolTable, wildcard_matches);
	knownSymbols->without = SymbolTableInt_AddFast(symbolTable, without);
	knownSymbols->xdigit_q = SymbolTableInt_AddFast(symbolTable, xdigit_q);
	knownSymbols->xor = SymbolTableInt_AddFast(symbolTable, xor);
	knownSymbols->zero_q = SymbolTableInt_AddFast(symbolTable, zero_q);
}

//-------------------------------------------------------------------------------------------------
//  Error symbols.

STATIC_STRING(compile_error, "compile-error");
STATIC_STRING(configuration_error, "configuration-error");
STATIC_STRING(eval_error, "eval-error");
STATIC_STRING(exec_error, "exec-error");
STATIC_STRING(json_error, "json-error");
STATIC_STRING(lexer_error, "lexer-error");
STATIC_STRING(load_error, "load-error");
STATIC_STRING(native_method_error, "native-method-error");
STATIC_STRING(object_security_error, "object-security-error");
STATIC_STRING(post_condition_assertion, "post-condition-assertion");
STATIC_STRING(pre_condition_assertion, "pre-condition-assertion");
STATIC_STRING(property_error, "property-error");
STATIC_STRING(syntax_error, "syntax-error");
STATIC_STRING(system_exception, "system-exception");
STATIC_STRING(type_assertion, "type-assertion");
STATIC_STRING(user_exception, "user-exception");

static void KnownSymbolsInt_PreloadErrorSymbols(SymbolTable symbolTable, KnownSymbols knownSymbols)
{
	knownSymbols->compile_error = SymbolTableInt_AddFast(symbolTable, compile_error);
	knownSymbols->configuration_error = SymbolTableInt_AddFast(symbolTable, configuration_error);
	knownSymbols->eval_error = SymbolTableInt_AddFast(symbolTable, eval_error);
	knownSymbols->exec_error = SymbolTableInt_AddFast(symbolTable, exec_error);
	knownSymbols->json_error = SymbolTableInt_AddFast(symbolTable, json_error);
	knownSymbols->lexer_error = SymbolTableInt_AddFast(symbolTable, lexer_error);
	knownSymbols->load_error = SymbolTableInt_AddFast(symbolTable, load_error);
	knownSymbols->native_method_error = SymbolTableInt_AddFast(symbolTable, native_method_error);
	knownSymbols->object_security_error = SymbolTableInt_AddFast(symbolTable, object_security_error);
	knownSymbols->post_condition_assertion = SymbolTableInt_AddFast(symbolTable, post_condition_assertion);
	knownSymbols->pre_condition_assertion = SymbolTableInt_AddFast(symbolTable, pre_condition_assertion);
	knownSymbols->property_error = SymbolTableInt_AddFast(symbolTable, property_error);
	knownSymbols->syntax_error = SymbolTableInt_AddFast(symbolTable, syntax_error);
	knownSymbols->system_exception = SymbolTableInt_AddFast(symbolTable, system_exception);
	knownSymbols->type_assertion = SymbolTableInt_AddFast(symbolTable, type_assertion);
	knownSymbols->user_exception = SymbolTableInt_AddFast(symbolTable, user_exception);
}

//-------------------------------------------------------------------------------------------------
//  Public API.

void KnownSymbols_PreloadSymbolTable(SymbolTable symbolTable, KnownSymbols knownSymbols)
{
	struct SymbolTableInt *table = (struct SymbolTableInt *)symbolTable;
	if (table->count != 1)
		Smile_Abort_FatalError("Cannot preload symbol table: Symbol table must be empty to be preloaded.");
	if (table->max < 1024)
		Smile_Abort_FatalError("Cannot preload symbol table: Symbol table is too small for preloading.");

	KnownSymbolsInt_PreloadSpecials(symbolTable, knownSymbols);
	KnownSymbolsInt_PreloadTypenames(symbolTable, knownSymbols);
	KnownSymbolsInt_PreloadGeneralSymbols(symbolTable, knownSymbols);
	KnownSymbolsInt_PreloadErrorSymbols(symbolTable, knownSymbols);
}
