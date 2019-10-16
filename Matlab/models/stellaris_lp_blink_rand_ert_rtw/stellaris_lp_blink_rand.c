/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stellaris_lp_blink_rand.c
 *
 * Code generated for Simulink model 'stellaris_lp_blink_rand'.
 *
 * Model version                  : 1.77
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Sep 11 18:23:27 2019
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

#include "stellaris_lp_blink_rand.h"
#include "stellaris_lp_blink_rand_private.h"
#include "rt_urand_Upu32_Yd_f_pw.h"

/* Block signals and states (auto storage) */
DW_stellaris_lp_blink_rand stellaris_lp_blink_rand_DW;

/* Real-time model */
RT_MODEL_stellaris_lp_blink_ran stellaris_lp_blink_rand_M_;
RT_MODEL_stellaris_lp_blink_ran *const stellaris_lp_blink_rand_M =
  &stellaris_lp_blink_rand_M_;
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
  (stellaris_lp_blink_rand_M->Timing.TaskCounters.TID[1])++;
  if ((stellaris_lp_blink_rand_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.4s, 0.0s] */
    stellaris_lp_blink_rand_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void stellaris_lp_blink_rand_step(void)
{
  uint8_T rtb_Output;
  uint8_T rtb_FixPtSum1_d;
  uint8_T rtb_FixPtSwitch_c;
  if (stellaris_lp_blink_rand_M->Timing.TaskCounters.TID[1] == 0) {
    /* UnitDelay: '<S3>/Output' */
    rtb_Output = stellaris_lp_blink_rand_DW.Output_DSTATE;

    /* MultiPortSwitch: '<S1>/Output' incorporates:
     *  Constant: '<S1>/Vector'
     *  UnitDelay: '<S3>/Output'
     */
    stellaris_lp_blink_rand_DW.Output =
      stellaris_lp_blink_rand_P.NotRAND_OutValues[stellaris_lp_blink_rand_DW.Output_DSTATE];
  }

  /* ManualSwitch: '<Root>/Random Style Switch' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  ManualSwitch: '<Root>/Random Style Switch1'
   *  UniformRandomNumber: '<Root>/Random Every Sample'
   */
  if (((int32_T)stellaris_lp_blink_rand_P.RandomStyleSwitch_CurrentSettin) == 1)
  {
    rtb_FixPtSum1_d = (uint8_T)
      stellaris_lp_blink_rand_DW.RandomEverySample_NextOutput;
  } else if (((int32_T)stellaris_lp_blink_rand_P.RandomStyleSwitch1_CurrentSetti)
             == 1) {
    /* ManualSwitch: '<Root>/Random Style Switch1' incorporates:
     *  Constant: '<S2>/Vector'
     *  MultiPortSwitch: '<S2>/Output'
     *  UnitDelay: '<S6>/Output'
     */
    rtb_FixPtSum1_d =
      stellaris_lp_blink_rand_P.RandomEveryBuild_OutValues[stellaris_lp_blink_rand_DW.Output_DSTATE_n];
  } else {
    rtb_FixPtSum1_d = stellaris_lp_blink_rand_DW.Output;
  }

  /* End of ManualSwitch: '<Root>/Random Style Switch' */

  /* S-Function (stellaris_lp_sfunc_GPIOWrite): '<Root>/GPIO Write' incorporates:
   *  Constant: '<Root>/BLUE LED'
   *  Constant: '<Root>/GREEN LED'
   *  Constant: '<Root>/RED LED'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator'
   */
  GPIOWrite(stellaris_lp_blink_rand_P.GPIOWrite_p1, (uint8_T)
            ((stellaris_lp_blink_rand_P.REDLED_Value |
              stellaris_lp_blink_rand_P.BLUELED_Value) |
             stellaris_lp_blink_rand_P.GREENLED_Value), rtb_FixPtSum1_d);

  /* Sum: '<S7>/FixPt Sum1' incorporates:
   *  Constant: '<S7>/FixPt Constant'
   *  UnitDelay: '<S6>/Output'
   */
  rtb_FixPtSum1_d = (uint8_T)(((uint32_T)
    stellaris_lp_blink_rand_DW.Output_DSTATE_n) + ((uint32_T)
    stellaris_lp_blink_rand_P.FixPtConstant_Value));
  if (stellaris_lp_blink_rand_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S4>/FixPt Sum1' incorporates:
     *  Constant: '<S4>/FixPt Constant'
     */
    rtb_Output = (uint8_T)(((uint32_T)rtb_Output) + ((uint32_T)
      stellaris_lp_blink_rand_P.FixPtConstant_Value_b));

    /* Switch: '<S5>/FixPt Switch' incorporates:
     *  Constant: '<S5>/Constant'
     */
    if (rtb_Output > stellaris_lp_blink_rand_P.LimitedCounter_uplimit_e) {
      rtb_FixPtSwitch_c = stellaris_lp_blink_rand_P.Constant_Value;
    } else {
      rtb_FixPtSwitch_c = rtb_Output;
    }

    /* End of Switch: '<S5>/FixPt Switch' */
  }

  /* S-Function (stellaris_lp_sfunc_GPIOSetup): '<Root>/GPIO Setup' */
  GPIOVoidFunc();
  if (stellaris_lp_blink_rand_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S3>/Output' */
    stellaris_lp_blink_rand_DW.Output_DSTATE = rtb_FixPtSwitch_c;
  }

  /* Switch: '<S8>/FixPt Switch' */
  if (rtb_FixPtSum1_d > stellaris_lp_blink_rand_P.LimitedCounter_uplimit) {
    /* Update for UnitDelay: '<S6>/Output' incorporates:
     *  Constant: '<S8>/Constant'
     */
    stellaris_lp_blink_rand_DW.Output_DSTATE_n =
      stellaris_lp_blink_rand_P.Constant_Value_j;
  } else {
    /* Update for UnitDelay: '<S6>/Output' */
    stellaris_lp_blink_rand_DW.Output_DSTATE_n = rtb_FixPtSum1_d;
  }

  /* End of Switch: '<S8>/FixPt Switch' */

  /* Update for UniformRandomNumber: '<Root>/Random Every Sample' */
  stellaris_lp_blink_rand_DW.RandomEverySample_NextOutput =
    ((stellaris_lp_blink_rand_P.RandomEverySample_Maximum -
      stellaris_lp_blink_rand_P.RandomEverySample_Minimum) *
     rt_urand_Upu32_Yd_f_pw(&stellaris_lp_blink_rand_DW.RandSeed)) +
    stellaris_lp_blink_rand_P.RandomEverySample_Minimum;
  rate_scheduler();
}

/* Model initialize function */
void stellaris_lp_blink_rand_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)stellaris_lp_blink_rand_M, 0,
                sizeof(RT_MODEL_stellaris_lp_blink_ran));

  /* states (dwork) */
  (void) memset((void *)&stellaris_lp_blink_rand_DW, 0,
                sizeof(DW_stellaris_lp_blink_rand));

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;

    /* Start for S-Function (stellaris_lp_sfunc_GPIOSetup): '<Root>/GPIO Setup' */
    GPIOSetup(stellaris_lp_blink_rand_P.GPIOSetup_p1,
              stellaris_lp_blink_rand_P.GPIOSetup_p2,
              stellaris_lp_blink_rand_P.GPIOSetup_p3,
              stellaris_lp_blink_rand_P.GPIOSetup_p4);

    /* InitializeConditions for UnitDelay: '<S3>/Output' */
    stellaris_lp_blink_rand_DW.Output_DSTATE =
      stellaris_lp_blink_rand_P.Output_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S6>/Output' */
    stellaris_lp_blink_rand_DW.Output_DSTATE_n =
      stellaris_lp_blink_rand_P.Output_InitialCondition_i;

    /* InitializeConditions for UniformRandomNumber: '<Root>/Random Every Sample' */
    tseed = (uint32_T)stellaris_lp_blink_rand_P.RandomEverySample_Seed;
    r = (int32_T)((uint32_T)(tseed >> 16U));
    t = (int32_T)((uint32_T)(tseed & 32768U));
    tseed = ((((tseed - (((uint32_T)r) << 16U)) + ((uint32_T)t)) << 16U) +
             ((uint32_T)t)) + ((uint32_T)r);
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    stellaris_lp_blink_rand_DW.RandSeed = tseed;
    stellaris_lp_blink_rand_DW.RandomEverySample_NextOutput =
      ((stellaris_lp_blink_rand_P.RandomEverySample_Maximum -
        stellaris_lp_blink_rand_P.RandomEverySample_Minimum) *
       rt_urand_Upu32_Yd_f_pw(&stellaris_lp_blink_rand_DW.RandSeed)) +
      stellaris_lp_blink_rand_P.RandomEverySample_Minimum;

    /* End of InitializeConditions for UniformRandomNumber: '<Root>/Random Every Sample' */
  }
}

/* Model terminate function */
void stellaris_lp_blink_rand_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
