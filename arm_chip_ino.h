/*!\file arm_chip_ino.h
** \author SMFSW
** \copyright MIT (c) 2017-2018, SMFSW
** \brief Common macros for Arduino
*/
/****************************************************************/
#ifndef __ARM_CHIP_INO_H
	#define __ARM_CHIP_INO_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "arm_attributes.h"		// Common attributes (following compiler)
#include "arm_typedefs.h"		// Common typedefs
#include "arm_errors.h"			// Common errors
#include "arm_cmsis.h"			// HAL & Drivers (following defined platform)
/****************************************************************/
#if ARDUINO > 22
	#include "Arduino.h"		// Common Arduino definitions
#else
	#include "WProgram.h"		// Common Arduino definitions
#endif
#include "pins_arduino.h"		// Arduino pins definitions for current board
/****************************************************************/


/*** Define Enable/Disable interrupts macros ***/
#undef diInterrupts
#define diInterrupts()		noInterrupts()		//!< Disable interruptions macro
#undef enInterrupts
#define enInterrupts()		interrupts()		//!< Enable interruptions macro

/*** MS Time base ***/
#ifndef HAL_MAX_TICKS
//!\note Define HAL_MAX_TICKS with custom max value in project if tick max value is not using 32b variable full scale
#define HAL_MAX_TICKS		((uint32_t) -1)		//!< Max Ticks value
#endif
#ifndef HAL_MS_TICKS_FACTOR
//!\note Define HAL_MS_TICKS_FACTOR with custom multiplier in project if tick period is not 1ms
#define HAL_MS_TICKS_FACTOR	1					//!< Milliseconds multiplier (depending tick counter frequency)
#endif

#define HALTicks()			millis()			//!< Alias for Arduino get ms ticks function


/*!\enum eResetSource
** \brief Source of last reset
**/
typedef enum eResetSource {
	RST_POR = 1,		//!< Power On Reset
	RST_UNKNOWN = 0xFF	//!< Unknown Reset Source
} eResetSource;


/*!\brief Get and convert ARDUINO Reset Source to eResetSource
** \warning This function should be called soon after reset
** \return Last reset source
**/
__INLINE eResetSource INLINE__ HAL_ResetSource(void) {
	return RST_UNKNOWN; }


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
