/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Feedback_2.c
 *
 * Code generated for Simulink model 'Feedback_2'.
 *
 * Model version                  : 1.35
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Oct 15 18:26:23 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Feedback_2.h"
#include "Feedback_2_private.h"

/* Block states (auto storage) */
DW_Feedback_2_T Feedback_2_DW;

/* Real-time model */
RT_MODEL_Feedback_2_T Feedback_2_M_;
RT_MODEL_Feedback_2_T *const Feedback_2_M = &Feedback_2_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Feedback_2_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Feedback_2_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(Feedback_2_M, 2));
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
  (Feedback_2_M->Timing.TaskCounters.TID[1])++;
  if ((Feedback_2_M->Timing.TaskCounters.TID[1]) > 999) {/* Sample time: [0.1s, 0.0s] */
    Feedback_2_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Feedback_2_M->Timing.TaskCounters.TID[2])++;
  if ((Feedback_2_M->Timing.TaskCounters.TID[2]) > 1999) {/* Sample time: [0.2s, 0.0s] */
    Feedback_2_M->Timing.TaskCounters.TID[2] = 0;
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
 *    '<Root>/MATLAB Function3'
 *    '<Root>/MATLAB Function4'
 */
void Feedback_2_MATLABFunction3(real_T rtu_ir, int32_T *rty_dc)
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

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
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
void Feedback_2_step0(void)            /* Sample time: [0.0001s, 0.0s] */
{
  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void Feedback_2_step1(void)            /* Sample time: [0.1s, 0.0s] */
{
  int32_T rtb_DataTypeConversion1_0;
  real_T avg;
  int32_T rtb_min;
  int32_T rtb_max;
  int32_T tmp;

  /* S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw1' */
  rtb_DataTypeConversion1_0 = ADCRead(Feedback_2_P.ADRaw1_p1);

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw1'
   */
  if (!Feedback_2_DW.ir_arr_not_empty) {
    memset(&Feedback_2_DW.ir_arr[0], 0, 400U * sizeof(real_T));
    Feedback_2_DW.ir_arr_not_empty = true;
    Feedback_2_DW.i = 1.0;
    for (rtb_min = 0; rtb_min < 20; rtb_min++) {
      Feedback_2_DW.i = 1.0 + (real_T)rtb_min;
      Feedback_2_DW.ir_arr[(int32_T)Feedback_2_DW.i - 1] =
        rtb_DataTypeConversion1_0;
    }

    Feedback_2_DW.i = 1.0;
  }

  Feedback_2_DW.ir_arr[(int32_T)Feedback_2_DW.i - 1] = rtb_DataTypeConversion1_0;
  avg = Feedback_2_DW.ir_arr[0];
  for (rtb_min = 0; rtb_min < 19; rtb_min++) {
    avg += Feedback_2_DW.ir_arr[rtb_min + 1];
  }

  avg /= 20.0;
  if (Feedback_2_DW.i == 20.0) {
    Feedback_2_DW.i = 0.0;
  }

  Feedback_2_DW.i++;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw1'
   */
  if (!Feedback_2_DW.p_min_not_empty) {
    Feedback_2_DW.p_min = rtb_DataTypeConversion1_0;
    Feedback_2_DW.p_min_not_empty = true;
    Feedback_2_DW.p_max = rtb_DataTypeConversion1_0;
  }

  if (rtb_DataTypeConversion1_0 < Feedback_2_DW.p_min) {
    rtb_min = rtb_DataTypeConversion1_0;
    Feedback_2_DW.p_min = rtb_DataTypeConversion1_0;
  } else {
    rtb_min = Feedback_2_DW.p_min;
  }

  if (rtb_DataTypeConversion1_0 > Feedback_2_DW.p_max) {
    rtb_max = rtb_DataTypeConversion1_0;
    Feedback_2_DW.p_max = rtb_DataTypeConversion1_0;
  } else {
    rtb_max = Feedback_2_DW.p_max;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* MATLAB Function: '<Root>/MATLAB Function2' */
  avg = rt_roundd_snf((avg - 230.0) / 5.0);
  if (avg < 2.147483648E+9) {
    if (avg >= -2.147483648E+9) {
      tmp = (int32_T)avg;
    } else {
      tmp = MIN_int32_T;
    }
  } else {
    tmp = MAX_int32_T;
  }

  /* S-Function (stellaris_lp_sfunc_DebugPrint): '<Root>/Debug Print' incorporates:
   *  S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw1'
   */
  DebugPrint(Feedback_2_P.DebugPrint_p1, rtb_DataTypeConversion1_0, tmp, rtb_min,
             rtb_max);

  /* S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S7>/S-Function2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  MATLAB Function: '<Root>/MATLAB Function1'
   *  S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw1'
   */
  PWMUpdate_f(Feedback_2_P.SFunction2_p1, (real32_T)(int32_T)rt_roundf_snf
              (((real32_T)rtb_DataTypeConversion1_0 - 220.0F) / 3640.0F * 100.0F));

  /* S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw2' */
  rtb_DataTypeConversion1_0 = ADCRead(Feedback_2_P.ADRaw2_p1);

  /* MATLAB Function: '<Root>/MATLAB Function4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   *  S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw2'
   */
  Feedback_2_MATLABFunction3((real_T)(uint32_T)rtb_DataTypeConversion1_0,
    &rtb_min);

  /* S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S8>/S-Function2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   */
  PWMUpdate_f(Feedback_2_P.SFunction2_p1_d, (real32_T)rtb_min);

  /* S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw3' */
  rtb_DataTypeConversion1_0 = ADCRead(Feedback_2_P.ADRaw3_p1);

  /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   *  S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw3'
   */
  Feedback_2_MATLABFunction3((real_T)(uint32_T)rtb_DataTypeConversion1_0,
    &rtb_min);

  /* S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S6>/S-Function2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  PWMUpdate_f(Feedback_2_P.SFunction2_p1_l, (real32_T)rtb_min);

  /* S-Function (stellaris_lp_sfunc_GPIOSetup): '<S9>/GPIO Setup' */
  GPIOVoidFunc();
}

/* Model step function for TID2 */
void Feedback_2_step2(void)            /* Sample time: [0.2s, 0.0s] */
{
  real_T tmp;

  /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
   *  UniformRandomNumber: '<S9>/Uniform Random Number'
   */
  tmp = floor(Feedback_2_DW.UniformRandomNumber_NextOutput);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* S-Function (stellaris_lp_sfunc_GPIOWrite): '<S9>/GPIO Write' incorporates:
   *  Constant: '<S9>/BLUE LED'
   *  Constant: '<S9>/GREEN LED'
   *  Constant: '<S9>/RED LED'
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   *  S-Function (sfix_bitop): '<S9>/Bitwise Operator'
   */
  GPIOWrite(Feedback_2_P.GPIOWrite_p1, (uint8_T)(Feedback_2_P.REDLED_Value |
             Feedback_2_P.BLUELED_Value | Feedback_2_P.GREENLED_Value), (uint8_T)
            (tmp < 0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)-tmp : (int32_T)
             (uint8_T)tmp));

  /* Update for UniformRandomNumber: '<S9>/Uniform Random Number' */
  Feedback_2_DW.UniformRandomNumber_NextOutput =
    (Feedback_2_P.UniformRandomNumber_Maximum -
     Feedback_2_P.UniformRandomNumber_Minimum) * rt_urand_Upu32_Yd_f_pw_snf
    (&Feedback_2_DW.RandSeed) + Feedback_2_P.UniformRandomNumber_Minimum;
}

/* Model initialize function */
void Feedback_2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Feedback_2_M, 0,
                sizeof(RT_MODEL_Feedback_2_T));

  /* states (dwork) */
  (void) memset((void *)&Feedback_2_DW, 0,
                sizeof(DW_Feedback_2_T));

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* Start for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S7>/S-Function2' */
    PWMInit(Feedback_2_P.SFunction2_p1, Feedback_2_P.SFunction2_p2,
            Feedback_2_P.SFunction2_p3);

    /* Start for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S8>/S-Function2' */
    PWMInit(Feedback_2_P.SFunction2_p1_d, Feedback_2_P.SFunction2_p2_e,
            Feedback_2_P.SFunction2_p3_m);

    /* Start for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S6>/S-Function2' */
    PWMInit(Feedback_2_P.SFunction2_p1_l, Feedback_2_P.SFunction2_p2_h,
            Feedback_2_P.SFunction2_p3_o);

    /* Start for S-Function (stellaris_lp_sfunc_GPIOSetup): '<S9>/GPIO Setup' */
    GPIOSetup(Feedback_2_P.GPIOSetup_p1, Feedback_2_P.GPIOSetup_p2,
              Feedback_2_P.GPIOSetup_p3, Feedback_2_P.GPIOSetup_p4);

    /* InitializeConditions for UniformRandomNumber: '<S9>/Uniform Random Number' */
    tmp = floor(Feedback_2_P.UniformRandomNumber_Seed);
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

    Feedback_2_DW.RandSeed = tseed;
    Feedback_2_DW.UniformRandomNumber_NextOutput =
      (Feedback_2_P.UniformRandomNumber_Maximum -
       Feedback_2_P.UniformRandomNumber_Minimum) * rt_urand_Upu32_Yd_f_pw_snf
      (&Feedback_2_DW.RandSeed) + Feedback_2_P.UniformRandomNumber_Minimum;

    /* End of InitializeConditions for UniformRandomNumber: '<S9>/Uniform Random Number' */

    /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function2' */
    Feedback_2_DW.ir_arr_not_empty = false;

    /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
    Feedback_2_DW.p_min_not_empty = false;
  }
}

/* Model terminate function */
void Feedback_2_terminate(void)
{
  /* Terminate for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S7>/S-Function2' */
  PWMStop(Feedback_2_P.SFunction2_p1);

  /* Terminate for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S8>/S-Function2' */
  PWMStop(Feedback_2_P.SFunction2_p1_d);

  /* Terminate for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S6>/S-Function2' */
  PWMStop(Feedback_2_P.SFunction2_p1_l);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
