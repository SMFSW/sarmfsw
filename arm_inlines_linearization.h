/*!\file arm_inlines_linearization.h
** \author SMFSW
** \copyright MIT (c) 2017-2022, SMFSW
** \brief Linearization inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_LINEARIZATION_H
	#define __ARM_INLINES_LINEARIZATION_H

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


#define	LINEAR_TAB(name, nbElem)		typedef struct linear##name {	\
											WORD	nb;					\
											SDWORD	array[nbElem][2];	\
										} linear##name;	//!< Pattern tab typedef declaration with \b name catenation and \b nbElem max tab elements

#define LINEAR_EVAL(name, val)			linearization_eval(name.array, name.nb, val)	//!< Macro to call linearization on a LINEAR_TAB typedef


/*!\brief 2 dimensional linearization
**
** \param [in] array - pointer to 2 dimensional
** \param [in] nb - Number of items of the array
** \param [in] val - Value to evaluate
** \return Evaluated value in regard of val
**/
__INLINE SDWORD NONNULL__ linearization_eval(SDWORD array[][2], WORD nb, const SDWORD val)
{
	uintCPU_t idxMin = 0, idxMax = nb - 1;

	// Find indexes
	while (idxMax > idxMin + 1)
	{
		const uintCPU_t idx = ((idxMax - idxMin) / 2 + idxMin);

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


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_LINEARIZATION_H */
/****************************************************************/
