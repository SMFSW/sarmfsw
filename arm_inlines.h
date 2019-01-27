/*!\file arm_inlines.h
** \author SMFSW
** \copyright MIT (c) 2017-2019, SMFSW
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
	register const	uint32_t hNow = HALTicks();
	const uint32_t	diff = (hNow >= last) ? hNow - last : (HAL_MAX_TICKS - last) + hNow;
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
	register const	uint32_t hNow = HALTicks();
	const uint32_t	diff = (hNow >= last) ? hNow - last : (HAL_MAX_TICKS - last) + hNow;
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
	const BYTE	nb = (bits > nb_bits) ? nb_bits : bits;
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
	const BYTE	nb = (bits > nb_bits) ? nb_bits : bits;
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
	const BYTE	nb = (bits > nb_bits ? nb_bits : bits) - 1;
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
	const BYTE	ms = RSHIFT(bcd & 0xF0, 4);
	const BYTE	ls = bcd & 0x0F;
	if ((ms > 9) || (ls > 9))	{ return 0xFF; }
	return (BYTE) ((ms * 10) + ls); }


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
__INLINE BYTE ASCIIToHex(const CHAR ascii) {
	if ((ascii >= '0') && (ascii <= '9'))			{ return ascii - 0x30; }
	else if ((ascii >= 'A') && (ascii <= 'F'))		{ return ascii - 0x37; }
	else if ((ascii >= 'a') && (ascii <= 'f'))		{ return ascii - 0x47; }
	else											{ return 0xFF; } }


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
	SWORD	bits = 32;
	DWORD	tmp = gray;
	while ((bits >>= 1) > 0)	{ tmp ^= (tmp >> bits); }
	return tmp; }


/******************************/
/***  VAR SIZE CONVERSIONS  ***/
/******************************/

/*!\brief convert 16bits variable to 8bits
** \param[in] val - 16b value to convert
** \return Converted value
**/
__INLINE BYTE INLINE__ conv16to8Bits(const WORD val) {
	return (BYTE) RSHIFT(val, 8); }

/*!\brief convert 8bits variable to 16bits
** \param[in] val - 8b value to convert
** \return Converted value
**/
__INLINE WORD INLINE__ conv8to16Bits(const BYTE val) {
	return (WORD) (LSHIFT(val, 8) + val); }


/*!\brief convert 32bits variable to 16bits
** \param[in] val - 32b value to convert
** \return Converted value
**/
__INLINE WORD INLINE__ conv32to16Bits(const DWORD val) {
	return (WORD) RSHIFT(val, 16); }

/*!\brief convert 16bits variable to 32bits
** \param[in] val - 16b value to convert
** \return Converted value
**/
__INLINE DWORD INLINE__ conv16to32Bits(const WORD val) {
	return (DWORD) (LSHIFT(val, 16) + val); }


/*!\brief convert 64bits variable to 32bits
** \param[in] val - 64b value to convert
** \return Converted value
**/
__INLINE DWORD INLINE__ conv64to32Bits(const LWORD val) {
	return (DWORD) RSHIFT64(val, 32); }

/*!\brief convert 32bits variable to 64bits
** \param[in] val - 32b value to convert
** \return Converted value
**/
__INLINE LWORD INLINE__ conv32to64Bits(const DWORD val) {
	return (LWORD) (LSHIFT64(val, 32) + val); }


/*!\brief convert 8bits variable to 8+nb bits (16bits max)
** \warning conversion output shall not exceed 16bits (input shall strictly be unsigned 8bits)
** \warning nb shall be in range 0-8 (note that using 0 doesn't change val)
** \param[in] val - 8b value to convert
** \param[in] nb - number of bits to add (8bits max)
** \return Converted value
**/
__INLINE WORD conv8upto16Bits(const BYTE val, const BYTE nb) {
	return (WORD) ((val << nb) + (val >> (8 - nb))); }

/*!\brief convert 16bits variable to 16+nb bits (32bits max)
** \warning conversion output shall not exceed 32bits (input shall strictly be unsigned 16bits)
** \warning nb shall be in range 0-16 (note that using 0 doesn't change val)
** \param[in] val - 16b value to convert
** \param[in] nb - number of bits to add (16bits max)
** \return Converted value
**/
__INLINE DWORD conv16upto32Bits(const WORD val, const BYTE nb) {
	return (DWORD) ((val << nb) + (val >> (16 - nb))); }

/*!\brief convert 32bits variable to 32+nb bits (64bits max)
** \warning conversion output shall not exceed 64bits (input shall strictly be unsigned 32bits)
** \warning nb shall be in range 0-32 (note that using 0 doesn't change val)
** \param[in] val - 32b value to convert
** \param[in] nb - number of bits to add (32bits max)
** \return Converted value
**/
__INLINE LWORD conv32upto64Bits(const DWORD val, const BYTE nb) {
	return (LWORD) (((LWORD) val << nb) + (val >> (32 - nb))); }


