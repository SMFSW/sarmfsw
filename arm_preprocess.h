/*!\file arm_preprocess.h
** \author SMFSW
** \copyright MIT (c) 2017-2025, SMFSW
** \brief ARM common pre-processing macros and directives
** \MISRA Header scope deviation has been granted for following rules:\n
** 	\b Rule-20.5 - \b Advisory: \c \#undef (misra-c2012-20.5)\n
** 	\b Rule-20.10 - \b Advisory: \c # and \c ## preprocessor operators (misra-c2012-20.10)\n
** \MISRA Header scope legitimate use derogation authorized for:\n
*/
// cppcheck-suppress-begin [misra-c2012-20.5, misra-c2012-20.10]
/****************************************************************/
#ifndef ARM_PREPROCESS_H_
	#define ARM_PREPROCESS_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


/******************/
/*** C standard ***/
/******************/
#if (!defined(__STDC__) && !defined(__STDC_VERSION__))
# define __STDC_C78 	//!< Does not comply with C89 or later standard! Most likely complies with 1978 K&R C standard (informally known as C78)
#elif (defined(__STDC__) && !defined(__STDC_VERSION__))
# define __STDC_C90		//!< Complies with ANSI C89 / ISO C90 standard
#elif (__STDC_VERSION__ >= 202311L)
# define __STDC_C23 	//!< Complies with C23 standard
#elif (__STDC_VERSION__ >= 201710L)
# define __STDC_C17		//!< Complies with C17 standard
#elif (__STDC_VERSION__ >= 201112L)
# define __STDC_C11		//!< Complies with C11 standard
#elif (__STDC_VERSION__ >= 199901L)
# define __STDC_C99		//!< Complies with C99 standard
#elif (__STDC_VERSION__ >= 199409L)
# define __STDC_C95		//!< Complies with amended C90 standard (known as C95)
#endif


/*****************************/
/*** Pre-processing macros ***/
/*****************************/
//! \warning No nesting possible, use \ref XCAT instead (unless there is a good reason not to use \ref XCAT)
#define	CAT(a, b)			a##b			//!< Preprocessor Name catenation of \c a and \c b (use of \ref XCAT is highly recommended for any need)
#define XCAT(a, b)			CAT(a, b)		//!< Preprocessor Name catenation of \c a and \c b (nesting possibility)

#define STR(s)				#s				//!< Stringify \c s expression
#define XSTR(s)				STR(s)			//!< Stringify the result of \c s expression expansion (stringification of a macro expansion)


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_PREPROCESS_H_ */
// cppcheck-suppress-end [misra-c2012-20.5, misra-c2012-20.10]
/****************************************************************/
