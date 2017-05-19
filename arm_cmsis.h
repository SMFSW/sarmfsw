/*!\file arm_cmsis.h
** \author SMFSW
** \version v0.9
** \date 2017
** \copyright MIT (c) 2017, SMFSW
** \brief ARM link with CMSIS files
*/
/****************************************************************/
#ifndef __ARM_CMSIS_H
	#define __ARM_CMSIS_H
/****************************************************************/


#if !defined(STM_FAMILY)

#if		defined (STM32F030x6) || defined (STM32F030x8) || defined (STM32F031x6) || defined (STM32F038xx) || \
		defined (STM32F042x6) || defined (STM32F048xx) || defined (STM32F070x6) || defined (STM32F051x8) || \
		defined (STM32F058xx) || defined (STM32F071xB) || defined (STM32F072xB) || defined (STM32F078xx) || \
		defined (STM32F070xB) || defined (STM32F091xC) || defined (STM32F098xx) || defined (STM32F030xC)
	#define STM_FAMILY	f0
#elif	defined (STM32F100xB) || defined (STM32F100xE) || defined (STM32F101x6) || \
		defined (STM32F101xB) || defined (STM32F101xE) || defined (STM32F101xG) || \
		defined (STM32F102x6) || defined (STM32F102xB) || defined (STM32F103x6) || \
		defined (STM32F103xB) || defined (STM32F103xE) || defined (STM32F103xG) || \
		defined (STM32F105xC) || defined (STM32F107xC)
	#define STM_FAMILY	f1
#elif	defined (STM32F205xx) || defined (STM32F215xx) || defined (STM32F207xx) || defined (STM32F217xx)
	#define STM_FAMILY	f2
#elif	defined (STM32F301x8) || defined (STM32F302x8) || defined (STM32F318xx) || \
		defined (STM32F302xC) || defined (STM32F303xC) || defined (STM32F358xx) || \
		defined (STM32F303x8) || defined (STM32F334x8) || defined (STM32F328xx) || \
		defined (STM32F302xE) || defined (STM32F303xE) || defined (STM32F398xx) || \
		defined (STM32F373xC) || defined (STM32F378xx)
	#define STM_FAMILY	f3
#elif	defined (STM32F405xx) || defined (STM32F415xx) || defined (STM32F407xx) || defined (STM32F417xx) || \
		defined (STM32F427xx) || defined (STM32F437xx) || defined (STM32F429xx) || defined (STM32F439xx) || \
		defined (STM32F401xC) || defined (STM32F401xE) || defined (STM32F410Tx) || defined (STM32F410Cx) || \
		defined (STM32F410Rx) || defined (STM32F411xE) || defined (STM32F446xx) || defined (STM32F469xx) || \
		defined (STM32F479xx) || defined (STM32F412Cx) || defined (STM32F412Rx) || defined (STM32F412Vx) || \
		defined (STM32F412Zx) || defined (STM32F413xx) || defined (STM32F423xx)
	#define STM_FAMILY	f4
#elif	defined (STM32F756xx) || defined (STM32F746xx) || defined (STM32F745xx) || defined (STM32F767xx) || \
		defined (STM32F769xx) || defined (STM32F777xx) || defined (STM32F779xx) || defined (STM32F722xx) || \
		defined (STM32F723xx) || defined (STM32F732xx) || defined (STM32F733xx)
	#define STM_FAMILY	f7
#elif	defined (STM32L011xx) || defined (STM32L021xx) || defined (STM32L031xx) || defined (STM32L041xx) || \
		defined (STM32L051xx) || defined (STM32L052xx) || defined (STM32L053xx) || defined (STM32L061xx) || \
		defined (STM32L062xx) || defined (STM32L063xx) || defined (STM32L071xx) || defined (STM32L072xx) || \
		defined (STM32L073xx) || defined (STM32L081xx) || defined (STM32L082xx) || defined (STM32L083xx)
	#define STM_FAMILY	l0
#elif	defined (STM32L100xB) || defined (STM32L100xBA) || defined (STM32L100xC) || defined (STM32L151xB) || \
		defined (STM32L151xBA) || defined (STM32L151xC) || defined (STM32L151xCA) || defined (STM32L151xD) || \
		defined (STM32L151xDX) || defined (STM32L151xE) || defined (STM32L152xB) || defined (STM32L152xBA) || \
		defined (STM32L152xC) || defined (STM32L152xCA) || defined (STM32L152xD) || defined (STM32L152xDX) || \
		defined (STM32L152xE) || defined (STM32L162xC) || defined (STM32L162xCA) || defined (STM32L162xD) || \
		defined (STM32L162xDX) || defined (STM32L162xE)
	#define STM_FAMILY	l1
#elif	defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx) || defined (STM32L442xx) || \
		defined (STM32L443xx) || defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx) || \
		defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || \
		defined (STM32L486xx) || defined (STM32L496xx) || defined (STM32L4A6xx)
	#define STM_FAMILY	l4
#else
	#error "You should add the CMSIS base include following chip used & comment this error."
	#error "If working on STM32, and not in the list, try add STM_FAMILY=(f/l)x in project defines."
#endif
#endif


#if defined(STM_FAMILY)
	#include "arm_stm32.h"

	/*** GLOBAL ***/
	#define CMSIS_INC			STM32_INC						//!< Alias for CMSIS include
	#define CMSIS_CFG			STM32_CFG						//!< Alias for CMSIS config include
#else
	#error "You will have to define your own CMSIS_INC & CMSIS_CFG file names with <> around."
#endif


/****************************************************************/
#endif /* __ARM_CMSIS_H */
/****************************************************************/
