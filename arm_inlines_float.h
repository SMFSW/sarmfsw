/*!\file arm_inlines_float.h
** \author SMFSW
** \copyright MIT (c) 2017-2019, SMFSW
** \brief Floating point manipulation inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_FLOAT_H
	#define __ARM_INLINES_FLOAT_H

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


/*!\brief Get floating point number decimal part
** \note in need to print floats, add '-u _printf_float' in Linker options.
** \warning enabling floating point support from linker seems to fubar printing long variables,
** 			so welcome get_fp_dec for the purpose.
** \param[in] f - floating point value
** \param[in] nb - Number of decimal to get after floating point
** \return nb decimal part as integer
**/
__INLINE SDWORD get_fp_dec(float f, BYTE nb)
{
	SDWORD mul = 1;

	f -= (SDWORD) f;

	while (nb-- != 0) { mul *= 10; }

	return (SDWORD) (f * mul);
}



/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_FLOAT_H */
/****************************************************************/
