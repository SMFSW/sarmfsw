/*!\file arm_attributes.h
** \author SMFSW
** \version v0.9
** \date 2017
** \copyright MIT (c) 2017, SMFSW
** \brief ARM common gcc attributes
*/
/****************************************************************/
#ifndef __ARM_ATTRIB_H
	#define __ARM_ATTRIB_H
/****************************************************************/

#define		INLINE__			__attribute__((always_inline))	//!< \b Inline attribute for gcc
#define		WEAK__				__attribute__((weak))			//!< \b Weak attribute for gcc
#define		PACK__				__attribute__((__packed__))		//!< \b Packed attribute for gcc

/****************************************************************/
#endif /* __ARM_ATTRIB_H */
/****************************************************************/
