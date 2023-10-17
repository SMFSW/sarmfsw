/*!\file arm_stdclib.h
** \author SMFSW
** \copyright MIT (c) 2017-2023, SMFSW
** \brief ARM common standard c library wrapper macros
*/
/****************************************************************/
#ifndef __ARM_STDCLIB_H
	#define __ARM_STDCLIB_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <string.h>
#include <stdio.h>
/****************************************************************/


/*** prints and strings ***/
#define str_clr(s)			(s[0] = charNull)						//!< clear string \b s (fast way)
#define str_clr_safe(s)		(memset(s, charNull, sizeof(s)))		//!< clear string \b s (safe way)

#define	str_add_tab(s)		(strcat(s, '\t'))						//!< Adding tab to string using strcat
#define	str_add_cr(s)		(strcat(s, '\r'))						//!< Adding carriage return to string using strcat
#define	str_add_lf(s)		(strcat(s, '\n'))						//!< Adding line feed to string using strcat
#define	str_add_crlf(s)		(strcat(s, '\r\n'))						//!< Adding carriage return and line feed to string using strcat


#define printExpr(e)		(printf("%s = %d\r\n", STR(e), (e)))	//!< Print expression \b e and it's result \b e using printf

#define verbInstr(i)		(printf(STR(i)), (i))					//!< Print instruction \b e and execute it

#define verbInc(x)			(puts("Incrementing " STR(x)), (x)++)	//!< Increment example using puts
#define verbDec(x)			(puts("Decrementing " STR(x)), (x)--)	//!< Decrement example using puts


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_STDCLIB_H */
/****************************************************************/
