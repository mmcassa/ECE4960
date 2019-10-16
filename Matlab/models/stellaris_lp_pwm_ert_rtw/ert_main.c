/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include "stellaris_lp_pwm.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  systick_intr_enable();
  stellaris_lp_pwm_step();

  /* Get model outputs here */
  systick_intr_disable();
  OverrunFlag--;
}

volatile boolean_T stopRequested = false;
int main(int argc, char **argv)
{
  volatile boolean_T runModel = true;
  float modelBaseRate = 0.002;
  float systemClock = 100;
  system_init();
  rtmSetErrorStatus(stellaris_lp_pwm_M, 0);
  stellaris_lp_pwm_initialize();
  systick_init(modelBaseRate);
  runModel =
    rtmGetErrorStatus(stellaris_lp_pwm_M) == (NULL);
  systick_intr_enable();
  while (runModel) {
    stopRequested = !(
                      rtmGetErrorStatus(stellaris_lp_pwm_M) == (NULL));
    runModel = !(stopRequested);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  stellaris_lp_pwm_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
