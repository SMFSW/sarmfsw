/*!\file arm_typedefs.h
** \author SMFSW
** \copyright MIT (c) 2017-2025, SMFSW
** \brief ARM common typedefs
** \warning	Endianness for unions shall be checked following target / compiler to avoid potential headaches!
** \warning sBitfieldXX are defined from lsb to msb as most compiler does by default; if it's not the case,
**			try to find a compiler directive or pragma to reverse bitfield order;
**			if not available, define REVERSE_BITFIELD symbol at project level.
** \warning	For Arduino platform, some binary.h definitions needs to be undefined.
**			If you find them useful, define USE_INO_BINARY_HEADER before including sarmfsw.h to keep them defined.
**			Please note, B0 & B1 Bytes sub-structures of unions defined hereafter will not be available in this case.
** \note	For Arduino platform, prefer ANSI-C(pp) 0b notation for binary representation,
** 			instead of using defines from Arduino binary.h
** \note	STDBOOL_NDEF can be defined at project level if stdint.h doesn't exist for target compiler
** \note	STDINT_NDEF can be defined at project level if stdint.h doesn't exist for target compiler
** \MISRA Header scope deviation has been granted for following rules:\n
** 	\b Rule-19.2 - \b Advisory: \c union keyword (misra-c2012-19.2)\n
** \MISRA Header scope legitimate use derogation authorized for:\n
** 	\b Rule-21.1 - \b Required: \c \#define and \c \#undef on reserved identifiers (misra-c2012-21.1)\n
**	\a Justification: \c \#define are library specific reserved identifiers.\n
*/
// cppcheck-suppress-begin [misra-c2012-19.2]
// cppcheck-suppress-begin [misra-c2012-21.1]
/****************************************************************/
#ifndef ARM_TYPEDEFS_H_
	#define ARM_TYPEDEFS_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


#ifndef STDBOOL_NDEF // TODO: maybe find proper pre-processing directive for compilers not handling stdbool.h
#define __STDBOOL_DEF
#else
// If not possible to include header, types defined as symbols here
typedef unsigned char			bool;		//!< pseudo bool typedef
#endif

#ifndef STDINT_NDEF // TODO: maybe find proper pre-processing directive for compilers not handling stdint.h
#define __STDINT_DEF
#else
// If not possible to include header, types defined as symbols here
typedef unsigned char			uint8_t;	//!< uint8_t typedef
typedef short unsigned int		uint16_t;	//!< uint16_t typedef
typedef long unsigned int		uint32_t;	//!< uint32_t typedef
typedef long long unsigned int	uint64_t;	//!< uint64_t typedef
typedef signed char				int8_t;		//!< int8_t typedef
typedef short signed int		int16_t;	//!< int16_t typedef
typedef long signed int			int32_t;	//!< int32_t typedef
typedef long long signed int	int64_t;	//!< int64_t typedef
#endif


#ifdef __STDBOOL_DEF
#include <stdbool.h>	//!< Include stdbool.h
#endif
#ifdef __STDINT_DEF
#include <stdint.h>		//!< Include stdint.h
#endif

typedef int					intCPU_t;	//!< Signed integer typedef
typedef unsigned int		uintCPU_t;	//!< Unsigned integer typedef

