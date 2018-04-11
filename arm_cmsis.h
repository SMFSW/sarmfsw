/*!\file arm_cmsis.h
** \author SMFSW
** \copyright MIT (c) 2017-2018, SMFSW
** \brief ARM link with CMSIS files
** \warning Latest ARM chips might now be recognized; if not, define at project level:
** 			- for STM32 families (STMicroelectronics):
** 				- STM_FAMILY xy:
** 					- x : f/l/h
** 					- y : sub-family number
** 			- for SAM families (Atmel):
** 				- SAM_FAMILY xy(yy)
** 			- for Other families (TI...):
** 				- not implemented yet
*/
/****************************************************************/
#ifndef __ARM_CMSIS_H
	#define __ARM_CMSIS_H

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


#define diInterrupts()		__disable_irq()		//!< Disable interruptions macro
#define enInterrupts()		__enable_irq()		//!< Enable interruptions macro


/************************/
/*** Arduino platform ***/
/************************/
#if defined (ARDUINO)
	#define ARDUINO_PLATFORM		//!< Arduino platform generic define
	#if !defined(INO_FAMILY)
		#define INO_FAMILY	arduino	//!< Arduion family for name catenation?
	#endif

/******************************/
/*** STMicro STM32 Families ***/
/******************************/
#elif	defined(STM32F030x6) || defined(STM32F030x8) ||													\
		defined(STM32F031x6) || defined(STM32F038xx) ||													\
		defined(STM32F042x6) || defined(STM32F048xx) || defined(STM32F070x6) ||							\
		defined(STM32F051x8) || defined(STM32F058xx) ||													\
		defined(STM32F071xB) || defined(STM32F072xB) || defined(STM32F078xx) || defined(STM32F070xB) ||	\
		defined(STM32F091xC) || defined(STM32F098xx) || defined(STM32F030xC)
	#define STM32F0					//!< STM32F0 family generic define
	#if !defined(STM_FAMILY)
		#define STM_FAMILY	f0		//!< STM32 family (f0) for name catenation
	#endif
#elif	defined(STM32F100xB) || defined(STM32F100xE) || defined(STM32F101x6) ||																			\
		defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6) ||	\
		defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
	#define STM32F1					//!< STM32F1 family generic define
	#if !defined(STM_FAMILY)
		#define STM_FAMILY	f1		//!< STM32 family (f1) for name catenation
	#endif
#elif	defined(STM32F205xx) || defined(STM32F215xx) || defined(STM32F207xx) || defined(STM32F217xx)
	#define STM32F2					//!< STM32F2 family generic define
	#if !defined(STM_FAMILY)
		#define STM_FAMILY	f2		//!< STM32 family (f2) for name catenation
	#endif
#elif	defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx) ||	\
		defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) ||	\
		defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx) ||	\
		defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx) ||	\
		defined(STM32F373xC) || defined(STM32F378xx)
	#define STM32F3					//!< STM32F3 family generic define
	#if !defined(STM_FAMILY)
		#define STM_FAMILY	f3		//!< STM32 family (f3) for name catenation
	#endif
#elif	defined(STM32F405xx) || defined(STM32F415xx) || defined(STM32F407xx) || defined(STM32F417xx) ||	\
		defined(STM32F427xx) || defined(STM32F437xx) || defined(STM32F429xx) || defined(STM32F439xx) ||	\
		defined(STM32F401xC) || defined(STM32F401xE) || defined(STM32F410Tx) || defined(STM32F410Cx) ||	\
		defined(STM32F410Rx) || defined(STM32F411xE) || defined(STM32F446xx) || defined(STM32F469xx) ||	\
		defined(STM32F479xx) || defined(STM32F412Cx) || defined(STM32F412Rx) || defined(STM32F412Vx) ||	\
		defined(STM32F412Zx) || defined(STM32F413xx) || defined(STM32F423xx)
	#define STM32F4					//!< STM32F4 family generic define
	#if !defined(STM_FAMILY)
		#define STM_FAMILY	f4		//!< STM32 family (f4) for name catenation
	#endif
#elif	defined(STM32F756xx) || defined(STM32F746xx) || defined(STM32F745xx) || defined(STM32F767xx) ||	\
		defined(STM32F769xx) || defined(STM32F777xx) || defined(STM32F779xx) || defined(STM32F722xx) ||	\
		defined(STM32F723xx) || defined(STM32F732xx) || defined(STM32F733xx)
	#define STM32F7					//!< STM32F7 family generic define
	#if !defined(STM_FAMILY)
		#define STM_FAMILY	f7		//!< STM32 family (f7) for name catenation
	#endif
#elif	defined(STM32H743xx) || defined(STM32H753xx)
	#define STM32H7					//!< STM32H7 family generic define
	#if !defined(STM_FAMILY)
		#define STM_FAMILY	h7		//!< STM32 family (h7) for name catenation
	#endif
#elif	defined(STM32L011xx) || defined(STM32L021xx) ||							\
		defined(STM32L031xx) || defined(STM32L041xx) ||							\
		defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||	\
		defined(STM32L061xx) || defined(STM32L062xx) || defined(STM32L063xx) ||	\
		defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||	\
		defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)
	#define STM32L0					//!< STM32L0 family generic define
	#if !defined(STM_FAMILY)
		#define STM_FAMILY	l0		//!< STM32 family (l0) for name catenation
	#endif
