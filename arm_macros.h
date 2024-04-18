/*!\file arm_macros.h
** \author SMFSW
** \copyright MIT (c) 2017-2024, SMFSW
** \brief ARM common macros
** \note If used CPU only handles single shifts, you may define SINGLE_SHIFT_ONLY_OPCODE at project level (see \ref LSHIFT & \ref RSHIFT)
** \MISRA Header scope deviation has been granted for following rules:\n
** 		\b Rule-1.2 - \b Advisory: Language extensions (misra-c2012-1.2)\n
** 		\b Rule-20.5 - \b Advisory: \c #undef (misra-c2012-20.5)\n
** 		\b Rule-20.10 - \b Advisory: \c # and \c ## preprocessor operators (misra-c2012-20.10)\n
*/
// cppcheck-suppress-begin [misra-c2012-1.2, misra-c2012-20.5, misra-c2012-20.10]
/****************************************************************/
#ifndef ARM_MACROS_H_
	#define ARM_MACROS_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


#define	Undefined			(-1)			//!< Undefined value

#define Null				(0)				//!< Null Value
#define pNull				((void *) 0)	//!< Null pointer -> same as NULL in stdlib.h
#define	charNull			('\0')			//!< Null Char


#ifndef True
	#define	True			true			//!< \c True alias for \c true
#endif
#ifndef False
	#define	False			false			//!< \c False alias for \c false
#endif
#ifndef TRUE
	#define	TRUE			true			//!< \c TRUE alias for \c true
#endif
#ifndef FALSE
	#define	FALSE			false			//!< \c FALSE alias for \c false
#endif


#define GET_BITS(v, b)			((v) & (b))						//!< Get bits from mask \p b of variable \p v
#define SET_BITS(v, b)			((v) |= (b))					//!< Set bits \p b of variable \p v
#define CLR_BITS(v, b)			((v) &= ~(b))					//!< Clear bits \p b of variable \p v
#define INV_BITS(v, b)			((v) ^= (b))					//!< Invert bits \p b of variable \p v

#define SET_BITS_VAL(v, c, s)	((v) = (((v) & ~(c)) | (s)))	//!< Set variable \p v with clear mask \p c to set mask \p s
#define TEST_BITS_VAL(v, b)		(((v) & (b)) == (b))			//!< Test variable \p v with bits \p b
#define TEST_MASK_VAL(v, m, r)	(((v) & (m)) == (r))			//!< Test variable \p v with bits mask \p m is equal to \p r


#if defined(SINGLE_SHIFT_ONLY_OPCODE)

//!\warning this macro is optimized only when \p n is a static value
#define LSHIFT_CAST(t, v, n)	((t) ((t) (v) * ((t) 1 << (n))))
//!\warning this macro is optimized only when \p n is a static value
#define RSHIFT_CAST(t, v, n)	((t) ((t) (v) / ((t) 1 << (n))))

//!\warning this macro is optimized only when \p n is a static value
#define LSHIFT(v, n)			((v) * (1U << (n)))				//!< Shift \p v \p n bits left
//!\warning this macro is optimized only when \p n is a static value
#define RSHIFT(v, n)			((v) / (1U << (n)))				//!< Shift \p v \p n bits right

//!\warning this macro is optimized only when \p n is a static value
#define LSHIFT8(v, n)			LSHIFT_CAST(BYTE, v, n)			//!< Shift \p v \p n bits left (up to 7b)
//!\warning this macro is optimized only when \p n is a static value
#define RSHIFT8(v, n)			RSHIFT_CAST(BYTE, v, n)			//!< Shift \p v \p n bits right (up to 7b)

//!\warning this macro is optimized only when \p n is a static value
#define LSHIFT16(v, n)			LSHIFT_CAST(WORD, v, n)			//!< Shift \p v \p n bits left (up to 15b)
//!\warning this macro is optimized only when \p n is a static value
#define RSHIFT16(v, n)			RSHIFT_CAST(WORD, v, n)			//!< Shift \p v \p n bits right (up to 15b)

//!\warning this macro is optimized only when \p n is a static value
#define LSHIFT32(v, n)			LSHIFT_CAST(DWORD, v, n)		//!< Shift \p v \p n bits left (up to 31b)
//!\warning this macro is optimized only when \p n is a static value
#define RSHIFT32(v, n)			RSHIFT_CAST(DWORD, v, n)		//!< Shift \p v \p n bits right (up to 31b)

//!\warning this macro is optimized only when \p n is a static value
#define LSHIFT64(v, n)			LSHIFT_CAST(LWORD, v, n)		//!< Shift \p v \p n bits left (up to 63b)
//!\warning this macro is optimized only when \p n is a static value
#define RSHIFT64(v, n)			RSHIFT_CAST(LWORD, v, n)		//!< Shift \p v \p n bits right (up to 63b)

