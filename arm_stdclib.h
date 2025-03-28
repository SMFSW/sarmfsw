/*!\file arm_stdclib.h
** \author SMFSW
** \copyright MIT (c) 2017-2025, SMFSW
** \brief ARM common standard c library wrapper macros
*/
/****************************************************************/
#ifndef ARM_STDCLIB_H_
	#define ARM_STDCLIB_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include <string.h>
#include <stdio.h>
/****************************************************************/


/*** prints and strings ***/
#define str_clr(s)			(s[0] = charNull)						//!< clear string \p s (fast way)
#define str_clr_safe(s)		(memset(s, charNull, sizeof(s)))		//!< clear string \p s (safe way)

#define	str_add_tab(s)		(strcat(s, '\t'))						//!< Adding tab to \p s string using strcat
#define	str_add_cr(s)		(strcat(s, '\r'))						//!< Adding carriage return to \p s string using strcat
#define	str_add_lf(s)		(strcat(s, '\n'))						//!< Adding line feed to \p s string using strcat
#define	str_add_crlf(s)		(strcat(s, '\r\n'))						//!< Adding carriage return and line feed to \p s string using strcat


#define printExpr(e)		(printf("%s = %d\r\n", STR(e), (e)))	//!< Print expression \p e and it's result \p e using \c printf

#define verbInstr(i)		(printf(STR(i)), (i))					//!< Print instruction \p i and execute it

#define verbInc(x)			(puts("Incrementing " STR(x)), (x)++)	//!< Increment example on \p x using \c puts
#define verbDec(x)			(puts("Decrementing " STR(x)), (x)--)	//!< Decrement example on \p x using \c puts


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_STDCLIB_H_ */
/****************************************************************/
