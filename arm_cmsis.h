/*!\file arm_cmsis.h
** \author SMFSW
** \copyright MIT (c) 2017-2025, SMFSW
** \brief ARM link with CMSIS files
** \warning Latest ARM chips might now be recognized; if not, define at project level:
** 			- for STM32 families (STMicroelectronics):
** 				- STM_FAMILY xy:
** 					- x : c/f/h/l/mp/u/wb/wl
** 					- y : sub-family number
** 			- for SAM families (Atmel):
** 				- SAM_FAMILY xy(yy)
** 			- for PIC families (Microchip):
** 				- PIC_FAMILY pic(xx)
** 			- for Other families (TI...):
** 				- not implemented yet
** \MISRA Header scope derogation to following rules:\n
** 	\b Rule-21.1 - \b Required: \c \#define and \c \#undef on reserved identifiers (misra-c2012-21.1)\n
**	\a Justification: define generic CMSIS IO macros in case not already defined.\n
*/
// cppcheck-suppress-begin [misra-c2012-21.1]
/****************************************************************/
#ifndef ARM_CMSIS_H_
	#define ARM_CMSIS_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


#define diInterrupts()		__disable_irq()		//!< Disable interruptions macro
#define enInterrupts()		__enable_irq()		//!< Enable interruptions macro


#define CORE_CMSIS_VERSION	__CM_CMSIS_VERSION	//!< CMSIS Core version alias
#define CORTEX_M			__CORTEX_M			//!< ARM Cortex type alias


#ifndef SARMFSW_NO_CHIP_HAL
/************************/
/*** Arduino platform ***/
/************************/
#if defined(ARDUINO)
	#if !defined(INO_FAMILY)
	#define INO_FAMILY			arduino							//!< Arduino family for name catenation?
	#endif
	#define ARDUINO_PLATFORM									//!< Arduino platform generic define

/******************************/
/*** STMicro STM32 Families ***/
/******************************/
#elif	defined(STM32C011xx) || defined(STM32C031xx) ||	\
		defined(STM32C051xx) || defined(STM32C071xx) ||	\
		defined(STM32C091xx) || defined(STM32C092xx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			c0								//!< STM32 family (c0) for name catenation
	#endif
	#define STM32C0												//!< STM32C0 family generic define
	#define STM32_CMSIS_VERSION	__STM32C0_CMSIS_VERSION			//!< STM32C0 CMSIS version

#elif	defined(STM32F030x6) || defined(STM32F030x8) ||													\
		defined(STM32F031x6) || defined(STM32F038xx) ||													\
		defined(STM32F042x6) || defined(STM32F048xx) || defined(STM32F070x6) ||							\
		defined(STM32F051x8) || defined(STM32F058xx) ||													\
		defined(STM32F071xB) || defined(STM32F072xB) || defined(STM32F078xx) || defined(STM32F070xB) ||	\
		defined(STM32F091xC) || defined(STM32F098xx) || defined(STM32F030xC)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			f0								//!< STM32 family (f0) for name catenation
	#endif
	#define STM32F0												//!< STM32F0 family generic define
	#define STM32_CMSIS_VERSION	__STM32F0_CMSIS_VERSION			//!< STM32F0 CMSIS version

#elif	defined(STM32F100xB) || defined(STM32F100xE) || defined(STM32F101x6) ||																			\
		defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6) ||	\
		defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			f1								//!< STM32 family (f1) for name catenation
	#endif
	#define STM32F1												//!< STM32F1 family generic define
	#define STM32_CMSIS_VERSION	__STM32F1_CMSIS_VERSION			//!< STM32F1 CMSIS version

#elif	defined(STM32F205xx) || defined(STM32F215xx) || defined(STM32F207xx) || defined(STM32F217xx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			f2								//!< STM32 family (f2) for name catenation
	#endif
	#define STM32F2												//!< STM32F2 family generic define
	#define STM32_CMSIS_VERSION	__STM32F2xx_CMSIS_VERSION		//!< STM32F2 CMSIS version

