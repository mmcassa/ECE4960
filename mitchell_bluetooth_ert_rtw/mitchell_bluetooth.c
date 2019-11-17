/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mitchell_bluetooth.c
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

/* Block signals (default storage) */
B_mitchell_bluetooth_T mitchell_bluetooth_B;

/* Block states (default storage) */
DW_mitchell_bluetooth_T mitchell_bluetooth_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_mitchell_bluetooth_T mitchell_bluetooth_Y;

/* Real-time model */
RT_MODEL_mitchell_bluetooth_T mitchell_bluetooth_M_;
RT_MODEL_mitchell_bluetooth_T *const mitchell_bluetooth_M =
  &mitchell_bluetooth_M_;
static void rate_monotonic_scheduler(void);
int32_T MultiWord2sLong(const uint32_T u[])
{
  return (int32_T)u[0];
}

void sMultiWordShr(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T nb;
  int32_T i;
  uint32_T ys;
  uint32_T yi;
  uint32_T u1i;
  int32_T nc;
  uint32_T nr;
  uint32_T nl;
  int32_T i1;
  nb = (int32_T)(n2 >> 5);
  i = 0;
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  if (nb < n1) {
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint32_T)nb << 5);
    if (nr > 0U) {
      nl = 32U - nr;
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << nl | yi;
        i++;
      }

      yi = u1i >> nr;
      u1i = nc < n1 ? u1[nc] : ys;
      y[i] = u1i << nl | yi;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
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
  boolean_T isNegative1;
  boolean_T isNegative2;
  uint32_T cb1;
  uint32_T cb2;
  isNegative1 = ((u1[n1 - 1] & 2147483648U) != 0U);
  isNegative2 = ((u2[n2 - 1] & 2147483648U) != 0U);
  cb1 = 1U;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    cb2 = 1U;
    k = n - i;
    nj = n2 <= k ? n2 : k;
    k = i;
    for (j = 0; j < nj; j++) {
      yk = y[k];
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

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

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1U;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void mitchell_bluetooth_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(mitchell_bluetooth_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(mitchell_bluetooth_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(mitchell_bluetooth_M, 3));
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
  (mitchell_bluetooth_M->Timing.TaskCounters.TID[1])++;
  if ((mitchell_bluetooth_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.0001s, 0.0s] */
    mitchell_bluetooth_M->Timing.TaskCounters.TID[1] = 0;
  }

  (mitchell_bluetooth_M->Timing.TaskCounters.TID[2])++;
  if ((mitchell_bluetooth_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.001s, 0.0s] */
    mitchell_bluetooth_M->Timing.TaskCounters.TID[2] = 0;
  }

  (mitchell_bluetooth_M->Timing.TaskCounters.TID[3])++;
  if ((mitchell_bluetooth_M->Timing.TaskCounters.TID[3]) > 1999) {/* Sample time: [0.1s, 0.0s] */
    mitchell_bluetooth_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/* Model step function for TID0 */
void mitchell_bluetooth_step0(void)    /* Sample time: [5.0E-5s, 0.0s] */
{
  {                                    /* Sample time: [5.0E-5s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void mitchell_bluetooth_step1(void)    /* Sample time: [0.0001s, 0.0s] */
{
  int32_T k;
  real32_T rtb_Gain1_hj;
  real_T rtb_Sum2;
  real32_T rtb_Gain2_g;
  real_T rtb_ContollerGain_c;
  real_T rtb_Sum2_b;
  real32_T rtb_Gain_cx;
  real_T rtb_ContollerGain_k;
  real32_T rtb_ManualSwitch1;
  real_T DiscreteTransferFcn_tmp;

  /* S-Function (stellaris_lp_sfunc_ADCRead): '<S2>/AD Raw1' */
  k = ADCRead(mitchell_bluetooth_P.ADRaw1_p1);

  /* Sum: '<S8>/Sum' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Zero Sensor Voltage'
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  Gain: '<S2>/ToVolt'
   *  Gain: '<S8>/Gain'
   *  S-Function (stellaris_lp_sfunc_ADCRead): '<S2>/AD Raw1'
   *  Sum: '<S8>/Sum1'
   */
  rtb_Gain1_hj = (mitchell_bluetooth_P.ToVolt_Gain * (real32_T)(uint32_T)k -
                  mitchell_bluetooth_P.ZeroSensorVoltage_Value) *
    mitchell_bluetooth_P.Gain_Gain + mitchell_bluetooth_P.Constant_Value_n;

  /* Sum: '<S12>/Sum' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   */
  mitchell_bluetooth_B.MultiportSwitch1_o = rtb_Gain1_hj -
    mitchell_bluetooth_B.ManualSwitch4;

  /* Outport: '<Root>/Out1' incorporates:
   *  Gain: '<S12>/Gain1'
   */
  mitchell_bluetooth_Y.Out1 = mitchell_bluetooth_P.Gain1_Gain *
    mitchell_bluetooth_B.MultiportSwitch1_o;

  /* Sum: '<S12>/Sum1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  mitchell_bluetooth_B.MultiportSwitch1_o +=
    mitchell_bluetooth_P.Constant2_Value;

  /* Outport: '<Root>/Out2' incorporates:
   *  Gain: '<S12>/Gain2'
   */
  mitchell_bluetooth_Y.Out2 = mitchell_bluetooth_P.Gain2_Gain *
    mitchell_bluetooth_B.MultiportSwitch1_o;

  /* DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn' incorporates:
   *  Gain: '<S12>/Contoller Gain'
   */
  DiscreteTransferFcn_tmp = (mitchell_bluetooth_P.ContollerGain_Gain *
    mitchell_bluetooth_B.MultiportSwitch1_o -
    mitchell_bluetooth_P.DiscreteTransferFcn_DenCoef[1] *
    mitchell_bluetooth_DW.DiscreteTransferFcn_states) /
    mitchell_bluetooth_P.DiscreteTransferFcn_DenCoef[0];

  /* Sum: '<S12>/Sum2' incorporates:
   *  DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn'
   */
  rtb_Sum2 = (mitchell_bluetooth_P.DiscreteTransferFcn_NumCoef[0] *
              DiscreteTransferFcn_tmp +
              mitchell_bluetooth_P.DiscreteTransferFcn_NumCoef[1] *
              mitchell_bluetooth_DW.DiscreteTransferFcn_states) +
    mitchell_bluetooth_B.ManualSwitch3;

  /* Outport: '<Root>/Out3' incorporates:
   *  Gain: '<S12>/Gain3'
   */
  mitchell_bluetooth_Y.Out3 = mitchell_bluetooth_P.Gain3_Gain * rtb_Sum2;

  /* S-Function (stellaris_lp_sfunc_ADCRead): '<S3>/AD Raw1' */
  k = ADCRead(mitchell_bluetooth_P.ADRaw1_p1_f);

  /* Sum: '<S9>/Sum' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Zero Sensor Voltage'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Gain: '<S3>/ToVolt'
   *  Gain: '<S9>/Gain'
   *  S-Function (stellaris_lp_sfunc_ADCRead): '<S3>/AD Raw1'
   *  Sum: '<S9>/Sum1'
   */
  rtb_Gain2_g = (mitchell_bluetooth_P.ToVolt_Gain_d * (real32_T)(uint32_T)k -
                 mitchell_bluetooth_P.ZeroSensorVoltage_Value_k) *
    mitchell_bluetooth_P.Gain_Gain_e + mitchell_bluetooth_P.Constant_Value_k;

  /* Sum: '<S13>/Sum' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  mitchell_bluetooth_B.MultiportSwitch1_o = rtb_Gain2_g -
    mitchell_bluetooth_B.ManualSwitch4;

  /* Outport: '<Root>/Out4' incorporates:
   *  Gain: '<S13>/Gain1'
   */
  mitchell_bluetooth_Y.Out4 = mitchell_bluetooth_P.Gain1_Gain_o *
    mitchell_bluetooth_B.MultiportSwitch1_o;

  /* Sum: '<S13>/Sum1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  mitchell_bluetooth_B.MultiportSwitch1_o +=
    mitchell_bluetooth_P.Constant2_Value;

  /* Outport: '<Root>/Out5' incorporates:
   *  Gain: '<S13>/Gain2'
   */
  mitchell_bluetooth_Y.Out5 = mitchell_bluetooth_P.Gain2_Gain_b *
    mitchell_bluetooth_B.MultiportSwitch1_o;

  /* DiscreteTransferFcn: '<S20>/Discrete Transfer Fcn' incorporates:
   *  Gain: '<S13>/Contoller Gain'
   */
  mitchell_bluetooth_B.ContollerGain =
    (mitchell_bluetooth_P.ContollerGain_Gain_a *
     mitchell_bluetooth_B.MultiportSwitch1_o -
     mitchell_bluetooth_P.DiscreteTransferFcn_DenCoef_j[1] *
     mitchell_bluetooth_DW.DiscreteTransferFcn_states_k) /
    mitchell_bluetooth_P.DiscreteTransferFcn_DenCoef_j[0];

  /* Sum: '<S13>/Sum2' incorporates:
   *  DiscreteTransferFcn: '<S20>/Discrete Transfer Fcn'
   */
  rtb_Sum2_b = (mitchell_bluetooth_P.DiscreteTransferFcn_NumCoef_j[0] *
                mitchell_bluetooth_B.ContollerGain +
                mitchell_bluetooth_P.DiscreteTransferFcn_NumCoef_j[1] *
                mitchell_bluetooth_DW.DiscreteTransferFcn_states_k) +
    mitchell_bluetooth_B.ManualSwitch3;

  /* Outport: '<Root>/Out6' incorporates:
   *  Gain: '<S13>/Gain3'
   */
  mitchell_bluetooth_Y.Out6 = mitchell_bluetooth_P.Gain3_Gain_g * rtb_Sum2_b;

  /* S-Function (stellaris_lp_sfunc_ADCRead): '<S1>/AD Raw1' */
  k = ADCRead(mitchell_bluetooth_P.ADRaw1_p1_e);

  /* Sum: '<S7>/Sum' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Zero Sensor Voltage'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  Gain: '<S1>/ToVolt'
   *  Gain: '<S7>/Gain'
   *  S-Function (stellaris_lp_sfunc_ADCRead): '<S1>/AD Raw1'
   *  Sum: '<S7>/Sum1'
   */
  rtb_Gain_cx = (mitchell_bluetooth_P.ToVolt_Gain_l * (real32_T)(uint32_T)k -
                 mitchell_bluetooth_P.ZeroSensorVoltage_Value_i) *
    mitchell_bluetooth_P.Gain_Gain_g + mitchell_bluetooth_P.Constant_Value_b;

  /* Sum: '<S11>/Sum' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   */
  mitchell_bluetooth_B.MultiportSwitch1_o = rtb_Gain_cx -
    mitchell_bluetooth_B.ManualSwitch4;

  /* Outport: '<Root>/Out7' incorporates:
   *  Gain: '<S11>/Gain1'
   */
  mitchell_bluetooth_Y.Out7 = mitchell_bluetooth_P.Gain1_Gain_j *
    mitchell_bluetooth_B.MultiportSwitch1_o;

  /* Sum: '<S11>/Sum1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  mitchell_bluetooth_B.MultiportSwitch1_o +=
    mitchell_bluetooth_P.Constant2_Value;

  /* Outport: '<Root>/Out8' incorporates:
   *  Gain: '<S11>/Gain2'
   */
  mitchell_bluetooth_Y.Out8 = mitchell_bluetooth_P.Gain2_Gain_l *
    mitchell_bluetooth_B.MultiportSwitch1_o;

  /* DiscreteTransferFcn: '<S18>/Discrete Transfer Fcn' incorporates:
   *  Gain: '<S11>/Contoller Gain'
   */
  rtb_ContollerGain_c = (mitchell_bluetooth_P.ContollerGain_Gain_e *
    mitchell_bluetooth_B.MultiportSwitch1_o -
    mitchell_bluetooth_P.DiscreteTransferFcn_DenCoef_h[1] *
    mitchell_bluetooth_DW.DiscreteTransferFcn_states_b) /
    mitchell_bluetooth_P.DiscreteTransferFcn_DenCoef_h[0];

  /* Sum: '<S11>/Sum2' incorporates:
   *  DiscreteTransferFcn: '<S18>/Discrete Transfer Fcn'
   */
  rtb_ContollerGain_k = (mitchell_bluetooth_P.DiscreteTransferFcn_NumCoef_e[0] *
    rtb_ContollerGain_c + mitchell_bluetooth_P.DiscreteTransferFcn_NumCoef_e[1] *
    mitchell_bluetooth_DW.DiscreteTransferFcn_states_b) +
    mitchell_bluetooth_B.ManualSwitch3;

  /* Outport: '<Root>/Out9' incorporates:
   *  Gain: '<S11>/Gain3'
   */
  mitchell_bluetooth_Y.Out9 = mitchell_bluetooth_P.Gain3_Gain_b *
    rtb_ContollerGain_k;

  /* MultiPortSwitch: '<Root>/Multiport Switch2' incorporates:
   *  Constant: '<Root>/Constant8'
   *  Constant: '<S13>/Current Offset'
   *  Gain: '<S13>/DC//I Gain'
   *  Gain: '<S13>/Temperature  Normalization'
   *  Sum: '<S13>/Sum3'
   */
  if (mitchell_bluetooth_B.latch == 0) {
    mitchell_bluetooth_B.MultiportSwitch1_o =
      mitchell_bluetooth_P.Constant8_Value;
  } else {
    mitchell_bluetooth_B.MultiportSwitch1_o =
      (mitchell_bluetooth_P.CurrentOffset_Value + rtb_Sum2_b) *
      mitchell_bluetooth_P.DCIGain_Gain *
      mitchell_bluetooth_P.TemperatureNormalization_Gain;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch2' */

  /* RateLimiter: '<Root>/Rate Limiter2' */
  mitchell_bluetooth_B.rateLimiterRate = mitchell_bluetooth_B.MultiportSwitch1_o
    - mitchell_bluetooth_DW.PrevY;
  if (mitchell_bluetooth_B.rateLimiterRate >
      mitchell_bluetooth_P.RateLimiter2_RisingLim) {
    mitchell_bluetooth_B.MultiportSwitch1_o = mitchell_bluetooth_DW.PrevY +
      mitchell_bluetooth_P.RateLimiter2_RisingLim;
  } else {
    if (mitchell_bluetooth_B.rateLimiterRate <
        mitchell_bluetooth_P.RateLimiter2_FallingLim) {
      mitchell_bluetooth_B.MultiportSwitch1_o = mitchell_bluetooth_DW.PrevY +
        mitchell_bluetooth_P.RateLimiter2_FallingLim;
    }
  }

  mitchell_bluetooth_DW.PrevY = mitchell_bluetooth_B.MultiportSwitch1_o;

  /* End of RateLimiter: '<Root>/Rate Limiter2' */

  /* Saturate: '<Root>/Duty Cycle Saturation2' */
  if (mitchell_bluetooth_B.MultiportSwitch1_o >
      mitchell_bluetooth_P.DutyCycleSaturation2_UpperSat) {
    rtb_Sum2_b = mitchell_bluetooth_P.DutyCycleSaturation2_UpperSat;
  } else if (mitchell_bluetooth_B.MultiportSwitch1_o <
             mitchell_bluetooth_P.DutyCycleSaturation2_LowerSat) {
    rtb_Sum2_b = mitchell_bluetooth_P.DutyCycleSaturation2_LowerSat;
  } else {
    rtb_Sum2_b = mitchell_bluetooth_B.MultiportSwitch1_o;
  }

  /* End of Saturate: '<Root>/Duty Cycle Saturation2' */

  /* DataTypeConversion: '<Root>/Data Type Conversion10' incorporates:
   *  Gain: '<Root>/Gain3'
   */
  mitchell_bluetooth_B.MultiportSwitch1_o = floor
    (mitchell_bluetooth_P.Gain3_Gain_n * rtb_Sum2_b);
  if (rtIsNaN(mitchell_bluetooth_B.MultiportSwitch1_o) || rtIsInf
      (mitchell_bluetooth_B.MultiportSwitch1_o)) {
    mitchell_bluetooth_B.MultiportSwitch1_o = 0.0;
  } else {
    mitchell_bluetooth_B.MultiportSwitch1_o = fmod
      (mitchell_bluetooth_B.MultiportSwitch1_o, 4.294967296E+9);
  }

  mitchell_bluetooth_B.DataTypeConversion10 =
    mitchell_bluetooth_B.MultiportSwitch1_o < 0.0 ? -(int32_T)(uint32_T)
    -mitchell_bluetooth_B.MultiportSwitch1_o : (int32_T)(uint32_T)
    mitchell_bluetooth_B.MultiportSwitch1_o;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion10' */

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<Root>/Constant7'
   *  Constant: '<S11>/Current Offset'
   *  Gain: '<S11>/DC//I Gain'
   *  Gain: '<S11>/Temperature  Normalization'
   *  Sum: '<S11>/Sum3'
   */
  if (mitchell_bluetooth_B.latch == 0) {
    mitchell_bluetooth_B.MultiportSwitch1_o =
      mitchell_bluetooth_P.Constant7_Value;
  } else {
    mitchell_bluetooth_B.MultiportSwitch1_o =
      (mitchell_bluetooth_P.CurrentOffset_Value_p3 + rtb_ContollerGain_k) *
      mitchell_bluetooth_P.DCIGain_Gain_i *
      mitchell_bluetooth_P.TemperatureNormalization_Gain_p;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* RateLimiter: '<Root>/Rate Limiter' */
  mitchell_bluetooth_B.rateLimiterRate = mitchell_bluetooth_B.MultiportSwitch1_o
    - mitchell_bluetooth_DW.PrevY_c;
  if (mitchell_bluetooth_B.rateLimiterRate >
      mitchell_bluetooth_P.RateLimiter_RisingLim) {
    mitchell_bluetooth_B.MultiportSwitch1_o = mitchell_bluetooth_DW.PrevY_c +
      mitchell_bluetooth_P.RateLimiter_RisingLim;
  } else {
    if (mitchell_bluetooth_B.rateLimiterRate <
        mitchell_bluetooth_P.RateLimiter_FallingLim) {
      mitchell_bluetooth_B.MultiportSwitch1_o = mitchell_bluetooth_DW.PrevY_c +
        mitchell_bluetooth_P.RateLimiter_FallingLim;
    }
  }

  mitchell_bluetooth_DW.PrevY_c = mitchell_bluetooth_B.MultiportSwitch1_o;

  /* End of RateLimiter: '<Root>/Rate Limiter' */

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant3'
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  Saturate: '<Root>/Duty Cycle Saturation'
   */
  if (mitchell_bluetooth_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ManualSwitch1 = (real32_T)mitchell_bluetooth_P.Constant3_Value;
  } else if (mitchell_bluetooth_B.MultiportSwitch1_o >
             mitchell_bluetooth_P.DutyCycleSaturation_UpperSat) {
    /* Saturate: '<Root>/Duty Cycle Saturation' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion2'
     */
    rtb_ManualSwitch1 = (real32_T)
      mitchell_bluetooth_P.DutyCycleSaturation_UpperSat;
  } else if (mitchell_bluetooth_B.MultiportSwitch1_o <
             mitchell_bluetooth_P.DutyCycleSaturation_LowerSat) {
    /* Saturate: '<Root>/Duty Cycle Saturation' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion2'
     */
    rtb_ManualSwitch1 = (real32_T)
      mitchell_bluetooth_P.DutyCycleSaturation_LowerSat;
  } else {
    rtb_ManualSwitch1 = (real32_T)mitchell_bluetooth_B.MultiportSwitch1_o;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S4>/S-Function2' */
  PWMUpdate_f(mitchell_bluetooth_P.SFunction2_p1, rtb_ManualSwitch1);

  /* ManualSwitch: '<Root>/Manual Switch2' incorporates:
   *  Constant: '<Root>/Constant5'
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   */
  if (mitchell_bluetooth_P.ManualSwitch2_CurrentSetting == 1) {
    rtb_ManualSwitch1 = (real32_T)mitchell_bluetooth_P.Constant5_Value;
  } else {
    rtb_ManualSwitch1 = (real32_T)rtb_Sum2_b;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch2' */

  /* S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S5>/S-Function2' */
  PWMUpdate_f(mitchell_bluetooth_P.SFunction2_p1_c, rtb_ManualSwitch1);

  /* MultiPortSwitch: '<Root>/Multiport Switch1' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<S12>/Current Offset'
   *  Gain: '<S12>/DC//I Gain'
   *  Gain: '<S12>/Temperature  Normalization'
   *  Sum: '<S12>/Sum3'
   */
  if (mitchell_bluetooth_B.latch == 0) {
    mitchell_bluetooth_B.MultiportSwitch1_o =
      mitchell_bluetooth_P.Constant6_Value;
  } else {
    mitchell_bluetooth_B.MultiportSwitch1_o =
      (mitchell_bluetooth_P.CurrentOffset_Value_p + rtb_Sum2) *
      mitchell_bluetooth_P.DCIGain_Gain_a *
      mitchell_bluetooth_P.TemperatureNormalization_Gain_i;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch1' */

  /* RateLimiter: '<Root>/Rate Limiter1' */
  mitchell_bluetooth_B.rateLimiterRate = mitchell_bluetooth_B.MultiportSwitch1_o
    - mitchell_bluetooth_DW.PrevY_n;
  if (mitchell_bluetooth_B.rateLimiterRate >
      mitchell_bluetooth_P.RateLimiter1_RisingLim) {
    mitchell_bluetooth_B.MultiportSwitch1_o = mitchell_bluetooth_DW.PrevY_n +
      mitchell_bluetooth_P.RateLimiter1_RisingLim;
  } else {
    if (mitchell_bluetooth_B.rateLimiterRate <
        mitchell_bluetooth_P.RateLimiter1_FallingLim) {
      mitchell_bluetooth_B.MultiportSwitch1_o = mitchell_bluetooth_DW.PrevY_n +
        mitchell_bluetooth_P.RateLimiter1_FallingLim;
    }
  }

  mitchell_bluetooth_DW.PrevY_n = mitchell_bluetooth_B.MultiportSwitch1_o;

  /* End of RateLimiter: '<Root>/Rate Limiter1' */

  /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
   *  Constant: '<Root>/Constant4'
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   *  Saturate: '<Root>/Duty Cycle Saturation1'
   */
  if (mitchell_bluetooth_P.ManualSwitch1_CurrentSetting == 1) {
    rtb_ManualSwitch1 = (real32_T)mitchell_bluetooth_P.Constant4_Value;
  } else if (mitchell_bluetooth_B.MultiportSwitch1_o >
             mitchell_bluetooth_P.DutyCycleSaturation1_UpperSat) {
    /* Saturate: '<Root>/Duty Cycle Saturation1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion5'
     */
    rtb_ManualSwitch1 = (real32_T)
      mitchell_bluetooth_P.DutyCycleSaturation1_UpperSat;
  } else if (mitchell_bluetooth_B.MultiportSwitch1_o <
             mitchell_bluetooth_P.DutyCycleSaturation1_LowerSat) {
    /* Saturate: '<Root>/Duty Cycle Saturation1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion5'
     */
    rtb_ManualSwitch1 = (real32_T)
      mitchell_bluetooth_P.DutyCycleSaturation1_LowerSat;
  } else {
    rtb_ManualSwitch1 = (real32_T)mitchell_bluetooth_B.MultiportSwitch1_o;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */

  /* S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S6>/S-Function2' */
  PWMUpdate_f(mitchell_bluetooth_P.SFunction2_p1_d, rtb_ManualSwitch1);

  /* Gain: '<Root>/Gain' */
  rtb_Gain_cx *= mitchell_bluetooth_P.Gain_Gain_n;

  /* Gain: '<Root>/Gain1' */
  rtb_Gain1_hj *= mitchell_bluetooth_P.Gain1_Gain_f;

  /* Gain: '<Root>/Gain2' */
  rtb_Gain2_g *= mitchell_bluetooth_P.Gain2_Gain_n;

  /* S-Function (stellaris_lp_sfunc_GPIOWrite): '<S10>/GPIO Write' incorporates:
   *  Constant: '<S10>/RED LED'
   *  Constant: '<S10>/Red LED Off'
   */
  GPIOWrite(mitchell_bluetooth_P.GPIOWrite_p1, mitchell_bluetooth_P.REDLED_Value,
            mitchell_bluetooth_P.RedLEDOff_Value);

  /* DataTypeConversion: '<S10>/Data Type Conversion3' */
  rtb_ManualSwitch1 = (real32_T)floor(rtb_Gain_cx);
  if (rtIsNaNF(rtb_ManualSwitch1) || rtIsInfF(rtb_ManualSwitch1)) {
    rtb_ManualSwitch1 = 0.0F;
  } else {
    rtb_ManualSwitch1 = (real32_T)fmod(rtb_ManualSwitch1, 4.294967296E+9);
  }

  mitchell_bluetooth_B.DataTypeConversion3 = rtb_ManualSwitch1 < 0.0F ?
    -(int32_T)(uint32_T)-rtb_ManualSwitch1 : (int32_T)(uint32_T)
    rtb_ManualSwitch1;

  /* End of DataTypeConversion: '<S10>/Data Type Conversion3' */

  /* DataTypeConversion: '<S10>/Data Type Conversion1' */
  rtb_ManualSwitch1 = (real32_T)floor(rtb_Gain1_hj);
  if (rtIsNaNF(rtb_ManualSwitch1) || rtIsInfF(rtb_ManualSwitch1)) {
    rtb_ManualSwitch1 = 0.0F;
  } else {
    rtb_ManualSwitch1 = (real32_T)fmod(rtb_ManualSwitch1, 4.294967296E+9);
  }

  mitchell_bluetooth_B.DataTypeConversion1 = rtb_ManualSwitch1 < 0.0F ?
    -(int32_T)(uint32_T)-rtb_ManualSwitch1 : (int32_T)(uint32_T)
    rtb_ManualSwitch1;

  /* End of DataTypeConversion: '<S10>/Data Type Conversion1' */

  /* DataTypeConversion: '<S10>/Data Type Conversion2' */
  rtb_ManualSwitch1 = (real32_T)floor(rtb_Gain2_g);
  if (rtIsNaNF(rtb_ManualSwitch1) || rtIsInfF(rtb_ManualSwitch1)) {
    rtb_ManualSwitch1 = 0.0F;
  } else {
    rtb_ManualSwitch1 = (real32_T)fmod(rtb_ManualSwitch1, 4.294967296E+9);
  }

  mitchell_bluetooth_B.DataTypeConversion2 = rtb_ManualSwitch1 < 0.0F ?
    -(int32_T)(uint32_T)-rtb_ManualSwitch1 : (int32_T)(uint32_T)
    rtb_ManualSwitch1;

  /* End of DataTypeConversion: '<S10>/Data Type Conversion2' */

  /* DataTypeConversion: '<S10>/Data Type Conversion10' incorporates:
   *  Constant: '<S10>/Latch signal'
   */
  mitchell_bluetooth_B.DataTypeConversion10_l =
    mitchell_bluetooth_P.Latchsignal_Value;

  /* S-Function (any2byte): '<S10>/Byte Pack' incorporates:
   *  Constant: '<S10>/Float ier'
   *  Constant: '<S10>/Mass Identifier'
   *  Constant: '<S10>/Sensor 1 Identifier'
   *  Constant: '<S10>/Sensor 2 Identifier'
   *  Constant: '<S10>/Sensor 3 Identifier'
   */

  /* Pack: <S10>/Byte Pack */
  (void) memcpy(&mitchell_bluetooth_B.BytePack[0],
                &mitchell_bluetooth_P.Sensor1Identifier_Value,
                4);
  (void) memcpy(&mitchell_bluetooth_B.BytePack[4],
                &mitchell_bluetooth_B.DataTypeConversion3,
                4);
  (void) memcpy(&mitchell_bluetooth_B.BytePack[8],
                &mitchell_bluetooth_P.Sensor2Identifier_Value,
                4);
  (void) memcpy(&mitchell_bluetooth_B.BytePack[12],
                &mitchell_bluetooth_B.DataTypeConversion1,
                4);
  (void) memcpy(&mitchell_bluetooth_B.BytePack[16],
                &mitchell_bluetooth_P.Sensor3Identifier_Value,
                4);
  (void) memcpy(&mitchell_bluetooth_B.BytePack[20],
                &mitchell_bluetooth_B.DataTypeConversion2,
                4);
  (void) memcpy(&mitchell_bluetooth_B.BytePack[24],
                &mitchell_bluetooth_P.Floatier_Value,
                4);
  (void) memcpy(&mitchell_bluetooth_B.BytePack[28],
                &mitchell_bluetooth_B.DataTypeConversion9_e,
                4);
  (void) memcpy(&mitchell_bluetooth_B.BytePack[32],
                &mitchell_bluetooth_P.MassIdentifier_Value,
                4);
  (void) memcpy(&mitchell_bluetooth_B.BytePack[36],
                &mitchell_bluetooth_B.DataTypeConversion10_l,
                4);

  /* S-Function (stellaris_lp_sfunc_GPIOSetup): '<S10>/GPIO Setup' */
  GPIOVoidFunc();

  /* S-Function (stellaris_lp_sfunc_XDataInit): '<S10>/XComInit' */
  init_xdatapacket_void();

  /* Update for DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn' */
  mitchell_bluetooth_DW.DiscreteTransferFcn_states = DiscreteTransferFcn_tmp;

  /* Update for DiscreteTransferFcn: '<S20>/Discrete Transfer Fcn' */
  mitchell_bluetooth_DW.DiscreteTransferFcn_states_k =
    mitchell_bluetooth_B.ContollerGain;

  /* Update for DiscreteTransferFcn: '<S18>/Discrete Transfer Fcn' */
  mitchell_bluetooth_DW.DiscreteTransferFcn_states_b = rtb_ContollerGain_c;
}

/* Model step function for TID2 */
void mitchell_bluetooth_step2(void)    /* Sample time: [0.001s, 0.0s] */
{
  int32_T rtb_DataTypeConversion6;
  uint8_T rtb_TmpRTBAtMultiportSwitchInpo;
  int32_T rtb_DataTypeConversion4;
  uint8_T rtb_SFunction_o1;
  real_T rtb_Divide;
  int64m_T tmp;
  int64m_T tmp_0;
  uint32_T tmp_1;
  uint32_T tmp_2;
  int64m_T tmp_3;

  /* S-Function (stellaris_lp_sfunc_XDataPackin): '<S16>/S-Function' incorporates:
   *  Inport: '<S17>/In1'
   */
  rtb_TmpRTBAtMultiportSwitchInpo = xdatapacket_get(1, &rtb_SFunction_o1);

  /* Outputs for Enabled SubSystem: '<S16>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  if (rtb_TmpRTBAtMultiportSwitchInpo > 0) {
    mitchell_bluetooth_B.In1 = rtb_SFunction_o1;
  }

  /* End of S-Function (stellaris_lp_sfunc_XDataPackin): '<S16>/S-Function' */
  /* End of Outputs for SubSystem: '<S16>/Enabled Subsystem' */

  /* S-Function (xpcbytepacking): '<S10>/Unpack' */

  /* Byte Unpacking: <S10>/Unpack */
  (void)memcpy((uint8_T*)&mitchell_bluetooth_B.Unpack, (uint8_T*)
               &mitchell_bluetooth_B.In1 + 0, 1);

  /* DataTypeConversion: '<S10>/Data Type Conversion6' */
  rtb_DataTypeConversion6 = mitchell_bluetooth_B.Unpack;

  /* RateTransition: '<S10>/TmpRTBAtMultiport SwitchInport2' incorporates:
   *  Constant: '<S10>/Red LED Off'
   */
  rtb_TmpRTBAtMultiportSwitchInpo = mitchell_bluetooth_P.RedLEDOff_Value;

  /* RateTransition: '<S10>/TmpRTBAtMultiport SwitchInport6' incorporates:
   *  Constant: '<S10>/Red LED Off'
   */
  rtb_SFunction_o1 = mitchell_bluetooth_P.RedLEDOff_Value;

  /* MultiPortSwitch: '<S10>/Multiport Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Red LED On'
   *  Constant: '<S10>/Red LED On1'
   *  Constant: '<S10>/Red LED On2'
   *  DataTypeConversion: '<S10>/Data Type Conversion6'
   *  Sum: '<S10>/Subtract'
   */
  switch (mitchell_bluetooth_B.Unpack - mitchell_bluetooth_P.Constant_Value_g) {
   case 0:
    rtb_SFunction_o1 = rtb_TmpRTBAtMultiportSwitchInpo;
    break;

   case 1:
    rtb_SFunction_o1 = mitchell_bluetooth_P.RedLEDOn_Value;
    break;

   case 2:
    rtb_SFunction_o1 = mitchell_bluetooth_P.RedLEDOn1_Value;
    break;

   case 3:
    rtb_SFunction_o1 = mitchell_bluetooth_P.RedLEDOn2_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S10>/Multiport Switch' */

  /* DataTypeConversion: '<S10>/Data Type Conversion4' */
  rtb_DataTypeConversion4 = rtb_SFunction_o1;

  /* MATLAB Function: '<S10>/MATLAB Function' */
  if (rtb_DataTypeConversion4 == 0) {
    switch (mitchell_bluetooth_DW.val) {
     case 1:
      mitchell_bluetooth_DW.output++;
      break;

     case 2:
      mitchell_bluetooth_DW.output--;
      break;

     case 3:
      mitchell_bluetooth_DW.latched = (mitchell_bluetooth_DW.latched == 0);
      break;
    }

    mitchell_bluetooth_DW.val = 0;
  } else {
    mitchell_bluetooth_DW.val = rtb_DataTypeConversion4;
  }

  mitchell_bluetooth_B.latch = mitchell_bluetooth_DW.latched;

  /* ManualSwitch: '<Root>/Manual Switch4' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain7'
   *  MATLAB Function: '<S10>/MATLAB Function'
   */
  if (mitchell_bluetooth_P.ManualSwitch4_CurrentSetting == 1) {
    mitchell_bluetooth_B.ManualSwitch4 = mitchell_bluetooth_P.Gain7_Gain *
      mitchell_bluetooth_DW.output;
  } else {
    mitchell_bluetooth_B.ManualSwitch4 = mitchell_bluetooth_P.Constant_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch4' */

  /* ManualSwitch: '<Root>/Manual Switch3' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Sqrt: '<S14>/Sqrt'
   */
  if (mitchell_bluetooth_P.ManualSwitch3_CurrentSetting == 1) {
    /* Polyval: '<Root>/f^(h)' */
    rtb_Divide = mitchell_bluetooth_P.fh_Coefs[0];
    for (rtb_DataTypeConversion4 = 0; rtb_DataTypeConversion4 < 6;
         rtb_DataTypeConversion4++) {
      rtb_Divide = rtb_Divide * mitchell_bluetooth_B.ManualSwitch4 +
        mitchell_bluetooth_P.fh_Coefs[rtb_DataTypeConversion4 + 1];
    }

    /* End of Polyval: '<Root>/f^(h)' */

    /* Product: '<S14>/Divide' incorporates:
     *  Constant: '<S14>/1//3 Total Mass'
     *  Constant: '<S14>/Gravity Constant'
     *  Product: '<S14>/Product'
     */
    rtb_Divide = mitchell_bluetooth_P.u3TotalMass_Value *
      mitchell_bluetooth_P.GravityConstant_Value / rtb_Divide;
    mitchell_bluetooth_B.ManualSwitch3 = sqrt(rtb_Divide);
  } else {
    mitchell_bluetooth_B.ManualSwitch3 = mitchell_bluetooth_P.Constant1_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch3' */

  /* Gain: '<Root>/Gain4' */
  tmp_1 = (uint32_T)mitchell_bluetooth_P.Gain4_Gain;
  tmp_2 = (uint32_T)mitchell_bluetooth_B.latch;
  sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_0.chunks[0U], 2);

  /* DataTypeConversion: '<Root>/Data Type Conversion6' */
  sMultiWordShr(&tmp_0.chunks[0U], 2, 30U, &tmp.chunks[0U], 2);
  mitchell_bluetooth_B.DataTypeConversion6 = MultiWord2sLong(&tmp.chunks[0U]);

  /* DataTypeConversion: '<Root>/Data Type Conversion8' incorporates:
   *  Gain: '<Root>/Gain5'
   *  MATLAB Function: '<S10>/MATLAB Function'
   */
  rtb_Divide = floor(mitchell_bluetooth_P.Gain5_Gain *
                     mitchell_bluetooth_DW.output);
  if (rtIsNaN(rtb_Divide) || rtIsInf(rtb_Divide)) {
    rtb_Divide = 0.0;
  } else {
    rtb_Divide = fmod(rtb_Divide, 4.294967296E+9);
  }

  mitchell_bluetooth_B.DataTypeConversion8 = rtb_Divide < 0.0 ? -(int32_T)
    (uint32_T)-rtb_Divide : (int32_T)(uint32_T)rtb_Divide;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion8' */

  /* Gain: '<Root>/Gain6' */
  tmp_1 = (uint32_T)mitchell_bluetooth_P.Gain6_Gain;
  tmp_2 = (uint32_T)rtb_DataTypeConversion6;
  sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_3.chunks[0U], 2);

  /* DataTypeConversion: '<Root>/Data Type Conversion9' */
  sMultiWordShr(&tmp_3.chunks[0U], 2, 30U, &tmp_0.chunks[0U], 2);
  mitchell_bluetooth_B.DataTypeConversion9 = MultiWord2sLong(&tmp_0.chunks[0U]);

  /* RateTransition: '<S10>/TmpRTBAtMultiport Switch1Inport3' incorporates:
   *  Constant: '<S10>/Latch signal'
   */
  rtb_TmpRTBAtMultiportSwitchInpo = mitchell_bluetooth_P.Latchsignal_Value;

  /* MultiPortSwitch: '<S10>/Multiport Switch1' incorporates:
   *  MATLAB Function: '<S10>/MATLAB Function'
   */
  if (mitchell_bluetooth_B.latch == 0) {
    rtb_Divide = mitchell_bluetooth_DW.output;
  } else {
    rtb_Divide = rtb_TmpRTBAtMultiportSwitchInpo;
  }

  /* End of MultiPortSwitch: '<S10>/Multiport Switch1' */

  /* DataTypeConversion: '<S10>/Data Type Conversion9' */
  rtb_Divide = floor(rtb_Divide);
  if (rtIsNaN(rtb_Divide) || rtIsInf(rtb_Divide)) {
    rtb_Divide = 0.0;
  } else {
    rtb_Divide = fmod(rtb_Divide, 4.294967296E+9);
  }

  mitchell_bluetooth_B.DataTypeConversion9_e = rtb_Divide < 0.0 ? -(int32_T)
    (uint32_T)-rtb_Divide : (int32_T)(uint32_T)rtb_Divide;

  /* End of DataTypeConversion: '<S10>/Data Type Conversion9' */
}

/* Model step function for TID3 */
void mitchell_bluetooth_step3(void)    /* Sample time: [0.1s, 0.0s] */
{
  /* S-Function (stellaris_lp_sfunc_DebugPrint): '<Root>/Debug Print' */
  DebugPrint(mitchell_bluetooth_P.DebugPrint_p1,
             mitchell_bluetooth_B.DataTypeConversion6,
             mitchell_bluetooth_B.DataTypeConversion8,
             mitchell_bluetooth_B.DataTypeConversion9,
             mitchell_bluetooth_B.DataTypeConversion10);

  /* S-Function (stellaris_lp_sfunc_XDataPackout): '<S10>/XComSend' */
  xdatapacket_put(40, mitchell_bluetooth_B.BytePack);
}

/* Model initialize function */
void mitchell_bluetooth_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)mitchell_bluetooth_M, 0,
                sizeof(RT_MODEL_mitchell_bluetooth_T));

  /* block I/O */
  (void) memset(((void *) &mitchell_bluetooth_B), 0,
                sizeof(B_mitchell_bluetooth_T));

  /* states (dwork) */
  (void) memset((void *)&mitchell_bluetooth_DW, 0,
                sizeof(DW_mitchell_bluetooth_T));

  /* external outputs */
  (void) memset((void *)&mitchell_bluetooth_Y, 0,
                sizeof(ExtY_mitchell_bluetooth_T));

  /* Start for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S4>/S-Function2' */
  PWMInit(mitchell_bluetooth_P.SFunction2_p1, mitchell_bluetooth_P.SFunction2_p2,
          mitchell_bluetooth_P.SFunction2_p3);

  /* Start for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S5>/S-Function2' */
  PWMInit(mitchell_bluetooth_P.SFunction2_p1_c,
          mitchell_bluetooth_P.SFunction2_p2_l,
          mitchell_bluetooth_P.SFunction2_p3_m);

  /* Start for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S6>/S-Function2' */
  PWMInit(mitchell_bluetooth_P.SFunction2_p1_d,
          mitchell_bluetooth_P.SFunction2_p2_e,
          mitchell_bluetooth_P.SFunction2_p3_mx);

  /* Start for S-Function (stellaris_lp_sfunc_GPIOSetup): '<S10>/GPIO Setup' */
  GPIOSetup(mitchell_bluetooth_P.GPIOSetup_p1, mitchell_bluetooth_P.GPIOSetup_p2,
            mitchell_bluetooth_P.GPIOSetup_p3, mitchell_bluetooth_P.GPIOSetup_p4);

  /* Start for S-Function (stellaris_lp_sfunc_XDataInit): '<S10>/XComInit' */
  init_xdatapacket(mitchell_bluetooth_P.XComInit_p1);

  /* InitializeConditions for DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn' */
  mitchell_bluetooth_DW.DiscreteTransferFcn_states =
    mitchell_bluetooth_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for DiscreteTransferFcn: '<S20>/Discrete Transfer Fcn' */
  mitchell_bluetooth_DW.DiscreteTransferFcn_states_k =
    mitchell_bluetooth_P.DiscreteTransferFcn_InitialSt_p;

  /* InitializeConditions for DiscreteTransferFcn: '<S18>/Discrete Transfer Fcn' */
  mitchell_bluetooth_DW.DiscreteTransferFcn_states_b =
    mitchell_bluetooth_P.DiscreteTransferFcn_InitialSt_b;

  /* InitializeConditions for RateLimiter: '<Root>/Rate Limiter2' */
  mitchell_bluetooth_DW.PrevY = mitchell_bluetooth_P.RateLimiter2_IC;

  /* InitializeConditions for RateLimiter: '<Root>/Rate Limiter' */
  mitchell_bluetooth_DW.PrevY_c = mitchell_bluetooth_P.RateLimiter_IC;

  /* InitializeConditions for RateLimiter: '<Root>/Rate Limiter1' */
  mitchell_bluetooth_DW.PrevY_n = mitchell_bluetooth_P.RateLimiter1_IC;

  /* SystemInitialize for Enabled SubSystem: '<S16>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S17>/Out1' */
  mitchell_bluetooth_B.In1 = mitchell_bluetooth_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S16>/Enabled Subsystem' */

  /* SystemInitialize for MATLAB Function: '<S10>/MATLAB Function' */
  mitchell_bluetooth_DW.val = 0;
  mitchell_bluetooth_DW.output = 9.0;
  mitchell_bluetooth_DW.latched = 1;
}

/* Model terminate function */
void mitchell_bluetooth_terminate(void)
{
  /* Terminate for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S4>/S-Function2' */
  PWMStop(mitchell_bluetooth_P.SFunction2_p1);

  /* Terminate for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S5>/S-Function2' */
  PWMStop(mitchell_bluetooth_P.SFunction2_p1_c);

  /* Terminate for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S6>/S-Function2' */
  PWMStop(mitchell_bluetooth_P.SFunction2_p1_d);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
