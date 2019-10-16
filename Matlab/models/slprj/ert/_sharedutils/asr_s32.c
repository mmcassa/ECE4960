/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: asr_s32.c
 *
 * Code generated for Simulink model 'stellaris_lp_irreceive_RCA'.
 *
 * Model version                  : 1.208
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Sep 17 13:33:48 2019
 */

#include "rtwtypes.h"
#include "asr_s32.h"

int32_T asr_s32(int32_T u, uint32_T n)
{
  int32_T y;
  if (u >= 0) {
    y = (int32_T)((uint32_T)(((uint32_T)u) >> n));
  } else {
    y = (-((int32_T)((uint32_T)(((uint32_T)((int32_T)(-1 - u))) >> n)))) - 1;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
