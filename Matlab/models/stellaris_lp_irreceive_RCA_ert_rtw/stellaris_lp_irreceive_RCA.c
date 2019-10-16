/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stellaris_lp_irreceive_RCA.c
 *
 * Code generated for Simulink model 'stellaris_lp_irreceive_RCA'.
 *
 * Model version                  : 1.208
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Sep 17 13:33:48 2019
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

#include "stellaris_lp_irreceive_RCA.h"
#include "stellaris_lp_irreceive_RCA_private.h"
#include "asr_s32.h"

/* Named constants for Chart: '<Root>/BitDecoder' */
#define stellaris_lp_irre_IN_BitDecoded ((uint8_T)1U)
#define stellaris_lp_irrece_IN_OutStage ((uint8_T)4U)
#define stellaris_lp_irrece_IN_StartSym ((uint8_T)5U)
#define stellaris_lp_irrecei_IN_BitWait ((uint8_T)2U)
#define stellaris_lp_irreceive__IN_Idle ((uint8_T)3U)

/* Block signals and states (auto storage) */
DW_stellaris_lp_irreceive_RCA stellaris_lp_irreceive_RCA_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_stellaris_lp_irreceive_ stellaris_lp_irreceive__PrevZCX;

/* Real-time model */
RT_MODEL_stellaris_lp_irreceive stellaris_lp_irreceive_RCA_M_;
RT_MODEL_stellaris_lp_irreceive *const stellaris_lp_irreceive_RCA_M =
  &stellaris_lp_irreceive_RCA_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void stellaris_lp_irreceive_RCA_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(stellaris_lp_irreceive_RCA_M, 1));
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
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  stellaris_lp_irreceive_RCA_M->Timing.RateInteraction.TID0_1 =
    (stellaris_lp_irreceive_RCA_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (stellaris_lp_irreceive_RCA_M->Timing.TaskCounters.TID[1])++;
  if ((stellaris_lp_irreceive_RCA_M->Timing.TaskCounters.TID[1]) > 1999) {/* Sample time: [0.2s, 0.0s] */
    stellaris_lp_irreceive_RCA_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void stellaris_lp_irreceive_RCA_step0(void) /* Sample time: [0.0001s, 0.0s] */
{
  uint8_T rtb_BitwiseOperator_g;
  int32_T rtb_state;
  boolean_T rtb_Compare;
  boolean_T guard1 = false;

  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (stellaris_lp_sfunc_GPIORead): '<S3>/GPIO Read' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  rtb_BitwiseOperator_g = GPIORead(stellaris_lp_irreceive_RCA_P.GPIORead_p1,
    stellaris_lp_irreceive_RCA_P.Constant1_Value);

  /* S-Function (sfix_bitop): '<S3>/Bitwise Operator' incorporates:
   *  ArithShift: '<S3>/Shift Arithmetic'
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator1'
   *  S-Function (stellaris_lp_sfunc_GPIORead): '<S3>/GPIO Read'
   */
  rtb_BitwiseOperator_g = (uint8_T)(((uint8_T)(~((uint8_T)(((uint32_T)
    rtb_BitwiseOperator_g) >> 4)))) &
    stellaris_lp_irreceive_RCA_P.BitwiseOperator_BitMask_i);

  /* S-Function (stellaris_lp_sfunc_GPIOWrite): '<S4>/GPIO Write' incorporates:
   *  Constant: '<S4>/Constant'
   *  Gain: '<S4>/Gain1'
   */
  GPIOWrite(stellaris_lp_irreceive_RCA_P.GPIOWrite_p1,
            stellaris_lp_irreceive_RCA_P.Constant_Value, (uint8_T)((((uint32_T)
    stellaris_lp_irreceive_RCA_P.Gain1_Gain) * ((uint32_T)rtb_BitwiseOperator_g))
             >> 6));

  /* S-Function (stellaris_lp_sfunc_GPIOSetup): '<S4>/GPIO Setup' */
  GPIOVoidFunc();

  /* Chart: '<Root>/BitDecoder' */
  if (((uint32_T)stellaris_lp_irreceive_RCA_DW.temporalCounter_i1) < 127U) {
    stellaris_lp_irreceive_RCA_DW.temporalCounter_i1 = (uint8_T)((int32_T)
      (((int32_T)stellaris_lp_irreceive_RCA_DW.temporalCounter_i1) + 1));
  }

  /* Gateway: BitDecoder */
  /* During: BitDecoder */
  if (((uint32_T)stellaris_lp_irreceive_RCA_DW.is_active_c1_stellaris_lp_irrec) ==
      0U) {
    /* Entry: BitDecoder */
    stellaris_lp_irreceive_RCA_DW.is_active_c1_stellaris_lp_irrec = 1U;

    /* Entry Internal: BitDecoder */
    /* Transition: '<S1>:127' */
    stellaris_lp_irreceive_RCA_DW.is_c1_stellaris_lp_irreceive_RC =
      stellaris_lp_irreceive__IN_Idle;

    /* Entry 'Idle': '<S1>:129' */
    rtb_state = -1;
    stellaris_lp_irreceive_RCA_DW.frame = 0;
  } else {
    guard1 = false;
    switch (stellaris_lp_irreceive_RCA_DW.is_c1_stellaris_lp_irreceive_RC) {
     case stellaris_lp_irre_IN_BitDecoded:
      rtb_state = -4;

      /* During 'BitDecoded': '<S1>:181' */
      if (((int32_T)rtb_BitwiseOperator_g) == 0) {
        /* Transition: '<S1>:182' */
        if (stellaris_lp_irreceive_RCA_DW.nb > 2147483646) {
          stellaris_lp_irreceive_RCA_DW.nb = MAX_int32_T;
        } else {
          stellaris_lp_irreceive_RCA_DW.nb++;
        }

        stellaris_lp_irreceive_RCA_DW.is_c1_stellaris_lp_irreceive_RC =
          stellaris_lp_irrecei_IN_BitWait;
        stellaris_lp_irreceive_RCA_DW.temporalCounter_i1 = 0U;

        /* Entry 'BitWait': '<S1>:135' */
        rtb_state = -3;
      }
      break;

     case stellaris_lp_irrecei_IN_BitWait:
      rtb_state = -3;

      /* During 'BitWait': '<S1>:135' */
      if (stellaris_lp_irreceive_RCA_DW.nb >= 13) {
        /* Transition: '<S1>:140' */
        stellaris_lp_irreceive_RCA_DW.is_c1_stellaris_lp_irreceive_RC =
          stellaris_lp_irrece_IN_OutStage;

        /* Entry 'OutStage': '<S1>:138' */
        rtb_state = 1;
      } else if ((((uint32_T)stellaris_lp_irreceive_RCA_DW.temporalCounter_i1) >=
                  15U) && (((int32_T)rtb_BitwiseOperator_g) == 1)) {
        /* Transition: '<S1>:183' */
        if (stellaris_lp_irreceive_RCA_DW.frame > 1073741823) {
          rtb_state = MAX_int32_T;
        } else if (stellaris_lp_irreceive_RCA_DW.frame <= -1073741824) {
          rtb_state = MIN_int32_T;
        } else {
          rtb_state = stellaris_lp_irreceive_RCA_DW.frame * 2;
        }

        if (rtb_state > 2147483646) {
          stellaris_lp_irreceive_RCA_DW.frame = MAX_int32_T;
        } else {
          stellaris_lp_irreceive_RCA_DW.frame = rtb_state + 1;
        }

        guard1 = true;
      } else if ((((uint32_T)stellaris_lp_irreceive_RCA_DW.temporalCounter_i1) <
                  15U) && (((int32_T)rtb_BitwiseOperator_g) == 1)) {
        /* Transition: '<S1>:180' */
        if (stellaris_lp_irreceive_RCA_DW.frame > 1073741823) {
          stellaris_lp_irreceive_RCA_DW.frame = MAX_int32_T;
        } else if (stellaris_lp_irreceive_RCA_DW.frame <= -1073741824) {
          stellaris_lp_irreceive_RCA_DW.frame = MIN_int32_T;
        } else {
          stellaris_lp_irreceive_RCA_DW.frame *= 2;
        }

        guard1 = true;
      } else {
        if (((uint32_T)stellaris_lp_irreceive_RCA_DW.temporalCounter_i1) >= 100U)
        {
          /* Transition: '<S1>:132' */
          stellaris_lp_irreceive_RCA_DW.is_c1_stellaris_lp_irreceive_RC =
            stellaris_lp_irreceive__IN_Idle;

          /* Entry 'Idle': '<S1>:129' */
          rtb_state = -1;
          stellaris_lp_irreceive_RCA_DW.frame = 0;
        }
      }
      break;

     case stellaris_lp_irreceive__IN_Idle:
      rtb_state = -1;

      /* During 'Idle': '<S1>:129' */
      if (((int32_T)rtb_BitwiseOperator_g) == 1) {
        /* Transition: '<S1>:141' */
        stellaris_lp_irreceive_RCA_DW.is_c1_stellaris_lp_irreceive_RC =
          stellaris_lp_irrece_IN_StartSym;
        stellaris_lp_irreceive_RCA_DW.temporalCounter_i1 = 0U;

        /* Entry 'StartSym': '<S1>:134' */
        rtb_state = -2;
      }
      break;

     case stellaris_lp_irrece_IN_OutStage:
      /* During 'OutStage': '<S1>:138' */
      /* Transition: '<S1>:136' */
      stellaris_lp_irreceive_RCA_DW.is_c1_stellaris_lp_irreceive_RC =
        stellaris_lp_irreceive__IN_Idle;

      /* Entry 'Idle': '<S1>:129' */
      rtb_state = -1;
      stellaris_lp_irreceive_RCA_DW.frame = 0;
      break;

     default:
      rtb_state = -2;

      /* During 'StartSym': '<S1>:134' */
      if ((((uint32_T)stellaris_lp_irreceive_RCA_DW.temporalCounter_i1) >= 35U) &&
          (((int32_T)rtb_BitwiseOperator_g) == 0)) {
        /* Transition: '<S1>:128' */
        stellaris_lp_irreceive_RCA_DW.nb = 0;
        stellaris_lp_irreceive_RCA_DW.frame = 0;
        stellaris_lp_irreceive_RCA_DW.is_c1_stellaris_lp_irreceive_RC =
          stellaris_lp_irrecei_IN_BitWait;
        stellaris_lp_irreceive_RCA_DW.temporalCounter_i1 = 0U;

        /* Entry 'BitWait': '<S1>:135' */
        rtb_state = -3;
      } else {
        if ((((uint32_T)stellaris_lp_irreceive_RCA_DW.temporalCounter_i1) < 35U)
            && (((int32_T)rtb_BitwiseOperator_g) == 0)) {
          /* Transition: '<S1>:124' */
          stellaris_lp_irreceive_RCA_DW.is_c1_stellaris_lp_irreceive_RC =
            stellaris_lp_irreceive__IN_Idle;

          /* Entry 'Idle': '<S1>:129' */
          rtb_state = -1;
          stellaris_lp_irreceive_RCA_DW.frame = 0;
        }
      }
      break;
    }

    if (guard1) {
      stellaris_lp_irreceive_RCA_DW.is_c1_stellaris_lp_irreceive_RC =
        stellaris_lp_irre_IN_BitDecoded;

      /* Entry 'BitDecoded': '<S1>:181' */
      rtb_state = -4;
    }
  }

  /* End of Chart: '<Root>/BitDecoder' */

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_Compare = (rtb_state > stellaris_lp_irreceive_RCA_P.FrameDataValid_const);

  /* Outputs for Triggered SubSystem: '<Root>/Latch' incorporates:
   *  TriggerPort: '<S5>/Trigger'
   */
  if (rtb_Compare && (((uint32_T)stellaris_lp_irreceive__PrevZCX.Latch_Trig_ZCE)
                      != POS_ZCSIG)) {
    /* Inport: '<S5>/In1' */
    stellaris_lp_irreceive_RCA_DW.In1 = stellaris_lp_irreceive_RCA_DW.frame;
  }

  stellaris_lp_irreceive__PrevZCX.Latch_Trig_ZCE = rtb_Compare ? 1U : 0U;

  /* End of Outputs for SubSystem: '<Root>/Latch' */

  /* RateTransition: '<S6>/Rate Transition' */
  if (stellaris_lp_irreceive_RCA_M->Timing.RateInteraction.TID0_1) {
    stellaris_lp_irreceive_RCA_DW.RateTransition =
      stellaris_lp_irreceive_RCA_DW.In1;

    /* RateTransition: '<S6>/Rate Transition1' */
    stellaris_lp_irreceive_RCA_DW.RateTransition1 = rtb_state;
  }

  /* End of RateTransition: '<S6>/Rate Transition' */
}

/* Model step function for TID1 */
void stellaris_lp_irreceive_RCA_step1(void) /* Sample time: [0.2s, 0.0s] */
{
  /* S-Function (stellaris_lp_sfunc_DebugPrint): '<S6>/Debug Print' incorporates:
   *  ArithShift: '<S6>/Shift Arithmetic'
   *  ArithShift: '<S6>/Shift Arithmetic1'
   *  S-Function (sfix_bitop): '<S6>/Bitwise Operator'
   *  S-Function (sfix_bitop): '<S6>/Bitwise Operator1'
   *  S-Function (sfix_bitop): '<S6>/Bitwise Operator2'
   */
  DebugPrint(stellaris_lp_irreceive_RCA_P.DebugPrint_p1, asr_s32
             (stellaris_lp_irreceive_RCA_DW.RateTransition, 8U) &
             stellaris_lp_irreceive_RCA_P.BitwiseOperator_BitMask, asr_s32
             (stellaris_lp_irreceive_RCA_DW.RateTransition, 4U) &
             stellaris_lp_irreceive_RCA_P.BitwiseOperator1_BitMask,
             stellaris_lp_irreceive_RCA_DW.RateTransition &
             stellaris_lp_irreceive_RCA_P.BitwiseOperator2_BitMask,
             stellaris_lp_irreceive_RCA_DW.RateTransition1);
}

/* Model initialize function */
void stellaris_lp_irreceive_RCA_initialize(void)
{
  /* Start for S-Function (stellaris_lp_sfunc_GPIOSetup): '<S4>/GPIO Setup' */
  GPIOSetup(stellaris_lp_irreceive_RCA_P.GPIOSetup_p1,
            stellaris_lp_irreceive_RCA_P.GPIOSetup_p2,
            stellaris_lp_irreceive_RCA_P.GPIOSetup_p3,
            stellaris_lp_irreceive_RCA_P.GPIOSetup_p4);
  stellaris_lp_irreceive__PrevZCX.Latch_Trig_ZCE = POS_ZCSIG;

  /* SystemInitialize for Triggered SubSystem: '<Root>/Latch' */
  /* SystemInitialize for Outport: '<S5>/Out1' */
  stellaris_lp_irreceive_RCA_DW.In1 = stellaris_lp_irreceive_RCA_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Latch' */
}

/* Model terminate function */
void stellaris_lp_irreceive_RCA_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
