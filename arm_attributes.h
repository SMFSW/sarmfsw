/*!\file arm_attributes.h
** \author SMFSW
** \copyright MIT (c) 2017-2024, SMFSW
** \brief ARM common compilers attributes
** \details Set attributes following compiler
** \warning Cosmic compiler for STM32 attributes not implemented
** \MISRA Header scope deviation has been granted for following rules:\n
** 	\b Rule-20.5 - \b Advisory: \c \#undef (misra-c2012-20.5)\n
** 	\b Rule-20.10 - \b Advisory: \c # and \c ## preprocessor operators (misra-c2012-20.10)\n
** \MISRA Header scope legitimate use derogation authorized for:\n
** 	\b Rule-21.1 - \b Required: \c \#define and \c \#undef on reserved identifiers (misra-c2012-21.1)\n
**	\a Justification: \c \#define are generic reserved identifiers for attributes.\n
*/
// cppcheck-suppress-begin [misra-c2012-20.5, misra-c2012-20.10]
// cppcheck-suppress-begin [misra-c2012-21.1]
/****************************************************************/
#ifndef ARM_ATTRIBUTES_H_
	#define ARM_ATTRIBUTES_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


#if defined (__CC_ARM)
	/*** ARM REAL VIEW ***/
	// Declared as qualifier
	#define __WEAK				__weak									//!< Weak attribute
	#define __IRQ				__irq									//!< Interrupt attribute
	// Declared as attribute
	#define ATTR__(...)			__attribute__((__VA_ARGS__))			//!< Macro to define one or multiple attribute(s) \p ... for a declaration

	#define ALIGN__(n)			__attribute__((align(n)))				//!< Align attribute padded to \p n
	#define COLD__
	#define DEPRECATED__		__attribute__((deprecated))				//!< Deprecated attribute
	#define HOT__
	#define INLINE__			__attribute__((always_inline))			//!< Always \c inline attribute
	#define NONNULL__
	#define NONNULLX__(...)
	#define NORETURN__			__attribute__((noreturn))				//!< No \c return attribute
	#define PACK__				__attribute__((packed))					//!< Packed attribute
	#define PURE__				__attribute__((pure))					//!< Pure attribute
	#define SECTION__(s)		__attribute__((section(#s)))			//!< Section attribute to place declaration into section \p s
	#define USED__				__attribute__((used))					//!< Used attribute ensures declaration won't be removed by garbage collector
	// Common mixed attributes
	#define NONNULL_INLINE__	ATTR__(nonnull, always_inline)			//!< Non \c null and Always \c inline attributes

	#if (!defined(__OPTIMIZE__))
	#define __NOOPT__													//!< No Optimizations attribute
	#endif

#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
	/*** ARM COMPILER TOOLCHAIN ***/
	// Declared as qualifier
	#define __WEAK				__weak									//!< Weak attribute
	#define __IRQ				__irq									//!< Interrupt attribute
	// Declared as attribute
	#define ATTR__(...)			__attribute__((__VA_ARGS__))			//!< Macro to define one or multiple attribute(s) \p ... for a declaration

	#define ALIGN__(n)			__attribute__((align(n)))				//!< Align attribute padded to \p n
	#define COLD__
	#define DEPRECATED__		__attribute__((deprecated))				//!< Deprecated attribute
	#define HOT__
	#define INLINE__			__attribute__((always_inline))			//!< Always \c inline attribute
	#define NONNULL__			__attribute__((nonnull))				//!< Non \c null attribute (all pointers will be checked)
	#define NONNULLX__(...)		__attribute__((nonnull(__VA_ARGS__)))	//!< Non \c null attribute for \p ... pointers indexes
	#define NORETURN__			__attribute__((noreturn))				//!< No \c return attribute
	#define PACK__				__attribute__((packed))					//!< Packed attribute
	#define PURE__				__attribute__((pure))					//!< Pure attribute
	#define SECTION__(s)		__attribute__((section(#s)))			//!< Section attribute to place declaration into section \p s
	#define USED__				__attribute__((used))					//!< Used attribute ensures declaration won't be removed by garbage collector
	// Common mixed attributes
	#define NONNULL_INLINE__	ATTR__(nonnull, always_inline)			//!< Non \c null and Always \c inline attributes

	#if (!defined(__OPTIMIZE__))
	#define __NOOPT__													//!< No Optimizations attribute
	#endif

#elif defined (__XC__)	// Defined prior to __GNUC__ as also defined for some __XC__ compilers
	/*** Microchip XC ***/
	// Declared as qualifier
	#define __WEAK				__attribute__((weak))					//!< Weak attribute
	#define __IRQ				__attribute__((interrupt))  			//!< Interrupt attribute
	// Declared as attribute
	#define ATTR__(...)			__attribute__((__VA_ARGS__))			//!< Macro to define one or multiple attribute(s) \p ... for a declaration

	#define ALIGN__(n)			__attribute__((aligned (n)))			//!< Align attribute padded to \p n
	#define COLD__
	#define DEPRECATED__		__attribute__((deprecated))				//!< Deprecated attribute
	#define HOT__
	#define INLINE__			__attribute__((always_inline))  		//!< Always \c inline attribute
	#define NONNULL__
	#define NONNULLX__(...)
	#define NORETURN__
	#define PACK__				__attribute__((packed)) 				//!< Packed attribute
	#define PURE__
	#define SECTION__(s)		__attribute__((section(#s)))			//!< Section attribute to place declaration into section \p s
	#define USED__
	// Common mixed attributes
	#define NONNULL_INLINE__	__attribute__((always_inline))          //!< Always \c inline attribute

	#if (!defined(__OPTIMIZE__))
	#define __NOOPT__													//!< No Optimizations attribute
	#endif

