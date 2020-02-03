/*!\file arm_inlines_var_test.h
** \author SMFSW
** \copyright MIT (c) 2017-2020, SMFSW
** \brief Variables test inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_VAR_TEST_H
	#define __ARM_INLINES_VAR_TEST_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "arm_typedefs.h"			// Common typedefs
/****************************************************************/


/*!\brief Checks if val given as parameter is in tolerance
** \param[in] val - Value to check
** \param[in] ref - Reference value
** \param[in] tolerance - Tolerance on reference value (in percent)
** \return true if val is inTolerance
**/
__INLINE bool inTolerance(const SDWORD val, const SDWORD ref, float tolerance)
{
	tolerance = min(100.0f, max(0.0f, tolerance));

	const DWORD margin = (DWORD) (ref * (tolerance / 100.0f));

	return ((val <= (SDWORD) (ref + margin)) && (val >= (SDWORD) (ref - margin)));
}


/*!\brief Checks if val given as parameter is in range
** \param[in] val - Value to check
** \param[in] low - Low range boundary
** \param[in] high - High range boundary
** \return true if val is inRange
**/
__INLINE bool INLINE__ inRange(const SDWORD val, const SDWORD low, const SDWORD high)
{
	return ((val <= high) && (val >= low));
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_VAR_TEST_H */
/****************************************************************/
