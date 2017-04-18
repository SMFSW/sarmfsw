/*!\file arm_attributes.h
** \author SMFSW
** \version v0.5
** \date 2017
** \copyright MIT (c) 2017, SMFSW
** \brief ARM common gcc attributes
*/
/****************************************************************/
#ifndef __ARM_ATTRIB_H
	#define __ARM_ATTRIB_H
/****************************************************************/

#define		INLINE__			__attribute__((always_inline))
#define		WEAK__				__attribute__((weak))
#define		PACK__				__attribute__((__packed__))

/****************************************************************/
#endif /* __ARM_ATTRIB_H */
/****************************************************************/
