/*!\file arm_inlines_stdclib.h
** \author SMFSW
** \copyright MIT (c) 2017-2025, SMFSW
** \brief ARM common standard c library inlines and wrapper macros
** \MISRA Header scope deviation has been granted for following rules:\n
**	\b Rule-18.4 - \b Advisory: +/- operators on pointer type (misra-c2012-18.4)\n
** \MISRA Header scope legitimate use derogation authorized for:\n
** 	\b Rule-21.6 - \b Required: Use of \c <stdio.h> (misra-c2012-21.6)\n
**	\a Justification: Some of the following functions are \c sprintf like oriented extensions to standard library.\n
** 	\b Rule-17.1 - \b Required: Use of \c <starg.h> (misra-c2012-17.1)\n
**	\a Justification: Legitimate use of variadic parameters received, passed to \c printf like function call.\n
**	\b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
**	\a Justification: \p Use of \ref STR catenate macro in macros expansion.\n
*/
// cppcheck-suppress-begin misra-c2012-18.4
// cppcheck-suppress-begin [misra-c2012-21.6, misra-c2012-17.1, misra-c2012-20.7]
/****************************************************************/
#ifndef ARM_STDCLIB_H_
	#define ARM_STDCLIB_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
/****************************************************************/


/***********************/
/*** heap management ***/
/***********************/

#define malloc_assert(x)	((x) = malloc(sizeof(*(x))), assert((x)))	//!< malloc \p x object and assert it

/*!\brief Get current heap address
** \note Address is returned as integer (returning released pointer value would cause a warning from compiler)
** 		 Use \ref get_current_heap_address to get current heap address under the form of \c void* pointer
** \MISRA Local legitimate use derogation authorized for:\n
**	\b Rule-11.6 - \b Required: pointer to void cast to arithmetic (misra-c2012-11.6)\n
**	\b Rule-21.3 - \b Required: dynamic allocation (misra-c2012-21.3)\n
**	\a Justification: Intended to identify potential memory leaks in case of dynamic allocation use.\n
** \return Integer value of current heap address
**/
__INLINE uintPTR_t get_current_heap_address_int(void)
{
	/*** Allocate dummy memory ***/
	void * p = malloc(0);					// cppcheck-suppress misra-c2012-21.3
	/*** Save heap current address as integer to avoid warning about possible use of freed allocated memory ***/
	const uintPTR_t addr = (uintPTR_t) p;	// cppcheck-suppress misra-c2012-11.6
	/*** Free dummy allocated memory ***/
	free(p);								// cppcheck-suppress misra-c2012-21.3

	return addr;	// Return address as integer
}

/*!\brief Get current heap address pointer
** \note Can be useful to get heap value when testing for potential memory leaks
** \MISRA Local legitimate use derogation authorized for:\n
**	\b Rule-11.6 - \b Required: pointer to void cast to arithmetic (misra-c2012-11.6)\n
**	\a Justification: Intended to identify potential memory leaks in case of dynamic allocation use.\n
** \warning Shall not cast returned value to \c void* (allowing to write anything to the pointed content)
** \return Pointer to current heap address
**/
__INLINE const void * INLINE__ get_current_heap_address(void)
{
	/*** Return integer value with cast to pointer type ***/
	return (const void *) get_current_heap_address_int();	// cppcheck-suppress misra-c2012-11.6
}


/*************************/
/*** print and strings ***/
/*************************/

//! \warning Only works with char arrays, do not use on pointer to char array
#define strclr_full(s)			(memset(s, charNull, sizeof(s)))					//!< Clear string \p s (full content)

#define printExpr(e)			(printf("%s = %d\r\n", STR(e), (e)))				//!< Print expression \p e and it's result \p e using \c printf
#define sprintExpr(s, e)		(sprintf((s), "%s = %d\r\n", STR(e), (e)))			//!< Print expression \p e and it's result \p e to \p s string
#define snprintExpr(s, n, e)	(snprintf((s), (n), "%s = %d\r\n", STR(e), (e)))	//!< Print expression \p e and it's result \p e with max \p n characters to \p s string

#define verbInstr(i)			(printf(STR(i)), (i))								//!< Print instruction \p i using \c printf and execute it
#define sverbInstr(s, i)		(sprintf((s), STR(i)), (i))							//!< Print instruction \p i to \p s string and execute it
#define snverbInstr(s, n, i)	(snprintf((s), (n), STR(i)), (i))					//!< Print instruction \p i to \p s string with max \p n characters and execute it

#define verbInc(x)				(puts("Incrementing " STR(x)), (x)++)				//!< Increment example on \p x using \c puts
#define verbDec(x)				(puts("Decrementing " STR(x)), (x)--)				//!< Decrement example on \p x using \c puts


/*!\brief Append formatted content at the end of string (char array)
** \note As of C library, use \ref strnappend to ensure resulting \p s string won't exceed given length
** \note If support for long long is needed, make sure Runtime library is set to Standard C
** \note If support for floats is needed, make sure Use float with printf is checked
**
** \param[in,out] s - Pointer to char array
** \param[in] fmt - Pointer to formatted string to append
** \param[in] ... - Variadic printf like format arguments
** \return Number of characters that would have been written to string
** \retval Negative number in case of encoding error
**/
__NEVER_INLINE intCPU_t PRINTF__(2, 3) strappend(CHAR * const __RESTRICT s, const CHAR * const __RESTRICT fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	const intCPU_t ret = vsprintf(s+strlen(s), fmt, args);
	va_end(args);

	return ret;
}

