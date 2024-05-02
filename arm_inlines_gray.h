/*!\file arm_inlines_gray.h
** \author SMFSW
** \copyright MIT (c) 2017-2024, SMFSW
** \brief Gray code conversion inlines
*/
/****************************************************************/
#ifndef ARM_INLINES_GRAY_H_
	#define ARM_INLINES_GRAY_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


/*!\brief Convert binary value to gray code
** \param[in] bin - binary value
** \return Converted value (gray code)
**/
__INLINE DWORD INLINE__ bin2gray(const DWORD bin)
{
	return (RSHIFT(bin, 1U) ^ bin);
}


/*!\brief Convert gray code to binary value
** \param[in] gray - gray code value
** \return Converted value (binary)
**/
__INLINE DWORD gray2bin(const DWORD gray)
{
	uintCPU_t	bits = 32;
	DWORD		tmp = gray;

	while ((bits >>= 1U) != 0U)
	{
		tmp ^= (tmp >> bits);
	}

	return tmp;
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_INLINES_GRAY_H_ */
/****************************************************************/
