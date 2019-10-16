/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Feedback_3.h
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

#ifndef RTW_HEADER_Feedback_3_h_
#define RTW_HEADER_Feedback_3_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Feedback_3_COMMON_INCLUDES_
# define Feedback_3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "lct_wrapper.h"
#include "gpiolct.h"
#endif                                 /* Feedback_3_COMMON_INCLUDES_ */

#include "Feedback_3_types.h"
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
  real_T DiscreteTransferFcn_states;   /* '<S5>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_c; /* '<S6>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_e; /* '<S7>/Discrete Transfer Fcn' */
  real_T UniformRandomNumber_NextOutput;/* '<S4>/Uniform Random Number' */
  uint32_T RandSeed;                   /* '<S4>/Uniform Random Number' */
} DW_Feedback_3_T;

/* Parameters (auto storage) */
struct P_Feedback_3_T_ {
  real_T Constant1_Value;              /* Expression: .1257
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: -.008
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant_Value_f;             /* Expression: 230
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Polynomial_Coefs[3];          /* Expression: [825.38 -933.83 394.44]
                                        * Referenced by: '<S5>/Polynomial'
                                        */
  real_T Constant1_Value_c;            /* Expression: 1000
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Gain_Gain;                    /* Expression: 9000
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T DiscreteTransferFcn_NumCoef[2];/* Expression: [1 500]
                                         * Referenced by: '<S5>/Discrete Transfer Fcn'
                                         */
  real_T DiscreteTransferFcn_DenCoef[2];/* Expression: [1 0.5]
                                         * Referenced by: '<S5>/Discrete Transfer Fcn'
                                         */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<S5>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_o;             /* Expression: 230
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Polynomial_Coefs_c[3];        /* Expression: [825.38 -933.83 394.44]
                                        * Referenced by: '<S6>/Polynomial'
                                        */
  real_T Constant1_Value_a;            /* Expression: 1000
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 9000
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T DiscreteTransferFcn_NumCoef_l[2];/* Expression: [1 500]
                                           * Referenced by: '<S6>/Discrete Transfer Fcn'
                                           */
  real_T DiscreteTransferFcn_DenCoef_n[2];/* Expression: [1 0.5]
                                           * Referenced by: '<S6>/Discrete Transfer Fcn'
                                           */
  real_T DiscreteTransferFcn_InitialSt_l;/* Expression: 0
                                          * Referenced by: '<S6>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_b;             /* Expression: 230
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Polynomial_Coefs_cy[3];       /* Expression: [825.38 -933.83 394.44]
                                        * Referenced by: '<S7>/Polynomial'
                                        */
  real_T Constant1_Value_l;            /* Expression: 1000
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 9000
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T DiscreteTransferFcn_NumCoef_g[2];/* Expression: [1 500]
                                           * Referenced by: '<S7>/Discrete Transfer Fcn'
                                           */
  real_T DiscreteTransferFcn_DenCoef_f[2];/* Expression: [1 0.5]
                                           * Referenced by: '<S7>/Discrete Transfer Fcn'
                                           */
  real_T DiscreteTransferFcn_InitialSt_m;/* Expression: 0
                                          * Referenced by: '<S7>/Discrete Transfer Fcn'
                                          */
  real_T UniformRandomNumber_Minimum;  /* Expression: 2
                                        * Referenced by: '<S4>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Maximum;  /* Expression: 16
                                        * Referenced by: '<S4>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Seed;     /* Expression: 0
                                        * Referenced by: '<S4>/Uniform Random Number'
                                        */
  int32_T ADRaw3_p1;                   /* Computed Parameter: ADRaw3_p1
                                        * Referenced by: '<Root>/AD Raw3'
                                        */
  int32_T ADRaw2_p1;                   /* Computed Parameter: ADRaw2_p1
                                        * Referenced by: '<Root>/AD Raw2'
                                        */
  int32_T ADRaw1_p1;                   /* Computed Parameter: ADRaw1_p1
                                        * Referenced by: '<Root>/AD Raw1'
                                        */
  int32_T SFunction2_p1;               /* Expression: int32(ch)
                                        * Referenced by: '<S1>/S-Function2'
                                        */
  int32_T SFunction2_p3;               /* Expression: int32(invert-1)
                                        * Referenced by: '<S1>/S-Function2'
                                        */
  int32_T SFunction2_p1_c;             /* Expression: int32(ch)
                                        * Referenced by: '<S2>/S-Function2'
                                        */
  int32_T SFunction2_p3_m;             /* Expression: int32(invert-1)
                                        * Referenced by: '<S2>/S-Function2'
                                        */
  int32_T SFunction2_p1_d;             /* Expression: int32(ch)
                                        * Referenced by: '<S3>/S-Function2'
                                        */
  int32_T SFunction2_p3_mx;            /* Expression: int32(invert-1)
                                        * Referenced by: '<S3>/S-Function2'
                                        */
  uint32_T SFunction2_p2;              /* Expression: uint32(freq)
                                        * Referenced by: '<S1>/S-Function2'
                                        */
  uint32_T SFunction2_p2_l;            /* Expression: uint32(freq)
                                        * Referenced by: '<S2>/S-Function2'
                                        */
  uint32_T SFunction2_p2_e;            /* Expression: uint32(freq)
                                        * Referenced by: '<S3>/S-Function2'
                                        */
  uint32_T GPIOWrite_p1;               /* Computed Parameter: GPIOWrite_p1
                                        * Referenced by: '<S4>/GPIO Write'
                                        */
  uint32_T GPIOSetup_p1;               /* Computed Parameter: GPIOSetup_p1
                                        * Referenced by: '<S4>/GPIO Setup'
                                        */
  uint32_T GPIOSetup_p2;               /* Computed Parameter: GPIOSetup_p2
                                        * Referenced by: '<S4>/GPIO Setup'
                                        */
  uint8_T DebugPrint_p1[35];           /* Expression: [uint8(fmt), 13,10, 0]
                                        * Referenced by: '<Root>/Debug Print'
                                        */
  uint8_T REDLED_Value;                /* Computed Parameter: REDLED_Value
                                        * Referenced by: '<S4>/RED LED'
                                        */
  uint8_T BLUELED_Value;               /* Computed Parameter: BLUELED_Value
                                        * Referenced by: '<S4>/BLUE LED'
                                        */
  uint8_T GREENLED_Value;              /* Computed Parameter: GREENLED_Value
                                        * Referenced by: '<S4>/GREEN LED'
                                        */
  uint8_T GPIOSetup_p3;                /* Computed Parameter: GPIOSetup_p3
                                        * Referenced by: '<S4>/GPIO Setup'
                                        */
  uint8_T GPIOSetup_p4;                /* Computed Parameter: GPIOSetup_p4
                                        * Referenced by: '<S4>/GPIO Setup'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Feedback_3_T {
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
extern P_Feedback_3_T Feedback_3_P;

/* Block states (auto storage) */
extern DW_Feedback_3_T Feedback_3_DW;

/* External function called from main */
extern void Feedback_3_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Feedback_3_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Feedback_3_initialize(void);
extern void Feedback_3_step0(void);
extern void Feedback_3_step1(void);
extern void Feedback_3_step2(void);
extern void Feedback_3_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Feedback_3_T *const Feedback_3_M;

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
 * '<Root>' : 'Feedback_3'
 * '<S1>'   : 'Feedback_3/PWM Output'
 * '<S2>'   : 'Feedback_3/PWM Output1'
 * '<S3>'   : 'Feedback_3/PWM Output2'
 * '<S4>'   : 'Feedback_3/Running Indicator'
 * '<S5>'   : 'Feedback_3/Subsystem1'
 * '<S6>'   : 'Feedback_3/Subsystem2'
 * '<S7>'   : 'Feedback_3/Subsystem3'
 * '<S8>'   : 'Feedback_3/Subsystem1/MATLAB Function3'
 * '<S9>'   : 'Feedback_3/Subsystem2/MATLAB Function3'
 * '<S10>'  : 'Feedback_3/Subsystem3/MATLAB Function3'
 */
#endif                                 /* RTW_HEADER_Feedback_3_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
