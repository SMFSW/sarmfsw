/*!\file arm_hal_peripheral.h
** \warning for STM32, HAL shall be configured to generate as pairs of h/c files
** \author SMFSW
** \copyright MIT (c) 2017-2022, SMFSW
** \brief ARM HAL peripheral includes
*/
/****************************************************************/
#ifndef __ARM_HAL_PERIPHERAL_H
	#define __ARM_HAL_PERIPHERAL_H

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


#if defined(STM_FAMILY)

	#if defined(HAL_MODULE_ENABLED)
		/***********************/
		/*** HAL PERIPHERALS ***/
		/***********************/
		#ifdef HAL_ADC_MODULE_ENABLED
			#include "adc.h"
		#endif /* HAL_ADC_MODULE_ENABLED */

		#ifdef HAL_CAN_MODULE_ENABLED
			#include "can.h"
		#endif /* HAL_CAN_MODULE_ENABLED */

		#ifdef HAL_CEC_MODULE_ENABLED
			#include "cec.h"
		#endif /* HAL_CEC_MODULE_ENABLED */

		#ifdef HAL_COMP_MODULE_ENABLED
			#include "comp.h"
		#endif /* HAL_COMP_MODULE_ENABLED */

		#ifdef HAL_CRC_MODULE_ENABLED
			#include "crc.h"
		#endif /* HAL_CRC_MODULE_ENABLED */

		#ifdef HAL_CRYP_MODULE_ENABLED
			#include "cryp.h"
		#endif /* HAL_CRYP_MODULE_ENABLED */

		#ifdef HAL_DAC_MODULE_ENABLED
			#include "dac.h"
		#endif /* HAL_DAC_MODULE_ENABLED */

		#ifdef HAL_DCMI_MODULE_ENABLED
			#include "dcmi.h"
		#endif /* HAL_DCMI_MODULE_ENABLED */

	//	#ifdef HAL_DMA_MODULE_ENABLED
	//		#include "dma.h"
	//	#endif /* HAL_DMA_MODULE_ENABLED */

	//	#ifdef HAL_DMA2D_MODULE_ENABLED
	//		#include "dma2d.h"
	//	#endif /* HAL_DMA2D_MODULE_ENABLED */

	//	#ifdef HAL_ETH_MODULE_ENABLED
	//		#include "eth.h"
	//	#endif /* HAL_ETH_MODULE_ENABLED */

		#ifdef HAL_FDCAN_MODULE_ENABLED
			#include "fdcan.h"
		#endif /* HAL_FDCAN_MODULE_ENABLED */

		#ifdef HAL_GPIO_MODULE_ENABLED
			#include "gpio.h"
		#endif /* HAL_GPIO_MODULE_ENABLED */

		#ifdef HAL_HASH_MODULE_ENABLED
			#include "hash.h"
		#endif /* HAL_HASH_MODULE_ENABLED */

	//	#ifdef HAL_HCD_MODULE_ENABLED
	//		#include "hcd.h"
	//	#endif /* HAL_HCD_MODULE_ENABLED */

		#ifdef HAL_HRTIM_MODULE_ENABLED
			#include "hrtim.h"
		#endif /* HAL_HRTIM_MODULE_ENABLED */

		#ifdef HAL_HSEM_MODULE_ENABLED
			#include "hsem.h"
		#endif /* HAL_HSEM_MODULE_ENABLED */

		#ifdef HAL_I2C_MODULE_ENABLED
			#include "i2c.h"
		#endif /* HAL_I2C_MODULE_ENABLED */

		#ifdef HAL_IRDA_MODULE_ENABLED
			#include "irda.h"
		#endif /* HAL_IRDA_MODULE_ENABLED */

		#ifdef HAL_I2S_MODULE_ENABLED
			#include "i2s.h"
		#endif /* HAL_I2S_MODULE_ENABLED */

		#ifdef HAL_IWDG_MODULE_ENABLED
			#include "iwdg.h"
		#endif /* HAL_IWDG_MODULE_ENABLED */

		#ifdef HAL_JPEG_MODULE_ENABLED
			#include "libjpeg.h"
			#include "jconfig.h"
			#include "jmorecfg.h"
		#endif /* HAL_JPEG_MODULE_ENABLED */

		#ifdef HAL_LPTIM_MODULE_ENABLED
			#include "lptim.h"
		#endif /* HAL_LPTIM_MODULE_ENABLED */

		#ifdef HAL_LTDC_MODULE_ENABLED
			#include "ltdc.h"
		#endif /* HAL_LTDC_MODULE_ENABLED */

		#ifdef HAL_MDIOS_MODULE_ENABLED
			#include "mdios.h"
		#endif /* HAL_MDIOS_MODULE_ENABLED */

		#ifdef HAL_MDMA_MODULE_ENABLED
			#include "mdma.h"
		#endif /* HAL_MDMA_MODULE_ENABLED */

		#ifdef HAL_NAND_MODULE_ENABLED
			#include "nand.h"
		#endif /* HAL_NAND_MODULE_ENABLED */

		#ifdef HAL_NOR_MODULE_ENABLED
			#include "nor.h"
		#endif /* HAL_NOR_MODULE_ENABLED */

		#ifdef HAL_OPAMP_MODULE_ENABLED
			#include "opamp.h"
		#endif /* HAL_OPAMP_MODULE_ENABLED */

		#ifdef HAL_PCCARD_MODULE_ENABLED
			#include "pccard.h"
		#endif /* HAL_PCCARD_MODULE_ENABLED */

		#ifdef HAL_PCD_MODULE_ENABLED
			#include "usb_device.h"
		#endif /* HAL_PCD_MODULE_ENABLED */

		#ifdef HAL_QSPI_MODULE_ENABLED
			#include "quadspi.h"
		#endif /* HAL_QSPI_MODULE_ENABLED */

		#ifdef HAL_RNG_MODULE_ENABLED
			#include "rng.h"
		#endif /* HAL_RNG_MODULE_ENABLED */

		#ifdef HAL_RTC_MODULE_ENABLED
			#include "rtc.h"
		#endif /* HAL_RTC_MODULE_ENABLED */

		#ifdef HAL_SAI_MODULE_ENABLED
			#include "sai.h"
		#endif /* HAL_SAI_MODULE_ENABLED */

		#ifdef HAL_SD_MODULE_ENABLED
			#include "sd.h"
		#endif /* HAL_SD_MODULE_ENABLED */

		#ifdef HAL_SDADC_MODULE_ENABLED
			#include "sdadc.h"
		#endif /* HAL_SDADC_MODULE_ENABLED */

		#ifdef HAL_SPDIFRX_MODULE_ENABLED
			#include "spdifrx.h"
		#endif /* HAL_SPDIFRX_MODULE_ENABLED */

		#ifdef HAL_SMARTCARD_MODULE_ENABLED
			#include "smartcard.h"
		#endif /* HAL_SMARTCARD_MODULE_ENABLED */

		#ifdef HAL_SMBUS_MODULE_ENABLED
			#include "smbus.h"
		#endif /* HAL_SMBUS_MODULE_ENABLED */

		#ifdef HAL_SPI_MODULE_ENABLED
			#include "spi.h"
		#endif /* HAL_SPI_MODULE_ENABLED */

		#ifdef HAL_SRAM_MODULE_ENABLED
			#include "sram.h"
		#endif /* HAL_SRAM_MODULE_ENABLED */

		#ifdef HAL_SWPMI_MODULE_ENABLED
			#include "swpmi.h"
		#endif /* HAL_SWPMI_MODULE_ENABLED */

		#ifdef HAL_TIM_MODULE_ENABLED
			#include "tim.h"
		#endif /* HAL_TIM_MODULE_ENABLED */

		#ifdef HAL_TSC_MODULE_ENABLED
			#include "tsc.h"
		#endif /* HAL_TSC_MODULE_ENABLED */

		#ifdef HAL_UART_MODULE_ENABLED
			#include "usart.h"
		#endif /* HAL_UART_MODULE_ENABLED */

		#ifdef HAL_USART_MODULE_ENABLED
			#include "usart.h"
		#endif /* HAL_USART_MODULE_ENABLED */

		#ifdef HAL_WWDG_MODULE_ENABLED
			#include "wwdg.h"
		#endif /* HAL_WWDG_MODULE_ENABLED */

	#endif

#elif defined(SAM_FAMILY)

	// SAM families HAL config includes already included by CMSIS include

#endif


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_HAL_PERIPHERAL_H */
/****************************************************************/
