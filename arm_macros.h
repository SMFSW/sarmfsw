/*!\file arm_macros.h
** \author SMFSW
** \copyright MIT (c) 2017-2023, SMFSW
** \brief ARM common macros
** \note If used CPU only handles single shifts, you may define SINGLE_SHIFT_ONLY_OPCODE at project level (see \ref LSHIFT & \ref RSHIFT)
*/
/****************************************************************/
#ifndef __ARM_MACROS_H
	#define __ARM_MACROS_H

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


#define	Undefined			(-1)			//!< Undefined value

#define Null				(0)				//!< Null Value
#define pNull				((void *) 0)	//!< Null pointer -> same as NULL in stdlib.h
#define	charNull			'\0'			//!< Null Char


#ifndef True
	#define	True			true			//!< \b True alias for \b true
#endif
#ifndef False
	#define	False			false			//!< \b False alias for \b false
#endif
#ifndef TRUE
	#define	TRUE			true			//!< \b TRUE alias for \b true
#endif
#ifndef FALSE
	#define	FALSE			false			//!< \b FALSE alias for \b false
#endif


#define GET_BITS(v, b)			(v & (b))					//!< Get bits from mask \b b of variable \b v
#define SET_BITS(v, b)			(v |= (b))					//!< Set bits \b b of variable \b v
#define CLR_BITS(v, b)			(v &= ~(b))					//!< Clear bits \b b of variable \b v
#define INV_BITS(v, b)			(v ^= (b))					//!< Invert bits \b b of variable \b v

#define SET_BITS_VAL(v, c, s)	(v = ((v & ~(c)) | (s)))	//!< Set variable \b v with clear mask \b c to set mask \b s


#if defined(SINGLE_SHIFT_ONLY_OPCODE)

//!\warning this macro is optimized only when \b n is a static value
#define LSHIFT_CAST(t, v, n)	((t) ((t) (v) * ((t) 1U << n)))
//!\warning this macro is optimized only when \b n is a static value
#define RSHIFT_CAST(t, v, n)	((t) ((t) (v) / ((t) 1U << n)))

//!\warning this macro is optimized only when \b n is a static value
//!\note sarmfsw library being optimized for 32b architecture, default shifting behavior set to 32b
#define LSHIFT(v, n)			((DWORD) ((v) * (1UL << n))		//!< Shift \b v \b n bits left
//!\warning this macro is optimized only when \b n is a static value
//!\note sarmfsw library being optimized for 32b architecture, default shifting behavior set to 32b
#define RSHIFT(v, n)			((DWORD) ((v) / (1UL << n))		//!< Shift \b v \b n bits right

//!\warning this macro is optimized only when \b n is a static value
#define LSHIFT8(v, n)			LSHIFT_CAST(BYTE, v, n)			//!< Shift \b v \b n bits left (up to 7b)
//!\warning this macro is optimized only when \b n is a static value
#define RSHIFT8(v, n)			RSHIFT_CAST(BYTE, v, n)			//!< Shift \b v \b n bits right (up to 7b)

//!\warning this macro is optimized only when \b n is a static value
#define LSHIFT16(v, n)			LSHIFT_CAST(WORD, v, n)			//!< Shift \b v \b n bits left (up to 15b)
//!\warning this macro is optimized only when \b n is a static value
#define RSHIFT16(v, n)			RSHIFT_CAST(WORD, v, n)			//!< Shift \b v \b n bits right (up to 15b)

//!\warning this macro is optimized only when \b n is a static value
#define LSHIFT32(v, n)			LSHIFT_CAST(DWORD, v, n)		//!< Shift \b v \b n bits left (up to 31b)
//!\warning this macro is optimized only when \b n is a static value
#define RSHIFT32(v, n)			RSHIFT_CAST(DWORD, v, n)		//!< Shift \b v \b n bits right (up to 31b)

//!\warning this macro is optimized only when \b n is a static value
#define LSHIFT64(v, n)			LSHIFT_CAST(LWORD, v, n)		//!< Shift \b v \b n bits left (up to 63b)
//!\warning this macro is optimized only when \b n is a static value
#define RSHIFT64(v, n)			RSHIFT_CAST(LWORD, v, n)		//!< Shift \b v \b n bits right (up to 63b)

#else

//!\note sarmfsw library being optimized for 32b architecture, default shifting behavior set to 32b
#define LSHIFT(v, n)			((DWORD) ((DWORD) (v) << n))	//!< Shift \b v \b n bits left
//!\note sarmfsw library being optimized for 32b architecture, default shifting behavior set to 32b
#define RSHIFT(v, n)			((DWORD) ((DWORD) (v) >> n))	//!< Shift \b v \b n bits right

#define LSHIFT8(v, n)			((BYTE) ((BYTE) (v) << n))		//!< Shift \b v \b n bits left (up to 7b)
#define RSHIFT8(v, n)			((BYTE) ((BYTE) (v) >> n))		//!< Shift \b v \b n bits right (up to 7b)

