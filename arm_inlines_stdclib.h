/*!\file arm_inlines_stdclib.h
** \author SMFSW
** \copyright MIT (c) 2017-2025, SMFSW
** \brief ARM common standard c library inlines and wrapper macros
*/
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
** \return Integer value of current heap address
**/
__INLINE uintCPU_t _get_current_heap_address(void)
{
	void * p = malloc(0);					// Allocate dummy memory
	const uintCPU_t addr = (uintCPU_t) p;	// Save heap current address as integer to avoid warning about possible use of freed p
	free(p);								// Free dummy allocated memory
	return addr;							// Return address as integer
}

/*!\brief Get current heap address pointer
** \note Can be useful to get heap value when testing for potential memory leaks
** \warning Shall not cast returned value to \c void* (allowing to write anything to the pointed content)
** \return Pointer to current heap address
**/
__INLINE const void * INLINE__ get_current_heap_address(void)
{
	return (const void *) _get_current_heap_address();	// Return integer value with cast to pointer type
}


/*************************/
/*** print and strings ***/
/*************************/

//! \warning Only works with char arrays, do not use on pointer to char array
#define strclr_full(s)		(memset(s, charNull, sizeof(s)))			//!< Clear string \p s (full content)

#define printExpr(e)		(printf("%s = %d\r\n", STR(e), (e)))		//!< Print expression \p e and it's result \p e using \c printf
#define sprintExpr(s, e)	(sprintf(s, "%s = %d\r\n", STR(e), (e)))	//!< Print expression \p e and it's result \p e to \p s string

#define verbInstr(i)		(printf(STR(i)), (i))						//!< Print instruction \p i using \c printf and execute it
#define sverbInstr(s, i)	(sprintf(s, STR(i)), (i))					//!< Print instruction \p i to \p s string and execute it

#define verbInc(x)			(puts("Incrementing " STR(x)), (x)++)		//!< Increment example on \p x using \c puts
#define verbDec(x)			(puts("Decrementing " STR(x)), (x)--)		//!< Decrement example on \p x using \c puts


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
__INLINE intCPU_t PRINTF__(2, 3) strappend(CHAR * const s, const CHAR * const fmt, ...)
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
__INLINE intCPU_t PRINTF__(3, 4) strnappend(CHAR * const s, const size_t len, const CHAR * const fmt, ...)
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
__INLINE CHAR * strncat_sz(CHAR * const s, const CHAR * const s2, const size_t size) {
	const intCPU_t sz = size - strlen(s) - 1;
	return (sz <= 0) ? s : strncat(s, s2, sz); }


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
__INLINE CHAR * INLINE__ str_add_tab(CHAR * const s) {
	return strcat(s, "\t"); }

/*!\brief Append carriage return char at the end of string (char array)
** \note As of C library, use \ref strn_add_cr to ensure resulting \p s string won't exceed given length
**
** \param[in,out] s - Pointer to char array
** \return Pointer to resulting string (char array)
**/
__INLINE CHAR * INLINE__ str_add_cr(CHAR * const s) {
	return strcat(s, "\r"); }

/*!\brief Append line feed char at the end of string (char array)
** \note As of C library, use \ref strn_add_lf to ensure resulting \p s string won't exceed given length
**
** \param[in,out] s - Pointer to char array
** \return Pointer to resulting string (char array)
**/
__INLINE CHAR * INLINE__ str_add_lf(CHAR * const s) {
	return strcat(s, "\n"); }

/*!\brief Append carriage return and line feed chars at the end of string (char array)
** \note As of C library, use \ref strn_add_crlf to ensure resulting \p s string won't exceed given length
**
** \param[in,out] s - Pointer to char array
** \return Pointer to resulting string (char array)
**/
__INLINE CHAR * INLINE__ str_add_crlf(CHAR * const s) {
	return strcat(s, "\r\n"); }


/*!\brief Append tab char at the end of sized string (char array)
**
** \param[in,out] s - Pointer to char array
** \param[in] len - Length of char array \p s
** \return Pointer to resulting string (char array)
**/
__INLINE CHAR * INLINE__ strn_add_tab(CHAR * const s, const size_t len) {
	return strncat_sz(s, "\t", len); }

/*!\brief Append carriage return char at the end of sized string (char array)
**
** \param[in,out] s - Pointer to char array
** \param[in] len - Length of char array \p s
** \return Pointer to resulting string (char array)
**/
__INLINE CHAR * INLINE__ strn_add_cr(CHAR * const s, const size_t len) {
	return strncat_sz(s, "\r", len); }

/*!\brief Append line feed char at the end of sized string (char array)
**
** \param[in,out] s - Pointer to char array
** \param[in] len - Length of char array \p s
** \return Pointer to resulting string (char array)
**/
__INLINE CHAR * INLINE__ strn_add_lf(CHAR * const s, const size_t len) {
	return strncat_sz(s, "\n", len); }

/*!\brief Append carriage return and line feed chars at the end of sized string (char array)
**
** \param[in,out] s - Pointer to char array
** \param[in] len - Length of char array \p s
** \return Pointer to resulting string (char array)
**/
__INLINE CHAR * INLINE__ strn_add_crlf(CHAR * const s, const size_t len) {
	return strncat_sz(s, "\r\n", len); }


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_STDCLIB_H_ */
/****************************************************************/
