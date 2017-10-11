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
/****************************************************************/


/********************/
/***  TIME TESTS  ***/
/********************/

/*!\brief Tests if stored time value has reached time lapse in ms
** \param[in] val - stored time value
** \param[in] time - time lapse (in ms)
** \return true if time elapsed
**/
__INLINE bool INLINE__ TPSSUP_MS(DWORD val, DWORD time) {
	return ((DWORD) (HAL_GetTick() - (DWORD) (val)) > (DWORD) (time)); }

/*!\brief Tests if stored time value has not reached time lapse in ms
** \param[in] val - stored time value
** \param[in] time - time lapse (in ms)
** \return true if time not elapsed
**/
__INLINE bool INLINE__ TPSINF_MS(DWORD val, DWORD time) {
	return ((DWORD) (HAL_GetTick() - (DWORD) (val)) < (DWORD) (time)); }


/*******************************/
/***  GRAY CODE CONVERSIONS  ***/
/*******************************/

/*!\brief Convert binary value to gray code
** \param[in] bin - binary value
** \return Converted value (gray code)
**/
__INLINE DWORD bin2gray(DWORD bin) {
	return RSHIFT(bin, 1) ^ bin; }

/*!\brief Convert gray code to binary value
** \param[in] gray - gray code value
** \return Converted value (binary)
**/
__INLINE DWORD gray2bin(DWORD gray)
{
	int bits = 32;
	DWORD tmp = gray;
	
	while ((bits >>= 1) > 0)	{ tmp ^= (tmp >> bits); }
	return tmp;
}


/******************************/
/***  VAR SIZE CONVERSIONS  ***/
/******************************/

/*!\brief converts 16bits to 8bits
** \param[in] val - 16b value to convert
** \return Converted value
**/
__INLINE BYTE INLINE__ conv16to8Bits(WORD val) {
	return (BYTE) RSHIFT(val, 8); }

/*!\brief converts 8bits to 16bits
** \param[in] val - 8b value to convert
** \return Converted value
**/
__INLINE WORD INLINE__ conv8to16Bits(BYTE val) {
	return (WORD) (LSHIFT(val, 8) + val); }


/*!\brief converts 8bits to 8+nb bits (16bits max)
** \warning conversion output shall not exceed 16bits (input shall strictly be unsigned 8bits)
** \warning nb shall be in range 0-8 (note that using 0 doesn't change val)
** \param[in] val - 8b value to convert
** \param[in] nb - number of bits to add (8bits max)
** \return Converted value
**/
__INLINE WORD conv8upto16Bits(BYTE val, BYTE nb) {
	return ((WORD) ((WORD) (val << nb) + (WORD) (val & (0xFF >> (8-nb))))); }

/*!\brief converts 16bits to 16+nb bits (32bits max)
** \warning conversion output shall not exceed 32bits (input shall strictly be unsigned 16bits)
** \warning nb shall be in range 0-16 (note that using 0 doesn't change val)
** \param[in] val - 16b value to convert
** \param[in] nb - number of bits to add (16bits max)
** \return Converted value
**/
__INLINE DWORD conv16upto32Bits(WORD val, BYTE nb) {
	return ((DWORD) ((DWORD) (val << nb) + (DWORD) (val & (0xFFFF >> (16-nb))))); }

/*!\brief converts 32bits to 32+nb bits (64bits max)
** \warning conversion output shall not exceed 64bits (input shall strictly be unsigned 32bits)
** \warning nb shall be in range 0-32 (note that using 0 doesn't change val)
** \param[in] val - 32b value to convert
** \param[in] nb - number of bits to add (32bits max)
** \return Converted value
**/
__INLINE LWORD conv32upto64Bits(DWORD val, BYTE nb) {
	return ((LWORD) ((LWORD) (val << nb) + (LWORD) (val & (0xFFFFFFFF >> (32-nb))))); }


/*****************************/
/***  ENDIANS CONVERSIONS  ***/
/*****************************/

/*!\brief Swap endians of the contents of a 16b value
** \param[in] w - 16b value
** \return Swapped value
**/
__INLINE WORD SWAP_END16B(WORD w) {
	return (WORD) (LSHIFT((w & 0xFF), 8) | RSHIFT((w & 0xFF00), 8)); }

/*!\brief Swap endians of the contents of a 32b value
** \param[in] d - 32b value
** \return Swapped value
**/
__INLINE DWORD SWAP_END32B(DWORD d) {
	return (DWORD) (LSHIFT(SWAP_END16B(d & 0xFFFF), 16) | SWAP_END16B(RSHIFT((d & 0xFFFF0000), 16))); }

/*!\brief Swap endians of the contents of a 64b value
** \param[in] d - 64b value
** \return Swapped value
**/
__INLINE LWORD SWAP_END64B(LWORD l) {
	//!\warning need to be tested
	return (LWORD) (LSHIFT_L(SWAP_END32B(l & 0xFFFFFFFF), 32) | SWAP_END32B(RSHIFT_L((l & 0xFFFFFFFF00000000), 32))); }


/*!\brief Swap endians of a 16b tab
** \param[in] tab - tab of 16b values
** \param[in] nb - nb of values in tab
**/
__INLINE void INLINE__ SWAP_END16B_TAB(WORD tab[], WORD nb) {
	for (int i = 0 ; i < nb ; i++)	tab[i] = SWAP_END16B(tab[i]); }

/*!\brief Swap endians of a 32b tab
** \param[in] tab - tab of 32b values
** \param[in] nb - nb of values in tab
**/
__INLINE void INLINE__ SWAP_END32B_TAB(DWORD tab[], WORD nb) {
	for (int i = 0 ; i < nb ; i++)	tab[i] = SWAP_END32B(tab[i]); }

/*!\brief Swap endians of a 64b tab
** \param[in] tab - tab of 64b values
** \param[in] nb - nb of values in tab
**/
__INLINE void INLINE__ SWAP_END64B_TAB(LWORD tab[], WORD nb) {
	for (int i = 0 ; i < nb ; i++)	tab[i] = SWAP_END64B(tab[i]); }


/************************/
/***  VALUES TESTING  ***/
/************************/

/*!\brief Checks if val given as parameter is in tolerance
** \param[in] val - Value to check
** \param[in] ref - Reference value
** \param[in] tolerance - Tolerance on reference value (in percent)
** \return true if val is inTolerance
**/
__INLINE bool inTolerance(SDWORD val, SDWORD ref, SDWORD tolerance)
{
	tolerance = min(100, max(0, tolerance));
	DWORD margin = (DWORD) (ref * ((float) tolerance / 100.0f));
	return ((val <= (SDWORD) (ref + margin)) && (val >= (SDWORD) (ref - margin)));
}

/*!\brief Checks if val given as parameter is in range
** \param[in] val - Value to check
** \param[in] low - Low range boundary
** \param[in] high - High range boundary
** \return true if val is inRange
**/
__INLINE bool INLINE__ inRange(SDWORD val, SDWORD low, SDWORD high) {
	return ((val <= high) && (val >= low)); }


/****************************************************************/
#endif /* __ARM_INLINES_H */
/****************************************************************/
