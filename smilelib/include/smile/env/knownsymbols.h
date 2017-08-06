#ifndef __SMILE_ENV_KNOWNSYMBOLS_H__
#define __SMILE_ENV_KNOWNSYMBOLS_H__

#ifndef __SMILE_ENV_SYMBOLTABLE_H__
#include <smile/env/symboltable.h>
#endif

// Preregistered symbol IDs for the special symbols.
typedef enum SmileSpecialSymbolEnum {

	// The twenty primitive forms first.
	SMILE_SPECIAL_SYMBOL__SET	= 1,
	SMILE_SPECIAL_SYMBOL__OPSET	= 2,
	SMILE_SPECIAL_SYMBOL__IF	= 3,
	SMILE_SPECIAL_SYMBOL__WHILE	= 4,
	SMILE_SPECIAL_SYMBOL__TILL	= 5,
	SMILE_SPECIAL_SYMBOL__FN	= 6,
	SMILE_SPECIAL_SYMBOL__QUOTE	= 7,
	SMILE_SPECIAL_SYMBOL__SCOPE	= 8,
	SMILE_SPECIAL_SYMBOL__PROG1	= 9,
	SMILE_SPECIAL_SYMBOL__PROGN	= 10,
	SMILE_SPECIAL_SYMBOL__RETURN	= 11,
	SMILE_SPECIAL_SYMBOL__CATCH	= 12,
	SMILE_SPECIAL_SYMBOL__NOT	= 13,
	SMILE_SPECIAL_SYMBOL__OR	= 14,
	SMILE_SPECIAL_SYMBOL__AND	= 15,
	SMILE_SPECIAL_SYMBOL__EQ	= 16,
	SMILE_SPECIAL_SYMBOL__NE	= 17,
	SMILE_SPECIAL_SYMBOL__NEW	= 18,
	SMILE_SPECIAL_SYMBOL__IS	= 19,
	SMILE_SPECIAL_SYMBOL__TYPEOF	= 20,
		
	// Special keywords.	
	SMILE_SPECIAL_SYMBOL_VAR	= 21,
	SMILE_SPECIAL_SYMBOL_CONST	= 22,
	SMILE_SPECIAL_SYMBOL_AUTO	= 23,		
	SMILE_SPECIAL_SYMBOL_KEYWORD	= 24,
	SMILE_SPECIAL_SYMBOL_IF = 25,
	SMILE_SPECIAL_SYMBOL_UNLESS = 26,
	SMILE_SPECIAL_SYMBOL_THEN = 27,
	SMILE_SPECIAL_SYMBOL_ELSE = 28,
	SMILE_SPECIAL_SYMBOL_DO = 29,
	SMILE_SPECIAL_SYMBOL_WHILE = 30,
	SMILE_SPECIAL_SYMBOL_UNTIL = 31,
	SMILE_SPECIAL_SYMBOL_TILL = 32,
	SMILE_SPECIAL_SYMBOL_WHEN = 33,
	SMILE_SPECIAL_SYMBOL_RETURN = 34,
	SMILE_SPECIAL_SYMBOL_TRY	= 35,
	SMILE_SPECIAL_SYMBOL_CATCH	= 36,
	SMILE_SPECIAL_SYMBOL_NOT	= 37,
	SMILE_SPECIAL_SYMBOL_OR	= 38,
	SMILE_SPECIAL_SYMBOL_AND	= 39,
	SMILE_SPECIAL_SYMBOL_NEW	= 40,
	SMILE_SPECIAL_SYMBOL_IS	= 41,
	SMILE_SPECIAL_SYMBOL_TYPEOF	= 42,
		
	// Comparison punctuation.	
	SMILE_SPECIAL_SYMBOL_SUPEREQ	= 43,
	SMILE_SPECIAL_SYMBOL_SUPERNE	= 44,	
	SMILE_SPECIAL_SYMBOL_EQ	= 45,
	SMILE_SPECIAL_SYMBOL_NE	= 46,
	SMILE_SPECIAL_SYMBOL_LT	= 47,
	SMILE_SPECIAL_SYMBOL_GT	= 48,
	SMILE_SPECIAL_SYMBOL_LE	= 49,
	SMILE_SPECIAL_SYMBOL_GE	= 50,
		
	// Arithmetic.	
	SMILE_SPECIAL_SYMBOL_PLUS	= 51,
	SMILE_SPECIAL_SYMBOL_MINUS	= 52,
	SMILE_SPECIAL_SYMBOL_STAR	= 53,
	SMILE_SPECIAL_SYMBOL_SLASH	= 54,
		
	// Braces and brackets.	
	SMILE_SPECIAL_SYMBOL_LEFTPARENTHESIS	= 55,
	SMILE_SPECIAL_SYMBOL_RIGHTPARENTHESIS	= 56,
	SMILE_SPECIAL_SYMBOL_LEFTBRACKET	= 57,
	SMILE_SPECIAL_SYMBOL_RIGHTBRACKET	= 58,
	SMILE_SPECIAL_SYMBOL_LEFTBRACE	= 59,
	SMILE_SPECIAL_SYMBOL_RIGHTBRACE	= 60,
		
	// Other punctuation.	
	SMILE_SPECIAL_SYMBOL_COMMA	= 61,
	SMILE_SPECIAL_SYMBOL_SEMICOLON	= 62,
	SMILE_SPECIAL_SYMBOL_COLON	= 63,
	SMILE_SPECIAL_SYMBOL_QUESTIONMARK	= 64,
	SMILE_SPECIAL_SYMBOL_IMPLIES	= 65,
	SMILE_SPECIAL_SYMBOL_CARET	= 66,
	SMILE_SPECIAL_SYMBOL_SHL	= 67,
	SMILE_SPECIAL_SYMBOL_SHR	= 68,
	SMILE_SPECIAL_SYMBOL_SAL	= 69,
	SMILE_SPECIAL_SYMBOL_SAR	= 70,
	SMILE_SPECIAL_SYMBOL_ROL	= 71,
	SMILE_SPECIAL_SYMBOL_ROR	= 72,
		
	// Special #syntax classes.	
	SMILE_SPECIAL_SYMBOL_STMT	= 73,
	SMILE_SPECIAL_SYMBOL_EXPR	= 74,
	SMILE_SPECIAL_SYMBOL_CMPEXPR	= 75,
	SMILE_SPECIAL_SYMBOL_ADDEXPR	= 76,
	SMILE_SPECIAL_SYMBOL_MULEXPR	= 77,
	SMILE_SPECIAL_SYMBOL_BINARYEXPR	= 78,
	SMILE_SPECIAL_SYMBOL_COLONEXPR	= 79,
	SMILE_SPECIAL_SYMBOL_RANGEEXPR	= 80,
	SMILE_SPECIAL_SYMBOL_PREFIXEXPR	= 81,
	SMILE_SPECIAL_SYMBOL_POSTFIXEXPR	= 82,
	SMILE_SPECIAL_SYMBOL_CONSEXPR	= 83,
	SMILE_SPECIAL_SYMBOL_DOTEXPR	= 84,
	SMILE_SPECIAL_SYMBOL_TERM	= 85,
	SMILE_SPECIAL_SYMBOL_NAME	= 86,

	// The special 'get-member' and 'set-member' method names.
	SMILE_SPECIAL_SYMBOL_GET_MEMBER	= 87,
	SMILE_SPECIAL_SYMBOL_SET_MEMBER = 88,

	// Miscellaneous.
	SMILE_SPECIAL_SYMBOL_AS = 89,

} SmileSpecialSymbol;

