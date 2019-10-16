/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stellaris_lp_blink_rand_data.c
 *
 * Code generated for Simulink model 'stellaris_lp_blink_rand'.
 *
 * Model version                  : 1.77
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Sep 11 18:23:27 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 *    4. Traceability
 *    5. Safety precaution
 *    6. Debugging
 *    7. MISRA C:2012 guidelines
 *    8. Polyspace
 * Validation result: Not run
 */

#include "stellaris_lp_blink_rand.h"
#include "stellaris_lp_blink_rand_private.h"

/* Block parameters (auto storage) */
P_stellaris_lp_blink_rand stellaris_lp_blink_rand_P = {
  /* Mask Parameter: RandomEveryBuild_OutValues
   * Referenced by: '<S2>/Vector'
   */
  { 8U, 4U, 6U, 2U, 0U },

  /* Mask Parameter: NotRAND_OutValues
   * Referenced by: '<S1>/Vector'
   */
  { 0U, 2U, 4U, 6U, 8U },

  /* Mask Parameter: LimitedCounter_uplimit
   * Referenced by: '<S8>/FixPt Switch'
   */
  4U,

  /* Mask Parameter: LimitedCounter_uplimit_e
   * Referenced by: '<S5>/FixPt Switch'
   */
  4U,

  /* Expression: 0
   * Referenced by: '<Root>/Random Every Sample'
   */
  0.0,

  /* Expression: 16
   * Referenced by: '<Root>/Random Every Sample'
   */
  16.0,

  /* Expression: 0
   * Referenced by: '<Root>/Random Every Sample'
   */
  0.0,

  /* Computed Parameter: GPIOWrite_p1
   * Referenced by: '<Root>/GPIO Write'
   */
  1073893376U,

  /* Computed Parameter: GPIOSetup_p1
   * Referenced by: '<Root>/GPIO Setup'
   */
  536870944U,

  /* Computed Parameter: GPIOSetup_p2
   * Referenced by: '<Root>/GPIO Setup'
   */
  1073893376U,

  /* Computed Parameter: RandomStyleSwitch1_CurrentSetti
   * Referenced by: '<Root>/Random Style Switch1'
   */
  0U,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S5>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_j
   * Referenced by: '<S8>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S3>/Output'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition_i
   * Referenced by: '<S6>/Output'
   */
  0U,

  /* Computed Parameter: RandomStyleSwitch_CurrentSettin
   * Referenced by: '<Root>/Random Style Switch'
   */
  0U,

  /* Computed Parameter: REDLED_Value
   * Referenced by: '<Root>/RED LED'
   */
  2U,

  /* Computed Parameter: BLUELED_Value
   * Referenced by: '<Root>/BLUE LED'
   */
  4U,

  /* Computed Parameter: GREENLED_Value
   * Referenced by: '<Root>/GREEN LED'
   */
  8U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S7>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: FixPtConstant_Value_b
   * Referenced by: '<S4>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: GPIOSetup_p3
   * Referenced by: '<Root>/GPIO Setup'
   */
  14U,

  /* Computed Parameter: GPIOSetup_p4
   * Referenced by: '<Root>/GPIO Setup'
   */
  241U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
