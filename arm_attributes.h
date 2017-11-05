/*!\file arm_attributes.h
** \author SMFSW
** \date 2017
** \copyright MIT (c) 2017, SMFSW
** \brief ARM common compilers attributes
*/
/****************************************************************/
#ifndef __ARM_ATTRIBUTES_H
	#define __ARM_ATTRIBUTES_H

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


#if defined (__CC_ARM)
	/*** ARM REAL VIEW ***/
	// Declared as qualifier
	#define __WEAK			__weak								//!< \b Weak attribute
	#define __IRQ			__irq								//!< \b Interrupt attribute
	// Declared as attribute
	#define ALIGN__(n)		__attribute__((align(n)))			//!< \b Align attribute padded to \b n
	#define COLD__
	#define DEPRECATED__	__attribute__((deprecated))			//!< \b Deprecated attribute
	#define HOT__
	#define INLINE__		__attribute__((always_inline))		//!< \b Always inline attribute
	#define NONNULL__
	#define NORETURN__		__attribute__((noreturn))			//!< \b No return attribute
	#define PACK__			__attribute__((packed))				//!< \b Packed attribute
	#define PURE__			__attribute__((pure))				//!< \b Pure attribute

#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
	/*** ARM COMPILER TOOLCHAIN ***/
	// Declared as qualifier
	#define __WEAK			__weak								//!< \b Weak attribute
	#define __IRQ			__irq								//!< \b Interrupt attribute
	// Declared as attribute
	#define ALIGN__(n)		__attribute__((align(n)))			//!< \b Align attribute padded to \b n
	#define COLD__
	#define DEPRECATED__	__attribute__((deprecated))			//!< \b Deprecated attribute
	#define HOT__
	#define INLINE__		__attribute__((always_inline))		//!< \b Always inline attribute
	#define NONNULL__		__attribute__((nonnull))			//!< \b Non null attribute (all pointers will be checked)
	#define NORETURN__		__attribute__((noreturn))			//!< \b No return attribute
	#define PACK__			__attribute__((packed))				//!< \b Packed attribute
	#define PURE__			__attribute__((pure))				//!< \b Pure attribute

#elif defined (__GNUC__)
	/*** GCC ***/
	// Declared as qualifier
	#define __WEAK			__attribute__((weak))				//!< \b Weak attribute
	#define __IRQ			__attribute__((interrupt_handler))	//!< \b Interrupt attribute
	// Declared as attribute
	#define ALIGN__(n)		__attribute__((align(n)))			//!< \b Align attribute padded to \b n
	#define COLD__			__attribute__((cold))				//!< \b Cold attribute
	#define DEPRECATED__	__attribute__((deprecated))			//!< \b Deprecated attribute
	#define HOT__			__attribute__((hot))				//!< \b Hot attribute
	#define INLINE__		__attribute__((always_inline))		//!< \b Always inline attribute
	#define NONNULL__		__attribute__((nonnull))			//!< \b Non null attribute (all pointers will be checked)
	#define NORETURN__		__attribute__((noreturn))			//!< \b No return attribute
	#define PACK__			__attribute__((__packed__))			//!< \b Packed attribute
	#define PURE__			__attribute__((pure))				//!< \b Pure attribute

#elif defined (__ICCARM__)
	/*** IAR ***/
	// Declared as qualifier
	#define __WEAK			__weak								//!< \b Weak attribute
	#define __IRQ			__irq								//!< \b Interrupt attribute
	// Declared as attribute
	#define ALIGN__(n)		__attribute__((align(n)))			//!< \b Align attribute padded to \b n
	#define COLD__
	#define DEPRECATED__
	#define HOT__
	#define INLINE__
	#define NONNULL__
	#define NORETURN__		__noreturn							//!< \b No return attribute
	#define PACK__			__packed							//!< \b Packed attribute
	#define PURE__

#elif defined (__TMS470__)
	/*** TEXAS INSTRUMENTS ***/
	// Declared as qualifier
	#define __WEAK												//!< \b Weak attribute only through #pragma weak(symbol)
	#define __IRQ			__interrupt							//!< \b Interrupt attribute
	// Declared as attribute
	#define ALIGN__(n)											//!< \b Align attribute only through #pragma DATA_ALIGN(symbol, constant)
	#define COLD__
	#define DEPRECATED__	__attribute__((deprecated))			//!< \b Deprecated attribute
	#define HOT__
	#define INLINE__		__attribute__((always_inline))		//!< \b Always inline attribute
	#define NONNULL__
	#define NORETURN__		__attribute__((noreturn))			//!< \b No return attribute
	#define PACK__			__attribute__((__packed__))			//!< \b Packed attribute
	#define PURE__			__attribute__((pure))				//!< \b Pure attribute

#elif defined (__TASKING__)
	/*** TASKING ***/
	// Declared as qualifier
	#define __WEAK			__attribute__((weak))				//!< \b Weak attribute
	#define __IRQ			__interrupt_irq						//!< \b Interrupt attribute
	// Declared as attribute
	#define ALIGN__(n)		__align(n)							//!< \b Align attribute padded to \b n
	#define COLD__
	#define DEPRECATED__
	#define HOT__
	#define INLINE__		__attribute__((always_inline))		//!< \b Always inline attribute
	#define NONNULL__
	#define NORETURN__		__attribute__((noreturn))			//!< \b No return attribute
	#define PACK__			__packed__							//!< \b Packed attribute
	#define PURE__			__attribute__((pure))				//!< \b Pure attribute

#elif defined (__CSMC__)
	/*** COSMIC ***/
	#error No attribute defined yet for Cosmic compiler.

#else
	#error Unknown compiler. Attributes will not be recognized.
#endif


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_ATTRIBUTES_H */
/****************************************************************/