#if defined(__UINTPTR_TYPE__) && defined(__INTPTR_TYPE__)
typedef __INTPTR_TYPE__		intPTR_t;	//!< Signed integer pointer address typedef
typedef __UINTPTR_TYPE__	uintPTR_t;	//!< Unsigned integer pointer address typedef
#elif defined(__SIZEOF_POINTER__) && defined (__SIZEOF_INT__) && (__SIZEOF_POINTER__ == __SIZEOF_INT__)
typedef intCPU_t			intPTR_t;	//!< Signed integer pointer address typedef
typedef uintCPU_t			uintPTR_t;	//!< Unsigned integer pointer address typedef
#elif defined(__SIZEOF_POINTER__) && (__SIZEOF_POINTER__ <= 2)
typedef int16_t				intPTR_t;	//!< Signed integer pointer address typedef
typedef uint16_t			uintPTR_t;	//!< Unsigned integer pointer address typedef
#elif defined(__SIZEOF_POINTER__) && (__SIZEOF_POINTER__ <= 4)
typedef int32_t				intPTR_t;	//!< Signed integer pointer address typedef
typedef uint32_t			uintPTR_t;	//!< Unsigned integer pointer address typedef
#elif defined(__SIZEOF_POINTER__) && (__SIZEOF_POINTER__ <= 8)
typedef int64_t				intPTR_t;	//!< Signed integer pointer address typedef
typedef uint64_t			uintPTR_t;	//!< Unsigned integer pointer address typedef
#else
#error "Not able to automatically define pointer size, __SIZEOF_POINTER__ define needed with size in bytes"
#endif

typedef	bool				BOOL;		//!< boolean typedef (1bit, for stdbool.h handling compilers)
typedef char				CHAR;		//!< Char typedef (8bits)
typedef	uint8_t				BYTE;		//!< Unsigned Byte typedef (8bits)
typedef	uint16_t			WORD;		//!< Unsigned Word typedef (16bits)
typedef	uint32_t			DWORD;		//!< Unsigned dWord typedef (32bits)
typedef	uint64_t			LWORD;		//!< Unsigned lWord typedef (64bits)
typedef	int8_t				SBYTE;		//!< Signed Byte typedef (8bits)
typedef	int16_t				SWORD;		//!< Signed Word typedef (16bits)
typedef	int32_t				SDWORD;		//!< Signed dWord typedef (32bits)
typedef	int64_t				SLWORD;		//!< Signed lWord typedef (64bits)


#if 	defined(__BYTE_ORDER) && (__BYTE_ORDER == __BIG_ENDIAN) ||								\
		defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) ||					\
		defined(__FLOAT_WORD_ORDER__) && (__FLOAT_WORD_ORDER__ == __ORDER_BIG_ENDIAN__) ||		\
		defined(__BIG_ENDIAN__) ||																\
		defined(__ARMEB__) || defined(__THUMBEB__) || defined(__AARCH64EB__) ||					\
		defined(_MIPSEB) || defined(__MIPSEB) || defined(__MIPSEB__)
	#ifndef __BIG_ENDIAN__
		#define __BIG_ENDIAN__		//!< Big-endian target
	#endif
#elif	defined(__BYTE_ORDER) && (__BYTE_ORDER == __LITTLE_ENDIAN) ||							\
		defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) ||				\
		defined(__FLOAT_WORD_ORDER__) && (__FLOAT_WORD_ORDER__ == __ORDER_LITTLE_ENDIAN__) ||	\
		defined(__LITTLE_ENDIAN__) ||															\
		defined(__ARMEL__) || defined(__THUMBEL__) || defined(__AARCH64EL__) ||					\
		defined(_MIPSEL) || defined(__MIPSEL) || defined(__MIPSEL__)
	#ifndef __LITTLE_ENDIAN__
		#define __LITTLE_ENDIAN__	//!< Little-endian target
	#endif
#elif	defined(__BYTE_ORDER) && (__BYTE_ORDER == __PDP_ENDIAN)
	#warning "Unfortunately, easy-access typedefs for PDP Endian not handled by the sarmfw library!"
	#ifndef __PDP_ENDIAN__
		#define __PDP_ENDIAN__		//!< Little-endian (word swapped) target
	#endif
#else
	#warning "Unknown endianness, please define LITTLE_ENDIAN or BIG_ENDIAN symbol to ensure behavior!"
#endif


/*!\enum _eState
** \brief Activation state On, Off
**/
typedef enum _eState {
	Off = 0U,	//!< Off / Reset
	On = 1U		//!< On / Set
} eState;


