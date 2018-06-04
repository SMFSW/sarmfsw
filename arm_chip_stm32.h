/*!\file arm_chip_stm32.h
** \author SMFSW
** \copyright MIT (c) 2017-2018, SMFSW
** \brief ARM common macros for STM32
*/
/****************************************************************/
#ifndef __ARM_CHIP_STM32_H
	#define __ARM_CHIP_STM32_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "arm_attributes.h"		// Common attributes (following compiler)
#include "arm_typedefs.h"		// Common typedefs
#include "arm_errors.h"			// Common errors
#include "arm_cmsis.h"			// HAL & Drivers (following defined platform)
/****************************************************************/
#include "main.h"				// Project pins & constants definitions
/****************************************************************/


#define STM_HEADER(f)		XCAT(<stm32, XCAT(f, xx.h>))		//!< concatenate <stm32(f)xx.h> name following stm family \b f
#define STM_CONF_HEADER(f)	XCAT(<stm32, XCAT(f, xx_hal.h>))	//!< concatenate <stm32(f)xx_hal.h> name following stm family \b f

#define ARM_CMSIS_INC		STM_HEADER(STM_FAMILY)				//!< Alias for STM32 CMSIS include
#define ARM_HAL_CFG			STM_CONF_HEADER(STM_FAMILY)			//!< Alias for STM32 HAL config include


/*** GPIO pin name wrapper (from CubeMX pin names) ***/
#define	port(mnem)			XCAT(mnem, _GPIO_Port)				//!< Wrapper for PORT Alias
#define	pin(mnem)			XCAT(mnem, _Pin)					//!< Wrapper for PIN Alias
#define	GPIO(mnem)			port(mnem), pin(mnem)				//!< Wrapper for PORT/PIN Alias (when using HAL_GPIO_ReadPin for example)

/*** TIM Channel name wrapper ***/
#define	timer(mnem)			XCAT(mnem, _Tim)					//!< Wrapper for TIM Alias
#define	channel(mnem)		XCAT(mnem, _Chan)					//!< Wrapper for TIM Channel Alias
//!\note You would have to define mnemonic _Tim/_Chan corresponding to what's defined in CubeMX as Port/Pin (for consistency)
#define	TIM(mnem)			timer(mnem), channel(mnem)			//!< Wrapper for TIM/CHAN Alias (when using HAL_TIM_PWM_Start for example)


/*** MS Time base ***/
#ifndef HAL_MAX_TICKS
//!\note Define HAL_MAX_TICKS with custom max value in project if tick max value is not using 32b variable full scale
#define HAL_MAX_TICKS		((uint32_t) -1)		//!< HAL max Ticks value
#endif
#ifndef HAL_MS_TICKS_FACTOR
//!\note Define HAL_MS_TICKS_FACTOR with custom multiplier in project if tick period is not 1ms
#define HAL_MS_TICKS_FACTOR	1					//!< HAL milliseconds multiplier (depending tick counter frequency)
#endif

#define HALTicks()			HAL_GetTick()		//!< Alias for HAL get ticks function


/*!\enum eResetSource
** \brief Source of last reset
**/
typedef enum eResetSource {
	RST_POR = 1,		//!< Power On Reset
	RST_PIN,			//!< Pin Reset (External Reset)
	RST_SW,				//!< Software Reset
	RST_IWDG,			//!< Independent Watchdog Reset
	RST_WWDG,			//!< Window Watchdog Reset
	RST_LPWR,			//!< Low Power Reset
	RST_OBL,			//!< Option Byte Load Reset (F3)
	RST_V18PWR,			//!< 1.8V Domain Power Reset (F3)
	RST_UNKNOWN = 0xFF	//!< Unknown Reset Source
} eResetSource;


/*** GLOBAL CMSIS & HAL includes ***/
#include ARM_CMSIS_INC	// CMSIS includes
// #include ARM_HAL_CFG	// HAL configuration includes (already included by ARM_CMSIS_INC)


/*!\brief Get STM32 Reset Source
** \warning This function should be called soon after reset (before or after SystemClock_Config())
** \note This function using some special macros can't be inlined, thus can't be in sarmfsw stm32 header unfortunately
** \return Last reset source
**/
#define HAL_ResetSource()	Get_Reset_Source()	//!< Alias for HARMcksL Get_Reset_Source function


/*!\brief Convert HAL_StatusTypeDef to FctERR
** \param[in] status - HAL_StatusTypeDef status
** \return FctERR status
**/
__INLINE FctERR HALERRtoFCTERR(HAL_StatusTypeDef status)
{
	if		(status == HAL_OK)			return ERROR_OK;
	else if (status == HAL_ERROR)		return ERROR_FAULT;
	else if (status == HAL_BUSY)		return ERROR_BUSY;
	else if (status == HAL_TIMEOUT)		return ERROR_TIMEOUT;
	else 								return ERROR_COMMON;
}


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_CHIP_STM32_H */
/****************************************************************/
