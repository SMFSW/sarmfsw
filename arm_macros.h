/*!\file arm_macros.h
** \author SMFSW
** \copyright MIT (c) 2017-2026, SMFSW
** \brief ARM common macros
** \note If used CPU only handles single shifts, you may define \c SINGLE_SHIFT_ONLY_OPCODE at project level (see \ref LSHIFT & \ref RSHIFT)
** \MISRA Header scope deviation has been granted for following rules:\n
** 	\b Rule-1.2 - \b Advisory: Language extensions (misra-c2012-1.2)\n
** 	\b Rule-20.5 - \b Advisory: \c \#undef (misra-c2012-20.5)\n
*/
// cppcheck-suppress-begin [misra-c2012-1.2, misra-c2012-20.5]
// cppcheck-suppress-begin [misra-c2012-10.4, misra-c2012-11.4, misra-c2012-20.7] macros warnings
/****************************************************************/
#ifndef ARM_MACROS_H_
	#define ARM_MACROS_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


#define	Undefined		(-1)			//!< Undefined value

#define Null			(0)				//!< Null Value
#define pNull			((void *) 0)	//!< Null pointer -> same as NULL in stdlib.h
#define	charNull		('\0')			//!< Null Char


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


#ifndef UNUSED
#define UNUSED(X)		(void) (X)		//!< Unused parameter \p X (to avoid gcc/g++ warnings)
#endif

#ifndef UNUSED_RET
#define UNUSED_RET		(void)			//!< Explicitly ignore function return (MISRA compliance)
#endif
#define _x_				UNUSED_RET		//!< Short alias for \ref UNUSED_RET


#define GET_BITS(v, b)			((v) & (b))								//!< Get bits from mask \p b of variable \p v
#define SET_BITS(v, b)			((v) |= (b))							//!< Set bits \p b of variable \p v
#define CLR_BITS(v, b)			((v) &= ~(b))							//!< Clear bits \p b of variable \p v
#define INV_BITS(v, b)			((v) ^= (b))							//!< Invert bits \p b of variable \p v

#define SET_BITS_VAL(v, m, s)	((v) = (((v) & ~(m)) | ((s) & (m))))	//!< Set variable \p v to set value \p s with mask \p m
#define TEST_BITS_SET(v, b)		(((v) & (b)) == (b))					//!< Test variable \p v with bits \p b (all set)
#define TEST_BITS_CLR(v, b)		(((v) & (b)) == 0)						//!< Test variable \p v with bits \p b (all cleared)
#define TEST_BITS_VAL(v, b)		TEST_BITS_SET((v), (b))					//!< Test variable \p v with bits \p b (all set)
#define TEST_MASK_VAL(v, m, r)	(((v) & (m)) == (r))					//!< Test variable \p v with bits mask \p m is equal to \p r


#if defined(SINGLE_SHIFT_ONLY_OPCODE)

/*!\brief Shift \p v \p n bits left with parameters cast to \p t
** \warning this macro is optimized only when \p n is a static value
**/
#define LSHIFT_CAST(t, v, n)	((t) ((t) (v) * ((t) 1 << (n))))

/*!\brief Shift \p v \p n bits right with parameters cast to \p t
** \warning this macro is optimized only when \p n is a static value
**/
#define RSHIFT_CAST(t, v, n)	((t) ((t) (v) / ((t) 1 << (n))))

/*!\brief Shift \p v \p n bits left
** \warning this macro is optimized only when \p n is a static value
**/
#define LSHIFT(v, n)			((v) * (1U << (n)))

/*!\brief Shift \p v \p n bits right
** \warning this macro is optimized only when \p n is a static value
**/
#define RSHIFT(v, n)			((v) / (1U << (n)))

/*!\brief Shift \p v \p n bits left (up to 7b)
** \warning this macro is optimized only when \p n is a static value
**/
#define LSHIFT8(v, n)			LSHIFT_CAST(BYTE, v, n)

/*!\brief Shift \p v \p n bits right (up to 7b)
** \warning this macro is optimized only when \p n is a static value
**/
#define RSHIFT8(v, n)			RSHIFT_CAST(BYTE, v, n)