#define LSHIFT16(v, n)			((WORD) ((WORD) (v) << n))		//!< Shift \b v \b n bits left (up to 15b)
#define RSHIFT16(v, n)			((WORD) ((WORD) (v) >> n))		//!< Shift \b v \b n bits right (up to 15b)

#define LSHIFT32(v, n)			((DWORD) ((DWORD) (v) << n))	//!< Shift \b v \b n bits left (up to 31b)
#define RSHIFT32(v, n)			((DWORD) ((DWORD) (v) >> n))	//!< Shift \b v \b n bits right (up to 31b)

#define LSHIFT64(v, n)			((LWORD) ((LWORD) (v) << n))	//!< Shift \b v \b n bits left (up to 63b)
#define RSHIFT64(v, n)			((LWORD) ((LWORD) (v) >> n))	//!< Shift \b v \b n bits right (up to 63b)

#endif


#define MAKEWORD(lsb, msb)		((WORD) (((BYTE) (lsb)) | LSHIFT(((WORD) ((BYTE) (msb))), 8)))		//!< Make WORD from \b lsb and \b msb
#define MAKELONG(lsw, msw)		((DWORD) (((WORD) (lsw)) | LSHIFT(((DWORD) ((WORD) (msw))), 16)))	//!< Make LONG from \b lsw and \b msw

#ifdef LOBYTE
#undef LOBYTE	//!\note Undefine LOBYTE if already defined in some other library
#endif

#ifdef HIBYTE
#undef HIBYTE	//!\note Undefine HIBYTE if already defined in some other library
#endif

#define LOBYTE(w)				((BYTE) (w))						//!< Get BYTE LSB from WORD \b w
#define HIBYTE(w)				((BYTE) RSHIFT((WORD) (w), 8))		//!< Get BYTE MSB from WORD \b w
#define LOWORD(l)				((WORD) (l))						//!< Get WORD LSW from LONG \b l
#define HIWORD(l)				((WORD) RSHIFT((DWORD) (l), 16))	//!< Get WORD MSW from LONG \b l

#define	SWAP_TYPE(a, b, typ)	{ typ c = a; a = b; b = c; }		//!< Swap type \b typ \b a \& \b b
#define	SWAP_BYTE(a, b)			SWAP_TYPE(a, b, BYTE)				//!< Swap BYTEs \b a \& \b b
#define	SWAP_WORD(a, b)			SWAP_TYPE(a, b, WORD)				//!< Swap WORDs \b a \& \b b
#define	SWAP_DWORD(a, b)		SWAP_TYPE(a, b, DWORD)				//!< Swap DWORDs \b a \& \b b
#define	SWAP_LWORD(a, b)		SWAP_TYPE(a, b, LWORD)				//!< Swap LWORDs \b a \& \b b
#define	SWAP_FLOAT(a, b)		SWAP_TYPE(a, b, float)				//!< Swap floats \b a \& \b b
#define	SWAP_DOUBLE(a, b)		SWAP_TYPE(a, b, double)				//!< Swap doubles \b a \& \b b


#define VAL_AT(addr, typ)		(*(typ *) (addr))										//!< Get the type \b typ content of address \b addr

#define SZ_ARRAY(arr)			((size_t) (sizeof(arr) / sizeof(arr[0])))				//!< Computes the number of array elements in \b arr
#define SZ_OBJ(obj, typ)		((size_t) (sizeof(obj) / sizeof(typ)))					//!< Computes the number of elements in \b obj of type \b typ
#define SZ_TYP_MBR(typ, mbr)	((size_t) sizeof(((typ *)0)->mbr))						//!< Computes the size of member \b mbr in struct type \b typ

#define TYP_MBR(typ, mbr)		(((typ *)0)->mbr)										//!< Get member \b mbr from a struct type \b typ
//! \warning use with caution, C language typeof extension works well with native types, yet can be the cause of big (experienced) issues with more complex ones
//! \note \b typeof C language extension should only be used to get a compiler native known type
#define TYP_MBR_TYP(typ, mbr)	typeof(TYP_MBR(typ, mbr))								//!< Get typeof member \b mbr from a struct type \b typ (no () as it wouldn't work for pointers to member type)

#define OFFSET_OF(typ, mbr)		((size_t) &(((typ *)0)->mbr))							//!< Computes the offset member \b mbr from struct type \b typ
#define ROOT_OF(ptr, typ, mbr)	((typ *) (((uint8_t *) ptr) - OFFSET_OF(typ, mbr)))		//!< Computes the address of parent struct \b typ of \b ptr from member \b mbr


//! \warning No nesting possible, use \ref XCAT instead (unless there is a good reason not to use \ref XCAT)
#define	CAT(a, b)			a##b			//!< Preprocessor Name catenation (use of \ref XCAT is highly recommended for any need)
#define XCAT(a, b)			CAT(a, b)		//!< Preprocessor Name catenation (possible nesting)

#define STR(s)				(#s)			//!< Stringify an expression


