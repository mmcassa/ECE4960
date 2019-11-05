/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Feedback_3.c
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

/* Block signals (auto storage) */
B_Feedback_3_T Feedback_3_B;

/* Block states (auto storage) */
DW_Feedback_3_T Feedback_3_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Feedback_3_T Feedback_3_Y;

/* Real-time model */
RT_MODEL_Feedback_3_T Feedback_3_M_;
RT_MODEL_Feedback_3_T *const Feedback_3_M = &Feedback_3_M_;
static void rate_monotonic_scheduler(void);
real_T uMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T i;
  int32_T exp_0;
  y = 0.0;
  exp_0 = e1;
  for (i = 0; i < n1; i++) {
    y += ldexp(u1[i], exp_0);
    exp_0 += 32;
  }

  return y;
}

void uMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T nj;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    k = n - i;
    nj = n2 <= k ? n2 : k;
    k = i;
    for (j = 0; j < nj; j++) {
      yk = y[k];
      u1i = u2[j];
      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk += cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Feedback_3_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Feedback_3_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(Feedback_3_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(Feedback_3_M, 3));
  eventFlags[4] = ((boolean_T)rtmStepTask(Feedback_3_M, 4));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Feedback_3_M->Timing.TaskCounters.TID[1])++;
  if ((Feedback_3_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.0001s, 0.0s] */
    Feedback_3_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Feedback_3_M->Timing.TaskCounters.TID[2])++;
  if ((Feedback_3_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.001s, 0.0s] */
    Feedback_3_M->Timing.TaskCounters.TID[2] = 0;
  }

  (Feedback_3_M->Timing.TaskCounters.TID[3])++;
  if ((Feedback_3_M->Timing.TaskCounters.TID[3]) > 999) {/* Sample time: [0.01s, 0.0s] */
    Feedback_3_M->Timing.TaskCounters.TID[3] = 0;
  }

  (Feedback_3_M->Timing.TaskCounters.TID[4])++;
  if ((Feedback_3_M->Timing.TaskCounters.TID[4]) > 1999) {/* Sample time: [0.02s, 0.0s] */
    Feedback_3_M->Timing.TaskCounters.TID[4] = 0;
  }
}