/*!\brief Shift \p v \p n bits left (up to 15b)
** \warning this macro is optimized only when \p n is a static value
**/
#define LSHIFT16(v, n)			LSHIFT_CAST(WORD, v, n)

/*!\brief Shift \p v \p n bits right (up to 15b)
** \warning this macro is optimized only when \p n is a static value
**/
#define RSHIFT16(v, n)			RSHIFT_CAST(WORD, v, n)

/*!\brief Shift \p v \p n bits left (up to 31b)
** \warning this macro is optimized only when \p n is a static value
**/
#define LSHIFT32(v, n)			LSHIFT_CAST(DWORD, v, n)

/*!\brief Shift \p v \p n bits right (up to 31b)
** \warning this macro is optimized only when \p n is a static value
**/
#define RSHIFT32(v, n)			RSHIFT_CAST(DWORD, v, n)

/*!\brief Shift \p v \p n bits left (up to 63b)
** \warning this macro is optimized only when \p n is a static value
**/
#define LSHIFT64(v, n)			LSHIFT_CAST(LWORD, v, n)

/*!\brief Shift \p v \p n bits right (up to 63b)
** \warning this macro is optimized only when \p n is a static value
**/
#define RSHIFT64(v, n)			RSHIFT_CAST(LWORD, v, n)

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

/*!\brief Swap two variable type \p typ \p a \& \p b
** \MISRA Local legitimate use derogation authorized for:\n
** \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
** \a Justification: \p typ parameter would be cast instead of type declaration (thus raising error);
** 	other parameters shall be variable names, raising error otherwise is intended.\n
**/
#define	SWAP_TYPE(a, b, typ)	({ typ c = a; a = b; b = c; })		// cppcheck-suppress-macro misra-c2012-20.7

#define	SWAP_BYTE(a, b)			SWAP_TYPE(a, b, BYTE)				//!< Swap two \c BYTE \p a \& \p b
#define	SWAP_WORD(a, b)			SWAP_TYPE(a, b, WORD)				//!< Swap two \c WORD \p a \& \p b
#define	SWAP_DWORD(a, b)		SWAP_TYPE(a, b, DWORD)				//!< Swap two \c DWORD \p a \& \p b
#define	SWAP_LWORD(a, b)		SWAP_TYPE(a, b, LWORD)				//!< Swap two \c LWORD \p a \& \p b
#define	SWAP_FLOAT(a, b)		SWAP_TYPE(a, b, float)				//!< Swap two \c float \p a \& \p b
#define	SWAP_DOUBLE(a, b)		SWAP_TYPE(a, b, double)				//!< Swap two \c double \p a \& \p b


/*!\brief Get the type \p typ content of address \p addr
** \MISRA Local legitimate use derogation authorized for:\n
** \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
** \a Justification: \p typ parameter would be cast instead of type.\n
**/
#define VAL_AT(addr, typ)		(*(typ *) (addr))										// cppcheck-suppress-macro misra-c2012-20.7

/*!\brief Computes the number of array elements in \p arr
** \MISRA local derogation authorized for:\n
** \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
** \a Justification: Parenthesis doesn't make sense as parameter \p arr shall be an instance of type; raising error otherwise is intended.\n
**/
#define SZ_ARRAY(arr)			((size_t) (sizeof(arr) / sizeof(arr[0])))				// cppcheck-suppress-macro misra-c2012-20.7

/*!\brief Computes the number of elements in \p obj of type \p typ
** \MISRA Local legitimate use derogation authorized for:\n
** \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
** \a Justification: \p obj parameter can be a type instead of an istance of type.\n
** \a Justification: \p typ parameter would be cast instead of type.\n
**/
#define SZ_OBJ(obj, typ)		((size_t) (sizeof(obj) / sizeof(typ)))					// cppcheck-suppress-macro misra-c2012-20.7

/*!\brief Computes the size of member \p mbr in struct type \p typ
** \MISRA Local deviation has been granted for following rules:\n
** \b Rule-11.4 - \b Advisory: pointer to integer conversion (misra-c2012-11.4)\n
** Local legitimate use derogation authorized for:\n
** \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
** \a Justification: \p typ parameter would be cast instead of type.\n
** \a Justification: \p mbr parameter shall be a structure member; will in any way raise an error in case not.\n
**/
#define SZ_TYP_MBR(typ, mbr)	((size_t) sizeof(((typ *)0)->mbr))						// cppcheck-suppress-macro [misra-c2012-11.4, misra-c2012-20.7]

