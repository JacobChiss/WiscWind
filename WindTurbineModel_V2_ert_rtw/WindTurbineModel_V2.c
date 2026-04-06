/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: WindTurbineModel_V2.c
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
#include "WindTurbineModel_V2_private.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Block signals (default storage) */
B_WindTurbineModel_V2_T WindTurbineModel_V2_B;

/* Block states (default storage) */
DW_WindTurbineModel_V2_T WindTurbineModel_V2_DW;

/* Real-time model */
static RT_MODEL_WindTurbineModel_V2_T WindTurbineModel_V2_M_;
RT_MODEL_WindTurbineModel_V2_T *const WindTurbineModel_V2_M =
  &WindTurbineModel_V2_M_;
real_T sMultiWord2Double(const uint32_T u1[], int16_T n1, int16_T e1)
{
  real_T y;
  uint32_T cb;
  uint32_T u1i;
  int16_T exp_0;
  int16_T i;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648UL) != 0UL) {
    cb = 1UL;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

void sMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T cb1;
  uint32_T cb2;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T ni;
  boolean_T isNegative1;
  boolean_T isNegative2;
  isNegative1 = ((u1[n1 - 1] & 2147483648UL) != 0UL);
  isNegative2 = ((u2[n2 - 1] & 2147483648UL) != 0UL);
  cb1 = 1UL;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    cb2 = 1UL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1UL;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void WindTurbineModel_V2_step(void)
{
  int128m_T tmp;
  int64m_T tmp_0;
  uint32_T tmp_1;
  uint32_T tmp_2;

  /* MATLABSystem: '<Root>/Encoder1' */
  if (WindTurbineModel_V2_DW.obj.TunablePropsChanged) {
    WindTurbineModel_V2_DW.obj.TunablePropsChanged = false;
  }

  /* MATLABSystem: '<Root>/Encoder1' */
  MW_EncoderRead(WindTurbineModel_V2_DW.obj.Index,
                 &WindTurbineModel_V2_B.Encoder1);

  /* Gain: '<Root>/Gain' incorporates:
   *  Delay: '<Root>/Delay'
   *  Sum: '<Root>/Subtract1'
   */
  tmp_1 = (uint32_T)WindTurbineModel_V2_P.Gain_Gain;
  tmp_2 = (uint32_T)(WindTurbineModel_V2_B.Encoder1 -
                     WindTurbineModel_V2_DW.Delay_DSTATE_j);
  sMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_0.chunks[0U], 2);

  /* Gain: '<Root>/Gain1' */
  sMultiWordMul(&WindTurbineModel_V2_P.Gain1_Gain.chunks[0U], 2, &tmp_0.chunks
                [0U], 2, &tmp.chunks[0U], 4);

  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/PPR'
   */
  WindTurbineModel_V2_B.Divide = sMultiWord2Double(&tmp.chunks[0U], 4, 0) *
    4.1359030627651384E-25 / WindTurbineModel_V2_P.PPR_Value;

  /* Sum: '<S1>/Add1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Delay: '<S1>/Delay'
   *  Product: '<S1>/Divide'
   *  Product: '<S1>/Product'
   *  Sum: '<S1>/Add'
   */
  WindTurbineModel_V2_B.Add1 = WindTurbineModel_V2_P.Constant1_Value /
    WindTurbineModel_V2_P.Constant2_Value * (WindTurbineModel_V2_B.Divide -
    WindTurbineModel_V2_DW.Delay_DSTATE) + WindTurbineModel_V2_DW.Delay_DSTATE;

  /* Product: '<S3>/Divide3' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Lambda'
   *  Constant: '<Root>/R [m]'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant3'
   *  Product: '<S3>/Divide2'
   */
  WindTurbineModel_V2_B.Divide3 = WindTurbineModel_V2_P.Constant3_Value *
    WindTurbineModel_V2_P.Lambda_Value / WindTurbineModel_V2_P.Rm_Value *
    WindTurbineModel_V2_P.Constant1_Value_k /
    WindTurbineModel_V2_P.Constant2_Value_i /
    WindTurbineModel_V2_P.Constant3_Value_n;

  /* Product: '<S4>/Divide' incorporates:
   *  Constant: '<Root>/Cp'
   *  Constant: '<Root>/Lambda'
   *  Constant: '<Root>/R [m]'
   *  Constant: '<S4>/2'
   *  Constant: '<S4>/5th power'
   *  Constant: '<S4>/Cubic'
   *  Constant: '<S4>/Pi'
   *  Constant: '<S4>/rho [kg//m^3]'
   *  Math: '<S4>/R^5 [m^5]'
   *  Math: '<S4>/lamda^3'
   */
  WindTurbineModel_V2_B.Divide_i = WindTurbineModel_V2_P.rho *
    WindTurbineModel_V2_P.Pi_Value * rt_powd_snf(WindTurbineModel_V2_P.Rm_Value,
    WindTurbineModel_V2_P.uthpower_Value) * WindTurbineModel_V2_P.Cp_Value /
    WindTurbineModel_V2_P.u_Value / rt_powd_snf
    (WindTurbineModel_V2_P.Lambda_Value, WindTurbineModel_V2_P.Cubic_Value);

  /* Product: '<S2>/Divide1' incorporates:
   *  Math: '<S2>/Square'
   */
  WindTurbineModel_V2_B.Divide1 = WindTurbineModel_V2_B.Divide3 *
    WindTurbineModel_V2_B.Divide3 * WindTurbineModel_V2_B.Divide_i;

  /* Update for Delay: '<Root>/Delay' */
  WindTurbineModel_V2_DW.Delay_DSTATE_j = WindTurbineModel_V2_B.Encoder1;

  /* Update for Delay: '<S1>/Delay' */
  WindTurbineModel_V2_DW.Delay_DSTATE = WindTurbineModel_V2_B.Add1;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.00011, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  WindTurbineModel_V2_M->Timing.clockTick0++;
}

