/*!\file sarmfsw.h
** \author SMFSW
** \date 2017
** \copyright MIT (c) 2017, SMFSW
** \brief ARM common headers for projects
*/
/****************************************************************/
#ifndef __SARMFSW_H
	#define __SARMFSW_H
/****************************************************************/

#include "arm_attributes.h"		// Attributes depending compiler
#include "arm_typedefs.h"		// Common typedefs
#include "arm_macros.h"			// Common macros
#include "arm_stdclib.h"		// Common standard c library wrapper macros

#include "arm_cmsis.h"			// HAL & Drivers depending platform
#include "arm_hal_peripheral.h"	// HAL peripherals includes

#include "arm_errors.h"			// Common errors

#include "arm_inlines.h"		// Common inlines (at the end as some needs to access HAL)

/*!\enum FW_target
** \brief Firmware target types
**/
typedef enum PACK__ FW_target{
	DefSpecialTarget = 0,		//!< Special FW target (same as debug, yet)
	DefDebugTarget,				//!< Debug FW target (default)
	DefReleaseTarget,			//!< Release FW target (No debug information)
	DefFUBARTarget,				//!< FUBAR FW target (shall be used only for stress/testing purposes)
	DefUnknownTarget = 0xFF		//!< Unknown FW target (should never happen!)
} FW_target;


/****************************************************************/
#endif /* __SARMFSW_H */
/****************************************************************/
