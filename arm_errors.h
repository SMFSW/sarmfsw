/*!\file FctERR.h
** \author SMFSW
** \date 2017
** \copyright MIT (c) 2017, SMFSW
** \brief ARM user errors declarations
**/
/****************************************************************/
#ifndef __ARM_ERROR_H
	#define __ARM_ERROR_H
/****************************************************************/


/*!\enum FctERR
** \brief Enum of low/mid level functions return state
** \note TODO: Fix !defined lines when __mx_lwip_H set (should not cause any harm, but ugly and set to cause issues sometime, somehow)
**/
typedef enum FctERR {
#if !defined(__mx_lwip_H)	// TODO: find a fix to remove this pre-processor ugliness
	ERR_OK			= 0,	//!< OK
#endif
	ERR_SPEED		= -1,	//!< This device does not work in the active speed mode.
	ERR_RANGE		= -2,	//!< Parameter out of range.
#if !defined(__mx_lwip_H)	// TODO: find a fix to remove this pre-processor ugliness
	ERR_TIMEOUT		= -3,	//!< Abort on timeout error
#endif
	ERR_VALUE		= -4,	//!< Parameter of incorrect value.
	ERR_OVERFLOW	= -5,	//!< Overflow.
	ERR_MATH		= -6,	//!< Overflow during evaluation.
	ERR_ENABLED		= -7,	//!< Device is enabled.
	ERR_DISABLED	= -8,	//!< Device is disabled.
	ERR_BUSY		= -9,	//!< Device is busy.
	ERR_NOTAVAIL	= -10,	//!< Requested value or method not available.
	ERR_RXEMPTY		= -11,	//!< No data in receiver.
	ERR_TXFULL		= -12,	//!< Transmitter is full.
	ERR_BUSOFF		= -13,	//!< Bus not available.
	ERR_OVERRUN		= -14,	//!< Overrun error is detected.
	ERR_FRAMING		= -15,	//!< Framing error is detected.
	ERR_PARITY		= -16,	//!< Parity error is detected.
	ERR_NOISE		= -17,	//!< Noise error is detected.
	ERR_IDLE		= -18,	//!< Idle error is detected.
	ERR_FAULT		= -19,	//!< Fault error is detected.
	ERR_BREAK		= -20,	//!< Break char is received during communication.
	ERR_CRC			= -21,	//!< CRC error is detected.
	ERR_ARBITR		= -22,	//!< A node lost arbitration. This error occurs if two nodes start transmission at the same time.
	ERR_PROTECT		= -23,	//!< Protection error is detected.
	ERR_UNDERFLOW	= -24,	//!< Underflow error is detected.
	ERR_UNDERRUN	= -25,	//!< Underrun error is detected.
	ERR_COMMON		= -26,	//!< Common error of a device.
	ERR_LINSYNC		= -27,	//!< LIN synchronization error is detected.
	ERR_FAILED		= -28,	//!< Requested functionality or process failed.
	ERR_QFULL		= -29,	//!< Queue is full.
	ERR_CMD			= -30,	//!< Command error is detected
	ERR_NOTIMPLEM	= -31,	//!< Function not implemented error
	ERR_MEMORY		= -32,	//!< Memory error
	ERR_INSTANCE	= -33	//!< Instance error
} FctERR;


/****************************************************************/
#endif /* __ARM_ERROR_H */
/****************************************************************/
