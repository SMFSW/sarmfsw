/*!\file arm_stdclib.h
** \author SMFSW
** \copyright MIT (c) 2017-2018, SMFSW
** \brief ARM common standard c library wrapper macros
*/
/****************************************************************/
#ifndef __ARM_STDCLIB_H
	#define __ARM_STDCLIB_H

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


/*** prints and strings ***/
#define str_clr(s)			(s[0] = '\0')						//!< clear string \b s (fast way)
#define str_clr_safe(s)		(memset('\0', s, sizeof(s)))		//!< clear string \b s (safe way)

#define	str_add_tab(s)		(strcat(s, '\t'))					//!< Adding tab to string using strcat
#define	str_add_cr(s)		(strcat(s, '\r\n'))					//!< Adding new line to string using strcat


#define printExpr(e)		(printf("%s = %d\r\n", #e, (e)))	//!< Print expression \b e and it's result \b e using printf
#define verbInstr(i)		(printf(#i), (i))					//!< Print instruction \b e and execute it


#define verbInc(x)			(puts("Incrementing " #x), (x)++)	//!< Increment example using puts
#define verbDec(x)			(puts("Incrementing " #x), (x)--)	//!< Decrement example using puts


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_STDCLIB_H */
/****************************************************************/
