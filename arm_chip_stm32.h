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


#define	port(mnem)			XCAT(mnem, _GPIO_Port)				//!< Wrapper for PORT Alias
#define	pin(mnem)			XCAT(mnem, _Pin)					//!< Wrapper for PIN Alias
#define	gpio(mnem)			port(mnem), pin(mnem)				//!< Wrapper for PORT/PIN Alias (when using HAL_GPIO_ReadPin for example)


/****************************************************************/
#endif /* __ARM_CHIP_STM32_H */
/****************************************************************/
