/*!\file arm_inlines_rotation.h
** \author SMFSW
** \copyright MIT (c) 2017-2025, SMFSW
** \brief Rotation inlines
*/
/****************************************************************/
#ifndef ARM_INLINES_ROTATION_H_
	#define ARM_INLINES_ROTATION_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include <math.h>
/****************************************************************/


/*!\struct sCoord2D
** \brief 2D coordinates structure
**/
typedef struct sCoord2D {
	SDWORD	x;	//!< x coordinate
	SDWORD	y;	//!< y coordinate
} sCoord2D;


/*!\brief 2D Coordinates rotation
** \note Counter clockwise rotation
** \MISRA Function scope deviation granted for:\n
**	\b Rule-15.5 - \b Advisory: single point of exit (misra-c2012-15.5)\n
** \param[in] c - Coordinates to rotate
** \param[in] angle - Rotation angle (in degrees, counter clockwise)
** \return Rotated coordinates
**/
__INLINE sCoord2D rotate_2D(const sCoord2D c, const SWORD angle)
{
	sCoord2D	r = { c.x, c.y };
	SWORD		deg = angle % 360;

	if (deg < 0)	{ deg += 360; }

	switch (deg)
	{
		default:
		{
			const float rad = (float) deg * M_PI_180;
			const float cos_rad = cos(rad);
			const float sin_rad = sin(rad);
			r.x = (SDWORD) ((c.x * cos_rad) - (c.y * sin_rad));
			r.y = (SDWORD) ((c.x * sin_rad) + (c.y * cos_rad));
		}
		break;

		case 0:
			return c;	// cppcheck-suppress misra-c2012-15.5

		case 45:
		case 90 + 45:
		case 180 + 45:
		case 270 + 45:
			r.x = (SDWORD) ((c.x - c.y) / M_SQRT2);
			r.y = (SDWORD) ((c.x + c.y) / M_SQRT2);
			deg -= 45;
			//break;	// No break, may still need to rotate by a multiple of 90°

		case 90:
			// Return only if 90°, otherwise, continue
			if (deg == 90)	{ return (sCoord2D) { -r.y, r.x }; }	// cppcheck-suppress misra-c2012-15.5

		case 180:
			// Return only if 180°, otherwise, continue
			if (deg == 180)	{ return (sCoord2D) { -r.x, -r.y }; }	// cppcheck-suppress misra-c2012-15.5

		case 270:
			// Return only if 270°, otherwise, continue
			if (deg == 270)	{ return (sCoord2D) { r.y, -r.x }; }	// cppcheck-suppress misra-c2012-15.5
	}

	return r;
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_INLINES_ROTATION_H_ */
/****************************************************************/
