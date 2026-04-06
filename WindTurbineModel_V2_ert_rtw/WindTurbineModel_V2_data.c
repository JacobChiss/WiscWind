/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: WindTurbineModel_V2_data.c
 *
 * Code generated for Simulink model 'WindTurbineModel_V2'.
 *
 * Model version                  : 1.25
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon Mar  2 18:29:20 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "WindTurbineModel_V2.h"

/* Block parameters (default storage) */
P_WindTurbineModel_V2_T WindTurbineModel_V2_P = {
  /* Variable: rho
   * Referenced by: '<S4>/rho [kg//m^3]'
   */
  1.125,

  /* Expression: 30
   * Referenced by: '<Root>/PPR'
   */
  30.0,

  /* Expression: 0.01
   * Referenced by: '<Root>/Constant1'
   */
  0.01,

  /* Expression: 0.1
   * Referenced by: '<Root>/Constant2'
   */
  0.1,

  /* Expression: 0.0
   * Referenced by: '<S1>/Delay'
   */
  0.0,

  /* Expression: 4
   * Referenced by: '<Root>/Constant3'
   */
  4.0,

  /* Expression: 7
   * Referenced by: '<Root>/Lambda'
   */
  7.0,

  /* Expression: .18
   * Referenced by: '<Root>/R [m]'
   */
  0.18,

  /* Expression: 60
   * Referenced by: '<S3>/Constant1'
   */
  60.0,

  /* Expression: 2
   * Referenced by: '<S3>/Constant2'
   */
  2.0,

  /* Expression: pi
   * Referenced by: '<S3>/Constant3'
   */
  3.1415926535897931,

  /* Expression: pi
   * Referenced by: '<S4>/Pi'
   */
  3.1415926535897931,

  /* Expression: 5
   * Referenced by: '<S4>/5th power'
   */
  5.0,

  /* Expression: .49
   * Referenced by: '<Root>/Cp'
   */
  0.49,

  /* Expression: 2
   * Referenced by: '<S4>/2'
   */
  2.0,

  /* Expression: 3
   * Referenced by: '<S4>/Cubic'
   */
  3.0,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<Root>/Gain1'
   */
  { { 0UL, 0x78000000UL } },

  /* Computed Parameter: Delay_InitialCondition_a
   * Referenced by: '<Root>/Delay'
   */
  0L,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<Root>/Gain'
   */
  1677721600L
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
