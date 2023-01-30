/*!\file arm_inlines.h
** \author SMFSW
** \copyright MIT (c) 2017-2023, SMFSW
** \brief ARM common inlines
*/
/****************************************************************/
#ifndef __ARM_INLINES_H
	#define __ARM_INLINES_H

#ifdef __cplusplus
	extern "C" {
#endif
/****************************************************************/


/********************/
/***  TIME TESTS  ***/
/********************/
#include "arm_inlines_ticks.h"

/******************************/
/***  BINARY MANIPULATIONS  ***/
/******************************/
#include "arm_inlines_binary.h"

/*************************************************/
/***  HEX, ASCII, BCD & GRAY CODE CONVERSIONS  ***/
/*************************************************/
#include "arm_inlines_ascii.h"
#include "arm_inlines_bcd.h"
#include "arm_inlines_gray.h"

/******************************/
/***  VAR SIZE CONVERSIONS  ***/
/******************************/
#include "arm_inlines_var_size.h"

/************************/
/***  VALUES TESTING  ***/
/************************/
#include "arm_inlines_var_test.h"

/***************************************/
/***  ENDIANS CONVERSIONS & TESTING  ***/
/***************************************/
#include "arm_inlines_endian.h"

/************************/
/***  FLOATING POINT  ***/
/************************/
#include "arm_inlines_float.h"

/*******************/
/***  AVERAGING  ***/
/*******************/
#include "arm_inlines_average.h"

/***********************/
/***  LINEARIZATION  ***/
/***********************/
#include "arm_inlines_linearization.h"

/**************************/
/***  ANGLE CONVERSIONS ***/
/**************************/
#include "arm_inlines_angle.h"

/*******************/
/***  ROTATTION  ***/
/*******************/
#include "arm_inlines_rotation.h"

/********************************/
/***  TEMPERATURE CONVERSIONS ***/
/********************************/
#include "arm_inlines_temperature.h"


/****************************************************************/
#ifdef __cplusplus
	}
#endif

#endif /* __ARM_INLINES_H */
/****************************************************************/
