/*!\file arm_attributes.h
** \author SMFSW
** \copyright MIT (c) 2017-2022, SMFSW
** \brief ARM common compilers attributes
** \details Set attributes following compiler
** \warning Cosmic compiler for STM32 attributes not implemented
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
	#define __WEAK				__weak									//!< \b Weak attribute
	#define __IRQ				__irq									//!< \b Interrupt attribute
	// Declared as attribute
	#define ATTR__(...)			__attribute__((__VA_ARGS__))			//!< Macro to define one or multiple attribute(s) \b ... for a declaration

	#define ALIGN__(n)			__attribute__((align(n)))				//!< \b Align attribute padded to \b n
	#define COLD__
	#define DEPRECATED__		__attribute__((deprecated))				//!< \b Deprecated attribute
	#define HOT__
	#define INLINE__			__attribute__((always_inline))			//!< \b Always \b inline attribute
	#define NONNULL__
	#define NONNULLX__(...)
	#define NORETURN__			__attribute__((noreturn))				//!< \b No \b return attribute
	#define PACK__				__attribute__((packed))					//!< \b Packed attribute
	#define PURE__				__attribute__((pure))					//!< \b Pure attribute
	#define SECTION__(s)		__attribute__((section(#s)))			//!< \b Section attribute to place declaration into section \b s
	#define USED__				__attribute__((used))					//!< \b Used attribute ensures declaration won't be removed by garbage collector
	// Common mixed attributes
	#define NONNULL_INLINE__	ATTR__(nonnull, always_inline)			//!< \b Non-null and \b Always \b inline attributes

	#if (!defined(__OPTIMIZE__))
	#define __NOOPT__													//!< \b No \b Optimizations attribute
	#endif

#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
	/*** ARM COMPILER TOOLCHAIN ***/
	// Declared as qualifier
	#define __WEAK				__weak									//!< \b Weak attribute
	#define __IRQ				__irq									//!< \b Interrupt attribute
	// Declared as attribute
	#define ATTR__(...)			__attribute__((__VA_ARGS__))			//!< Macro to define one or multiple attribute(s) \b ... for a declaration

	#define ALIGN__(n)			__attribute__((align(n)))				//!< \b Align attribute padded to \b n
	#define COLD__
	#define DEPRECATED__		__attribute__((deprecated))				//!< \b Deprecated attribute
	#define HOT__
	#define INLINE__			__attribute__((always_inline))			//!< \b Always \b inline attribute
	#define NONNULL__			__attribute__((nonnull))				//!< \b Non \b null attribute (all pointers will be checked)
	#define NONNULLX__(...)		__attribute__((nonnull(__VA_ARGS__)))	//!< \b Non \b null attribute for \b ... pointers indexes
	#define NORETURN__			__attribute__((noreturn))				//!< \b No \b return attribute
	#define PACK__				__attribute__((packed))					//!< \b Packed attribute
	#define PURE__				__attribute__((pure))					//!< \b Pure attribute
	#define SECTION__(s)		__attribute__((section(#s)))			//!< \b Section attribute to place declaration into section \b s
	#define USED__				__attribute__((used))					//!< \b Used attribute ensures declaration won't be removed by garbage collector
	// Common mixed attributes
	#define NONNULL_INLINE__	ATTR__(nonnull, always_inline)			//!< \b Non-null and \b Always \b inline attributes

	#if (!defined(__OPTIMIZE__))
	#define __NOOPT__													//!< \b No \b Optimizations attribute
	#endif

