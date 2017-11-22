/*!\file arm_chip_ino.h
** \author SMFSW
** \date 2017
** \copyright MIT (c) 2017, SMFSW
** \brief Common macros for Arduino
*/
/****************************************************************/
#ifndef __ARM_CHIP_INO_H
	#define __ARM_CHIP_INO_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "arm_attributes.h"		// Common attributes depending compiler
#include "arm_typedefs.h"		// Common typedefs
#include "arm_errors.h"			// Common errors
#include "arm_cmsis.h"			// HAL & Drivers depending platform
/****************************************************************/
#if ARDUINO > 22
	#include "Arduino.h"		// Common Arduino definitions
#else
	#include "WProgram.h"		// Common Arduino definitions
#endif
#include "pins_arduino.h"		// Arduino pins definitions
/****************************************************************/


/*** Define Enable/Disable interrupts macros ***/
#define	diInterrupts()		cli()				//!< Disable interruptions macro
#define	enInterrupts()		sei()				//!< Enable interruptions macro

/*** MS Time base ***/
#ifndef HAL_MAX_TICKS
//!\note Define HAL_MAX_TICKS with custom max value in project if tick max value is not using 32b variable full scale
#define HAL_MAX_TICKS		((uint32_t) -1)		//!< Max Ticks value
#endif
#ifndef HAL_MS_TICKS_FACTOR
//!\note Define HAL_MS_TICKS_FACTOR with custom multiplier in project if tick period is not 1ms
#define HAL_MS_TICKS_FACTOR	1					//!< Milliseconds multiplier (depending tick counter frequency)
#endif

#define HALTicks()			micros()			//!< Alias for Arduino get ms ticks function

/*!\brief Convert Arduino error code to FctERR
** \param[in] status - Arduino error code
** \return FctERR status
**/
__INLINE FctERR HALERRtoFCTERR(int32_t status)
{
	if (status == 0)	return ERROR_OK;
	else				return ERROR_COMMON;
}

/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_CHIP_INO_H */
/****************************************************************/
