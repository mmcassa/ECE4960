/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mitchell_bluetooth.h
 *
 * Code generated for Simulink model 'mitchell_bluetooth'.
 *
 * Model version                  : 1.145
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Nov 14 20:47:44 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_mitchell_bluetooth_h_
#define RTW_HEADER_mitchell_bluetooth_h_
#include <string.h>
#include <math.h>
#include <stddef.h>
#ifndef mitchell_bluetooth_COMMON_INCLUDES_
# define mitchell_bluetooth_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "xdatapacket.h"
#include "lct_wrapper.h"
#include "gpiolct.h"
#endif                                 /* mitchell_bluetooth_COMMON_INCLUDES_ */

#include "mitchell_bluetooth_types.h"

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

/* Block signals (default storage) */
typedef struct {
  real_T ManualSwitch4;                /* '<Root>/Manual Switch4' */
  real_T ManualSwitch3;                /* '<Root>/Manual Switch3' */
  int32_T DataTypeConversion6;         /* '<Root>/Data Type Conversion6' */
  int32_T DataTypeConversion8;         /* '<Root>/Data Type Conversion8' */
  int32_T DataTypeConversion9;         /* '<Root>/Data Type Conversion9' */
  int32_T DataTypeConversion10;        /* '<Root>/Data Type Conversion10' */
  int32_T DataTypeConversion3;         /* '<S10>/Data Type Conversion3' */
  int32_T DataTypeConversion1;         /* '<S10>/Data Type Conversion1' */
  int32_T DataTypeConversion2;         /* '<S10>/Data Type Conversion2' */
  int32_T DataTypeConversion9_e;       /* '<S10>/Data Type Conversion9' */
  int32_T DataTypeConversion10_l;      /* '<S10>/Data Type Conversion10' */
  int32_T latch;                       /* '<S10>/MATLAB Function' */
  uint8_T Unpack;                      /* '<S10>/Unpack' */
  uint8_T BytePack[40];                /* '<S10>/Byte Pack' */
  real_T rateLimiterRate;
  real_T MultiportSwitch1_o;           /* '<Root>/Multiport Switch1' */
  real_T ContollerGain;                /* '<S12>/Contoller Gain' */
  uint8_T In1;                         /* '<S17>/In1' */
} B_mitchell_bluetooth_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTransferFcn_states;   /* '<S19>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_k; /* '<S20>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_states_b; /* '<S18>/Discrete Transfer Fcn' */
  real_T PrevY;                        /* '<Root>/Rate Limiter2' */
  real_T PrevY_c;                      /* '<Root>/Rate Limiter' */
  real_T PrevY_n;                      /* '<Root>/Rate Limiter1' */
  real_T output;                       /* '<S10>/MATLAB Function' */
  int32_T val;                         /* '<S10>/MATLAB Function' */
  int32_T latched;                     /* '<S10>/MATLAB Function' */
  int_T Unpack_IWORK[2];               /* '<S10>/Unpack' */
} DW_mitchell_bluetooth_T;

/* External outputs (root outports fed by signals with default storage) */
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
} ExtY_mitchell_bluetooth_T;

