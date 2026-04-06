/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: WindTurbineModel_V2.h
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

#ifndef WindTurbineModel_V2_h_
#define WindTurbineModel_V2_h_
#ifndef WindTurbineModel_V2_COMMON_INCLUDES_
#define WindTurbineModel_V2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ArduinoEncoder.h"
#endif                                /* WindTurbineModel_V2_COMMON_INCLUDES_ */

#include "WindTurbineModel_V2_types.h"
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Divide;                       /* '<Root>/Divide' */
  real_T Add1;                         /* '<S1>/Add1' */
  real_T Divide3;                      /* '<S3>/Divide3' */
  real_T Divide_i;                     /* '<S4>/Divide' */
  real_T Divide1;                      /* '<S2>/Divide1' */
  int32_T Encoder1;                    /* '<Root>/Encoder1' */
} B_WindTurbineModel_V2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_internal_arduino_RotaryEncoder_WindTurbineModel_V2_T
    obj;                               /* '<Root>/Encoder1' */
  real_T Delay_DSTATE;                 /* '<S1>/Delay' */
  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T Delay_DSTATE_j;              /* '<Root>/Delay' */
} DW_WindTurbineModel_V2_T;

/* Parameters (default storage) */
struct P_WindTurbineModel_V2_T_ {
  real_T rho;                          /* Variable: rho
                                        * Referenced by: '<S4>/rho [kg//m^3]'
                                        */
  real_T PPR_Value;                    /* Expression: 30
                                        * Referenced by: '<Root>/PPR'
                                        */
  real_T Constant1_Value;              /* Expression: 0.01
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0.1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay'
                                        */
  real_T Constant3_Value;              /* Expression: 4
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Lambda_Value;                 /* Expression: 7
                                        * Referenced by: '<Root>/Lambda'
                                        */
  real_T Rm_Value;                     /* Expression: .18
                                        * Referenced by: '<Root>/R [m]'
                                        */
  real_T Constant1_Value_k;            /* Expression: 60
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant2_Value_i;            /* Expression: 2
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T Constant3_Value_n;            /* Expression: pi
                                        * Referenced by: '<S3>/Constant3'
                                        */
  real_T Pi_Value;                     /* Expression: pi
                                        * Referenced by: '<S4>/Pi'
                                        */
  real_T uthpower_Value;               /* Expression: 5
                                        * Referenced by: '<S4>/5th power'
                                        */
  real_T Cp_Value;                     /* Expression: .49
                                        * Referenced by: '<Root>/Cp'
                                        */
  real_T u_Value;                      /* Expression: 2
                                        * Referenced by: '<S4>/2'
                                        */
  real_T Cubic_Value;                  /* Expression: 3
                                        * Referenced by: '<S4>/Cubic'
                                        */
  int64m_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  int32_T Delay_InitialCondition_a;
                                 /* Computed Parameter: Delay_InitialCondition_a
                                  * Referenced by: '<Root>/Delay'
                                  */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_WindTurbineModel_V2_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_WindTurbineModel_V2_T WindTurbineModel_V2_P;

/* Block signals (default storage) */
extern B_WindTurbineModel_V2_T WindTurbineModel_V2_B;

/* Block states (default storage) */
extern DW_WindTurbineModel_V2_T WindTurbineModel_V2_DW;

/* Model entry point functions */
extern void WindTurbineModel_V2_initialize(void);
extern void WindTurbineModel_V2_step(void);
extern void WindTurbineModel_V2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_WindTurbineModel_V2_T *const WindTurbineModel_V2_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant' : Unused code path elimination
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
 * '<Root>' : 'WindTurbineModel_V2'
 * '<S1>'   : 'WindTurbineModel_V2/Subsystem'
 * '<S2>'   : 'WindTurbineModel_V2/Subsystem2'
 * '<S3>'   : 'WindTurbineModel_V2/Subsystem2/Subsystem'
 * '<S4>'   : 'WindTurbineModel_V2/Subsystem2/Subsystem1'
 */
#endif                                 /* WindTurbineModel_V2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
