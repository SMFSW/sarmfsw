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

#define TPSSUP_MS(v, t)		((DWORD) (HAL_GetTick() - (DWORD) (v)) > (DWORD) (t))	//!< Tests if \b v (a HStart variable) has reached time lapse stated in \b t (ms)
#define TPSINF_MS(v, t)		((DWORD) (HAL_GetTick() - (DWORD) (v)) < (DWORD) (t))	//!< Tests if \b v (a HStart variable) has not reached time lapse stated in \b t (ms)

#define OFFSET_OF(typ, mbr)	((size_t) &(((typ*)0)->mbr))	//!< Computes the offset member \b mbr from struct \b typ
#define SZ_OBJ(obj, typ)	(sizeof(obj) / sizeof(typ))		//!< Computes the number of elements of \b obj following \b typ

//! \warning No possible nesting, use \a XCAT in this case
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

//!\warning conversion output shall not exceed 16bits (input shall strictly be unsigned 8bits)
//!\warning nb shall be in range 0-8 (note that using 0 doesn't change val)
#define conv8upto16Bits(val, nb)	((WORD) ((WORD) ((val) << (nb)) + (WORD) ((val) & (0xFF >> (8-(nb))))))			//!< converts \b val (8bits) to \b 8+nb bits (nb must be comprised between 0 \& 8 bits)

//!\warning conversion output shall not exceed 32bits (input shall strictly be unsigned 16bits)
//!\warning nb shall be in range 0-16 (note that using 0 doesn't change val)
#define conv16upto32Bits(val, nb)	((DWORD) ((DWORD) ((val) << (nb)) + (DWORD) ((val) & (0xFFFF >> (16-(nb))))))	//!< converts \b val (16bits) to \b 16+nb bits (nb must be comprised between 0 \& 16 bits)


#define	SWAP_BYTE(a, b)		{ BYTE c; c=(a); a=(b); b=c; }	//!< Swap BYTEs \b a \& \b b
#define	SWAP_WORD(a, b)		{ WORD c; c=(a); a=(b); b=c; }	//!< Swap WORDs \b a \& \b b
#define	SWAP_DWORD(a, b)	{ DWORD c; c=(a); a=(b); b=c; }	//!< Swap DWORDs \b a \& \b b


/*!\brief Swap endians of the contents of a 16b value
** \param[in] w - 16b value
** \return Swapped value
**/
inline uint16_t INLINE__ SWAP_END16B(uint16_t w) {
	return (uint16_t) ((((w) & 0xFFU) * 0x100) | (((w) & 0xFF00U) / 0x100)); }

/*!\brief Swap endians of the contents of a 32b value
** \param[in] d - 32b value
** \return Swapped value
**/
inline uint32_t INLINE__ SWAP_END32B(uint32_t d) {
	return (uint32_t) ((SWAP_END16B((d) & 0xFFFFUL) * 0x10000) | SWAP_END16B(((d) & 0xFFFF0000UL) / 0x10000)); }


/*!\brief Swap endians of a 16b tab
** \param[in] tab - tab of 16b values
** \param[in] nb - nb of values in tab
**/
inline void INLINE__ SWAP_END16B_TAB(uint16_t tab[], uint16_t nb) {
	for (int i = 0 ; i < nb ; i++)	tab[i] = SWAP_END16B(tab[i]); }

/*!\brief Swap endians of a 32b tab
** \param[in] tab - tab of 32b values
** \param[in] nb - nb of values in tab
**/
inline void INLINE__ SWAP_END32B_TAB(uint32_t tab[], uint16_t nb) {
	for (int i = 0 ; i < nb ; i++)	tab[i] = SWAP_END32B(tab[i]); }


/*!\brief Checks if val given as parameter is in tolerance
** \param[in] val - Value to check
** \param[in] ref - Reference value
** \param[in] tolerance - Tolerance on reference value
** \return True if val is inTolerance
**/
inline bool INLINE__ inTolerance(int16_t val, int16_t ref, int16_t tolerance)
{
	tolerance = min(100, max(0, tolerance));
	register uint16_t margin = (uint16_t) (ref * ((float) tolerance / 100.0f));

	if ((val <= (int16_t) (ref + margin)) && (val >= (int16_t) (ref - margin))) return true;
	return false;
}

/*!\brief Checks if val given as parameter is in range
** \param[in] val - Value to check
** \param[in] low - Low range boundary
** \param[in] high - High range boundary
** \return True if val is inRange
**/
inline bool INLINE__ inRange(int16_t val, int16_t low, int16_t high)
{
	if ((val <= high) && (val >= low)) return true;
	return false;
}


/****************************************************************/
#endif /* __ARM_MACROS_H */
/****************************************************************/