/*!\enum _eEdge
** \brief Signal Edges
**/
typedef enum _eEdge {
	NoEdge = 0,	//!< No change
	Rising,		//!< Rising edge
	Falling		//!< Falling edge
} eEdge;


/*!\enum _eGPIOState
** \brief GPIO possible states/actions enumeration
**/
typedef enum _eGPIOState {
	Reset = 0,	//!< Reset State
	Set,		//!< Set State
	Toggle		//!< Toggle Output
	//! \note Toggle is only GPIO output related
} eGPIOState;

/*!\enum _eGPIOPull
** \brief GPIO possible pull resistor configuration
**/
typedef enum _eGPIOPull {
	PullDown = 0,	//!< GPIO with pull down
	PullUp,			//!< GPIO with pull up
	NoPull			//!< GPIO without pull
} eGPIOPull;


/*!\struct sBitfield8
** \brief Bitfield 8b
**/
typedef struct _sBitfield8 {
	#ifndef REVERSE_BITFIELD
		BYTE	b0	:1;	//!< Bit 0 (LSB)
		BYTE	b1	:1;	//!< Bit 1
		BYTE	b2	:1;	//!< Bit 2
		BYTE	b3	:1;	//!< Bit 3
		BYTE	b4	:1;	//!< Bit 4
		BYTE	b5	:1;	//!< Bit 5
		BYTE	b6	:1;	//!< Bit 6
		BYTE	b7	:1;	//!< Bit 7 (MSB)
	#else
		BYTE	b7	:1;	//!< Bit 7 (MSB)
		BYTE	b6	:1;	//!< Bit 6
		BYTE	b5	:1;	//!< Bit 5
		BYTE	b4	:1;	//!< Bit 4
		BYTE	b3	:1;	//!< Bit 3
		BYTE	b2	:1;	//!< Bit 2
		BYTE	b1	:1;	//!< Bit 1
		BYTE	b0	:1;	//!< Bit 0 (LSB)
	#endif
} sBitfield8;

/*!\struct sBitfield16
** \brief Bitfield 16b
**/
typedef struct _sBitfield16 {
	#ifndef REVERSE_BITFIELD
		WORD	b0	:1;	//!< Bit 0 (LSB)
		WORD	b1	:1;	//!< Bit 1
		WORD	b2	:1;	//!< Bit 2
		WORD	b3	:1;	//!< Bit 3
		WORD	b4	:1;	//!< Bit 4
		WORD	b5	:1;	//!< Bit 5
		WORD	b6	:1;	//!< Bit 6
		WORD	b7	:1;	//!< Bit 7
		WORD	b8	:1;	//!< Bit 8
		WORD	b9	:1;	//!< Bit 9
		WORD	b10	:1;	//!< Bit 10
		WORD	b11	:1;	//!< Bit 11
		WORD	b12	:1;	//!< Bit 12
		WORD	b13	:1;	//!< Bit 13
		WORD	b14	:1;	//!< Bit 14
		WORD	b15	:1;	//!< Bit 15 (MSB)
	#else
		WORD	b15	:1;	//!< Bit 15 (MSB)
		WORD	b14	:1;	//!< Bit 14
		WORD	b13	:1;	//!< Bit 13
		WORD	b12	:1;	//!< Bit 12
		WORD	b11	:1;	//!< Bit 11
		WORD	b10	:1;	//!< Bit 10
		WORD	b9	:1;	//!< Bit 9
		WORD	b8	:1;	//!< Bit 8
		WORD	b7	:1;	//!< Bit 7
		WORD	b6	:1;	//!< Bit 6
		WORD	b5	:1;	//!< Bit 5
		WORD	b4	:1;	//!< Bit 4
		WORD	b3	:1;	//!< Bit 3
		WORD	b2	:1;	//!< Bit 2
		WORD	b1	:1;	//!< Bit 1
		WORD	b0	:1;	//!< Bit 0 (LSB)
	#endif
} sBitfield16;

