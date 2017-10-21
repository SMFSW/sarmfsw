/*!\file arm_chip_stm32.h
** \author SMFSW
** \date 2017
** \copyright MIT (c) 2017, SMFSW
** \brief ARM common macros for STM32
*/
/****************************************************************/
#ifndef __ARM_CHIP_STM32_H
	#define __ARM_CHIP_STM32_H
/****************************************************************/


#define STM_HEADER(f)		XCAT(<stm32, XCAT(f, xx.h>))		//!< concatenate <stm32(f)xx.h> name following stm family \b f
#define STM_CONF_HEADER(f)	XCAT(<stm32, XCAT(f, xx_hal.h>))	//!< concatenate <stm32(f)xx_hal.h> name following stm family \b f

#define ARM_CMSIS_INC		STM_HEADER(STM_FAMILY)				//!< Alias for STM32 CMSIS include
#define ARM_HAL_CFG			STM_CONF_HEADER(STM_FAMILY)			//!< Alias for STM32 HAL config include


/*** GPIO name wrapper (from CubeMX pin names) ***/
#define	port(mnem)			XCAT(mnem, _GPIO_Port)				//!< Wrapper for PORT Alias
#define	pin(mnem)			XCAT(mnem, _Pin)					//!< Wrapper for PIN Alias
#define	gpio(mnem)			port(mnem), pin(mnem)				//!< Wrapper for PORT/PIN Alias (when using HAL_GPIO_ReadPin for example)

/*** TIM PWM name wrapper ***/
#define	tim(mnem)			XCAT(mnem, _Tim)					//!< Wrapper for TIM Alias
#define	chan(mnem)			XCAT(mnem, _Chan)					//!< Wrapper for TIM Channel Alias
#define	pwm(mnem)			tim(mnem), chan(mnem)				//!< Wrapper for TIM/CHAN Alias (when using HAL_TIM_PWM_Start for example)
//!\note You would have to define mnemonic _Tim/_Chan corresponding to what's defined in CubeMX as Port/Pin (for consistency)


/****************************************************************/
#endif /* __ARM_CHIP_STM32_H */
/****************************************************************/
