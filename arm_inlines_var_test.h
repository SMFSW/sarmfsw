/*!\file arm_inlines_var_test.h
** \author SMFSW
** \copyright MIT (c) 2017-2024, SMFSW
** \brief Variables test inlines
*/
/****************************************************************/
#ifndef ARM_INLINES_VAR_TEST_H_
	#define ARM_INLINES_VAR_TEST_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


/*!\brief Checks if val given as parameter is in tolerance
** \param[in] val - Value to check
** \param[in] ref - Reference value
** \param[in] tolerance - Tolerance on reference value (in percent)
** \return true if val is inTolerance
**/
__INLINE BOOL inTolerance(const SDWORD val, const SDWORD ref, const float tolerance)
{
	const float ratio = MIN(100.0f, MAX(0.0f, tolerance)) / 100.0f;

	SDWORD hyst = (SDWORD) ((float) ref * ratio);
	if (hyst < 0.0f)	{ hyst = -hyst; }

	return ((val <= (SDWORD) (ref + hyst)) && (val >= (SDWORD) (ref - hyst)));
}


/*!\brief Checks if val given as parameter is in range
** \param[in] val - Value to check
** \param[in] low - Low range boundary
** \param[in] high - High range boundary
** \return true if val is inRange
**/
__INLINE BOOL INLINE__ inRange(const SDWORD val, const SDWORD low, const SDWORD high)
{
	return ((val <= high) && (val >= low));
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_INLINES_VAR_TEST_H_ */
/****************************************************************/