/* Model step function for TID0 */
void Feedback_3_step0(void)            /* Sample time: [1.0E-5s, 0.0s] */
{
  {                                    /* Sample time: [1.0E-5s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void Feedback_3_step1(void)            /* Sample time: [0.0001s, 0.0s] */
{
  int32_T k;
  uint8_T tmp;
  real32_T rtb_ManualSwitch1;
  real_T DiscreteTransferFcn_tmp_j;
  real_T DiscreteTransferFcn_tmp_f;
  real_T tmp_0;
  uint64m_T tmp_1;
  uint32_T tmp_2;
  uint64m_T tmp_3;
  uint64m_T tmp_4;

  /* S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw2' */
  k = ADCRead(Feedback_3_P.ADRaw2_p1);

  /* Gain: '<S5>/Gain' incorporates:
   *  S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw2'
   */
  tmp_2 = (uint32_T)k;
  uMultiWordMul(&Feedback_3_P.Gain_Gain_i, 1, &tmp_2, 1, &tmp_1.chunks[0U], 2);

  /* Sum: '<S5>/Sum1' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   *  Sum: '<S5>/Sum'
   */
  Feedback_3_B.Gain5 = (uMultiWord2Double(&tmp_1.chunks[0U], 2, 0) *
                        1.1102230246251565E-16 + Feedback_3_P.Constant_Value_k)
    - Feedback_3_P.Constant1_Value;

  /* Saturate: '<S5>/Saturation' */
  if (Feedback_3_B.Gain5 > Feedback_3_P.Saturation_UpperSat) {
    Feedback_3_B.Gain5 = Feedback_3_P.Saturation_UpperSat;
  } else {
    if (Feedback_3_B.Gain5 < Feedback_3_P.Saturation_LowerSat) {
      Feedback_3_B.Gain5 = Feedback_3_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S5>/Saturation' */

  /* Sum: '<S9>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  Feedback_3_B.Gain6 = Feedback_3_B.Gain5 - Feedback_3_P.Constant_Value;

  /* Outport: '<Root>/Out1' incorporates:
   *  Gain: '<S9>/Gain1'
   */
  Feedback_3_Y.Out1 = Feedback_3_P.Gain1_Gain * Feedback_3_B.Gain6;

  /* Sum: '<S9>/Sum1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  Feedback_3_B.Gain6 += Feedback_3_P.Constant2_Value;

  /* Outport: '<Root>/Out2' incorporates:
   *  Gain: '<S9>/Gain2'
   */
  Feedback_3_Y.Out2 = Feedback_3_P.Gain2_Gain * Feedback_3_B.Gain6;

  /* DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn' incorporates:
   *  Gain: '<S9>/Contoller Gain'
   */
  Feedback_3_B.DiscreteTransferFcn_tmp = (Feedback_3_P.ContollerGain_Gain *
    Feedback_3_B.Gain6 - Feedback_3_P.DiscreteTransferFcn_DenCoef[1] *
    Feedback_3_DW.DiscreteTransferFcn_states) /
    Feedback_3_P.DiscreteTransferFcn_DenCoef[0];

  /* Sum: '<S9>/Sum2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn'
   */
  Feedback_3_B.ContollerGain = (Feedback_3_P.DiscreteTransferFcn_NumCoef[0] *
    Feedback_3_B.DiscreteTransferFcn_tmp +
    Feedback_3_P.DiscreteTransferFcn_NumCoef[1] *
    Feedback_3_DW.DiscreteTransferFcn_states) + Feedback_3_P.Constant1_Value_j;

  /* Outport: '<Root>/Out3' incorporates:
   *  Gain: '<S9>/Gain3'
   */
  Feedback_3_Y.Out3 = Feedback_3_P.Gain3_Gain * Feedback_3_B.ContollerGain;

  /* S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw1' */
  k = ADCRead(Feedback_3_P.ADRaw1_p1);

  /* Gain: '<S6>/Gain' incorporates:
   *  S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw1'
   */
  tmp_2 = (uint32_T)k;
  uMultiWordMul(&Feedback_3_P.Gain_Gain_k, 1, &tmp_2, 1, &tmp_3.chunks[0U], 2);

  /* Sum: '<S6>/Sum1' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Sum: '<S6>/Sum'
   */
  Feedback_3_B.Gain6 = (uMultiWord2Double(&tmp_3.chunks[0U], 2, 0) *
                        2.2204460492503131E-16 + Feedback_3_P.Constant_Value_i)
    - Feedback_3_P.Constant1_Value_p;

  /* Saturate: '<S6>/Saturation' */
  if (Feedback_3_B.Gain6 > Feedback_3_P.Saturation_UpperSat_n) {
    Feedback_3_B.Gain6 = Feedback_3_P.Saturation_UpperSat_n;
  } else {
    if (Feedback_3_B.Gain6 < Feedback_3_P.Saturation_LowerSat_c) {
      Feedback_3_B.Gain6 = Feedback_3_P.Saturation_LowerSat_c;
    }
  }

  /* End of Saturate: '<S6>/Saturation' */

  /* Sum: '<S10>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  Feedback_3_B.Gain4 = Feedback_3_B.Gain6 - Feedback_3_P.Constant_Value;

  /* Outport: '<Root>/Out4' incorporates:
   *  Gain: '<S10>/Gain1'
   */
  Feedback_3_Y.Out4 = Feedback_3_P.Gain1_Gain_l * Feedback_3_B.Gain4;

  /* Sum: '<S10>/Sum1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  Feedback_3_B.Gain4 += Feedback_3_P.Constant2_Value;

  /* Outport: '<Root>/Out5' incorporates:
   *  Gain: '<S10>/Gain2'
   */
  Feedback_3_Y.Out5 = Feedback_3_P.Gain2_Gain_e * Feedback_3_B.Gain4;

  /* DiscreteTransferFcn: '<S18>/Discrete Transfer Fcn' incorporates:
   *  Gain: '<S10>/Contoller Gain'
   */
  DiscreteTransferFcn_tmp_j = (Feedback_3_P.ContollerGain_Gain_m *
    Feedback_3_B.Gain4 - Feedback_3_P.DiscreteTransferFcn_DenCoef_e[1] *
    Feedback_3_DW.DiscreteTransferFcn_states_f) /
    Feedback_3_P.DiscreteTransferFcn_DenCoef_e[0];

  /* Sum: '<S10>/Sum2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  DiscreteTransferFcn: '<S18>/Discrete Transfer Fcn'
   */
  Feedback_3_B.ContollerGain_c = (Feedback_3_P.DiscreteTransferFcn_NumCoef_p[0] *
    DiscreteTransferFcn_tmp_j + Feedback_3_P.DiscreteTransferFcn_NumCoef_p[1] *
    Feedback_3_DW.DiscreteTransferFcn_states_f) + Feedback_3_P.Constant1_Value_j;

  /* Outport: '<Root>/Out6' incorporates:
   *  Gain: '<S10>/Gain3'
   */
  Feedback_3_Y.Out6 = Feedback_3_P.Gain3_Gain_o * Feedback_3_B.ContollerGain_c;

  /* S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw3' */
  k = ADCRead(Feedback_3_P.ADRaw3_p1);

  /* Gain: '<S4>/Gain' incorporates:
   *  S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw3'
   */
  tmp_2 = (uint32_T)k;
  uMultiWordMul(&Feedback_3_P.Gain_Gain_g, 1, &tmp_2, 1, &tmp_4.chunks[0U], 2);

  /* Sum: '<S4>/Sum1' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  Sum: '<S4>/Sum'
   */
  Feedback_3_B.Gain4 = (uMultiWord2Double(&tmp_4.chunks[0U], 2, 0) *
                        1.1102230246251565E-16 + Feedback_3_P.Constant_Value_b)
    - Feedback_3_P.Constant1_Value_i;

  /* Saturate: '<S4>/Saturation' */
  if (Feedback_3_B.Gain4 > Feedback_3_P.Saturation_UpperSat_c) {
    Feedback_3_B.Gain4 = Feedback_3_P.Saturation_UpperSat_c;
  } else {
    if (Feedback_3_B.Gain4 < Feedback_3_P.Saturation_LowerSat_i) {
      Feedback_3_B.Gain4 = Feedback_3_P.Saturation_LowerSat_i;
    }
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* Sum: '<S8>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  Feedback_3_B.Gain2_p = Feedback_3_B.Gain4 - Feedback_3_P.Constant_Value;

  /* Outport: '<Root>/Out7' incorporates:
   *  Gain: '<S8>/Gain1'
   */
  Feedback_3_Y.Out7 = Feedback_3_P.Gain1_Gain_j * Feedback_3_B.Gain2_p;

  /* Sum: '<S8>/Sum1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  Feedback_3_B.Gain2_p += Feedback_3_P.Constant2_Value;

  /* Outport: '<Root>/Out8' incorporates:
   *  Gain: '<S8>/Gain2'
   */
  Feedback_3_Y.Out8 = Feedback_3_P.Gain2_Gain_l * Feedback_3_B.Gain2_p;

  /* DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn' incorporates:
   *  Gain: '<S8>/Contoller Gain'
   */
  DiscreteTransferFcn_tmp_f = (Feedback_3_P.ContollerGain_Gain_e *
    Feedback_3_B.Gain2_p - Feedback_3_P.DiscreteTransferFcn_DenCoef_h[1] *
    Feedback_3_DW.DiscreteTransferFcn_states_b) /
    Feedback_3_P.DiscreteTransferFcn_DenCoef_h[0];

  /* Sum: '<S8>/Sum2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn'
   */
  Feedback_3_B.Gain2_p = (Feedback_3_P.DiscreteTransferFcn_NumCoef_e[0] *
    DiscreteTransferFcn_tmp_f + Feedback_3_P.DiscreteTransferFcn_NumCoef_e[1] *
    Feedback_3_DW.DiscreteTransferFcn_states_b) + Feedback_3_P.Constant1_Value_j;

  /* Outport: '<Root>/Out9' incorporates:
   *  Gain: '<S8>/Gain3'
   */
  Feedback_3_Y.Out9 = Feedback_3_P.Gain3_Gain_b * Feedback_3_B.Gain2_p;

  /* DataTypeConversion: '<S7>/Data Type Conversion3' incorporates:
   *  Gain: '<Root>/Gain'
   */
  tmp_0 = floor(Feedback_3_P.Gain_Gain * Feedback_3_B.Gain4);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 4.294967296E+9);
  }

  Feedback_3_B.DataTypeConversion3 = tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 :
    (int32_T)(uint32_T)tmp_0;

  /* End of DataTypeConversion: '<S7>/Data Type Conversion3' */

  /* DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  tmp_0 = floor(Feedback_3_P.Gain1_Gain_f * Feedback_3_B.Gain5);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 4.294967296E+9);
  }

  Feedback_3_B.DataTypeConversion1 = tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 :
    (int32_T)(uint32_T)tmp_0;

  /* End of DataTypeConversion: '<S7>/Data Type Conversion1' */

  /* DataTypeConversion: '<S7>/Data Type Conversion2' incorporates:
   *  Gain: '<Root>/Gain2'
   */
  tmp_0 = floor(Feedback_3_P.Gain2_Gain_n * Feedback_3_B.Gain6);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 4.294967296E+9);
  }

  Feedback_3_B.DataTypeConversion2 = tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 :
    (int32_T)(uint32_T)tmp_0;

  /* End of DataTypeConversion: '<S7>/Data Type Conversion2' */

  /* S-Function (any2byte): '<S7>/Byte Pack' */

  /* Pack: <S7>/Byte Pack */
  (void) memcpy(&Feedback_3_B.BytePack[0], &Feedback_3_B.DataTypeConversion3,
                4);
  (void) memcpy(&Feedback_3_B.BytePack[4], &Feedback_3_B.DataTypeConversion1,
                4);
  (void) memcpy(&Feedback_3_B.BytePack[8], &Feedback_3_B.DataTypeConversion2,
                4);

  /* S-Function (stellaris_lp_sfunc_XDataPackout): '<S7>/XComSend' */
  tmp = xdatapacket_put(12, Feedback_3_B.BytePack);

  /* Outport: '<Root>/Out10' incorporates:
   *  S-Function (stellaris_lp_sfunc_XDataPackout): '<S7>/XComSend'
   */
  Feedback_3_Y.Out10 = tmp;

  /* Gain: '<Root>/Gain4' */
  Feedback_3_B.Gain4 *= Feedback_3_P.Gain4_Gain;

  /* DataTypeConversion: '<Root>/Data Type Conversion6' */
  tmp_0 = floor(Feedback_3_B.Gain4);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 4.294967296E+9);
  }

  Feedback_3_B.DataTypeConversion6 = tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 :
    (int32_T)(uint32_T)tmp_0;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion6' */

  /* Gain: '<Root>/Gain5' */
  Feedback_3_B.Gain5 *= Feedback_3_P.Gain5_Gain;

  /* DataTypeConversion: '<Root>/Data Type Conversion8' */
  tmp_0 = floor(Feedback_3_B.Gain5);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 4.294967296E+9);
  }

  Feedback_3_B.DataTypeConversion8 = tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 :
    (int32_T)(uint32_T)tmp_0;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion8' */

  /* Gain: '<Root>/Gain6' */
  Feedback_3_B.Gain6 *= Feedback_3_P.Gain6_Gain;

  /* DataTypeConversion: '<Root>/Data Type Conversion9' */
  tmp_0 = floor(Feedback_3_B.Gain6);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 4.294967296E+9);
  }

  Feedback_3_B.DataTypeConversion9 = tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 :
    (int32_T)(uint32_T)tmp_0;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion9' */

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  if (Feedback_3_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ManualSwitch1 = (real32_T)Feedback_3_P.Constant3_Value;
  } else {
    /* Gain: '<S8>/Temperature  Normalization' incorporates:
     *  Constant: '<S8>/Current Offset'
     *  Gain: '<S8>/DC//I Gain'
     *  Sum: '<S8>/Sum3'
     */
    Feedback_3_B.Gain5 = (Feedback_3_P.CurrentOffset_Value_p +
                          Feedback_3_B.Gain2_p) * Feedback_3_P.DCIGain_Gain_i *
      Feedback_3_P.TemperatureNormalization_Gain_p;

    /* Saturate: '<S8>/Duty Cycle Saturation' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion2'
     */
    if (Feedback_3_B.Gain5 > Feedback_3_P.DutyCycleSaturation_UpperSat_f) {
      rtb_ManualSwitch1 = (real32_T)Feedback_3_P.DutyCycleSaturation_UpperSat_f;
    } else if (Feedback_3_B.Gain5 < Feedback_3_P.DutyCycleSaturation_LowerSat_c)
    {
      rtb_ManualSwitch1 = (real32_T)Feedback_3_P.DutyCycleSaturation_LowerSat_c;
    } else {
      rtb_ManualSwitch1 = (real32_T)Feedback_3_B.Gain5;
    }

    /* End of Saturate: '<S8>/Duty Cycle Saturation' */
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S1>/S-Function2' */
  PWMUpdate_f(Feedback_3_P.SFunction2_p1, rtb_ManualSwitch1);

  /* ManualSwitch: '<Root>/Manual Switch2' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  if (Feedback_3_P.ManualSwitch2_CurrentSetting == 1) {
    rtb_ManualSwitch1 = (real32_T)Feedback_3_P.Constant5_Value;
  } else {
    /* Gain: '<S10>/Temperature  Normalization' incorporates:
     *  Constant: '<S10>/Current Offset'
     *  Gain: '<S10>/DC//I Gain'
     *  Sum: '<S10>/Sum3'
     */
    Feedback_3_B.Gain5 = (Feedback_3_P.CurrentOffset_Value +
                          Feedback_3_B.ContollerGain_c) *
      Feedback_3_P.DCIGain_Gain * Feedback_3_P.TemperatureNormalization_Gain;

    /* Saturate: '<S10>/Duty Cycle Saturation' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion7'
     */
    if (Feedback_3_B.Gain5 > Feedback_3_P.DutyCycleSaturation_UpperSat) {
      rtb_ManualSwitch1 = (real32_T)Feedback_3_P.DutyCycleSaturation_UpperSat;
    } else if (Feedback_3_B.Gain5 < Feedback_3_P.DutyCycleSaturation_LowerSat) {
      rtb_ManualSwitch1 = (real32_T)Feedback_3_P.DutyCycleSaturation_LowerSat;
    } else {
      rtb_ManualSwitch1 = (real32_T)Feedback_3_B.Gain5;
    }

    /* End of Saturate: '<S10>/Duty Cycle Saturation' */
  }

  /* End of ManualSwitch: '<Root>/Manual Switch2' */

  /* S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S2>/S-Function2' */
  PWMUpdate_f(Feedback_3_P.SFunction2_p1_c, rtb_ManualSwitch1);

  /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  if (Feedback_3_P.ManualSwitch1_CurrentSetting == 1) {
    rtb_ManualSwitch1 = (real32_T)Feedback_3_P.Constant4_Value;
  } else {
    /* Gain: '<S9>/Temperature  Normalization' incorporates:
     *  Constant: '<S9>/Current Offset'
     *  Gain: '<S9>/DC//I Gain'
     *  Sum: '<S9>/Sum3'
     */
    Feedback_3_B.Gain5 = (Feedback_3_P.CurrentOffset_Value_o +
                          Feedback_3_B.ContollerGain) *
      Feedback_3_P.DCIGain_Gain_k * Feedback_3_P.TemperatureNormalization_Gain_h;

    /* Saturate: '<S9>/Duty Cycle Saturation' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion5'
     */
    if (Feedback_3_B.Gain5 > Feedback_3_P.DutyCycleSaturation_UpperSat_a) {
      rtb_ManualSwitch1 = (real32_T)Feedback_3_P.DutyCycleSaturation_UpperSat_a;
    } else if (Feedback_3_B.Gain5 < Feedback_3_P.DutyCycleSaturation_LowerSat_n)
    {
      rtb_ManualSwitch1 = (real32_T)Feedback_3_P.DutyCycleSaturation_LowerSat_n;
    } else {
      rtb_ManualSwitch1 = (real32_T)Feedback_3_B.Gain5;
    }

    /* End of Saturate: '<S9>/Duty Cycle Saturation' */
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */

  /* S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S3>/S-Function2' */
  PWMUpdate_f(Feedback_3_P.SFunction2_p1_d, rtb_ManualSwitch1);

  /* S-Function (stellaris_lp_sfunc_GPIOWrite): '<S7>/GPIO Write' incorporates:
   *  Constant: '<S7>/RED LED'
   *  Constant: '<S7>/Red LED Off'
   */
  GPIOWrite(Feedback_3_P.GPIOWrite_p1, Feedback_3_P.REDLED_Value,
            Feedback_3_P.RedLEDOff_Value);

  /* S-Function (stellaris_lp_sfunc_GPIOSetup): '<S7>/GPIO Setup' */
  GPIOVoidFunc();

  /* S-Function (stellaris_lp_sfunc_XDataInit): '<S7>/XComInit' */
  init_xdatapacket_void();

  /* Update for DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn' */
  Feedback_3_DW.DiscreteTransferFcn_states =
    Feedback_3_B.DiscreteTransferFcn_tmp;

  /* Update for DiscreteTransferFcn: '<S18>/Discrete Transfer Fcn' */
  Feedback_3_DW.DiscreteTransferFcn_states_f = DiscreteTransferFcn_tmp_j;

  /* Update for DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn' */
  Feedback_3_DW.DiscreteTransferFcn_states_b = DiscreteTransferFcn_tmp_f;
}

