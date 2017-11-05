/*!\file arm_chip_sam.h
** \author SMFSW
** \date 2017
** \copyright MIT (c) 2017, SMFSW
** \brief ARM common macros for Atmel SAM families
*/
/****************************************************************/
#ifndef __ARM_CHIP_SAM_H
	#define __ARM_CHIP_SAM_H

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


#define SAM_HEADER(f)		XCAT(<hri_, f).h>					//!< concatenate <hri_(f).h> name following sam family \b f
#define SAM_CONF_HEADER(f)	<sam.h>								//!< <sam.h> name following sam family \b f

#define ARM_CMSIS_INC		SAM_HEADER(SAM_FAMILY)				//!< Alias for SAM CMSIS include
#define ARM_HAL_CFG			SAM_CONF_HEADER(SAM_FAMILY)			//!< Alias for SAM HAL config include


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_CHIP_SAM_H */
/****************************************************************/
