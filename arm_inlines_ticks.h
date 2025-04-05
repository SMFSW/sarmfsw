/*!\file arm_inlines_ticks.h
** \author SMFSW
** \copyright MIT (c) 2017-2025, SMFSW
** \brief Ticks related inlines
*/
/****************************************************************/
#ifndef ARM_INLINES_TICKS_H_
	#define ARM_INLINES_TICKS_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


/*!\brief Tests if stored time value has reached time lapse in ms
** \warning For SAM families, no ms base time counter is implemented in HAL,
**			please refer to arm_chip_sam.h for an implementation example.
** \note	Define custom HAL_MS_TICKS_FACTOR at project level if tick period is not 1ms
** \param[in] prev - previously stored time value
** \param[in] lapse - time lapse (in ms)
** \return true if time elapsed
**/
__INLINE BOOL INLINE__ TPSSUP_MS(const DWORD prev, const DWORD lapse)
{
	const DWORD scaled_time = lapse * HAL_MS_TICKS_FACTOR;
	const DWORD diff = OVF_DIFF(HALTicks(), prev);

	return binEval(diff >= scaled_time);
}


/*!\brief Tests if stored time value has not reached time lapse in ms
** \warning For SAM families, no ms base time counter is implemented in HAL,
**			please refer to arm_chip_sam.h for an implementation example.
** \note	Define custom HAL_MS_TICKS_FACTOR at project level if tick period is not 1ms
** \param[in] prev - previously stored time value
** \param[in] lapse - time lapse (in ms)
** \return true if time not elapsed
**/
__INLINE BOOL INLINE__ TPSINF_MS(const DWORD prev, const DWORD lapse)
{
	const DWORD diff = OVF_DIFF(HALTicks(), prev);
	const DWORD scaled_time = lapse * HAL_MS_TICKS_FACTOR;

	return binEval(diff < scaled_time);
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_INLINES_TICKS_H_ */
/****************************************************************/
