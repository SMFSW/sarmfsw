/*!\file arm_inlines_average.h
** \author SMFSW
** \copyright MIT (c) 2017-2020, SMFSW
** \brief Averaging inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_AVERAGE_H
	#define __ARM_INLINES_AVERAGE_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "arm_typedefs.h"			// Common typedefs
/****************************************************************/


#define	RESTRICTED_AVERAGE(typ_t, sum_t)																					\
__INLINE typ_t RestrictedAverage_##typ_t(volatile typ_t pArray[], const uint8_t nb)											\
{																															\
	typ_t	Array[nb];																										\
	sum_t	sum = 0;																										\
																															\
	if (nb <= 2)	{ return 0; }																							\
																															\
	/* Array copy (memcpy not used as copy by byte and pTab may be volatile) */												\
	for (int i = 0 ; i < nb ; i++)			{ Array[i] = pArray[i]; }														\
	/* Shift min to first array index */																					\
	for (int i = 1 ; i < nb ; i++)			{ if (Array[i] < Array[0])	SWAP_TYPE(Array[0], Array[i], typ_t); }				\
	/* Shift max to last array index */																						\
	for (int i = 1 ; i < (nb - 1) ; i++)	{ if (Array[i] > Array[nb - 1])	SWAP_TYPE(Array[nb - 1], Array[i], typ_t); }	\
	/* Sum and averaging */																									\
	for (int i = 1 ; i < (nb - 1) ; i++)	{ sum += Array[i]; }															\
	return (sum / (nb - 2));																								\
}


/*!\brief Get average value of tab excluding most extreme values (BYTE)
** \warning If pArray is volatile array:
** 			A new value may be written in the tab (by interrupt for example) while copying it (not dangerous for BYTEs).
** 			Disabling interruptions before calling function can overcome this behavior if needed (not forgetting to re-enable interrupts afterwards).
** \param[in] pArray - Pointer to BYTEs array
** \param[in] nb - Number of array elements
** \return Average value (BYTE)
**/
RESTRICTED_AVERAGE(BYTE, DWORD);


/*!\brief Get average value of tab excluding most extreme values (WORD)
** \warning If pArray is volatile array:
** 			A new value may be written in the tab (by interrupt for example) while copying it
** 			(which can lead to corrupted results for 8b MCU).
** 			Disabling interruptions before calling function can overcome this behavior if needed (not forgetting to re-enable interrupts afterwards).
** \param[in] pArray - Pointer to WORDs array
** \param[in] nb - Number of array elements
** \return Average value (WORD)
**/
RESTRICTED_AVERAGE(WORD, LWORD);


/*!\brief Get average value of tab excluding most extreme values (DWORD)
** \warning If pArray is volatile array:
** 			A new value may be written in the tab (by interrupt for example) while copying it
** 			(which can lead to corrupted results for 8b and 16b MCU).
** 			Disabling interruptions before calling function can overcome this behavior if needed (not forgetting to re-enable interrupts afterwards).
** \param[in] pArray - Pointer to DWORDs array
** \param[in] nb - Number of array elements
** \return Average value (DWORD)
**/
RESTRICTED_AVERAGE(DWORD, LWORD);


/*!\brief Get average value of tab excluding most extreme values (SBYTE)
** \warning If pArray is volatile array:
** 			A new value may be written in the tab (by interrupt for example) while copying it (not dangerous for SBYTEs).
** 			Disabling interruptions before calling function can overcome this behavior if needed (not forgetting to re-enable interrupts afterwards).
** \param[in] pArray - Pointer to SBYTEs array
** \param[in] nb - Number of array elements
** \return Average value (SBYTE)
**/
RESTRICTED_AVERAGE(SBYTE, SDWORD);


/*!\brief Get average value of tab excluding most extreme values (SWORD)
** \warning If pArray is volatile array:
** 			A new value may be written in the tab (by interrupt for example) while copying it
** 			(which can lead to corrupted results for 8b MCU).
** 			Disabling interruptions before calling function can overcome this behavior if needed (not forgetting to re-enable interrupts afterwards).
** \param[in] pArray - Pointer to SWORDs array
** \param[in] nb - Number of array elements
** \return Average value (SWORD)
**/
RESTRICTED_AVERAGE(SWORD, SLWORD);


/*!\brief Get average value of tab excluding most extreme values (SDWORD)
** \warning If pArray is volatile array:
** 			A new value may be written in the tab (by interrupt for example) while copying it
** 			(which can lead to corrupted results for 8b and 16b MCU).
** 			Disabling interruptions before calling function can overcome this behavior if needed (not forgetting to re-enable interrupts afterwards).
** \param[in] pArray - Pointer to SDWORDs array
** \param[in] nb - Number of array elements
** \return Average value (SDWORD)
**/
RESTRICTED_AVERAGE(SDWORD, SLWORD);


/*!\brief Get average value of tab excluding most extreme values (float)
** \warning If pArray is volatile array:
** 			A new value may be written in the tab (by interrupt for example) while copying it (which can lead to corrupted results).
** 			Disabling interruptions before calling function can overcome this behavior (not forgetting to re-enable interrupts afterwards).
** \param[in] pArray - Pointer to floats array
** \param[in] nb - Number of array elements
** \return Average value (float)
**/
RESTRICTED_AVERAGE(float, float);


/*!\brief Get average value of tab excluding most extreme values (double)
** \warning If pArray is volatile array:
** 			A new value may be written in the tab (by interrupt for example) while copying it (which can lead to corrupted results).
** 			Disabling interruptions before calling function can overcome this behavior (not forgetting to re-enable interrupts afterwards).
** \param[in] pArray - Pointer to doubles array
** \param[in] nb - Number of array elements
** \return Average value (double)
**/
RESTRICTED_AVERAGE(double, double);


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_AVERAGE_H */
/****************************************************************/
