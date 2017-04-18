/*!\file arm_stdclib.h
** \author SMFSW
** \version v0.5
** \date 2017
** \copyright MIT (c) 2017, SMFSW
** \brief ARM common standard c library wrapper macros
*/
/****************************************************************/
#ifndef __ARM_STDCLIB_H
	#define __ARM_STDCLIB_H
/****************************************************************/


/*** prints and strings ***/
#define PrintExpr(x)		(printf("%s = %d\n", #x, (x)))			//!< Print expression \b x and it's result \b x using printf

#define	addTab(s)			(strcat(s, '\t'))						//!< Adding tab to string using strcat
#define	addEOL(s)			(strcat(s, '\n'))						//!< Adding new line to string using strcat

#define VerboseInc(x)		(puts("Incrementing " #x), (x)++)		//!< Increment example using puts


/*** Test Macros ***/
#define TestMalloc(x)		((x) = malloc(sizeof(*x)), assert(x))	//!< Asserted malloc


/****************************************************************/
#endif /* __ARM_STDCLIB_H */
/****************************************************************/