/*!\brief Get member \p mbr from a struct type \p typ
** \MISRA Local legitimate use derogation authorized for:\n
** \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
** \a Justification: \p typ parameter would be cast instead of type.\n
** \a Justification: \p mbr parameter shall be a structure member; will in any way raise an error in case not.\n
**/
#define TYP_MBR(typ, mbr)		(((typ *)0)->mbr)										// cppcheck-suppress-macro misra-c2012-20.7

/*!\brief Get typeof member \p mbr from a struct type \p typ
** \warning use with caution, C language typeof extension works well with native types, yet can be the cause of big (experienced) issues with more complex ones
** \note \c typeof C language extension should only be used to get a compiler native known type
**/
#define TYP_MBR_TYP(typ, mbr)	typeof(TYP_MBR(typ, mbr))

/*!\brief Computes the offset member \p mbr from struct type \p typ
** \MISRA Local deviation has been granted for following rules:\n
** \b Rule-11.4 - \b Advisory: pointer to integer conversion (misra-c2012-11.4)\n
** Local legitimate use derogation authorized for:\n
** \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
** \a Justification: \p typ parameter would be cast instead of type.\n
** \a Justification: \p mbr parameter shall be a structure member; will in any way raise an error in case not.\n
**/
#define OFFSET_OF(typ, mbr)		((size_t) &(((typ *)0)->mbr))							// cppcheck-suppress-macro [misra-c2012-11.4, misra-c2012-20.7]

/*!\brief Computes the address of parent struct \p typ of \p ptr from member \p mbr
** \MISRA Local legitimate use derogation authorized for:\n
** \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
** \a Justification: \p mbr parameter shall be a structure member; will in any way raise an error in case not.\n
**/
#define ROOT_OF(ptr, typ, mbr)	((typ *) (((uint8_t *) (ptr)) - OFFSET_OF(typ, mbr)))	// cppcheck-suppress-macro misra-c2012-20.7


#define binEval(exp)		((exp) ? true : false)		//!< boolean evaluation of expression \p exp
#define nbinEval(exp)		(!binEval(exp))				//!< complemented boolean evaluation of expression \p exp

#define isNull(p)			((p) == pNull)				//!< Test is \p p is null
#define isNotNull(p)		((p) != pNull)				//!< Test is \p p is not null

/*!\brief Test is \p v is odd
** \MISRA Local legitimate use derogation authorized for:\n
** \b Rule-10.4 - \b Required: same essential type category (misra-c2012-10.4)\n
** \a Justification: \c signed or \c unsigned use will produce the same result.\n
**/
#define isOdd(v)			(((v) & 1) == 1)			// cppcheck-suppress-macro misra-c2012-10.4

/*!\brief Test is \p v is even
** \MISRA Local legitimate use derogation authorized for:\n
** \b Rule-10.4 - \b Required: same essential type category (misra-c2012-10.4)\n
** \a Justification: \c signed or \c unsigned use will produce the same result.\n
**/
#define isEven(v)			(((v) & 1) == 0)			// cppcheck-suppress-macro misra-c2012-10.4


#ifdef min
#undef min		//!\note Undefine \c min if already defined in some other library
#endif
#ifdef MIN
#undef MIN		//!\note Undefine \c MIN if already defined in some other library
#endif
#define min		MIN		//!< \c min alias for \c MIN
//!\brief Returns min value between \p a and \p b
#define MIN(a, b)			({	__TYPEOF(a) _a = (a);	\
								__TYPEOF(b) _b = (b);	\
								(_a <= _b) ? _a : _b; })	// cppcheck-suppress-macro misra-c2012-1.2

#ifdef max
#undef max		//!\note Undefine \c max if already defined in some other library
#endif
#ifdef MAX
#undef MAX		//!\note Undefine \c MAX if already defined in some other library
#endif
#define max		MAX		//!< \c max alias for \c MAX
//!\brief Returns max value between \p a and \p b
#define MAX(a, b)			({	__TYPEOF(a) _a = (a);	\
								__TYPEOF(b) _b = (b);	\
								(_a >= _b) ? _a : _b; })	// cppcheck-suppress-macro misra-c2012-1.2