#elif defined (__GNUC__)
	/*** GCC ***/
	// Declared as qualifier
	#define __WEAK				__attribute__((weak))					//!< Weak attribute
	#define __IRQ				__attribute__((interrupt_handler))		//!< Interrupt attribute
	// Declared as attribute
	#define ATTR__(...)			__attribute__((__VA_ARGS__))			//!< Macro to define one or multiple attribute(s) \p ... for a declaration

	#define ALIGN__(n)			__attribute__((align(n)))				//!< Align attribute padded to \p n
	#define COLD__				__attribute__((cold))					//!< Cold attribute
	#define DEPRECATED__		__attribute__((deprecated))				//!< Deprecated attribute
	#define HOT__				__attribute__((hot))					//!< Hot attribute
	#define INLINE__			__attribute__((always_inline))			//!< Always \c inline attribute
	#define NONNULL__			__attribute__((nonnull))				//!< Non \c null attribute (all pointers will be checked)
	#define NONNULLX__(...)		__attribute__((nonnull(__VA_ARGS__)))	//!< Non \c null attribute for \p ... pointers indexes
	#define NORETURN__			__attribute__((__noreturn__))			//!< No \c return attribute
	#define PACK__				__attribute__((packed))					//!< Packed attribute
	#define PURE__				__attribute__((pure))					//!< Pure attribute
	#define SECTION__(s)		__attribute__((section(#s)))			//!< Section attribute to place declaration into section \p s
	#define USED__				__attribute__((used))					//!< Used attribute ensures declaration won't be removed by garbage collector
	// Common mixed attributes
	#define NONNULL_INLINE__	ATTR__(nonnull, always_inline)			//!< Non \c null and Always \c inline attributes

	// Only supported starting GCC 6 (WARNING: here mostly for reference and specific cases, not defined for other compilers)
	#define SSO(o)				scalar_storage_order(#o)				//!< Alias for Scalar Storage Order
	#define BIG_ENDIAN__		ATTR__(packed, SSO(big-endian))			//!< Force structure in Big-Endian (use wisely or not at all)
	#define LITTLE_ENDIAN__		ATTR__(packed, SSO(little-endian))		//!< Force structure in Little-Endian (use wisely or not at all)

	#if (!defined(__OPTIMIZE__))
	#define __NOOPT__													//!< No Optimizations attribute
	#endif

#elif defined (__ICCARM__)
	// FIXME: most likely will not work, check cmsis_iccarm.h to fix attributes
	/*** IAR ***/
	// Declared as qualifier
	#define __WEAK				__weak									//!< Weak attribute
	#define __IRQ				__irq									//!< Interrupt attribute
	// Declared as attribute
	#define ATTR__(...)			__attribute__((__VA_ARGS__))			//!< Macro to define one or multiple attribute(s) \p ... for a declaration

	#define ALIGN__(n)			__attribute__((align(n)))				//!< Align attribute padded to \p n
	#define COLD__
	#define DEPRECATED__
	#define HOT__
	#define INLINE__
	#define NONNULL__
	#define NONNULLX__(...)
	#define NORETURN__			__noreturn								//!< No \c return attribute
	#define PACK__				__packed								//!< Packed attribute
	#define PURE__
	#define SECTION__(s)
	#define USED__
	// Common mixed attributes
	#define NONNULL_INLINE__

	//#define __NOOPT__													//!< No Optimizations attribute not identified on IAR toolchain

#elif defined (__TI_ARM__)
	/*** TEXAS INSTRUMENTS ***/
	// Declared as qualifier
	#define __WEAK				__attribute__((weak))					//!< Weak attribute only through \c #pragma weak(symbol)
	#define __IRQ				__interrupt								//!< Interrupt attribute
	// Declared as attribute
	#define ATTR__(...)			__attribute__((__VA_ARGS__))			//!< Macro to define one or multiple attribute(s) \p ... for a declaration

	#define ALIGN__(n)
	#define COLD__
	#define DEPRECATED__		__attribute__((deprecated))				//!< Deprecated attribute
	#define HOT__
	#define INLINE__
	#define NONNULL__
	#define NONNULLX__(...)
	#define NORETURN__			__attribute__((noreturn))				//!< No \c return attribute
	#define PACK__				__attribute__((packed))					//!< Packed attribute
	#define PURE__				__attribute__((pure))					//!< Pure attribute
	#define SECTION__(s)		__attribute__((section(#s)))			//!< Section attribute to place declaration into section \p s
	#define USED__				__attribute__((used))					//!< Used attribute ensures declaration won't be removed by garbage collector
	// Common mixed attributes
	#define NONNULL_INLINE__

	#if (!defined(__OPTIMIZE__))
	#define __NOOPT__													//!< No Optimizations attribute
	#define __STATIC_FORCEINLINE	static inline						//!< Static \c inline attribute alias when \c __NOOPT__ defined
	#endif

