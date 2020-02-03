/*!\file arm_inlines_binary.h
** \author SMFSW
** \copyright MIT (c) 2017-2020, SMFSW
** \brief Binary manipulation inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_BINARY_H
	#define __ARM_INLINES_BINARY_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "arm_typedefs.h"			// Common typedefs
/****************************************************************/


/*!\brief Create specified number of bits mask
** \note function limited to arm native 32b
** \param[in] bits - Number of bits to create mask
** \return Mask value for specified number of bits
**/
__INLINE DWORD maskBits(const BYTE bits)
{
	const BYTE	nb_bits = 32;
	const BYTE	nb = (bits > nb_bits) ? nb_bits : bits;
	DWORD		mask = 0;

	for (unsigned int i = 0 ; i < nb ; i++)	{ mask |= 1UL << i; }

	return mask;
}


/*!\brief Check the number of clear/set bits in a variable
** \note function limited to arm native 32b
** \param[in] val - Variable to check for bits
** \param[in] bits - Number of bits to check
** \param[in] state - Logic state to check
** \return Number of state specified bits in val
**/
__INLINE BYTE nbBitsState(const DWORD val, const BYTE bits, const bool state)
{
	const BYTE	nb_bits = 32;
	const BYTE	nb = (bits > nb_bits) ? nb_bits : bits;
	BYTE		ret = 0;

	for (unsigned int i = 0 ; i < nb ; i++)	{ if (val & (1UL << i))	ret++; }

	return state ? ret : nb - ret;
}


/*!\brief Get power of 2 of the most significant set bit
** \note function limited to arm native 32b
** \param[in] val - Variable to check for bits
** \return Power of 2 of most significant bit set
** \retval >=0: Index (power of 2) of most significant bit set
** \retval -1: no bit set
**/
__INLINE SBYTE getMSBitSet(const DWORD val)
{
	const BYTE	nb_bits = 32;

	for (int i = nb_bits - 1 ; i >= 0 ; i--)	{ if (val & (1UL << i))	return i; }

	return -1;
}


/*!\brief Swap specified number of bits in value (mirroring bits)
** \note function limited to arm native 32b
** \param[in] val - Value to swap
** \param[in] bits - Number of bits to swap
** \return Swapped binary value
**/
__INLINE DWORD swapBits(const DWORD val, const BYTE bits)
{
	const BYTE	nb_bits = 32;
	const BYTE	nb = (bits > nb_bits ? nb_bits : bits) - 1;
	DWORD		swap = 0;

	for (int i = nb ; i >= 0 ; i--)	{ if (val & (1UL << i))	swap |= 1UL << (nb - i); }

	return swap;
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_BINARY_H */
/****************************************************************/
