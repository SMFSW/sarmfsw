/*!\file arm_inlines_rotation.h
** \author SMFSW
** \copyright MIT (c) 2017-2022, SMFSW
** \brief Rotation inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_ROTATION_H
	#define __ARM_INLINES_ROTATION_H

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
			const float rad = deg * M_PI_180;
			r.x = (SDWORD) ((c.x * cos(rad)) - (c.y * sin(rad)));
			r.y = (SDWORD) ((c.x * sin(rad)) + (c.y * cos(rad)));
		}
		break;

		case 0:
			return c;

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
			if (deg == 90)	{ return (sCoord2D) { -r.y, r.x }; }

		case 180:
			// Return only if 180°, otherwise, continue
			if (deg == 180)	{ return (sCoord2D) { -r.x, -r.y }; }

		case 270:
			// Return only if 270°, otherwise, continue
			if (deg == 270)	{ return (sCoord2D) { r.y, -r.x }; }
	}

	return r;
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_ROTATION_H */
/****************************************************************/