#elif	defined(STM32L100xB) || defined(STM32L100xBA) || defined(STM32L100xC) ||																									\
		defined(STM32L151xB) || defined(STM32L151xBA) || defined(STM32L151xC) || defined(STM32L151xCA) || defined(STM32L151xD) || defined(STM32L151xDX) || defined(STM32L151xE) ||	\
		defined(STM32L152xB) || defined(STM32L152xBA) || defined(STM32L152xC) || defined(STM32L152xCA) || defined(STM32L152xD) || defined(STM32L152xDX) || defined(STM32L152xE) ||	\
		defined(STM32L162xC) || defined(STM32L162xCA) || defined(STM32L162xD) || defined(STM32L162xDX) || defined(STM32L162xE)
	#define STM32L1					//!< STM32L1 family generic define
	#if !defined(STM_FAMILY)
		#define STM_FAMILY	l1		//!< STM32 family (l1) for name catenation
	#endif
#elif	defined(STM32L431xx) || defined(STM32L432xx) || defined(STM32L433xx) || defined(STM32L442xx) || defined(STM32L443xx) ||							\
		defined(STM32L451xx) || defined(STM32L452xx) || defined(STM32L462xx) ||																			\
		defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx) ||							\
		defined(STM32L496xx) || defined(STM32L4A6xx) ||																									\
		defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
	#define STM32L4					//!< STM32L4 family generic define
	#if !defined(STM_FAMILY)
		#define STM_FAMILY	l4		//!< STM32 family (l4) for name catenation
	#endif
/**************************/
/*** Atmel SAM Families ***/
/**************************/
#elif	defined(__SAM3A4C__) || defined(__ATSAM3A4C__) || defined(__SAM3A8C__) || defined(__ATSAM3A8C__)
	#define SAM3A					//!< SAM3A family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	3a		//!< SAM family (3a) for name catenation
	#endif
#elif	defined(__SAM3N00A__) || defined(__ATSAM3N00A__) || defined(__SAM3N00B__) || defined(__ATSAM3N00B__) || defined(__SAM3N0A__) || defined(__ATSAM3N0A__) ||	\
		defined(__SAM3N0B__) || defined(__ATSAM3N0B__) || defined(__SAM3N0C__) || defined(__ATSAM3N0C__) || defined(__SAM3N1A__) || defined(__ATSAM3N1A__) ||		\
		defined(__SAM3N1B__) || defined(__ATSAM3N1B__) || defined(__SAM3N1C__) || defined(__ATSAM3N1C__) || defined(__SAM3N2A__) || defined(__ATSAM3N2A__) ||		\
		defined(__SAM3N2B__) || defined(__ATSAM3N2B__) || defined(__SAM3N2C__) || defined(__ATSAM3N2C__) || defined(__SAM3N4A__) || defined(__ATSAM3N4A__) ||		\
		defined(__SAM3N4B__) || defined(__ATSAM3N4B__) || defined(__SAM3N4C__) || defined(__ATSAM3N4C__)
	#define SAM3N					//!< SAM3N family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	3n		//!< SAM family (3n) for name catenation
	#endif
#elif	defined(__SAM3S1A__) || defined(__ATSAM3S1A__) || defined(__SAM3S1B__) || defined(__ATSAM3S1B__) || defined(__SAM3S1C__) || defined(__ATSAM3S1C__) || \
		defined(__SAM3S2A__) || defined(__ATSAM3S2A__) || defined(__SAM3S2B__) || defined(__ATSAM3S2B__) || defined(__SAM3S2C__) || defined(__ATSAM3S2C__) || \
		defined(__SAM3S4A__) || defined(__ATSAM3S4A__) || defined(__SAM3S4B__) || defined(__ATSAM3S4B__) || defined(__SAM3S4C__) || defined(__ATSAM3S4C__)
	#define SAM3S					//!< SAM3S family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	3s		//!< SAM family (3s) for name catenation
	#endif
#elif	defined(__SAM3S8B__) || defined(__ATSAM3S8B__) || defined(__SAM3S8C__) || defined(__ATSAM3S8C__) || defined(__SAM3SD8B__) || defined(__ATSAM3SD8B__) ||	\
		defined(__SAM3SD8C__) || defined(__ATSAM3SD8C__)
	#define SAM3S8B					//!< SAM3S8B family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	3s8b	//!< SAM family (3s8b) for name catenation
	#endif
#elif	defined(__SAM3U1C__) || defined(__ATSAM3U1C__) || defined(__SAM3U1E__) || defined(__ATSAM3U1E__) || defined(__SAM3U2C__) || defined(__ATSAM3U2C__) || \
		defined(__SAM3U2E__) || defined(__ATSAM3U2E__) || defined(__SAM3U4C__) || defined(__ATSAM3U4C__) || defined(__SAM3U4E__) || defined(__ATSAM3U4E__)
	#define SAM3U					//!< SAM3U family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	3u		//!< SAM family (3u) for name catenation
	#endif
#elif	defined(__SAM3X4C__) || defined(__ATSAM3X4C__) || defined(__SAM3X4E__) || defined(__ATSAM3X4E__) || defined(__SAM3X8C__) || defined(__ATSAM3X8C__) || \
		defined(__SAM3X8E__) || defined(__ATSAM3X8E__) || defined(__SAM3X8H__) || defined(__ATSAM3X8H__)
	#define SAM3X					//!< SAM3X family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	3x		//!< SAM family (3x) for name catenation
	#endif
#elif	defined(__SAM4C16C_0__) || defined(__ATSAM4C16C_0__) || defined(__SAM4C16C_1__) || defined(__ATSAM4C16C_1__) || defined(__SAM4C4C_0__) || defined(__ATSAM4C4C_0__) || \
		defined(__SAM4C4C_1__) || defined(__ATSAM4C4C_1__) || defined(__SAM4C8C_0__) || defined(__ATSAM4C8C_0__) || defined(__SAM4C8C_1__) || defined(__ATSAM4C8C_1__)
	#define SAM4C					//!< SAM4C family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	4c		//!< SAM family (4c) for name catenation
	#endif
