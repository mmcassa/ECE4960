/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Feedback_3.c
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

/* Block states (auto storage) */
DW_Feedback_3_T Feedback_3_DW;

/* Real-time model */
RT_MODEL_Feedback_3_T Feedback_3_M_;
RT_MODEL_Feedback_3_T *const Feedback_3_M = &Feedback_3_M_;
static void rate_monotonic_scheduler(void);

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
  if ((Feedback_3_M->Timing.TaskCounters.TID[1]) > 999) {/* Sample time: [0.1s, 0.0s] */
    Feedback_3_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Feedback_3_M->Timing.TaskCounters.TID[2])++;
  if ((Feedback_3_M->Timing.TaskCounters.TID[2]) > 1999) {/* Sample time: [0.2s, 0.0s] */
    Feedback_3_M->Timing.TaskCounters.TID[2] = 0;
  }
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

/*
 * Output and update for atomic system:
 *    '<S5>/MATLAB Function3'
 *    '<S6>/MATLAB Function3'
 *    '<S7>/MATLAB Function3'
 */
void Feedback_3_MATLABFunction3(real_T rtu_ir, int32_T *rty_dc)
{
  real32_T tmp;
  tmp = rt_roundf_snf(((real32_T)rtu_ir - 220.0F) / 3640.0F * 100.0F);
  if (tmp < 2.14748365E+9F) {
    if (tmp >= -2.14748365E+9F) {
      *rty_dc = (int32_T)tmp;
    } else {
      *rty_dc = MIN_int32_T;
    }
  } else {
    *rty_dc = MAX_int32_T;
  }
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

/* Model step function for TID0 */
void Feedback_3_step0(void)            /* Sample time: [0.0001s, 0.0s] */
{
  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void Feedback_3_step1(void)            /* Sample time: [0.1s, 0.0s] */
{
  int32_T tmp;
  int_T idx;
  uint32_T rtb_ADRaw1;
  real_T rtb_Gain;
  real_T rtb_Gain_b;
  int32_T rtb_dc_d;
  int32_T rtb_dc;
  int32_T rtb_dc_c;
  real_T rtb_Subtract;

  /* S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw3' */
  idx = ADCRead(Feedback_3_P.ADRaw3_p1);

  /* MATLAB Function: '<S5>/MATLAB Function3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw3'
   */
  Feedback_3_MATLABFunction3((real_T)(uint32_T)idx, &rtb_dc_d);

  /* S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw2' */
  tmp = ADCRead(Feedback_3_P.ADRaw2_p1);

  /* MATLAB Function: '<S7>/MATLAB Function3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   *  S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw2'
   */
  Feedback_3_MATLABFunction3((real_T)(uint32_T)tmp, &rtb_dc);

  /* S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw1' */
  rtb_dc_c = ADCRead(Feedback_3_P.ADRaw1_p1);
  rtb_ADRaw1 = (uint32_T)rtb_dc_c;

  /* MATLAB Function: '<S6>/MATLAB Function3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  Feedback_3_MATLABFunction3((real_T)rtb_ADRaw1, &rtb_dc_c);

  /* S-Function (stellaris_lp_sfunc_DebugPrint): '<Root>/Debug Print' */
  DebugPrint(Feedback_3_P.DebugPrint_p1, rtb_dc_d, rtb_dc, rtb_dc_c, 0);

  /* Sum: '<S5>/Subtract' incorporates:
   *  Constant: '<S5>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw3'
   */
  rtb_Subtract = (real_T)(uint32_T)idx - Feedback_3_P.Constant_Value_f;

  /* DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S5>/Constant1'
   *  Gain: '<S5>/Gain'
   *  Polyval: '<S5>/Polynomial'
   *  Product: '<S5>/Divide'
   *  Sum: '<S5>/Sum'
   *  Sum: '<S5>/Sum1'
   */
  rtb_Subtract = ((Feedback_3_P.Constant2_Value -
                   (((Feedback_3_P.Polynomial_Coefs[0] * rtb_Subtract +
                      Feedback_3_P.Polynomial_Coefs[1]) * rtb_Subtract +
                     Feedback_3_P.Polynomial_Coefs[2]) /
                    Feedback_3_P.Constant1_Value_c - Feedback_3_P.Constant_Value))
                  * Feedback_3_P.Gain_Gain -
                  Feedback_3_P.DiscreteTransferFcn_DenCoef[1] *
                  Feedback_3_DW.DiscreteTransferFcn_states) /
    Feedback_3_P.DiscreteTransferFcn_DenCoef[0];

  /* S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S1>/S-Function2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn'
   *  Sum: '<S5>/Sum2'
   */
  PWMUpdate_f(Feedback_3_P.SFunction2_p1, (real32_T)
              (Feedback_3_P.Constant1_Value +
               (Feedback_3_P.DiscreteTransferFcn_NumCoef[0] * rtb_Subtract +
                Feedback_3_P.DiscreteTransferFcn_NumCoef[1] *
                Feedback_3_DW.DiscreteTransferFcn_states)));

  /* Sum: '<S6>/Subtract' incorporates:
   *  Constant: '<S6>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  rtb_Gain = (real_T)rtb_ADRaw1 - Feedback_3_P.Constant_Value_o;

  /* DiscreteTransferFcn: '<S6>/Discrete Transfer Fcn' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S6>/Constant1'
   *  Gain: '<S6>/Gain'
   *  Polyval: '<S6>/Polynomial'
   *  Product: '<S6>/Divide'
   *  Sum: '<S6>/Sum'
   *  Sum: '<S6>/Sum1'
   */
  rtb_Gain = ((Feedback_3_P.Constant2_Value -
               (((Feedback_3_P.Polynomial_Coefs_c[0] * rtb_Gain +
                  Feedback_3_P.Polynomial_Coefs_c[1]) * rtb_Gain +
                 Feedback_3_P.Polynomial_Coefs_c[2]) /
                Feedback_3_P.Constant1_Value_a - Feedback_3_P.Constant_Value)) *
              Feedback_3_P.Gain_Gain_l -
              Feedback_3_P.DiscreteTransferFcn_DenCoef_n[1] *
              Feedback_3_DW.DiscreteTransferFcn_states_c) /
    Feedback_3_P.DiscreteTransferFcn_DenCoef_n[0];

  /* S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S2>/S-Function2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  DiscreteTransferFcn: '<S6>/Discrete Transfer Fcn'
   *  Sum: '<S6>/Sum2'
   */
  PWMUpdate_f(Feedback_3_P.SFunction2_p1_c, (real32_T)
              (Feedback_3_P.Constant1_Value +
               (Feedback_3_P.DiscreteTransferFcn_NumCoef_l[0] * rtb_Gain +
                Feedback_3_P.DiscreteTransferFcn_NumCoef_l[1] *
                Feedback_3_DW.DiscreteTransferFcn_states_c)));

  /* Sum: '<S7>/Subtract' incorporates:
   *  Constant: '<S7>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   *  S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw2'
   */
  rtb_Gain_b = (real_T)(uint32_T)tmp - Feedback_3_P.Constant_Value_b;

  /* DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S7>/Constant1'
   *  Gain: '<S7>/Gain'
   *  Polyval: '<S7>/Polynomial'
   *  Product: '<S7>/Divide'
   *  Sum: '<S7>/Sum'
   *  Sum: '<S7>/Sum1'
   */
  rtb_Gain_b = ((Feedback_3_P.Constant2_Value -
                 (((Feedback_3_P.Polynomial_Coefs_cy[0] * rtb_Gain_b +
                    Feedback_3_P.Polynomial_Coefs_cy[1]) * rtb_Gain_b +
                   Feedback_3_P.Polynomial_Coefs_cy[2]) /
                  Feedback_3_P.Constant1_Value_l - Feedback_3_P.Constant_Value))
                * Feedback_3_P.Gain_Gain_c -
                Feedback_3_P.DiscreteTransferFcn_DenCoef_f[1] *
                Feedback_3_DW.DiscreteTransferFcn_states_e) /
    Feedback_3_P.DiscreteTransferFcn_DenCoef_f[0];

  /* S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S3>/S-Function2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   *  DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn'
   *  Sum: '<S7>/Sum2'
   */
  PWMUpdate_f(Feedback_3_P.SFunction2_p1_d, (real32_T)
              (Feedback_3_P.Constant1_Value +
               (Feedback_3_P.DiscreteTransferFcn_NumCoef_g[0] * rtb_Gain_b +
                Feedback_3_P.DiscreteTransferFcn_NumCoef_g[1] *
                Feedback_3_DW.DiscreteTransferFcn_states_e)));

  /* S-Function (stellaris_lp_sfunc_GPIOSetup): '<S4>/GPIO Setup' */
  GPIOVoidFunc();

  /* Update for DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn' */
  Feedback_3_DW.DiscreteTransferFcn_states = rtb_Subtract;

  /* Update for DiscreteTransferFcn: '<S6>/Discrete Transfer Fcn' */
  Feedback_3_DW.DiscreteTransferFcn_states_c = rtb_Gain;

  /* Update for DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn' */
  Feedback_3_DW.DiscreteTransferFcn_states_e = rtb_Gain_b;
}

/* Model step function for TID2 */
void Feedback_3_step2(void)            /* Sample time: [0.2s, 0.0s] */
{
  real_T tmp;

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  UniformRandomNumber: '<S4>/Uniform Random Number'
   */
  tmp = floor(Feedback_3_DW.UniformRandomNumber_NextOutput);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* S-Function (stellaris_lp_sfunc_GPIOWrite): '<S4>/GPIO Write' incorporates:
   *  Constant: '<S4>/BLUE LED'
   *  Constant: '<S4>/GREEN LED'
   *  Constant: '<S4>/RED LED'
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   *  S-Function (sfix_bitop): '<S4>/Bitwise Operator'
   */
  GPIOWrite(Feedback_3_P.GPIOWrite_p1, (uint8_T)(Feedback_3_P.REDLED_Value |
             Feedback_3_P.BLUELED_Value | Feedback_3_P.GREENLED_Value), (uint8_T)
            (tmp < 0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)-tmp : (int32_T)
             (uint8_T)tmp));

  /* Update for UniformRandomNumber: '<S4>/Uniform Random Number' */
  Feedback_3_DW.UniformRandomNumber_NextOutput =
    (Feedback_3_P.UniformRandomNumber_Maximum -
     Feedback_3_P.UniformRandomNumber_Minimum) * rt_urand_Upu32_Yd_f_pw_snf
    (&Feedback_3_DW.RandSeed) + Feedback_3_P.UniformRandomNumber_Minimum;
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

  /* states (dwork) */
  (void) memset((void *)&Feedback_3_DW, 0,
                sizeof(DW_Feedback_3_T));

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* Start for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S1>/S-Function2' */
    PWMInit(Feedback_3_P.SFunction2_p1, Feedback_3_P.SFunction2_p2,
            Feedback_3_P.SFunction2_p3);

    /* Start for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S2>/S-Function2' */
    PWMInit(Feedback_3_P.SFunction2_p1_c, Feedback_3_P.SFunction2_p2_l,
            Feedback_3_P.SFunction2_p3_m);

    /* Start for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S3>/S-Function2' */
    PWMInit(Feedback_3_P.SFunction2_p1_d, Feedback_3_P.SFunction2_p2_e,
            Feedback_3_P.SFunction2_p3_mx);

    /* Start for S-Function (stellaris_lp_sfunc_GPIOSetup): '<S4>/GPIO Setup' */
    GPIOSetup(Feedback_3_P.GPIOSetup_p1, Feedback_3_P.GPIOSetup_p2,
              Feedback_3_P.GPIOSetup_p3, Feedback_3_P.GPIOSetup_p4);

    /* InitializeConditions for DiscreteTransferFcn: '<S5>/Discrete Transfer Fcn' */
    Feedback_3_DW.DiscreteTransferFcn_states =
      Feedback_3_P.DiscreteTransferFcn_InitialStat;

    /* InitializeConditions for DiscreteTransferFcn: '<S6>/Discrete Transfer Fcn' */
    Feedback_3_DW.DiscreteTransferFcn_states_c =
      Feedback_3_P.DiscreteTransferFcn_InitialSt_l;

    /* InitializeConditions for DiscreteTransferFcn: '<S7>/Discrete Transfer Fcn' */
    Feedback_3_DW.DiscreteTransferFcn_states_e =
      Feedback_3_P.DiscreteTransferFcn_InitialSt_m;

    /* InitializeConditions for UniformRandomNumber: '<S4>/Uniform Random Number' */
    tmp = floor(Feedback_3_P.UniformRandomNumber_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    Feedback_3_DW.RandSeed = tseed;
    Feedback_3_DW.UniformRandomNumber_NextOutput =
      (Feedback_3_P.UniformRandomNumber_Maximum -
       Feedback_3_P.UniformRandomNumber_Minimum) * rt_urand_Upu32_Yd_f_pw_snf
      (&Feedback_3_DW.RandSeed) + Feedback_3_P.UniformRandomNumber_Minimum;

    /* End of InitializeConditions for UniformRandomNumber: '<S4>/Uniform Random Number' */
  }
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
