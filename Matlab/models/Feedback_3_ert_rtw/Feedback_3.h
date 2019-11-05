/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Feedback_3.h
 *
 * Code generated for Simulink model 'Feedback_3'.
 *
 * Model version                  : 1.117
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Oct 31 18:58:25 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Feedback_3_h_
#define RTW_HEADER_Feedback_3_h_
#include <string.h>
#include <math.h>
#include <stddef.h>
#ifndef Feedback_3_COMMON_INCLUDES_
# define Feedback_3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "lct_wrapper.h"
#include "xdatapacket.h"
#include "gpiolct.h"
#endif                                 /* Feedback_3_COMMON_INCLUDES_ */

#include "Feedback_3_types.h"

/* Shared type includes */
#include "multiword_types.h"
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

/* Block signals (auto storage) */
typedef struct {
  real_T Gain5;                        /* '<Root>/Gain5' */
  real_T Gain6;                        /* '<Root>/Gain6' */
  real_T ContollerGain;                /* '<S9>/Contoller Gain' */
  real_T Gain4;                        /* '<Root>/Gain4' */
  real_T ContollerGain_c;              /* '<S10>/Contoller Gain' */
  real_T Gain2_p;                      /* '<Root>/Gain2' */
  real_T DiscreteTransferFcn_tmp;
  int32_T DataTypeConversion3;         /* '<S7>/Data Type Conversion3' */
  int32_T DataTypeConversion1;         /* '<S7>/Data Type Conversion1' */
  int32_T DataTypeConversion2;         /* '<S7>/Data Type Conversion2' */
  int32_T DataTypeConversion6;         /* '<Root>/Data Type Conversion6' */
  int32_T DataTypeConversion8;         /* '<Root>/Data Type Conversion8' */
  int32_T DataTypeConversion9;         /* '<Root>/Data Type Conversion9' */
  int32_T DataTypeConversion10;        /* '<Root>/Data Type Conversion10' */
  uint8_T BytePack[12];                /* '<S7>/Byte Pack' */
  uint8_T Unpack;                      /* '<S7>/Unpack' */
  uint8_T In1;                         /* '<S13>/In1' */
} B_Feedback_3_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTransferFcn_states;   /* '<S16>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_f; /* '<S18>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_b; /* '<S14>/Discrete Transfer Fcn' */
  real_T output;                       /* '<S7>/MATLAB Function' */
  int32_T val;                         /* '<S7>/MATLAB Function' */
  int_T Unpack_IWORK[2];               /* '<S7>/Unpack' */
} DW_Feedback_3_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
  real_T Out2;                         /* '<Root>/Out2' */
  real_T Out3;                         /* '<Root>/Out3' */
  real_T Out4;                         /* '<Root>/Out4' */
  real_T Out5;                         /* '<Root>/Out5' */
  real_T Out6;                         /* '<Root>/Out6' */
  real_T Out7;                         /* '<Root>/Out7' */
  real_T Out8;                         /* '<Root>/Out8' */
  real_T Out9;                         /* '<Root>/Out9' */
  int32_T Out10;                       /* '<Root>/Out10' */
} ExtY_Feedback_3_T;

