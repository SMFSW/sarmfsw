/*!\file arm_attributes.h
** \author SMFSW
** \version v0.3
** \date 2017
** \copyright MIT (c) 2017, SMFSW
** \brief ARM common gcc attributes
*/
/****************************************************************/
#ifndef __ARM_ATTRIB_H
	#define __ARM_ATTRIB_H
/****************************************************************/

#define		_atrINLINE			__attribute__((always_inline))
#define		_atrWEAK			__attribute__((weak))
#define		_atrPACK			__attribute__((__packed__))

/****************************************************************/
#endif /* __ARM_ATTRIB_H */
/****************************************************************/