/* Model initialize function */
void WindTurbineModel_V2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(WindTurbineModel_V2_M, -1);

  /* External mode info */
  WindTurbineModel_V2_M->Sizes.checksums[0] = (1504168014U);
  WindTurbineModel_V2_M->Sizes.checksums[1] = (2814006611U);
  WindTurbineModel_V2_M->Sizes.checksums[2] = (1497629008U);
  WindTurbineModel_V2_M->Sizes.checksums[3] = (2218124902U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    WindTurbineModel_V2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(WindTurbineModel_V2_M->extModeInfo,
      &WindTurbineModel_V2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(WindTurbineModel_V2_M->extModeInfo,
                        WindTurbineModel_V2_M->Sizes.checksums);
    rteiSetTFinalTicks(WindTurbineModel_V2_M->extModeInfo, -1);
  }

  /* InitializeConditions for Delay: '<Root>/Delay' */
  WindTurbineModel_V2_DW.Delay_DSTATE_j =
    WindTurbineModel_V2_P.Delay_InitialCondition_a;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  WindTurbineModel_V2_DW.Delay_DSTATE =
    WindTurbineModel_V2_P.Delay_InitialCondition;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  WindTurbineModel_V2_DW.obj.Index = 0U;
  WindTurbineModel_V2_DW.obj.matlabCodegenIsDeleted = false;
  WindTurbineModel_V2_DW.obj.isSetupComplete = false;
  WindTurbineModel_V2_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &WindTurbineModel_V2_DW.obj.Index);
  WindTurbineModel_V2_DW.obj.isSetupComplete = true;
  WindTurbineModel_V2_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<Root>/Encoder1' */
  MW_EncoderReset(WindTurbineModel_V2_DW.obj.Index);
}

/* Model terminate function */
void WindTurbineModel_V2_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Encoder1' */
  if (!WindTurbineModel_V2_DW.obj.matlabCodegenIsDeleted) {
    WindTurbineModel_V2_DW.obj.matlabCodegenIsDeleted = true;
    if ((WindTurbineModel_V2_DW.obj.isInitialized == 1L) &&
        WindTurbineModel_V2_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
