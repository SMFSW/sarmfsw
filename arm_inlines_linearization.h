/*!\file arm_inlines_linearization.h
** \author SMFSW
** \copyright MIT (c) 2017-2024, SMFSW
** \brief Linearization inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_LINEARIZATION_H
	#define __ARM_INLINES_LINEARIZATION_H

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


/*************************************************/
/*** Non Flexible member array type definition ***/
/*************************************************/
#define	LINEAR_TAB(name, nbElem)	typedef struct sLinear##name {	\
										DWORD	nb;					\
										SDWORD	array[nbElem][2];	\
									} sLinear##name;	//!< Pattern tab typedef declaration with \b name catenation and \b nbElem max array elements

/*********************************************/
/*** Flexible member array type definition ***/
/*********************************************/
/*!\struct sLinearFlexArray
** \brief Linearization flexible member array structure
** \note Can be used as declaration of static hard-coded initialized structures or dynamically allocated structures
**/
typedef struct sLinearFlexArray {
	DWORD	nb;						//!< Number of items
	SDWORD	array[/*flexible*/][2];	//!< Flexible 2 dimensional array member
} sLinearFlexArray;


#define LINEAR_EVAL(name, val)		linearization_eval(name.array, name.nb, val)	//!< Macro to call linearization on a LINEAR_TAB or sLinearFlexArray typedef


/*!\brief 2 dimensional linearization
**
** \param [in] array - pointer to 2 dimensional array
** \param [in] nb - Number of items of the array
** \param [in] val - Value to evaluate
** \return Evaluated value in regard of val
**/
__INLINE SDWORD NONNULL__ linearization_eval(const SDWORD array[][2], const DWORD nb, const SDWORD val)
{
	DWORD idxMin = 0, idxMax = nb - 1;

	// Find indexes
	while (idxMax > idxMin + 1)
	{
		const DWORD idx = ((idxMax - idxMin) / 2 + idxMin);

		if (val < array[idx][0])	{ idxMax = idx; }
		else						{ idxMin = idx; }
	}

	// Get interval values
	const SDWORD x0 = array[idxMin][0];
	const SDWORD y0 = array[idxMin][1];
	const SDWORD x1 = array[idxMax][0];
	const SDWORD y1 = array[idxMax][1];

	// Linearize
	const float coef = (float) (y1 - y0) / (float) (x1 - x0);
	return (SDWORD) (coef * (val - x0) + y0);
}


/*!\brief 2 dimensional linearization (flexible member array)
**
** \param [in] pArray - pointer to flexible member array structure
** \param [in] val - Value to evaluate
** \return Evaluated value in regard of val
**/
__INLINE SDWORD NONNULL_INLINE__ linearization_eval_flex(const sLinearFlexArray * const pArray, const SDWORD val) {
	return linearization_eval(pArray->array, pArray->nb, val); }


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_LINEARIZATION_H */
/****************************************************************/
