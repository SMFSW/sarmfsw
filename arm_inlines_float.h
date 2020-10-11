/*!\file arm_inlines_float.h
** \author SMFSW
** \copyright MIT (c) 2017-2020, SMFSW
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
** \note in need to print floats, add '-u _printf_float' in Linker options.
** \warning enabling floating point support from linker seems to fubar printing long variables,
** 			so welcome get_fp_dec for the purpose.
** \param[in] f - floating point value
** \param[in] nb - Number of decimal to get after floating point
** \return nb decimal part as unsigned integer
**/
__INLINE DWORD get_fp_dec(const float f, BYTE nb)
{
	DWORD mul = 1;

	while (nb-- != 0) { mul *= 10; }

	return (DWORD) (fabs(f - (SDWORD) f) * mul);
}



/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_FLOAT_H */
/****************************************************************/