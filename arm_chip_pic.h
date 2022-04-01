/*!\file arm_chip_pic.h
** \author SMFSW
** \copyright MIT (c) 2017-2022, SMFSW
** \brief Common macros for PIC
** \attention	On PIC families you should configure a timer to count for ms.
**				A TIM peripheral shall be configured in MCC or Harmony (with a period of 1ms).
**
** HAL_GetTick shall be known to sarmfsw.
** As no specific project header is included yet in this file, external definition is provided.
**
** \code
** #include <stdint.h>
** uint32_t HAL_GetTick(void);
** \endcode
*/
/****************************************************************/
#ifndef __ARM_CHIP_PIC_H
	#define __ARM_CHIP_PIC_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "arm_attributes.h"		// Common attributes (following compiler)
#include "arm_typedefs.h"		// Common typedefs
#include "arm_errors.h"			// Common errors
#include "arm_cmsis.h"			// HAL & Drivers (following defined platform)
/****************************************************************/
#include "xc.h"					// Microchip common

extern unsigned int HAL_GetTick(void);	//!< External definition of HAL_GetTick that shall be defined in project
/****************************************************************/


/*** Define Enable/Disable interrupts macros ***/
#undef diInterrupts
#define diInterrupts()		_GIE = 0;		//!< Disable interruptions macro
#undef enInterrupts
#define enInterrupts()		_GIE = 1;		//!< Enable interruptions macro

/*** MS Time base ***/
#ifndef HAL_MAX_TICKS
//!\note Define HAL_MAX_TICKS with custom max value in project if tick max value is not using unsigned int variable full scale
#define HAL_MAX_TICKS		((unsigned int) -1)		//!< Max Ticks value
#endif
#ifndef HAL_MS_TICKS_FACTOR
//!\note Define HAL_MS_TICKS_FACTOR with custom multiplier in project if tick period is not 1ms
#define HAL_MS_TICKS_FACTOR	1					//!< Milliseconds multiplier (depending tick counter frequency)
#endif

#ifndef HALTicks
#define HALTicks()			HAL_GetTick()			//!< Alias for Arduino get ms ticks function
#endif

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
__INLINE FctERR HALERRtoFCTERR(const SDWORD status)
{
	if (status == 0)	return ERROR_OK;
	else				return ERROR_COMMON;
}


#ifndef UNUSED
#define UNUSED(X)			(void) (X)			//!< To avoid gcc/g++ warnings
#endif


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_CHIP_PIC_H */
/****************************************************************/