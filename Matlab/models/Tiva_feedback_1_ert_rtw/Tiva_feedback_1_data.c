/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Tiva_feedback_1_data.c
 *
 * Code generated for Simulink model 'Tiva_feedback_1'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Mon Sep 30 18:15:48 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Tiva_feedback_1.h"
#include "Tiva_feedback_1_private.h"

/* Block parameters (auto storage) */
P_Tiva_feedback_1_T Tiva_feedback_1_P = {
  /* Expression: 2
   * Referenced by: '<S6>/Uniform Random Number'
   */
  2.0,

  /* Expression: 16
   * Referenced by: '<S6>/Uniform Random Number'
   */
  16.0,

  /* Expression: 0
   * Referenced by: '<S6>/Uniform Random Number'
   */
  0.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<Root>/Constant'
   */
  10.0F,

  /* Computed Parameter: ADRaw1_p1
   * Referenced by: '<Root>/AD Raw1'
   */
  2,

  /* Expression: int32(ch)
   * Referenced by: '<S5>/S-Function2'
   */
  2,

  /* Expression: int32(invert-1)
   * Referenced by: '<S5>/S-Function2'
   */
  -1,

  /* Expression: int32(ch)
   * Referenced by: '<S4>/S-Function2'
   */
  1,

  /* Expression: int32(invert-1)
   * Referenced by: '<S4>/S-Function2'
   */
  -1,

  /* Expression: uint32(freq)
   * Referenced by: '<S5>/S-Function2'
   */
  50000U,

  /* Expression: uint32(freq)
   * Referenced by: '<S4>/S-Function2'
   */
  1000U,

  /* Computed Parameter: GPIOWrite_p1
   * Referenced by: '<S6>/GPIO Write'
   */
  1073893376U,

  /* Computed Parameter: GPIOSetup_p1
   * Referenced by: '<S6>/GPIO Setup'
   */
  536870944U,

  /* Computed Parameter: GPIOSetup_p2
   * Referenced by: '<S6>/GPIO Setup'
   */
  1073893376U,

  /* Expression: [uint8(fmt), 13,10, 0]
   * Referenced by: '<Root>/Debug Print'
   */
  { 67U, 111U, 110U, 118U, 101U, 114U, 116U, 32U, 37U, 100U, 32U, 32U, 32U, 32U,
    68U, 105U, 115U, 116U, 97U, 110U, 99U, 101U, 32U, 32U, 37U, 100U, 32U, 32U,
    32U, 32U, 109U, 105U, 110U, 32U, 32U, 37U, 100U, 32U, 32U, 32U, 32U, 109U,
    97U, 120U, 32U, 32U, 37U, 100U, 13U, 10U, 0U },

  /* Computed Parameter: REDLED_Value
   * Referenced by: '<S6>/RED LED'
   */
  2U,

  /* Computed Parameter: BLUELED_Value
   * Referenced by: '<S6>/BLUE LED'
   */
  4U,

  /* Computed Parameter: GREENLED_Value
   * Referenced by: '<S6>/GREEN LED'
   */
  8U,

  /* Computed Parameter: GPIOSetup_p3
   * Referenced by: '<S6>/GPIO Setup'
   */
  14U,

  /* Computed Parameter: GPIOSetup_p4
   * Referenced by: '<S6>/GPIO Setup'
   */
  241U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