/*!\brief convert x bits variable to y bits (32bits max)
** \warning conversion output shall not exceed 32bits (input shall strictly be unsigned 32bits)
** \warning nb shall be in range 0-32
** \param[in] val - x bits value to convert
** \param[in] from - number of bits from former variable
** \param[in] to - number of bits of output variable
** \return Converted value
**/
__INLINE DWORD convXtoYBits(const DWORD val, const BYTE from, const BYTE to)
{
	const int8_t diff_bits = min(32, to) - min(32, from);
	if (diff_bits > 0)		{ return (DWORD) ((val << diff_bits) + (val >> (from - diff_bits))); }
	else if (diff_bits < 0)	{ return (DWORD) RSHIFT(val, diff_bits); }
	return val;
}


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
	const DWORD margin = (DWORD) (ref * (tolerance / 100.0f));
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
	const WORD x = 0x100;
	return (*(BYTE *) (&x)) ? Endian_big : Endian_little; }

/*!\brief Test Core endian (full, recognizing mid endians too)
** \return Endian type
**/
__INLINE eEndian testEndian_full(void) {
	union {
		LWORD	dword;
		BYTE	byte[sizeof(LWORD)];
	} tst = { .byte = { 1, 2, 3, 4 } };

	switch (tst.dword)
	{
		case 0x01020304UL:	return Endian_big;
		case 0x04030201UL:	return Endian_little;
		case 0x03040102UL:	return Endian_mid_big;
		case 0x02010403UL:	return Endian_mid_little;
		default:      		return Endian_unknown;
	}
}


/*********************************/
/***  TEMPERATURE CCONVERSIONS ***/
/*********************************/

/*!\brief Convert degrees Celsius to Kelvin
** \param[in] cels - Celsius degrees value
** \return Kelvin degrees
**/
__INLINE float celsius2kelvin(const float cels) {
	return (cels + 273.15f); }

/*!\brief Convert degrees Kelvin to Celsius
** \param[in] kelv - Kelvin degrees value
** \return Kelvin degrees
**/
__INLINE float kelvin2celsius(const float kelv) {
	return (kelv - 273.15f); }


/*!\brief Convert degrees Celsius to Fahrenheit
** \param[in] cels - Celsius degrees value
** \return Fahrenheit degrees
**/
__INLINE float celsius2fahrenheit(const float cels) {
	return (cels * (9.0f / 5.0f)) + 32.0f; }

/*!\brief Convert degrees Fahrenheit to Celsius
** \param[in] fahr - Fahrenheit degrees value
** \return Celsius degrees
**/
__INLINE float fahrenheit2celsius(const float fahr) {
	return ((fahr - 32.0f) * (5.0f / 9.0f)); }


/*!\brief Convert degrees Fahrenheit to Kelvin
** \param[in] fahr - Fahrenheit degrees value
** \return Kelvin degrees
**/
__INLINE float fahrenheit2kelvin(const float fahr) {
	return (celsius2kelvin(fahrenheit2celsius(fahr))); }

/*!\brief Convert degrees Kelvin to Fahrenheit
** \param[in] kelv - Kelvin degrees value
** \return Fahrenheit degrees
**/
__INLINE float kelvin2fahrenheit(const float kelv) {
	return (celsius2fahrenheit(kelvin2celsius(kelv))); }


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
__INLINE SDWORD get_fp_dec(float f, BYTE nb) {
	SDWORD mul = 1;
	f -= (SDWORD) f;
	while (nb-- != 0) { mul *= 10; }
	return (SDWORD) (f * mul); }


/*******************/
/***  AVERAGING  ***/
/*******************/

#define	RESTRICTED_AVERAGE(typ_t, sum_t)																						\
	__INLINE typ_t RestrictedAverage_##typ_t(volatile typ_t pArray[], const uint8_t nb)											\
	{																															\
		typ_t	Array[nb];																										\
		sum_t	sum = 0;																										\
																																\
		if (nb <= 2)	{ return 0; }																							\
																																\
		/* Array copy (memcpy not used as copy by byte and pTab may be volatile) */												\
		for (int i = 0 ; i < nb ; i++)			{ Array[i] = pArray[i]; }														\
		/* Shift min to first array index */																					\
		for (int i = 1 ; i < nb ; i++)			{ if (Array[i] < Array[0])	SWAP_TYPE(Array[0], Array[i], typ_t); }				\
		/* Shift max to last array index */																						\
		for (int i = 1 ; i < (nb - 1) ; i++)	{ if (Array[i] > Array[nb - 1])	SWAP_TYPE(Array[nb - 1], Array[i], typ_t); }	\
		/* Sum and averaging */																									\
		for (int i = 1 ; i < (nb - 1) ; i++)	{ sum += Array[i]; }															\
		return (sum / (nb - 2));																								\
	}																															\