/*!\brief Append formatted content at the end of sized string (char array)
** \note If support for long long is needed, make sure Runtime library is set to Standard C
** \note If support for floats is needed, make sure Use float with printf is checked
**
** \param[in,out] s - Pointer to char array
** \param[in] len - Length of char array \p s
** \param[in] fmt - Pointer to formatted string to append
** \param[in] ... - Variadic printf like format arguments
** \return Number of characters that would have been written to string
** \retval Negative number in case of encoding error
**/
__NEVER_INLINE intCPU_t PRINTF__(3, 4) strnappend(CHAR * const __RESTRICT s, const size_t len, const CHAR * const __RESTRICT fmt, ...)
{
	const size_t slen = strlen(s);
	intCPU_t ret = 0;

	if (slen < len)
	{
		va_list args;
		va_start(args, fmt);
		ret = vsnprintf(s + slen, len - slen, fmt, args);
		va_end(args);
	}

	return ret;
}

/*!\brief Append string at the end of sized string (char array)
** \note A little safer to use than \c strncat to keep \c s un-corrupted
**
** \param[in,out] s - Pointer to char array
** \param[in] s2 - Pointer to char array to catenate at the end of \p s
** \param[in] size - Length of char array \p s
** \return Pointer to resulting string (char array)
**/
__INLINE CHAR * strncat_sz(CHAR * const __RESTRICT s, const CHAR * const __RESTRICT s2, const size_t size) {
	const size_t sz = size - strlen(s) - 1U;
	return (sz > size) ? s : strncat(s, s2, sz); }


/*!\brief Fast clear string (char array)
**
** \param[in,out] s - pointer to char array
**/
__INLINE void INLINE__ strclr(CHAR * const s) {
	s[0] = charNull; }

/*!\brief Append tab char at the end of string (char array)
** \note As of C library, use \ref strn_add_tab to ensure resulting \p s string won't exceed given length
**
** \param[in,out] s - Pointer to char array
** \return Pointer to resulting string (char array)
**/
__INLINE CHAR * INLINE__ str_add_tab(CHAR * const __RESTRICT s) {
	return strcat(s, "\t"); }

/*!\brief Append carriage return char at the end of string (char array)
** \note As of C library, use \ref strn_add_cr to ensure resulting \p s string won't exceed given length
**
** \param[in,out] s - Pointer to char array
** \return Pointer to resulting string (char array)
**/
__INLINE CHAR * INLINE__ str_add_cr(CHAR * const __RESTRICT s) {
	return strcat(s, "\r"); }

/*!\brief Append line feed char at the end of string (char array)
** \note As of C library, use \ref strn_add_lf to ensure resulting \p s string won't exceed given length
**
** \param[in,out] s - Pointer to char array
** \return Pointer to resulting string (char array)
**/
__INLINE CHAR * INLINE__ str_add_lf(CHAR * const __RESTRICT s) {
	return strcat(s, "\n"); }

/*!\brief Append carriage return and line feed chars at the end of string (char array)
** \note As of C library, use \ref strn_add_crlf to ensure resulting \p s string won't exceed given length
**
** \param[in,out] s - Pointer to char array
** \return Pointer to resulting string (char array)
**/
__INLINE CHAR * INLINE__ str_add_crlf(CHAR * const __RESTRICT s) {
	return strcat(s, "\r\n"); }


/*!\brief Append tab char at the end of sized string (char array)
**
** \param[in,out] s - Pointer to char array
** \param[in] len - Length of char array \p s
** \return Pointer to resulting string (char array)
**/
__INLINE CHAR * INLINE__ strn_add_tab(CHAR * const __RESTRICT s, const size_t len) {
	return strncat_sz(s, "\t", len); }

/*!\brief Append carriage return char at the end of sized string (char array)
**
** \param[in,out] s - Pointer to char array
** \param[in] len - Length of char array \p s
** \return Pointer to resulting string (char array)
**/
__INLINE CHAR * INLINE__ strn_add_cr(CHAR * const __RESTRICT s, const size_t len) {
	return strncat_sz(s, "\r", len); }

/*!\brief Append line feed char at the end of sized string (char array)
**
** \param[in,out] s - Pointer to char array
** \param[in] len - Length of char array \p s
** \return Pointer to resulting string (char array)
**/
__INLINE CHAR * INLINE__ strn_add_lf(CHAR * const __RESTRICT s, const size_t len) {
	return strncat_sz(s, "\n", len); }

/*!\brief Append carriage return and line feed chars at the end of sized string (char array)
**
** \param[in,out] s - Pointer to char array
** \param[in] len - Length of char array \p s
** \return Pointer to resulting string (char array)
**/
__INLINE CHAR * INLINE__ strn_add_crlf(CHAR * const __RESTRICT s, const size_t len) {
	return strncat_sz(s, "\r\n", len); }


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_STDCLIB_H_ */
// cppcheck-suppress-end misra-c2012-18.4
// cppcheck-suppress-end [misra-c2012-21.6, misra-c2012-17.1, misra-c2012-20.7]
/****************************************************************/
