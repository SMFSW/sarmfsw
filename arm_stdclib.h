/*!\file arm_stdclib.h
** \author SMFSW
** \date 2017
** \copyright MIT (c) 2017, SMFSW
** \brief ARM common standard c library wrapper macros
*/
/****************************************************************/
#ifndef __ARM_STDCLIB_H
	#define __ARM_STDCLIB_H
/****************************************************************/


/*** prints and strings ***/
#define printExpr(e)		(printf("%s = %d\r\n", #e, (e)))		//!< Print expression \b e and it's result \b e using printf
#define verbInstr(i)		(printf("" #i), (i))					//!< Print instruction \b e and execute it

#define str_clr(s)			(s[0] = '\0')							//!< clear string \b s (fast way)
#define str_clr_safe(s)		(memset('\0', s, sizeof(s)))			//!< clear string \b s (safe way)

#define	str_add_tab(s)		(strcat(s, '\t'))						//!< Adding tab to string using strcat
#define	str_add_cr(s)		(strcat(s, '\r\n'))						//!< Adding new line to string using strcat


#define VerboseInc(x)		(puts("Incrementing " #x), (x)++)		//!< Increment example using puts


/*** Test Macros ***/
#define TestMalloc(x)		((x) = malloc(sizeof(*x)), assert(x))	//!< Asserted malloc


/****************************************************************/
#endif /* __ARM_STDCLIB_H */
/****************************************************************/