#else

#define LSHIFT(v, n)			((v) << (n))					//!< Shift \p v \p n bits left
#define RSHIFT(v, n)			((v) >> (n))					//!< Shift \p v \p n bits right

#define LSHIFT8(v, n)			((BYTE) ((BYTE) (v) << (n)))	//!< Shift \p v \p n bits left (up to 7b)
#define RSHIFT8(v, n)			((BYTE) ((BYTE) (v) >> (n)))	//!< Shift \p v \p n bits right (up to 7b)

#define LSHIFT16(v, n)			((WORD) ((WORD) (v) << (n)))	//!< Shift \p v \p n bits left (up to 15b)
#define RSHIFT16(v, n)			((WORD) ((WORD) (v) >> (n)))	//!< Shift \p v \p n bits right (up to 15b)

#define LSHIFT32(v, n)			((DWORD) ((DWORD) (v) << (n)))	//!< Shift \p v \p n bits left (up to 31b)
#define RSHIFT32(v, n)			((DWORD) ((DWORD) (v) >> (n)))	//!< Shift \p v \p n bits right (up to 31b)

#define LSHIFT64(v, n)			((LWORD) ((LWORD) (v) << (n)))	//!< Shift \p v \p n bits left (up to 63b)
#define RSHIFT64(v, n)			((LWORD) ((LWORD) (v) >> (n)))	//!< Shift \p v \p n bits right (up to 63b)

#endif


#define MAKEWORD(lsb, msb)		((WORD) (((BYTE) (lsb)) | LSHIFT(((WORD) (msb)), 8)))		//!< Make \c WORD from \p lsb and \p msb
#define MAKELONG(lsw, msw)		((DWORD) (((WORD) (lsw)) | LSHIFT(((DWORD) (msw)), 16)))	//!< Make \c LONG from \p lsw and \p msw

#ifdef LOBYTE
#undef LOBYTE	//!\note Undefine \c LOBYTE if already defined in some other library
#endif

#ifdef HIBYTE
#undef HIBYTE	//!\note Undefine \c HIBYTE if already defined in some other library
#endif

#define LOBYTE(w)				((BYTE) (w))						//!< Get \c BYTE LSB from \c WORD \p w
#define HIBYTE(w)				((BYTE) RSHIFT((WORD) (w), 8))		//!< Get \c BYTE MSB from \c WORD \p w
#define LOWORD(l)				((WORD) (l))						//!< Get \c WORD LSW from \c LONG \p l
#define HIWORD(l)				((WORD) RSHIFT((DWORD) (l), 16))	//!< Get \c WORD MSW from \c LONG \p l

//!\MISRA Local legitimate use derogation authorized for:\n
//! \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
//! \a Justification: \p typ parameter would be cast instead of type declaration (thus raising error); other parameters shall be variable names, raising error otherwise is intended.\n
// cppcheck-suppress-macro misra-c2012-20.7
#define	SWAP_TYPE(a, b, typ)	({ typ c = a; a = b; b = c; })		//!< Swap two variable type \p typ \p a \& \p b
#define	SWAP_BYTE(a, b)			SWAP_TYPE(a, b, BYTE)				//!< Swap two \c BYTE \p a \& \p b
#define	SWAP_WORD(a, b)			SWAP_TYPE(a, b, WORD)				//!< Swap two \c WORD \p a \& \p b
#define	SWAP_DWORD(a, b)		SWAP_TYPE(a, b, DWORD)				//!< Swap two \c DWORD \p a \& \p b
#define	SWAP_LWORD(a, b)		SWAP_TYPE(a, b, LWORD)				//!< Swap two \c LWORD \p a \& \p b
#define	SWAP_FLOAT(a, b)		SWAP_TYPE(a, b, float)				//!< Swap two \c float \p a \& \p b
#define	SWAP_DOUBLE(a, b)		SWAP_TYPE(a, b, double)				//!< Swap two \c double \p a \& \p b


//!\MISRA Local legitimate use derogation authorized for:\n
//! \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
//! \a Justification: \p typ parameter would be cast instead of type.\n
// cppcheck-suppress-macro misra-c2012-20.7
#define VAL_AT(addr, typ)		(*(typ *) (addr))										//!< Get the type \p typ content of address \p addr

//!\MISRA local derogation authorized for:\n
//! \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
//! \a Justification: Parenthesis doesn't make sense as parameter \p arr shall be an instance of type; raising error otherwise is intended.\n
// cppcheck-suppress-macro misra-c2012-20.7
#define SZ_ARRAY(arr)			((size_t) (sizeof(arr) / sizeof(arr[0])))				//!< Computes the number of array elements in \p arr

