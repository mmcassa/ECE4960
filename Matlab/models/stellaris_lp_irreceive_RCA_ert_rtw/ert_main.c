/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include "stellaris_lp_irreceive_RCA.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[2] = { 0, 0 };

boolean_T need2runFlags[2] = { 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[2];

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.  The generated code includes function
   * writeCodeInfoFcn() which sets the rates
   * that need to run this time step.  The return values are 1 and 0
   * for true and false, respectively.
   */
  stellaris_lp_irreceive_RCA_SetEventsForThisBaseStep(eventFlags);
  systick_intr_enable();
  stellaris_lp_irreceive_RCA_step0();

  /* Get model outputs here */
  systick_intr_disable();
  isRateRunning[0]--;
  if (eventFlags[1]) {
    if (need2runFlags[1]++) {
      IsrOverrun = 1;
      need2runFlags[1]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[1]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[1]++;
    systick_intr_enable();

    /* Step the model for subrate "1" */
    switch (1)
    {
     case 1 :
      stellaris_lp_irreceive_RCA_step1();

      /* Get model outputs here */
      break;

     default :
      break;
    }

    systick_intr_disable();
    need2runFlags[1]--;
    isRateRunning[1]--;
  }
}

volatile boolean_T stopRequested = false;
int main(int argc, char **argv)
{
  volatile boolean_T runModel = true;
  float modelBaseRate = 0.0001;
  float systemClock = 100;
  system_init();
  ((void) 0);
  stellaris_lp_irreceive_RCA_initialize();
  systick_init(modelBaseRate);
  systick_intr_enable();
  while (runModel) {
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  stellaris_lp_irreceive_RCA_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
