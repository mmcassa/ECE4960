/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stellaris_lp_blink_bluetooth_data.c
 *
 * Code generated for Simulink model 'stellaris_lp_blink_bluetooth'.
 *
 * Model version                  : 1.88
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Oct 15 17:22:09 2019
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

#include "stellaris_lp_blink_bluetooth.h"
#include "stellaris_lp_blink_bluetooth_private.h"

/* Block parameters (auto storage) */
P_stellaris_lp_blink_bluetooth stellaris_lp_blink_bluetooth_P = {
  /* Computed Parameter: ADRaw1_p1
   * Referenced by: '<Root>/AD Raw1'
   */
  2,

  /* Computed Parameter: XComInit_p1
   * Referenced by: '<Root>/XComInit'
   */
  9600,

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

  /* Computed Parameter: RedLEDOn_Value
   * Referenced by: '<Root>/Red LED On'
   */
  2U,

  /* Computed Parameter: RedLEDOff_Value
   * Referenced by: '<Root>/Red LED Off'
   */
  0U,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S2>/Out1'
   */
  0U,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<Root>/Constant'
   */
  48U,

  /* Expression: [uint8(fmt), 13,10, 0]
   * Referenced by: '<Root>/Debug Print'
   */
  { 67U, 111U, 110U, 118U, 101U, 114U, 116U, 32U, 37U, 100U, 32U, 32U, 32U, 32U,
    68U, 105U, 115U, 116U, 97U, 110U, 99U, 101U, 32U, 32U, 37U, 100U, 32U, 32U,
    32U, 32U, 109U, 105U, 110U, 32U, 32U, 37U, 100U, 32U, 32U, 32U, 32U, 109U,
    97U, 120U, 32U, 32U, 37U, 100U, 13U, 10U, 0U },

  /* Computed Parameter: REDLED_Value
   * Referenced by: '<Root>/RED LED'
   */
  2U,

  /* Computed Parameter: Memory_InitialCondition
   * Referenced by: '<Root>/Memory'
   */
  0U,

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
