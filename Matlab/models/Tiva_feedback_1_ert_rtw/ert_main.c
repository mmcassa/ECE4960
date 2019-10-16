/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'Tiva_feedback_1'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Mon Sep 30 18:15:48 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Tiva_feedback_1.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[3] = { 0, 0, 0 };

boolean_T need2runFlags[3] = { 0, 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[3];
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
  Tiva_feedback_1_SetEventsForThisBaseStep(eventFlags);
  systick_intr_enable();
  Tiva_feedback_1_step0();

  /* Get model outputs here */
  systick_intr_disable();
  isRateRunning[0]--;
  for (i = 1; i < 3; i++) {
    if (eventFlags[i]) {
      if (need2runFlags[i]++) {
        IsrOverrun = 1;
        need2runFlags[i]--;            /* allow future iterations to succeed*/
        break;
      }
    }
  }

  for (i = 1; i < 3; i++) {
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
        Tiva_feedback_1_step1();

        /* Get model outputs here */
        break;

       case 2 :
        Tiva_feedback_1_step2();

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
  float modelBaseRate = 0.0001;
  float systemClock = 100;
  system_init();
  rtmSetErrorStatus(Tiva_feedback_1_M, 0);
  Tiva_feedback_1_initialize();
  systick_init(modelBaseRate);
  runModel =
    rtmGetErrorStatus(Tiva_feedback_1_M) == (NULL);
  systick_intr_enable();
  while (runModel) {
    stopRequested = !(
                      rtmGetErrorStatus(Tiva_feedback_1_M) == (NULL));
    runModel = !(stopRequested);
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  Tiva_feedback_1_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
