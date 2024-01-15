/*!\file arm_hal_peripheral.h
** \warning for STM32, HAL shall be configured to generate as pairs of h/c files
** \author SMFSW
** \copyright MIT (c) 2017-2024, SMFSW
** \brief ARM HAL peripheral includes
*/
/****************************************************************/
#ifndef __ARM_HAL_PERIPHERAL_H
	#define __ARM_HAL_PERIPHERAL_H

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/

#if !defined(HAL_INC_DISABLE)

	#if defined(STM_FAMILY)

		#if defined(HAL_MODULE_ENABLED)
			/***********************/
			/*** HAL PERIPHERALS ***/
			/***********************/
			#if defined(HAL_ADC_MODULE_ENABLED) && !defined(HAL_ADC_INC_DISABLE)
				#include "adc.h"
			#endif /* HAL_ADC_MODULE_ENABLED */

			#if defined(HAL_CAN_MODULE_ENABLED) && !defined(HAL_CAN_INC_DISABLE)
				#include "can.h"
			#endif /* HAL_CAN_MODULE_ENABLED */

			#if defined(HAL_CEC_MODULE_ENABLED) && !defined(HAL_CEC_INC_DISABLE)
				#include "cec.h"
			#endif /* HAL_CEC_MODULE_ENABLED */

			#if defined(HAL_COMP_MODULE_ENABLED) && !defined(HAL_COMP_INC_DISABLE)
				#include "comp.h"
			#endif /* HAL_COMP_MODULE_ENABLED */

			#if defined(HAL_CRC_MODULE_ENABLED) && !defined(HAL_CRC_INC_DISABLE)
				#include "crc.h"
			#endif /* HAL_CRC_MODULE_ENABLED */

			#if defined(HAL_CRYP_MODULE_ENABLED) && !defined(HAL_CRYP_INC_DISABLE)
				#include "cryp.h"
			#endif /* HAL_CRYP_MODULE_ENABLED */

			#if defined(HAL_DAC_MODULE_ENABLED) && !defined(HAL_DAC_INC_DISABLE)
				#include "dac.h"
			#endif /* HAL_DAC_MODULE_ENABLED */

			#if defined(HAL_DCMI_MODULE_ENABLED) && !defined(HAL_DCMI_INC_DISABLE)
				#include "dcmi.h"
			#endif /* HAL_DCMI_MODULE_ENABLED */

//			#if defined(HAL_DMA_MODULE_ENABLED) && !defined(HAL_DMA_INC_DISABLE)
//				#include "dma.h"	// No header generated
//			#endif /* HAL_DMA_MODULE_ENABLED */

//			#if defined(HAL_DMA2D_MODULE_ENABLED) && !defined(HAL_DMA2D_INC_DISABLE)
//				#include "dma2d.h"	// No header generated
//			#endif /* HAL_DMA2D_MODULE_ENABLED */

//			#if defined(HAL_ETH_MODULE_ENABLED) && !defined(HAL_ETH_INC_DISABLE)
//				#include "eth.h"	// No header generated
//			#endif /* HAL_ETH_MODULE_ENABLED */

			#if defined(HAL_FDCAN_MODULE_ENABLED) && !defined(HAL_FDCAN_INC_DISABLE)
				#include "fdcan.h"
			#endif /* HAL_FDCAN_MODULE_ENABLED */

			#if defined(HAL_GPIO_MODULE_ENABLED) && !defined(HAL_GPIO_INC_DISABLE)
				#include "gpio.h"
			#endif /* HAL_GPIO_MODULE_ENABLED */

			#if defined(HAL_HASH_MODULE_ENABLED) && !defined(HAL_HASH_INC_DISABLE)
				#include "hash.h"
			#endif /* HAL_HASH_MODULE_ENABLED */

//			#if defined(HAL_HCD_MODULE_ENABLED) && !defined(HAL_HCD_INC_DISABLE)
//				#include "hcd.h"	// No header generated
//			#endif /* HAL_HCD_MODULE_ENABLED */

			#if defined(HAL_HRTIM_MODULE_ENABLED) && !defined(HAL_HRTIM_INC_DISABLE)
				#include "hrtim.h"
			#endif /* HAL_HRTIM_MODULE_ENABLED */

//			#if defined(HAL_HSEM_MODULE_ENABLED) && !defined(HAL_HSEM_INC_DISABLE)
//				#include "hsem.h"	// No header generated
//			#endif /* HAL_HSEM_MODULE_ENABLED */

			#if defined(HAL_I2C_MODULE_ENABLED) && !defined(HAL_I2C_INC_DISABLE)
				#include "i2c.h"
			#endif /* HAL_I2C_MODULE_ENABLED */

			#if defined(HAL_IRDA_MODULE_ENABLED) && !defined(HAL_IRDA_INC_DISABLE)
				#include "irda.h"
			#endif /* HAL_IRDA_MODULE_ENABLED */

			#if defined(HAL_I2S_MODULE_ENABLED) && !defined(HAL_I2S_INC_DISABLE)
				#include "i2s.h"
			#endif /* HAL_I2S_MODULE_ENABLED */

			#if defined(HAL_IWDG_MODULE_ENABLED) && !defined(HAL_IWDG_INC_DISABLE)
				#include "iwdg.h"
			#endif /* HAL_IWDG_MODULE_ENABLED */

			#if defined(HAL_JPEG_MODULE_ENABLED) && !defined(HAL_JPEG_INC_DISABLE)
				#include "libjpeg.h"
				#include "jconfig.h"
				#include "jmorecfg.h"
			#endif /* HAL_JPEG_MODULE_ENABLED */

			#if defined(HAL_LPTIM_MODULE_ENABLED) && !defined(HAL_LPTIM_INC_DISABLE)
				#include "lptim.h"
			#endif /* HAL_LPTIM_MODULE_ENABLED */

			#if defined(HAL_LTDC_MODULE_ENABLED) && !defined(HAL_LTDC_INC_DISABLE)
				#include "ltdc.h"
			#endif /* HAL_LTDC_MODULE_ENABLED */

			#if defined(HAL_MDIOS_MODULE_ENABLED) && !defined(HAL_MDIOS_INC_DISABLE)
				#include "mdios.h"
			#endif /* HAL_MDIOS_MODULE_ENABLED */

