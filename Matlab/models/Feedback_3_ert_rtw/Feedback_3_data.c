/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Feedback_3_data.c
 *
 * Code generated for Simulink model 'Feedback_3'.
 *
 * Model version                  : 1.41
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Oct 15 19:40:34 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Feedback_3.h"
#include "Feedback_3_private.h"

/* Block parameters (auto storage) */
P_Feedback_3_T Feedback_3_P = {
  /* Expression: .1257
   * Referenced by: '<Root>/Constant1'
   */
  0.1257,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: -.008
   * Referenced by: '<Root>/Constant'
   */
  -0.008,

  /* Expression: 230
   * Referenced by: '<S5>/Constant'
   */
  230.0,

  /* Expression: [825.38 -933.83 394.44]
   * Referenced by: '<S5>/Polynomial'
   */
  { 825.38, -933.83, 394.44 },

  /* Expression: 1000
   * Referenced by: '<S5>/Constant1'
   */
  1000.0,

  /* Expression: 9000
   * Referenced by: '<S5>/Gain'
   */
  9000.0,

  /* Expression: [1 500]
   * Referenced by: '<S5>/Discrete Transfer Fcn'
   */
  { 1.0, 500.0 },

  /* Expression: [1 0.5]
   * Referenced by: '<S5>/Discrete Transfer Fcn'
   */
  { 1.0, 0.5 },

  /* Expression: 0
   * Referenced by: '<S5>/Discrete Transfer Fcn'
   */
  0.0,

  /* Expression: 230
   * Referenced by: '<S6>/Constant'
   */
  230.0,

  /* Expression: [825.38 -933.83 394.44]
   * Referenced by: '<S6>/Polynomial'
   */
  { 825.38, -933.83, 394.44 },

  /* Expression: 1000
   * Referenced by: '<S6>/Constant1'
   */
  1000.0,

  /* Expression: 9000
   * Referenced by: '<S6>/Gain'
   */
  9000.0,

  /* Expression: [1 500]
   * Referenced by: '<S6>/Discrete Transfer Fcn'
   */
  { 1.0, 500.0 },

  /* Expression: [1 0.5]
   * Referenced by: '<S6>/Discrete Transfer Fcn'
   */
  { 1.0, 0.5 },

  /* Expression: 0
   * Referenced by: '<S6>/Discrete Transfer Fcn'
   */
  0.0,

  /* Expression: 230
   * Referenced by: '<S7>/Constant'
   */
  230.0,

  /* Expression: [825.38 -933.83 394.44]
   * Referenced by: '<S7>/Polynomial'
   */
  { 825.38, -933.83, 394.44 },

  /* Expression: 1000
   * Referenced by: '<S7>/Constant1'
   */
  1000.0,

  /* Expression: 9000
   * Referenced by: '<S7>/Gain'
   */
  9000.0,

  /* Expression: [1 500]
   * Referenced by: '<S7>/Discrete Transfer Fcn'
   */
  { 1.0, 500.0 },

  /* Expression: [1 0.5]
   * Referenced by: '<S7>/Discrete Transfer Fcn'
   */
  { 1.0, 0.5 },

  /* Expression: 0
   * Referenced by: '<S7>/Discrete Transfer Fcn'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S4>/Uniform Random Number'
   */
  2.0,

  /* Expression: 16
   * Referenced by: '<S4>/Uniform Random Number'
   */
  16.0,

  /* Expression: 0
   * Referenced by: '<S4>/Uniform Random Number'
   */
  0.0,

  /* Computed Parameter: ADRaw3_p1
   * Referenced by: '<Root>/AD Raw3'
   */
  5,

  /* Computed Parameter: ADRaw2_p1
   * Referenced by: '<Root>/AD Raw2'
   */
  3,

  /* Computed Parameter: ADRaw1_p1
   * Referenced by: '<Root>/AD Raw1'
   */
  2,

  /* Expression: int32(ch)
   * Referenced by: '<S1>/S-Function2'
   */
  1,

  /* Expression: int32(invert-1)
   * Referenced by: '<S1>/S-Function2'
   */
  -1,

  /* Expression: int32(ch)
   * Referenced by: '<S2>/S-Function2'
   */
  3,

  /* Expression: int32(invert-1)
   * Referenced by: '<S2>/S-Function2'
   */
  -1,

  /* Expression: int32(ch)
   * Referenced by: '<S3>/S-Function2'
   */
  2,

  /* Expression: int32(invert-1)
   * Referenced by: '<S3>/S-Function2'
   */
  -1,

  /* Expression: uint32(freq)
   * Referenced by: '<S1>/S-Function2'
   */
  50000U,

  /* Expression: uint32(freq)
   * Referenced by: '<S2>/S-Function2'
   */
  50000U,

  /* Expression: uint32(freq)
   * Referenced by: '<S3>/S-Function2'
   */
  50000U,

  /* Computed Parameter: GPIOWrite_p1
   * Referenced by: '<S4>/GPIO Write'
   */
  1073893376U,

  /* Computed Parameter: GPIOSetup_p1
   * Referenced by: '<S4>/GPIO Setup'
   */
  536870944U,

  /* Computed Parameter: GPIOSetup_p2
   * Referenced by: '<S4>/GPIO Setup'
   */
  1073893376U,

  /* Expression: [uint8(fmt), 13,10, 0]
   * Referenced by: '<Root>/Debug Print'
   */
  { 49U, 58U, 32U, 32U, 37U, 100U, 32U, 32U, 32U, 32U, 68U, 105U, 115U, 116U,
    32U, 32U, 37U, 100U, 32U, 32U, 32U, 32U, 109U, 105U, 110U, 32U, 32U, 37U,
    100U, 32U, 37U, 100U, 13U, 10U, 0U },

  /* Computed Parameter: REDLED_Value
   * Referenced by: '<S4>/RED LED'
   */
  2U,

  /* Computed Parameter: BLUELED_Value
   * Referenced by: '<S4>/BLUE LED'
   */
  4U,

  /* Computed Parameter: GREENLED_Value
   * Referenced by: '<S4>/GREEN LED'
   */
  8U,

  /* Computed Parameter: GPIOSetup_p3
   * Referenced by: '<S4>/GPIO Setup'
   */
  14U,

  /* Computed Parameter: GPIOSetup_p4
   * Referenced by: '<S4>/GPIO Setup'
   */
  241U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