#elif	defined(__SAM4C32C_0__) || defined(__ATSAM4C32C_0__) || defined(__SAM4C32C_1__) || defined(__ATSAM4C32C_1__) || defined(__SAM4C32E_0__) || defined(__ATSAM4C32E_0__) || \
		defined(__SAM4C32E_1__) || defined(__ATSAM4C32E_1__)
	#define SAM4C32					//!< SAM4C32 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	4c32	//!< SAM family (4c32) for name catenation
	#endif
#elif	defined(__SAM4CMP16C_0__) || defined(__ATSAM4CMP16C_0__) || defined(__SAM4CMP16C_1__) || defined(__ATSAM4CMP16C_1__) || defined(__SAM4CMP8C_0__) || defined(__ATSAM4CMP8C_0__) ||	\
		defined(__SAM4CMP8C_1__) || defined(__ATSAM4CMP8C_1__) || defined(__SAM4CMS16C_0__) || defined(__ATSAM4CMS16C_0__) || defined(__SAM4CMS16C_1__) || defined(__ATSAM4CMS16C_1__) ||	\
		defined(__SAM4CMS4C_0__) || defined(__ATSAM4CMS4C_0__) || defined(__SAM4CMS4C_1__) || defined(__ATSAM4CMS4C_1__) || defined(__SAM4CMS8C_0__) || defined(__ATSAM4CMS8C_0__) ||		\
		defined(__SAM4CMS8C_1__) || defined(__ATSAM4CMS8C_1__)
	#define SAM4CM					//!< SAM4CM family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	4cm		//!< SAM family (4cm) for name catenation
	#endif
#elif	defined(__SAM4CMP32C_0__) || defined(__ATSAM4CMP32C_0__) || defined(__SAM4CMP32C_1__) || defined(__ATSAM4CMP32C_1__) || defined(__SAM4CMS32C_0__) || defined(__ATSAM4CMS32C_0__) || \
		defined(__SAM4CMS32C_1__) || defined(__ATSAM4CMS32C_1__)
	#define SAM4CM32				//!< SAM4CM32 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	4cm32	//!< SAM family (4cm32) for name catenation
	#endif
#elif	defined(__SAM4CP16B_0__) || defined(__ATSAM4CP16B_0__) || defined(__SAM4CP16B_1__) || defined(__ATSAM4CP16B_1__) || defined(__SAM4CP16C_0__) || defined(__ATSAM4CP16C_0__) || \
		defined(__SAM4CP16C_1__) || defined(__ATSAM4CP16C_1__)
	#define SAM4CP					//!< SAM4CP family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	4cp		//!< SAM family (4cp) for name catenation
	#endif
#elif	defined(__SAM4E16C__) || defined(__ATSAM4E16C__) || defined(__SAM4E16E__) || defined(__ATSAM4E16E__) || defined(__SAM4E8C__) || defined(__ATSAM4E8C__) ||	\
		defined(__SAM4E8E__) || defined(__ATSAM4E8E__)
	#define SAM4E					//!< SAM4E family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	4e		//!< SAM family (4e) for name catenation
	#endif
#elif	defined(__SAM4E16CB__) || defined(__ATSAM4E16CB__) || defined(__SAM4E8CB__) || defined(__ATSAM4E8CB__)
	#define SAM4ECB					//!< SAM4ECB family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	4ecb	//!< SAM family (4ecb) for name catenation
	#endif
#elif	defined(__SAM4LC2A__) || defined(__ATSAM4LC2A__) || defined(__SAM4LC2B__) || defined(__ATSAM4LC2B__) || defined(__SAM4LC2C__) || defined(__ATSAM4LC2C__) ||	\
		defined(__SAM4LC4A__) || defined(__ATSAM4LC4A__) || defined(__SAM4LC4B__) || defined(__ATSAM4LC4B__) || defined(__SAM4LC4C__) || defined(__ATSAM4LC4C__) ||	\
		defined(__SAM4LS2A__) || defined(__ATSAM4LS2A__) || defined(__SAM4LS2B__) || defined(__ATSAM4LS2B__) || defined(__SAM4LS2C__) || defined(__ATSAM4LS2C__) ||	\
		defined(__SAM4LS4A__) || defined(__ATSAM4LS4A__) || defined(__SAM4LS4B__) || defined(__ATSAM4LS4B__) || defined(__SAM4LS4C__) || defined(__ATSAM4LS4C__)
	#define SAM4L4					//!< SAM4L4 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	4l4		//!< SAM family (4l4) for name catenation
	#endif
#elif	defined(__SAM4LC8A__) || defined(__ATSAM4LC8A__) || defined(__SAM4LC8B__) || defined(__ATSAM4LC8B__) || defined(__SAM4LC8C__) || defined(__ATSAM4LC8C__) ||	\
		defined(__SAM4LS8A__) || defined(__ATSAM4LS8A__) || defined(__SAM4LS8B__) || defined(__ATSAM4LS8B__) || defined(__SAM4LS8C__) || defined(__ATSAM4LS8C__)
	#define SAM4L8					//!< SAM4L8 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	4l8		//!< SAM family (4l8) for name catenation
	#endif
#elif	defined(__SAM4N16B__) || defined(__ATSAM4N16B__) || defined(__SAM4N16C__) || defined(__ATSAM4N16C__) || defined(__SAM4N8A__) || defined(__ATSAM4N8A__) || \
		defined(__SAM4N8B__) || defined(__ATSAM4N8B__) || defined(__SAM4N8C__) || defined(__ATSAM4N8C__)
	#define SAM4N					//!< SAM4N family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	4n		//!< SAM family (4n) for name catenation
	#endif
