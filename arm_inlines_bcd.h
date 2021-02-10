/*!\file arm_inlines_bcd.h
** \author SMFSW
** \copyright MIT (c) 2017-2021, SMFSW
** \brief BCD code conversion inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_BCD_H
	#define __ARM_INLINES_BCD_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdlib.h>
#include "arm_typedefs.h"			// Common typedefs
/****************************************************************/


/*!\brief Converts hexadecimal value to BCD
** \note Returns 0xFFFFFFFF if Hex value can't be represented on a BCD BYTE
** \param[in] hex - Hexadecimal value to convert
** \return BCD value
**/
__INLINE DWORD HexToBCD(const DWORD hex)
{
	if (hex > 99999999)		{ return (DWORD) -1; }

	uint32_t res = 0;

	div_t tmp;
	tmp.quot = hex;

	for (int i = 0 ; i < 8 ; i++)
	{
		tmp = div(tmp.quot, 10);
		res |= LSHIFT(tmp.rem, (4 * i));
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
	uint32_t res = 0, mult = 1;

	for (unsigned int i = 0 ; i < 8 ; i++)
	{
		const uint8_t single = (RSHIFT(bcd, (4 * i)) & 0x0F);

		if (single > 9)		{ return (DWORD) -1; }

		res += single * mult;
		mult *= 10;
	}

	return res;
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_BCD_H */
/****************************************************************/
