/*!\file arm_chip_pic.h
** \author SMFSW
** \copyright MIT (c) 2017-2024, SMFSW
** \brief Common macros for PIC
** \warning Do not use macros for function qualifiers in this file
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
** \MISRA header deviation has been granted for following rules:\n
** 		\b Rule-20.5 - \b Advisory: #undef (misra-c2012-20.5)\n
*/
/****************************************************************/
#ifndef ARM_CHIP_PIC_H_
	#define ARM_CHIP_PIC_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/
#include "xc.h"					// Microchip common & MCU dependent definitions
/****************************************************************/


/*** Define Enable/Disable interrupts macros ***/
#undef diInterrupts		// cppcheck-suppress misra-c2012-20.5
#undef enInterrupts		// cppcheck-suppress misra-c2012-20.5
#if defined(__XC8)
	#define diInterrupts()		di()							//!< Disable interruptions macro
	#define enInterrupts()		en()							//!< Enable interruptions macro
#else	// builtins should be defined for __XC16 & __XC32
	#define diInterrupts()		__builtin_disable_interrupts()	//!< Disable interruptions macro
	#define enInterrupts()		__builtin_enable_interrupts()	//!< Enable interruptions macro
#endif


/*** MS Time base ***/
#ifndef HAL_MAX_TICKS
//!\note Define HAL_MAX_TICKS with custom max value in project if tick max value is not using 32b variable full scale
#define HAL_MAX_TICKS		((uint32_t) -1)		//!< Max Ticks value
#endif
#ifndef HAL_MS_TICKS_FACTOR
//!\note Define HAL_MS_TICKS_FACTOR with custom multiplier in project if tick period is not 1ms
#define HAL_MS_TICKS_FACTOR	1					//!< Milliseconds multiplier (depending tick counter frequency)
#endif

#ifndef HALTicks
// Use common definition of HALTicks in arm_cmsis.h
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
static inline eResetSource HAL_ResetSource(void) {
	return RST_UNKNOWN; }


/*!\brief Convert Arduino error code to FctERR
** \param[in] status - Arduino error code
** \return FctERR status
**/
static inline FctERR HALERRtoFCTERR(const SDWORD status)
{
	if (status == 0)	return ERROR_OK;
	else				return ERROR_COMMON;
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_CHIP_PIC_H_ */
/****************************************************************/