#elif	defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx) ||	\
		defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) ||	\
		defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx) ||	\
		defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx) ||	\
		defined(STM32F373xC) || defined(STM32F378xx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			f3								//!< STM32 family (f3) for name catenation
	#endif
	#define STM32F3												//!< STM32F3 family generic define
	#define STM32_CMSIS_VERSION	__STM32F3_CMSIS_VERSION			//!< STM32F3 CMSIS version

#elif	defined(STM32F405xx) || defined(STM32F415xx) || defined(STM32F407xx) || defined(STM32F417xx) ||	\
		defined(STM32F427xx) || defined(STM32F437xx) || defined(STM32F429xx) || defined(STM32F439xx) ||	\
		defined(STM32F401xC) || defined(STM32F401xE) || defined(STM32F410Tx) || defined(STM32F410Cx) ||	\
		defined(STM32F410Rx) || defined(STM32F411xE) || defined(STM32F446xx) || defined(STM32F469xx) ||	\
		defined(STM32F479xx) || defined(STM32F412Cx) || defined(STM32F412Rx) || defined(STM32F412Vx) ||	\
		defined(STM32F412Zx) || defined(STM32F413xx) || defined(STM32F423xx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			f4								//!< STM32 family (f4) for name catenation
	#endif
	#define STM32F4												//!< STM32F4 family generic define
	#define STM32_CMSIS_VERSION	__STM32F4xx_CMSIS_VERSION		//!< STM32F4 CMSIS version

#elif	defined(STM32F756xx) || defined(STM32F746xx) || defined(STM32F745xx) || defined(STM32F765xx) || \
		defined(STM32F767xx) || defined(STM32F769xx) || defined(STM32F777xx) || defined(STM32F779xx) || \
		defined(STM32F722xx) || defined(STM32F723xx) || defined(STM32F732xx) || defined(STM32F733xx) || \
		defined(STM32F730xx) || defined(STM32F750xx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			f7								//!< STM32 family (f7) for name catenation
	#endif
	#define STM32F7												//!< STM32F7 family generic define
	#define STM32_CMSIS_VERSION	__STM32F7_CMSIS_VERSION			//!< STM32F7 CMSIS version

#elif	defined(STM32G071xx) || defined(STM32G081xx) || defined(STM32G070xx) || \
		defined(STM32G030xx) || defined(STM32G031xx) || defined(STM32G041xx) || \
		defined(STM32G0B0xx) || defined(STM32G0B1xx) || defined(STM32G0C1xx) || \
		defined(STM32G050xx) || defined(STM32G051xx) || defined(STM32G061xx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			g0								//!< STM32 family (g0) for name catenation
	#endif
	#define STM32G0												//!< STM32G0 family generic define
	#define STM32_CMSIS_VERSION	__STM32G0_CMSIS_VERSION			//!< STM32G0 CMSIS version

#elif	defined(STM32G431xx) || defined(STM32G441xx) || defined(STM32G471xx) || \
		defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G484xx) || \
		defined(STM32GBK1CB) || defined(STM32G491xx) || defined(STM32G4A1xx) || \
		defined(STM32G411xB) || defined(STM32G411xC) || defined(STM32G414xx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			g4								//!< STM32 family (g4) for name catenation
	#endif
	#define STM32G4												//!< STM32G4 family generic define
	#define STM32_CMSIS_VERSION	__STM32G4_CMSIS_VERSION			//!< STM32G4 CMSIS version

#elif	defined(STM32H573xx) || defined(STM32H563xx) ||	\
		defined(STM32H562xx) || defined(STM32H503xx) ||	\
		defined(STM32H533xx) || defined(STM32H523xx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			h5								//!< STM32 family (h5) for name catenation
	#endif
	#define STM32H5												//!< STM32H5 family generic define
	#define STM32_CMSIS_VERSION	__STM32H5_CMSIS_VERSION			//!< STM32H5 CMSIS version

#elif	defined(STM32H743xx) || defined(STM32H753xx)  || defined(STM32H750xx) || defined(STM32H742xx)  ||													\
		defined(STM32H745xx) || defined(STM32H745xG)  || defined(STM32H755xx) || defined(STM32H747xx)  || defined(STM32H747xG) || defined(STM32H757xx)  ||	\
		defined(STM32H7A3xx) || defined(STM32H7A3xxQ) || defined(STM32H7B3xx) || defined(STM32H7B3xxQ) || defined(STM32H7B0xx) || defined(STM32H7B0xxQ) ||	\
		defined(STM32H735xx) || defined(STM32H733xx)  || defined(STM32H730xx) || defined(STM32H730xxQ) || defined(STM32H725xx) || defined(STM32H723xx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			h7								//!< STM32 family (h7) for name catenation
	#endif
	#define STM32H7												//!< STM32H7 family generic define
	#define STM32_CMSIS_VERSION	__STM32H7xx_CMSIS_VERSION		//!< STM32H7 CMSIS version

#elif	defined(STM32H7R7xx) || defined(STM32H7R3xx) || defined(STM32H7S3xx) || defined(STM32H7S7xx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			h7rs							//!< STM32 family (h7rs) for name catenation
	#endif
	#define STM32H7RS											//!< STM32H7RS family generic define
	#define STM32_CMSIS_VERSION	__STM32H7RS_CMSIS_VERSION		//!< STM32H7RS CMSIS version

#elif	defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) ||	\
		defined(STM32L011xx) || defined(STM32L021xx) ||													\
		defined(STM32L031xx) || defined(STM32L041xx) ||													\
		defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) ||							\
		defined(STM32L062xx) || defined(STM32L063xx) ||													\
		defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) ||							\
		defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			l0								//!< STM32 family (l0) for name catenation
	#endif
	#define STM32L0												//!< STM32L0 family generic define
	#define STM32_CMSIS_VERSION	__STM32L0xx_CMSIS_VERSION		//!< STM32L0 CMSIS version

#elif	defined(STM32L100xB) || defined(STM32L100xBA) || defined(STM32L100xC) ||																									\
		defined(STM32L151xB) || defined(STM32L151xBA) || defined(STM32L151xC) || defined(STM32L151xCA) || defined(STM32L151xD) || defined(STM32L151xDX) || defined(STM32L151xE) ||	\
		defined(STM32L152xB) || defined(STM32L152xBA) || defined(STM32L152xC) || defined(STM32L152xCA) || defined(STM32L152xD) || defined(STM32L152xDX) || defined(STM32L152xE) ||	\
		defined(STM32L162xC) || defined(STM32L162xCA) || defined(STM32L162xD) || defined(STM32L162xDX) || defined(STM32L162xE)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			l1								//!< STM32 family (l1) for name catenation
	#endif
	#define STM32L1												//!< STM32L1 family generic define
	#define STM32_CMSIS_VERSION	__STM32L1xx_CMSIS_VERSION		//!< STM32L1 CMSIS version

#elif	defined(STM32L412xx) || defined(STM32L422xx) ||																									\
		defined(STM32L431xx) || defined(STM32L432xx) || defined(STM32L433xx) || defined(STM32L442xx) || defined(STM32L443xx) ||							\
		defined(STM32L451xx) || defined(STM32L452xx) || defined(STM32L462xx) ||																			\
		defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx) ||							\
		defined(STM32L496xx) || defined(STM32L4A6xx) ||																									\
		defined(STM32L4P5xx) || defined(STM32L4Q5xx) ||																									\
		defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			l4								//!< STM32 family (l4) for name catenation
	#endif
	#define STM32L4												//!< STM32L4 family generic define
	#define STM32_CMSIS_VERSION	__STM32L4_CMSIS_VERSION			//!< STM32L4 CMSIS version

#elif defined(STM32L552xx) || defined(STM32L562xx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			l5								//!< STM32 family (l5) for name catenation
	#endif
	#define STM32L5												//!< STM32L5 family generic define
	#define STM32_CMSIS_VERSION	__STM32L5_CMSIS_VERSION			//!< STM32L5 CMSIS version

#elif 	defined(STM32MP15xx)   ||																				\
		defined(STM32MP157Axx) || defined(STM32MP157Cxx) || defined(STM32MP157Dxx) || defined(STM32MP157Fxx) || \
		defined(STM32MP153Axx) || defined(STM32MP153Cxx) || defined(STM32MP153Dxx) || defined(STM32MP153Fxx) || \
		defined(STM32MP151Axx) || defined(STM32MP151Cxx) || defined(STM32MP151Dxx) || defined(STM32MP151Fxx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			mp1								//!< STM32 family (mp1) for name catenation
	#endif
	#define STM32MP1											//!< STM32MP1 family generic define
	#define STM32_CMSIS_VERSION	__STM32MP1xx_CMSIS_VERSION		//!< STM32MP1 CMSIS version

#elif	defined(STM32MP257Fxx) || defined(STM32MP257Dxx) || defined(STM32MP257Cxx) || defined(STM32MP257Axx) ||\
		defined(STM32MP255Fxx) || defined(STM32MP255Dxx) || defined(STM32MP255Cxx) || defined(STM32MP255Axx) ||\
		defined(STM32MP253Fxx) || defined(STM32MP253Dxx) || defined(STM32MP253Cxx) || defined(STM32MP253Axx) ||\
		defined(STM32MP251Fxx) || defined(STM32MP251Dxx) || defined(STM32MP251Cxx) || defined(STM32MP251Axx) ||\
		defined(STM32MP215Fxx) || defined(STM32MP215Dxx) || defined(STM32MP215Cxx) || defined(STM32MP215Axx) ||\
		defined(STM32MP213Fxx) || defined(STM32MP213Dxx) || defined(STM32MP213Cxx) || defined(STM32MP213Axx) ||\
		defined(STM32MP211Fxx) || defined(STM32MP211Dxx) || defined(STM32MP211Cxx) || defined(STM32MP211Axx) ||\
		defined(STM32MP235Fxx) || defined(STM32MP235Dxx) || defined(STM32MP235Cxx) || defined(STM32MP235Axx) ||\
		defined(STM32MP233Fxx) || defined(STM32MP233Dxx) || defined(STM32MP233Cxx) || defined(STM32MP233Axx) ||\
		defined(STM32MP231Fxx) || defined(STM32MP231Dxx) || defined(STM32MP231Cxx) || defined(STM32MP231Axx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			mp2								//!< STM32 family (mp2) for name catenation
	#endif
	#define STM32MP2											//!< STM32MP2 family generic define
	#define STM32_CMSIS_VERSION	__STM32MP2xx_CMSIS_VERSION		//!< STM32MP2 CMSIS version

#elif	defined(STM32MP13xx)   || defined(STM32MP135Axx) || defined(STM32MP135Cxx) || defined(STM32MP135Dxx) || defined(STM32MP135Fxx) ||	\
		defined(STM32MP133Axx) || defined(STM32MP133Cxx) || defined(STM32MP133Dxx) || defined(STM32MP133Fxx) ||								\
		defined(STM32MP131Axx) || defined(STM32MP131Cxx) || defined(STM32MP131Dxx) || defined(STM32MP131Fxx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			mp13							//!< STM32 family (mp13) for name catenation
	#endif
	#define STM32MP13											//!< STM32MP13 family generic define
	#define STM32_CMSIS_VERSION	__STM32MP13xx_CMSIS_VERSION		//!< STM32MP13 CMSIS version

#elif	defined(STM32N647xx) || defined(STM32N657xx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			n6								//!< STM32 family (n6) for name catenation
	#endif
	#define STM32N6												//!< STM32N6 family generic define
	#define STM32_CMSIS_VERSION	__STM32N6_CMSIS_VERSION			//!< STM32N6 CMSIS version

#elif	defined(STM32U073xx) || defined(STM32U083xx) || defined(STM32U031xx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			u0								//!< STM32 family (u0) for name catenation
	#endif
	#define STM32U0												//!< STM32U0 family generic define
	#define STM32_CMSIS_VERSION	__STM32U0_CMSIS_VERSION			//!< STM32U0 CMSIS version

#elif	defined(STM32U375xx) || defined(STM32U385xx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			u3								//!< STM32 family (u3) for name catenation
	#endif
	#define STM32U3												//!< STM32U3 family generic define
	#define STM32_CMSIS_VERSION	__STM32U3_CMSIS_VERSION			//!< STM32U3 CMSIS version

#elif 	defined(STM32U575xx) || defined(STM32U585xx) || \
		defined(STM32U595xx) || defined(STM32U599xx) || \
		defined(STM32U5A5xx) || defined(STM32U5A9xx) || \
		defined(STM32U5F7xx) || defined(STM32U5G7xx) || \
		defined(STM32U5F9xx) || defined(STM32U5G9xx) || \
		defined(STM32U535xx) || defined(STM32U545xx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			u5								//!< STM32 family (u5) for name catenation
	#endif
	#define STM32U5												//!< STM32U5 family generic define
	#define STM32_CMSIS_VERSION	__STM32U5_CMSIS_VERSION			//!< STM32U5 CMSIS version

#elif	defined(STM32WB55xx) || defined(STM32WB5Mxx) || defined(STM32WB50xx) || \
		defined(STM32WB35xx) || defined(STM32WB30xx) ||							\
		defined(STM32WB15xx) || defined(STM32WB10xx) || defined(STM32WB1Mxx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			wb									//!< STM32 family (wb) for name catenation
	#endif
	#define STM32WB													//!< STM32WB family generic define
	#define STM32_CMSIS_VERSION	__STM32WBxx_CMSIS_DEVICE_VERSION	//!< STM32WB CMSIS version

#elif	defined(STM32WB05) || defined(STM32WB06) || defined(STM32WB07)  || defined(STM32WB09)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			wb0									//!< STM32 family (wb0) for name catenation
	#endif
	#define STM32WB0												//!< STM32WB0 family generic define
	#define STM32_CMSIS_VERSION	__STM32WB0x_CMSIS_DEVICE_VERSION	//!< STM32WB0 CMSIS version

#elif	defined(STM32WBA50xx) || defined(STM32WBA52xx) || defined(STM32WBA54xx) || defined(STM32WBA55xx) ||	\
		defined(STM32WBA5Mxx) || defined(STM32WBA62xx) || defined(STM32WBA63xx) || defined(STM32WBA64xx) ||	\
		defined(STM32WBA65xx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			wba								//!< STM32 family (wba) for name catenation
	#endif
	#define STM32WBA											//!< STM32WBA family generic define
	#define STM32_CMSIS_VERSION	__STM32WBA_CMSIS_VERSION		//!< STM32WBA CMSIS version

#elif	defined(STM32WL55xx) || defined(STM32WL54xx) || defined(STM32WLE5xx) || defined(STM32WLE4xx) || defined(STM32WL5Mxx)
	#if !defined(STM_FAMILY)
	#define STM_FAMILY			wl								//!< STM32 family (wl) for name catenation
	#endif
	#define STM32WL												//!< STM32WL family generic define
	#define STM32_CMSIS_VERSION	__STM32WLxx_CMSIS_VERSION		//!< STM32WL CMSIS version

/**************************/
/*** Atmel SAM Families ***/
/**************************/
#elif	defined(__SAM3A4C__) || defined(__ATSAM3A4C__) || defined(__SAM3A8C__) || defined(__ATSAM3A8C__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			3a								//!< SAM family (3a) for name catenation
	#endif
	#define SAM3A												//!< SAM3A family generic define

#elif	defined(__SAM3N00A__) || defined(__ATSAM3N00A__) || defined(__SAM3N00B__) || defined(__ATSAM3N00B__) || defined(__SAM3N0A__) || defined(__ATSAM3N0A__) ||	\
		defined(__SAM3N0B__) || defined(__ATSAM3N0B__) || defined(__SAM3N0C__) || defined(__ATSAM3N0C__) || defined(__SAM3N1A__) || defined(__ATSAM3N1A__) ||		\
		defined(__SAM3N1B__) || defined(__ATSAM3N1B__) || defined(__SAM3N1C__) || defined(__ATSAM3N1C__) || defined(__SAM3N2A__) || defined(__ATSAM3N2A__) ||		\
		defined(__SAM3N2B__) || defined(__ATSAM3N2B__) || defined(__SAM3N2C__) || defined(__ATSAM3N2C__) || defined(__SAM3N4A__) || defined(__ATSAM3N4A__) ||		\
		defined(__SAM3N4B__) || defined(__ATSAM3N4B__) || defined(__SAM3N4C__) || defined(__ATSAM3N4C__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			3n								//!< SAM family (3n) for name catenation
	#endif
	#define SAM3N												//!< SAM3N family generic define

#elif	defined(__SAM3S1A__) || defined(__ATSAM3S1A__) || defined(__SAM3S1B__) || defined(__ATSAM3S1B__) || defined(__SAM3S1C__) || defined(__ATSAM3S1C__) || \
		defined(__SAM3S2A__) || defined(__ATSAM3S2A__) || defined(__SAM3S2B__) || defined(__ATSAM3S2B__) || defined(__SAM3S2C__) || defined(__ATSAM3S2C__) || \
		defined(__SAM3S4A__) || defined(__ATSAM3S4A__) || defined(__SAM3S4B__) || defined(__ATSAM3S4B__) || defined(__SAM3S4C__) || defined(__ATSAM3S4C__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			3s								//!< SAM family (3s) for name catenation
	#endif
	#define SAM3S												//!< SAM3S family generic define

#elif	defined(__SAM3S8B__) || defined(__ATSAM3S8B__) || defined(__SAM3S8C__) || defined(__ATSAM3S8C__) || defined(__SAM3SD8B__) || defined(__ATSAM3SD8B__) ||	\
		defined(__SAM3SD8C__) || defined(__ATSAM3SD8C__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			3s8b							//!< SAM family (3s8b) for name catenation
	#endif
	#define SAM3S8B												//!< SAM3S8B family generic define

#elif	defined(__SAM3U1C__) || defined(__ATSAM3U1C__) || defined(__SAM3U1E__) || defined(__ATSAM3U1E__) || defined(__SAM3U2C__) || defined(__ATSAM3U2C__) || \
		defined(__SAM3U2E__) || defined(__ATSAM3U2E__) || defined(__SAM3U4C__) || defined(__ATSAM3U4C__) || defined(__SAM3U4E__) || defined(__ATSAM3U4E__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			3u								//!< SAM family (3u) for name catenation
	#endif
	#define SAM3U												//!< SAM3U family generic define

#elif	defined(__SAM3X4C__) || defined(__ATSAM3X4C__) || defined(__SAM3X4E__) || defined(__ATSAM3X4E__) || defined(__SAM3X8C__) || defined(__ATSAM3X8C__) || \
		defined(__SAM3X8E__) || defined(__ATSAM3X8E__) || defined(__SAM3X8H__) || defined(__ATSAM3X8H__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			3x								//!< SAM family (3x) for name catenation
	#endif
	#define SAM3X												//!< SAM3X family generic define

#elif	defined(__SAM4C16C_0__) || defined(__ATSAM4C16C_0__) || defined(__SAM4C16C_1__) || defined(__ATSAM4C16C_1__) || defined(__SAM4C4C_0__) || defined(__ATSAM4C4C_0__) || \
		defined(__SAM4C4C_1__) || defined(__ATSAM4C4C_1__) || defined(__SAM4C8C_0__) || defined(__ATSAM4C8C_0__) || defined(__SAM4C8C_1__) || defined(__ATSAM4C8C_1__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			4c								//!< SAM family (4c) for name catenation
	#endif
	#define SAM4C												//!< SAM4C family generic define

#elif	defined(__SAM4C32C_0__) || defined(__ATSAM4C32C_0__) || defined(__SAM4C32C_1__) || defined(__ATSAM4C32C_1__) || defined(__SAM4C32E_0__) || defined(__ATSAM4C32E_0__) || \
		defined(__SAM4C32E_1__) || defined(__ATSAM4C32E_1__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			4c32							//!< SAM family (4c32) for name catenation
	#endif
	#define SAM4C32												//!< SAM4C32 family generic define

#elif	defined(__SAM4CMP16C_0__) || defined(__ATSAM4CMP16C_0__) || defined(__SAM4CMP16C_1__) || defined(__ATSAM4CMP16C_1__) || defined(__SAM4CMP8C_0__) || defined(__ATSAM4CMP8C_0__) ||	\
		defined(__SAM4CMP8C_1__) || defined(__ATSAM4CMP8C_1__) || defined(__SAM4CMS16C_0__) || defined(__ATSAM4CMS16C_0__) || defined(__SAM4CMS16C_1__) || defined(__ATSAM4CMS16C_1__) ||	\
		defined(__SAM4CMS4C_0__) || defined(__ATSAM4CMS4C_0__) || defined(__SAM4CMS4C_1__) || defined(__ATSAM4CMS4C_1__) || defined(__SAM4CMS8C_0__) || defined(__ATSAM4CMS8C_0__) ||		\
		defined(__SAM4CMS8C_1__) || defined(__ATSAM4CMS8C_1__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			4cm								//!< SAM family (4cm) for name catenation
	#endif
	#define SAM4CM												//!< SAM4CM family generic define

#elif	defined(__SAM4CMP32C_0__) || defined(__ATSAM4CMP32C_0__) || defined(__SAM4CMP32C_1__) || defined(__ATSAM4CMP32C_1__) || defined(__SAM4CMS32C_0__) || defined(__ATSAM4CMS32C_0__) || \
		defined(__SAM4CMS32C_1__) || defined(__ATSAM4CMS32C_1__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			4cm32							//!< SAM family (4cm32) for name catenation
	#endif
	#define SAM4CM32											//!< SAM4CM32 family generic define

#elif	defined(__SAM4CP16B_0__) || defined(__ATSAM4CP16B_0__) || defined(__SAM4CP16B_1__) || defined(__ATSAM4CP16B_1__) || defined(__SAM4CP16C_0__) || defined(__ATSAM4CP16C_0__) || \
		defined(__SAM4CP16C_1__) || defined(__ATSAM4CP16C_1__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			4cp								//!< SAM family (4cp) for name catenation
	#endif
	#define SAM4CP												//!< SAM4CP family generic define

#elif	defined(__SAM4E16C__) || defined(__ATSAM4E16C__) || defined(__SAM4E16E__) || defined(__ATSAM4E16E__) || defined(__SAM4E8C__) || defined(__ATSAM4E8C__) ||	\
		defined(__SAM4E8E__) || defined(__ATSAM4E8E__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			4e								//!< SAM family (4e) for name catenation
	#endif
	#define SAM4E												//!< SAM4E family generic define

#elif	defined(__SAM4E16CB__) || defined(__ATSAM4E16CB__) || defined(__SAM4E8CB__) || defined(__ATSAM4E8CB__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			4ecb							//!< SAM family (4ecb) for name catenation
	#endif
	#define SAM4ECB												//!< SAM4ECB family generic define

#elif	defined(__SAM4LC2A__) || defined(__ATSAM4LC2A__) || defined(__SAM4LC2B__) || defined(__ATSAM4LC2B__) || defined(__SAM4LC2C__) || defined(__ATSAM4LC2C__) ||	\
		defined(__SAM4LC4A__) || defined(__ATSAM4LC4A__) || defined(__SAM4LC4B__) || defined(__ATSAM4LC4B__) || defined(__SAM4LC4C__) || defined(__ATSAM4LC4C__) ||	\
		defined(__SAM4LS2A__) || defined(__ATSAM4LS2A__) || defined(__SAM4LS2B__) || defined(__ATSAM4LS2B__) || defined(__SAM4LS2C__) || defined(__ATSAM4LS2C__) ||	\
		defined(__SAM4LS4A__) || defined(__ATSAM4LS4A__) || defined(__SAM4LS4B__) || defined(__ATSAM4LS4B__) || defined(__SAM4LS4C__) || defined(__ATSAM4LS4C__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			4l4								//!< SAM family (4l4) for name catenation
	#endif
	#define SAM4L4												//!< SAM4L4 family generic define

#elif	defined(__SAM4LC8A__) || defined(__ATSAM4LC8A__) || defined(__SAM4LC8B__) || defined(__ATSAM4LC8B__) || defined(__SAM4LC8C__) || defined(__ATSAM4LC8C__) ||	\
		defined(__SAM4LS8A__) || defined(__ATSAM4LS8A__) || defined(__SAM4LS8B__) || defined(__ATSAM4LS8B__) || defined(__SAM4LS8C__) || defined(__ATSAM4LS8C__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			4l8								//!< SAM family (4l8) for name catenation
	#endif
	#define SAM4L8												//!< SAM4L8 family generic define

#elif	defined(__SAM4N16B__) || defined(__ATSAM4N16B__) || defined(__SAM4N16C__) || defined(__ATSAM4N16C__) || defined(__SAM4N8A__) || defined(__ATSAM4N8A__) || \
		defined(__SAM4N8B__) || defined(__ATSAM4N8B__) || defined(__SAM4N8C__) || defined(__ATSAM4N8C__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			4n								//!< SAM family (4n) for name catenation
	#endif
	#define SAM4N												//!< SAM4N family generic define

#elif	defined(__SAM4S16B__) || defined(__ATSAM4S16B__) || defined(__SAM4S16C__) || defined(__ATSAM4S16C__) || defined(__SAM4S2A__) || defined(__ATSAM4S2A__) ||			\
		defined(__SAM4S2B__) || defined(__ATSAM4S2B__) || defined(__SAM4S2C__) || defined(__ATSAM4S2C__) || defined(__SAM4S4A__) || defined(__ATSAM4S4A__) ||				\
		defined(__SAM4S4B__) || defined(__ATSAM4S4B__) || defined(__SAM4S4C__) || defined(__ATSAM4S4C__) || defined(__SAM4S8B__) || defined(__ATSAM4S8B__) ||				\
		defined(__SAM4S8C__) || defined(__ATSAM4S8C__) || defined(__SAM4SA16B__) || defined(__ATSAM4SA16B__) || defined(__SAM4SA16C__) || defined(__ATSAM4SA16C__) ||		\
		defined(__SAM4SD16B__) || defined(__ATSAM4SD16B__) || defined(__SAM4SD16C__) || defined(__ATSAM4SD16C__) || defined(__SAM4SD32B__) || defined(__ATSAM4SD32B__) ||	\
		defined(__SAM4SD32C__) || defined(__ATSAM4SD32C__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			4s								//!< SAM family (4s) for name catenation
	#endif
	#define SAM4S												//!< SAM4S family generic define

#elif	defined(__SAM4SP32A__) || defined(__ATSAM4SP32A__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			4sp								//!< SAM family (4sp) for name catenation
	#endif
	#define SAM4SP												//!< SAM4SP family generic define

#elif	defined(__BTLC1000WLCSP__) || defined(__ATBTLC1000WLCSP__) || defined(__SAMB11G18A__) || defined(__ATSAMB11G18A__) || defined(__SAMB11ZR__) || defined(__ATSAMB11ZR__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			b11								//!< SAM family (b11) for name catenation
	#endif
	#define SAMB11												//!< SAMB11 family generic define

#elif	defined(__SAMC20E15A__) || defined(__ATSAMC20E15A__) || defined(__SAMC20E16A__) || defined(__ATSAMC20E16A__) || defined(__SAMC20E17A__) || defined(__ATSAMC20E17A__) ||		\
		defined(__SAMC20E18A__) || defined(__ATSAMC20E18A__) || defined(__SAMC20G15A__) || defined(__ATSAMC20G15A__) || defined(__SAMC20G16A__) || defined(__ATSAMC20G16A__) ||		\
		defined(__SAMC20G17A__) || defined(__ATSAMC20G17A__) || defined(__SAMC20G18A__) || defined(__ATSAMC20G18A__) || defined(__SAMC20J15A__) || defined(__ATSAMC20J15A__) ||		\
		defined(__SAMC20J16A__) || defined(__ATSAMC20J16A__) || defined(__SAMC20J17A__) || defined(__ATSAMC20J17A__) || defined(__SAMC20J17AU__) || defined(__ATSAMC20J17AU__) ||	\
		defined(__SAMC20J18A__) || defined(__ATSAMC20J18A__) || defined(__SAMC20J18AU__) || defined(__ATSAMC20J18AU__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			c20								//!< SAM family (c20) for name catenation
	#endif
	#define SAMC20												//!< SAMC20 family generic define

#elif	defined(__SAMC20N17A__) || defined(__ATSAMC20N17A__) ||	defined(__SAMC20N18A__) || defined(__ATSAMC20N18A__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			c20n							//!< SAM family (c20n) for name catenation
	#endif
	#define SAMC20N												//!< SAMC20N family generic define

#elif	defined(__SAMC21E15A__) || defined(__ATSAMC21E15A__) || defined(__SAMC21E16A__) || defined(__ATSAMC21E16A__) || defined(__SAMC21E17A__) || defined(__ATSAMC21E17A__) ||		\
		defined(__SAMC21E18A__) || defined(__ATSAMC21E18A__) ||	defined(__SAMC21G15A__) || defined(__ATSAMC21G15A__) || defined(__SAMC21G16A__) || defined(__ATSAMC21G16A__) ||		\
		defined(__SAMC21G17A__) || defined(__ATSAMC21G17A__) || defined(__SAMC21G18A__) || defined(__ATSAMC21G18A__) || defined(__SAMC21J15A__) || defined(__ATSAMC21J15A__) ||		\
		defined(__SAMC21J16A__) || defined(__ATSAMC21J16A__) || defined(__SAMC21J17A__) || defined(__ATSAMC21J17A__) || defined(__SAMC21J17AU__) || defined(__ATSAMC21J17AU__) ||	\
		defined(__SAMC21J18A__) || defined(__ATSAMC21J18A__) || defined(__SAMC21J18AU__) || defined(__ATSAMC21J18AU__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			c21								//!< SAM family (c21) for name catenation
	#endif
	#define SAMC21												//!< SAMC21 family generic define

#elif	defined(__SAMC21N17A__) || defined(__ATSAMC21N17A__) || defined(__SAMC21N18A__) || defined(__ATSAMC21N18A__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			c21n							//!< SAM family (c21n) for name catenation
	#endif
	#define SAMC21N												//!< SAMC21N family generic define

#elif	defined(__SAMD09C13A__) || defined(__ATSAMD09C13A__) || defined(__SAMD09D14A__) || defined(__ATSAMD09D14A__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			d09								//!< SAM family (d09) for name catenation
	#endif
	#define SAMD09												//!< SAMD09 family generic define

#elif	defined(__SAMD10C13A__) || defined(__ATSAMD10C13A__) || defined(__SAMD10C14A__) || defined(__ATSAMD10C14A__) || defined(__SAMD10D13AM__) || defined(__ATSAMD10D13AM__) ||		\
		defined(__SAMD10D13AS__) || defined(__ATSAMD10D13AS__) || defined(__SAMD10D14AM__) || defined(__ATSAMD10D14AM__) || defined(__SAMD10D14AS__) || defined(__ATSAMD10D14AS__) ||	\
		defined(__SAMD10D14AU__) || defined(__ATSAMD10D14AU__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			d10								//!< SAM family (d10) for name catenation
	#endif
	#define SAMD10												//!< SAMD10 family generic define

#elif	defined(__SAMD11C14A__) || defined(__ATSAMD11C14A__) || defined(__SAMD11D14AM__) || defined(__ATSAMD11D14AM__) || defined(__SAMD11D14AS__) || defined(__ATSAMD11D14AS__) || \
		defined(__SAMD11D14AU__) || defined(__ATSAMD11D14AU__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			d11								//!< SAM family (d11) for name catenation
	#endif
	#define SAMD11												//!< SAMD11 family generic define

#elif	defined(__SAMD20E14__) || defined(__ATSAMD20E14__) || defined(__SAMD20E15__) || defined(__ATSAMD20E15__) || defined(__SAMD20E16__) || defined(__ATSAMD20E16__) ||		\
		defined(__SAMD20E17__) || defined(__ATSAMD20E17__) || defined(__SAMD20E18__) || defined(__ATSAMD20E18__) || defined(__SAMD20G14__) || defined(__ATSAMD20G14__) ||		\
		defined(__SAMD20G15__) || defined(__ATSAMD20G15__) || defined(__SAMD20G16__) || defined(__ATSAMD20G16__) || defined(__SAMD20G17__) || defined(__ATSAMD20G17__) ||		\
		defined(__SAMD20G17U__) || defined(__ATSAMD20G17U__) || defined(__SAMD20G18__) || defined(__ATSAMD20G18__) || defined(__SAMD20G18U__) || defined(__ATSAMD20G18U__) ||	\
		defined(__SAMD20J14__) || defined(__ATSAMD20J14__) || defined(__SAMD20J15__) || defined(__ATSAMD20J15__) || defined(__SAMD20J16__) || defined(__ATSAMD20J16__) ||		\
		defined(__SAMD20J17__) || defined(__ATSAMD20J17__) || defined(__SAMD20J18__) || defined(__ATSAMD20J18__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			d20								//!< SAM family (d20) for name catenation
	#endif
	#define SAMD20												//!< SAMD20 family generic define

#elif	defined(__SAMD20E14B__) || defined(__ATSAMD20E14B__) || defined(__SAMD20E15B__) || defined(__ATSAMD20E15B__) || defined(__SAMD20E16B__) || defined(__ATSAMD20E16B__) || \
		defined(__SAMD20G14B__) || defined(__ATSAMD20G14B__) || defined(__SAMD20G15B__) || defined(__ATSAMD20G15B__) || defined(__SAMD20G16B__) || defined(__ATSAMD20G16B__) || \
		defined(__SAMD20J14B__) || defined(__ATSAMD20J14B__) ||	defined(__SAMD20J15B__) || defined(__ATSAMD20J15B__) || defined(__SAMD20J16B__) || defined(__ATSAMD20J16B__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			d20b							//!< SAM family (d20b) for name catenation
	#endif
	#define SAMD20B												//!< SAMD20B family generic define

#elif	defined(__SAMD21E15A__) || defined(__ATSAMD21E15A__) || defined(__SAMD21E16A__) || defined(__ATSAMD21E16A__) || defined(__SAMD21E17A__) || defined(__ATSAMD21E17A__) ||		\
		defined(__SAMD21E18A__) || defined(__ATSAMD21E18A__) || defined(__SAMD21G15A__) || defined(__ATSAMD21G15A__) || defined(__SAMD21G16A__) || defined(__ATSAMD21G16A__) ||		\
		defined(__SAMD21G17A__) || defined(__ATSAMD21G17A__) || defined(__SAMD21G17AU__) || defined(__ATSAMD21G17AU__) || defined(__SAMD21G18A__) || defined(__ATSAMD21G18A__) ||	\
		defined(__SAMD21G18AU__) || defined(__ATSAMD21G18AU__) || defined(__SAMD21J15A__) || defined(__ATSAMD21J15A__) || defined(__SAMD21J16A__) || defined(__ATSAMD21J16A__) ||	\
		defined(__SAMD21J17A__) || defined(__ATSAMD21J17A__) || defined(__SAMD21J18A__) || defined(__ATSAMD21J18A__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			d21a							//!< SAM family (d21a) for name catenation
	#endif
	#define SAMD21A												//!< SAMD21A family generic define

#elif	defined(__SAMD21E15BU__) || defined(__ATSAMD21E15BU__) || defined(__SAMD21E16BU__) || defined(__ATSAMD21E16BU__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			d21b							//!< SAM family (d21b) for name catenation
	#endif
	#define SAMD21B												//!< SAMD21B family generic define

#elif	defined(__SAMD21E15B__) || defined(__ATSAMD21E15B__) || defined(__SAMD21E15CU__) || defined(__ATSAMD21E15CU__) || defined(__SAMD21E15L__) || defined(__ATSAMD21E15L__) ||	\
		defined(__SAMD21E16B__) || defined(__ATSAMD21E16B__) || defined(__SAMD21E16CU__) || defined(__ATSAMD21E16CU__) || defined(__SAMD21E16L__) || defined(__ATSAMD21E16L__) ||	\
		defined(__SAMD21G15B__) || defined(__ATSAMD21G15B__) || defined(__SAMD21G15L__) || defined(__ATSAMD21G15L__) || defined(__SAMD21G16B__) || defined(__ATSAMD21G16B__) ||		\
		defined(__SAMD21G16L__) || defined(__ATSAMD21G16L__) || defined(__SAMD21J15B__) || defined(__ATSAMD21J15B__) ||	defined(__SAMD21J16B__) || defined(__ATSAMD21J16B__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			d21c							//!< SAM family (d21c) for name catenation
	#endif
	#define SAMD21C												//!< SAMD21C family generic define

#elif	defined(__SAMD51G18A__) || defined(__ATSAMD51G18A__) || defined(__SAMD51G19A__) || defined(__ATSAMD51G19A__) || defined(__SAMD51J18A__) || defined(__ATSAMD51J18A__) ||	\
		defined(__SAMD51J19A__) || defined(__ATSAMD51J19A__) || defined(__SAMD51J20A__) || defined(__ATSAMD51J20A__) || defined(__SAMD51N19A__) || defined(__ATSAMD51N19A__) ||	\
		defined(__SAMD51N20A__) || defined(__ATSAMD51N20A__) || defined(__SAMD51P19A__) || defined(__ATSAMD51P19A__) || defined(__SAMD51P20A__) || defined(__ATSAMD51P20A__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			d51								//!< SAM family (d51) for name catenation
	#endif
	#define SAMD51												//!< SAMD51 family generic define

#elif	defined(__SAMDA1E14A__) || defined(__ATSAMDA1E14A__) || defined(__SAMDA1E15A__) || defined(__ATSAMDA1E15A__) || defined(__SAMDA1E16A__) || defined(__ATSAMDA1E16A__) ||	\
		defined(__SAMDA1G14A__) || defined(__ATSAMDA1G14A__) || defined(__SAMDA1G15A__) || defined(__ATSAMDA1G15A__) || defined(__SAMDA1G16A__) || defined(__ATSAMDA1G16A__) ||	\
		defined(__SAMDA1J14A__) || defined(__ATSAMDA1J14A__) || defined(__SAMDA1J15A__) || defined(__ATSAMDA1J15A__) || defined(__SAMDA1J16A__) || defined(__ATSAMDA1J16A__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			da1								//!< SAM family (da1) for name catenation
	#endif
	#define SAMDA1												//!< SAMDA1 family generic define

#elif	defined(__SAMDA1E14B__) || defined(__ATSAMDA1E14B__) || defined(__SAMDA1E15B__) || defined(__ATSAMDA1E15B__) || defined(__SAMDA1E16B__) || defined(__ATSAMDA1E16B__) ||	\
		defined(__SAMDA1G14B__) || defined(__ATSAMDA1G14B__) || defined(__SAMDA1G15B__) || defined(__ATSAMDA1G15B__) || defined(__SAMDA1G16B__) || defined(__ATSAMDA1G16B__) ||	\
		defined(__SAMDA1J14B__) || defined(__ATSAMDA1J14B__) || defined(__SAMDA1J15B__) || defined(__ATSAMDA1J15B__) || defined(__SAMDA1J16B__) || defined(__ATSAMDA1J16B__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			da1b							//!< SAM family (da1b) for name catenation
	#endif
	#define SAMDA1B												//!< SAMDA1B family generic define

#elif	defined(__SAME51J18A__) || defined(__ATSAME51J18A__) || defined(__SAME51J19A__) || defined(__ATSAME51J19A__) || defined(__SAME51J20A__) || defined(__ATSAME51J20A__) || \
		defined(__SAME51N19A__) || defined(__ATSAME51N19A__) || defined(__SAME51N20A__) || defined(__ATSAME51N20A__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			e51								//!< SAM family (e51) for name catenation
	#endif
	#define SAME51												//!< SAME51 family generic define

#elif	defined(__SAME53J18A__) || defined(__ATSAME53J18A__) || defined(__SAME53J19A__) || defined(__ATSAME53J19A__) || defined(__SAME53J20A__) || defined(__ATSAME53J20A__) || \
		defined(__SAME53N19A__) || defined(__ATSAME53N19A__) || defined(__SAME53N20A__) || defined(__ATSAME53N20A__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			e53								//!< SAM family (e53) for name catenation
	#endif
	#define SAME53												//!< SAME53 family generic define

#elif	defined(__SAME54N19A__) || defined(__ATSAME54N19A__) || defined(__SAME54N20A__) || defined(__ATSAME54N20A__) || defined(__SAME54P19A__) || defined(__ATSAME54P19A__) || \
		defined(__SAME54P20A__) || defined(__ATSAME54P20A__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			e54								//!< SAM family (e54) for name catenation
	#endif
	#define SAME54												//!< SAME54 family generic define

#elif	defined(__SAME70J19__) || defined(__ATSAME70J19__) || defined(__SAME70J20__) || defined(__ATSAME70J20__) || defined(__SAME70J21__) || defined(__ATSAME70J21__) || \
		defined(__SAME70N19__) || defined(__ATSAME70N19__) || defined(__SAME70N20__) || defined(__ATSAME70N20__) || defined(__SAME70N21__) || defined(__ATSAME70N21__) || \
		defined(__SAME70Q19__) || defined(__ATSAME70Q19__) || defined(__SAME70Q20__) || defined(__ATSAME70Q20__) || defined(__SAME70Q21__) || defined(__ATSAME70Q21__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			e70a							//!< SAM family (e70a) for name catenation
	#endif
	#define SAME70A												//!< SAME70A family generic define

#elif	defined(__SAME70J19B__) || defined(__ATSAME70J19B__) || defined(__SAME70J20B__) || defined(__ATSAME70J20B__) || defined(__SAME70J21B__) || defined(__ATSAME70J21B__) ||	\
		defined(__SAME70N19B__) || defined(__ATSAME70N19B__) || defined(__SAME70N20B__) || defined(__ATSAME70N20B__) || defined(__SAME70N21B__) || defined(__ATSAME70N21B__) ||	\
		defined(__SAME70Q19B__) || defined(__ATSAME70Q19B__) || defined(__SAME70Q20B__) || defined(__ATSAME70Q20B__) || defined(__SAME70Q21B__) || defined(__ATSAME70Q21B__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			e70b							//!< SAM family (e70b) for name catenation
	#endif
	#define SAME70B												//!< SAME70B family generic define

#elif	defined(__SAMG51G18__) || defined(__ATSAMG51G18__) || defined(__SAMG51N18__) || defined(__ATSAMG51N18__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			g51								//!< SAM family (g51) for name catenation
	#endif
	#define SAMG51												//!< SAMG51 family generic define

#elif	defined(__SAMG53G19__) || defined(__ATSAMG53G19__) || defined(__SAMG53N19__) || defined(__ATSAMG53N19__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			g53								//!< SAM family (g53) for name catenation
	#endif
	#define SAMG53												//!< SAMG53 family generic define

#elif	defined(__SAMG54G19__) || defined(__ATSAMG54G19__) || defined(__SAMG54J19__) || defined(__ATSAMG54J19__) || defined(__SAMG54N19__) || defined(__ATSAMG54N19__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			g54								//!< SAM family (g54) for name catenation
	#endif
	#define SAMG54												//!< SAMG54 family generic define

#elif	defined(__SAMG55G19__) || defined(__ATSAMG55G19__) || defined(__SAMG55J19__) || defined(__ATSAMG55J19__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			g55								//!< SAM family (g55) for name catenation
	#endif
	#define SAMG55												//!< SAMG55 family generic define

#elif	defined(__SAMHA1G14A__) || defined(__ATSAMHA1G14A__) || defined(__SAMHA1G15A__) || defined(__ATSAMHA1G15A__) || defined(__SAMHA1G16A__) || defined(__ATSAMHA1G16A__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			ha1a							//!< SAM family (ha1a) for name catenation
	#endif
	#define SAMHA1A												//!< SAMHA1A family generic define

#elif	defined(__SAMHA1G14AB__) || defined(__ATSAMHA1G14AB__) || defined(__SAMHA1G15AB__) || defined(__ATSAMHA1G15AB__) || defined(__SAMHA1G16AB__) || defined(__ATSAMHA1G16AB__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			ha1ab							//!< SAM family (ha1ab) for name catenation
	#endif
	#define SAMHA1AB											//!< SAMHA1AB family generic define

#elif	defined(__SAML21E18A__) || defined(__ATSAML21E18A__) || defined(__SAML21G18A__) || defined(__ATSAML21G18A__) || defined(__SAML21J18A__) || defined(__ATSAML21J18A__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			l21a1							//!< SAM family (l21a1) for name catenation
	#endif
	#define SAML21A1											//!< SAML21A1 family generic define

#elif	defined(__SAML21E15B__) || defined(__ATSAML21E15B__) || defined(__SAML21E16B__) || defined(__ATSAML21E16B__) || defined(__SAML21E17B__) || defined(__ATSAML21E17B__) ||	\
		defined(__SAML21E18B__) || defined(__ATSAML21E18B__) || defined(__SAML21G16B__) || defined(__ATSAML21G16B__) || defined(__SAML21G17B__) || defined(__ATSAML21G17B__) ||	\
		defined(__SAML21G18B__) || defined(__ATSAML21G18B__) || defined(__SAML21J16B__) || defined(__ATSAML21J16B__) || defined(__SAML21J17B__) || defined(__ATSAML21J17B__) ||	\
		defined(__SAML21J18B__) || defined(__ATSAML21J18B__) || defined(__SAML21J18BU__) || defined(__ATSAML21J18BU__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			l21b							//!< SAM family (l21b) for name catenation
	#endif
	#define SAML21B												//!< SAML21B family generic define

#elif	defined(__SAML22G16A__) || defined(__ATSAML22G16A__) || defined(__SAML22G17A__) || defined(__ATSAML22G17A__) || defined(__SAML22G18A__) || defined(__ATSAML22G18A__) ||	\
		defined(__SAML22J16A__) || defined(__ATSAML22J16A__) || defined(__SAML22J17A__) || defined(__ATSAML22J17A__) || defined(__SAML22J18A__) || defined(__ATSAML22J18A__) ||	\
		defined(__SAML22N16A__) || defined(__ATSAML22N16A__) || defined(__SAML22N17A__) || defined(__ATSAML22N17A__) || defined(__SAML22N18A__) || defined(__ATSAML22N18A__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			l22								//!< SAM family (l22) for name catenation
	#endif
	#define SAML22												//!< SAML22 family generic define

#elif	defined(__SAMR21E16A__) || defined(__ATSAMR21E16A__) || defined(__SAMR21E17A__) || defined(__ATSAMR21E17A__) || defined(__SAMR21E18A__) || defined(__ATSAMR21E18A__) ||	\
		defined(__SAMR21E19A__) || defined(__ATSAMR21E19A__) || defined(__SAMR21G16A__) || defined(__ATSAMR21G16A__) || defined(__SAMR21G17A__) || defined(__ATSAMR21G17A__) ||	\
		defined(__SAMR21G18A__) || defined(__ATSAMR21G18A__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			r21								//!< SAM family (r21) for name catenation
	#endif
	#define SAMR21												//!< SAMR21 family generic define

#elif	defined(__SAMR30E18A__) || defined(__ATSAMR30E18A__) || defined(__SAMR30G18A__) || defined(__ATSAMR30G18A__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			r30								//!< SAM family (r30) for name catenation
	#endif
	#define SAMR30												//!< SAMR30 family generic define

#elif	defined(__SAMS70J19__) || defined(__ATSAMS70J19__) || defined(__SAMS70J20__) || defined(__ATSAMS70J20__) || defined(__SAMS70J21__) || defined(__ATSAMS70J21__) || \
		defined(__SAMS70N19__) || defined(__ATSAMS70N19__) || defined(__SAMS70N20__) || defined(__ATSAMS70N20__) || defined(__SAMS70N21__) || defined(__ATSAMS70N21__) || \
		defined(__SAMS70Q19__) || defined(__ATSAMS70Q19__) || defined(__SAMS70Q20__) || defined(__ATSAMS70Q20__) || defined(__SAMS70Q21__) || defined(__ATSAMS70Q21__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			s70a							//!< SAM family (s70a) for name catenation
	#endif
	#define SAMS70A												//!< SAMS70A family generic define

#elif	defined(__SAMS70J19B__) || defined(__ATSAMS70J19B__) || defined(__SAMS70J20B__) || defined(__ATSAMS70J20B__) || defined(__SAMS70J21B__) || defined(__ATSAMS70J21B__) ||	\
		defined(__SAMS70N19B__) || defined(__ATSAMS70N19B__) || defined(__SAMS70N20B__) || defined(__ATSAMS70N20B__) || defined(__SAMS70N21B__) || defined(__ATSAMS70N21B__) ||	\
		defined(__SAMS70Q19B__) || defined(__ATSAMS70Q19B__) || defined(__SAMS70Q20B__) || defined(__ATSAMS70Q20B__) || defined(__SAMS70Q21B__) || defined(__ATSAMS70Q21B__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			s70b							//!< SAM family (s70b) for name catenation
	#endif
	#define SAMS70B												//!< SAMS70B family generic define

#elif	defined(__SAMV70J19__) || defined(__ATSAMV70J19__) || defined(__SAMV70J20__) || defined(__ATSAMV70J20__) || defined(__SAMV70N19__) || defined(__ATSAMV70N19__) || \
		defined(__SAMV70N20__) || defined(__ATSAMV70N20__) || defined(__SAMV70Q19__) || defined(__ATSAMV70Q19__) || defined(__SAMV70Q20__) || defined(__ATSAMV70Q20__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			v70								//!< SAM family (v70) for name catenation
	#endif
	#define SAMV70												//!< SAMV70 family generic define

#elif	defined(__SAMV70J19B__) || defined(__ATSAMV70J19B__) || defined(__SAMV70J20B__) || defined(__ATSAMV70J20B__) || defined(__SAMV70N19B__) || defined(__ATSAMV70N19B__) ||	\
		defined(__SAMV70N20B__) || defined(__ATSAMV70N20B__) || defined(__SAMV70Q19B__) || defined(__ATSAMV70Q19B__) || defined(__SAMV70Q20B__) || defined(__ATSAMV70Q20B__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			v70b							//!< SAM family (v70b) for name catenation
	#endif
	#define SAMV70B												//!< SAMV70B family generic define

#elif	defined(__SAMV71J19__) || defined(__ATSAMV71J19__) || defined(__SAMV71J20__) || defined(__ATSAMV71J20__) || defined(__SAMV71J21__) || defined(__ATSAMV71J21__) || \
		defined(__SAMV71N19__) || defined(__ATSAMV71N19__) || defined(__SAMV71N20__) || defined(__ATSAMV71N20__) || defined(__SAMV71N21__) || defined(__ATSAMV71N21__) || \
		defined(__SAMV71Q19__) || defined(__ATSAMV71Q19__) || defined(__SAMV71Q20__) || defined(__ATSAMV71Q20__) || defined(__SAMV71Q21__) || defined(__ATSAMV71Q21__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			v71								//!< SAM family (v71) for name catenation
	#endif
	#define SAMV71												//!< SAMV71 family generic define

#elif	defined(__SAMV71J19B__) || defined(__ATSAMV71J19B__) || defined(__SAMV71J20B__) || defined(__ATSAMV71J20B__) || defined(__SAMV71J21B__) || defined(__ATSAMV71J21B__) ||	\
		defined(__SAMV71N19B__) || defined(__ATSAMV71N19B__) || defined(__SAMV71N20B__) || defined(__ATSAMV71N20B__) || defined(__SAMV71N21B__) || defined(__ATSAMV71N21B__) ||	\
		defined(__SAMV71Q19B__) || defined(__ATSAMV71Q19B__) || defined(__SAMV71Q20B__) || defined(__ATSAMV71Q20B__) || defined(__SAMV71Q21B__) || defined(__ATSAMV71Q21B__)
	#if !defined(SAM_FAMILY)
	#define SAM_FAMILY			v71b							//!< SAM family (v71b) for name catenation
	#endif
	#define SAMV71B												//!< SAMV71B family generic define

/******************************/
/*** Microchip PIC Families ***/
/******************************/
#elif	defined(__XC__)
	#if defined(__XC32)
		#if !defined(PIC_FAMILY)
		#define PIC_FAMILY		pic32							//!< PIC family (pic32) for name catenation?
		#endif
		#define PIC32											//!< PIC32 platform generic define

	#elif defined(__XC16)
		#if !defined(PIC_FAMILY)
		#define PIC_FAMILY		pic16							//!< PIC family (pic16) for name catenation?
		#endif
		#define PIC16											//!< PIC16 platform generic define

	#elif defined(__XC8)
		#if !defined(PIC_FAMILY)
		#define PIC_FAMILY		pic8							//!< PIC family (pic8) for name catenation?
		#endif
		#define PIC8											//!< PIC8 platform generic define

	#else
		#if !defined(PIC_FAMILY)
		#define PIC_FAMILY		pic								//!< PIC family (pic) for name catenation?
		#endif
		#define PIC												//!< PIC platform generic define

	#endif

/**********************/
/*** Other Families ***/
/**********************/
/* #elif	XXX_FAMILIES
	#if !defined(XXX_FAMILY)
	#define XXX_FAMILY			xx								//!< XXX family (xx) for name catenation
	#endif
	#define XXXxxxx												//!< XXXxxxx family generic define
*/
#elif !defined(INO_FAMILY) && !defined(STM_FAMILY) && !defined(SAM_FAMILY) && !defined(PIC_FAMILY)
	#error "You should add the CMSIS base include following chip used & comment this error."
	#error "If working with STM32 and chip is not in the list, try add STM_FAMILY=(c/f/h/l/mp/u/wb/wl)x in project defines."
	#error "If working with ATMEL SAM and chip is not in the list, try add SAM_FAMILY=(b/c/d/e/g/h/l/r/s/v)xx in project defines."
#endif


#if defined(INO_FAMILY)
	/*** Defines for Arduino platform ***/
	#include "arm_chip_ino.h"

#elif defined(PIC_FAMILY)
	/*** Defines for Microchip PIC families ***/
	#include "arm_chip_pic.h"

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

#endif /* SARMFSW_NO_CHIP_HAL */


/*** arm_inlines_ticks.h needs a generic definition of HALTicks & HAL_MS_TICKS_FACTOR ***/
//!\MISRA Local derogation authorized for:\n
//! \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
//! \a Justification: \p func paramater shall be a function name; raising error otherwise is intended.\n
// cppcheck-suppress-macro misra-c2012-20.7
#define HALTICKS_PROTOTYPE(func)	uint32_t func(void)		//!< External definition of Ticks getter that shall be implemented in project

// In case chip headers don't include specific HALTicks symbol, define generic one and its external prototype
#ifndef HALTicks
HALTICKS_PROTOTYPE(HAL_GetTick);	//!< External definition of HAL_GetTick that shall be defined in project
#define HALTicks	HAL_GetTick		//!< Alias for HAL get ticks function
#else
HALTICKS_PROTOTYPE(HALTicks);		//!< External definition of Ticks getter to check for prototype validity
#endif

#ifndef HAL_MS_TICKS_FACTOR
#define HAL_MS_TICKS_FACTOR	1U		//!< HAL milliseconds multiplier (depending tick counter frequency)
#endif


/* IO definitions (access restrictions to peripheral registers) */
#ifndef __I
#ifdef __cplusplus
#define __I			volatile		//!< Defines 'read only' permissions
#else
#define __I			volatile const	//!< Defines 'read only' permissions
#endif
#endif

#ifndef __O
#define __O			volatile		//!< Defines 'write only' permissions
#endif

#ifndef __IO
#define __IO		volatile		//!< Defines 'read / write' permissions
#endif

/* following defines should be used for structure members */
#ifndef __IM
#define __IM		volatile const	//!< Defines 'read only' structure member permissions
#endif

#ifndef __OM
#define __OM		volatile		//!< Defines 'write only' structure member permissions
#endif

#ifndef __IOM
#define __IOM		volatile		//!< Defines 'read / write' structure member permissions
#endif


#ifndef UNUSED
#define UNUSED(X)	(void) (X)		//!< Unused parameter \p X (to avoid gcc/g++ warnings)
#endif

#ifndef UNUSED_RET
#define UNUSED_RET	(void)			//!< Explicitly ignore function return (MISRA compliance)
#endif


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_CMSIS_H_ */
// cppcheck-suppress-end [misra-c2012-21.1]
/****************************************************************/