#define binEval(exp)		((exp) ? true : false)		//!< boolean evaluation of expression \b exp
#define nbinEval(exp)		(!binEval(exp))				//!< complemented boolean evaluation of expression \b exp


#ifdef min
#undef min		//!\note Undefine min if already defined in some other library
#endif
#ifdef MIN
#undef MIN		//!\note Undefine MIN if already defined in some other library
#endif
#define min					MIN								//!< \b min alias for \b MIN
#define MIN(a, b)			({	__TYPEOF(a) _a = (a);	\
								__TYPEOF(b) _b = (b);	\
								_a <= _b ? _a : _b; })		//!< Returns min value between \b a and \b b

#ifdef max
#undef max		//!\note Undefine max if already defined in some other library
#endif
#ifdef MAX
#undef MAX		//!\note Undefine MAX if already defined in some other library
#endif
#define max					MAX								//!< \b max alias for \b MAX
	#define MAX(a, b)		({	__TYPEOF(a) _a = (a);	\
								__TYPEOF(b) _b = (b);	\
								_a >= _b ? _a : _b; })		//!< Returns max value between \b a and \b b

#ifdef min3
#undef min3		//!\note Undefine min3 if already defined in some other library
#endif
#ifdef MIN3
#undef MIN3		//!\note Undefine MIN3 if already defined in some other library
#endif
#define min3				MIN3							//!< \b min3 alias for \b MIN3
#define	MIN3(a, b, c)		({	__TYPEOF(a) _a = (a);	\
								__TYPEOF(b) _b = (b);	\
								__TYPEOF(c) _c = (c);	\
								_b <= _c ? (_a <= _b ? _a : _b) : (_a <= _c ? _a : c); })	//!< Returns min value between \b a, \b b and \b c

#ifdef max3
#undef max3		//!\note Undefine max3 if already defined in some other library
#endif
#ifdef MAX3
#undef MAX3		//!\note Undefine MAX3 if already defined in some other library
#endif
#define max3				MAX3							//!< \b max3 alias for \b MAX3
#define	MAX3(a, b, c)		({	__TYPEOF(a) _a = (a);	\
								__TYPEOF(b) _b = (b);	\
								__TYPEOF(c) _c = (c);	\
								_b >= _c ? (_a >= _b ? _a : _b) : (_a >= _c ? _a : _c); })	//!< Returns max value between \b a, \b b and \b c

#ifdef clamp
#undef clamp	//!\note Undefine clamp if already defined in some other library
#endif
#ifdef CLAMP
#undef CLAMP	//!\note Undefine CLAMP if already defined in some other library
#endif
#define clamp				CLAMP							//!< \b clamp alias for \b CLAMP
#define CLAMP(v, mn, mx)	({	__TYPEOF(v) _v = (v);		\
								__TYPEOF(mn) _mn = (mn);	\
								__TYPEOF(mx) _mx = (mx);	\
								_v < _mn ? _mn : (_v > _mx ? _mx : _v); })	//!< Returns the value between \b mn and \b mx from \b val


//! \warning OVF_DIFF only works with unsigned integers
#define OVF_DIFF(a, b)		({	__TYPEOF(a) _a = (a);	\
								__TYPEOF(b) _b = (b);	\
								__TYPEOF(a) _max = -1;	\
								_a >= _b ? (_a - _b) : (_max - _b) + _a; })	//!< Returns difference of unsigned \b a and \b b (with potential overflow handliing)


//! \warning SCALE_VAL does not check types and is limited to MCU register size computation, for larger scales, use \ref SCALE_VAL_T or \ref scaleValue instead
#define SCALE_VAL(	v, from_min, from_max, to_min, to_max)		\
					(((((v) - from_min) * (to_max - to_min)) /	\
					(from_max - from_min)) + to_min)						//!< Scale value \b v from range \b from_min:from_max to range \b to_min:to_max

#define SCALE_VAL_T(typ, v, from_min, from_max, to_min, to_max)							\
					(((((typ) (v) - (typ) from_min) * ((typ) to_max - (typ) to_min)) /	\
					((typ) from_max - (typ) from_min)) + (typ) to_min)		//!< Scale typed \b typ value \b v from range \b from_min:from_max to range \b to_min:to_max


#define BYTE_TO_PERC(b)		((BYTE) ((((b) > 255 ? 255 : (b)) * 100) / 255))	//!< Converts a BYTE \b b (0-255) to percent (0-100)
#define PERC_TO_BYTE(p)		((BYTE) ((((p) > 100 ? 100 : (p)) * 255) / 100))	//!< Converts a BYTE \b p percentage (0-100) to BYTE (0-255) with max checking


/*** Constants ***/
#define M_1_3				(1.0 / 3.0)		//!< 1/3 constant approximation
#define M_2_3				(2.0 / 3.0)		//!< 2/3 constant approximation


/*** Test Macros ***/
#define malloc_assert(x)	((x) = malloc(sizeof(*x)), assert(x))	//!< Asserted malloc


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_MACROS_H */
/****************************************************************/
