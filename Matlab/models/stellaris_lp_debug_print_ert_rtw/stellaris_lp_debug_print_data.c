/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stellaris_lp_debug_print_data.c
 *
 * Code generated for Simulink model 'stellaris_lp_debug_print'.
 *
 * Model version                  : 1.84
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Sep 11 18:39:54 2019
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

#include "stellaris_lp_debug_print.h"
#include "stellaris_lp_debug_print_private.h"

/* Block parameters (auto storage) */
P_stellaris_lp_debug_print stellaris_lp_debug_print_P = {
  /* Mask Parameter: BitwiseOperator1_BitMask
   * Referenced by: '<Root>/Bitwise Operator1'
   */
  16U,

  /* Mask Parameter: BitwiseOperator2_BitMask
   * Referenced by: '<Root>/Bitwise Operator2'
   */
  1U,

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

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<Root>/Gain1'
   */
  32768U,

  /* Expression: [uint8(fmt), 13,10, 0]
   * Referenced by: '<Root>/Debug Print'
   */
  { 115U, 119U, 49U, 32U, 32U, 37U, 100U, 32U, 32U, 32U, 32U, 115U, 119U, 50U,
    32U, 32U, 37U, 100U, 32U, 32U, 32U, 32U, 98U, 111U, 116U, 104U, 32U, 37U,
    100U, 13U, 10U, 0U },

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

  /* Computed Parameter: GPIOSetup_p3
   * Referenced by: '<Root>/GPIO Setup'
   */
  14U,

  /* Computed Parameter: GPIOSetup_p4
   * Referenced by: '<Root>/GPIO Setup'
   */
  224U,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<Root>/Gain'
   */
  128U,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<Root>/Gain2'
   */
  128U,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<Root>/Gain3'
   */
  128U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