#elif	defined(__SAM4S16B__) || defined(__ATSAM4S16B__) || defined(__SAM4S16C__) || defined(__ATSAM4S16C__) || defined(__SAM4S2A__) || defined(__ATSAM4S2A__) ||			\
		defined(__SAM4S2B__) || defined(__ATSAM4S2B__) || defined(__SAM4S2C__) || defined(__ATSAM4S2C__) || defined(__SAM4S4A__) || defined(__ATSAM4S4A__) ||				\
		defined(__SAM4S4B__) || defined(__ATSAM4S4B__) || defined(__SAM4S4C__) || defined(__ATSAM4S4C__) || defined(__SAM4S8B__) || defined(__ATSAM4S8B__) ||				\
		defined(__SAM4S8C__) || defined(__ATSAM4S8C__) || defined(__SAM4SA16B__) || defined(__ATSAM4SA16B__) || defined(__SAM4SA16C__) || defined(__ATSAM4SA16C__) ||		\
		defined(__SAM4SD16B__) || defined(__ATSAM4SD16B__) || defined(__SAM4SD16C__) || defined(__ATSAM4SD16C__) || defined(__SAM4SD32B__) || defined(__ATSAM4SD32B__) ||	\
		defined(__SAM4SD32C__) || defined(__ATSAM4SD32C__)
	#define SAM4S					//!< SAM4S family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	4s		//!< SAM family (4s) for name catenation
	#endif
#elif	defined(__SAM4SP32A__) || defined(__ATSAM4SP32A__)
	#define SAM4SP					//!< SAM4SP family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	4sp		//!< SAM family (4sp) for name catenation
	#endif
#elif	defined(__BTLC1000WLCSP__) || defined(__ATBTLC1000WLCSP__) || defined(__SAMB11G18A__) || defined(__ATSAMB11G18A__) || defined(__SAMB11ZR__) || defined(__ATSAMB11ZR__)
	#define SAMB11					//!< SAMB11 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	b11		//!< SAM family (b11) for name catenation
	#endif
#elif	defined(__SAMC20E15A__) || defined(__ATSAMC20E15A__) || defined(__SAMC20E16A__) || defined(__ATSAMC20E16A__) || defined(__SAMC20E17A__) || defined(__ATSAMC20E17A__) ||		\
		defined(__SAMC20E18A__) || defined(__ATSAMC20E18A__) || defined(__SAMC20G15A__) || defined(__ATSAMC20G15A__) || defined(__SAMC20G16A__) || defined(__ATSAMC20G16A__) ||		\
		defined(__SAMC20G17A__) || defined(__ATSAMC20G17A__) || defined(__SAMC20G18A__) || defined(__ATSAMC20G18A__) || defined(__SAMC20J15A__) || defined(__ATSAMC20J15A__) ||		\
		defined(__SAMC20J16A__) || defined(__ATSAMC20J16A__) || defined(__SAMC20J17A__) || defined(__ATSAMC20J17A__) || defined(__SAMC20J17AU__) || defined(__ATSAMC20J17AU__) ||	\
		defined(__SAMC20J18A__) || defined(__ATSAMC20J18A__) || defined(__SAMC20J18AU__) || defined(__ATSAMC20J18AU__)
	#define SAMC20					//!< SAMC20 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	c20		//!< SAM family (c20) for name catenation
	#endif
#elif	defined(__SAMC20N17A__) || defined(__ATSAMC20N17A__) ||	defined(__SAMC20N18A__) || defined(__ATSAMC20N18A__)
	#define SAMC20N					//!< SAMC20N family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	c20n	//!< SAM family (c20n) for name catenation
	#endif
#elif	defined(__SAMC21E15A__) || defined(__ATSAMC21E15A__) || defined(__SAMC21E16A__) || defined(__ATSAMC21E16A__) || defined(__SAMC21E17A__) || defined(__ATSAMC21E17A__) ||		\
		defined(__SAMC21E18A__) || defined(__ATSAMC21E18A__) ||	defined(__SAMC21G15A__) || defined(__ATSAMC21G15A__) || defined(__SAMC21G16A__) || defined(__ATSAMC21G16A__) ||		\
		defined(__SAMC21G17A__) || defined(__ATSAMC21G17A__) || defined(__SAMC21G18A__) || defined(__ATSAMC21G18A__) || defined(__SAMC21J15A__) || defined(__ATSAMC21J15A__) ||		\
		defined(__SAMC21J16A__) || defined(__ATSAMC21J16A__) || defined(__SAMC21J17A__) || defined(__ATSAMC21J17A__) || defined(__SAMC21J17AU__) || defined(__ATSAMC21J17AU__) ||	\
		defined(__SAMC21J18A__) || defined(__ATSAMC21J18A__) || defined(__SAMC21J18AU__) || defined(__ATSAMC21J18AU__)
	#define SAMC21					//!< SAMC21 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	c21		//!< SAM family (c21) for name catenation
	#endif
#elif	defined(__SAMC21N17A__) || defined(__ATSAMC21N17A__) || defined(__SAMC21N18A__) || defined(__ATSAMC21N18A__)
	#define SAMC21N					//!< SAMC21N family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	c21n	//!< SAM family (c21n) for name catenation
	#endif
#elif	defined(__SAMD09C13A__) || defined(__ATSAMD09C13A__) || defined(__SAMD09D14A__) || defined(__ATSAMD09D14A__)
	#define SAMD09					//!< SAMD09 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	d09		//!< SAM family (d09) for name catenation
	#endif
#elif	defined(__SAMD10C13A__) || defined(__ATSAMD10C13A__) || defined(__SAMD10C14A__) || defined(__ATSAMD10C14A__) || defined(__SAMD10D13AM__) || defined(__ATSAMD10D13AM__) ||		\
		defined(__SAMD10D13AS__) || defined(__ATSAMD10D13AS__) || defined(__SAMD10D14AM__) || defined(__ATSAMD10D14AM__) || defined(__SAMD10D14AS__) || defined(__ATSAMD10D14AS__) ||	\
		defined(__SAMD10D14AU__) || defined(__ATSAMD10D14AU__)
	#define SAMD10					//!< SAMD10 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	d10		//!< SAM family (d10) for name catenation
	#endif
