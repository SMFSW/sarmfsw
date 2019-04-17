/*!\file arm_inlines_bcd.h
** \author SMFSW
** \copyright MIT (c) 2017-2019, SMFSW
** \brief BCD code conversion inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_BCD_H
	#define __ARM_INLINES_BCD_H

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


/*!\brief Converts hexadecimal value to BCD
** \note Returns 0xFF if Hex value can't be represented on a BCD BYTE
** \param[in] hex - Hexadecimal value to convert
** \return BCD value
**/
__INLINE BYTE HexToBCD(const BYTE hex)
{
	return ((hex > 99) ? 0xFF : (LSHIFT((hex / 10), 4) | (hex % 10)));
}


/*!\brief Converts BCD value to hexadecimal
** \note Returns 0xFF if BCD value is inconsistent
** \param[in] bcd - BCD value to convert
** \return Hexadecimal value
**/
__INLINE BYTE BCDToHex(const BYTE bcd)
{
	const BYTE ms = RSHIFT(bcd & 0xF0, 4);
	const BYTE ls = bcd & 0x0F;

	return (((ms > 9) || (ls > 9)) ? 0xFF : ((BYTE) ((ms * 10) + ls)));
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_BCD_H */
/****************************************************************/
