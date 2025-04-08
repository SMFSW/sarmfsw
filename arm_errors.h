/*!\file arm_errors.h
** \author SMFSW
** \copyright MIT (c) 2017-2025, SMFSW
** \brief ARM user errors
**/
/****************************************************************/
#ifndef ARM_ERRORS_H_
	#define ARM_ERRORS_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


/*!\enum _FctERR
** \brief Enum of low/mid level functions return state
**/
typedef enum _FctERR {
	ERROR_OK				= 0,	//!< OK
	ERROR_SPEED				= -1,	//!< This device does not work in the active speed mode.
	ERROR_RANGE				= -2,	//!< Parameter out of range.
	ERROR_TIMEOUT			= -3,	//!< Abort on timeout error
	ERROR_VALUE				= -4,	//!< Parameter of incorrect value.
	ERROR_OVERFLOW			= -5,	//!< Overflow.
	ERROR_MATH				= -6,	//!< Overflow during evaluation.
	ERROR_ENABLED			= -7,	//!< Device is enabled.
	ERROR_DISABLED			= -8,	//!< Device is disabled.
	ERROR_BUSY				= -9,	//!< Device is busy.
	ERROR_NOTAVAIL			= -10,	//!< Requested value or method not available.
	ERROR_RXEMPTY			= -11,	//!< No data in receiver.
	ERROR_TXFULL			= -12,	//!< Transmitter is full.
	ERROR_BUSOFF			= -13,	//!< Bus not available.
	ERROR_OVERRUN			= -14,	//!< Overrun error is detected.
	ERROR_FRAMING			= -15,	//!< Framing error is detected.
	ERROR_PARITY			= -16,	//!< Parity error is detected.
	ERROR_NOISE				= -17,	//!< Noise error is detected.
	ERROR_IDLE				= -18,	//!< Idle error is detected.
	ERROR_FAULT				= -19,	//!< Fault error is detected.
	ERROR_BREAK				= -20,	//!< Break char is received during communication.
	ERROR_CRC				= -21,	//!< CRC error is detected.
	ERROR_ARBITR			= -22,	//!< A node lost arbitration. This error occurs if two nodes start transmission at the same time.
	ERROR_PROTECT			= -23,	//!< Protection error is detected.
	ERROR_UNDERFLOW			= -24,	//!< Underflow error is detected.
	ERROR_UNDERRUN			= -25,	//!< Underrun error is detected.
	ERROR_COMMON			= -26,	//!< Common error of a device.
	ERROR_LINSYNC			= -27,	//!< LIN synchronization error is detected.
	ERROR_FAILED			= -28,	//!< Requested functionality or process failed.
	ERROR_QFULL				= -29,	//!< Queue is full.
	ERROR_CMD				= -30,	//!< Command error is detected
	ERROR_NOTIMPLEM			= -31,	//!< Function not implemented error
	ERROR_MEMORY			= -32,	//!< Memory error
	ERROR_INSTANCE			= -33,	//!< Instance error
	ERROR_DEVICE_UNKNOWN	= -34,	//!< Device unknown
	ERROR_DEVICE_RESPONSE	= -35,	//!< Device response inconsistent
	ERROR_COM				= -36,	//!< Communication error
} FctERR;


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_ERRORS_H_ */
/****************************************************************/
