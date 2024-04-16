/*!\file arm_inlines_bcd.h
** \author SMFSW
** \copyright MIT (c) 2017-2024, SMFSW
** \brief BCD code conversion inlines
*/
/****************************************************************/
#ifndef ARM_INLINES_BCD_H_
	#define ARM_INLINES_BCD_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdlib.h>
/****************************************************************/


/*!\brief Converts hexadecimal value to BCD
** \note Returns 0xFFFFFFFF if Hex value can't be represented on a BCD BYTE
** \param[in] hex - Hexadecimal value to convert
** \return BCD value
**/
__INLINE DWORD HexToBCD(const DWORD hex)
{
	DWORD res = 0;

	if (hex > 99999999U)
	{
		res = (DWORD) -1;
	}
	else
	{
		div_t tmp;
		tmp.quot = hex;

		for (uintCPU_t i = 0 ; i < 8U ; i++)
		{
			tmp = div(tmp.quot, 10);
			res |= LSHIFT(tmp.rem, (4U * i));
		}
	}

	return res;
}


/*!\brief Converts BCD value to hexadecimal
** \note Returns 0xFFFFFFFF if BCD value is inconsistent
** \param[in] bcd - BCD value to convert
** \return Hexadecimal value
**/
__INLINE DWORD BCDToHex(const DWORD bcd)
{
	DWORD res = 0, mult = 1;

	for (uintCPU_t i = 0 ; i < 8U ; i++, mult *= 10)
	{
		const BYTE single = (BYTE) (RSHIFT(bcd, (4U * i)) & 0x0FU);

		if (single > 9U)
		{
			res = (DWORD) -1;
			break;
		}

		res += single * mult;
	}

	return res;
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_INLINES_BCD_H_ */
/****************************************************************/
