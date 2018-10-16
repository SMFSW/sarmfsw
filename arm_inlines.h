/*!\file arm_inlines.h
** \author SMFSW
** \copyright MIT (c) 2017-2018, SMFSW
** \brief ARM common inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_H
	#define __ARM_INLINES_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "arm_attributes.h"		// Common attributes (following compiler)
#include "arm_typedefs.h"		// Common typedefs
#include "arm_errors.h"			// Common errors
#include "arm_macros.h"			// Common macros
#include "arm_cmsis.h"			// HAL & Drivers (following defined platform)
#include "arm_hal_peripheral.h"	// HAL peripherals includes (following defined platform)
/****************************************************************/


/********************/
/***  TIME TESTS  ***/
/********************/

/*!\brief Tests if stored time value has reached time lapse in ms
** \warning For SAM families, no ms base time counter is implemented in HAL,
**			please refer to arm_chip_sam.h for an implementation example.
** \note	Define custom HAL_MS_TICKS_FACTOR at project level if tick period is not 1ms
** \param[in] last - stored time value
** \param[in] time - time lapse (in ms)
** \return true if time elapsed
**/
__INLINE bool INLINE__ TPSSUP_MS(const DWORD last, const DWORD time) {
	register uint32_t hNow = HALTicks();
	uint32_t diff = (hNow >= last) ? hNow - last : (HAL_MAX_TICKS - last) + hNow;
	return (diff > (DWORD) (time * HAL_MS_TICKS_FACTOR)); }

/*!\brief Tests if stored time value has not reached time lapse in ms
** \warning For SAM families, no ms base time counter is implemented in HAL,
**			please refer to arm_chip_sam.h for an implementation example.
** \note	Define custom HAL_MS_TICKS_FACTOR at project level if tick period is not 1ms
** \param[in] last - stored time value
** \param[in] time - time lapse (in ms)
** \return true if time not elapsed
**/
__INLINE bool INLINE__ TPSINF_MS(const DWORD last, const DWORD time) {
	register uint32_t hNow = HALTicks();
	uint32_t diff = (hNow >= last) ? hNow - last : (HAL_MAX_TICKS - last) + hNow;
	return (diff < (DWORD) (time * HAL_MS_TICKS_FACTOR)); }


/******************************/
/***  BINARY MANIPULATIONS  ***/
/******************************/

/*!\brief Create specified number of bits mask
** \note function limited to arm native 32b
** \param[in] bits - Number of bits to create mask
** \return Mask value for specified number of bits
**/
__INLINE DWORD maskBits(const BYTE bits) {
	const BYTE	nb_bits = 32;
	uint8_t		nb = (bits > nb_bits) ? nb_bits : bits;
	DWORD		mask = 0;
	for (unsigned int i = 0 ; i < nb ; i++)	mask |= 1UL << i;
	return mask; }

/*!\brief Check the number of clear/set bits in a variable
** \note function limited to arm native 32b
** \param[in] val - Variable to check for bits
** \param[in] bits - Number of bits to check
** \param[in] state - Logic state to check
** \return Number of state specified bits in val
**/
__INLINE BYTE nbBitsState(const DWORD val, const BYTE bits, const bool state) {
	const BYTE	nb_bits = 32;
	uint8_t		nb = (bits > nb_bits) ? nb_bits : bits;
	BYTE		ret = 0;
	for (unsigned int i = 0 ; i < nb ; i++)	{ if (val & (1UL << i))	ret++; }
	return state ? ret : nb - ret; }

/*!\brief Get power of 2 of the most significant set bit
** \param[in] val - Variable to check for bits
** \return Power of 2 of most significant bit set
** \retval >=0: Index (power of 2) of most significant bit set
** \retval -1: no bit set
**/
__INLINE SBYTE getMSBitSet(const DWORD val) {
	const BYTE	nb_bits = 32;
	for (int i = nb_bits - 1 ; i >= 0 ; i--)	{ if (val & (1UL << i))	return i; }
	return -1; }

/*!\brief Swap specified number of bits in value (mirroring bits)
** \note function limited to arm native 32b
** \param[in] val - Value to swap
** \param[in] bits - Number of bits to swap
** \return Swapped binary value
**/
__INLINE DWORD swapBits(const DWORD val, const BYTE bits) {
	const BYTE	nb_bits = 32;
	uint8_t		nb = (bits > nb_bits ? nb_bits : bits) - 1;
	DWORD		swap = 0;
	for (int i = nb ; i >= 0 ; i--)	{ if (val & (1UL << i))	swap |= 1UL << (nb - i); }
	return swap; }


/*************************************************/
/***  HEX, ASCII, BCD & GRAY CODE CONVERSIONS  ***/
/*************************************************/

