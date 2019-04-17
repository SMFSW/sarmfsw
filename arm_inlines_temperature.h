/*!\file arm_inlines_temperature.h
** \author SMFSW
** \copyright MIT (c) 2017-2019, SMFSW
** \brief Temperature conversion inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_TEMPERATURE_H
	#define __ARM_INLINES_TEMPERATURE_H

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


/*!\brief Convert degrees Celsius to Kelvin
** \param[in] cel - Celsius degrees value
** \return Kelvin degrees
**/
__INLINE float celsius2kelvin(const float cel)
{
	return (cel + 273.15f);
}


/*!\brief Convert degrees Kelvin to Celsius
** \param[in] kel - Kelvin degrees value
** \return Kelvin degrees
**/
__INLINE float kelvin2celsius(const float kel)
{
	return (kel - 273.15f);
}


/*!\brief Convert degrees Celsius to Fahrenheit
** \param[in] cel - Celsius degrees value
** \return Fahrenheit degrees
**/
__INLINE float celsius2fahrenheit(const float cel)
{
	return (cel * (9.0f / 5.0f)) + 32.0f;
}


/*!\brief Convert degrees Fahrenheit to Celsius
** \param[in] fah - Fahrenheit degrees value
** \return Celsius degrees
**/
__INLINE float fahrenheit2celsius(const float fah)
{
	return ((fah - 32.0f) * (5.0f / 9.0f));
}


/*!\brief Convert degrees Fahrenheit to Kelvin
** \param[in] fah - Fahrenheit degrees value
** \return Kelvin degrees
**/
__INLINE float fahrenheit2kelvin(const float fah)
{
	return (celsius2kelvin(fahrenheit2celsius(fah)));
}


/*!\brief Convert degrees Kelvin to Fahrenheit
** \param[in] kel - Kelvin degrees value
** \return Fahrenheit degrees
**/
__INLINE float kelvin2fahrenheit(const float kel)
{
	return (celsius2fahrenheit(kelvin2celsius(kel)));
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_TEMPERATURE_H */
/****************************************************************/
