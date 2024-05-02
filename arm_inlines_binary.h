/*!\file arm_inlines_binary.h
** \author SMFSW
** \copyright MIT (c) 2017-2024, SMFSW
** \brief Binary manipulation inlines
*/
/****************************************************************/
#ifndef ARM_INLINES_BINARY_H_
	#define ARM_INLINES_BINARY_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


/*!\brief Create specified number of bits mask
** \note function limited to arm native 32b
** \param[in] bits - Number of bits to create mask
** \return Mask value for specified number of bits
**/
__INLINE DWORD maskBits(const BYTE bits)
{
	const uintCPU_t	nb_bits = 32;
	const uintCPU_t	nb = MIN(bits, nb_bits);
	DWORD			mask = 0;

	for (uintCPU_t i = 0 ; i < nb ; i++)
	{
		mask |= LSHIFT(1UL, i);
	}

	return mask;
}


/*!\brief Check the number of clear/set bits in a variable
** \note function limited to arm native 32b
** \param[in] val - Variable to check for bits
** \param[in] bits - Number of bits to check
** \param[in] state - Logic state to check
** \return Number of state specified bits in val
**/
__INLINE BYTE nbBitsState(const DWORD val, const BYTE bits, const BOOL state)
{
	const uintCPU_t	nb_bits = 32;
	const uintCPU_t	nb = MIN(bits, nb_bits);
	BYTE			ret = 0;

	for (uintCPU_t i = 0 ; i < nb ; i++)
	{
		if ((val & LSHIFT(1UL, i)) != 0U)
		{
			ret++;
		}
	}

	if (!state)
	{
		ret = (BYTE) nb - ret;
	}

	return ret;
}


/*!\brief Get power of 2 of the most significant set bit
** \note function limited to arm native 32b
** \param[in] val - Variable to check for bits
** \return Power of 2 of most significant bit set
** \retval >=0: Index (power of 2) of most significant bit set
** \retval -1: no bit set
**/
__INLINE SDWORD getMSBitSet(const DWORD val)
{
	const uintCPU_t nb_bits = 32;
	SDWORD ret = -1;

	for (uintCPU_t i = nb_bits ; i > 0U ; i--)
	{
		const uintCPU_t bit = i - 1U;
		if ((val & LSHIFT(1UL, bit)) != 0U)
		{
			ret = (SDWORD) bit;
			break;
		}
	}

	return ret;
}


/*!\brief Swap specified number of bits in value (mirroring bits)
** \note function limited to arm native 32b
** \param[in] val - Value to swap
** \param[in] bits - Number of bits to swap
** \return Swapped binary value
**/
__INLINE DWORD swapBits(const DWORD val, const BYTE bits)
{
	const uintCPU_t	nb_bits = 32;
	const uintCPU_t	nb = MIN(bits, nb_bits) - 1U;
	DWORD			swap = 0;

	for (uintCPU_t i = nb + 1U ; i > 0U ; i--)
	{
		const uintCPU_t bit = i - 1U;
		if ((val & LSHIFT(1UL, bit)) != 0U)
		{
			swap |= LSHIFT(1UL, (nb - bit));
		}
	}

	return swap;
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_INLINES_BINARY_H_ */
/****************************************************************/