#elif	defined(__SAMD11C14A__) || defined(__ATSAMD11C14A__) || defined(__SAMD11D14AM__) || defined(__ATSAMD11D14AM__) || defined(__SAMD11D14AS__) || defined(__ATSAMD11D14AS__) || \
		defined(__SAMD11D14AU__) || defined(__ATSAMD11D14AU__)
	#define SAMD11					//!< SAMD11 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	d11		//!< SAM family (d11) for name catenation
	#endif
#elif	defined(__SAMD20E14__) || defined(__ATSAMD20E14__) || defined(__SAMD20E15__) || defined(__ATSAMD20E15__) || defined(__SAMD20E16__) || defined(__ATSAMD20E16__) ||		\
		defined(__SAMD20E17__) || defined(__ATSAMD20E17__) || defined(__SAMD20E18__) || defined(__ATSAMD20E18__) || defined(__SAMD20G14__) || defined(__ATSAMD20G14__) ||		\
		defined(__SAMD20G15__) || defined(__ATSAMD20G15__) || defined(__SAMD20G16__) || defined(__ATSAMD20G16__) || defined(__SAMD20G17__) || defined(__ATSAMD20G17__) ||		\
		defined(__SAMD20G17U__) || defined(__ATSAMD20G17U__) || defined(__SAMD20G18__) || defined(__ATSAMD20G18__) || defined(__SAMD20G18U__) || defined(__ATSAMD20G18U__) ||	\
		defined(__SAMD20J14__) || defined(__ATSAMD20J14__) || defined(__SAMD20J15__) || defined(__ATSAMD20J15__) || defined(__SAMD20J16__) || defined(__ATSAMD20J16__) ||		\
		defined(__SAMD20J17__) || defined(__ATSAMD20J17__) || defined(__SAMD20J18__) || defined(__ATSAMD20J18__)
	#define SAMD20					//!< SAMD20 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	d20		//!< SAM family (d20) for name catenation
	#endif
#elif	defined(__SAMD20E14B__) || defined(__ATSAMD20E14B__) || defined(__SAMD20E15B__) || defined(__ATSAMD20E15B__) || defined(__SAMD20E16B__) || defined(__ATSAMD20E16B__) || \
		defined(__SAMD20G14B__) || defined(__ATSAMD20G14B__) || defined(__SAMD20G15B__) || defined(__ATSAMD20G15B__) || defined(__SAMD20G16B__) || defined(__ATSAMD20G16B__) || \
		defined(__SAMD20J14B__) || defined(__ATSAMD20J14B__) ||	defined(__SAMD20J15B__) || defined(__ATSAMD20J15B__) || defined(__SAMD20J16B__) || defined(__ATSAMD20J16B__)
	#define SAMD20B					//!< SAMD20B family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	d20b	//!< SAM family (d20b) for name catenation
	#endif
#elif	defined(__SAMD21E15A__) || defined(__ATSAMD21E15A__) || defined(__SAMD21E16A__) || defined(__ATSAMD21E16A__) || defined(__SAMD21E17A__) || defined(__ATSAMD21E17A__) ||		\
		defined(__SAMD21E18A__) || defined(__ATSAMD21E18A__) || defined(__SAMD21G15A__) || defined(__ATSAMD21G15A__) || defined(__SAMD21G16A__) || defined(__ATSAMD21G16A__) ||		\
		defined(__SAMD21G17A__) || defined(__ATSAMD21G17A__) || defined(__SAMD21G17AU__) || defined(__ATSAMD21G17AU__) || defined(__SAMD21G18A__) || defined(__ATSAMD21G18A__) ||	\
		defined(__SAMD21G18AU__) || defined(__ATSAMD21G18AU__) || defined(__SAMD21J15A__) || defined(__ATSAMD21J15A__) || defined(__SAMD21J16A__) || defined(__ATSAMD21J16A__) ||	\
		defined(__SAMD21J17A__) || defined(__ATSAMD21J17A__) || defined(__SAMD21J18A__) || defined(__ATSAMD21J18A__)
	#define SAMD21A					//!< SAMD21A family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	d21a	//!< SAM family (d21a) for name catenation
	#endif
#elif	defined(__SAMD21E15BU__) || defined(__ATSAMD21E15BU__) || defined(__SAMD21E16BU__) || defined(__ATSAMD21E16BU__)
	#define SAMD21B					//!< SAMD21B family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	d21b	//!< SAM family (d21b) for name catenation
	#endif
#elif	defined(__SAMD21E15B__) || defined(__ATSAMD21E15B__) || defined(__SAMD21E15CU__) || defined(__ATSAMD21E15CU__) || defined(__SAMD21E15L__) || defined(__ATSAMD21E15L__) ||	\
		defined(__SAMD21E16B__) || defined(__ATSAMD21E16B__) || defined(__SAMD21E16CU__) || defined(__ATSAMD21E16CU__) || defined(__SAMD21E16L__) || defined(__ATSAMD21E16L__) ||	\
		defined(__SAMD21G15B__) || defined(__ATSAMD21G15B__) || defined(__SAMD21G15L__) || defined(__ATSAMD21G15L__) || defined(__SAMD21G16B__) || defined(__ATSAMD21G16B__) ||		\
		defined(__SAMD21G16L__) || defined(__ATSAMD21G16L__) || defined(__SAMD21J15B__) || defined(__ATSAMD21J15B__) ||	defined(__SAMD21J16B__) || defined(__ATSAMD21J16B__)
	#define SAMD21C					//!< SAMD21C family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	d21c	//!< SAM family (d21c) for name catenation
	#endif
