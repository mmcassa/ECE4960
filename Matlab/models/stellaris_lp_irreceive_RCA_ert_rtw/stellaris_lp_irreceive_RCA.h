/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stellaris_lp_irreceive_RCA.h
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

#ifndef RTW_HEADER_stellaris_lp_irreceive_RCA_h_
#define RTW_HEADER_stellaris_lp_irreceive_RCA_h_
#ifndef stellaris_lp_irreceive_RCA_COMMON_INCLUDES_
# define stellaris_lp_irreceive_RCA_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "gpiolct.h"
#include "lct_wrapper.h"
#endif                                 /* stellaris_lp_irreceive_RCA_COMMON_INCLUDES_ */

#include "stellaris_lp_irreceive_RCA_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  int32_T RateTransition;              /* '<S6>/Rate Transition' */
  int32_T RateTransition1;             /* '<S6>/Rate Transition1' */
  int32_T In1;                         /* '<S5>/In1' */
  int32_T frame;                       /* '<Root>/BitDecoder' */
  int32_T nb;                          /* '<Root>/BitDecoder' */
  uint8_T is_active_c1_stellaris_lp_irrec;/* '<Root>/BitDecoder' */
  uint8_T is_c1_stellaris_lp_irreceive_RC;/* '<Root>/BitDecoder' */
  uint8_T temporalCounter_i1;          /* '<Root>/BitDecoder' */
} DW_stellaris_lp_irreceive_RCA;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Latch_Trig_ZCE;           /* '<Root>/Latch' */
} PrevZCX_stellaris_lp_irreceive_;

/* Parameters (auto storage) */
struct P_stellaris_lp_irreceive_RCA_ {
  int32_T BitwiseOperator_BitMask;     /* Mask Parameter: BitwiseOperator_BitMask
                                        * Referenced by: '<S6>/Bitwise Operator'
                                        */
  int32_T BitwiseOperator1_BitMask;    /* Mask Parameter: BitwiseOperator1_BitMask
                                        * Referenced by: '<S6>/Bitwise Operator1'
                                        */
  int32_T BitwiseOperator2_BitMask;    /* Mask Parameter: BitwiseOperator2_BitMask
                                        * Referenced by: '<S6>/Bitwise Operator2'
                                        */
  int32_T FrameDataValid_const;        /* Mask Parameter: FrameDataValid_const
                                        * Referenced by: '<S2>/Constant'
                                        */
  uint8_T BitwiseOperator_BitMask_i;   /* Mask Parameter: BitwiseOperator_BitMask_i
                                        * Referenced by: '<S3>/Bitwise Operator'
                                        */
  int32_T Out1_Y0;                     /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S5>/Out1'
                                        */
  uint32_T GPIORead_p1;                /* Computed Parameter: GPIORead_p1
                                        * Referenced by: '<S3>/GPIO Read'
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
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S4>/Constant'
                                        */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S3>/Constant1'
                                        */
  uint8_T GPIOSetup_p3;                /* Computed Parameter: GPIOSetup_p3
                                        * Referenced by: '<S4>/GPIO Setup'
                                        */
  uint8_T GPIOSetup_p4;                /* Computed Parameter: GPIOSetup_p4
                                        * Referenced by: '<S4>/GPIO Setup'
                                        */
  uint8_T DebugPrint_p1[41];           /* Expression: [uint8(fmt), 13,10, 0]
                                        * Referenced by: '<S6>/Debug Print'
                                        */
  uint8_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S4>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_stellaris_lp_irreceive_ {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_stellaris_lp_irreceive_RCA stellaris_lp_irreceive_RCA_P;

/* Block signals and states (auto storage) */
extern DW_stellaris_lp_irreceive_RCA stellaris_lp_irreceive_RCA_DW;

/* External function called from main */
extern void stellaris_lp_irreceive_RCA_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void stellaris_lp_irreceive_RCA_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void stellaris_lp_irreceive_RCA_initialize(void);
extern void stellaris_lp_irreceive_RCA_step0(void);
extern void stellaris_lp_irreceive_RCA_step1(void);
extern void stellaris_lp_irreceive_RCA_terminate(void);

/* Real-time Model object */
extern RT_MODEL_stellaris_lp_irreceive *const stellaris_lp_irreceive_RCA_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion' : Unused code path elimination
 * Block '<Root>/Debug Scope' : Unused code path elimination
 * Block '<S6>/Data Type Conversion1' : Eliminate redundant data type conversion
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
 * '<Root>' : 'stellaris_lp_irreceive_RCA'
 * '<S1>'   : 'stellaris_lp_irreceive_RCA/BitDecoder'
 * '<S2>'   : 'stellaris_lp_irreceive_RCA/Frame Data Valid'
 * '<S3>'   : 'stellaris_lp_irreceive_RCA/Ir Sensor'
 * '<S4>'   : 'stellaris_lp_irreceive_RCA/LED Data Indicator'
 * '<S5>'   : 'stellaris_lp_irreceive_RCA/Latch'
 * '<S6>'   : 'stellaris_lp_irreceive_RCA/Print Output'
 */

/*-
 * Requirements for '<Root>': stellaris_lp_irreceive_RCA
 */
#endif                                 /* RTW_HEADER_stellaris_lp_irreceive_RCA_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
