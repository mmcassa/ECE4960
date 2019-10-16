/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stellaris_lp_debug_print.h
 *
 * Code generated for Simulink model 'stellaris_lp_debug_print'.
 *
 * Model version                  : 1.84
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Sep 11 18:39:54 2019
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

#ifndef RTW_HEADER_stellaris_lp_debug_print_h_
#define RTW_HEADER_stellaris_lp_debug_print_h_
#ifndef stellaris_lp_debug_print_COMMON_INCLUDES_
# define stellaris_lp_debug_print_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "buttonslct.h"
#include "lct_wrapper.h"
#include "gpiolct.h"
#endif                                 /* stellaris_lp_debug_print_COMMON_INCLUDES_ */

#include "stellaris_lp_debug_print_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */

/* Parameters (auto storage) */
struct P_stellaris_lp_debug_print_ {
  uint8_T BitwiseOperator1_BitMask;    /* Mask Parameter: BitwiseOperator1_BitMask
                                        * Referenced by: '<Root>/Bitwise Operator1'
                                        */
  uint8_T BitwiseOperator2_BitMask;    /* Mask Parameter: BitwiseOperator2_BitMask
                                        * Referenced by: '<Root>/Bitwise Operator2'
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
  uint16_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  uint8_T DebugPrint_p1[32];           /* Expression: [uint8(fmt), 13,10, 0]
                                        * Referenced by: '<Root>/Debug Print'
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
  uint8_T GPIOSetup_p3;                /* Computed Parameter: GPIOSetup_p3
                                        * Referenced by: '<Root>/GPIO Setup'
                                        */
  uint8_T GPIOSetup_p4;                /* Computed Parameter: GPIOSetup_p4
                                        * Referenced by: '<Root>/GPIO Setup'
                                        */
  uint8_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  uint8_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
  uint8_T Gain3_Gain;                  /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<Root>/Gain3'
                                        */
};

/* Block parameters (auto storage) */
extern P_stellaris_lp_debug_print stellaris_lp_debug_print_P;

/* Model entry point functions */
extern void stellaris_lp_debug_print_initialize(void);
extern void stellaris_lp_debug_print_step(void);
extern void stellaris_lp_debug_print_terminate(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion4' : Eliminate redundant data type conversion
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
 * '<Root>' : 'stellaris_lp_debug_print'
 */

/*-
 * Requirements for '<Root>': stellaris_lp_debug_print
 */
#endif                                 /* RTW_HEADER_stellaris_lp_debug_print_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
