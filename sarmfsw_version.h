/*!\file sarmfsw_version.h
** \author SMFSW
** \copyright MIT (c) 2017-2026, SMFSW
** \brief sarmfsw version headers
*/
/****************************************************************/
#ifndef SARMFSW_VERSION_H_
	#define SARMFSW_VERSION_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


#define SARMFSW_RELEASE			(false)								//!< [31:31] sarmfsw release status
#define SARMFSW_VERSION_MAIN	(4U)								//!< [30:16] sarmfsw main version
#define SARMFSW_VERSION_SUB		(0U)								//!< [15:0]  sarmfsw sub version

#define SARMFSW_VERSION		(	((DWORD) (~SARMFSW_RELEASE) << 31U) |	\
								((DWORD) SARMFSW_VERSION_MAIN << 16U) |	\
								((DWORD) SARMFSW_VERSION_SUB))		//!< sarmfsw version number


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* SARMFSW_VERSION_H_ */
/****************************************************************/
