/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stellaris_lp_irreceive_RCA_data.c
 *
 * Code generated for Simulink model 'stellaris_lp_irreceive_RCA'.
 *
 * Model version                  : 1.208
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Sep 17 13:33:48 2019
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

#include "stellaris_lp_irreceive_RCA.h"
#include "stellaris_lp_irreceive_RCA_private.h"

/* Block parameters (auto storage) */
P_stellaris_lp_irreceive_RCA stellaris_lp_irreceive_RCA_P = {
  /* Mask Parameter: BitwiseOperator_BitMask
   * Referenced by: '<S6>/Bitwise Operator'
   */
  15,

  /* Mask Parameter: BitwiseOperator1_BitMask
   * Referenced by: '<S6>/Bitwise Operator1'
   */
  15,

  /* Mask Parameter: BitwiseOperator2_BitMask
   * Referenced by: '<S6>/Bitwise Operator2'
   */
  15,

  /* Mask Parameter: FrameDataValid_const
   * Referenced by: '<S2>/Constant'
   */
  0,

  /* Mask Parameter: BitwiseOperator_BitMask_i
   * Referenced by: '<S3>/Bitwise Operator'
   */
  1U,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S5>/Out1'
   */
  0,

  /* Computed Parameter: GPIORead_p1
   * Referenced by: '<S3>/GPIO Read'
   */
  1073893376U,

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

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S4>/Constant'
   */
  6U,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S3>/Constant1'
   */
  16U,

  /* Computed Parameter: GPIOSetup_p3
   * Referenced by: '<S4>/GPIO Setup'
   */
  14U,

  /* Computed Parameter: GPIOSetup_p4
   * Referenced by: '<S4>/GPIO Setup'
   */
  241U,

  /* Expression: [uint8(fmt), 13,10, 0]
   * Referenced by: '<S6>/Debug Print'
   */
  { 65U, 108U, 108U, 49U, 58U, 32U, 48U, 120U, 37U, 120U, 44U, 32U, 97U, 100U,
    100U, 114U, 58U, 32U, 37U, 100U, 44U, 32U, 107U, 101U, 121U, 32U, 37U, 100U,
    44U, 32U, 115U, 116U, 97U, 116U, 101U, 32U, 37U, 100U, 13U, 10U, 0U },

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S4>/Gain1'
   */
  128U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