/* Parameters (auto storage) */
struct P_Feedback_3_T_ {
  real_T CurrentOffset_Value;          /* Expression: 0
                                        * Referenced by: '<S10>/Current Offset'
                                        */
  real_T DCIGain_Gain;                 /* Expression: 100*10.1/3.3
                                        * Referenced by: '<S10>/DC//I Gain'
                                        */
  real_T TemperatureNormalization_Gain;/* Expression: 1
                                        * Referenced by: '<S10>/Temperature  Normalization'
                                        */
  real_T DutyCycleSaturation_UpperSat; /* Expression: 99
                                        * Referenced by: '<S10>/Duty Cycle Saturation'
                                        */
  real_T DutyCycleSaturation_LowerSat; /* Expression: 0
                                        * Referenced by: '<S10>/Duty Cycle Saturation'
                                        */
  real_T Constant5_Value;              /* Expression: 40
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T CurrentOffset_Value_o;        /* Expression: 0
                                        * Referenced by: '<S9>/Current Offset'
                                        */
  real_T DCIGain_Gain_k;               /* Expression: 100*10.1/3.3
                                        * Referenced by: '<S9>/DC//I Gain'
                                        */
  real_T TemperatureNormalization_Gain_h;/* Expression: 1
                                          * Referenced by: '<S9>/Temperature  Normalization'
                                          */
  real_T DutyCycleSaturation_UpperSat_a;/* Expression: 99
                                         * Referenced by: '<S9>/Duty Cycle Saturation'
                                         */
  real_T DutyCycleSaturation_LowerSat_n;/* Expression: 0
                                         * Referenced by: '<S9>/Duty Cycle Saturation'
                                         */
  real_T Constant4_Value;              /* Expression: 40
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T CurrentOffset_Value_p;        /* Expression: 0
                                        * Referenced by: '<S8>/Current Offset'
                                        */
  real_T DCIGain_Gain_i;               /* Expression: 100*10.1/3.3
                                        * Referenced by: '<S8>/DC//I Gain'
                                        */
  real_T TemperatureNormalization_Gain_p;/* Expression: 1
                                          * Referenced by: '<S8>/Temperature  Normalization'
                                          */
  real_T DutyCycleSaturation_UpperSat_f;/* Expression: 99
                                         * Referenced by: '<S8>/Duty Cycle Saturation'
                                         */
  real_T DutyCycleSaturation_LowerSat_c;/* Expression: 0
                                         * Referenced by: '<S8>/Duty Cycle Saturation'
                                         */
  real_T Constant3_Value;              /* Expression: 40
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant_Value;               /* Expression: 0.0006
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: 1.1611 * 10^-3
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1.63 * 10^-3
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: .005
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1000000
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real_T Constant1_Value_j;            /* Expression: 0.11
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T ContollerGain_Gain;           /* Expression: 5300
                                        * Referenced by: '<S9>/Contoller Gain'
                                        */
  real_T DiscreteTransferFcn_NumCoef[2];/* Expression: numd
                                         * Referenced by: '<S16>/Discrete Transfer Fcn'
                                         */
  real_T DiscreteTransferFcn_DenCoef[2];/* Expression: dend
                                         * Referenced by: '<S16>/Discrete Transfer Fcn'
                                         */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<S16>/Discrete Transfer Fcn'
                                          */
  real_T Gain3_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S9>/Gain3'
                                        */
  real_T Constant_Value_i;             /* Expression: 1.1611 * 10^-3
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant1_Value_p;            /* Expression: 2.1 * 10^-3
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Saturation_UpperSat_n;        /* Expression: .005
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: 0
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: 1000
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: 1000000
                                        * Referenced by: '<S10>/Gain2'
                                        */
  real_T ContollerGain_Gain_m;         /* Expression: 5300
                                        * Referenced by: '<S10>/Contoller Gain'
                                        */
  real_T DiscreteTransferFcn_NumCoef_p[2];/* Expression: numd
                                           * Referenced by: '<S18>/Discrete Transfer Fcn'
                                           */
  real_T DiscreteTransferFcn_DenCoef_e[2];/* Expression: dend
                                           * Referenced by: '<S18>/Discrete Transfer Fcn'
                                           */
  real_T DiscreteTransferFcn_InitialSt_f;/* Expression: 0
                                          * Referenced by: '<S18>/Discrete Transfer Fcn'
                                          */
  real_T Gain3_Gain_o;                 /* Expression: 1000
                                        * Referenced by: '<S10>/Gain3'
                                        */
  real_T Constant_Value_b;             /* Expression: 1.1611 * 10^-3
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant1_Value_i;            /* Expression: 1.49 * 10^-3
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Saturation_UpperSat_c;        /* Expression: .005
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation_LowerSat_i;        /* Expression: 0
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: 1000
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Gain2_Gain_l;                 /* Expression: 1000000
                                        * Referenced by: '<S8>/Gain2'
                                        */
  real_T ContollerGain_Gain_e;         /* Expression: 5300
                                        * Referenced by: '<S8>/Contoller Gain'
                                        */
  real_T DiscreteTransferFcn_NumCoef_e[2];/* Expression: numd
                                           * Referenced by: '<S14>/Discrete Transfer Fcn'
                                           */
  real_T DiscreteTransferFcn_DenCoef_h[2];/* Expression: dend
                                           * Referenced by: '<S14>/Discrete Transfer Fcn'
                                           */
  real_T DiscreteTransferFcn_InitialSt_b;/* Expression: 0
                                          * Referenced by: '<S14>/Discrete Transfer Fcn'
                                          */
  real_T Gain3_Gain_b;                 /* Expression: 1000
                                        * Referenced by: '<S8>/Gain3'
                                        */
  real_T Gain_Gain;                    /* Expression: 10000
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 10000
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain2_Gain_n;                 /* Expression: 10000
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1000000
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1000000
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1000000
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T Gain3_Gain_n;                 /* Expression: 1
                                        * Referenced by: '<Root>/Gain3'
                                        */
  int32_T ADRaw2_p1;                   /* Computed Parameter: ADRaw2_p1
                                        * Referenced by: '<Root>/AD Raw2'
                                        */
  int32_T ADRaw1_p1;                   /* Computed Parameter: ADRaw1_p1
                                        * Referenced by: '<Root>/AD Raw1'
                                        */
  int32_T ADRaw3_p1;                   /* Computed Parameter: ADRaw3_p1
                                        * Referenced by: '<Root>/AD Raw3'
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
  int32_T XComInit_p1;                 /* Computed Parameter: XComInit_p1
                                        * Referenced by: '<S7>/XComInit'
                                        */
  int32_T ADRaw1_p1_f;                 /* Computed Parameter: ADRaw1_p1_f
                                        * Referenced by: '<S15>/AD Raw1'
                                        */
  int32_T ADRaw1_p1_a;                 /* Computed Parameter: ADRaw1_p1_a
                                        * Referenced by: '<S17>/AD Raw1'
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
                                        * Referenced by: '<S7>/GPIO Write'
                                        */
  uint32_T GPIOSetup_p1;               /* Computed Parameter: GPIOSetup_p1
                                        * Referenced by: '<S7>/GPIO Setup'
                                        */
  uint32_T GPIOSetup_p2;               /* Computed Parameter: GPIOSetup_p2
                                        * Referenced by: '<S7>/GPIO Setup'
                                        */
  uint32_T Gain_Gain_k;                /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S6>/Gain'
                                        */
  uint32_T Gain_Gain_i;                /* Computed Parameter: Gain_Gain_i
                                        * Referenced by: '<S5>/Gain'
                                        */
  uint32_T Gain_Gain_g;                /* Computed Parameter: Gain_Gain_g
                                        * Referenced by: '<S4>/Gain'
                                        */
  uint8_T RedLEDOn2_Value;             /* Computed Parameter: RedLEDOn2_Value
                                        * Referenced by: '<S7>/Red LED On2'
                                        */
  uint8_T RedLEDOn1_Value;             /* Computed Parameter: RedLEDOn1_Value
                                        * Referenced by: '<S7>/Red LED On1'
                                        */
  uint8_T RedLEDOn_Value;              /* Computed Parameter: RedLEDOn_Value
                                        * Referenced by: '<S7>/Red LED On'
                                        */
  uint8_T Out1_Y0;                     /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S13>/Out1'
                                        */
  uint8_T Constant_Value_m;            /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S7>/Constant'
                                        */
  uint8_T RedLEDOff_Value;             /* Computed Parameter: RedLEDOff_Value
                                        * Referenced by: '<S7>/Red LED Off'
                                        */
  uint8_T DebugPrint_p1[35];           /* Expression: [uint8(fmt), 13,10, 0]
                                        * Referenced by: '<Root>/Debug Print'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  uint8_T ManualSwitch2_CurrentSetting;/* Computed Parameter: ManualSwitch2_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch2'
                                        */
  uint8_T ManualSwitch1_CurrentSetting;/* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch1'
                                        */
  uint8_T REDLED_Value;                /* Computed Parameter: REDLED_Value
                                        * Referenced by: '<S7>/RED LED'
                                        */
  uint8_T GPIOSetup_p3;                /* Computed Parameter: GPIOSetup_p3
                                        * Referenced by: '<S7>/GPIO Setup'
                                        */
  uint8_T GPIOSetup_p4;                /* Computed Parameter: GPIOSetup_p4
                                        * Referenced by: '<S7>/GPIO Setup'
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
      uint16_T TID[5];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Feedback_3_T Feedback_3_P;

/* Block signals (auto storage) */
extern B_Feedback_3_T Feedback_3_B;

/* Block states (auto storage) */
extern DW_Feedback_3_T Feedback_3_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Feedback_3_T Feedback_3_Y;

/* External function called from main */
extern void Feedback_3_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Feedback_3_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Feedback_3_initialize(void);
extern void Feedback_3_step0(void);
extern void Feedback_3_step1(void);
extern void Feedback_3_step2(void);
extern void Feedback_3_step3(void);
extern void Feedback_3_step4(void);
extern void Feedback_3_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Feedback_3_T *const Feedback_3_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S15>/Data Type Conversion' : Unused code path elimination
 * Block '<S15>/ToVolt' : Unused code path elimination
 * Block '<S17>/Data Type Conversion' : Unused code path elimination
 * Block '<S17>/ToVolt' : Unused code path elimination
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion3' : Eliminate redundant data type conversion
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
 * '<Root>' : 'Feedback_3'
 * '<S1>'   : 'Feedback_3/PWM Output'
 * '<S2>'   : 'Feedback_3/PWM Output1'
 * '<S3>'   : 'Feedback_3/PWM Output2'
 * '<S4>'   : 'Feedback_3/Sensor 1 Position Conversion'
 * '<S5>'   : 'Feedback_3/Sensor 2 Position Conversion'
 * '<S6>'   : 'Feedback_3/Sensor 3 Position Conversion'
 * '<S7>'   : 'Feedback_3/Subsystem'
 * '<S8>'   : 'Feedback_3/Subsystem1'
 * '<S9>'   : 'Feedback_3/Subsystem2'
 * '<S10>'  : 'Feedback_3/Subsystem3'
 * '<S11>'  : 'Feedback_3/Subsystem/MATLAB Function'
 * '<S12>'  : 'Feedback_3/Subsystem/XComRecv'
 * '<S13>'  : 'Feedback_3/Subsystem/XComRecv/Enabled Subsystem'
 * '<S14>'  : 'Feedback_3/Subsystem1/Lead Compensator'
 * '<S15>'  : 'Feedback_3/Subsystem2/AD Volt'
 * '<S16>'  : 'Feedback_3/Subsystem2/Lead Compensator'
 * '<S17>'  : 'Feedback_3/Subsystem3/AD Volt'
 * '<S18>'  : 'Feedback_3/Subsystem3/Lead Compensator'
 */
#endif                                 /* RTW_HEADER_Feedback_3_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
