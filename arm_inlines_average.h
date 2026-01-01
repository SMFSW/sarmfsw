/*!\file arm_inlines_average.h
** \author SMFSW
** \copyright MIT (c) 2017-2026, SMFSW
** \brief Averaging inlines
*/
// cppcheck-suppress-begin [misra-c2012-18.8] macro warning
/****************************************************************/
#ifndef ARM_INLINES_AVERAGE_H_
	#define ARM_INLINES_AVERAGE_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


/*!\brief Get average value of tab excluding most extreme values
** \MISRA Function scope deviation granted for:\n
**	\b Rule-20.10 - \b Advisory: \c # and \c ## preprocessor operators (misra-c2012-20.10)\n
** Local legitimate use derogation authorized for:\n
** \b Rule-18.8 - \b Required: Var-length array types (misra-c2012-18.8)\n
** \a Justification: \p pArray is used as array, makes sense to declare it in the same manner.\n
** \a Justification: copy \c array needs to have a size and is always used in conjunction with \p nb.\n
** \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
** \a Justification: \p typ_t parameter would always be used as cast and wouldn't catenate name.\n
** \b Rule-20.12 - \b Required: macro parameter operand to # or ## (misra-c2012-20.12)\n
** \a Justification: compliant use.\n
**/
#define	RESTRICTED_AVERAGE(typ_t, sum_t)													\
__INLINE typ_t RestrictedAverage_##typ_t(volatile const typ_t pArray[], const uint8_t nb)	\
{																							\
	const typ_t n = (typ_t) nb - (typ_t) 2;													\
	typ_t average = (typ_t) 0;																\
																							\
	if (nb > 2U)																			\
	{																						\
		/* Array copy (memcpy not used as copy by byte and pTab may be volatile) */			\
		typ_t array[nb];																	\
		for (uintCPU_t i = 0 ; i < nb ; i++)	{ array[i] = pArray[i]; }					\
																							\
		/* Sum and min/max recording */														\
		sum_t min_val = pArray[0];															\
		sum_t max_val = pArray[0];															\
		sum_t sum = (typ_t) 0;																\
		for (uintCPU_t i = 0 ; i < nb ; i++)												\
		{																					\
			sum += array[i];																\
			if (array[i] > max_val)	{ max_val = array[i]; }									\
			if (array[i] < min_val)	{ min_val = array[i]; }									\
		}																					\
																							\
		/* Averaging */																		\
		sum -= min_val + max_val;															\
		sum /= n;																			\
		average = (typ_t) sum;																\
	}																						\
																							\
	return average;																			\
}	// cppcheck-suppress [misra-c2012-18.8, misra-c2012-20.7, misra-c2012-20.10, misra-c2012-20.12]


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

#endif /* ARM_INLINES_AVERAGE_H_ */
// cppcheck-suppress-end [misra-c2012-18.8] macro warning
/****************************************************************/