/*!\struct sBitfield32
** \brief Bitfield 32b
**/
typedef struct _sBitfield32 {
	#ifndef REVERSE_BITFIELD
		DWORD	b0	:1;	//!< Bit 0 (LSB)
		DWORD	b1	:1;	//!< Bit 1
		DWORD	b2	:1;	//!< Bit 2
		DWORD	b3	:1;	//!< Bit 3
		DWORD	b4	:1;	//!< Bit 4
		DWORD	b5	:1;	//!< Bit 5
		DWORD	b6	:1;	//!< Bit 6
		DWORD	b7	:1;	//!< Bit 7
		DWORD	b8	:1;	//!< Bit 8
		DWORD	b9	:1;	//!< Bit 9
		DWORD	b10	:1;	//!< Bit 10
		DWORD	b11	:1;	//!< Bit 11
		DWORD	b12	:1;	//!< Bit 12
		DWORD	b13	:1;	//!< Bit 13
		DWORD	b14	:1;	//!< Bit 14
		DWORD	b15	:1;	//!< Bit 15
		DWORD	b16	:1;	//!< Bit 16
		DWORD	b17	:1;	//!< Bit 17
		DWORD	b18	:1;	//!< Bit 18
		DWORD	b19	:1;	//!< Bit 19
		DWORD	b20	:1;	//!< Bit 20
		DWORD	b21	:1;	//!< Bit 21
		DWORD	b22	:1;	//!< Bit 22
		DWORD	b23	:1;	//!< Bit 23
		DWORD	b24	:1;	//!< Bit 24
		DWORD	b25	:1;	//!< Bit 25
		DWORD	b26	:1;	//!< Bit 26
		DWORD	b27	:1;	//!< Bit 27
		DWORD	b28	:1;	//!< Bit 28
		DWORD	b29	:1;	//!< Bit 29
		DWORD	b30	:1;	//!< Bit 30
		DWORD	b31	:1;	//!< Bit 31 (MSB)
	#else
		DWORD	b31	:1;	//!< Bit 31 (MSB)
		DWORD	b30	:1;	//!< Bit 30
		DWORD	b29	:1;	//!< Bit 29
		DWORD	b28	:1;	//!< Bit 28
		DWORD	b27	:1;	//!< Bit 27
		DWORD	b26	:1;	//!< Bit 26
		DWORD	b25	:1;	//!< Bit 25
		DWORD	b24	:1;	//!< Bit 24
		DWORD	b23	:1;	//!< Bit 23
		DWORD	b22	:1;	//!< Bit 22
		DWORD	b21	:1;	//!< Bit 21
		DWORD	b20	:1;	//!< Bit 20
		DWORD	b19	:1;	//!< Bit 19
		DWORD	b18	:1;	//!< Bit 18
		DWORD	b17	:1;	//!< Bit 17
		DWORD	b16	:1;	//!< Bit 16
		DWORD	b15	:1;	//!< Bit 15
		DWORD	b14	:1;	//!< Bit 14
		DWORD	b13	:1;	//!< Bit 13
		DWORD	b12	:1;	//!< Bit 12
		DWORD	b11	:1;	//!< Bit 11
		DWORD	b10	:1;	//!< Bit 10
		DWORD	b9	:1;	//!< Bit 9
		DWORD	b8	:1;	//!< Bit 8
		DWORD	b7	:1;	//!< Bit 7
		DWORD	b6	:1;	//!< Bit 6
		DWORD	b5	:1;	//!< Bit 5
		DWORD	b4	:1;	//!< Bit 4
		DWORD	b3	:1;	//!< Bit 3
		DWORD	b2	:1;	//!< Bit 2
		DWORD	b1	:1;	//!< Bit 1
		DWORD	b0	:1;	//!< Bit 0 (LSB)
	#endif
} sBitfield32;