#elif defined (__XC__)	// Defined prior to __GNUC__ as also defined for some __XC__ compilers
	/*** Microchip XC ***/
	// Declared as qualifier
	#define __WEAK				__attribute__((weak))					//!< \b Weak attribute
	#define __IRQ				__attribute__((__interrupt__))			//!< \b Interrupt attribute
	// Declared as attribute
	#define ATTR__(...)			__attribute__((__VA_ARGS__))			//!< Macro to define one or multiple attribute(s) \b ... for a declaration

	#define ALIGN__(n)			__attribute__((aligned (n)))			//!< \b Align attribute padded to \b n
	#define COLD__
	#define DEPRECATED__		__attribute__((deprecated))				//!< \b Deprecated attribute
	#define HOT__
	#define INLINE__			__attribute__((__always_inline__))		//!< \b Always \b inline attribute
	#define NONNULL__
	#define NONNULLX__(...)
	#define NORETURN__
	#define PACK__				__attribute__((__packed__))				//!< \b Packed attribute
	#define PURE__
	#define SECTION__(s)		__attribute__((section(#s)))			//!< \b Section attribute to place declaration into section \b s
	#define USED__
	// Common mixed attributes
	#define NONNULL_INLINE__	__attribute__((__always_inline__))		//!< \b Always \b inline attribute

	#if (!defined(__OPTIMIZE__))
	#define __NOOPT__													//!< \b No \b Optimizations attribute
	#endif

#elif defined (__GNUC__)
	/*** GCC ***/
	// Declared as qualifier
	#define __WEAK				__attribute__((weak))					//!< \b Weak attribute
	#define __IRQ				__attribute__((interrupt_handler))		//!< \b Interrupt attribute
	// Declared as attribute
	#define ATTR__(...)			__attribute__((__VA_ARGS__))			//!< Macro to define one or multiple attribute(s) \b ... for a declaration

	#define ALIGN__(n)			__attribute__((align(n)))				//!< \b Align attribute padded to \b n
	#define COLD__				__attribute__((cold))					//!< \b Cold attribute
	#define DEPRECATED__		__attribute__((deprecated))				//!< \b Deprecated attribute
	#define HOT__				__attribute__((hot))					//!< \b Hot attribute
	#define INLINE__			__attribute__((always_inline))			//!< \b Always \b inline attribute
	#define NONNULL__			__attribute__((nonnull))				//!< \b Non \b null attribute (all pointers will be checked)
	#define NONNULLX__(...)		__attribute__((nonnull(__VA_ARGS__)))	//!< \b Non \b null attribute for \b ... pointers indexes
	#define NORETURN__			__attribute__((noreturn))				//!< \b No \b return attribute
	#define PACK__				__attribute__((__packed__))				//!< \b Packed attribute
	#define PURE__				__attribute__((pure))					//!< \b Pure attribute
	#define SECTION__(s)		__attribute__((section(#s)))			//!< \b Section attribute to place declaration into section \b s
	#define USED__				__attribute__((used))					//!< \b Used attribute ensures declaration won't be removed by garbage collector
	// Common mixed attributes
	#define NONNULL_INLINE__	ATTR__(nonnull, always_inline)			//!< \b Non-null and \b Always \b inline attributes

	#if (!defined(__OPTIMIZE__))
	#define __NOOPT__													//!< \b No \b Optimizations attribute
	#endif

#elif defined (__ICCARM__)
	/*** IAR ***/
	// Declared as qualifier
	#define __WEAK				__weak									//!< \b Weak attribute
	#define __IRQ				__irq									//!< \b Interrupt attribute
	// Declared as attribute
	#define ATTR__(...)			__attribute__((__VA_ARGS__))			//!< Macro to define one or multiple attribute(s) \b ... for a declaration

	#define ALIGN__(n)			__attribute__((align(n)))				//!< \b Align attribute padded to \b n
	#define COLD__
	#define DEPRECATED__
	#define HOT__
	#define INLINE__
	#define NONNULL__
	#define NONNULLX__(...)
	#define NORETURN__			__noreturn								//!< \b No \b return attribute
	#define PACK__				__packed								//!< \b Packed attribute
	#define PURE__
	#define SECTION__(s)
	#define USED__
	// Common mixed attributes
	#define NONNULL_INLINE__

	//#define __NOOPT__													//!< \b No \b Optimizations attribute not identified on IAR toolchain