/*!\brief Get average value of tab excluding most extreme values (BYTE)
** \warning If pArray is volatile array:
** 			A new value may be written in the tab (by interrupt for example) while copying it (not dangerous for BYTEs).
** 			Disabling interruptions before calling function can overcome this behavior if needed
** 			(not forgetting to re-enable interrupts after).
**
**
** \param[in] pArray - Pointer to BYTEs array
** \param[in] nb - Number of array elements
** \return Average value (BYTE)
**/
RESTRICTED_AVERAGE(BYTE, DWORD);

/*!\brief Get average value of tab excluding most extreme values (WORD)
** \warning If pArray is volatile array:
** 			A new value may be written in the tab (by interrupt for example) while copying it
** 			(which can lead to corrupted results for 8b microcontroller).
** 			Disabling interruptions before calling function can overcome this behavior if needed
** 			(not forgetting to re-enable interrupts after).
**
** \param[in] pArray - Pointer to WORDs array
** \param[in] nb - Number of array elements
** \return Average value (WORD)
**/
RESTRICTED_AVERAGE(WORD, LWORD);

/*!\brief Get average value of tab excluding most extreme values (DWORD)
** \warning If pArray is volatile array:
** 			A new value may be written in the tab (by interrupt for example) while copying it
** 			(which can lead to corrupted results for 8b and 16b microcontroller).
** 			Disabling interruptions before calling function can overcome this behavior if needed
** 			(not forgetting to re-enable interrupts after).
**
** \param[in] pArray - Pointer to DWORDs array
** \param[in] nb - Number of array elements
** \return Average value (DWORD)
**/
RESTRICTED_AVERAGE(DWORD, LWORD);

/*!\brief Get average value of tab excluding most extreme values (SBYTE)
** \warning If pArray is volatile array:
** 			A new value may be written in the tab (by interrupt for example) while copying it (not dangerous for SBYTEs).
** 			Disabling interruptions before calling function can overcome this behavior if needed
** 			(not forgetting to re-enable interrupts after).
**
** \param[in] pArray - Pointer to SBYTEs array
** \param[in] nb - Number of array elements
** \return Average value (SBYTE)
**/
RESTRICTED_AVERAGE(SBYTE, SDWORD);

/*!\brief Get average value of tab excluding most extreme values (SWORD)
** \warning If pArray is volatile array:
** 			A new value may be written in the tab (by interrupt for example) while copying it
** 			(which can lead to corrupted results for 8b microcontroller).
** 			Disabling interruptions before calling function can overcome this behavior if needed
** 			(not forgetting to re-enable interrupts after).
**
** \param[in] pArray - Pointer to SWORDs array
** \param[in] nb - Number of array elements
** \return Average value (SWORD)
**/
RESTRICTED_AVERAGE(SWORD, SLWORD);

/*!\brief Get average value of tab excluding most extreme values (SDWORD)
** \warning If pArray is volatile array:
** 			A new value may be written in the tab (by interrupt for example) while copying it
** 			(which can lead to corrupted results for 8b and 16b microcontroller).
** 			Disabling interruptions before calling function can overcome this behavior if needed
** 			(not forgetting to re-enable interrupts after).
**
** \param[in] pArray - Pointer to SDWORDs array
** \param[in] nb - Number of array elements
** \return Average value (SDWORD)
**/
RESTRICTED_AVERAGE(SDWORD, SLWORD);

/*!\brief Get average value of tab excluding most extreme values (float)
** \warning If pArray is volatile array:
** 			A new value may be written in the tab (by interrupt for example) while copying it
** 			(which can lead to corrupted results).
** 			Disabling interruptions before calling function can overcome this behavior
** 			(not forgetting to re-enable interrupts after).
**
** \param[in] pArray - Pointer to floats array
** \param[in] nb - Number of array elements
** \return Average value (float)
**/
RESTRICTED_AVERAGE(float, float);

/*!\brief Get average value of tab excluding most extreme values (double)
** \warning If pArray is volatile array:
** 			A new value may be written in the tab (by interrupt for example) while copying it
** 			(which can lead to corrupted results).
** 			Disabling interruptions before calling function can overcome this behavior
** 			(not forgetting to re-enable interrupts after).
**
** \param[in] pArray - Pointer to doubles array
** \param[in] nb - Number of array elements
** \return Average value (double)
**/
RESTRICTED_AVERAGE(double, double);


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_H */
/****************************************************************/
