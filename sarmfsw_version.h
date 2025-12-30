/*!\file sarmfsw_version.h
** \author SMFSW
** \copyright MIT (c) 2017-2025, SMFSW
** \brief sarmfsw version headers
*/
/****************************************************************/
#ifndef SARMFSW_VERSION_H_
	#define SARMFSW_VERSION_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


#define __SARMFSW_RELEASE		(false)										//!< [31:31] sarmfsw debug version
#define __SARMFSW_VERSION_MAIN	(3U)										//!< [30:16] sarmfsw main version
#define __SARMFSW_VERSION_SUB	(7U)										//!< [15:0]  sarmfsw sub version

#define __SARMFSW_VERSION		(	((DWORD) (~__SARMFSW_RELEASE) << 31U) |		\
									((DWORD) __SARMFSW_VERSION_MAIN << 16U) |	\
									((DWORD) __SARMFSW_VERSION_SUB))		//!< sarmfsw version number


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* SARMFSW_VERSION_H_ */
/****************************************************************/
