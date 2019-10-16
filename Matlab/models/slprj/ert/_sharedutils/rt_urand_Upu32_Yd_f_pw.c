/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_urand_Upu32_Yd_f_pw.c
 *
 * Code generated for Simulink model 'stellaris_lp_blink_rand'.
 *
 * Model version                  : 1.77
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Sep 11 18:23:27 2019
 */

#include "rtwtypes.h"
#include "rt_urand_Upu32_Yd_f_pw.h"

real_T rt_urand_Upu32_Yd_f_pw(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = ((*u) % 127773U) * 16807U;
  hi = ((*u) / 127773U) * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return ((real_T)(*u)) * 4.6566128752457969E-10;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