// The set of known symbols, preregistered at startup time to save on runtime-initialization costs.
typedef struct KnownSymbolsStruct {

	//------------------------------------------
	// The 80-ish special symbols from the list above first.

	// The twenty core special forms.
	Symbol _set, _opset;
	Symbol _if, _while, _till;
	Symbol _fn, _quote, _scope, _prog1, _progn, _return, _catch;
	Symbol _not, _or, _and, _eq, _ne;
	Symbol _new, _is, _typeof;

	// Special keywords.
	Symbol var_, const_, auto_, keyword_;
	Symbol if_, unless_, then_, else_, do_, while_, until_, till_, when_, return_, try_, catch_;
	Symbol not_, or_, and_;
	Symbol new_, is_, typeof_;

	// Comparison punctuation.
	Symbol supereq_, superne_, eq, ne, lt, gt, le, ge;

	// Arithmetic.
	Symbol plus, minus, star, slash;

	// Braces and brackets.
	Symbol left_parenthesis, right_parenthesis, left_bracket, right_bracket, left_brace, right_brace;

	// Other punctuation.
	Symbol comma, semicolon, colon, question_mark, implies, caret;
	Symbol shift_left, shift_right, arithmetic_shift_left, arithmetic_shift_right, rotate_left, rotate_right;

	// Special #syntax classes.
	Symbol STMT;
	Symbol EXPR, CMPEXPR, ADDEXPR, MULEXPR, BINARYEXPR, COLONEXPR, RANGEEXPR, PREFIXEXPR, POSTFIXEXPR, CONSEXPR, DOTEXPR;
	Symbol TERM;
	Symbol NAME;

	// The special 'get-member' and 'set-member' methods.
	Symbol get_member, set_member;

	// Miscellaneous.
	Symbol as;

	// End of special symbols.
	//------------------------------------------

	// Typename symbols.
	Symbol Actor_, Array_, ArrayBase_, Bool_, BoolArray_, Char_, Closure, Enumerable_, Exception_, Facade_, FacadeProper_, Fn_, Handle_;
	Symbol List_, Map_, MapBase_, MathException, Null_, Object_, Pair_, Program_, Random_, Range_;
	Symbol Regex_, String_, StringArray_, StringMap_, Symbol_, SymbolArray_, SymbolMap_, UserObject_;

	// Numeric typename symbols.
	Symbol Number_, NumericArray_, NumericRange_, NumericMap_;

	// Integer typename symbols.
	Symbol Integer_, IntegerBase_, IntegerArrayBase_, IntegerRange_, IntegerRangeBase_, IntegerMap_, IntegerMapBase_;
	Symbol Byte_, ByteArray_, ByteRange_, ByteMap_;
	Symbol Integer16_, Integer16Array_, Integer16Range_, Integer16Map_;
	Symbol Integer32_, Integer32Array_, Integer32Range_, Integer32Map_;
	Symbol Integer64_, Integer64Array_, Integer64Range_, Integer64Map_;
	Symbol Integer128_, Integer128Array_, Integer128Range_, Integer128Map_;

	// Real typename symbols.
	Symbol Real_, RealBase_, RealArrayBase_, RealRange_, RealRangeBase_, RealMap_, RealMapBase_;
	Symbol Real32_, Real32Array_, Real32Range_, Real32Map_;
	Symbol Real64_, Real64Array_, Real64Range_, Real64Map_;
	Symbol Real128_, Real128Array_, Real128Range_, Real128Map_;

	// Float typename symbols.
	Symbol Float_, FloatBase_, FloatArrayBase_, FloatRange_, FloatRangeBase_, FloatMap_, FloatMapBase_;
	Symbol Float32_, Float32Array_, Float32Range_, Float32Map_;
	Symbol Float64_, Float64Array_, Float64Range_, Float64Map_;
	Symbol Float128_, Float128Array_, Float128Range_, Float128Map_;

	// General symbols.
	Symbol a, abs, acos, add_c_slashes, alnum_q, alpha_q, apply, apply_method, arguments, asin, assertions, assigned_name, atan, atan2;
	Symbol base_, bit_and, bit_not, bit_or, bit_xor, body, bool_, byte_, byte_array;
	Symbol call, call_method, camelCase, CamelCase, case_fold, case_insensitive, case_sensitive, category, ceil, char_, chip, chop;
	Symbol cident_q, clip, clone, code_at, code_length, combine, compare, compare_i, compose, composed_q, cons, contains, contains_i, control_q, context, cos, count, count64;
	Symbol count_left_ones, count_left_zeros, count_of, count_of_i, count_ones, count_right_ones, count_right_zeros, count_zeros, crc32, create, create_child_closure;
	Symbol d, decompose, default_, diacritic_q, digit_q, div, divide_by_zero, does_not_understand;
	Symbol each, end, ends_with, ends_with_i, escape, eval, even_q, exit, exp, extend_object, extend_where_new;
	Symbol false_, filename_mode, first, floor, fold, from_seed;
	Symbol get_object_security, get_property;
	Symbol handle_kind, has_property, hash, hex_string, hex_string_pretty, html_decode, html_encode, hyphenize;
	Symbol id, in_, include, index_of, index_of_i, int_, int16_, int32_, int64_, int_lg;
	Symbol join;
	Symbol keys, kind;
	Symbol last_index_of, last_index_of_i, latin1_to_utf8, left, length, letter, letter_q;
	Symbol letter_lowercase, letter_modifier, letter_other, letter_titlecase, letter_uppercase;
	Symbol lg, list, load, log, log_domain, lower, lowercase, lowercase_q, ln;
	Symbol map, mark, mark_enclosing, mark_non_spacing, mark_spacing_combining;
	Symbol match, matches, max, message, mid, min, mod;
	Symbol name, neg_q, newline_q, next_pow2, nonterminal, normalize_diacritics, nth, nth_cell, null_, number;
	Symbol number_decimal_digit, number_letter, number_other, numeric_q;
	Symbol octal_q, of, of_size, odd_q, one_q, options, other;
	Symbol other_control, other_format, other_not_assigned, other_private_use, other_surrogate;
	Symbol parity, parse, parse_and_eval, pattern, pos_q, post, pow2_q, pre, primary_category, printf, process_id, property_names, punct_q, punctuation;
	Symbol punctuation_close, punctuation_connector, punctuation_dash, punctuation_final_quote, punctuation_initial_quote, punctuation_open, punctuation_other;
	Symbol range_to, raw_reverse, read_append, read_only, read_write, read_write_append, real_, real32_, real64_, rem, repeat, replace, replacement, resize, rest, result;
	Symbol reverse, reverse_bits, reverse_bytes, right, rot_13;
	Symbol separator, separator_line, separator_paragraph, separator_space;
	Symbol set_object_security, set_property, sign, sin, space_q, splice, split, sprintf;
	Symbol sqrt, sqrt_domain, start, starts_with, starts_with_i, step, stepping;
	Symbol string_, strip_c_slashes, studied_, study, substr, substring, symbol;
	Symbol symbol_currency, symbol_math, symbol_modifier, symbol_other;
	Symbol tan, text, this_, this_closure, throw_, title, titlecase, titlecase_q, trim, trim_end, trim_start, true_, type;
	Symbol underscorize, unknown, upper, uppercase, uppercase_q, url_decode, url_encode, url_query_encode, utf8_to_latin1;
	Symbol values;
	Symbol where_, whitespace_q, wildcard_matches, without;
	Symbol xdigit_q, xor;
	Symbol zero_q;

	// Error and exception symbols.
	Symbol compile_error, configuration_error, eval_error, exec_error, json_error, lexer_error, load_error, native_method_error, object_security_error;
	Symbol post_condition_assertion, pre_condition_assertion, property_error, syntax_error, system_exception, type_assertion, user_exception;

} *KnownSymbols;

SMILE_API_FUNC void KnownSymbols_PreloadSymbolTable(SymbolTable symbolTable, KnownSymbols knownSymbols);

#endif