/*!\brief Converts hexadecimal value to BCD
** \note Returns 0xFF if Hex value can't be represented on a BCD BYTE
** \param[in] hex - Hexadecimal value to convert
** \return BCD value
**/
__INLINE BYTE HexToBCD(const BYTE hex) {
	if (hex > 99)	{ return 0xFF; }
	return LSHIFT((hex / 10), 4) | (hex % 10); }

/*!\brief Converts BCD value to hexadecimal
** \note Returns 0xFF if BCD value is inconsistent
** \param[in] bcd - BCD value to convert
** \return Hexadecimal value
**/
__INLINE BYTE BCDToHex(const BYTE bcd) {
	uint8_t	ms = RSHIFT(bcd & 0xF0, 4);
	uint8_t	ls = bcd & 0x0F;
	if ((ms > 9) || (ls > 9))	{ return 0xFF; }
	return (uint8_t) ((ms * 10) + ls); }


/*!\brief Converts hexadecimal value to ASCII
** \param[in] hex - Hexadecimal value to convert
** \return ASCII char
**/
__INLINE CHAR INLINE__ HexToASCII(BYTE hex) {
	hex &= 0x0F;
	return (hex < 0x0A ? 0x30 : 0x37) + hex; }

/*!\brief Converts ASCII char to hexadecimal
** \param[in] ascii - ASCII char to convert
** \return Hexadecimal value
**/
__INLINE SBYTE ASCIIToHex(const CHAR ascii) {
	if ((ascii >= '0') && (ascii <= '9'))			{ return ascii - 0x30; }
	else if ((ascii >= 'A') && (ascii <= 'F'))		{ return ascii - 0x37; }
	else if ((ascii >= 'a') && (ascii <= 'f'))		{ return ascii - 0x47; }
	else											{ return -1; } }


/*!\brief Convert binary value to gray code
** \param[in] bin - binary value
** \return Converted value (gray code)
**/
__INLINE DWORD INLINE__ bin2gray(const DWORD bin) {
	return RSHIFT(bin, 1) ^ bin; }

/*!\brief Convert gray code to binary value
** \param[in] gray - gray code value
** \return Converted value (binary)
**/
__INLINE DWORD gray2bin(const DWORD gray) {
	SWORD bits = 32;
	DWORD tmp = gray;
	while ((bits >>= 1) > 0)	{ tmp ^= (tmp >> bits); }
	return tmp; }


/******************************/
/***  VAR SIZE CONVERSIONS  ***/
/******************************/

/*!\brief converts 16bits to 8bits
** \param[in] val - 16b value to convert
** \return Converted value
**/
__INLINE BYTE INLINE__ conv16to8Bits(const WORD val) {
	return (BYTE) RSHIFT(val, 8); }

/*!\brief converts 8bits to 16bits
** \param[in] val - 8b value to convert
** \return Converted value
**/
__INLINE WORD INLINE__ conv8to16Bits(const BYTE val) {
	return (WORD) (LSHIFT(val, 8) + val); }


/*!\brief converts 8bits to 8+nb bits (16bits max)
** \warning conversion output shall not exceed 16bits (input shall strictly be unsigned 8bits)
** \warning nb shall be in range 0-8 (note that using 0 doesn't change val)
** \param[in] val - 8b value to convert
** \param[in] nb - number of bits to add (8bits max)
** \return Converted value
**/
__INLINE WORD conv8upto16Bits(const BYTE val, const BYTE nb) {
	return ((WORD) ((WORD) (val << nb) + (WORD) (val & (0xFFU >> (8-nb))))); }

/*!\brief converts 16bits to 16+nb bits (32bits max)
** \warning conversion output shall not exceed 32bits (input shall strictly be unsigned 16bits)
** \warning nb shall be in range 0-16 (note that using 0 doesn't change val)
** \param[in] val - 16b value to convert
** \param[in] nb - number of bits to add (16bits max)
** \return Converted value
**/
__INLINE DWORD conv16upto32Bits(const WORD val, const BYTE nb) {
	return ((DWORD) ((DWORD) (val << nb) + (DWORD) (val & (0xFFFFU >> (16-nb))))); }

/*!\brief converts 32bits to 32+nb bits (64bits max)
** \warning conversion output shall not exceed 64bits (input shall strictly be unsigned 32bits)
** \warning nb shall be in range 0-32 (note that using 0 doesn't change val)
** \param[in] val - 32b value to convert
** \param[in] nb - number of bits to add (32bits max)
** \return Converted value
**/
__INLINE LWORD conv32upto64Bits(const DWORD val, const BYTE nb) {
	return ((LWORD) ((LWORD) (val << nb) + (LWORD) (val & (0xFFFFFFFFUL >> (32-nb))))); }


/************************/
/***  VALUES TESTING  ***/
/************************/

