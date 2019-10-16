/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Feedback_2.h
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

#ifndef RTW_HEADER_Feedback_2_h_
#define RTW_HEADER_Feedback_2_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Feedback_2_COMMON_INCLUDES_
# define Feedback_2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "lct_wrapper.h"
#include "gpiolct.h"
#endif                                 /* Feedback_2_COMMON_INCLUDES_ */

#include "Feedback_2_types.h"
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
  real_T UniformRandomNumber_NextOutput;/* '<S9>/Uniform Random Number' */
  real_T ir_arr[400];                  /* '<Root>/MATLAB Function2' */
  real_T i;                            /* '<Root>/MATLAB Function2' */
  int32_T p_min;                       /* '<Root>/MATLAB Function' */
  int32_T p_max;                       /* '<Root>/MATLAB Function' */
  uint32_T RandSeed;                   /* '<S9>/Uniform Random Number' */
  boolean_T ir_arr_not_empty;          /* '<Root>/MATLAB Function2' */
  boolean_T p_min_not_empty;           /* '<Root>/MATLAB Function' */
} DW_Feedback_2_T;

/* Parameters (auto storage) */
struct P_Feedback_2_T_ {
  real_T UniformRandomNumber_Minimum;  /* Expression: 2
                                        * Referenced by: '<S9>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Maximum;  /* Expression: 16
                                        * Referenced by: '<S9>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Seed;     /* Expression: 0
                                        * Referenced by: '<S9>/Uniform Random Number'
                                        */
  int32_T ADRaw1_p1;                   /* Computed Parameter: ADRaw1_p1
                                        * Referenced by: '<Root>/AD Raw1'
                                        */
  int32_T SFunction2_p1;               /* Expression: int32(ch)
                                        * Referenced by: '<S7>/S-Function2'
                                        */
  int32_T SFunction2_p3;               /* Expression: int32(invert-1)
                                        * Referenced by: '<S7>/S-Function2'
                                        */
  int32_T ADRaw2_p1;                   /* Computed Parameter: ADRaw2_p1
                                        * Referenced by: '<Root>/AD Raw2'
                                        */
  int32_T SFunction2_p1_d;             /* Expression: int32(ch)
                                        * Referenced by: '<S8>/S-Function2'
                                        */
  int32_T SFunction2_p3_m;             /* Expression: int32(invert-1)
                                        * Referenced by: '<S8>/S-Function2'
                                        */
  int32_T ADRaw3_p1;                   /* Computed Parameter: ADRaw3_p1
                                        * Referenced by: '<Root>/AD Raw3'
                                        */
  int32_T SFunction2_p1_l;             /* Expression: int32(ch)
                                        * Referenced by: '<S6>/S-Function2'
                                        */
  int32_T SFunction2_p3_o;             /* Expression: int32(invert-1)
                                        * Referenced by: '<S6>/S-Function2'
                                        */
  uint32_T SFunction2_p2;              /* Expression: uint32(freq)
                                        * Referenced by: '<S7>/S-Function2'
                                        */
  uint32_T SFunction2_p2_e;            /* Expression: uint32(freq)
                                        * Referenced by: '<S8>/S-Function2'
                                        */
  uint32_T SFunction2_p2_h;            /* Expression: uint32(freq)
                                        * Referenced by: '<S6>/S-Function2'
                                        */
  uint32_T GPIOWrite_p1;               /* Computed Parameter: GPIOWrite_p1
                                        * Referenced by: '<S9>/GPIO Write'
                                        */
  uint32_T GPIOSetup_p1;               /* Computed Parameter: GPIOSetup_p1
                                        * Referenced by: '<S9>/GPIO Setup'
                                        */
  uint32_T GPIOSetup_p2;               /* Computed Parameter: GPIOSetup_p2
                                        * Referenced by: '<S9>/GPIO Setup'
                                        */
  uint8_T DebugPrint_p1[43];           /* Expression: [uint8(fmt), 13,10, 0]
                                        * Referenced by: '<Root>/Debug Print'
                                        */
  uint8_T REDLED_Value;                /* Computed Parameter: REDLED_Value
                                        * Referenced by: '<S9>/RED LED'
                                        */
  uint8_T BLUELED_Value;               /* Computed Parameter: BLUELED_Value
                                        * Referenced by: '<S9>/BLUE LED'
                                        */
  uint8_T GREENLED_Value;              /* Computed Parameter: GREENLED_Value
                                        * Referenced by: '<S9>/GREEN LED'
                                        */
  uint8_T GPIOSetup_p3;                /* Computed Parameter: GPIOSetup_p3
                                        * Referenced by: '<S9>/GPIO Setup'
                                        */
  uint8_T GPIOSetup_p4;                /* Computed Parameter: GPIOSetup_p4
                                        * Referenced by: '<S9>/GPIO Setup'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Feedback_2_T {
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
extern P_Feedback_2_T Feedback_2_P;

/* Block states (auto storage) */
extern DW_Feedback_2_T Feedback_2_DW;

/* External function called from main */
extern void Feedback_2_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Feedback_2_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Feedback_2_initialize(void);
extern void Feedback_2_step0(void);
extern void Feedback_2_step1(void);
extern void Feedback_2_step2(void);
extern void Feedback_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Feedback_2_T *const Feedback_2_M;

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
 * '<Root>' : 'Feedback_2'
 * '<S1>'   : 'Feedback_2/MATLAB Function'
 * '<S2>'   : 'Feedback_2/MATLAB Function1'
 * '<S3>'   : 'Feedback_2/MATLAB Function2'
 * '<S4>'   : 'Feedback_2/MATLAB Function3'
 * '<S5>'   : 'Feedback_2/MATLAB Function4'
 * '<S6>'   : 'Feedback_2/PWM Output'
 * '<S7>'   : 'Feedback_2/PWM Output1'
 * '<S8>'   : 'Feedback_2/PWM Output2'
 * '<S9>'   : 'Feedback_2/Running Indicator'
 */
#endif                                 /* RTW_HEADER_Feedback_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