#elif defined (__TASKING__)
	/*** TASKING ***/
	// Declared as qualifier
	#define __WEAK				__attribute__((weak))					//!< Weak attribute
	#define __IRQ				__interrupt_irq							//!< Interrupt attribute
	// Declared as attribute
	#define ATTR__(...)			__attribute__((__VA_ARGS__))			//!< Macro to define one or multiple attribute(s) \p ... for a declaration

	#define ALIGN__(n)			__align(n)								//!< Align attribute padded to \p n
	#define COLD__
	#define DEPRECATED__
	#define HOT__
	#define INLINE__			__attribute__((always_inline))			//!< Always \c inline attribute
	#define NONNULL__
	#define NONNULLX__(...)
	#define NORETURN__			__attribute__((noreturn))				//!< No \c return attribute
	#define PACK__				__packed__								//!< Packed attribute
	#define PURE__				__attribute__((pure))					//!< Pure attribute
	#define SECTION__(s)		__attribute__((section(#s)))			//!< Section attribute to place declaration into section \p s
	#define USED__				__attribute__((used))					//!< Used attribute ensures declaration won't be removed by garbage collector
	// Common mixed attributes
	#define NONNULL_INLINE__	__attribute__((always_inline))			//!< Always \c inline attribute

	#if (!defined(__OPTIMIZE__))
	#define __NOOPT__													//!< No Optimizations attribute
	#define __STATIC_FORCEINLINE	static inline						//!< Static \c inline attribute alias when \c __NOOPT__ defined
	#endif

#elif defined (__CSMC__)
	/*** GCC ***/
	// Declared as qualifier
	#define __WEAK				__weak									//!< Weak attribute
	#define __IRQ				@interrupt								//!< Interrupt attribute
	// Declared as attribute
	#define ATTR__(...)

	#define ALIGN__(n)
	#define COLD__
	#define DEPRECATED__
	#define HOT__
	#define INLINE__
	#define NONNULL__
	#define NONNULLX__(...)
	#define NORETURN__
	#define PACK__				@packed									//!< Packed attribute
	#define PURE__
	#define SECTION__(s)
	#define USED__
	// Common mixed attributes
	#define NONNULL_INLINE__

	#if (!defined(__OPTIMIZE__))
	#define __NOOPT__													//!< No Optimizations attribute
	#define __STATIC_FORCEINLINE	static inline						//!< Static \c inline attribute alias when \c __NOOPT__ defined
	#endif

#else
	#error Unknown compiler. Attributes will not be recognized.
#endif

/*** C extensions keywords ***/
#ifndef __TYPEOF
#define __TYPEOF			__typeof__			//!< \c typeof keyword alias (\note so that it may prior be set to other expansion following compiler)
#endif

#ifndef __ASM
#define __ASM				__asm__				//!< \c asm keyword alias (\note so that it may prior be set to other expansion following compiler)
#endif


/*** C standard keywords ***/
#ifdef __STATIC
#undef __STATIC
#endif
#if defined(NO_STATIC_FUNC) || defined(UNITY_TESTING)
#define __STATIC								//!< \c static alias when functions visibility may be required (__INLINE remaining static)
#else
#define __STATIC			static				//!< \c static alias when functions visibility may be required (__INLINE remaining static)
#endif


#ifdef __INLINE
#undef __INLINE
#endif
//!\note Doesn't optimize code size much (when generated as functions) as code will be static to each file and hidden from others (leading to code duplicates)
#define __INLINE			static inline		//!< \c inline attribute alias

#ifndef __STATIC_INLINE
#define __STATIC_INLINE		static inline		//!< \c static \c inline attribute alias
#endif

/*** INLINES WORKAROUND WHEN OPTIMIZATION LEVEL SET TO NONE (GCC like toolchains) ***/
#if defined(__NOOPT__)
#undef __INLINE
#undef __STATIC_INLINE

#ifdef __STATIC_FORCEINLINE
#define __INLINE			__STATIC_FORCEINLINE							//!< \c inline attribute alias when \c __NOOPT__ defined
#define __STATIC_INLINE		__STATIC_FORCEINLINE							//!< \c static \c inline attribute alias when \c __NOOPT__ defined
#else
#define __INLINE			__attribute__((always_inline)) static inline	//!< \c inline attribute alias when \c __NOOPT__ defined
#define __STATIC_INLINE		__attribute__((always_inline)) static inline	//!< \c static \c inline attribute alias when \c __NOOPT__ defined
#endif
#endif

/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_ATTRIBUTES_H_ */
// cppcheck-suppress-end [misra-c2012-20.5, misra-c2012-20.10]
// cppcheck-suppress-end [misra-c2012-21.1]
/****************************************************************/
