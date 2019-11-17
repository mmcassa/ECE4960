/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include "mitchell_bluetooth.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[4] = { 0, 0, 0, 0 };

boolean_T need2runFlags[4] = { 0, 0, 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[4];
  int_T i;

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
  mitchell_bluetooth_SetEventsForThisBaseStep(eventFlags);
  systick_intr_enable();
  mitchell_bluetooth_step0();

  /* Get model outputs here */
  systick_intr_disable();
  isRateRunning[0]--;
  for (i = 1; i < 4; i++) {
    if (eventFlags[i]) {
      if (need2runFlags[i]++) {
        IsrOverrun = 1;
        need2runFlags[i]--;            /* allow future iterations to succeed*/
        break;
      }
    }
  }

  for (i = 1; i < 4; i++) {
    if (isRateRunning[i]) {
      /* Yield to higher priority*/
      return;
    }

    if (need2runFlags[i]) {
      isRateRunning[i]++;
      systick_intr_enable();

      /* Step the model for subrate "i" */
      switch (i)
      {
       case 1 :
        mitchell_bluetooth_step1();

        /* Get model outputs here */
        break;

       case 2 :
        mitchell_bluetooth_step2();

        /* Get model outputs here */
        break;

       case 3 :
        mitchell_bluetooth_step3();

        /* Get model outputs here */
        break;

       default :
        break;
      }

      systick_intr_disable();
      need2runFlags[i]--;
      isRateRunning[i]--;
    }
  }
}

volatile boolean_T stopRequested = false;
int main(int argc, char **argv)
{
  volatile boolean_T runModel = true;
  float modelBaseRate = 5.0E-5;
  float systemClock = 100;
  system_init();
  rtmSetErrorStatus(mitchell_bluetooth_M, 0);
  mitchell_bluetooth_initialize();
  systick_init(modelBaseRate);
  runModel =
    rtmGetErrorStatus(mitchell_bluetooth_M) == (NULL);
  systick_intr_enable();
  while (runModel) {
    stopRequested = !(
                      rtmGetErrorStatus(mitchell_bluetooth_M) == (NULL));
    runModel = !(stopRequested);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  mitchell_bluetooth_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