#ifdef min3
#undef min3		//!\note Undefine \c min3 if already defined in some other library
#endif
#ifdef MIN3
#undef MIN3		//!\note Undefine \c MIN3 if already defined in some other library
#endif
#define min3	MIN3	//!< \c min3 alias for \c MIN3
//!\brief Returns min value between \p a, \p b and \p c
#define	MIN3(a, b, c)		({	__TYPEOF(a) _a = (a);	\
								__TYPEOF(b) _b = (b);	\
								__TYPEOF(c) _c = (c);	\
								(_b <= _c) ? ((_a <= _b) ? _a : _b) : ((_a <= _c) ? _a : _c); })	// cppcheck-suppress-macro misra-c2012-1.2

#ifdef max3
#undef max3		//!\note Undefine \c max3 if already defined in some other library
#endif
#ifdef MAX3
#undef MAX3		//!\note Undefine \c MAX3 if already defined in some other library
#endif
#define max3	MAX3	//!< \c max3 alias for \c MAX3
//!\brief Returns max value between \p a, \p b and \p c
#define	MAX3(a, b, c)		({	__TYPEOF(a) _a = (a);	\
								__TYPEOF(b) _b = (b);	\
								__TYPEOF(c) _c = (c);	\
								(_b >= _c) ? ((_a >= _b) ? _a : _b) : ((_a >= _c) ? _a : _c); })	// cppcheck-suppress-macro misra-c2012-1.2


#ifdef clamp
#undef clamp	//!\note Undefine \c clamp if already defined in some other library
#endif
#ifdef CLAMP
#undef CLAMP	//!\note Undefine \c CLAMP if already defined in some other library
#endif
#define clamp	CLAMP	//!< \c clamp alias for \c CLAMP
//!\brief Returns the value between \p mn and \p mx from \p v
#define CLAMP(v, mn, mx)	({	__TYPEOF(v) _v = (v);		\
								__TYPEOF(mn) _mn = (mn);	\
								__TYPEOF(mx) _mx = (mx);	\
								(_v < _mn) ? _mn : ((_v > _mx) ? _mx : _v); })	// cppcheck-suppress-macro misra-c2012-1.2


/*!\brief Scale value \p v from range \p from_min:from_max to range \p to_min:to_max
** \warning SCALE_VAL does not check types and is limited to MCU register size computation, for larger scales, use \ref SCALE_VAL_T or \ref scaleValue instead
**/
#define SCALE_VAL(v, from_min, from_max, to_min, to_max)				\
					(((((v) - (from_min)) * ((to_max) - (to_min))) /	\
					((from_max) - (from_min))) + (to_min))

//!\brief Scale typed \p typ value \p v from range \p from_min:from_max to range \p to_min:to_max
#define SCALE_VAL_T(typ, v, from_min, from_max, to_min, to_max)									\
					(((((typ) (v) - (typ) (from_min)) * ((typ) (to_max) - (typ) (to_min))) /	\
					((typ) (from_max) - (typ) (from_min))) + (typ) (to_min))


/*!\brief Converts a \c BYTE \p b (0-255) to percent (0-100)
** \warning This macro doesn't prevent from double evaluation; otherwise it couldn't be used as pre-processing initializer macro
**/
#define BYTE_TO_PERC(b)		((BYTE) (((((b) >= 255U) ? 255U : (b)) * 100U) / 255U))

/*!\brief Converts a \p p percentage (0-100) to \c BYTE (0-255) with max checking
** \warning This macro doesn't prevent from double evaluation; otherwise it couldn't be used as pre-processing initializer macro
**/
#define PERC_TO_BYTE(p)		((BYTE) (((((p) >= 100U) ? 100U : (p)) * 255U) / 100U))


/*** Constants ***/
#define M_1_3				(1.0 / 3.0)		//!< 1/3 constant approximation
#define M_2_3				(2.0 / 3.0)		//!< 2/3 constant approximation


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_MACROS_H_ */
// cppcheck-suppress-end [misra-c2012-1.2, misra-c2012-20.5]
// cppcheck-suppress-end [misra-c2012-10.4, misra-c2012-11.4, misra-c2012-20.7] macros warnings
/****************************************************************/
