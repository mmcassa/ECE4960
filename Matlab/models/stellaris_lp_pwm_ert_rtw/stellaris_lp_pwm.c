/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stellaris_lp_pwm.c
 *
 * Code generated for Simulink model 'stellaris_lp_pwm'.
 *
 * Model version                  : 1.75
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Mon Sep 30 17:25:50 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "stellaris_lp_pwm.h"
#include "stellaris_lp_pwm_private.h"

/* Block states (auto storage) */
D_Work_stellaris_lp_pwm stellaris_lp_pwm_DWork;

/* Real-time model */
RT_MODEL_stellaris_lp_pwm stellaris_lp_pwm_M_;
RT_MODEL_stellaris_lp_pwm *const stellaris_lp_pwm_M = &stellaris_lp_pwm_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (stellaris_lp_pwm_M->Timing.TaskCounters.TID[1])++;
  if ((stellaris_lp_pwm_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.2s, 0.0s] */
    stellaris_lp_pwm_M->Timing.TaskCounters.TID[1] = 0;
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

/* Model step function */
void stellaris_lp_pwm_step(void)
{
  real_T lastSin_tmp;

  /* S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S1>/S-Function2' incorporates:
   *  Constant: '<Root>/Constant'
   */
  PWMUpdate_f(stellaris_lp_pwm_P.SFunction2_p1,
              stellaris_lp_pwm_P.Constant_Value);

  /* Sin: '<Root>/Sine Wave' */
  if (stellaris_lp_pwm_DWork.systemEnable != 0) {
    lastSin_tmp = stellaris_lp_pwm_P.SineWave_Freq *
      ((stellaris_lp_pwm_M->Timing.clockTick0) * 0.002);
    stellaris_lp_pwm_DWork.lastSin = sin(lastSin_tmp);
    stellaris_lp_pwm_DWork.lastCos = cos(lastSin_tmp);
    stellaris_lp_pwm_DWork.systemEnable = 0;
  }

  /* S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S2>/S-Function2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Sin: '<Root>/Sine Wave'
   */
  PWMUpdate_f(stellaris_lp_pwm_P.SFunction2_p1_a, (real32_T)
              (stellaris_lp_pwm_P.SineWave_Amp *
               ((stellaris_lp_pwm_DWork.lastSin *
                 stellaris_lp_pwm_P.SineWave_PCos +
                 stellaris_lp_pwm_DWork.lastCos *
                 stellaris_lp_pwm_P.SineWave_PSin) *
                stellaris_lp_pwm_P.SineWave_HCos +
                (stellaris_lp_pwm_DWork.lastCos *
                 stellaris_lp_pwm_P.SineWave_PCos -
                 stellaris_lp_pwm_DWork.lastSin *
                 stellaris_lp_pwm_P.SineWave_PSin) *
                stellaris_lp_pwm_P.SineWave_Hsin) +
               stellaris_lp_pwm_P.SineWave_Bias));
  if (stellaris_lp_pwm_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
     *  UniformRandomNumber: '<S3>/Uniform Random Number'
     */
    lastSin_tmp = floor(stellaris_lp_pwm_DWork.UniformRandomNumber_NextOutput);
    if (rtIsNaN(lastSin_tmp) || rtIsInf(lastSin_tmp)) {
      lastSin_tmp = 0.0;
    } else {
      lastSin_tmp = fmod(lastSin_tmp, 256.0);
    }

    /* S-Function (stellaris_lp_sfunc_GPIOWrite): '<S3>/GPIO Write' incorporates:
     *  Constant: '<S3>/BLUE LED'
     *  Constant: '<S3>/GREEN LED'
     *  Constant: '<S3>/RED LED'
     *  DataTypeConversion: '<S3>/Data Type Conversion'
     *  S-Function (sfix_bitop): '<S3>/Bitwise Operator'
     */
    GPIOWrite(stellaris_lp_pwm_P.GPIOWrite_p1, (uint8_T)
              (stellaris_lp_pwm_P.REDLED_Value |
               stellaris_lp_pwm_P.BLUELED_Value |
               stellaris_lp_pwm_P.GREENLED_Value), (uint8_T)(lastSin_tmp < 0.0 ?
               (int32_T)(uint8_T)-(int8_T)(uint8_T)-lastSin_tmp : (int32_T)
               (uint8_T)lastSin_tmp));
  }

  /* S-Function (stellaris_lp_sfunc_GPIOSetup): '<S3>/GPIO Setup' */
  GPIOVoidFunc();

  /* Update for Sin: '<Root>/Sine Wave' */
  lastSin_tmp = stellaris_lp_pwm_DWork.lastSin;
  stellaris_lp_pwm_DWork.lastSin = stellaris_lp_pwm_DWork.lastSin *
    stellaris_lp_pwm_P.SineWave_HCos + stellaris_lp_pwm_DWork.lastCos *
    stellaris_lp_pwm_P.SineWave_Hsin;
  stellaris_lp_pwm_DWork.lastCos = stellaris_lp_pwm_DWork.lastCos *
    stellaris_lp_pwm_P.SineWave_HCos - lastSin_tmp *
    stellaris_lp_pwm_P.SineWave_Hsin;
  if (stellaris_lp_pwm_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UniformRandomNumber: '<S3>/Uniform Random Number' */
    stellaris_lp_pwm_DWork.UniformRandomNumber_NextOutput =
      (stellaris_lp_pwm_P.UniformRandomNumber_Maximum -
       stellaris_lp_pwm_P.UniformRandomNumber_Minimum) *
      rt_urand_Upu32_Yd_f_pw_snf(&stellaris_lp_pwm_DWork.RandSeed) +
      stellaris_lp_pwm_P.UniformRandomNumber_Minimum;
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.002, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  stellaris_lp_pwm_M->Timing.clockTick0++;
  rate_scheduler();
}

/* Model initialize function */
void stellaris_lp_pwm_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)stellaris_lp_pwm_M, 0,
                sizeof(RT_MODEL_stellaris_lp_pwm));

  /* states (dwork) */
  (void) memset((void *)&stellaris_lp_pwm_DWork, 0,
                sizeof(D_Work_stellaris_lp_pwm));

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* Start for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S1>/S-Function2' */
    PWMInit(stellaris_lp_pwm_P.SFunction2_p1, stellaris_lp_pwm_P.SFunction2_p2,
            stellaris_lp_pwm_P.SFunction2_p3);

    /* Start for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S2>/S-Function2' */
    PWMInit(stellaris_lp_pwm_P.SFunction2_p1_a,
            stellaris_lp_pwm_P.SFunction2_p2_d,
            stellaris_lp_pwm_P.SFunction2_p3_c);

    /* Start for S-Function (stellaris_lp_sfunc_GPIOSetup): '<S3>/GPIO Setup' */
    GPIOSetup(stellaris_lp_pwm_P.GPIOSetup_p1, stellaris_lp_pwm_P.GPIOSetup_p2,
              stellaris_lp_pwm_P.GPIOSetup_p3, stellaris_lp_pwm_P.GPIOSetup_p4);

    /* InitializeConditions for UniformRandomNumber: '<S3>/Uniform Random Number' */
    tmp = floor(stellaris_lp_pwm_P.UniformRandomNumber_Seed);
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

    stellaris_lp_pwm_DWork.RandSeed = tseed;
    stellaris_lp_pwm_DWork.UniformRandomNumber_NextOutput =
      (stellaris_lp_pwm_P.UniformRandomNumber_Maximum -
       stellaris_lp_pwm_P.UniformRandomNumber_Minimum) *
      rt_urand_Upu32_Yd_f_pw_snf(&stellaris_lp_pwm_DWork.RandSeed) +
      stellaris_lp_pwm_P.UniformRandomNumber_Minimum;

    /* End of InitializeConditions for UniformRandomNumber: '<S3>/Uniform Random Number' */

    /* Enable for Sin: '<Root>/Sine Wave' */
    stellaris_lp_pwm_DWork.systemEnable = 1;
  }
}

/* Model terminate function */
void stellaris_lp_pwm_terminate(void)
{
  /* Terminate for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S1>/S-Function2' */
  PWMStop(stellaris_lp_pwm_P.SFunction2_p1);

  /* Terminate for S-Function (stellaris_lp_sfunc_PWMUpdate_f): '<S2>/S-Function2' */
  PWMStop(stellaris_lp_pwm_P.SFunction2_p1_a);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
