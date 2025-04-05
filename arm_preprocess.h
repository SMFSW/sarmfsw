/*!\file arm_preprocess.h
** \author SMFSW
** \copyright MIT (c) 2017-2025, SMFSW
** \brief ARM common preprocessing macros and directives
** \MISRA Header scope deviation has been granted for following rules:\n
** 	\b Rule-20.10 - \b Advisory: \c # and \c ## preprocessor operators (misra-c2012-20.10)\n
*/
// cppcheck-suppress-begin misra-c2012-20.10
/****************************************************************/
#ifndef ARM_PREPROCESS_H_
	#define ARM_PREPROCESS_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


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
// cppcheck-suppress-end misra-c2012-20.10
/****************************************************************/
