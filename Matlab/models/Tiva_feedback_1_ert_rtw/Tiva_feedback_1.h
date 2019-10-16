/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Tiva_feedback_1.h
 *
 * Code generated for Simulink model 'Tiva_feedback_1'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Mon Sep 30 18:15:48 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Tiva_feedback_1_h_
#define RTW_HEADER_Tiva_feedback_1_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Tiva_feedback_1_COMMON_INCLUDES_
# define Tiva_feedback_1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "lct_wrapper.h"
#include "gpiolct.h"
#endif                                 /* Tiva_feedback_1_COMMON_INCLUDES_ */

#include "Tiva_feedback_1_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UniformRandomNumber_NextOutput;/* '<S6>/Uniform Random Number' */
  real_T ir_arr[400];                  /* '<Root>/MATLAB Function2' */
  real_T i;                            /* '<Root>/MATLAB Function2' */
  int32_T p_min;                       /* '<Root>/MATLAB Function' */
  int32_T p_max;                       /* '<Root>/MATLAB Function' */
  uint32_T RandSeed;                   /* '<S6>/Uniform Random Number' */
  boolean_T ir_arr_not_empty;          /* '<Root>/MATLAB Function2' */
  boolean_T p_min_not_empty;           /* '<Root>/MATLAB Function' */
} DW_Tiva_feedback_1_T;

/* Parameters (auto storage) */
struct P_Tiva_feedback_1_T_ {
  real_T UniformRandomNumber_Minimum;  /* Expression: 2
                                        * Referenced by: '<S6>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Maximum;  /* Expression: 16
                                        * Referenced by: '<S6>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Seed;     /* Expression: 0
                                        * Referenced by: '<S6>/Uniform Random Number'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
                                        */
  int32_T ADRaw1_p1;                   /* Computed Parameter: ADRaw1_p1
                                        * Referenced by: '<Root>/AD Raw1'
                                        */
  int32_T SFunction2_p1;               /* Expression: int32(ch)
                                        * Referenced by: '<S5>/S-Function2'
                                        */
  int32_T SFunction2_p3;               /* Expression: int32(invert-1)
                                        * Referenced by: '<S5>/S-Function2'
                                        */
  int32_T SFunction2_p1_l;             /* Expression: int32(ch)
                                        * Referenced by: '<S4>/S-Function2'
                                        */
  int32_T SFunction2_p3_o;             /* Expression: int32(invert-1)
                                        * Referenced by: '<S4>/S-Function2'
                                        */
  uint32_T SFunction2_p2;              /* Expression: uint32(freq)
                                        * Referenced by: '<S5>/S-Function2'
                                        */
  uint32_T SFunction2_p2_h;            /* Expression: uint32(freq)
                                        * Referenced by: '<S4>/S-Function2'
                                        */
  uint32_T GPIOWrite_p1;               /* Computed Parameter: GPIOWrite_p1
                                        * Referenced by: '<S6>/GPIO Write'
                                        */
  uint32_T GPIOSetup_p1;               /* Computed Parameter: GPIOSetup_p1
                                        * Referenced by: '<S6>/GPIO Setup'
                                        */
  uint32_T GPIOSetup_p2;               /* Computed Parameter: GPIOSetup_p2
                                        * Referenced by: '<S6>/GPIO Setup'
                                        */
  uint8_T DebugPrint_p1[51];           /* Expression: [uint8(fmt), 13,10, 0]
                                        * Referenced by: '<Root>/Debug Print'
                                        */
  uint8_T REDLED_Value;                /* Computed Parameter: REDLED_Value
                                        * Referenced by: '<S6>/RED LED'
                                        */
  uint8_T BLUELED_Value;               /* Computed Parameter: BLUELED_Value
                                        * Referenced by: '<S6>/BLUE LED'
                                        */
  uint8_T GREENLED_Value;              /* Computed Parameter: GREENLED_Value
                                        * Referenced by: '<S6>/GREEN LED'
                                        */
  uint8_T GPIOSetup_p3;                /* Computed Parameter: GPIOSetup_p3
                                        * Referenced by: '<S6>/GPIO Setup'
                                        */
  uint8_T GPIOSetup_p4;                /* Computed Parameter: GPIOSetup_p4
                                        * Referenced by: '<S6>/GPIO Setup'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Tiva_feedback_1_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Tiva_feedback_1_T Tiva_feedback_1_P;

/* Block states (auto storage) */
extern DW_Tiva_feedback_1_T Tiva_feedback_1_DW;

/* External function called from main */
extern void Tiva_feedback_1_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Tiva_feedback_1_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Tiva_feedback_1_initialize(void);
extern void Tiva_feedback_1_step0(void);
extern void Tiva_feedback_1_step1(void);
extern void Tiva_feedback_1_step2(void);
extern void Tiva_feedback_1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Tiva_feedback_1_T *const Tiva_feedback_1_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Tiva_feedback_1'
 * '<S1>'   : 'Tiva_feedback_1/MATLAB Function'
 * '<S2>'   : 'Tiva_feedback_1/MATLAB Function1'
 * '<S3>'   : 'Tiva_feedback_1/MATLAB Function2'
 * '<S4>'   : 'Tiva_feedback_1/PWM Output'
 * '<S5>'   : 'Tiva_feedback_1/PWM Output1'
 * '<S6>'   : 'Tiva_feedback_1/Running Indicator'
 */
#endif                                 /* RTW_HEADER_Tiva_feedback_1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
