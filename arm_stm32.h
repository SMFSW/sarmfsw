/*!\file arm_stm32.h
** \author SMFSW
** \date 2017
** \copyright MIT (c) 2017, SMFSW
** \brief ARM common macros for STM32
*/
/****************************************************************/
#ifndef __ARM_STM32_H
	#define __ARM_STM32_H
/****************************************************************/


#define	port(mnem)			XCAT(mnem, _GPIO_Port)				//!< Wrapper for PORT Alias
#define	pin(mnem)			XCAT(mnem, _Pin)					//!< Wrapper for PIN Alias
#define	gpio(mnem)			port(mnem), pin(mnem)				//!< Wrapper for PORT/PIN Alias (when using HAL_GPIO_ReadPin for example)


#define STM_HEADER(f)		XCAT(<stm32, XCAT(f, xx.h>))		//!< concatenate <stm32(f)xx.h> name following stm family \b f
#define STM_CONF_HEADER(f)	XCAT(<stm32, XCAT(f, xx_hal.h>))	//!< concatenate <stm32(f)xx_hal.h> name following stm family \b f

#define STM32_INC			STM_HEADER(STM_FAMILY)				//!< Alias for STM32 include
#define STM32_CFG			STM_CONF_HEADER(STM_FAMILY)			//!< Alias for STM32 include


/****************************************************************/
#endif /* __ARM_STM32_H */
/****************************************************************/