#elif	defined(__SAMD51G18A__) || defined(__ATSAMD51G18A__) || defined(__SAMD51G19A__) || defined(__ATSAMD51G19A__) || defined(__SAMD51J18A__) || defined(__ATSAMD51J18A__) ||	\
		defined(__SAMD51J19A__) || defined(__ATSAMD51J19A__) || defined(__SAMD51J20A__) || defined(__ATSAMD51J20A__) || defined(__SAMD51N19A__) || defined(__ATSAMD51N19A__) ||	\
		defined(__SAMD51N20A__) || defined(__ATSAMD51N20A__) || defined(__SAMD51P19A__) || defined(__ATSAMD51P19A__) || defined(__SAMD51P20A__) || defined(__ATSAMD51P20A__)
	#define SAMD51					//!< SAMD51 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	d51		//!< SAM family (d51) for name catenation
	#endif
#elif	defined(__SAMDA1E14A__) || defined(__ATSAMDA1E14A__) || defined(__SAMDA1E15A__) || defined(__ATSAMDA1E15A__) || defined(__SAMDA1E16A__) || defined(__ATSAMDA1E16A__) ||	\
		defined(__SAMDA1G14A__) || defined(__ATSAMDA1G14A__) || defined(__SAMDA1G15A__) || defined(__ATSAMDA1G15A__) || defined(__SAMDA1G16A__) || defined(__ATSAMDA1G16A__) ||	\
		defined(__SAMDA1J14A__) || defined(__ATSAMDA1J14A__) || defined(__SAMDA1J15A__) || defined(__ATSAMDA1J15A__) || defined(__SAMDA1J16A__) || defined(__ATSAMDA1J16A__)
	#define SAMDA1					//!< SAMDA1 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	da1		//!< SAM family (da1) for name catenation
	#endif
#elif	defined(__SAMDA1E14B__) || defined(__ATSAMDA1E14B__) || defined(__SAMDA1E15B__) || defined(__ATSAMDA1E15B__) || defined(__SAMDA1E16B__) || defined(__ATSAMDA1E16B__) ||	\
		defined(__SAMDA1G14B__) || defined(__ATSAMDA1G14B__) || defined(__SAMDA1G15B__) || defined(__ATSAMDA1G15B__) || defined(__SAMDA1G16B__) || defined(__ATSAMDA1G16B__) ||	\
		defined(__SAMDA1J14B__) || defined(__ATSAMDA1J14B__) || defined(__SAMDA1J15B__) || defined(__ATSAMDA1J15B__) || defined(__SAMDA1J16B__) || defined(__ATSAMDA1J16B__)
	#define SAMDA1B					//!< SAMDA1B family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	da1b	//!< SAM family (da1b) for name catenation
	#endif
#elif	defined(__SAME51J18A__) || defined(__ATSAME51J18A__) || defined(__SAME51J19A__) || defined(__ATSAME51J19A__) || defined(__SAME51J20A__) || defined(__ATSAME51J20A__) || \
		defined(__SAME51N19A__) || defined(__ATSAME51N19A__) || defined(__SAME51N20A__) || defined(__ATSAME51N20A__)
	#define SAME51					//!< SAME51 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	e51		//!< SAM family (e51) for name catenation
	#endif
#elif	defined(__SAME53J18A__) || defined(__ATSAME53J18A__) || defined(__SAME53J19A__) || defined(__ATSAME53J19A__) || defined(__SAME53J20A__) || defined(__ATSAME53J20A__) || \
		defined(__SAME53N19A__) || defined(__ATSAME53N19A__) || defined(__SAME53N20A__) || defined(__ATSAME53N20A__)
	#define SAME53					//!< SAME53 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	e53		//!< SAM family (e53) for name catenation
	#endif
#elif	defined(__SAME54N19A__) || defined(__ATSAME54N19A__) || defined(__SAME54N20A__) || defined(__ATSAME54N20A__) || defined(__SAME54P19A__) || defined(__ATSAME54P19A__) || \
		defined(__SAME54P20A__) || defined(__ATSAME54P20A__)
	#define SAME54					//!< SAME54 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	e54		//!< SAM family (e54) for name catenation
	#endif
#elif	defined(__SAME70J19__) || defined(__ATSAME70J19__) || defined(__SAME70J20__) || defined(__ATSAME70J20__) || defined(__SAME70J21__) || defined(__ATSAME70J21__) || \
		defined(__SAME70N19__) || defined(__ATSAME70N19__) || defined(__SAME70N20__) || defined(__ATSAME70N20__) || defined(__SAME70N21__) || defined(__ATSAME70N21__) || \
		defined(__SAME70Q19__) || defined(__ATSAME70Q19__) || defined(__SAME70Q20__) || defined(__ATSAME70Q20__) || defined(__SAME70Q21__) || defined(__ATSAME70Q21__)
	#define SAME70A					//!< SAME70A family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	e70a	//!< SAM family (e70a) for name catenation
	#endif
#elif	defined(__SAME70J19B__) || defined(__ATSAME70J19B__) || defined(__SAME70J20B__) || defined(__ATSAME70J20B__) || defined(__SAME70J21B__) || defined(__ATSAME70J21B__) ||	\
		defined(__SAME70N19B__) || defined(__ATSAME70N19B__) || defined(__SAME70N20B__) || defined(__ATSAME70N20B__) || defined(__SAME70N21B__) || defined(__ATSAME70N21B__) ||	\
		defined(__SAME70Q19B__) || defined(__ATSAME70Q19B__) || defined(__SAME70Q20B__) || defined(__ATSAME70Q20B__) || defined(__SAME70Q21B__) || defined(__ATSAME70Q21B__)
	#define SAME70B					//!< SAME70B family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	e70b	//!< SAM family (e70b) for name catenation
	#endif
#elif	defined(__SAMG51G18__) || defined(__ATSAMG51G18__) || defined(__SAMG51N18__) || defined(__ATSAMG51N18__)
	#define SAMG51					//!< SAMG51 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	g51		//!< SAM family (g51) for name catenation
	#endif
