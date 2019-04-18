/*!\file arm_inlines_angle.h
** \author SMFSW
** \copyright MIT (c) 2017-2019, SMFSW
** \brief Angle conversion inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_ANGLE_H
	#define __ARM_INLINES_ANGLE_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <math.h>
#include "arm_typedefs.h"			// Common typedefs
/****************************************************************/


#define M_PI_180	0.017453292519943295		//!< Pi/180 approximation constant
#define M_180_PI	57.295779513082323			//!< 180/Pi approximation constant


/*!\brief Radians normalization (normalize angle to single rotation)
** \param[in] rad - Radians to convert
** \return Converted angle
**/
__INLINE float RAD_NORM(float rad)
{
	while (fabs(rad) > M_TWOPI)
	{
		 rad += (rad < 0.0f) ? M_TWOPI : -M_TWOPI;
	}

	return rad;
}


/*!\brief Degrees normalization (normalize angle to single rotation)
** \param[in] deg - Degrees to convert
** \return Converted angle
**/
__INLINE float DEG_NORM(float deg)
{
	while (fabs(deg) > 360.0f)
	{
		 deg += (deg < 0.0f) ? 360.0f : -360.0f;
	}

	return deg;
}


/*!\brief Radians to degrees conversion
** \param[in] rad - Radians to convert
** \return Converted angle
**/
__INLINE float RAD_TO_DEG(const float rad)
{
	return RAD_NORM(rad) * M_180_PI;
}


/*!\brief Degrees to radians conversion
** \param[in] deg - Degrees to convert
** \return Converted angle
**/
__INLINE float DEG_TO_RAD(const float deg)
{
	return RAD_NORM(deg) * M_PI_180;
}


/*!\brief Radians to 0-1 scaled float conversion
** \param[in] rad - Radians to convert
** \return Converted angle
**/
__INLINE float RAD_TO_FLOAT(const float rad)
{
	return RAD_NORM(rad) / M_TWOPI;
}

/*!\brief 0-1 scaled float to radians conversion
** \param[in] val - 0-1 scaled float to convert
** \return Converted angle
**/
__INLINE float FLOAT_TO_RAD(const float val)
{
	return (val - (SDWORD) val) * M_TWOPI;
}


/*!\brief Degrees to 0-1 scaled float conversion
** \param[in] deg - Degrees to convert
** \return Converted angle
**/
__INLINE float DEG_TO_FLOAT(const float deg)
{
	return DEG_NORM(deg) / 360.0f;
}

/*!\brief 0-1 scaled float to degrees conversion
** \param[in] val - 0-1 scaled float to convert
** \return Converted angle
**/
__INLINE float FLOAT_TO_DEG(const float val)
{
	return (val - (SDWORD) val) * 360.0f;
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_ANGLE_H */
/****************************************************************/
