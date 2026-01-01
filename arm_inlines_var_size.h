/*!\file arm_inlines_var_size.h
** \author SMFSW
** \copyright MIT (c) 2017-2026, SMFSW
** \brief Variables size conversion inlines
*/
/****************************************************************/
#ifndef ARM_INLINES_VAR_SIZE_H_
	#define ARM_INLINES_VAR_SIZE_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


/*!\brief convert 16bits variable to 8bits
** \param[in] val - 16b value to convert
** \return Converted value
**/
__INLINE BYTE INLINE__ conv16to8Bits(const WORD val)
{
	return (BYTE) RSHIFT16(val, 8U);
}


/*!\brief convert 8bits variable to 16bits
** \param[in] val - 8b value to convert
** \return Converted value
**/
__INLINE WORD INLINE__ conv8to16Bits(const BYTE val)
{
	return LSHIFT16(val, 8U) | val;
}


/*!\brief convert 32bits variable to 16bits
** \param[in] val - 32b value to convert
** \return Converted value
**/
__INLINE WORD INLINE__ conv32to16Bits(const DWORD val)
{
	return (WORD) RSHIFT32(val, 16U);
}


/*!\brief convert 16bits variable to 32bits
** \param[in] val - 16b value to convert
** \return Converted value
**/
__INLINE DWORD INLINE__ conv16to32Bits(const WORD val)
{
	return LSHIFT32(val, 16U) | val;
}


/*!\brief convert 64bits variable to 32bits
** \param[in] val - 64b value to convert
** \return Converted value
**/
__INLINE DWORD INLINE__ conv64to32Bits(const LWORD val)
{
	return (DWORD) RSHIFT64(val, 32U);
}


/*!\brief convert 32bits variable to 64bits
** \param[in] val - 32b value to convert
** \return Converted value
**/
__INLINE LWORD INLINE__ conv32to64Bits(const DWORD val)
{
	return LSHIFT64(val, 32U) | val;
}


/*!\brief convert 8bits variable to 8+nb bits (16bits max)
** \warning conversion output shall not exceed 16bits (input shall strictly be unsigned 8bits)
** \warning nb shall be in range 0-8 (note that using 0 doesn't change val)
** \param[in] val - 8b value to convert
** \param[in] nb - number of bits to add (8bits max)
** \return Converted value
**/
__INLINE WORD conv8upto16Bits(const BYTE val, const BYTE nb)
{
	const BYTE rem = 8U - nb;
	return LSHIFT16(val, nb) | RSHIFT16(val, rem);
}


/*!\brief convert 16bits variable to 16+nb bits (32bits max)
** \warning conversion output shall not exceed 32bits (input shall strictly be unsigned 16bits)
** \warning nb shall be in range 0-16 (note that using 0 doesn't change val)
** \param[in] val - 16b value to convert
** \param[in] nb - number of bits to add (16bits max)
** \return Converted value
**/
__INLINE DWORD conv16upto32Bits(const WORD val, const BYTE nb)
{
	const BYTE rem = 16U - nb;
	return LSHIFT32(val, nb) | RSHIFT32(val, rem);
}


/*!\brief convert 32bits variable to 32+nb bits (64bits max)
** \warning conversion output shall not exceed 64bits (input shall strictly be unsigned 32bits)
** \warning nb shall be in range 0-32 (note that using 0 doesn't change val)
** \param[in] val - 32b value to convert
** \param[in] nb - number of bits to add (32bits max)
** \return Converted value
**/
__INLINE LWORD conv32upto64Bits(const DWORD val, const BYTE nb)
{
	const BYTE rem = 32U - nb;
	return LSHIFT64(val, nb) | RSHIFT64(val, rem);
}


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
	const SBYTE diff_bits = MIN(32U, to) - MIN(32U, from);
	const BYTE shift = abs(diff_bits);
	DWORD conv = val & maskBits(from);

	if (diff_bits > 0)	{ conv = LSHIFT32(conv, shift) | RSHIFT32(conv, (BYTE) (from - shift)); }
	if (diff_bits < 0)	{ conv = RSHIFT32(conv, shift); }

	return conv;
}


/*!\brief Scale value from one range to another
**
** \param[in] val - Value to scale
** \param[in] from_min - Minimal input range value
** \param[in] from_max - Maximal input range value
** \param[in] to_min - Minimal output range value
** \param[in] to_max - Maximal output range value
**/
__INLINE SLWORD scaleValue(const SLWORD val, const SLWORD from_min, const SLWORD from_max, const SLWORD to_min, const SLWORD to_max)
{
	return (((val - from_min) * (to_max - to_min)) / (from_max - from_min)) + to_min;
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_INLINES_VAR_SIZE_H_ */
/****************************************************************/