//!\MISRA Local legitimate use derogation authorized for:\n
//! \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
//! \a Justification: \p obj parameter can be a type instead of an istance of type.\n
//! \a Justification: \p typ parameter would be cast instead of type.\n
// cppcheck-suppress-macro misra-c2012-20.7
#define SZ_OBJ(obj, typ)		((size_t) (sizeof(obj) / sizeof(typ)))					//!< Computes the number of elements in \p obj of type \p typ

//!\MISRA Local legitimate use derogation authorized for:\n
//! \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
//! \a Justification: \p typ parameter would be cast instead of type.\n
//! \a Justification: \p mbr parameter shall be a structure member; will in any way raise an error in case not.\n
// cppcheck-suppress-macro misra-c2012-20.7
#define SZ_TYP_MBR(typ, mbr)	((size_t) sizeof(((typ *)0)->mbr))						//!< Computes the size of member \p mbr in struct type \p typ

//!\MISRA Local legitimate use derogation authorized for:\n
//! \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
//! \a Justification: \p typ parameter would be cast instead of type.\n
//! \a Justification: \p mbr parameter shall be a structure member; will in any way raise an error in case not.\n
// cppcheck-suppress-macro misra-c2012-20.7
#define TYP_MBR(typ, mbr)		(((typ *)0)->mbr)										//!< Get member \p mbr from a struct type \p typ

//! \warning use with caution, C language typeof extension works well with native types, yet can be the cause of big (experienced) issues with more complex ones
//! \note \c typeof C language extension should only be used to get a compiler native known type
#define TYP_MBR_TYP(typ, mbr)	typeof(TYP_MBR(typ, mbr))								//!< Get typeof member \p mbr from a struct type \p typ

//!\MISRA Local legitimate use derogation authorized for:\n
//! \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
//! \a Justification: \p typ parameter would be cast instead of type.\n
//! \a Justification: \p mbr parameter shall be a structure member; will in any way raise an error in case not.\n
// cppcheck-suppress-macro misra-c2012-20.7
#define OFFSET_OF(typ, mbr)		((size_t) &(((typ *)0)->mbr))							//!< Computes the offset member \p mbr from struct type \p typ

//!\MISRA Local legitimate use derogation authorized for:\n
//! \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
//! \a Justification: \p mbr parameter shall be a structure member; will in any way raise an error in case not.\n
// cppcheck-suppress-macro misra-c2012-20.7
#define ROOT_OF(ptr, typ, mbr)	((typ *) (((uint8_t *) (ptr)) - OFFSET_OF(typ, mbr)))	//!< Computes the address of parent struct \p typ of \p ptr from member \p mbr


//! \warning No nesting possible, use \ref XCAT instead (unless there is a good reason not to use \ref XCAT)
#define	CAT(a, b)			a##b			//!< Preprocessor Name catenation of \c a and \c b (use of \ref XCAT is highly recommended for any need)
#define XCAT(a, b)			CAT(a, b)		//!< Preprocessor Name catenation of \c a and \c b (nesting possibility)

#define STR(s)				#s				//!< Stringify \c s expression
#define XSTR(s)				STR(s)			//!< Stringify the result of \c s expression expansion (stringification of a macro expansion)

#define binEval(exp)		((exp) ? true : false)		//!< boolean evaluation of expression \p exp
#define nbinEval(exp)		(!binEval(exp))				//!< complemented boolean evaluation of expression \p exp


#ifdef min
#undef min		//!\note Undefine \c min if already defined in some other library
#endif
#ifdef MIN
#undef MIN		//!\note Undefine \c MIN if already defined in some other library
#endif
#define min					MIN								//!< \c min alias for \c MIN
// cppcheck-suppress-macro misra-c2012-1.2
#define MIN(a, b)			({	__TYPEOF(a) _a = (a);	\
								__TYPEOF(b) _b = (b);	\
								(_a <= _b) ? _a : _b; })	//!< Returns min value between \p a and \p b

#ifdef max
#undef max		//!\note Undefine \c max if already defined in some other library
#endif
#ifdef MAX
#undef MAX		//!\note Undefine \c MAX if already defined in some other library
#endif
#define max					MAX								//!< \c max alias for \c MAX
// cppcheck-suppress-macro misra-c2012-1.2
#define MAX(a, b)			({	__TYPEOF(a) _a = (a);	\
								__TYPEOF(b) _b = (b);	\
								(_a >= _b) ? _a : _b; })	//!< Returns max value between \p a and \p b