#elif defined (__TMS470__)
	/*** TEXAS INSTRUMENTS ***/
	// Declared as qualifier
	#define __WEAK														//!< \b Weak attribute only through #pragma weak(symbol)
	#define __IRQ				__interrupt								//!< \b Interrupt attribute
	// Declared as attribute
	#define ATTR__(...)			__attribute__((__VA_ARGS__))			//!< Macro to define one or multiple attribute(s) \b ... for a declaration

	#define ALIGN__(n)
	#define COLD__
	#define DEPRECATED__		__attribute__((deprecated))				//!< \b Deprecated attribute
	#define HOT__
	#define INLINE__			__attribute__((always_inline))			//!< \b Always \b inline attribute
	#define NONNULL__
	#define NONNULLX__(...)
	#define NORETURN__			__attribute__((noreturn))				//!< \b No \b return attribute
	#define PACK__				__attribute__((__packed__))				//!< \b Packed attribute
	#define PURE__				__attribute__((pure))					//!< \b Pure attribute
	#define SECTION__(s)		__attribute__((section(#s)))			//!< \b Section attribute to place declaration into section \b s
	#define USED__				__attribute__((used))					//!< \b Used attribute ensures declaration won't be removed by garbage collector
	// Common mixed attributes
	#define NONNULL_INLINE__	__attribute__((always_inline))			//!< \b Always \b inline attribute

	//#define __NOOPT__													//!< \b No \b Optimizations attribute not identified on TI toolchain

#elif defined (__TASKING__)
	/*** TASKING ***/
	// Declared as qualifier
	#define __WEAK				__attribute__((weak))					//!< \b Weak attribute
	#define __IRQ				__interrupt_irq							//!< \b Interrupt attribute
	// Declared as attribute
	#define ATTR__(...)			__attribute__((__VA_ARGS__))			//!< Macro to define one or multiple attribute(s) \b ... for a declaration

	#define ALIGN__(n)			__align(n)								//!< \b Align attribute padded to \b n
	#define COLD__
	#define DEPRECATED__
	#define HOT__
	#define INLINE__			__attribute__((always_inline))			//!< \b Always \b inline attribute
	#define NONNULL__
	#define NONNULLX__(...)
	#define NORETURN__			__attribute__((noreturn))				//!< \b No \b return attribute
	#define PACK__				__packed__								//!< \b Packed attribute
	#define PURE__				__attribute__((pure))					//!< \b Pure attribute
	#define SECTION__(s)		__attribute__((section(#s)))			//!< \b Section attribute to place declaration into section \b s
	#define USED__				__attribute__((used))					//!< \b Used attribute ensures declaration won't be removed by garbage collector
	// Common mixed attributes
	#define NONNULL_INLINE__	__attribute__((always_inline))			//!< \b Always \b inline attribute

	//#define __NOOPT__													//!< \b No \b Optimizations attribute not identified on TASKING toolchain

#elif defined (__CSMC__)
	/*** COSMIC ***/
	#error No attribute defined yet with Cosmic compiler.

#else
	#error Unknown compiler. Attributes will not be recognized.
#endif


#ifndef __INLINE
#define __INLINE			inline				//!< \b Inline attribute alias
#endif
#ifndef __STATIC_INLINE
#define __STATIC_INLINE		static inline		//!< \b Static \b Inline attribute alias
#endif

/*** INLINES WORKAROUND WHEN OPTIMIZATION LEVEL SET TO NONE (GCC like toolchains) ***/
#if defined(__NOOPT__)
#undef __INLINE
#undef __STATIC_INLINE

#ifdef __STATIC_FORCEINLINE
#define __INLINE			__STATIC_FORCEINLINE							//!< \b Inline attribute alias when `__NOOPT__` defined
#define __STATIC_INLINE		__STATIC_FORCEINLINE							//!< \b Static \b Inline attribute alias when `__NOOPT__` defined
#else
#define __INLINE			__attribute__((always_inline)) static inline	//!< \b Inline attribute alias when `__NOOPT__` defined
#define __STATIC_INLINE		__attribute__((always_inline)) static inline	//!< \b Static \b Inline attribute alias when `__NOOPT__` defined
#endif
#endif


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_ATTRIBUTES_H */
/****************************************************************/
