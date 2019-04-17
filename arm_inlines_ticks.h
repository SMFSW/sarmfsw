/*!\file arm_inlines_ticks.h
** \author SMFSW
** \copyright MIT (c) 2017-2019, SMFSW
** \brief Ticks related inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_TICKS_H
	#define __ARM_INLINES_TICKS_H

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


/*!\brief Tests if stored time value has reached time lapse in ms
** \warning For SAM families, no ms base time counter is implemented in HAL,
**			please refer to arm_chip_sam.h for an implementation example.
** \note	Define custom HAL_MS_TICKS_FACTOR at project level if tick period is not 1ms
** \param[in] last - stored time value
** \param[in] time - time lapse (in ms)
** \return true if time elapsed
**/
__INLINE bool INLINE__ TPSSUP_MS(const DWORD last, const DWORD time)
{
	register const DWORD	hNow = HALTicks();
	const DWORD				diff = (hNow >= last) ? hNow - last : (HAL_MAX_TICKS - last) + hNow;

	return (diff > (DWORD) (time * HAL_MS_TICKS_FACTOR));
}


/*!\brief Tests if stored time value has not reached time lapse in ms
** \warning For SAM families, no ms base time counter is implemented in HAL,
**			please refer to arm_chip_sam.h for an implementation example.
** \note	Define custom HAL_MS_TICKS_FACTOR at project level if tick period is not 1ms
** \param[in] last - stored time value
** \param[in] time - time lapse (in ms)
** \return true if time not elapsed
**/
__INLINE bool INLINE__ TPSINF_MS(const DWORD last, const DWORD time)
{
	register const DWORD	hNow = HALTicks();
	const DWORD				diff = (hNow >= last) ? hNow - last : (HAL_MAX_TICKS - last) + hNow;

	return (diff < (DWORD) (time * HAL_MS_TICKS_FACTOR));
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_TICKS_H */
/****************************************************************/