#elif	defined(__SAMG53G19__) || defined(__ATSAMG53G19__) || defined(__SAMG53N19__) || defined(__ATSAMG53N19__)
	#define SAMG53					//!< SAMG53 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	g53		//!< SAM family (g53) for name catenation
	#endif
#elif	defined(__SAMG54G19__) || defined(__ATSAMG54G19__) || defined(__SAMG54J19__) || defined(__ATSAMG54J19__) || defined(__SAMG54N19__) || defined(__ATSAMG54N19__)
	#define SAMG54					//!< SAMG54 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	g54		//!< SAM family (g54) for name catenation
	#endif
#elif	defined(__SAMG55G19__) || defined(__ATSAMG55G19__) || defined(__SAMG55J19__) || defined(__ATSAMG55J19__)
	#define SAMG55					//!< SAMG55 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	g55		//!< SAM family (g55) for name catenation
	#endif
#elif	defined(__SAMHA1G14A__) || defined(__ATSAMHA1G14A__) || defined(__SAMHA1G15A__) || defined(__ATSAMHA1G15A__) || defined(__SAMHA1G16A__) || defined(__ATSAMHA1G16A__)
	#define SAMHA1A					//!< SAMHA1A family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	ha1a	//!< SAM family (ha1a) for name catenation
	#endif
#elif	defined(__SAMHA1G14AB__) || defined(__ATSAMHA1G14AB__) || defined(__SAMHA1G15AB__) || defined(__ATSAMHA1G15AB__) || defined(__SAMHA1G16AB__) || defined(__ATSAMHA1G16AB__)
	#define SAMHA1AB				//!< SAMHA1AB family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	ha1ab	//!< SAM family (ha1ab) for name catenation
	#endif
#elif	defined(__SAML21E18A__) || defined(__ATSAML21E18A__) || defined(__SAML21G18A__) || defined(__ATSAML21G18A__) || defined(__SAML21J18A__) || defined(__ATSAML21J18A__)
	#define SAML21A1				//!< SAML21A1 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	l21a1	//!< SAM family (l21a1) for name catenation
	#endif
#elif	defined(__SAML21E15B__) || defined(__ATSAML21E15B__) || defined(__SAML21E16B__) || defined(__ATSAML21E16B__) || defined(__SAML21E17B__) || defined(__ATSAML21E17B__) ||	\
		defined(__SAML21E18B__) || defined(__ATSAML21E18B__) || defined(__SAML21G16B__) || defined(__ATSAML21G16B__) || defined(__SAML21G17B__) || defined(__ATSAML21G17B__) ||	\
		defined(__SAML21G18B__) || defined(__ATSAML21G18B__) || defined(__SAML21J16B__) || defined(__ATSAML21J16B__) || defined(__SAML21J17B__) || defined(__ATSAML21J17B__) ||	\
		defined(__SAML21J18B__) || defined(__ATSAML21J18B__) || defined(__SAML21J18BU__) || defined(__ATSAML21J18BU__)
	#define SAML21B					//!< SAML21B family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	l21b	//!< SAM family (l21b) for name catenation
	#endif
#elif	defined(__SAML22G16A__) || defined(__ATSAML22G16A__) || defined(__SAML22G17A__) || defined(__ATSAML22G17A__) || defined(__SAML22G18A__) || defined(__ATSAML22G18A__) ||	\
		defined(__SAML22J16A__) || defined(__ATSAML22J16A__) || defined(__SAML22J17A__) || defined(__ATSAML22J17A__) || defined(__SAML22J18A__) || defined(__ATSAML22J18A__) ||	\
		defined(__SAML22N16A__) || defined(__ATSAML22N16A__) || defined(__SAML22N17A__) || defined(__ATSAML22N17A__) || defined(__SAML22N18A__) || defined(__ATSAML22N18A__)
	#define SAML22					//!< SAML22 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	l22		//!< SAM family (l22) for name catenation
	#endif
#elif	defined(__SAMR21E16A__) || defined(__ATSAMR21E16A__) || defined(__SAMR21E17A__) || defined(__ATSAMR21E17A__) || defined(__SAMR21E18A__) || defined(__ATSAMR21E18A__) ||	\
		defined(__SAMR21E19A__) || defined(__ATSAMR21E19A__) || defined(__SAMR21G16A__) || defined(__ATSAMR21G16A__) || defined(__SAMR21G17A__) || defined(__ATSAMR21G17A__) ||	\
		defined(__SAMR21G18A__) || defined(__ATSAMR21G18A__)
	#define SAMR21					//!< SAMR21 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	r21		//!< SAM family (r21) for name catenation
	#endif
#elif	defined(__SAMR30E18A__) || defined(__ATSAMR30E18A__) || defined(__SAMR30G18A__) || defined(__ATSAMR30G18A__)
	#define SAMR30					//!< SAMR30 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	r30		//!< SAM family (r30) for name catenation
	#endif
#elif	defined(__SAMS70J19__) || defined(__ATSAMS70J19__) || defined(__SAMS70J20__) || defined(__ATSAMS70J20__) || defined(__SAMS70J21__) || defined(__ATSAMS70J21__) || \
		defined(__SAMS70N19__) || defined(__ATSAMS70N19__) || defined(__SAMS70N20__) || defined(__ATSAMS70N20__) || defined(__SAMS70N21__) || defined(__ATSAMS70N21__) || \
		defined(__SAMS70Q19__) || defined(__ATSAMS70Q19__) || defined(__SAMS70Q20__) || defined(__ATSAMS70Q20__) || defined(__SAMS70Q21__) || defined(__ATSAMS70Q21__)
	#define SAMS70A					//!< SAMS70A family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	s70a	//!< SAM family (s70a) for name catenation
	#endif
