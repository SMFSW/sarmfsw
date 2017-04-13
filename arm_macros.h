/*!\file arm_macros.h
** \author SMFSW
** \version v0.3
** \date 2017
** \copyright MIT (c) 2017, SMFSW
** \brief ARM common macros
*/
/****************************************************************/
#ifndef __ARM_MACROS_H
	#define __ARM_MACROS_H
/****************************************************************/

#include "arm_typedefs.h"


#define MAKEWORD(b1, b2)	((WORD) (((BYTE) (b1)) | ((WORD) ((BYTE) (b2))) << 8))		//!< Make WORD from \b b1 and \b b2 with \b b1 as LSB
#define MAKELONG(w1, w2)	((DWORD) (((WORD) (w1)) | ((DWORD) ((WORD) (w2))) << 16))	//!< Make LONG from \b w1 and \b w2 with \b w1 as LSB
#define LOWORD(l)			((WORD) (l))												//!< Get WORD LSW from LONG \b l
#define HIWORD(l)			((WORD) ((DWORD) (l) >> 16))								//!< Get WORD MSW from LONG \b l
#define LOBYTE(w)			((BYTE) (w))												//!< Get BYTE LSB from WORD \b w
#define HIBYTE(w)			((BYTE) ((WORD) (w) >> 8))									//!< Get BYTE MSB from WORD \b w

#define BYTE_TO_PERC(b)		((BYTE) ((b * 100) / DefMsqBYTE))					//!< Converts a BYTE \b b (0-255) to percent (0-100)
#define PERC_TO_BYTE(p)		((BYTE) ((p > 100 ? 100 : p) * DefMsqBYTE / 100))	//!< Converts a BYTE \b p percentage (0-100) to BYTE (0-255) with max checking

#define TPSSUP_MS(v, t)		((DWORD) (HAL_GetTick() - (DWORD) v) > (DWORD) t)	//!< Tests if \b v (a HStart variable) has reached time lapse stated in \b t (ms)
#define TPSINF_MS(v, t)		((DWORD) (HAL_GetTick() - (DWORD) v) < (DWORD) t)	//!< Tests if \b v (a HStart variable) has not reached time lapse stated in \b t (ms)

#define OFFSETOF(styp, mbr)	((size_t) & (((styp*)0)->mbr))	//!< Computes the offset member \b mbr from struct \b styp (extract from stdef.h)

#define	CAT(a, b)			a##b			//!< Macro de concaténation de noms (pas d'imbrication de la macro pour CAT car ## traité de façon particulière -\> dans ce cas, utiliser XCAT)
#define XCAT(a, b)			CAT(a, b)		//!< Macro de concaténation de noms (imbrication possible)

#define	SWAP_BYTE(a, b)		{ BYTE c; c=(a); a=(b); b=c; }	//!< Macro de swap BYTEs \b a \& \b b
#define	SWAP_WORD(a, b)		{ WORD c; c=(a); a=(b); b=c; }	//!< Macro de swap WORDs \b a \& \b b
#define	SWAP_DWORD(a, b)	{ DWORD c; c=(a); a=(b); b=c; }	//!< Macro de swap DWORDs \b a \& \b b

#ifndef max
	#define max(a, b)		(a >= b ? a : b)	//!< Returns max value between \b a and \b b
#endif
#ifndef min
	#define min(a, b)		(a <= b ? a : b)	//!< Returns min value between \b a and \b b
#endif


#define CLAMP(val, min, max)	((val) < (min) ? (min) : ((val) > (max) ? (max) : (val)))	//!< Returns the value between \b min and \b max from \b val

/****************************************************************/
#endif /* __ARM_MACROS_H */
/****************************************************************/
