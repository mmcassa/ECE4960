/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stellaris_lp_blink_rand.h
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

#ifndef RTW_HEADER_stellaris_lp_blink_rand_h_
#define RTW_HEADER_stellaris_lp_blink_rand_h_
#include <string.h>
#ifndef stellaris_lp_blink_rand_COMMON_INCLUDES_
# define stellaris_lp_blink_rand_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "gpiolct.h"
#endif                                 /* stellaris_lp_blink_rand_COMMON_INCLUDES_ */

#include "stellaris_lp_blink_rand_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  real_T RandomEverySample_NextOutput; /* '<Root>/Random Every Sample' */
  uint32_T RandSeed;                   /* '<Root>/Random Every Sample' */
  uint8_T Output;                      /* '<S1>/Output' */
  uint8_T Output_DSTATE;               /* '<S3>/Output' */
  uint8_T Output_DSTATE_n;             /* '<S6>/Output' */
} DW_stellaris_lp_blink_rand;

/* Parameters (auto storage) */
struct P_stellaris_lp_blink_rand_ {
  uint8_T RandomEveryBuild_OutValues[5];/* Mask Parameter: RandomEveryBuild_OutValues
                                         * Referenced by: '<S2>/Vector'
                                         */
  uint8_T NotRAND_OutValues[5];        /* Mask Parameter: NotRAND_OutValues
                                        * Referenced by: '<S1>/Vector'
                                        */
  uint8_T LimitedCounter_uplimit;      /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S8>/FixPt Switch'
                                        */
  uint8_T LimitedCounter_uplimit_e;    /* Mask Parameter: LimitedCounter_uplimit_e
                                        * Referenced by: '<S5>/FixPt Switch'
                                        */
  real_T RandomEverySample_Minimum;    /* Expression: 0
                                        * Referenced by: '<Root>/Random Every Sample'
                                        */
  real_T RandomEverySample_Maximum;    /* Expression: 16
                                        * Referenced by: '<Root>/Random Every Sample'
                                        */
  real_T RandomEverySample_Seed;       /* Expression: 0
                                        * Referenced by: '<Root>/Random Every Sample'
                                        */
  uint32_T GPIOWrite_p1;               /* Computed Parameter: GPIOWrite_p1
                                        * Referenced by: '<Root>/GPIO Write'
                                        */
  uint32_T GPIOSetup_p1;               /* Computed Parameter: GPIOSetup_p1
                                        * Referenced by: '<Root>/GPIO Setup'
                                        */
  uint32_T GPIOSetup_p2;               /* Computed Parameter: GPIOSetup_p2
                                        * Referenced by: '<Root>/GPIO Setup'
                                        */
  uint8_T RandomStyleSwitch1_CurrentSetti;/* Computed Parameter: RandomStyleSwitch1_CurrentSetti
                                           * Referenced by: '<Root>/Random Style Switch1'
                                           */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S5>/Constant'
                                        */
  uint8_T Constant_Value_j;            /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S8>/Constant'
                                        */
  uint8_T Output_InitialCondition;     /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S3>/Output'
                                        */
  uint8_T Output_InitialCondition_i;   /* Computed Parameter: Output_InitialCondition_i
                                        * Referenced by: '<S6>/Output'
                                        */
  uint8_T RandomStyleSwitch_CurrentSettin;/* Computed Parameter: RandomStyleSwitch_CurrentSettin
                                           * Referenced by: '<Root>/Random Style Switch'
                                           */
  uint8_T REDLED_Value;                /* Computed Parameter: REDLED_Value
                                        * Referenced by: '<Root>/RED LED'
                                        */
  uint8_T BLUELED_Value;               /* Computed Parameter: BLUELED_Value
                                        * Referenced by: '<Root>/BLUE LED'
                                        */
  uint8_T GREENLED_Value;              /* Computed Parameter: GREENLED_Value
                                        * Referenced by: '<Root>/GREEN LED'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S7>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_b;       /* Computed Parameter: FixPtConstant_Value_b
                                        * Referenced by: '<S4>/FixPt Constant'
                                        */
  uint8_T GPIOSetup_p3;                /* Computed Parameter: GPIOSetup_p3
                                        * Referenced by: '<Root>/GPIO Setup'
                                        */
  uint8_T GPIOSetup_p4;                /* Computed Parameter: GPIOSetup_p4
                                        * Referenced by: '<Root>/GPIO Setup'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_stellaris_lp_blink_rand {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_stellaris_lp_blink_rand stellaris_lp_blink_rand_P;

/* Block signals and states (auto storage) */
extern DW_stellaris_lp_blink_rand stellaris_lp_blink_rand_DW;

/* Model entry point functions */
extern void stellaris_lp_blink_rand_initialize(void);
extern void stellaris_lp_blink_rand_step(void);
extern void stellaris_lp_blink_rand_terminate(void);

/* Real-time Model object */
extern RT_MODEL_stellaris_lp_blink_ran *const stellaris_lp_blink_rand_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Propagation' : Unused code path elimination
 * Block '<S4>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S6>/Data Type Propagation' : Unused code path elimination
 * Block '<S7>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S1>/Out' : Eliminate redundant signal conversion block
 * Block '<S2>/Out' : Eliminate redundant signal conversion block
 */

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
 * '<Root>' : 'stellaris_lp_blink_rand'
 * '<S1>'   : 'stellaris_lp_blink_rand/Not RAND'
 * '<S2>'   : 'stellaris_lp_blink_rand/Random Every Build'
 * '<S3>'   : 'stellaris_lp_blink_rand/Not RAND/LimitedCounter'
 * '<S4>'   : 'stellaris_lp_blink_rand/Not RAND/LimitedCounter/Increment Real World'
 * '<S5>'   : 'stellaris_lp_blink_rand/Not RAND/LimitedCounter/Wrap To Zero'
 * '<S6>'   : 'stellaris_lp_blink_rand/Random Every Build/LimitedCounter'
 * '<S7>'   : 'stellaris_lp_blink_rand/Random Every Build/LimitedCounter/Increment Real World'
 * '<S8>'   : 'stellaris_lp_blink_rand/Random Every Build/LimitedCounter/Wrap To Zero'
 */

/*-
 * Requirements for '<Root>': stellaris_lp_blink_rand
 */
#endif                                 /* RTW_HEADER_stellaris_lp_blink_rand_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