/*!\struct sBitfield64
** \brief Bitfield 64b
**/
typedef struct _sBitfield64 {
	#ifndef REVERSE_BITFIELD
		LWORD	b0	:1;	//!< Bit 0 (LSB)
		LWORD	b1	:1;	//!< Bit 1
		LWORD	b2	:1;	//!< Bit 2
		LWORD	b3	:1;	//!< Bit 3
		LWORD	b4	:1;	//!< Bit 4
		LWORD	b5	:1;	//!< Bit 5
		LWORD	b6	:1;	//!< Bit 6
		LWORD	b7	:1;	//!< Bit 7
		LWORD	b8	:1;	//!< Bit 8
		LWORD	b9	:1;	//!< Bit 9
		LWORD	b10	:1;	//!< Bit 10
		LWORD	b11	:1;	//!< Bit 11
		LWORD	b12	:1;	//!< Bit 12
		LWORD	b13	:1;	//!< Bit 13
		LWORD	b14	:1;	//!< Bit 14
		LWORD	b15	:1;	//!< Bit 15
		LWORD	b16	:1;	//!< Bit 16
		LWORD	b17	:1;	//!< Bit 17
		LWORD	b18	:1;	//!< Bit 18
		LWORD	b19	:1;	//!< Bit 19
		LWORD	b20	:1;	//!< Bit 20
		LWORD	b21	:1;	//!< Bit 21
		LWORD	b22	:1;	//!< Bit 22
		LWORD	b23	:1;	//!< Bit 23
		LWORD	b24	:1;	//!< Bit 24
		LWORD	b25	:1;	//!< Bit 25
		LWORD	b26	:1;	//!< Bit 26
		LWORD	b27	:1;	//!< Bit 27
		LWORD	b28	:1;	//!< Bit 28
		LWORD	b29	:1;	//!< Bit 29
		LWORD	b30	:1;	//!< Bit 30
		LWORD	b31	:1;	//!< Bit 31
		LWORD	b32	:1;	//!< Bit 32
		LWORD	b33	:1;	//!< Bit 33
		LWORD	b34	:1;	//!< Bit 34
		LWORD	b35	:1;	//!< Bit 35
		LWORD	b36	:1;	//!< Bit 36
		LWORD	b37	:1;	//!< Bit 37
		LWORD	b38	:1;	//!< Bit 38
		LWORD	b39	:1;	//!< Bit 39
		LWORD	b40	:1;	//!< Bit 40
		LWORD	b41	:1;	//!< Bit 41
		LWORD	b42	:1;	//!< Bit 42
		LWORD	b43	:1;	//!< Bit 43
		LWORD	b44	:1;	//!< Bit 44
		LWORD	b45	:1;	//!< Bit 45
		LWORD	b46	:1;	//!< Bit 46
		LWORD	b47	:1;	//!< Bit 47
		LWORD	b48	:1;	//!< Bit 48
		LWORD	b49	:1;	//!< Bit 49
		LWORD	b50	:1;	//!< Bit 50
		LWORD	b51	:1;	//!< Bit 51
		LWORD	b52	:1;	//!< Bit 52
		LWORD	b53	:1;	//!< Bit 53
		LWORD	b54	:1;	//!< Bit 54
		LWORD	b55	:1;	//!< Bit 55
		LWORD	b56	:1;	//!< Bit 56
		LWORD	b57	:1;	//!< Bit 57
		LWORD	b58	:1;	//!< Bit 58
		LWORD	b59	:1;	//!< Bit 59
		LWORD	b60	:1;	//!< Bit 60
		LWORD	b61	:1;	//!< Bit 61
		LWORD	b62	:1;	//!< Bit 62
		LWORD	b63	:1;	//!< Bit 63 (MSB)
	#else
		LWORD	b63	:1;	//!< Bit 63 (MSB)
		LWORD	b62	:1;	//!< Bit 62
		LWORD	b61	:1;	//!< Bit 61
		LWORD	b60	:1;	//!< Bit 60
		LWORD	b59	:1;	//!< Bit 59
		LWORD	b58	:1;	//!< Bit 58
		LWORD	b57	:1;	//!< Bit 57
		LWORD	b56	:1;	//!< Bit 56
		LWORD	b55	:1;	//!< Bit 55
		LWORD	b54	:1;	//!< Bit 54
		LWORD	b53	:1;	//!< Bit 53
		LWORD	b52	:1;	//!< Bit 52
		LWORD	b51	:1;	//!< Bit 51
		LWORD	b50	:1;	//!< Bit 50
		LWORD	b49	:1;	//!< Bit 49
		LWORD	b48	:1;	//!< Bit 48
		LWORD	b47	:1;	//!< Bit 47
		LWORD	b46	:1;	//!< Bit 46
		LWORD	b45	:1;	//!< Bit 45
		LWORD	b44	:1;	//!< Bit 44
		LWORD	b43	:1;	//!< Bit 43
		LWORD	b42	:1;	//!< Bit 42
		LWORD	b41	:1;	//!< Bit 41
		LWORD	b40	:1;	//!< Bit 40
		LWORD	b39	:1;	//!< Bit 39
		LWORD	b38	:1;	//!< Bit 38
		LWORD	b37	:1;	//!< Bit 37
		LWORD	b36	:1;	//!< Bit 36
		LWORD	b35	:1;	//!< Bit 35
		LWORD	b34	:1;	//!< Bit 34
		LWORD	b33	:1;	//!< Bit 33
		LWORD	b32	:1;	//!< Bit 32
		LWORD	b31	:1;	//!< Bit 31
		LWORD	b30	:1;	//!< Bit 30
		LWORD	b29	:1;	//!< Bit 29
		LWORD	b28	:1;	//!< Bit 28
		LWORD	b27	:1;	//!< Bit 27
		LWORD	b26	:1;	//!< Bit 26
		LWORD	b25	:1;	//!< Bit 25
		LWORD	b24	:1;	//!< Bit 24
		LWORD	b23	:1;	//!< Bit 23
		LWORD	b22	:1;	//!< Bit 22
		LWORD	b21	:1;	//!< Bit 21
		LWORD	b20	:1;	//!< Bit 20
		LWORD	b19	:1;	//!< Bit 19
		LWORD	b18	:1;	//!< Bit 18
		LWORD	b17	:1;	//!< Bit 17
		LWORD	b16	:1;	//!< Bit 16
		LWORD	b15	:1;	//!< Bit 15
		LWORD	b14	:1;	//!< Bit 14
		LWORD	b13	:1;	//!< Bit 13
		LWORD	b12	:1;	//!< Bit 12
		LWORD	b11	:1;	//!< Bit 11
		LWORD	b10	:1;	//!< Bit 10
		LWORD	b9	:1;	//!< Bit 9
		LWORD	b8	:1;	//!< Bit 8
		LWORD	b7	:1;	//!< Bit 7
		LWORD	b6	:1;	//!< Bit 6
		LWORD	b5	:1;	//!< Bit 5
		LWORD	b4	:1;	//!< Bit 4
		LWORD	b3	:1;	//!< Bit 3
		LWORD	b2	:1;	//!< Bit 2
		LWORD	b1	:1;	//!< Bit 1
		LWORD	b0	:1;	//!< Bit 0 (LSB)
	#endif
} sBitfield64;


