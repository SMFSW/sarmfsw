/*!\file arm_chip_sam.h
** \author SMFSW
** \copyright MIT (c) 2017-2020, SMFSW
** \brief ARM common macros for Atmel SAM families
** \attention	On SAM families you should configure a timer to count for ms.
**				A TIM peripheral shall be configured in ATMEL START (with a period of 1ms).
**				Using driver examples from ATMEL START generated code,
**				you can add this code to your projects.
**
** \code
** static struct timer_task TIMER_0_task1;
** static volatile uint32_t uwTick = 0;
**
**
** uint32_t HAL_GetTick(void) {		// Declare HALTicks() at project level if you're using a different getter function name
** 	return uwTick; }
**
** static void TIMER_0_task1_cb(const struct timer_task *const timer_task) {
** 	uwTick++; }
**
** void TIMER_0_start(void)			// Adapt function if TIM configured is not TIMER_0
** {
** 	TIMER_0_task1.interval = 1;		// Adjust interval if TIM period is faster than 1ms (or define appropriate HAL_MS_TICKS_FACTOR)
** 	TIMER_0_task1.cb = TIMER_0_task1_cb;
** 	TIMER_0_task1.mode = TIMER_TASK_REPEAT;
**
** 	timer_add_task(&TIMER_0, &TIMER_0_task1);
** 	timer_start(&TIMER_0);
** }
** \endcode
**
** Please note TIMER_0_start() shall be called at init.
** Also, HAL_GetTick shall be known to sarmfsw.
** As atmel_start_pins.h is included by sarmfsw, you should add HAL_GetTick prototype in the file:
**
** \code
** #include <stdint.h>
** uint32_t HAL_GetTick(void);
** \endcode
*/
/****************************************************************/
#ifndef __ARM_CHIP_SAM_H
	#define __ARM_CHIP_SAM_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "arm_attributes.h"			// Common attributes (following compiler)
#include "arm_typedefs.h"			// Common typedefs
#include "arm_errors.h"				// Common errors
#include "arm_cmsis.h"				// HAL & Drivers (following defined platform)
/****************************************************************/
#include "atmel_start_pins.h"		// Project pins definitions
#include "err_codes.h"				// Atmel error codes
#include "hpl_reset.h"				// Atmel reset sources
/****************************************************************/


#define SAM_HEADER(f)		XCAT(<hri_, f).h>					//!< concatenate <hri_(f).h> name following sam family \b f
#define SAM_CONF_HEADER(f)	<sam.h>								//!< <sam.h> name following sam family \b f

#define ARM_CMSIS_INC		SAM_HEADER(SAM_FAMILY)				//!< Alias for SAM CMSIS include
#define ARM_HAL_CFG			SAM_CONF_HEADER(SAM_FAMILY)			//!< Alias for SAM HAL config include


/*** Flash size ***/
// FLASH_SIZE (in bytes) is already defined in controller header, thus not requiring to define it here

/*** MS Time base ***/
#ifndef HAL_MAX_TICKS
//!\note Define HAL_MAX_TICKS with custom max value in project if tick max value is not using 32b variable full scale
#define HAL_MAX_TICKS		((uint32_t) -1)		//!< HAL max Ticks value
#endif
#ifndef HAL_MS_TICKS_FACTOR
//!\note Define HAL_MS_TICKS_FACTOR with custom multiplier in project if tick period is not 1ms
#define HAL_MS_TICKS_FACTOR	1					//!< HAL milliseconds multiplier (depending tick counter frequency)
#endif

#ifndef HALTicks
//!\note Define HALTicks at project level to call your own ms tick getter function
#define HALTicks()			HAL_GetTick()		//!< Alias for HAL get ticks function
#endif


/*!\enum eResetSource
** \brief Source of last reset
**/
typedef enum eResetSource {
	RST_POR = RESET_REASON_POR,				//!< Power On Reset
	RST_BODCORE = RESET_REASON_BODCORE,		//!< Brown Out Reset
	RST_BODVDD = RESET_REASON_BODVDD,		//!
	RST_EXT = RESET_REASON_EXT,				//!< Pin Reset (External Reset)
	RST_WDT = RESET_REASON_WDT,				//!< Watchdog Reset
	RST_SYST = RESET_REASON_SYST,			//!< Software Reset
	RST_UNKNOWN = 0xFF						//!< Unknown Reset Source
} eResetSource;


/*** GLOBAL CMSIS & HAL includes ***/
#include ARM_CMSIS_INC	// CMSIS includes
// #include ARM_HAL_CFG	// HAL configuration includes (already included by ARM_CMSIS_INC)


/*!\brief Get and convert ATMEL Reset Source to eResetSource
** \warning This function should be called soon after reset
** \return Last reset source
**/
__INLINE eResetSource INLINE__ HAL_ResetSource(void) {
	return (eResetSource) _get_reset_reason(); }


/*!\brief Convert ATMEL error code to FctERR
** \param[in] status - ATMEL error code
** \return FctERR status
**/
__INLINE FctERR HALERRtoFCTERR(const SDWORD status)
{
	if		(status == ERR_NONE)									return ERROR_OK;
	else if (status == ERR_INVALID_DATA)							return ERROR_VALUE;
	else if ((status == ERR_BUSY) || (status == ERR_NOT_READY))		return ERROR_BUSY;
	else if (status == ERR_TIMEOUT)									return ERROR_TIMEOUT;
	else if (status == ERR_NO_MEMORY)								return ERROR_MEMORY;
	else if (status == ERR_BAD_FRQ)									return ERROR_SPEED;
	else if (status == ERR_DENIED)									return ERROR_PROTECT;
	else if (status == ERR_OVERFLOW)								return ERROR_OVERFLOW;
	else if (status == ERR_NOT_INITIALIZED)							return ERROR_NOTAVAIL;
	else if (status == ERR_PACKET_COLLISION)						return ERROR_ARBITR;
	else if (status == ERR_UNSUPPORTED_OP)							return ERROR_CMD;
	else 															return ERROR_COMMON;
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_CHIP_SAM_H */
/****************************************************************/