//			#if defined(HAL_MDMA_MODULE_ENABLED) && !defined(HAL_MDMA_INC_DISABLE)
//				#include "mdma.h"	// No header generated
//			#endif /* HAL_MDMA_MODULE_ENABLED */

			#if defined(HAL_NAND_MODULE_ENABLED) && !defined(HAL_NAND_INC_DISABLE)
				#include "nand.h"
			#endif /* HAL_NAND_MODULE_ENABLED */

			#if defined(HAL_NOR_MODULE_ENABLED) && !defined(HAL_NOR_INC_DISABLE)
				#include "nor.h"
			#endif /* HAL_NOR_MODULE_ENABLED */

			#if defined(HAL_OPAMP_MODULE_ENABLED) && !defined(HAL_OPAMP_INC_DISABLE)
				#include "opamp.h"
			#endif /* HAL_OPAMP_MODULE_ENABLED */

			#if defined(HAL_PCCARD_MODULE_ENABLED) && !defined(HAL_PCCARD_INC_DISABLE)
				#include "pccard.h"
			#endif /* HAL_PCCARD_MODULE_ENABLED */

			#if defined(HAL_PCD_MODULE_ENABLED) && !defined(HAL_PCD_INC_DISABLE)
				#include "usb_device.h"
			#endif /* HAL_PCD_MODULE_ENABLED */

			#if defined(HAL_QSPI_MODULE_ENABLED) && !defined(HAL_QSPI_INC_DISABLE)
				#include "quadspi.h"
			#endif /* HAL_QSPI_MODULE_ENABLED */

			#if defined(HAL_RNG_MODULE_ENABLED) && !defined(HAL_RNG_INC_DISABLE)
				#include "rng.h"
			#endif /* HAL_RNG_MODULE_ENABLED */

			#if defined(HAL_RTC_MODULE_ENABLED) && !defined(HAL_RTC_INC_DISABLE)
				#include "rtc.h"
			#endif /* HAL_RTC_MODULE_ENABLED */

			#if defined(HAL_SAI_MODULE_ENABLED) && !defined(HAL_SAI_INC_DISABLE)
				#include "sai.h"
			#endif /* HAL_SAI_MODULE_ENABLED */

			#if defined(HAL_SD_MODULE_ENABLED) && !defined(HAL_SD_INC_DISABLE)
				#include "sd.h"
			#endif /* HAL_SD_MODULE_ENABLED */

			#if defined(HAL_SDADC_MODULE_ENABLED) && !defined(HAL_SDADC_INC_DISABLE)
				#include "sdadc.h"
			#endif /* HAL_SDADC_MODULE_ENABLED */

			#if defined(HAL_SPDIFRX_MODULE_ENABLED) && !defined(HAL_SPDIFRX_INC_DISABLE)
				#include "spdifrx.h"
			#endif /* HAL_SPDIFRX_MODULE_ENABLED */

			#if defined(HAL_SMARTCARD_MODULE_ENABLED) && !defined(HAL_SMARTCARD_INC_DISABLE)
				#include "smartcard.h"
			#endif /* HAL_SMARTCARD_MODULE_ENABLED */

			#if defined(HAL_SMBUS_MODULE_ENABLED) && !defined(HAL_SMBUS_INC_DISABLE)
				#include "smbus.h"
			#endif /* HAL_SMBUS_MODULE_ENABLED */

			#if defined(HAL_SPI_MODULE_ENABLED) && !defined(HAL_SPI_INC_DISABLE)
				#include "spi.h"
			#endif /* HAL_SPI_MODULE_ENABLED */

			#if defined(HAL_SRAM_MODULE_ENABLED) && !defined(HAL_SRAM_INC_DISABLE)
				#include "sram.h"
			#endif /* HAL_SRAM_MODULE_ENABLED */

			#if defined(HAL_SWPMI_MODULE_ENABLED) && !defined(HAL_SWPMI_INC_DISABLE)
				#include "swpmi.h"
			#endif /* HAL_SWPMI_MODULE_ENABLED */

			#if defined(HAL_TIM_MODULE_ENABLED) && !defined(HAL_TIM_INC_DISABLE)
				#include "tim.h"
			#endif /* HAL_TIM_MODULE_ENABLED */

			#if defined(HAL_TSC_MODULE_ENABLED) && !defined(HAL_TSC_INC_DISABLE)
				#include "tsc.h"
			#endif /* HAL_TSC_MODULE_ENABLED */

			#if defined(HAL_UART_MODULE_ENABLED) && !defined(HAL_UART_INC_DISABLE)
				#include "usart.h"
			#endif /* HAL_UART_MODULE_ENABLED */

			#if defined(HAL_USART_MODULE_ENABLED) && !defined(HAL_USART_INC_DISABLE)
				#include "usart.h"
			#endif /* HAL_USART_MODULE_ENABLED */

			#if defined(HAL_WWDG_MODULE_ENABLED) && !defined(HAL_WWDG_INC_DISABLE)
				#include "wwdg.h"
			#endif /* HAL_WWDG_MODULE_ENABLED */

		#endif

	#elif defined(SAM_FAMILY)

		// SAM families HAL config includes already included by CMSIS include

	#endif

#endif

/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_HAL_PERIPHERAL_H */
/****************************************************************/
