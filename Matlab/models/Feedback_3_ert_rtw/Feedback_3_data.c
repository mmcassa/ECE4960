/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Feedback_3_data.c
 *
 * Code generated for Simulink model 'Feedback_3'.
 *
 * Model version                  : 1.117
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Oct 31 18:58:25 2019
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
  /* Expression: 0
   * Referenced by: '<S10>/Current Offset'
   */
  0.0,

  /* Expression: 100*10.1/3.3
   * Referenced by: '<S10>/DC//I Gain'
   */
  306.06060606060606,

  /* Expression: 1
   * Referenced by: '<S10>/Temperature  Normalization'
   */
  1.0,

  /* Expression: 99
   * Referenced by: '<S10>/Duty Cycle Saturation'
   */
  99.0,

  /* Expression: 0
   * Referenced by: '<S10>/Duty Cycle Saturation'
   */
  0.0,

  /* Expression: 40
   * Referenced by: '<Root>/Constant5'
   */
  40.0,

  /* Expression: 0
   * Referenced by: '<S9>/Current Offset'
   */
  0.0,

  /* Expression: 100*10.1/3.3
   * Referenced by: '<S9>/DC//I Gain'
   */
  306.06060606060606,

  /* Expression: 1
   * Referenced by: '<S9>/Temperature  Normalization'
   */
  1.0,

  /* Expression: 99
   * Referenced by: '<S9>/Duty Cycle Saturation'
   */
  99.0,

  /* Expression: 0
   * Referenced by: '<S9>/Duty Cycle Saturation'
   */
  0.0,

  /* Expression: 40
   * Referenced by: '<Root>/Constant4'
   */
  40.0,

  /* Expression: 0
   * Referenced by: '<S8>/Current Offset'
   */
  0.0,

  /* Expression: 100*10.1/3.3
   * Referenced by: '<S8>/DC//I Gain'
   */
  306.06060606060606,

  /* Expression: 1
   * Referenced by: '<S8>/Temperature  Normalization'
   */
  1.0,

  /* Expression: 99
   * Referenced by: '<S8>/Duty Cycle Saturation'
   */
  99.0,

  /* Expression: 0
   * Referenced by: '<S8>/Duty Cycle Saturation'
   */
  0.0,

  /* Expression: 40
   * Referenced by: '<Root>/Constant3'
   */
  40.0,

  /* Expression: 0.0006
   * Referenced by: '<Root>/Constant'
   */
  0.0006,

  /* Expression: 1.1611 * 10^-3
   * Referenced by: '<S5>/Constant'
   */
  0.0011611,

  /* Expression: 1.63 * 10^-3
   * Referenced by: '<S5>/Constant1'
   */
  0.00163,

  /* Expression: .005
   * Referenced by: '<S5>/Saturation'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S5>/Saturation'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S9>/Gain1'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 1000000
   * Referenced by: '<S9>/Gain2'
   */
  1.0E+6,

  /* Expression: 0.11
   * Referenced by: '<Root>/Constant1'
   */
  0.11,

  /* Expression: 5300
   * Referenced by: '<S9>/Contoller Gain'
   */
  5300.0,

  /* Expression: numd
   * Referenced by: '<S16>/Discrete Transfer Fcn'
   */
  { 1.0, -0.95659716682389051 },

  /* Expression: dend
   * Referenced by: '<S16>/Discrete Transfer Fcn'
   */
  { 1.0, -0.74826356757856516 },

  /* Expression: 0
   * Referenced by: '<S16>/Discrete Transfer Fcn'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S9>/Gain3'
   */
  1000.0,

  /* Expression: 1.1611 * 10^-3
   * Referenced by: '<S6>/Constant'
   */
  0.0011611,

  /* Expression: 2.1 * 10^-3
   * Referenced by: '<S6>/Constant1'
   */
  0.0021000000000000003,

  /* Expression: .005
   * Referenced by: '<S6>/Saturation'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S6>/Saturation'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S10>/Gain1'
   */
  1000.0,

  /* Expression: 1000000
   * Referenced by: '<S10>/Gain2'
   */
  1.0E+6,

  /* Expression: 5300
   * Referenced by: '<S10>/Contoller Gain'
   */
  5300.0,

  /* Expression: numd
   * Referenced by: '<S18>/Discrete Transfer Fcn'
   */
  { 1.0, -0.95659716682389051 },

  /* Expression: dend
   * Referenced by: '<S18>/Discrete Transfer Fcn'
   */
  { 1.0, -0.74826356757856516 },

  /* Expression: 0
   * Referenced by: '<S18>/Discrete Transfer Fcn'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S10>/Gain3'
   */
  1000.0,

  /* Expression: 1.1611 * 10^-3
   * Referenced by: '<S4>/Constant'
   */
  0.0011611,

  /* Expression: 1.49 * 10^-3
   * Referenced by: '<S4>/Constant1'
   */
  0.00149,

  /* Expression: .005
   * Referenced by: '<S4>/Saturation'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S4>/Saturation'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S8>/Gain1'
   */
  1000.0,

  /* Expression: 1000000
   * Referenced by: '<S8>/Gain2'
   */
  1.0E+6,

  /* Expression: 5300
   * Referenced by: '<S8>/Contoller Gain'
   */
  5300.0,

  /* Expression: numd
   * Referenced by: '<S14>/Discrete Transfer Fcn'
   */
  { 1.0, -0.95659716682389051 },

  /* Expression: dend
   * Referenced by: '<S14>/Discrete Transfer Fcn'
   */
  { 1.0, -0.74826356757856516 },

  /* Expression: 0
   * Referenced by: '<S14>/Discrete Transfer Fcn'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S8>/Gain3'
   */
  1000.0,

  /* Expression: 10000
   * Referenced by: '<Root>/Gain'
   */
  10000.0,

  /* Expression: 10000
   * Referenced by: '<Root>/Gain1'
   */
  10000.0,

  /* Expression: 10000
   * Referenced by: '<Root>/Gain2'
   */
  10000.0,

  /* Expression: 1000000
   * Referenced by: '<Root>/Gain4'
   */
  1.0E+6,

  /* Expression: 1000000
   * Referenced by: '<Root>/Gain5'
   */
  1.0E+6,

  /* Expression: 1000000
   * Referenced by: '<Root>/Gain6'
   */
  1.0E+6,

  /* Expression: 1
   * Referenced by: '<Root>/Gain3'
   */
  1.0,

  /* Computed Parameter: ADRaw2_p1
   * Referenced by: '<Root>/AD Raw2'
   */
  3,

  /* Computed Parameter: ADRaw1_p1
   * Referenced by: '<Root>/AD Raw1'
   */
  2,

  /* Computed Parameter: ADRaw3_p1
   * Referenced by: '<Root>/AD Raw3'
   */
  5,

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

  /* Computed Parameter: XComInit_p1
   * Referenced by: '<S7>/XComInit'
   */
  9600,

  /* Computed Parameter: ADRaw1_p1_f
   * Referenced by: '<S15>/AD Raw1'
   */
  1,

  /* Computed Parameter: ADRaw1_p1_a
   * Referenced by: '<S17>/AD Raw1'
   */
  1,

  /* Expression: uint32(freq)
   * Referenced by: '<S1>/S-Function2'
   */
  200000U,

  /* Expression: uint32(freq)
   * Referenced by: '<S2>/S-Function2'
   */
  200000U,

  /* Expression: uint32(freq)
   * Referenced by: '<S3>/S-Function2'
   */
  200000U,

  /* Computed Parameter: GPIOWrite_p1
   * Referenced by: '<S7>/GPIO Write'
   */
  1073893376U,

  /* Computed Parameter: GPIOSetup_p1
   * Referenced by: '<S7>/GPIO Setup'
   */
  536870944U,

  /* Computed Parameter: GPIOSetup_p2
   * Referenced by: '<S7>/GPIO Setup'
   */
  1073893376U,

  /* Computed Parameter: Gain_Gain_k
   * Referenced by: '<S6>/Gain'
   */
  2206763817U,

  /* Computed Parameter: Gain_Gain_i
   * Referenced by: '<S5>/Gain'
   */
  3905431525U,

  /* Computed Parameter: Gain_Gain_g
   * Referenced by: '<S4>/Gain'
   */
  4265719495U,

  /* Computed Parameter: RedLEDOn2_Value
   * Referenced by: '<S7>/Red LED On2'
   */
  3U,

  /* Computed Parameter: RedLEDOn1_Value
   * Referenced by: '<S7>/Red LED On1'
   */
  2U,

  /* Computed Parameter: RedLEDOn_Value
   * Referenced by: '<S7>/Red LED On'
   */
  1U,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S13>/Out1'
   */
  0U,

  /* Computed Parameter: Constant_Value_m
   * Referenced by: '<S7>/Constant'
   */
  48U,

  /* Computed Parameter: RedLEDOff_Value
   * Referenced by: '<S7>/Red LED Off'
   */
  0U,

  /* Expression: [uint8(fmt), 13,10, 0]
   * Referenced by: '<Root>/Debug Print'
   */
  { 97U, 58U, 32U, 37U, 100U, 32U, 32U, 32U, 32U, 98U, 58U, 32U, 37U, 100U, 32U,
    32U, 32U, 32U, 99U, 58U, 32U, 37U, 100U, 32U, 32U, 32U, 32U, 32U, 100U, 58U,
    37U, 100U, 13U, 10U, 0U },

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<Root>/Manual Switch2'
   */
  0U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  0U,

  /* Computed Parameter: REDLED_Value
   * Referenced by: '<S7>/RED LED'
   */
  2U,

  /* Computed Parameter: GPIOSetup_p3
   * Referenced by: '<S7>/GPIO Setup'
   */
  14U,

  /* Computed Parameter: GPIOSetup_p4
   * Referenced by: '<S7>/GPIO Setup'
   */
  241U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
