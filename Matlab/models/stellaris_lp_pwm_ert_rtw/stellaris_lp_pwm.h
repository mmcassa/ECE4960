/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stellaris_lp_pwm.h
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

#ifndef RTW_HEADER_stellaris_lp_pwm_h_
#define RTW_HEADER_stellaris_lp_pwm_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef stellaris_lp_pwm_COMMON_INCLUDES_
# define stellaris_lp_pwm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "lct_wrapper.h"
#include "gpiolct.h"
#endif                                 /* stellaris_lp_pwm_COMMON_INCLUDES_ */

#include "stellaris_lp_pwm_types.h"
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

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T lastSin;                      /* '<Root>/Sine Wave' */
  real_T lastCos;                      /* '<Root>/Sine Wave' */
  real_T UniformRandomNumber_NextOutput;/* '<S3>/Uniform Random Number' */
  int32_T systemEnable;                /* '<Root>/Sine Wave' */
  uint32_T RandSeed;                   /* '<S3>/Uniform Random Number' */
} D_Work_stellaris_lp_pwm;

/* Parameters (auto storage) */
struct Parameters_stellaris_lp_pwm_ {
  real_T SineWave_Amp;                 /* Expression: 50
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 50
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1/3*2*pi
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Hsin;                /* Computed Parameter: SineWave_Hsin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_HCos;                /* Computed Parameter: SineWave_HCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_PSin;                /* Computed Parameter: SineWave_PSin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_PCos;                /* Computed Parameter: SineWave_PCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T UniformRandomNumber_Minimum;  /* Expression: 2
                                        * Referenced by: '<S3>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Maximum;  /* Expression: 16
                                        * Referenced by: '<S3>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Seed;     /* Expression: 0
                                        * Referenced by: '<S3>/Uniform Random Number'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
                                        */
  int32_T SFunction2_p1;               /* Expression: int32(ch)
                                        * Referenced by: '<S1>/S-Function2'
                                        */
  int32_T SFunction2_p3;               /* Expression: int32(invert-1)
                                        * Referenced by: '<S1>/S-Function2'
                                        */
  int32_T SFunction2_p1_a;             /* Expression: int32(ch)
                                        * Referenced by: '<S2>/S-Function2'
                                        */
  int32_T SFunction2_p3_c;             /* Expression: int32(invert-1)
                                        * Referenced by: '<S2>/S-Function2'
                                        */
  uint32_T SFunction2_p2;              /* Expression: uint32(freq)
                                        * Referenced by: '<S1>/S-Function2'
                                        */
  uint32_T SFunction2_p2_d;            /* Expression: uint32(freq)
                                        * Referenced by: '<S2>/S-Function2'
                                        */
  uint32_T GPIOWrite_p1;               /* Computed Parameter: GPIOWrite_p1
                                        * Referenced by: '<S3>/GPIO Write'
                                        */
  uint32_T GPIOSetup_p1;               /* Computed Parameter: GPIOSetup_p1
                                        * Referenced by: '<S3>/GPIO Setup'
                                        */
  uint32_T GPIOSetup_p2;               /* Computed Parameter: GPIOSetup_p2
                                        * Referenced by: '<S3>/GPIO Setup'
                                        */
  uint8_T REDLED_Value;                /* Computed Parameter: REDLED_Value
                                        * Referenced by: '<S3>/RED LED'
                                        */
  uint8_T BLUELED_Value;               /* Computed Parameter: BLUELED_Value
                                        * Referenced by: '<S3>/BLUE LED'
                                        */
  uint8_T GREENLED_Value;              /* Computed Parameter: GREENLED_Value
                                        * Referenced by: '<S3>/GREEN LED'
                                        */
  uint8_T GPIOSetup_p3;                /* Computed Parameter: GPIOSetup_p3
                                        * Referenced by: '<S3>/GPIO Setup'
                                        */
  uint8_T GPIOSetup_p4;                /* Computed Parameter: GPIOSetup_p4
                                        * Referenced by: '<S3>/GPIO Setup'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_stellaris_lp_pwm {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_stellaris_lp_pwm stellaris_lp_pwm_P;

/* Block states (auto storage) */
extern D_Work_stellaris_lp_pwm stellaris_lp_pwm_DWork;

/* Model entry point functions */
extern void stellaris_lp_pwm_initialize(void);
extern void stellaris_lp_pwm_step(void);
extern void stellaris_lp_pwm_terminate(void);

/* Real-time Model object */
extern RT_MODEL_stellaris_lp_pwm *const stellaris_lp_pwm_M;

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
 * '<Root>' : 'stellaris_lp_pwm'
 * '<S1>'   : 'stellaris_lp_pwm/PWM Output'
 * '<S2>'   : 'stellaris_lp_pwm/PWM Output1'
 * '<S3>'   : 'stellaris_lp_pwm/Running Indicator'
 */
#endif                                 /* RTW_HEADER_stellaris_lp_pwm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
