/*!\file arm_inlines_float.h
** \author SMFSW
** \copyright MIT (c) 2017-2021, SMFSW
** \brief Floating point manipulation inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_FLOAT_H
	#define __ARM_INLINES_FLOAT_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <math.h>
#include "arm_typedefs.h"			// Common typedefs
/****************************************************************/


/*!\brief Get floating point number decimal part (as absolute value)
** \note if in need to print floats, you can add '-u _printf_float' in Linker options instead of using get_fp_dec.
** \param[in] f - floating point value
** \param[in] nb - Number of decimal to get after floating point (limited to 9 internally for proper result on 32b return type)
** \return nb decimal part as unsigned integer
**/
__INLINE DWORD get_fp_dec(const double f, BYTE nb)
{
	DWORD mul = 1;

	nb = min(9, nb);	// Limit to 9 digits
	while (nb-- != 0) 	{ mul *= 10; }

	return (DWORD) (fabs(f - (SDWORD) f) * mul);
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_FLOAT_H */
/****************************************************************/
