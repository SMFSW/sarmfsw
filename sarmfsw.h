/*!\file sarmfsw.h
** \author SMFSW
** \copyright MIT (c) 2017-2025, SMFSW
** \brief sarmfsw (ARM) common headers
*/
/****************************************************************/
#ifndef SARMFSW_H_
	#define SARMFSW_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/

#include "arm_preprocess.h"		// Common pre-processing directives
#include "arm_attributes.h"		// Common attributes (following compiler)

#include "arm_errors.h"			// Common errors
#include "arm_typedefs.h"		// Common typedefs

#include "arm_cmsis.h"			// HAL & Drivers (following defined platform)
#include "arm_hal_peripheral.h"	// HAL peripherals includes (following defined platform)

#include "arm_keywords.h"		// Common C keywords aliases
#include "arm_macros.h"			// Common macros
#include "arm_inlines.h"		// Common inlines (after all includes, some inlines needs to access HAL code)

/*!\enum _FW_target
** \brief Firmware target types
** \note A variable has to be defined in project using FW_target enum to be meaningful
**/
typedef enum PACK__ _FW_target {
	target_Special = 0,		//!< Special FW target
	target_Debug,			//!< Debug FW target
	target_Release,			//!< Release FW target (No debug information)
	target_FUBAR,			//!< FUBAR FW target (shall be used only for stress test / optimization testing purposes)
	target_Unknown = 0xFF	//!< Unknown FW target
} FW_target;


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* SARMFSW_H_ */
/****************************************************************/
