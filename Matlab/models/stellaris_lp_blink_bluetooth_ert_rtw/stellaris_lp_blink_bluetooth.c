/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stellaris_lp_blink_bluetooth.c
 *
 * Code generated for Simulink model 'stellaris_lp_blink_bluetooth'.
 *
 * Model version                  : 1.91
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Oct 16 20:19:09 2019
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

#include "stellaris_lp_blink_bluetooth.h"
#include "stellaris_lp_blink_bluetooth_private.h"

/* Block signals and states (auto storage) */
DW_stellaris_lp_blink_bluetooth stellaris_lp_blink_bluetooth_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_stellaris_lp_blink_bluetoo stellaris_lp_blink_bluetooth_Y;

/* Real-time model */
RT_MODEL_stellaris_lp_blink_blu stellaris_lp_blink_bluetooth_M_;
RT_MODEL_stellaris_lp_blink_blu *const stellaris_lp_blink_bluetooth_M =
  &stellaris_lp_blink_bluetooth_M_;
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
  (stellaris_lp_blink_bluetooth_M->Timing.TaskCounters.TID[1])++;
  if ((stellaris_lp_blink_bluetooth_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.001s, 0.0s] */
    stellaris_lp_blink_bluetooth_M->Timing.TaskCounters.TID[1] = 0;
  }

  (stellaris_lp_blink_bluetooth_M->Timing.TaskCounters.TID[2])++;
  if ((stellaris_lp_blink_bluetooth_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.01s, 0.0s] */
    stellaris_lp_blink_bluetooth_M->Timing.TaskCounters.TID[2] = 0;
  }

  (stellaris_lp_blink_bluetooth_M->Timing.TaskCounters.TID[3])++;
  if ((stellaris_lp_blink_bluetooth_M->Timing.TaskCounters.TID[3]) > 1999) {/* Sample time: [0.2s, 0.0s] */
    stellaris_lp_blink_bluetooth_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/* Model step function */
void stellaris_lp_blink_bluetooth_step(void)
{
  int32_T tmp;
  uint32_T rtb_ADRaw1;
  uint8_T rtb_MultiportSwitch;
  uint8_T rtb_SFunction_o1;
  if (stellaris_lp_blink_bluetooth_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (stellaris_lp_sfunc_ADCRead): '<Root>/AD Raw1' */
    tmp = ADCRead(stellaris_lp_blink_bluetooth_P.ADRaw1_p1);
    rtb_ADRaw1 = (uint32_T)tmp;

    /* DataTypeConversion: '<Root>/Data Type Conversion3' */
    stellaris_lp_blink_bluetooth_DW.DataTypeConversion3 = (int32_T)rtb_ADRaw1;

    /* S-Function (any2byte): '<Root>/Byte Pack' */

    /* Pack: <Root>/Byte Pack */
    (void) memcpy(&stellaris_lp_blink_bluetooth_DW.BytePack[0],
                  &stellaris_lp_blink_bluetooth_DW.DataTypeConversion3,
                  4);
  }

  if (stellaris_lp_blink_bluetooth_M->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (stellaris_lp_sfunc_XDataPackout): '<Root>/XComSend' */
    rtb_MultiportSwitch = xdatapacket_put(4,
      stellaris_lp_blink_bluetooth_DW.BytePack);

    /* Outport: '<Root>/Out1' incorporates:
     *  S-Function (stellaris_lp_sfunc_XDataPackout): '<Root>/XComSend'
     */
    stellaris_lp_blink_bluetooth_Y.Out1 = (int32_T)rtb_MultiportSwitch;
  }

  if (stellaris_lp_blink_bluetooth_M->Timing.TaskCounters.TID[3] == 0) {
    /* S-Function (stellaris_lp_sfunc_XDataPackin): '<S1>/S-Function' incorporates:
     *  Inport: '<S2>/In1'
     */
    rtb_MultiportSwitch = xdatapacket_get(1, &rtb_SFunction_o1);

    /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S2>/Enable'
     */
    if (((int32_T)rtb_MultiportSwitch) > 0) {
      stellaris_lp_blink_bluetooth_DW.In1 = rtb_SFunction_o1;
    }

    /* End of S-Function (stellaris_lp_sfunc_XDataPackin): '<S1>/S-Function' */
    /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem' */

    /* S-Function (xpcbytepacking): '<Root>/Unpack' */

    /* Byte Unpacking: <Root>/Unpack */
    (void)memcpy((uint8_T*)&stellaris_lp_blink_bluetooth_DW.Unpack, (uint8_T*)
                 &stellaris_lp_blink_bluetooth_DW.In1 + 0, 1);

    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    stellaris_lp_blink_bluetooth_DW.DataTypeConversion1 = (int32_T)
      stellaris_lp_blink_bluetooth_DW.Unpack;

    /* Sum: '<Root>/Subtract' incorporates:
     *  Constant: '<Root>/Constant'
     */
    stellaris_lp_blink_bluetooth_DW.Subtract = (uint8_T)
      (stellaris_lp_blink_bluetooth_DW.Unpack -
       stellaris_lp_blink_bluetooth_P.Constant_Value);

    /* DataTypeConversion: '<Root>/Data Type Conversion2' */
    stellaris_lp_blink_bluetooth_DW.DataTypeConversion2 = (int32_T)
      stellaris_lp_blink_bluetooth_DW.Subtract;
  }

  if (stellaris_lp_blink_bluetooth_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (stellaris_lp_sfunc_DebugPrint): '<Root>/Debug Print' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion4'
     */
    DebugPrint(stellaris_lp_blink_bluetooth_P.DebugPrint_p1,
               stellaris_lp_blink_bluetooth_DW.DataTypeConversion1,
               stellaris_lp_blink_bluetooth_DW.DataTypeConversion2, (int32_T)
               rtb_ADRaw1, 0);
  }

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<Root>/Red LED Off'
   *  Constant: '<Root>/Red LED On'
   *  Memory: '<Root>/Memory'
   */
  switch (stellaris_lp_blink_bluetooth_DW.Subtract) {
   case 0:
    rtb_MultiportSwitch = stellaris_lp_blink_bluetooth_P.RedLEDOff_Value;
    break;

   case 1:
    rtb_MultiportSwitch = stellaris_lp_blink_bluetooth_P.RedLEDOn_Value;
    break;

   default:
    rtb_MultiportSwitch = stellaris_lp_blink_bluetooth_DW.Memory_PreviousInput;
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* S-Function (stellaris_lp_sfunc_GPIOWrite): '<Root>/GPIO Write' incorporates:
   *  Constant: '<Root>/RED LED'
   */
  GPIOWrite(stellaris_lp_blink_bluetooth_P.GPIOWrite_p1,
            stellaris_lp_blink_bluetooth_P.REDLED_Value, rtb_MultiportSwitch);

  /* S-Function (stellaris_lp_sfunc_GPIOSetup): '<Root>/GPIO Setup' */
  GPIOVoidFunc();

  /* S-Function (stellaris_lp_sfunc_XDataInit): '<Root>/XComInit' */
  init_xdatapacket_void();

  /* Update for Memory: '<Root>/Memory' */
  stellaris_lp_blink_bluetooth_DW.Memory_PreviousInput = rtb_MultiportSwitch;
  rate_scheduler();
}

/* Model initialize function */
void stellaris_lp_blink_bluetooth_initialize(void)
{
  /* Start for S-Function (stellaris_lp_sfunc_GPIOSetup): '<Root>/GPIO Setup' */
  GPIOSetup(stellaris_lp_blink_bluetooth_P.GPIOSetup_p1,
            stellaris_lp_blink_bluetooth_P.GPIOSetup_p2,
            stellaris_lp_blink_bluetooth_P.GPIOSetup_p3,
            stellaris_lp_blink_bluetooth_P.GPIOSetup_p4);

  /* Start for S-Function (stellaris_lp_sfunc_XDataInit): '<Root>/XComInit' */
  init_xdatapacket(stellaris_lp_blink_bluetooth_P.XComInit_p1);

  /* InitializeConditions for Memory: '<Root>/Memory' */
  stellaris_lp_blink_bluetooth_DW.Memory_PreviousInput =
    stellaris_lp_blink_bluetooth_P.Memory_InitialCondition;

  /* SystemInitialize for Enabled SubSystem: '<S1>/Enabled Subsystem' */
  /* SystemInitialize for Outport: '<S2>/Out1' */
  stellaris_lp_blink_bluetooth_DW.In1 = stellaris_lp_blink_bluetooth_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/Enabled Subsystem' */
}

/* Model terminate function */
void stellaris_lp_blink_bluetooth_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
