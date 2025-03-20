/*!\file arm_inlines_ascii.h
** \author SMFSW
** \copyright MIT (c) 2017-2025, SMFSW
** \brief ASCII code conversion inlines
*/
/****************************************************************/
#ifndef ARM_INLINES_ASCII_H_
	#define ARM_INLINES_ASCII_H_

#ifdef __cplusplus
	extern "C" {
#endif

//#include <ctype.h>
/****************************************************************/


/*!\brief test for lower case alphabetic char
** \param[in] ascii - ASCII char to check
** \return true if lower case, false otherwise
** \warning You probably should ensure \p ascii is alphabetic char first (false will be always returned in case non alphabetic char)
**/
__INLINE BOOL isLowerCase(const CHAR ascii) {
	return binEval((ascii >= 'a') && (ascii <= 'z')); }


/*!\brief test for upper case alphabetic char
** \param[in] ascii - ASCII char to check
** \return true if upper case, false otherwise
** \warning You probably should ensure \p ascii is alphabetic char first (false will be always returned in case non alphabetic char)
**/
__INLINE BOOL isUpperCase(const CHAR ascii) {
	return binEval((ascii >= 'A') && (ascii <= 'Z')); }


/*!\brief test for alphabetic char
** \param[in] ascii - ASCII char to check
** \return true if alphabetic, false otherwise
**/
__INLINE BOOL isAlpha(const CHAR ascii) {
	return binEval(isLowerCase(ascii) || isUpperCase(ascii)); }


/*!\brief test for numeric char
** \param[in] ascii - ASCII char to check
** \return true if numeric, false otherwise
**/
__INLINE BOOL isNum(const CHAR ascii) {
	return binEval((ascii >= '0') && (ascii <= '9')); }


/*!\brief test for alphanumeric char
** \param[in] ascii - ASCII char to check
** \return true if alpha/numeric, false otherwise
**/
__INLINE BOOL isAlphaNum(const CHAR ascii) {
	return binEval(isNum(ascii) || isAlpha(ascii)); }


/*!\brief Convert upper case alphabetic char to lower case
** \param[in] ascii - ASCII char to convert
** \return Lower case char, same value otherwise
** \warning You probably should ensure \p ascii is alphabetic char first
**/
__INLINE CHAR toLowerCase(const CHAR ascii) {
	return binEval(isUpperCase(ascii)) ? (ascii + ('a' - 'A')) : ascii; }


/*!\brief Convert lower case alphabetic char to upper case
** \param[in] ascii - ASCII char to convert
** \return Upper case char, same value otherwise
** \warning You probably should ensure \p ascii is alphabetic char first
**/
__INLINE CHAR toUpperCase(const CHAR ascii) {
	return binEval(isLowerCase(ascii)) ? (ascii - ('a' - 'A')) : ascii; }


/*!\brief Converts hexadecimal value to ASCII
** \param[in] hex - Hexadecimal value to convert
** \return ASCII char
**/
__INLINE CHAR INLINE__ HexToASCII(const BYTE hex)
{
	const BYTE h = hex & 0x0FU;
	return (CHAR) (h) + ((h < 0x0AU) ? 0x30 : 0x37);
}


/*!\brief Converts ASCII char to hexadecimal
** \param[in] ascii - ASCII char to convert
** \return Hexadecimal value
**/
__INLINE BYTE ASCIIToHex(const CHAR ascii)
{
	BYTE h = (BYTE) ascii;

	if ((ascii >= '0') && (ascii <= '9'))		{ h -= 0x30U; }
	else if ((ascii >= 'A') && (ascii <= 'F'))	{ h -= 0x37U; }
	else if ((ascii >= 'a') && (ascii <= 'f'))	{ h -= 0x57U; }
	else										{ h = 0xFFU; }

	return h;
}

/*!\brief ASCII decimal string to 32bit unsigned integer
** \param[in] pASCII - pointer to ASCII string
** \param[in] len - ASCII string length (max shall be 10, and may overflow return value when 10)
** \return Unsigned integer value
**/
__INLINE DWORD NONNULL__ strDecToInt(const CHAR * const pASCII, const BYTE len)
{
	DWORD dec = 0;
	DWORD mult = 1U;

	for (uintCPU_t i = len ; i > 0U ; i--)
	{
		const BYTE single = ASCIIToHex(pASCII[i - 1U]);
		if (single > 9U)	{ break; }

		dec += single * mult;
		mult *= 10U;
	}

	return dec;
}


/*!\brief ASCII hexadecimal string to 32bit unsigned integer
** \param[in] pASCII - pointer to ASCII string
** \param[in] len - ASCII string length (max shall be 8)
** \return Unsigned integer value
**/
__INLINE DWORD NONNULL__ strHexToInt(const CHAR * const pASCII, const BYTE len)
{
	DWORD hex = 0;
	DWORD shift = 0;

	for (uintCPU_t i = len ; i > 0U ; i--)
	{
		const DWORD nybble = ASCIIToHex(pASCII[i - 1U]);
		if (nybble == 0xFFU)	{ break; }

		hex |= LSHIFT32(nybble, shift);
		shift += 4U;
	}

	return hex;
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_INLINES_ASCII_H_ */
/****************************************************************/