// Undefine binary.h definitions used here
//!\MISRA Local deviation has been granted for following rules:\n
//!	\b Rule-20.5 - \b Advisory: \c \#undef (misra-c2012-20.5)\n
#if defined(B0)
#undef B0	// cppcheck-suppress misra-c2012-20.5
#endif
#if defined(B1)
#undef B1	// cppcheck-suppress misra-c2012-20.5
#endif

/*!\union uByte
** \brief Union for BYTE
**/
typedef union _uByte {
	BYTE		Byte;	//!< BYTE
	sBitfield8	Bits;	//!< Bits
} uByte;

/*!\union uWord
** \brief Union for WORD
**/
typedef union _uWord {
	WORD			Word;		//!< 16b
	BYTE			Byte[2];	//!< Bytes tab
	struct {
		#ifdef __LITTLE_ENDIAN__
			BYTE	B0 :8;		//!< LSByte
			BYTE	B1 :8;		//!< MSByte
		#else
			BYTE	B1 :8;		//!< MSByte
			BYTE	B0 :8;		//!< LSByte
		#endif
	} Bytes;
	sBitfield16		Bits;		//!< Bits
} uWord;

/*!\union uDWord
** \brief Union for DWORD
**/
typedef union _uDWord {
	DWORD			DWord;		//!< 32b
	WORD			Word[2];	//!< Words tab
	BYTE			Byte[4];	//!< Bytes tab
	struct {
		#ifdef __LITTLE_ENDIAN__
			WORD	W0 :16;		//!< W0 LSWord
			WORD	W1 :16;		//!< W1 MSWord
		#else
			WORD	W1 :16;		//!< W1 MSWord
			WORD	W0 :16;		//!< W0 LSWord
		#endif
	} Words;
	struct {
		#ifdef __LITTLE_ENDIAN__
			BYTE	B0 :8;		//!< B0 LSByte
			BYTE	B1 :8;		//!< B1
			BYTE	B2 :8;		//!< B2
			BYTE	B3 :8;		//!< B3 MSByte
		#else
			BYTE	B3 :8;		//!< B3 MSByte
			BYTE	B2 :8;		//!< B2
			BYTE	B1 :8;		//!< B1
			BYTE	B0 :8;		//!< B0 LSByte
		#endif
	} Bytes;
	sBitfield32		Bits;		//!< Bits
} uDWord;

