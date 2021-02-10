/*!\file arm_inlines_ascii.h
** \author SMFSW
** \copyright MIT (c) 2017-2021, SMFSW
** \brief ASCII code conversion inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_ASCII_H
	#define __ARM_INLINES_ASCII_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "arm_typedefs.h"			// Common typedefs
/****************************************************************/


/*!\brief Converts hexadecimal value to ASCII
** \param[in] hex - Hexadecimal value to convert
** \return ASCII char
**/
__INLINE CHAR INLINE__ HexToASCII(const BYTE hex)
{
	const BYTE h = hex & 0x0F;
	return (h < 0x0A ? 0x30 : 0x37) + h;
}


/*!\brief Converts ASCII char to hexadecimal
** \param[in] ascii - ASCII char to convert
** \return Hexadecimal value
**/
__INLINE BYTE ASCIIToHex(const CHAR ascii)
{
	if ((ascii >= '0') && (ascii <= '9'))			{ return ascii - 0x30; }
	else if ((ascii >= 'A') && (ascii <= 'F'))		{ return ascii - 0x37; }
	else if ((ascii >= 'a') && (ascii <= 'f'))		{ return ascii - 0x57; }
	else											{ return 0xFF; }
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_ASCII_H */
/****************************************************************/
