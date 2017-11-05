/*!\file arm_typedefs.h
** \author SMFSW
** \date 2017
** \copyright MIT (c) 2017, SMFSW
** \brief ARM common typedefs
*/
/****************************************************************/
#ifndef __ARM_TYPEDEFS_H
	#define __ARM_TYPEDEFS_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
/****************************************************************/


typedef char		CHAR;		//!< Char typedef (8bits)
typedef	uint8_t		BYTE;		//!< Unsigned Byte typedef (8bits)
typedef	uint16_t	WORD;		//!< Unsigned Word typedef (16bits)
typedef	uint32_t	DWORD;		//!< Unsigned dWord typedef (32bits)
typedef	uint64_t	LWORD;		//!< Unsigned lWord typedef (64bits)
typedef	int8_t		SBYTE;		//!< Signed Byte typedef (8bits)
typedef	int16_t		SWORD;		//!< Signed Word typedef (16bits)
typedef	int32_t		SDWORD;		//!< Signed dWord typedef (32bits)
typedef	int64_t		SLWORD;		//!< Signed lWord typedef (64bits)


/*!\enum eState
** \brief Activation state On, Off
**/
typedef enum eState{
	Off = 0U,	//!< Off / Clear
	On = 1U		//!< On / Set
} eState;

/*!\enum eEdge
** \brief Signal Edges
**/
typedef enum eEdge {
	NoEdge = 0,	//!< No change
	Rising,		//!< Rising edge
	Falling		//!< Falling edge
} eEdge;


/*!\struct StructBitfield8
** \brief Bitfield 8b
**/
typedef struct StructBitfield8{
	BYTE	b0	:1;	//!< Bit 0 (LSB)
	BYTE	b1	:1;	//!< Bit 1
	BYTE	b2	:1;	//!< Bit 2
	BYTE	b3	:1;	//!< Bit 3
	BYTE	b4	:1;	//!< Bit 4
	BYTE	b5	:1;	//!< Bit 5
	BYTE	b6	:1;	//!< Bit 6
	BYTE	b7	:1;	//!< Bit 7 (MSB)
} sBitfield8;

/*!\struct StructBitfield16
** \brief Bitfield 16b
**/
typedef struct StructBitfield16{
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
} sBitfield16;

/*!\struct StructBitfield32
** \brief Bitfield 32b
**/
typedef struct StructBitfield32{
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
} sBitfield32;

/*!\struct StructBitfield64
** \brief Bitfield 64b
**/
typedef struct StructBitfield64{
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
} sBitfield64;


/*!\union UnionByte
** \brief Union for BYTE
**/
typedef union UnionByte{
	BYTE		Byte;	//!< BYTE
	sBitfield8	Bits;	//!< Bits
} uByte;

/*!\union UnionWord
** \brief Union for WORD
**/
typedef union UnionWord{
	WORD			Word;		//!< 16b
	BYTE			Byte[2];	//!< Bytes tab
	struct {
		BYTE		B0 :8;		//!< LSByte
		BYTE		B1 :8;		//!< MSByte
	} Bytes;
	sBitfield16		Bits;		//!< Bits
} uWord;

/*!\union UnionDWord
** \brief Union for DWORD
**/
typedef union UnionDWord{
	DWORD			DWord;		//!< 32b
	WORD			Word[2];	//!< Words tab
	BYTE			Byte[4];	//!< Bytes tab
	struct {
		WORD		W0 :16;		//!< W0 LSWord
		WORD		W1 :16;		//!< W1 MSWord
	} Words;
	struct {
		BYTE		B0 :8;		//!< B0 LSByte
		BYTE		B1 :8;		//!< B1
		BYTE		B2 :8;		//!< B2
		BYTE		B3 :8;		//!< B3 MSByte
	} Bytes;
	sBitfield32		Bits;		//!< Bits
} uDWord;

/*!\union UnionLWord
** \brief Union for LWORD
**/
typedef union UnionLWord{
	LWORD			LWord;		//!< 64b
	DWORD			DWord[2];	//!< DWords tab
	WORD			Word[4];	//!< Words tab
	BYTE			Byte[8];	//!< Bytes tab
	struct {
		DWORD		D0 :32;		//!< DW0 LSDWord
		DWORD		D1 :32;		//!< DW1 MSDWord
	} DWords;
	struct {
		WORD		W0 :16;		//!< W0 LSWord
		WORD		W1 :16;		//!< W1
		WORD		W2 :16;		//!< W2
		WORD		W3 :16;		//!< W3 MSWord
	} Words;
	struct {
		BYTE		B0 :8;		//!< B0 LSByte
		BYTE		B1 :8;		//!< B1
		BYTE		B2 :8;		//!< B2
		BYTE		B3 :8;		//!< B3
		BYTE		B4 :8;		//!< B4
		BYTE		B5 :8;		//!< B5
		BYTE		B6 :8;		//!< B6
		BYTE		B7 :8;		//!< B7 MSByte
	} Bytes;
	sBitfield64		Bits;		//!< Bits
} uLWord;


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_TYPEDEFS_H */
/****************************************************************/
