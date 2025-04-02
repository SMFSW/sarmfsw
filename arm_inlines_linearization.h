/*!\file arm_inlines_linearization.h
** \author SMFSW
** \copyright MIT (c) 2017-2025, SMFSW
** \brief Linearization inlines
*/
/****************************************************************/
#ifndef ARM_INLINES_LINEARIZATION_H_
	#define ARM_INLINES_LINEARIZATION_H_

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


/*************************************************/
/*** Non Flexible member array type definition ***/
/*************************************************/
//!\MISRA Local deviation has been granted for following rules:\n
//!	\b Rule-20.10 - \b Advisory: \c # and \c ## preprocessor operators (misra-c2012-20.10)\n
// cppcheck-suppress misra-c2012-20.10
#define	LINEAR_TAB(name, nbElem)	typedef struct sLinear##name {	\
										DWORD	nb;					\
										SDWORD	array[nbElem][2];	\
									} sLinear##name;	//!< Pattern tab typedef declaration with \p name catenation and \p nbElem max array elements

/*********************************************/
/*** Flexible member array type definition ***/
/*********************************************/
/*!\struct sLinearFlexArray
** \brief Linearization flexible member array structure
** \note Can be used as declaration of static hard-coded initialized structures or dynamically allocated structures
** \MISRA Function scope derogation authorized for:\n
**	\b Rule-18.7 - \b Required: flexible array members (misra-c2012-18.7)\n
**	\a Justification: \c array being an array of array, this is a rather legitimate representation of object than a pointer.\n
**/
typedef struct sLinearFlexArray {
	DWORD	nb;						//!< Number of items
	// cppcheck-suppress misra-c2012-18.7
	SDWORD	array[/*flexible*/][2];	//!< Flexible 2 dimensional array member
} sLinearFlexArray;


//!\MISRA Local legitimate use derogation authorized for:\n
//! \b Rule-20.7 - \b Required: Enclosed macro parameters expansion (misra-c2012-20.7)\n
//! \a Justification: Result expansion of \p name wouldn't produce the desired structured access expansion.\n
// cppcheck-suppress-macro misra-c2012-20.7
#define LINEAR_EVAL(name, val)		linearization_eval(name.array, name.nb, (val))	//!< Macro to call linearization on a LINEAR_TAB or sLinearFlexArray typedef


/*!\brief 2 dimensional linearization
**
** \param[in] array - pointer to 2 dimensional array
** \param[in] nb - Number of items of the array
** \param[in] val - Value to evaluate
** \return Evaluated value in regard of val
**/
__INLINE SDWORD NONNULL__ linearization_eval(const SDWORD array[][2], const DWORD nb, const SDWORD val)
{
	DWORD idxMin = 0;
	DWORD idxMax = nb - 1U;

	// Find indexes
	while (idxMax > (idxMin + 1U))
	{
		const DWORD idx = (((idxMax - idxMin) / 2U) + idxMin);

		if (val < array[idx][0])	{ idxMax = idx; }
		else						{ idxMin = idx; }
	}

	// Get interval values
	const float x0 = (float) array[idxMin][0];
	const float y0 = (float) array[idxMin][1];
	const float x1 = (float) array[idxMax][0];
	const float y1 = (float) array[idxMax][1];

	// Linearize
	const float coef = (y1 - y0) / (x1 - x0);
	return (SDWORD) (coef * ((float) val - x0) + y0);
}


/*!\brief 2 dimensional linearization (flexible member array)
**
** \param[in] pArray - pointer to flexible member array structure
** \param[in] val - Value to evaluate
** \return Evaluated value in regard of val
**/
__INLINE SDWORD NONNULL_INLINE__ linearization_eval_flex(const sLinearFlexArray * const pArray, const SDWORD val) {
	return linearization_eval(pArray->array, pArray->nb, val); }


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* ARM_INLINES_LINEARIZATION_H_ */
/****************************************************************/
