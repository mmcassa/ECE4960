/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: stellaris_lp_blink_bluetooth.h
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

#ifndef RTW_HEADER_stellaris_lp_blink_bluetooth_h_
#define RTW_HEADER_stellaris_lp_blink_bluetooth_h_
#include <string.h>
#ifndef stellaris_lp_blink_bluetooth_COMMON_INCLUDES_
# define stellaris_lp_blink_bluetooth_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "lct_wrapper.h"
#include "xdatapacket.h"
#include "gpiolct.h"
#endif                                 /* stellaris_lp_blink_bluetooth_COMMON_INCLUDES_ */

#include "stellaris_lp_blink_bluetooth_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  int_T Unpack_IWORK[2];               /* '<Root>/Unpack' */
  int32_T DataTypeConversion3;         /* '<Root>/Data Type Conversion3' */
  int32_T DataTypeConversion1;         /* '<Root>/Data Type Conversion1' */
  int32_T DataTypeConversion2;         /* '<Root>/Data Type Conversion2' */
  uint8_T BytePack[4];                 /* '<Root>/Byte Pack' */
  uint8_T Unpack;                      /* '<Root>/Unpack' */
  uint8_T Subtract;                    /* '<Root>/Subtract' */
  uint8_T In1;                         /* '<S2>/In1' */
  uint8_T Memory_PreviousInput;        /* '<Root>/Memory' */
} DW_stellaris_lp_blink_bluetooth;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  int32_T Out1;                        /* '<Root>/Out1' */
} ExtY_stellaris_lp_blink_bluetoo;

/* Parameters (auto storage) */
struct P_stellaris_lp_blink_bluetooth_ {
  int32_T ADRaw1_p1;                   /* Computed Parameter: ADRaw1_p1
                                        * Referenced by: '<Root>/AD Raw1'
                                        */
  int32_T XComInit_p1;                 /* Computed Parameter: XComInit_p1
                                        * Referenced by: '<Root>/XComInit'
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
  uint8_T RedLEDOn_Value;              /* Computed Parameter: RedLEDOn_Value
                                        * Referenced by: '<Root>/Red LED On'
                                        */
  uint8_T RedLEDOff_Value;             /* Computed Parameter: RedLEDOff_Value
                                        * Referenced by: '<Root>/Red LED Off'
                                        */
  uint8_T Out1_Y0;                     /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S2>/Out1'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
                                        */
  uint8_T DebugPrint_p1[51];           /* Expression: [uint8(fmt), 13,10, 0]
                                        * Referenced by: '<Root>/Debug Print'
                                        */
  uint8_T REDLED_Value;                /* Computed Parameter: REDLED_Value
                                        * Referenced by: '<Root>/RED LED'
                                        */
  uint8_T Memory_InitialCondition;     /* Computed Parameter: Memory_InitialCondition
                                        * Referenced by: '<Root>/Memory'
                                        */
  uint8_T GPIOSetup_p3;                /* Computed Parameter: GPIOSetup_p3
                                        * Referenced by: '<Root>/GPIO Setup'
                                        */
  uint8_T GPIOSetup_p4;                /* Computed Parameter: GPIOSetup_p4
                                        * Referenced by: '<Root>/GPIO Setup'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_stellaris_lp_blink_blue {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[4];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_stellaris_lp_blink_bluetooth stellaris_lp_blink_bluetooth_P;

/* Block signals and states (auto storage) */
extern DW_stellaris_lp_blink_bluetooth stellaris_lp_blink_bluetooth_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_stellaris_lp_blink_bluetoo stellaris_lp_blink_bluetooth_Y;

/* Model entry point functions */
extern void stellaris_lp_blink_bluetooth_initialize(void);
extern void stellaris_lp_blink_bluetooth_step(void);
extern void stellaris_lp_blink_bluetooth_terminate(void);

/* Real-time Model object */
extern RT_MODEL_stellaris_lp_blink_blu *const stellaris_lp_blink_bluetooth_M;

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
 * '<Root>' : 'stellaris_lp_blink_bluetooth'
 * '<S1>'   : 'stellaris_lp_blink_bluetooth/XComRecv'
 * '<S2>'   : 'stellaris_lp_blink_bluetooth/XComRecv/Enabled Subsystem'
 */

/*-
 * Requirements for '<Root>': stellaris_lp_blink_bluetooth
 */
#endif                                 /* RTW_HEADER_stellaris_lp_blink_bluetooth_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