/* Parameters (default storage) */
struct P_mitchell_bluetooth_T_ {
  real_T CurrentOffset_Value;          /* Expression: 0
                                        * Referenced by: '<S13>/Current Offset'
                                        */
  real_T DCIGain_Gain;                 /* Expression: 100*1/3.3
                                        * Referenced by: '<S13>/DC//I Gain'
                                        */
  real_T TemperatureNormalization_Gain;/* Expression: 1
                                        * Referenced by: '<S13>/Temperature  Normalization'
                                        */
  real_T Constant8_Value;              /* Expression: 50
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T CurrentOffset_Value_p;        /* Expression: 0
                                        * Referenced by: '<S12>/Current Offset'
                                        */
  real_T DCIGain_Gain_a;               /* Expression: 100*1/3.3
                                        * Referenced by: '<S12>/DC//I Gain'
                                        */
  real_T TemperatureNormalization_Gain_i;/* Expression: 1
                                          * Referenced by: '<S12>/Temperature  Normalization'
                                          */
  real_T Constant6_Value;              /* Expression: 50
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T CurrentOffset_Value_p3;       /* Expression: 0
                                        * Referenced by: '<S11>/Current Offset'
                                        */
  real_T DCIGain_Gain_i;               /* Expression: 100*1/3.3
                                        * Referenced by: '<S11>/DC//I Gain'
                                        */
  real_T TemperatureNormalization_Gain_p;/* Expression: 1
                                          * Referenced by: '<S11>/Temperature  Normalization'
                                          */
  real_T Constant7_Value;              /* Expression: 50
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant_Value;               /* Expression: 0.0011
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain7_Gain;                   /* Expression: .0001
                                        * Referenced by: '<Root>/Gain7'
                                        */
  real_T Constant1_Value;              /* Expression: 0.104
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T fh_Coefs[7];                  /* Expression: [ +1.6739e+20, -1.3935e+18, +4.7154e+15, -8.351e+12, +8.2878e+9, -4.527e+6, 1.1593e+3 ]
                                        * Referenced by: '<Root>/f^(h)'
                                        */
  real_T GravityConstant_Value;        /* Expression: 9.81
                                        * Referenced by: '<S14>/Gravity Constant'
                                        */
  real_T u3TotalMass_Value;            /* Expression: 0.176
                                        * Referenced by: '<S14>/1//3 Total Mass'
                                        */
  real_T Constant5_Value;              /* Expression: 50
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T DutyCycleSaturation1_UpperSat;/* Expression: 99
                                        * Referenced by: '<Root>/Duty Cycle Saturation1'
                                        */
  real_T DutyCycleSaturation1_LowerSat;/* Expression: 0
                                        * Referenced by: '<Root>/Duty Cycle Saturation1'
                                        */
  real_T Constant4_Value;              /* Expression: 50
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T DutyCycleSaturation_UpperSat; /* Expression: 99
                                        * Referenced by: '<Root>/Duty Cycle Saturation'
                                        */
  real_T DutyCycleSaturation_LowerSat; /* Expression: 0
                                        * Referenced by: '<Root>/Duty Cycle Saturation'
                                        */
  real_T Constant3_Value;              /* Expression: 50
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S12>/Gain1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1000000
                                        * Referenced by: '<S12>/Gain2'
                                        */
  real_T ContollerGain_Gain;           /* Expression: 5000
                                        * Referenced by: '<S12>/Contoller Gain'
                                        */
  real_T DiscreteTransferFcn_NumCoef[2];/* Expression: numd
                                         * Referenced by: '<S19>/Discrete Transfer Fcn'
                                         */
  real_T DiscreteTransferFcn_DenCoef[2];/* Expression: dend
                                         * Referenced by: '<S19>/Discrete Transfer Fcn'
                                         */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<S19>/Discrete Transfer Fcn'
                                          */
  real_T Gain3_Gain;                   /* Expression: 1000
                                        * Referenced by: '<S12>/Gain3'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: 1000
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real_T Gain2_Gain_b;                 /* Expression: 1000000
                                        * Referenced by: '<S13>/Gain2'
                                        */
  real_T ContollerGain_Gain_a;         /* Expression: 5000
                                        * Referenced by: '<S13>/Contoller Gain'
                                        */
  real_T DiscreteTransferFcn_NumCoef_j[2];/* Expression: numd
                                           * Referenced by: '<S20>/Discrete Transfer Fcn'
                                           */
  real_T DiscreteTransferFcn_DenCoef_j[2];/* Expression: dend
                                           * Referenced by: '<S20>/Discrete Transfer Fcn'
                                           */
  real_T DiscreteTransferFcn_InitialSt_p;/* Expression: 0
                                          * Referenced by: '<S20>/Discrete Transfer Fcn'
                                          */
  real_T Gain3_Gain_g;                 /* Expression: 1000
                                        * Referenced by: '<S13>/Gain3'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: 1000
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T Gain2_Gain_l;                 /* Expression: 1000000
                                        * Referenced by: '<S11>/Gain2'
                                        */
  real_T ContollerGain_Gain_e;         /* Expression: 5000
                                        * Referenced by: '<S11>/Contoller Gain'
                                        */
  real_T DiscreteTransferFcn_NumCoef_e[2];/* Expression: numd
                                           * Referenced by: '<S18>/Discrete Transfer Fcn'
                                           */
  real_T DiscreteTransferFcn_DenCoef_h[2];/* Expression: dend
                                           * Referenced by: '<S18>/Discrete Transfer Fcn'
                                           */
  real_T DiscreteTransferFcn_InitialSt_b;/* Expression: 0
                                          * Referenced by: '<S18>/Discrete Transfer Fcn'
                                          */
  real_T Gain3_Gain_b;                 /* Expression: 1000
                                        * Referenced by: '<S11>/Gain3'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T RateLimiter2_RisingLim;       /* Computed Parameter: RateLimiter2_RisingLim
                                        * Referenced by: '<Root>/Rate Limiter2'
                                        */
  real_T RateLimiter2_FallingLim;      /* Computed Parameter: RateLimiter2_FallingLim
                                        * Referenced by: '<Root>/Rate Limiter2'
                                        */
  real_T RateLimiter2_IC;              /* Expression: 0
                                        * Referenced by: '<Root>/Rate Limiter2'
                                        */
  real_T DutyCycleSaturation2_UpperSat;/* Expression: 99
                                        * Referenced by: '<Root>/Duty Cycle Saturation2'
                                        */
  real_T DutyCycleSaturation2_LowerSat;/* Expression: 0
                                        * Referenced by: '<Root>/Duty Cycle Saturation2'
                                        */
  real_T Gain3_Gain_n;                 /* Expression: 1
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T RateLimiter_RisingLim;        /* Computed Parameter: RateLimiter_RisingLim
                                        * Referenced by: '<Root>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim;       /* Computed Parameter: RateLimiter_FallingLim
                                        * Referenced by: '<Root>/Rate Limiter'
                                        */
  real_T RateLimiter_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Rate Limiter'
                                        */
  real_T RateLimiter1_RisingLim;       /* Computed Parameter: RateLimiter1_RisingLim
                                        * Referenced by: '<Root>/Rate Limiter1'
                                        */
  real_T RateLimiter1_FallingLim;      /* Computed Parameter: RateLimiter1_FallingLim
                                        * Referenced by: '<Root>/Rate Limiter1'
                                        */
  real_T RateLimiter1_IC;              /* Expression: 0
                                        * Referenced by: '<Root>/Rate Limiter1'
                                        */
  int32_T Constant_Value_g;            /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S10>/Constant'
                                        */
  int32_T ADRaw1_p1;                   /* Computed Parameter: ADRaw1_p1
                                        * Referenced by: '<S2>/AD Raw1'
                                        */
  int32_T ADRaw1_p1_f;                 /* Computed Parameter: ADRaw1_p1_f
                                        * Referenced by: '<S3>/AD Raw1'
                                        */
  int32_T ADRaw1_p1_e;                 /* Computed Parameter: ADRaw1_p1_e
                                        * Referenced by: '<S1>/AD Raw1'
                                        */
  int32_T SFunction2_p1;               /* Expression: int32(ch)
                                        * Referenced by: '<S4>/S-Function2'
                                        */
  int32_T SFunction2_p3;               /* Expression: int32(invert-1)
                                        * Referenced by: '<S4>/S-Function2'
                                        */
  int32_T SFunction2_p1_c;             /* Expression: int32(ch)
                                        * Referenced by: '<S5>/S-Function2'
                                        */
  int32_T SFunction2_p3_m;             /* Expression: int32(invert-1)
                                        * Referenced by: '<S5>/S-Function2'
                                        */
  int32_T SFunction2_p1_d;             /* Expression: int32(ch)
                                        * Referenced by: '<S6>/S-Function2'
                                        */
  int32_T SFunction2_p3_mx;            /* Expression: int32(invert-1)
                                        * Referenced by: '<S6>/S-Function2'
                                        */
  int32_T Sensor1Identifier_Value;     /* Computed Parameter: Sensor1Identifier_Value
                                        * Referenced by: '<S10>/Sensor 1 Identifier'
                                        */
  int32_T Sensor2Identifier_Value;     /* Computed Parameter: Sensor2Identifier_Value
                                        * Referenced by: '<S10>/Sensor 2 Identifier'
                                        */
  int32_T Sensor3Identifier_Value;     /* Computed Parameter: Sensor3Identifier_Value
                                        * Referenced by: '<S10>/Sensor 3 Identifier'
                                        */
  int32_T Floatier_Value;              /* Computed Parameter: Floatier_Value
                                        * Referenced by: '<S10>/Float ier'
                                        */
  int32_T MassIdentifier_Value;        /* Computed Parameter: MassIdentifier_Value
                                        * Referenced by: '<S10>/Mass Identifier'
                                        */
  int32_T XComInit_p1;                 /* Computed Parameter: XComInit_p1
                                        * Referenced by: '<S10>/XComInit'
                                        */
  int32_T Gain4_Gain;                  /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<Root>/Gain4'
                                        */
  int32_T Gain6_Gain;                  /* Computed Parameter: Gain6_Gain
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real32_T ToVolt_Gain;                /* Computed Parameter: ToVolt_Gain
                                        * Referenced by: '<S2>/ToVolt'
                                        */
  real32_T ZeroSensorVoltage_Value;    /* Computed Parameter: ZeroSensorVoltage_Value
                                        * Referenced by: '<S8>/Zero Sensor Voltage'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S8>/Gain'
                                        */
  real32_T Constant_Value_n;           /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S8>/Constant'
                                        */
  real32_T ToVolt_Gain_d;              /* Computed Parameter: ToVolt_Gain_d
                                        * Referenced by: '<S3>/ToVolt'
                                        */
  real32_T ZeroSensorVoltage_Value_k;  /* Computed Parameter: ZeroSensorVoltage_Value_k
                                        * Referenced by: '<S9>/Zero Sensor Voltage'
                                        */
  real32_T Gain_Gain_e;                /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S9>/Gain'
                                        */
  real32_T Constant_Value_k;           /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S9>/Constant'
                                        */
  real32_T ToVolt_Gain_l;              /* Computed Parameter: ToVolt_Gain_l
                                        * Referenced by: '<S1>/ToVolt'
                                        */
  real32_T ZeroSensorVoltage_Value_i;  /* Computed Parameter: ZeroSensorVoltage_Value_i
                                        * Referenced by: '<S7>/Zero Sensor Voltage'
                                        */
  real32_T Gain_Gain_g;                /* Computed Parameter: Gain_Gain_g
                                        * Referenced by: '<S7>/Gain'
                                        */
  real32_T Constant_Value_b;           /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S7>/Constant'
                                        */
  real32_T Gain_Gain_n;                /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<Root>/Gain'
                                        */
  real32_T Gain1_Gain_f;               /* Computed Parameter: Gain1_Gain_f
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real32_T Gain2_Gain_n;               /* Computed Parameter: Gain2_Gain_n
                                        * Referenced by: '<Root>/Gain2'
                                        */
  uint32_T SFunction2_p2;              /* Expression: uint32(freq)
                                        * Referenced by: '<S4>/S-Function2'
                                        */
  uint32_T SFunction2_p2_l;            /* Expression: uint32(freq)
                                        * Referenced by: '<S5>/S-Function2'
                                        */
  uint32_T SFunction2_p2_e;            /* Expression: uint32(freq)
                                        * Referenced by: '<S6>/S-Function2'
                                        */
  uint32_T GPIOWrite_p1;               /* Computed Parameter: GPIOWrite_p1
                                        * Referenced by: '<S10>/GPIO Write'
                                        */
  uint32_T GPIOSetup_p1;               /* Computed Parameter: GPIOSetup_p1
                                        * Referenced by: '<S10>/GPIO Setup'
                                        */
  uint32_T GPIOSetup_p2;               /* Computed Parameter: GPIOSetup_p2
                                        * Referenced by: '<S10>/GPIO Setup'
                                        */
  uint8_T RedLEDOn2_Value;             /* Computed Parameter: RedLEDOn2_Value
                                        * Referenced by: '<S10>/Red LED On2'
                                        */
  uint8_T RedLEDOn1_Value;             /* Computed Parameter: RedLEDOn1_Value
                                        * Referenced by: '<S10>/Red LED On1'
                                        */
  uint8_T RedLEDOn_Value;              /* Computed Parameter: RedLEDOn_Value
                                        * Referenced by: '<S10>/Red LED On'
                                        */
  uint8_T Out1_Y0;                     /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S17>/Out1'
                                        */
  uint8_T RedLEDOff_Value;             /* Computed Parameter: RedLEDOff_Value
                                        * Referenced by: '<S10>/Red LED Off'
                                        */
  uint8_T ManualSwitch4_CurrentSetting;/* Computed Parameter: ManualSwitch4_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch4'
                                        */
  uint8_T ManualSwitch3_CurrentSetting;/* Computed Parameter: ManualSwitch3_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch3'
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
                                        * Referenced by: '<S10>/RED LED'
                                        */
  uint8_T Latchsignal_Value;           /* Computed Parameter: Latchsignal_Value
                                        * Referenced by: '<S10>/Latch signal'
                                        */
  uint8_T GPIOSetup_p3;                /* Computed Parameter: GPIOSetup_p3
                                        * Referenced by: '<S10>/GPIO Setup'
                                        */
  uint8_T GPIOSetup_p4;                /* Computed Parameter: GPIOSetup_p4
                                        * Referenced by: '<S10>/GPIO Setup'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_mitchell_bluetooth_T {
  const char_T *errorStatus;

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

/* Block parameters (default storage) */
extern P_mitchell_bluetooth_T mitchell_bluetooth_P;

/* Block signals (default storage) */
extern B_mitchell_bluetooth_T mitchell_bluetooth_B;

/* Block states (default storage) */
extern DW_mitchell_bluetooth_T mitchell_bluetooth_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_mitchell_bluetooth_T mitchell_bluetooth_Y;

/* External function called from main */
extern void mitchell_bluetooth_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void mitchell_bluetooth_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void mitchell_bluetooth_initialize(void);
extern void mitchell_bluetooth_step0(void);
extern void mitchell_bluetooth_step1(void);
extern void mitchell_bluetooth_step2(void);
extern void mitchell_bluetooth_step3(void);
extern void mitchell_bluetooth_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mitchell_bluetooth_T *const mitchell_bluetooth_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S10>/Data Type Conversion11' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion12' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S10>/Data Type Conversion8' : Eliminate redundant data type conversion
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
 * '<Root>' : 'mitchell_bluetooth'
 * '<S1>'   : 'mitchell_bluetooth/AD Volt'
 * '<S2>'   : 'mitchell_bluetooth/AD Volt1'
 * '<S3>'   : 'mitchell_bluetooth/AD Volt2'
 * '<S4>'   : 'mitchell_bluetooth/PWM Output'
 * '<S5>'   : 'mitchell_bluetooth/PWM Output1'
 * '<S6>'   : 'mitchell_bluetooth/PWM Output2'
 * '<S7>'   : 'mitchell_bluetooth/Sensor 1 Position Conversion'
 * '<S8>'   : 'mitchell_bluetooth/Sensor 2 Position Conversion'
 * '<S9>'   : 'mitchell_bluetooth/Sensor 3 Position Conversion'
 * '<S10>'  : 'mitchell_bluetooth/Subsystem'
 * '<S11>'  : 'mitchell_bluetooth/Subsystem1'
 * '<S12>'  : 'mitchell_bluetooth/Subsystem2'
 * '<S13>'  : 'mitchell_bluetooth/Subsystem3'
 * '<S14>'  : 'mitchell_bluetooth/i_0 '
 * '<S15>'  : 'mitchell_bluetooth/Subsystem/MATLAB Function'
 * '<S16>'  : 'mitchell_bluetooth/Subsystem/XComRecv'
 * '<S17>'  : 'mitchell_bluetooth/Subsystem/XComRecv/Enabled Subsystem'
 * '<S18>'  : 'mitchell_bluetooth/Subsystem1/Lead Compensator'
 * '<S19>'  : 'mitchell_bluetooth/Subsystem2/Lead Compensator'
 * '<S20>'  : 'mitchell_bluetooth/Subsystem3/Lead Compensator'
 */
#endif                                 /* RTW_HEADER_mitchell_bluetooth_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
