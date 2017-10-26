/*!\file arm_attributes.h
** \author SMFSW
** \date 2017
** \copyright MIT (c) 2017, SMFSW
** \brief ARM common compilers attributes
*/
/****************************************************************/
#ifndef __ARM_ATTRIBUTES_H
	#define __ARM_ATTRIBUTES_H
/****************************************************************/


#if   defined ( __CC_ARM )

#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)

#elif defined ( __GNUC__ )
	// Usually declared at the beginning of the line
	#define __WEAK			__attribute__((weak))			//!< \b Weak attribute for gcc

	// Usually declared after name
	#define INLINE__		__attribute__((always_inline))	//!< \b Inline attribute for gcc
	#define PACK__			__attribute__((__packed__))		//!< \b Packed attribute for gcc

#elif defined ( __ICCARM__ )

#elif defined ( __TMS470__ )

#elif defined ( __TASKING__ )

#elif defined ( __CSMC__ )

#else
  #error Unknown compiler
#endif


/****************************************************************/
#endif /* __ARM_ATTRIBUTES_H */
/****************************************************************/
