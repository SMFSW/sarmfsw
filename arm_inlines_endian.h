/*!\file arm_inlines_endian.h
** \author SMFSW
** \copyright MIT (c) 2017-2022, SMFSW
** \brief Endian conversion and testing inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_ENDIAN_H
	#define __ARM_INLINES_ENDIAN_H

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


/*!\enum eEndian
** \brief Core endian
**/
typedef enum eEndian {
	Endian_little = 0,		//!< Little endian configured MCU
	Endian_big,				//!< Big endian configured MCU
	Endian_mid_little,		//!< Middle little endian configured MCU (PDP-11)
	Endian_mid_big,			//!< Middle big endian configured MCU (Honeywell 316)
	Endian_unknown			//!< Unknown endian MCU
} eEndian;


/*!\brief Swap content endian of a 16b value (little -> big, big -> little)
** \param[in] w - 16b value
** \return Swapped value
**/
__INLINE WORD SWAP_END16B(const WORD w)
{
	return (WORD) (LSHIFT16((w & 0xFFU), 8) | RSHIFT16((w & 0xFF00U), 8));
}


/*!\brief Swap content endian of a 32b value (little -> big, big -> little)
** \param[in] d - 32b value
** \return Swapped value
**/
__INLINE DWORD SWAP_END32B(const DWORD d)
{
	return (DWORD) (LSHIFT32(SWAP_END16B(d & 0xFFFFUL), 16) | SWAP_END16B(RSHIFT32((d & 0xFFFF0000UL), 16)));
}


/*!\brief Swap content endian of a 64b value (little -> big, big -> little)
** \param[in] l - 64b value
** \return Swapped value
**/
__INLINE LWORD SWAP_END64B(const LWORD l)
{
	return (LWORD) (LSHIFT64(SWAP_END32B(l & 0xFFFFFFFFULL), 32) | SWAP_END32B(RSHIFT64((l & 0xFFFFFFFF00000000ULL), 32)));
}


/*!\brief Swap endian of a 16b tab (little -> big, big -> little)
** \param[in] tab - tab of 16b values
** \param[in] nb - nb of values in tab
**/
__INLINE void NONNULL_INLINE__ SWAP_END16B_TAB(WORD tab[], const WORD nb)
{
	for (unsigned int i = 0 ; i < nb ; i++)	{ tab[i] = SWAP_END16B(tab[i]); }
}


/*!\brief Swap endian of a 32b tab (little -> big, big -> little)
** \param[in] tab - tab of 32b values
** \param[in] nb - nb of values in tab
**/
__INLINE void NONNULL_INLINE__ SWAP_END32B_TAB(DWORD tab[], const WORD nb)
{
	for (unsigned int i = 0 ; i < nb ; i++)	{ tab[i] = SWAP_END32B(tab[i]); }
}


/*!\brief Swap endian of a 64b tab (little -> big, big -> little)
** \param[in] tab - tab of 64b values
** \param[in] nb - nb of values in tab
**/
__INLINE void NONNULL_INLINE__ SWAP_END64B_TAB(LWORD tab[], const WORD nb)
{
	for (unsigned int i = 0 ; i < nb ; i++)	{ tab[i] = SWAP_END64B(tab[i]); }
}


/*!\brief Test Core endian
** \return Endian type
**/
__INLINE eEndian testEndian_basic(void)
{
	const WORD x = 0x100;

	return (*(BYTE *) (&x)) ? Endian_big : Endian_little;
}


/*!\brief Test Core endian (full, recognizing mid endian too)
** \return Endian type
**/
__INLINE eEndian testEndian_full(void)
{
	const union {
		DWORD	dword;
		BYTE	byte[sizeof(DWORD)];
	} tst = { .byte = { 1, 2, 3, 4 } };

	switch (tst.dword)
	{
		default:			return Endian_unknown;
		case 0x01020304UL:	return Endian_big;
		case 0x04030201UL:	return Endian_little;
		case 0x03040102UL:	return Endian_mid_big;
		case 0x02010403UL:	return Endian_mid_little;
	}
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_ENDIAN_H */
/****************************************************************/
