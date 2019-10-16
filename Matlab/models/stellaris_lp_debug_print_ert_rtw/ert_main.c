/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
  stellaris_lp_debug_print_step();

  /* Get model outputs here */
  systick_intr_disable();
  OverrunFlag--;
}

volatile boolean_T stopRequested = false;
int main(int argc, char **argv)
{
  volatile boolean_T runModel = true;
  float modelBaseRate = 0.2;
  float systemClock = 100;
  system_init();
  ((void) 0);
  stellaris_lp_debug_print_initialize();
  systick_init(modelBaseRate);
  systick_intr_enable();
  while (runModel) {
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  stellaris_lp_debug_print_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
