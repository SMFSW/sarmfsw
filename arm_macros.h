/*!\file arm_macros.h
** \author SMFSW
** \version v0.7
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


#define MAKEWORD(b1, b2)	((WORD) (((BYTE) (b1)) | ((WORD) ((BYTE) (b2))) << 8))		//!< Make WORD from \b b1 and \b b2 with \b b1 as LSB
#define MAKELONG(w1, w2)	((DWORD) (((WORD) (w1)) | ((DWORD) ((WORD) (w2))) << 16))	//!< Make LONG from \b w1 and \b w2 with \b w1 as LSB
#define LOWORD(l)			((WORD) (l))												//!< Get WORD LSW from LONG \b l
#define HIWORD(l)			((WORD) ((DWORD) (l) >> 16))								//!< Get WORD MSW from LONG \b l
#define LOBYTE(w)			((BYTE) (w))												//!< Get BYTE LSB from WORD \b w
#define HIBYTE(w)			((BYTE) ((WORD) (w) >> 8))									//!< Get BYTE MSB from WORD \b w

#define BYTE_TO_PERC(b)		((BYTE) (((b) * 100) / 255))						//!< Converts a BYTE \b b (0-255) to percent (0-100)
#define PERC_TO_BYTE(p)		((BYTE) (((p) > 100 ? 100 : (p)) * 255 / 100))		//!< Converts a BYTE \b p percentage (0-100) to BYTE (0-255) with max checking

#define TPSSUP_MS(v, t)		((DWORD) (HAL_GetTick() - (DWORD) (v)) > (DWORD) (t))	//!< Tests if \b v (a HStart variable) has reached time lapse stated in \b t (ms)
#define TPSINF_MS(v, t)		((DWORD) (HAL_GetTick() - (DWORD) (v)) < (DWORD) (t))	//!< Tests if \b v (a HStart variable) has not reached time lapse stated in \b t (ms)

#define OFFSETOF(styp, mbr)	((size_t) & (((styp*)0)->mbr))	//!< Computes the offset member \b mbr from struct \b styp (extract from stdef.h)

#define	CAT(a, b)			a##b			//!< Macro de concaténation de noms (pas d'imbrication de la macro pour CAT car ## traité de façon particulière -\> dans ce cas, utiliser XCAT)
#define XCAT(a, b)			CAT(a, b)		//!< Macro de concaténation de noms (imbrication possible)

#define STR(s)				("" #s)			//!< Stringify an expression

#define	SWAP_BYTE(a, b)		{ BYTE c; c=(a); a=(b); b=c; }	//!< Macro de swap BYTEs \b a \& \b b
#define	SWAP_WORD(a, b)		{ WORD c; c=(a); a=(b); b=c; }	//!< Macro de swap WORDs \b a \& \b b
#define	SWAP_DWORD(a, b)	{ DWORD c; c=(a); a=(b); b=c; }	//!< Macro de swap DWORDs \b a \& \b b

#define SWAP_WD_ENDIAN(w)	((WORD) ((((WORD) (w) & 0x00FFU) << 8) | (((WORD) (w) & 0xFF00U) >> 8)))										//!< Swap 16bits endian
#define SWAP_DWD_ENDIAN(d)	((DWORD) ((SWAP_WD_ENDIAN((DWORD) (d) & 0xFFFFUL) << 16) | (SWAP_WD_ENDIAN((DWORD) (d) & 0xFFFF0000U) >> 16)))	//!< Swap 32bits endian
//!\warning SWAP_DWD_ENDIAN needs some testing

#ifndef max
	#define max(a, b)		((a) >= (b) ? (a) : (b))	//!< Returns max value between \b a and \b b
#endif
#ifndef min
	#define min(a, b)		((a) <= (b) ? (a) : (b))	//!< Returns min value between \b a and \b b
#endif

#define	MIN3(a, b, c)		((b) <= (c) ? ((a) <= (b) ? (a) : (b)) : ((a) <= (c) ? (a) : (c)))	//!< Returns max value between \b a, \b b and \b c
#define	MAX3(a, b, c)		((b) >= (c) ? ((a) >= (b) ? (a) : (b)) : ((a) >= (c) ? (a) : (c)))	//!< Returns min value between \b a, \b b and \b c

#define CLAMP(v, min, max)	((v) < (min) ? (min) : ((v) > (max) ? (max) : (v)))		//!< Returns the value between \b min and \b max from \b val

#define binEval(exp)		((exp) ? true : false)		//!< boolean evaluation of expression \b exp
#define nbinEval(exp)		(!binEval(exp))				//!< complemented boolean evaluation of expression \b exp


#define conv8upto16Bits(val, nb)	((WORD) ((WORD) ((val) << (nb)) + (WORD) ((val) & (0xFF >> (8-(nb))))))			//!< converts \b val (8bits) to \b 8+nb bits (nb must be comprised between 0 \& 8 bits)
//!\warning conversion output shall not exceed 16bits (input shall strictly be unsigned 8bits)
//!\warning nb shall be in range 0-8 (note that using 0 doesn't change val)

#define conv16upto32Bits(val, nb)	((DWORD) ((DWORD) ((val) << (nb)) + (DWORD) ((val) & (0xFFFF >> (16-(nb))))))	//!< converts \b val (16bits) to \b 16+nb bits (nb must be comprised between 0 \& 16 bits)
//!\warning conversion output shall not exceed 32bits (input shall strictly be unsigned 16bits)
//!\warning nb shall be in range 0-16 (note that using 0 doesn't change val)

#define Pi					3.141593f		//!< Approximate Pi calculation (4 * atan(1))

#define RADIAN_TO_FLOAT(r)	((float) (((r) > 2*Pi ? 2*Pi : (r)) / 2*Pi))
#define FLOAT_TO_RADIAN(f)	((float) ((((f) > 1.0f ? 1.0f : (f)) < 0.0f ? 0.0f : (f)) * 2*Pi)

#define DEGREE_TO_FLOAT(d)	((float) (((d) > 360.0f ? 360.0f : (d)) / 360.0f))
#define FLOAT_TO_DEGREE(f)	((float) ((((f) > 1.0f ? 1.0f : (f)) < 0.0f ? 0.0f : (f)) * 360.0f))

#define Def1Third			((float) (1.0f / 3.0f))
#define Def2Third			((float) (2.0f / 3.0f))


/*!\brief Checks if val given as parameter is in tolerance
** \param[in] val - Value to check
** \param[in] ref - Reference value
** \param[in] tolerance - Tolerance on reference value
** \return True if val is inTolerance
**/
inline bool __attribute__((__always_inline__)) inTolerance(int16_t val, int16_t ref, int16_t tolerance)
{
	tolerance = min(100, max(0, tolerance));
	register uint16_t margin = (uint16_t) (ref * ((float) tolerance / 100.0f));

	if ((val <= (int16_t) (ref + margin)) && (val >= (int16_t) (ref - margin)))		{ return true; }
	else																			{ return false; }
}

/*!\brief Checks if val given as parameter is in range
** \param[in] val - Value to check
** \param[in] low - Low range boundary
** \param[in] high - High range boundary
** \return True if val is inRange
**/
inline bool __attribute__((__always_inline__)) inRange(int16_t val, int16_t low, int16_t high)
{
	if ((val <= high) && (val >= low))	{ return true; }
	else								{ return false; }
}


/****************************************************************/
#endif /* __ARM_MACROS_H */
/****************************************************************/
