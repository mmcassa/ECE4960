/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stellaris_lp_pwm_data.c
 *
 * Code generated for Simulink model 'stellaris_lp_pwm'.
 *
 * Model version                  : 1.75
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Mon Sep 30 17:25:50 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "stellaris_lp_pwm.h"
#include "stellaris_lp_pwm_private.h"

/* Block parameters (auto storage) */
Parameters_stellaris_lp_pwm stellaris_lp_pwm_P = {
  /* Expression: 50
   * Referenced by: '<Root>/Sine Wave'
   */
  50.0,

  /* Expression: 50
   * Referenced by: '<Root>/Sine Wave'
   */
  50.0,

  /* Expression: 1/3*2*pi
   * Referenced by: '<Root>/Sine Wave'
   */
  2.0943951023931953,

  /* Computed Parameter: SineWave_Hsin
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0041887779554038804,

  /* Computed Parameter: SineWave_HCos
   * Referenced by: '<Root>/Sine Wave'
   */
  0.99999122703113763,

  /* Computed Parameter: SineWave_PSin
   * Referenced by: '<Root>/Sine Wave'
   */
  -0.0041887779554038804,

  /* Computed Parameter: SineWave_PCos
   * Referenced by: '<Root>/Sine Wave'
   */
  0.99999122703113763,

  /* Expression: 2
   * Referenced by: '<S3>/Uniform Random Number'
   */
  2.0,

  /* Expression: 16
   * Referenced by: '<S3>/Uniform Random Number'
   */
  16.0,

  /* Expression: 0
   * Referenced by: '<S3>/Uniform Random Number'
   */
  0.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<Root>/Constant'
   */
  20.0F,

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
  2,

  /* Expression: int32(invert-1)
   * Referenced by: '<S2>/S-Function2'
   */
  -1,

  /* Expression: uint32(freq)
   * Referenced by: '<S1>/S-Function2'
   */
  100000U,

  /* Expression: uint32(freq)
   * Referenced by: '<S2>/S-Function2'
   */
  50U,

  /* Computed Parameter: GPIOWrite_p1
   * Referenced by: '<S3>/GPIO Write'
   */
  1073893376U,

  /* Computed Parameter: GPIOSetup_p1
   * Referenced by: '<S3>/GPIO Setup'
   */
  536870944U,

  /* Computed Parameter: GPIOSetup_p2
   * Referenced by: '<S3>/GPIO Setup'
   */
  1073893376U,

  /* Computed Parameter: REDLED_Value
   * Referenced by: '<S3>/RED LED'
   */
  2U,

  /* Computed Parameter: BLUELED_Value
   * Referenced by: '<S3>/BLUE LED'
   */
  4U,

  /* Computed Parameter: GREENLED_Value
   * Referenced by: '<S3>/GREEN LED'
   */
  8U,

  /* Computed Parameter: GPIOSetup_p3
   * Referenced by: '<S3>/GPIO Setup'
   */
  14U,

  /* Computed Parameter: GPIOSetup_p4
   * Referenced by: '<S3>/GPIO Setup'
   */
  241U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
