/*!\file arm_macros.h
** \author SMFSW
** \copyright MIT (c) 2017-2019, SMFSW
** \brief ARM common macros
*/
/****************************************************************/
#ifndef __ARM_MACROS_H
	#define __ARM_MACROS_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "arm_typedefs.h"		// Common typedefs
/****************************************************************/


#define	Undefined			-1				//!< Undefined value

#define Null				0				//!< Null Value
#define pNull				(void *) 0		//!< Null pointer -> same as NULL in stdlib.h
#define	charNUL				'\0'			//!< Null Char


#ifndef True
	#define	True			true			//!< \b True alias for \b true
#endif
#ifndef False
	#define	False			false			//!< \b False alias for \b false
#endif
#ifndef TRUE
	#define	TRUE			true			//!< \b TRUE alias for \b true
#endif
#ifndef FALSE
	#define	FALSE			false			//!< \b FALSE alias for \b false
#endif

//!\warning this macro is optimized only when used with \b b with a static value
#define LSHIFT(v, b)		((v) * (1UL << b))											//!< Shift \b v \b b bits left (up to 31b)
//!\warning this macro is optimized only when used with \b b with a static value
#define RSHIFT(v, b)		((v) / (1UL << b))											//!< Shift \b v \b b bits right (up to 31b)
//!\warning this macro is optimized only when used with \b b with a static value
#define LSHIFT64(v, b)		((v) * (1ULL << b))											//!< Shift \b v \b b bits left (up to 63b)
//!\warning this macro is optimized only when used with \b b with a static value
#define RSHIFT64(v, b)		((v) / (1ULL << b))											//!< Shift \b v \b b bits right (up to 63b)

#define MAKEWORD(lsb, msb)	((WORD) (((BYTE) (lsb)) | LSHIFT(((WORD) ((BYTE) (msb))), 8)))		//!< Make WORD from \b lsb and \b msb
#define MAKELONG(lsw, msw)	((DWORD) (((WORD) (lsw)) | LSHIFT(((DWORD) ((WORD) (msw))), 16)))	//!< Make LONG from \b lsw and \b msw


#ifdef LOBYTE
#undef LOBYTE	//!\note Undefine LOBYTE if already defined in some other library
#endif

#ifdef HIBYTE
#undef HIBYTE	//!\note Undefine HIBYTE if already defined in some other library
#endif

#define LOBYTE(w)			((BYTE) (w))						//!< Get BYTE LSB from WORD \b w
#define HIBYTE(w)			((BYTE) RSHIFT((WORD) (w), 8))		//!< Get BYTE MSB from WORD \b w
#define LOWORD(l)			((WORD) (l))						//!< Get WORD LSW from LONG \b l
#define HIWORD(l)			((WORD) RSHIFT((DWORD) (l), 16))	//!< Get WORD MSW from LONG \b l

#define	SWAP_TYPE(a, b, typ)	{ typ c = a; a = b; b = c; }	//!< Swap type \b typ \b a \& \b b
#define	SWAP_BYTE(a, b)			SWAP_TYPE(a, b, BYTE)			//!< Swap BYTEs \b a \& \b b
#define	SWAP_WORD(a, b)			SWAP_TYPE(a, b, WORD)			//!< Swap WORDs \b a \& \b b
#define	SWAP_DWORD(a, b)		SWAP_TYPE(a, b, DWORD)			//!< Swap DWORDs \b a \& \b b
#define	SWAP_LWORD(a, b)		SWAP_TYPE(a, b, LWORD)			//!< Swap LWORDs \b a \& \b b
#define	SWAP_FLOAT(a, b)		SWAP_TYPE(a, b, float)			//!< Swap floats \b a \& \b b
#define	SWAP_DOUBLE(a, b)		SWAP_TYPE(a, b, double)			//!< Swap doubles \b a \& \b b

#define VAL_AT(addr, typ)		(*(typ *) (addr))										//!< Get the type \b typ content of address \b addr

#define SZ_OBJ(obj, typ)		((size_t) (sizeof(obj) / sizeof(typ)))					//!< Computes the number of elements in \b obj of type \b typ
#define SZ_TYP_MBR(typ, mbr)	((size_t) sizeof(((typ *)0)->mbr))						//!< Computes the size of member \b mbr in struct type \b typ

#define TYP_MBR(typ, mbr)		(((typ *)0)->mbr)										//!< Get member \b mbr from a struct type \b typ
#define TYP_MBR_TYP(typ, mbr)	typeof(TYP_MBR(typ, mbr))								//!< Get typeof member \b mbr from a struct type \b typ (no () as it wouldn't work for pointers to member type)

#define OFFSET_OF(typ, mbr)		((size_t) &(((typ *)0)->mbr))							//!< Computes the offset member \b mbr from struct type \b typ
#define ROOT_OF(ptr, typ, mbr)	((typ *) (((uint8_t *) ptr) - OFFSET_OF(typ, mbr)))		//!< Computes the address of parent struct \b typ of \b ptr from member \b mbr

//! \warning No nesting possible, use \a XCAT in this case
#define	CAT(a, b)			a##b			//!< Preprocessor Name catenation
#define XCAT(a, b)			CAT(a, b)		//!< Preprocessor Name catenation (possible nesting)

#define STR(s)				(#s)			//!< Stringify an expression

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

#define BYTE_TO_PERC(b)		((BYTE) (((b) * 100) / 255))						//!< Converts a BYTE \b b (0-255) to percent (0-100)
#define PERC_TO_BYTE(p)		((BYTE) (((p) > 100 ? 100 : (p)) * 255 / 100))		//!< Converts a BYTE \b p percentage (0-100) to BYTE (0-255) with max checking

#define RAD_TO_FLOAT(r)		((float) (((r) > 2*Pi ? 2*Pi : (r)) / 2*Pi))
#define FLOAT_TO_RAD(f)		((float) ((((f) > 1.0f ? 1.0f : (f)) < 0.0f ? 0.0f : (f)) * 2*Pi)

#define DEG_TO_FLOAT(d)		((float) (((d) > 360.0f ? 360.0f : (d)) / 360.0f))
#define FLOAT_TO_DEG(f)		((float) ((((f) > 1.0f ? 1.0f : (f)) < 0.0f ? 0.0f : (f)) * 360.0f))


/*** Test Macros ***/
#define malloc_assert(x)	((x) = malloc(sizeof(*x)), assert(x))	//!< Asserted malloc


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_MACROS_H */
/****************************************************************/