/*!\union uLWord
** \brief Union for LWORD
**/
typedef union _uLWord {
	LWORD			LWord;		//!< 64b
	DWORD			DWord[2];	//!< DWords tab
	WORD			Word[4];	//!< Words tab
	BYTE			Byte[8];	//!< Bytes tab
	struct {
		#ifdef __LITTLE_ENDIAN__
			DWORD	D0 :32;		//!< DW0 LSDWord
			DWORD	D1 :32;		//!< DW1 MSDWord
		#else
			DWORD	D1 :32;		//!< DW1 MSDWord
			DWORD	D0 :32;		//!< DW0 LSDWord
		#endif
	} DWords;
	struct {
		#ifdef __LITTLE_ENDIAN__
			WORD	W0 :16;		//!< W0 LSWord
			WORD	W1 :16;		//!< W1
			WORD	W2 :16;		//!< W2
			WORD	W3 :16;		//!< W3 MSWord
		#else
			WORD	W3 :16;		//!< W3 MSWord
			WORD	W2 :16;		//!< W2
			WORD	W1 :16;		//!< W1
			WORD	W0 :16;		//!< W0 LSWord
		#endif
	} Words;
	struct {
		#ifdef __LITTLE_ENDIAN__
			BYTE	B0 :8;		//!< B0 LSByte
			BYTE	B1 :8;		//!< B1
			BYTE	B2 :8;		//!< B2
			BYTE	B3 :8;		//!< B3
			BYTE	B4 :8;		//!< B4
			BYTE	B5 :8;		//!< B5
			BYTE	B6 :8;		//!< B6
			BYTE	B7 :8;		//!< B7 MSByte
		#else
			BYTE	B7 :8;		//!< B7 MSByte
			BYTE	B6 :8;		//!< B6
			BYTE	B5 :8;		//!< B5
			BYTE	B4 :8;		//!< B4
			BYTE	B3 :8;		//!< B3
			BYTE	B2 :8;		//!< B2
			BYTE	B1 :8;		//!< B1
			BYTE	B0 :8;		//!< B0 LSByte
		#endif
	} Bytes;
	sBitfield64		Bits;		//!< Bits
} uLWord;


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_TYPEDEFS_H_ */
// cppcheck-suppress-end [misra-c2012-19.2]
// cppcheck-suppress-end [misra-c2012-21.1]
/****************************************************************/
