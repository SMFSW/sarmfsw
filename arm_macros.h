/*!\file arm_macros.h
** \author SMFSW
** \date 2017
** \copyright MIT (c) 2017, SMFSW
** \brief ARM common macros
*/
/****************************************************************/
#ifndef __ARM_MACROS_H
	#define __ARM_MACROS_H
/****************************************************************/

#include "arm_typedefs.h"


#define	Undefined			-1				//!< Undefined value

#define Null				0				//!< Null Value
#define pNull				(void *) 0		//!< Null pointer -> same as NULL in Stdlib.h
#define	charNUL				'\0'			//!< Null Char


#define MAKEWORD(b1, b2)	((WORD) (((BYTE) (b1)) | ((WORD) ((BYTE) (b2))) * 0x100))		//!< Make WORD from \b b1 and \b b2 with \b b1 as LSB
#define MAKELONG(w1, w2)	((DWORD) (((WORD) (w1)) | ((DWORD) ((WORD) (w2))) * 0x10000))	//!< Make LONG from \b w1 and \b w2 with \b w1 as LSB
#define LOWORD(l)			((WORD) (l))													//!< Get WORD LSW from LONG \b l
#define HIWORD(l)			((WORD) ((DWORD) (l) / 0x10000))								//!< Get WORD MSW from LONG \b l
#define LOBYTE(w)			((BYTE) (w))													//!< Get BYTE LSB from WORD \b w
#define HIBYTE(w)			((BYTE) ((WORD) (w) / 0x100))									//!< Get BYTE MSB from WORD \b w

#define BYTE_TO_PERC(b)		((BYTE) (((b) * 100) / 255))						//!< Converts a BYTE \b b (0-255) to percent (0-100)
#define PERC_TO_BYTE(p)		((BYTE) (((p) > 100 ? 100 : (p)) * 255 / 100))		//!< Converts a BYTE \b p percentage (0-100) to BYTE (0-255) with max checking

#define OFFSET_OF(typ, mbr)	((size_t) &(((typ*)0)->mbr))	//!< Computes the offset member \b mbr from struct \b typ
#define SZ_OBJ(obj, typ)	(sizeof(obj) / sizeof(typ))		//!< Computes the number of elements of \b obj following \b typ

//! \warning No nesting possible, use \a XCAT in this case
#define	CAT(a, b)			a##b			//!< Preprocessor Name concatenation
#define XCAT(a, b)			CAT(a, b)		//!< Preprocessor Name concatenation (possible nesting)

#define STR(s)				("" #s)			//!< Stringify an expression

#define binEval(exp)		((exp) ? true : false)		//!< boolean evaluation of expression \b exp
#define nbinEval(exp)		(!binEval(exp))				//!< complemented boolean evaluation of expression \b exp

#ifndef max
	#define max(a, b)		((a) >= (b) ? (a) : (b))	//!< Returns max value between \b a and \b b
#endif
#ifndef min
	#define min(a, b)		((a) <= (b) ? (a) : (b))	//!< Returns min value between \b a and \b b
#endif

#define	MIN3(a, b, c)		((b) <= (c) ? ((a) <= (b) ? (a) : (b)) : ((a) <= (c) ? (a) : (c)))	//!< Returns max value between \b a, \b b and \b c
#define	MAX3(a, b, c)		((b) >= (c) ? ((a) >= (b) ? (a) : (b)) : ((a) >= (c) ? (a) : (c)))	//!< Returns min value between \b a, \b b and \b c

#define CLAMP(v, min, max)	((v) < (min) ? (min) : ((v) > (max) ? (max) : (v)))		//!< Returns the value between \b min and \b max from \b val

#define OneThird			((float) (1.0 / 3.0))		//!< 1/3 approximation
#define TwoThird			((float) (2.0 / 3.0))		//!< 2/3 approximation

#define Pi					3.141593f		//!< Approximate Pi calculation (4 * atan(1))

#define RADIAN_TO_FLOAT(r)	((float) (((r) > 2*Pi ? 2*Pi : (r)) / 2*Pi))
#define FLOAT_TO_RADIAN(f)	((float) ((((f) > 1.0f ? 1.0f : (f)) < 0.0f ? 0.0f : (f)) * 2*Pi)

#define DEGREE_TO_FLOAT(d)	((float) (((d) > 360.0f ? 360.0f : (d)) / 360.0f))
#define FLOAT_TO_DEGREE(f)	((float) ((((f) > 1.0f ? 1.0f : (f)) < 0.0f ? 0.0f : (f)) * 360.0f))


#define	SWAP_BYTE(a, b)		{ BYTE c; c = a; a = b; b = c; }	//!< Swap BYTEs \b a \& \b b
#define	SWAP_WORD(a, b)		{ WORD c; c = a; a = b; b = c; }	//!< Swap WORDs \b a \& \b b
#define	SWAP_DWORD(a, b)	{ DWORD c; c = a; a = b; b = c; }	//!< Swap DWORDs \b a \& \b b


/****************************************************************/
#endif /* __ARM_MACROS_H */
/****************************************************************/
