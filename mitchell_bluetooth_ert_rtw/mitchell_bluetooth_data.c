/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mitchell_bluetooth_data.c
 *
 * Code generated for Simulink model 'mitchell_bluetooth'.
 *
 * Model version                  : 1.145
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Nov 14 20:47:44 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "mitchell_bluetooth.h"
#include "mitchell_bluetooth_private.h"

/* Block parameters (default storage) */
P_mitchell_bluetooth_T mitchell_bluetooth_P = {
  /* Expression: 0
   * Referenced by: '<S13>/Current Offset'
   */
  0.0,

  /* Expression: 100*1/3.3
   * Referenced by: '<S13>/DC//I Gain'
   */
  30.303030303030305,

  /* Expression: 1
   * Referenced by: '<S13>/Temperature  Normalization'
   */
  1.0,

  /* Expression: 50
   * Referenced by: '<Root>/Constant8'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S12>/Current Offset'
   */
  0.0,

  /* Expression: 100*1/3.3
   * Referenced by: '<S12>/DC//I Gain'
   */
  30.303030303030305,

  /* Expression: 1
   * Referenced by: '<S12>/Temperature  Normalization'
   */
  1.0,

  /* Expression: 50
   * Referenced by: '<Root>/Constant6'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S11>/Current Offset'
   */
  0.0,

  /* Expression: 100*1/3.3
   * Referenced by: '<S11>/DC//I Gain'
   */
  30.303030303030305,

  /* Expression: 1
   * Referenced by: '<S11>/Temperature  Normalization'
   */
  1.0,

  /* Expression: 50
   * Referenced by: '<Root>/Constant7'
   */
  50.0,

  /* Expression: 0.0011
   * Referenced by: '<Root>/Constant'
   */
  0.0011,

  /* Expression: .0001
   * Referenced by: '<Root>/Gain7'
   */
  0.0001,

  /* Expression: 0.104
   * Referenced by: '<Root>/Constant1'
   */
  0.104,

  /* Expression: [ +1.6739e+20, -1.3935e+18, +4.7154e+15, -8.351e+12, +8.2878e+9, -4.527e+6, 1.1593e+3 ]
   * Referenced by: '<Root>/f^(h)'
   */
  { 1.6739E+20, -1.3935E+18, 4.7154E+15, -8.351E+12, 8.2878E+9, -4.527E+6,
    1159.3 },

  /* Expression: 9.81
   * Referenced by: '<S14>/Gravity Constant'
   */
  9.81,

  /* Expression: 0.176
   * Referenced by: '<S14>/1//3 Total Mass'
   */
  0.176,

  /* Expression: 50
   * Referenced by: '<Root>/Constant5'
   */
  50.0,

  /* Expression: 99
   * Referenced by: '<Root>/Duty Cycle Saturation1'
   */
  99.0,

  /* Expression: 0
   * Referenced by: '<Root>/Duty Cycle Saturation1'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<Root>/Constant4'
   */
  50.0,

  /* Expression: 99
   * Referenced by: '<Root>/Duty Cycle Saturation'
   */
  99.0,

  /* Expression: 0
   * Referenced by: '<Root>/Duty Cycle Saturation'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<Root>/Constant3'
   */
  50.0,

  /* Expression: 1000
   * Referenced by: '<S12>/Gain1'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 1000000
   * Referenced by: '<S12>/Gain2'
   */
  1.0E+6,

  /* Expression: 5000
   * Referenced by: '<S12>/Contoller Gain'
   */
  5000.0,

  /* Expression: numd
   * Referenced by: '<S19>/Discrete Transfer Fcn'
   */
  { 1.0, -0.9527083309430191 },

  /* Expression: dend
   * Referenced by: '<S19>/Discrete Transfer Fcn'
   */
  { 1.0, -0.73344695622428924 },

  /* Expression: 0
   * Referenced by: '<S19>/Discrete Transfer Fcn'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S12>/Gain3'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S13>/Gain1'
   */
  1000.0,

  /* Expression: 1000000
   * Referenced by: '<S13>/Gain2'
   */
  1.0E+6,

  /* Expression: 5000
   * Referenced by: '<S13>/Contoller Gain'
   */
  5000.0,

  /* Expression: numd
   * Referenced by: '<S20>/Discrete Transfer Fcn'
   */
  { 1.0, -0.9527083309430191 },

  /* Expression: dend
   * Referenced by: '<S20>/Discrete Transfer Fcn'
   */
  { 1.0, -0.73344695622428924 },

  /* Expression: 0
   * Referenced by: '<S20>/Discrete Transfer Fcn'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S13>/Gain3'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S11>/Gain1'
   */
  1000.0,

  /* Expression: 1000000
   * Referenced by: '<S11>/Gain2'
   */
  1.0E+6,

  /* Expression: 5000
   * Referenced by: '<S11>/Contoller Gain'
   */
  5000.0,

  /* Expression: numd
   * Referenced by: '<S18>/Discrete Transfer Fcn'
   */
  { 1.0, -0.9527083309430191 },

  /* Expression: dend
   * Referenced by: '<S18>/Discrete Transfer Fcn'
   */
  { 1.0, -0.73344695622428924 },

  /* Expression: 0
   * Referenced by: '<S18>/Discrete Transfer Fcn'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S11>/Gain3'
   */
  1000.0,

  /* Expression: 1
   * Referenced by: '<Root>/Gain5'
   */
  1.0,

  /* Computed Parameter: RateLimiter2_RisingLim
   * Referenced by: '<Root>/Rate Limiter2'
   */
  1.0,

  /* Computed Parameter: RateLimiter2_FallingLim
   * Referenced by: '<Root>/Rate Limiter2'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Rate Limiter2'
   */
  0.0,

  /* Expression: 99
   * Referenced by: '<Root>/Duty Cycle Saturation2'
   */
  99.0,

  /* Expression: 0
   * Referenced by: '<Root>/Duty Cycle Saturation2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Gain3'
   */
  1.0,

  /* Computed Parameter: RateLimiter_RisingLim
   * Referenced by: '<Root>/Rate Limiter'
   */
  1.0,

  /* Computed Parameter: RateLimiter_FallingLim
   * Referenced by: '<Root>/Rate Limiter'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Rate Limiter'
   */
  0.0,

  /* Computed Parameter: RateLimiter1_RisingLim
   * Referenced by: '<Root>/Rate Limiter1'
   */
  1.0,

  /* Computed Parameter: RateLimiter1_FallingLim
   * Referenced by: '<Root>/Rate Limiter1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Rate Limiter1'
   */
  0.0,

  /* Computed Parameter: Constant_Value_g
   * Referenced by: '<S10>/Constant'
   */
  48,

  /* Computed Parameter: ADRaw1_p1
   * Referenced by: '<S2>/AD Raw1'
   */
  3,

  /* Computed Parameter: ADRaw1_p1_f
   * Referenced by: '<S3>/AD Raw1'
   */
  2,

  /* Computed Parameter: ADRaw1_p1_e
   * Referenced by: '<S1>/AD Raw1'
   */
  5,

  /* Expression: int32(ch)
   * Referenced by: '<S4>/S-Function2'
   */
  1,

  /* Expression: int32(invert-1)
   * Referenced by: '<S4>/S-Function2'
   */
  -1,

  /* Expression: int32(ch)
   * Referenced by: '<S5>/S-Function2'
   */
  3,

  /* Expression: int32(invert-1)
   * Referenced by: '<S5>/S-Function2'
   */
  -1,

  /* Expression: int32(ch)
   * Referenced by: '<S6>/S-Function2'
   */
  2,

  /* Expression: int32(invert-1)
   * Referenced by: '<S6>/S-Function2'
   */
  -1,

  /* Computed Parameter: Sensor1Identifier_Value
   * Referenced by: '<S10>/Sensor 1 Identifier'
   */
  100000,

  /* Computed Parameter: Sensor2Identifier_Value
   * Referenced by: '<S10>/Sensor 2 Identifier'
   */
  200000,

  /* Computed Parameter: Sensor3Identifier_Value
   * Referenced by: '<S10>/Sensor 3 Identifier'
   */
  300000,

  /* Computed Parameter: Floatier_Value
   * Referenced by: '<S10>/Float ier'
   */
  400000,

  /* Computed Parameter: MassIdentifier_Value
   * Referenced by: '<S10>/Mass Identifier'
   */
  500000,

  /* Computed Parameter: XComInit_p1
   * Referenced by: '<S10>/XComInit'
   */
  9600,

  /* Computed Parameter: Gain4_Gain
   * Referenced by: '<Root>/Gain4'
   */
  1073741824,

  /* Computed Parameter: Gain6_Gain
   * Referenced by: '<Root>/Gain6'
   */
  1073741824,

  /* Computed Parameter: ToVolt_Gain
   * Referenced by: '<S2>/ToVolt'
   */
  0.000805664051F,

  /* Computed Parameter: ZeroSensorVoltage_Value
   * Referenced by: '<S8>/Zero Sensor Voltage'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S8>/Gain'
   */
  0.00163219706F,

  /* Computed Parameter: Constant_Value_n
   * Referenced by: '<S8>/Constant'
   */
  -0.00194274017F,

  /* Computed Parameter: ToVolt_Gain_d
   * Referenced by: '<S3>/ToVolt'
   */
  0.000805664051F,

  /* Computed Parameter: ZeroSensorVoltage_Value_k
   * Referenced by: '<S9>/Zero Sensor Voltage'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain_e
   * Referenced by: '<S9>/Gain'
   */
  0.000936554919F,

  /* Computed Parameter: Constant_Value_k
   * Referenced by: '<S9>/Constant'
   */
  1.99985789E-5F,

  /* Computed Parameter: ToVolt_Gain_l
   * Referenced by: '<S1>/ToVolt'
   */
  0.000805664051F,

  /* Computed Parameter: ZeroSensorVoltage_Value_i
   * Referenced by: '<S7>/Zero Sensor Voltage'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain_g
   * Referenced by: '<S7>/Gain'
   */
  0.00187697774F,

  /* Computed Parameter: Constant_Value_b
   * Referenced by: '<S7>/Constant'
   */
  -0.00294202892F,

  /* Computed Parameter: Gain_Gain_n
   * Referenced by: '<Root>/Gain'
   */
  10000.0F,

  /* Computed Parameter: Gain1_Gain_f
   * Referenced by: '<Root>/Gain1'
   */
  10000.0F,

  /* Computed Parameter: Gain2_Gain_n
   * Referenced by: '<Root>/Gain2'
   */
  10000.0F,

  /* Expression: uint32(freq)
   * Referenced by: '<S4>/S-Function2'
   */
  100000U,

  /* Expression: uint32(freq)
   * Referenced by: '<S5>/S-Function2'
   */
  100000U,

  /* Expression: uint32(freq)
   * Referenced by: '<S6>/S-Function2'
   */
  100000U,

  /* Computed Parameter: GPIOWrite_p1
   * Referenced by: '<S10>/GPIO Write'
   */
  1073893376U,

  /* Computed Parameter: GPIOSetup_p1
   * Referenced by: '<S10>/GPIO Setup'
   */
  536870944U,

  /* Computed Parameter: GPIOSetup_p2
   * Referenced by: '<S10>/GPIO Setup'
   */
  1073893376U,

  /* Computed Parameter: RedLEDOn2_Value
   * Referenced by: '<S10>/Red LED On2'
   */
  3U,

  /* Computed Parameter: RedLEDOn1_Value
   * Referenced by: '<S10>/Red LED On1'
   */
  2U,

  /* Computed Parameter: RedLEDOn_Value
   * Referenced by: '<S10>/Red LED On'
   */
  1U,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S17>/Out1'
   */
  0U,

  /* Computed Parameter: RedLEDOff_Value
   * Referenced by: '<S10>/Red LED Off'
   */
  0U,

  /* Computed Parameter: ManualSwitch4_CurrentSetting
   * Referenced by: '<Root>/Manual Switch4'
   */
  1U,

  /* Computed Parameter: ManualSwitch3_CurrentSetting
   * Referenced by: '<Root>/Manual Switch3'
   */
  1U,

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
   * Referenced by: '<S10>/RED LED'
   */
  2U,

  /* Computed Parameter: Latchsignal_Value
   * Referenced by: '<S10>/Latch signal'
   */
  100U,

  /* Computed Parameter: GPIOSetup_p3
   * Referenced by: '<S10>/GPIO Setup'
   */
  14U,

  /* Computed Parameter: GPIOSetup_p4
   * Referenced by: '<S10>/GPIO Setup'
   */
  241U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
