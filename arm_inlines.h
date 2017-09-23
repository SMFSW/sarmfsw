/*!\file arm_inlines.h
** \author SMFSW
** \date 2017
** \copyright MIT (c) 2017, SMFSW
** \brief ARM common inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_H
	#define __ARM_INLINES_H

#include "arm_attributes.h"		// Attributes depending compiler
#include "arm_cmsis.h"			// HAL & Drivers depending platform
#include CMSIS_INC				// CMSIS includes
/****************************************************************/


/*!\brief Tests if stored time value has reached time lapse in ms
** \param[in] val - stored time value
** \param[in] time - time lapse (in ms)
** \return true if time elapsed
**/
__INLINE bool INLINE__ TPSSUP_MS(uint32_t val, uint32_t time) {
	return ((DWORD) (HAL_GetTick() - (DWORD) (val)) > (DWORD) (time)); }

/*!\brief Tests if stored time value has not reached time lapse in ms
** \param[in] val - stored time value
** \param[in] time - time lapse (in ms)
** \return true if time not elapsed
**/
__INLINE bool INLINE__ TPSINF_MS(uint32_t val, uint32_t time) {
	return ((DWORD) (HAL_GetTick() - (DWORD) (val)) < (DWORD) (time)); }


/*!\brief converts 8bits to 8+nb bits (16bits max)
** \warning conversion output shall not exceed 16bits (input shall strictly be unsigned 8bits)
** \warning nb shall be in range 0-8 (note that using 0 doesn't change val)
** \param[in] val - 8b value to convert
** \param[in] nb - number of bits to add (8bits max)
** \return Converted value
**/
__INLINE uint16_t INLINE__ conv8upto16Bits(uint8_t val, uint8_t nb) {
	return ((WORD) ((WORD) ((val) << (nb)) + (WORD) ((val) & (0xFF >> (8-(nb)))))); }


/*!\brief converts 16bits to 16+nb bits (32bits max)
** \warning conversion output shall not exceed 32bits (input shall strictly be unsigned 16bits)
** \warning nb shall be in range 0-16 (note that using 0 doesn't change val)
** \param[in] val - 16b value to convert
** \param[in] nb - number of bits to add (16bits max)
** \return Converted value
**/
__INLINE uint32_t INLINE__ conv16upto32Bits(uint16_t val, uint8_t nb) {
	return ((DWORD) ((DWORD) ((val) << (nb)) + (DWORD) ((val) & (0xFFFF >> (16-(nb)))))); }


/*!\brief Swap endians of the contents of a 16b value
** \param[in] w - 16b value
** \return Swapped value
**/
__INLINE uint16_t INLINE__ SWAP_END16B(uint16_t w) {
	return (uint16_t) ((((w) & 0xFFU) * 0x100) | (((w) & 0xFF00U) / 0x100)); }

/*!\brief Swap endians of the contents of a 32b value
** \param[in] d - 32b value
** \return Swapped value
**/
__INLINE uint32_t INLINE__ SWAP_END32B(uint32_t d) {
	return (uint32_t) ((SWAP_END16B((d) & 0xFFFFUL) * 0x10000) | SWAP_END16B(((d) & 0xFFFF0000UL) / 0x10000)); }


/*!\brief Swap endians of a 16b tab
** \param[in] tab - tab of 16b values
** \param[in] nb - nb of values in tab
**/
__INLINE void INLINE__ SWAP_END16B_TAB(uint16_t tab[], uint16_t nb) {
	for (int i = 0 ; i < nb ; i++)	tab[i] = SWAP_END16B(tab[i]); }

/*!\brief Swap endians of a 32b tab
** \param[in] tab - tab of 32b values
** \param[in] nb - nb of values in tab
**/
__INLINE void INLINE__ SWAP_END32B_TAB(uint32_t tab[], uint16_t nb) {
	for (int i = 0 ; i < nb ; i++)	tab[i] = SWAP_END32B(tab[i]); }


/*!\brief Checks if val given as parameter is in tolerance
** \param[in] val - Value to check
** \param[in] ref - Reference value
** \param[in] tolerance - Tolerance on reference value (in percent)
** \return true if val is inTolerance
**/
__INLINE bool INLINE__ inTolerance(int32_t val, int32_t ref, int32_t tolerance)
{
	tolerance = min(100, max(0, tolerance));
	register uint32_t margin = (uint32_t) (ref * ((float) tolerance / 100.0f));

	return ((val <= (int32_t) (ref + margin)) && (val >= (int32_t) (ref - margin)));
}

/*!\brief Checks if val given as parameter is in range
** \param[in] val - Value to check
** \param[in] low - Low range boundary
** \param[in] high - High range boundary
** \return true if val is inRange
**/
__INLINE bool INLINE__ inRange(int32_t val, int32_t low, int32_t high) {
	return ((val <= high) && (val >= low)); }


/****************************************************************/
#endif /* __ARM_INLINES_H */
/****************************************************************/
