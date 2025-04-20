/*!\file arm_chip_ino.h
** \author SMFSW
** \copyright MIT (c) 2017-2025, SMFSW
** \brief Common macros for Arduino
** \MISRA Header scope legitimate use derogation authorized for:\n
** 	\b Rule-5.5 - \b Required: distinct identifier and macro name (misra-c2012-5.5)\n
** 	\b Rule-5.6 - \b Required: unique \c typedef name (misra-c2012-5.6)\n
** 	\b Rule-5.7 - \b Required: unique tag name (misra-c2012-5.7)\n
** 	\b Rule-5.9 - \b Advisory: internal linkage unique function name (misra-c2012-5.9)\n
**	\a Justification: tag and \c typedefs name are only defined once (other arm_chip_xxx files are not included at the same time).\n
*/
// cppcheck-suppress-begin [misra-c2012-5.9]
// cppcheck-suppress-begin [misra-c2012-5.5, misra-c2012-5.6, misra-c2012-5.7]
/****************************************************************/
#ifndef ARM_CHIP_INO_H_
	#define ARM_CHIP_INO_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/
#if ARDUINO > 22
#include "Arduino.h"			// Common Arduino definitions
#else
#include "WProgram.h"			// Common Arduino definitions
#endif
#include "pins_arduino.h"		// Arduino pins definitions for current board
/****************************************************************/


/*** Define Enable/Disable interrupts macros ***/
#undef diInterrupts		// cppcheck-suppress misra-c2012-20.5
#undef enInterrupts		// cppcheck-suppress misra-c2012-20.5
#define diInterrupts()		noInterrupts()		//!< Disable interruptions macro
#define enInterrupts()		interrupts()		//!< Enable interruptions macro

/*** MS Time base ***/
#ifndef HAL_MAX_TICKS
//!\note Define HAL_MAX_TICKS with custom max value in project if tick max value is not using 32b variable full scale
#define HAL_MAX_TICKS		((DWORD) -1)		//!< Max Ticks value
#endif
#ifndef HAL_MS_TICKS_FACTOR
//!\note Define HAL_MS_TICKS_FACTOR with custom multiplier in project if tick period is not 1ms
#define HAL_MS_TICKS_FACTOR	1U					//!< Milliseconds multiplier (depending tick counter frequency)
#endif

#ifndef HALTicks
#define HALTicks			millis				//!< Alias for Arduino get ms ticks function
#endif


#if !defined(USE_INO_BINARY_HEADER)
// Undefine binary.h definitions used by \file arm_typedefs.h included from Arduino.h
//!\MISRA Local deviation has been granted for following rules:\n
//!	\b Rule-20.5 - \b Advisory: \c \#undef (misra-c2012-20.5)\n
#undef	B0		// cppcheck-suppress misra-c2012-20.5
#undef	B1		// cppcheck-suppress misra-c2012-20.5
#else
#define B0	0
#define B1	1
#endif


/*!\enum _eResetSource
** \brief Source of last reset
**/
typedef enum _eResetSource {
	RST_POR = 1,		//!< Power On Reset
	RST_UNKNOWN = 0xFF	//!< Unknown Reset Source
} eResetSource;


/*!\brief Get and convert ARDUINO Reset Source to eResetSource
** \warning This function should be called soon after reset
** \return Last reset source
**/
static inline eResetSource HAL_ResetSource(void) {
	return RST_UNKNOWN; }


/*!\brief Convert Arduino error code to FctERR
** \param[in] status - Arduino error code
** \return FctERR status
**/
static inline FctERR HALERRtoFCTERR(const SDWORD status)
{
	FctERR err;

	if (status == 0)	{ err = ERROR_OK; }
	else				{ err = ERROR_COMMON; }

	return err;
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_CHIP_INO_H_ */
// cppcheck-suppress-end [misra-c2012-5.9]
// cppcheck-suppress-end [misra-c2012-5.5, misra-c2012-5.6, misra-c2012-5.7]
/****************************************************************/
