/*!\file arm_keywords.h
** \author SMFSW
** \copyright MIT (c) 2017-2026, SMFSW
** \brief Common keywords aliases
** \MISRA Header scope deviation has been granted for following rules:\n
** 	\b Rule-20.5 - \b Advisory: \c \#undef (misra-c2012-20.5)\n
** \MISRA Header scope derogation to following rules:\n
** 	\b Rule-21.1 - \b Required: \c \#define and \c \#undef on reserved identifiers (misra-c2012-21.1)\n
**	\a Justification: define generic CMSIS IO macros and keywords aliases in case not already defined.\n
*/
// cppcheck-suppress-begin [misra-c2012-20.5]
// cppcheck-suppress-begin [misra-c2012-21.1]
/****************************************************************/
#ifndef ARM_KEYWORDS_H_
	#define ARM_KEYWORDS_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


/********************************************************************/
/*** IO definitions (access restrictions to peripheral registers) ***/
/********************************************************************/
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


/***************************/
/*** C standard keywords ***/
/***************************/
#ifndef __RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#define __RESTRICT			restrict			//!< \c restrict keyword alias
#else
#define __RESTRICT								//!< \c restrict keyword alias
#endif
#endif


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

#ifndef __NEVER_INLINE
//!\note Same as \c __INLINE or \c __STATIC_INLINE, but not modifier by \c __NOOPT__ symbol
#define __NEVER_INLINE		static inline		//!< \c inline attribute alias for code that can never be inlined (eg.: \c var_args parameters)
#endif


/************************************************************************************/
/*** INLINES WORKAROUND WHEN OPTIMIZATION LEVEL SET TO NONE (GCC like toolchains) ***/
/************************************************************************************/
#if defined(__NOOPT__)
#undef __INLINE
#undef __STATIC_INLINE

#ifdef __STATIC_FORCEINLINE
#define __INLINE			__STATIC_FORCEINLINE	//!< \c inline attribute alias when \c __NOOPT__ defined
#define __STATIC_INLINE		__STATIC_FORCEINLINE	//!< \c static \c inline attribute alias when \c __NOOPT__ defined
#else
#define __INLINE			static inline INLINE__	//!< \c inline attribute alias when \c __NOOPT__ defined
#define __STATIC_INLINE		static inline INLINE__	//!< \c static \c inline attribute alias when \c __NOOPT__ defined
#endif
#endif


/*****************************/
/*** C extensions keywords ***/
/*****************************/
#ifndef __TYPEOF
#define __TYPEOF			__typeof__			//!< \c typeof keyword alias (\note so that it may prior be set to other expansion following compiler)
#endif

#ifndef __ASM
#define __ASM				__asm__				//!< \c asm keyword alias (\note so that it may prior be set to other expansion following compiler)
#endif


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_KEYWORDS_H_ */
// cppcheck-suppress-end [misra-c2012-20.5]
// cppcheck-suppress-end [misra-c2012-21.1]
/****************************************************************/
