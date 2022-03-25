/*!\file arm_inlines_ascii.h
** \author SMFSW
** \copyright MIT (c) 2017-2022, SMFSW
** \brief ASCII code conversion inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_ASCII_H
	#define __ARM_INLINES_ASCII_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "arm_macros.h"				// Common macros
#include "arm_typedefs.h"			// Common typedefs
//#include "ctype.h"
/****************************************************************/


/*!\brief test for lower case alphabetic char
** \param[in] ascii - ASCII char to check
** \return true if lower case, false otherwise
** \warning You probably should ensure \b ascii is alphabetic char first (false will be always returned in case non alphabetic char)
**/
__INLINE bool isLowerCase(const CHAR ascii) {
	return binEval((ascii >= 'a') && (ascii <= 'z')); }


/*!\brief test for upper case alphabetic char
** \param[in] ascii - ASCII char to check
** \return true if upper case, false otherwise
** \warning You probably should ensure \b ascii is alphabetic char first (false will be always returned in case non alphabetic char)
**/
__INLINE bool isUpperCase(const CHAR ascii) {
	return binEval((ascii >= 'A') && (ascii <= 'Z')); }


/*!\brief test for alphabetic char
** \param[in] ascii - ASCII char to check
** \return true if alphabetic, false otherwise
**/
__INLINE bool isAlpha(const CHAR ascii) {
	return binEval(isLowerCase(ascii) || isUpperCase(ascii)); }


/*!\brief test for numeric char
** \param[in] ascii - ASCII char to check
** \return true if numeric, false otherwise
**/
__INLINE bool isNum(const CHAR ascii) {
	return binEval((ascii >= '0') && (ascii <= '9')); }


/*!\brief test for alphanumeric char
** \param[in] ascii - ASCII char to check
** \return true if alpha/numeric, false otherwise
**/
__INLINE bool isAlphaNum(const CHAR ascii) {
	return binEval(isNum(ascii) || isAlpha(ascii)); }


/*!\brief Convert upper case alphabetic char to lower case
** \param[in] ascii - ASCII char to convert
** \return Lower case char, same value otherwise
** \warning You probably should ensure \b ascii is alphabetic char first
**/
__INLINE CHAR toLowerCase(const CHAR ascii) {
	return binEval(isUpperCase(ascii)) ? (ascii + ('A' - 'a')) : ascii; }


/*!\brief Convert lower case alphabetic char to upper case
** \param[in] ascii - ASCII char to convert
** \return Upper case char, same value otherwise
** \warning You probably should ensure \b ascii is alphabetic char first
**/
__INLINE CHAR toUpperCase(const CHAR ascii) {
	return binEval(isLowerCase(ascii)) ? (ascii - ('A' - 'a')) : ascii; }


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

/*!\brief ASCII string to 32bit unsigned decimal
** \param[in] pASCII - pointer to ASCII string
** \param[in] len - ASCII string length (max shall be 10, and may overflow return value when 10)
** \return Unsigned decimal value
**/
__INLINE DWORD NONNULL__ ASCIIstrToDecimal(const CHAR * const pASCII, const BYTE len)
{
	DWORD dec = 0;

	for (int i = len - 1, mult = 1 ; i >= 0 ; i--, mult *= 10)
	{
		const uint8_t single = ASCIIToHex(pASCII[i]);

		if (single > 9)		{ break; }

		dec += single * mult;
	}

	return dec;
}


/*!\brief ASCII string to 32bit unsigned hexadecimal
** \param[in] pASCII - pointer to ASCII string
** \param[in] len - ASCII string length (max shall be 8)
** \return Unsigned hexadecimal value
**/
__INLINE DWORD NONNULL__ ASCIIstrToHex(const CHAR * const pASCII, const BYTE len)
{
	DWORD hex = 0;

	for (int i = len - 1, shift = 0 ; i >= 0 ; i--, shift += 4)
	{
		const uint8_t nybble = ASCIIToHex(pASCII[i]);

		if (nybble == 0xFF)	{ break; }

		hex |= LSHIFT(nybble, shift);
	}

	return hex;
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_ASCII_H */
/****************************************************************/