/* Model step function for TID2 */
void Feedback_3_step2(void)            /* Sample time: [0.001s, 0.0s] */
{
  /* S-Function (stellaris_lp_sfunc_ADCRead): '<S15>/AD Raw1' */
  ADCRead(Feedback_3_P.ADRaw1_p1_f);

  /* S-Function (stellaris_lp_sfunc_ADCRead): '<S17>/AD Raw1' */
  ADCRead(Feedback_3_P.ADRaw1_p1_a);
}

/* Model step function for TID3 */
void Feedback_3_step3(void)            /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (stellaris_lp_sfunc_DebugPrint): '<Root>/Debug Print' */
  DebugPrint(Feedback_3_P.DebugPrint_p1, Feedback_3_B.DataTypeConversion6,
             Feedback_3_B.DataTypeConversion8, Feedback_3_B.DataTypeConversion9,
             Feedback_3_B.DataTypeConversion10);
}

/* Model step function for TID4 */
void Feedback_3_step4(void)            /* Sample time: [0.02s, 0.0s] */
{
  uint8_T rtb_TmpRTBAtMultiportSwitchInpo;
  int32_T rtb_DataTypeConversion4;
  uint8_T rtb_SFunction_o1;
  real_T tmp;

  /* S-Function (stellaris_lp_sfunc_XDataPackin): '<S12>/S-Function' incorporates:
   *  Inport: '<S13>/In1'
   */
  rtb_TmpRTBAtMultiportSwitchInpo = xdatapacket_get(1, &rtb_SFunction_o1);

  /* Outputs for Enabled SubSystem: '<S12>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  if (rtb_TmpRTBAtMultiportSwitchInpo > 0) {
    Feedback_3_B.In1 = rtb_SFunction_o1;
  }

  /* End of S-Function (stellaris_lp_sfunc_XDataPackin): '<S12>/S-Function' */
  /* End of Outputs for SubSystem: '<S12>/Enabled Subsystem' */

  /* S-Function (xpcbytepacking): '<S7>/Unpack' */

  /* Byte Unpacking: <S7>/Unpack */
  (void)memcpy((uint8_T*)&Feedback_3_B.Unpack, (uint8_T*)&Feedback_3_B.In1 + 0,
               1);

  /* RateTransition: '<S7>/TmpRTBAtMultiport SwitchInport2' incorporates:
   *  Constant: '<S7>/Red LED Off'
   */
  rtb_TmpRTBAtMultiportSwitchInpo = Feedback_3_P.RedLEDOff_Value;

  /* RateTransition: '<S7>/TmpRTBAtMultiport SwitchInport6' incorporates:
   *  Constant: '<S7>/Red LED Off'
   */
  rtb_SFunction_o1 = Feedback_3_P.RedLEDOff_Value;

  /* MultiPortSwitch: '<S7>/Multiport Switch' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Red LED On'
   *  Constant: '<S7>/Red LED On1'
   *  Constant: '<S7>/Red LED On2'
   *  Sum: '<S7>/Subtract'
   */
  switch ((uint8_T)(Feedback_3_B.Unpack - Feedback_3_P.Constant_Value_m)) {
   case 0:
    rtb_SFunction_o1 = rtb_TmpRTBAtMultiportSwitchInpo;
    break;

   case 1:
    rtb_SFunction_o1 = Feedback_3_P.RedLEDOn_Value;
    break;

   case 2:
    rtb_SFunction_o1 = Feedback_3_P.RedLEDOn1_Value;
    break;

   case 3:
    rtb_SFunction_o1 = Feedback_3_P.RedLEDOn2_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S7>/Multiport Switch' */

  /* DataTypeConversion: '<S7>/Data Type Conversion4' */
  rtb_DataTypeConversion4 = rtb_SFunction_o1;

  /* MATLAB Function: '<S7>/MATLAB Function' */
  if (rtb_DataTypeConversion4 == 0) {
    switch (Feedback_3_DW.val) {
     case 1:
      Feedback_3_DW.output++;
      break;

     case 2:
      Feedback_3_DW.output--;
      break;

     case 3:
      Feedback_3_DW.output = 0.0;
      break;
    }

    Feedback_3_DW.val = 0;
  } else {
    Feedback_3_DW.val = rtb_DataTypeConversion4;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion10' incorporates:
   *  Gain: '<Root>/Gain3'
   *  MATLAB Function: '<S7>/MATLAB Function'
   */
  tmp = floor(Feedback_3_P.Gain3_Gain_n * Feedback_3_DW.output);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  Feedback_3_B.DataTypeConversion10 = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
    (int32_T)(uint32_T)tmp;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion10' */
}

/* Model initialize function */
void Feedback_3_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Feedback_3_M, 0,
                sizeof(RT_MODEL_Feedback_3_T));

  /* block I/O */
  (void) memset(((void *) &Feedback_3_B), 0,
                sizeof(B_Feedback_3_T));

  /* states (dwork) */
  (void) memset((void *)&Feedback_3_DW, 0,
                sizeof(DW_Feedback_3_T));

  /* external outputs */
  (void) memset((void *)&Feedback_3_Y, 0,
                sizeof(ExtY_Feedback_3_T));

  /* Start for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S1>/S-Function2' */
  PWMInit(Feedback_3_P.SFunction2_p1, Feedback_3_P.SFunction2_p2,
          Feedback_3_P.SFunction2_p3);

  /* Start for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S2>/S-Function2' */
  PWMInit(Feedback_3_P.SFunction2_p1_c, Feedback_3_P.SFunction2_p2_l,
          Feedback_3_P.SFunction2_p3_m);

  /* Start for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S3>/S-Function2' */
  PWMInit(Feedback_3_P.SFunction2_p1_d, Feedback_3_P.SFunction2_p2_e,
          Feedback_3_P.SFunction2_p3_mx);

  /* Start for S-Function (stellaris_lp_sfunc_GPIOSetup): '<S7>/GPIO Setup' */
  GPIOSetup(Feedback_3_P.GPIOSetup_p1, Feedback_3_P.GPIOSetup_p2,
            Feedback_3_P.GPIOSetup_p3, Feedback_3_P.GPIOSetup_p4);

  /* Start for S-Function (stellaris_lp_sfunc_XDataInit): '<S7>/XComInit' */
  init_xdatapacket(Feedback_3_P.XComInit_p1);

  /* InitializeConditions for DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn' */
  Feedback_3_DW.DiscreteTransferFcn_states =
    Feedback_3_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for DiscreteTransferFcn: '<S18>/Discrete Transfer Fcn' */
  Feedback_3_DW.DiscreteTransferFcn_states_f =
    Feedback_3_P.DiscreteTransferFcn_InitialSt_f;

  /* InitializeConditions for DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn' */
  Feedback_3_DW.DiscreteTransferFcn_states_b =
    Feedback_3_P.DiscreteTransferFcn_InitialSt_b;

  /* SystemInitialize for Enabled SubSystem: '<S12>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S13>/Out1' */
  Feedback_3_B.In1 = Feedback_3_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S12>/Enabled Subsystem' */

  /* SystemInitialize for MATLAB Function: '<S7>/MATLAB Function' */
  Feedback_3_DW.val = 0;
  Feedback_3_DW.output = 0.0;
}

/* Model terminate function */
void Feedback_3_terminate(void)
{
  /* Terminate for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S1>/S-Function2' */
  PWMStop(Feedback_3_P.SFunction2_p1);

  /* Terminate for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S2>/S-Function2' */
  PWMStop(Feedback_3_P.SFunction2_p1_c);

  /* Terminate for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S3>/S-Function2' */
  PWMStop(Feedback_3_P.SFunction2_p1_d);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