#ifdef min3
#undef min3		//!\note Undefine \c min3 if already defined in some other library
#endif
#ifdef MIN3
#undef MIN3		//!\note Undefine \c MIN3 if already defined in some other library
#endif
#define min3				MIN3							//!< \c min3 alias for \c MIN3
// cppcheck-suppress-macro misra-c2012-1.2
#define	MIN3(a, b, c)		({	__TYPEOF(a) _a = (a);	\
								__TYPEOF(b) _b = (b);	\
								__TYPEOF(c) _c = (c);	\
								(_b <= _c) ? ((_a <= _b) ? _a : _b) : ((_a <= _c) ? _a : _c); })	//!< Returns min value between \p a, \p b and \p c

#ifdef max3
#undef max3		//!\note Undefine \c max3 if already defined in some other library
#endif
#ifdef MAX3
#undef MAX3		//!\note Undefine \c MAX3 if already defined in some other library
#endif
#define max3				MAX3							//!< \c max3 alias for \c MAX3
// cppcheck-suppress-macro misra-c2012-1.2
#define	MAX3(a, b, c)		({	__TYPEOF(a) _a = (a);	\
								__TYPEOF(b) _b = (b);	\
								__TYPEOF(c) _c = (c);	\
								(_b >= _c) ? ((_a >= _b) ? _a : _b) : ((_a >= _c) ? _a : _c); })	//!< Returns max value between \p a, \p b and \p c

#ifdef clamp
#undef clamp	//!\note Undefine \c clamp if already defined in some other library
#endif
#ifdef CLAMP
#undef CLAMP	//!\note Undefine \c CLAMP if already defined in some other library
#endif
#define clamp				CLAMP							//!< \c clamp alias for \c CLAMP
// cppcheck-suppress-macro misra-c2012-1.2
#define CLAMP(v, mn, mx)	({	__TYPEOF(v) _v = (v);		\
								__TYPEOF(mn) _mn = (mn);	\
								__TYPEOF(mx) _mx = (mx);	\
								(_v < _mn) ? _mn : ((_v > _mx) ? _mx : _v); })	//!< Returns the value between \p mn and \p mx from \p val


//! \warning OVF_DIFF only works with unsigned integers
// cppcheck-suppress-macro misra-c2012-1.2
#define OVF_DIFF(a, b)		({	__TYPEOF(a) _a = (a);	\
								__TYPEOF(b) _b = (b);	\
								__TYPEOF(a) _max = -1;	\
								(_a >= _b) ? (_a - _b) : (_max - _b) + _a + 1; })	//!< Returns difference of unsigned \p a and \p b (with potential overflow handling)


//! \warning SCALE_VAL does not check types and is limited to MCU register size computation, for larger scales, use \ref SCALE_VAL_T or \ref scaleValue instead
#define SCALE_VAL(v, from_min, from_max, to_min, to_max)				\
					(((((v) - (from_min)) * ((to_max) - (to_min))) /	\
					((from_max) - (from_min))) + (to_min))						//!< Scale value \p v from range \p from_min:from_max to range \p to_min:to_max

#define SCALE_VAL_T(typ, v, from_min, from_max, to_min, to_max)									\
					(((((typ) (v) - (typ) (from_min)) * ((typ) (to_max) - (typ) (to_min))) /	\
					((typ) (from_max) - (typ) (from_min))) + (typ) (to_min))	//!< Scale typed \p typ value \p v from range \p from_min:from_max to range \p to_min:to_max


//! \warning This macro doesn't prevent from double evaluation; otherwise it couldn't be used as pre-processing initializer macro
#define BYTE_TO_PERC(b)		((BYTE) ((((b) > 255U ? 255U : (b)) * 100U) / 255U))	//!< Converts a \c BYTE \p b (0-255) to percent (0-100)
//! \warning This macro doesn't prevent from double evaluation; otherwise it couldn't be used as pre-processing initializer macro
#define PERC_TO_BYTE(p)		((BYTE) ((((p) > 100U ? 100U : (p)) * 255U) / 100U))	//!< Converts a \p p percentage (0-100) to \c BYTE (0-255) with max checking


/*** Constants ***/
#define M_1_3				(1.0 / 3.0)		//!< 1/3 constant approximation
#define M_2_3				(2.0 / 3.0)		//!< 2/3 constant approximation


/*** Test Macros ***/
#define malloc_assert(x)	((x) = malloc(sizeof(*(x))), assert((x)))	//!< Asserted malloc


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_MACROS_H_ */
// cppcheck-suppress-end [misra-c2012-1.2, misra-c2012-20.5, misra-c2012-20.10]
/****************************************************************/
