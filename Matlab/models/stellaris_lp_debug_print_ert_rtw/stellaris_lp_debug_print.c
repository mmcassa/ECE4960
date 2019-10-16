/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stellaris_lp_debug_print.c
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

#include "stellaris_lp_debug_print.h"
#include "stellaris_lp_debug_print_private.h"

/* Model step function */
void stellaris_lp_debug_print_step(void)
{
  boolean_T rtb_LogicalOperator;
  uint8_T rtb_ButtonsRead_o2;
  uint16_T rtb_Gain;

  /* S-Function (stellaris_lp_sfunc_Buttons): '<Root>/Buttons Read' */
  rtb_ButtonsRead_o2 = ButtonsRead(&rtb_ButtonsRead_o2);

  /* Gain: '<Root>/Gain' incorporates:
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator1'
   *  S-Function (stellaris_lp_sfunc_Buttons): '<Root>/Buttons Read'
   */
  rtb_Gain = (uint16_T)(((uint32_T)((int32_T)(((int32_T)rtb_ButtonsRead_o2) &
    ((int32_T)stellaris_lp_debug_print_P.BitwiseOperator1_BitMask)))) *
                        ((uint32_T)stellaris_lp_debug_print_P.Gain_Gain));

  /* S-Function (sfix_bitop): '<Root>/Bitwise Operator2' incorporates:
   *  S-Function (stellaris_lp_sfunc_Buttons): '<Root>/Buttons Read'
   */
  rtb_ButtonsRead_o2 &= stellaris_lp_debug_print_P.BitwiseOperator2_BitMask;

  /* Logic: '<Root>/Logical Operator' */
  rtb_LogicalOperator = ((((int32_T)rtb_Gain) != 0) && (((int32_T)
    rtb_ButtonsRead_o2) != 0));

  /* S-Function (stellaris_lp_sfunc_DebugPrint): '<Root>/Debug Print' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   */
  DebugPrint(stellaris_lp_debug_print_P.DebugPrint_p1, (int32_T)((uint32_T)
              (((uint32_T)rtb_Gain) >> 11)), (int32_T)rtb_ButtonsRead_o2,
             (int32_T)rtb_LogicalOperator, 0);

  /* S-Function (stellaris_lp_sfunc_GPIOWrite): '<Root>/GPIO Write' incorporates:
   *  Constant: '<Root>/BLUE LED'
   *  Constant: '<Root>/GREEN LED'
   *  Constant: '<Root>/RED LED'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain3'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator'
   *  S-Function (sfix_bitop): '<Root>/Bitwise Operator3'
   */
  GPIOWrite(stellaris_lp_debug_print_P.GPIOWrite_p1, (uint8_T)
            ((stellaris_lp_debug_print_P.REDLED_Value |
              stellaris_lp_debug_print_P.BLUELED_Value) |
             stellaris_lp_debug_print_P.GREENLED_Value), (uint8_T)(((uint8_T)
              (((uint8_T)((((uint32_T)stellaris_lp_debug_print_P.Gain1_Gain) *
    ((uint32_T)rtb_Gain)) >> 25)) | ((uint8_T)((((uint32_T)
    stellaris_lp_debug_print_P.Gain2_Gain) * ((uint32_T)rtb_ButtonsRead_o2)) >>
    5)))) | ((uint8_T)((int32_T)(rtb_LogicalOperator ? ((int32_T)((uint32_T)
    (((uint32_T)stellaris_lp_debug_print_P.Gain3_Gain) >> 4))) : 0)))));

  /* S-Function (stellaris_lp_sfunc_GPIOSetup): '<Root>/GPIO Setup' */
  GPIOVoidFunc();
}

/* Model initialize function */
void stellaris_lp_debug_print_initialize(void)
{
  /* Start for S-Function (stellaris_lp_sfunc_Buttons): '<Root>/Buttons Read' */
  ButtonsInit();

  /* Start for S-Function (stellaris_lp_sfunc_GPIOSetup): '<Root>/GPIO Setup' */
  GPIOSetup(stellaris_lp_debug_print_P.GPIOSetup_p1,
            stellaris_lp_debug_print_P.GPIOSetup_p2,
            stellaris_lp_debug_print_P.GPIOSetup_p3,
            stellaris_lp_debug_print_P.GPIOSetup_p4);
}

/* Model terminate function */
void stellaris_lp_debug_print_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
