/*!\file arm_inlines_gray.h
** \author SMFSW
** \copyright MIT (c) 2017-2020, SMFSW
** \brief Gray code conversion inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_GRAY_H
	#define __ARM_INLINES_GRAY_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "arm_typedefs.h"			// Common typedefs
/****************************************************************/


/*!\brief Convert binary value to gray code
** \param[in] bin - binary value
** \return Converted value (gray code)
**/
__INLINE DWORD INLINE__ bin2gray(const DWORD bin)
{
	return (RSHIFT(bin, 1) ^ bin);
}


/*!\brief Convert gray code to binary value
** \param[in] gray - gray code value
** \return Converted value (binary)
**/
__INLINE DWORD gray2bin(const DWORD gray)
{
	unsigned int	bits = 32;
	DWORD			tmp = gray;

	while ((bits >>= 1) > 0)	{ tmp ^= (tmp >> bits); }

	return tmp;
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_GRAY_H */
/****************************************************************/
