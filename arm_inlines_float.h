/*!\file arm_inlines_float.h
** \author SMFSW
** \copyright MIT (c) 2017-2024, SMFSW
** \brief Floating point manipulation inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_FLOAT_H
	#define __ARM_INLINES_FLOAT_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <math.h>
/****************************************************************/


//!< \warning Sign does not work for values between 0 and -1 (sign is lost)
#define SPLIT_FLOAT_TO_INTS(val, nb_frac)	(SDWORD) (val), get_fp_dec((val), (nb_frac))	//!< Split float value \b val into 2 integers with \b nb_frac fractional part digits


/*!\struct sIntFrac
** \brief Float representation on integers
**/
typedef struct sIntFrac {
	DWORD	integer;		//!< Integer part
	DWORD	fractionnal;	//!< Fractional part
	BYTE	nb_frac;		//!< Number of fractional digits
	BOOL	sign;			//!< Sign: true if negative
} sIntFrac;


/*!\brief Get floating point number decimal part (as absolute value)
** \note if in need to print floats, you can add '-u _printf_float' in Linker options instead of using get_fp_dec.
** 		 Otherwise, \ref SPLIT_FLOAT_TO_INTS may be used to ease the formatting process for printf like functions.
** \param[in] f - floating point value
** \param[in] nb - Number of decimal to get after floating point (limited to 9 internally for proper result on 32b return type)
** \return nb decimal part as unsigned integer
**/
__INLINE DWORD get_fp_dec(const double f, const BYTE nb)
{
	BYTE digits = MIN(9, nb);	// Limit to 9 digits
	DWORD mul = 1;

	while (digits-- > 0) 	{ mul *= 10; }

	return (DWORD) (fabs(f - (SDWORD) f) * mul);
}


/*!\brief Convert floating point representation to sIntFrac integers representation
** \param[in,out] pIntFrac - Pointer to result structure
** \param[in] f - floating point value to convert
** \param[in] nb - Number of decimal to get after floating point (limited to 9 internally for proper result on 32b return type)
**/
__INLINE void NONNULL__ float2sIntFrac(sIntFrac * const pIntFrac, const double f, const uint8_t nb_frac)
{
	pIntFrac->nb_frac = MIN(9, nb_frac);	// Limit to 9 digits
	pIntFrac->sign = binEval(f < 0.0);
	pIntFrac->integer = (DWORD) (f);
	pIntFrac->fractionnal = get_fp_dec(f, nb_frac);
}


/*!\brief Convert sIntFrac integers representation to floating point representation
** \param[in,out] pFloat - Pointer to floating point result
** \param[in] pIntFrac - Pointer to sIntFrac structure to convert
**/
__INLINE void NONNULL__ sIntFrac2float(double * const pFloat, const sIntFrac * const pIntFrac)
{
	*pFloat = pIntFrac->fractionnal;
	for (uintCPU_t i = pIntFrac->nb_frac ; i ; i--)	{ *pFloat /= 10.0; }

	*pFloat += pIntFrac->integer;

	if (pIntFrac->sign)	{ *pFloat = -*pFloat; }
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_FLOAT_H */
/****************************************************************/