#elif	defined(__SAMS70J19B__) || defined(__ATSAMS70J19B__) || defined(__SAMS70J20B__) || defined(__ATSAMS70J20B__) || defined(__SAMS70J21B__) || defined(__ATSAMS70J21B__) ||	\
		defined(__SAMS70N19B__) || defined(__ATSAMS70N19B__) || defined(__SAMS70N20B__) || defined(__ATSAMS70N20B__) || defined(__SAMS70N21B__) || defined(__ATSAMS70N21B__) ||	\
		defined(__SAMS70Q19B__) || defined(__ATSAMS70Q19B__) || defined(__SAMS70Q20B__) || defined(__ATSAMS70Q20B__) || defined(__SAMS70Q21B__) || defined(__ATSAMS70Q21B__)
	#define SAMS70B					//!< SAMS70B family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	s70b	//!< SAM family (s70b) for name catenation
	#endif
#elif	defined(__SAMV70J19__) || defined(__ATSAMV70J19__) || defined(__SAMV70J20__) || defined(__ATSAMV70J20__) || defined(__SAMV70N19__) || defined(__ATSAMV70N19__) || \
		defined(__SAMV70N20__) || defined(__ATSAMV70N20__) || defined(__SAMV70Q19__) || defined(__ATSAMV70Q19__) || defined(__SAMV70Q20__) || defined(__ATSAMV70Q20__)
	#define SAMV70					//!< SAMV70 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	v70		//!< SAM family (v70) for name catenation
	#endif
#elif	defined(__SAMV70J19B__) || defined(__ATSAMV70J19B__) || defined(__SAMV70J20B__) || defined(__ATSAMV70J20B__) || defined(__SAMV70N19B__) || defined(__ATSAMV70N19B__) ||	\
		defined(__SAMV70N20B__) || defined(__ATSAMV70N20B__) || defined(__SAMV70Q19B__) || defined(__ATSAMV70Q19B__) || defined(__SAMV70Q20B__) || defined(__ATSAMV70Q20B__)
	#define SAMV70B					//!< SAMV70B family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	v70b	//!< SAM family (v70b) for name catenation
	#endif
#elif	defined(__SAMV71J19__) || defined(__ATSAMV71J19__) || defined(__SAMV71J20__) || defined(__ATSAMV71J20__) || defined(__SAMV71J21__) || defined(__ATSAMV71J21__) || \
		defined(__SAMV71N19__) || defined(__ATSAMV71N19__) || defined(__SAMV71N20__) || defined(__ATSAMV71N20__) || defined(__SAMV71N21__) || defined(__ATSAMV71N21__) || \
		defined(__SAMV71Q19__) || defined(__ATSAMV71Q19__) || defined(__SAMV71Q20__) || defined(__ATSAMV71Q20__) || defined(__SAMV71Q21__) || defined(__ATSAMV71Q21__)
	#define SAMV71					//!< SAMV71 family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	v71		//!< SAM family (v71) for name catenation
	#endif
#elif	defined(__SAMV71J19B__) || defined(__ATSAMV71J19B__) || defined(__SAMV71J20B__) || defined(__ATSAMV71J20B__) || defined(__SAMV71J21B__) || defined(__ATSAMV71J21B__) ||	\
		defined(__SAMV71N19B__) || defined(__ATSAMV71N19B__) || defined(__SAMV71N20B__) || defined(__ATSAMV71N20B__) || defined(__SAMV71N21B__) || defined(__ATSAMV71N21B__) ||	\
		defined(__SAMV71Q19B__) || defined(__ATSAMV71Q19B__) || defined(__SAMV71Q20B__) || defined(__ATSAMV71Q20B__) || defined(__SAMV71Q21B__) || defined(__ATSAMV71Q21B__)
	#define SAMV71B					//!< SAMV71B family generic define
	#if !defined(SAM_FAMILY)
		#define SAM_FAMILY	v71b	//!< SAM family (v71b) for name catenation
	#endif
/**********************/
/*** Other Families ***/
/**********************/
/* #elif XXX_FAMILIES
	#define XXXxxxx					//!< XXXxxxx family generic define
	#if !defined(XXX_FAMILY)
		#define XXX_FAMILY	xx		//!< XXX family (xx) for name catenation
	#endif*/
#else
	#error "You should add the CMSIS base include following chip used & comment this error."
	#error "If working with STM32 and chip is not in the list, try add STM_FAMILY=(f/h/l)x in project defines."
	#error "If working with ATMEL SAM and chip is not in the list, try add SAM_FAMILY=(b/c/d/e/g/h/l/r/s/v)xx in project defines."
#endif


#if defined(INO_FAMILY)
	/*** Define CMSIS common macros ***/
	#define __ASM				__asm			//!< asm keyword for GNU Compiler
	#define __INLINE			inline			//!< inline keyword for GNU Compiler
	#define __STATIC_INLINE		static inline	//!< static inline keyword for GNU Compiler

	/*** Defines for Arduino platform ***/
	#include "arm_chip_ino.h"

#elif defined(STM_FAMILY)
	/*** Defines for STMicro STM32 families ***/
	#include "arm_chip_stm32.h"

	#if !defined(USE_HAL_DRIVER)
		#error "This library is intended to be used with chip vendor supplied HAL, please enable it!"
	#endif

#elif defined(SAM_FAMILY)
	/*** Defines for Atmel SAM families ***/
	#include "arm_chip_sam.h"

// #elif defined(XXX_FAMILY)
	// For other ARM vendor families
	// #include "arm_fam_XXX.h"

#else
	#error "You will have to define your own CMSIS_INC & CMSIS_CFG file names with <> around manually (for specified vendor chip before including sarmfsw.h)."
#endif


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_CMSIS_H */
/****************************************************************/