/*!\brief Checks if val given as parameter is in tolerance
** \param[in] val - Value to check
** \param[in] ref - Reference value
** \param[in] tolerance - Tolerance on reference value (in percent)
** \return true if val is inTolerance
**/
__INLINE bool inTolerance(const SDWORD val, const SDWORD ref, float tolerance) {
	tolerance = min(100.0f, max(0.0f, tolerance));
	DWORD margin = (DWORD) (ref * (tolerance / 100.0f));
	return ((val <= (SDWORD) (ref + margin)) && (val >= (SDWORD) (ref - margin))); }

/*!\brief Checks if val given as parameter is in range
** \param[in] val - Value to check
** \param[in] low - Low range boundary
** \param[in] high - High range boundary
** \return true if val is inRange
**/
__INLINE bool INLINE__ inRange(const SDWORD val, const SDWORD low, const SDWORD high) {
	return ((val <= high) && (val >= low)); }


/*****************************/
/***  ENDIANS CONVERSIONS  ***/
/*****************************/

/*!\brief Swap endians of the contents of a 16b value (little -> big, big -> little)
** \param[in] w - 16b value
** \return Swapped value
**/
__INLINE WORD SWAP_END16B(const WORD w) {
	return (WORD) (LSHIFT((w & 0xFFU), 8) | RSHIFT((w & 0xFF00U), 8)); }

/*!\brief Swap endians of the contents of a 32b value (little -> big, big -> little)
** \param[in] d - 32b value
** \return Swapped value
**/
__INLINE DWORD SWAP_END32B(const DWORD d) {
	return (DWORD) (LSHIFT(SWAP_END16B(d & 0xFFFFUL), 16) | SWAP_END16B(RSHIFT((d & 0xFFFF0000UL), 16))); }

/*!\brief Swap endians of the contents of a 64b value (little -> big, big -> little)
** \param[in] l - 64b value
** \return Swapped value
**/
__INLINE LWORD SWAP_END64B(const LWORD l) {
	return (LWORD) (LSHIFT64(SWAP_END32B(l & 0xFFFFFFFFULL), 32) | SWAP_END32B(RSHIFT64((l & 0xFFFFFFFF00000000ULL), 32))); }


/*!\brief Swap endians of a 16b tab (little -> big, big -> little)
** \param[in] tab - tab of 16b values
** \param[in] nb - nb of values in tab
**/
__INLINE void NONNULL_INLINE__ SWAP_END16B_TAB(WORD tab[], const WORD nb) {
	for (unsigned int i = 0 ; i < nb ; i++)	tab[i] = SWAP_END16B(tab[i]); }

/*!\brief Swap endians of a 32b tab (little -> big, big -> little)
** \param[in] tab - tab of 32b values
** \param[in] nb - nb of values in tab
**/
__INLINE void NONNULL_INLINE__ SWAP_END32B_TAB(DWORD tab[], const WORD nb) {
	for (unsigned int i = 0 ; i < nb ; i++)	tab[i] = SWAP_END32B(tab[i]); }

/*!\brief Swap endians of a 64b tab (little -> big, big -> little)
** \param[in] tab - tab of 64b values
** \param[in] nb - nb of values in tab
**/
__INLINE void NONNULL_INLINE__ SWAP_END64B_TAB(LWORD tab[], const WORD nb) {
	for (unsigned int i = 0 ; i < nb ; i++)	tab[i] = SWAP_END64B(tab[i]); }


/*************************/
/***  ENDIANS TESTING  ***/
/*************************/

/*!\brief Test Core endian
** \return Endian type
**/
__INLINE eEndian testEndian_basic(void) {
	WORD x = 0x100;
	return (* (CHAR *) (&x)) ? Endian_big : Endian_little; }

/*!\brief Test Core endian (full, recognizing mid endians too)
** \return Endian type
**/
__INLINE eEndian testEndian_full(void) {
	union {
		LWORD	dword;
		BYTE	byte[sizeof(LWORD)];
	} tst;

	tst.byte[0] = 1;
	tst.byte[1] = 2;
	tst.byte[2] = 3;
	tst.byte[3] = 4;

	switch (tst.dword)
	{
		case 0x01020304UL:	return Endian_big;
		case 0x04030201UL:	return Endian_little;
		case 0x03040102UL:	return Endian_mid_big;
		case 0x02010403UL:	return Endian_mid_little;
		default:      		return Endian_unknown;
	}
}


/************************/
/***  FLOATING POINT  ***/
/************************/

/*!\brief Get floating point number decimal part
** \note in need to print floats, add '-u _printf_float' in Linker options.
** \warning enabling floating point support from linker seems to fubar printing long variables,
** 			so welcome get_fp_dec for the purpose.
** \param[in] f - floating point value
** \param[in] nb - Number of decimal to get after floating point
** \return nb decimal part as integer
**/
__INLINE int32_t get_fp_dec(float f, uint8_t nb) {
	int32_t mul = 1;
	f -= (int32_t) f;
	while (nb-- != 0) { mul *= 10; }
	return (int32_t) (f * mul); }


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_H */
/****************************************************************/
