/* Include files */

#include <stddef.h>
#include "blas.h"
#include "simple_sfun.h"
#include "c1_simple.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "simple_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c1_simple(SFc1_simpleInstanceStruct *chartInstance);
static void initialize_params_c1_simple(SFc1_simpleInstanceStruct *chartInstance);
static void enable_c1_simple(SFc1_simpleInstanceStruct *chartInstance);
static void disable_c1_simple(SFc1_simpleInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_simple(SFc1_simpleInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_simple(SFc1_simpleInstanceStruct
  *chartInstance);
static void set_sim_state_c1_simple(SFc1_simpleInstanceStruct *chartInstance,
  const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_simple(SFc1_simpleInstanceStruct
  *chartInstance);
static void finalize_c1_simple(SFc1_simpleInstanceStruct *chartInstance);
static void sf_c1_simple(SFc1_simpleInstanceStruct *chartInstance);
static void initSimStructsc1_simple(SFc1_simpleInstanceStruct *chartInstance);
static void registerMessagesc1_simple(SFc1_simpleInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static int32_T c1_emlrt_marshallIn(SFc1_simpleInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_b_emlrt_marshallIn(SFc1_simpleInstanceStruct *chartInstance,
  const mxArray *c1_b_tp_start, const char_T *c1_identifier);
static uint8_T c1_c_emlrt_marshallIn(SFc1_simpleInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static c1_state_name c1_d_emlrt_marshallIn(SFc1_simpleInstanceStruct
  *chartInstance, const mxArray *c1_state, const char_T *c1_identifier);
static c1_state_name c1_e_emlrt_marshallIn(SFc1_simpleInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_f_emlrt_marshallIn(SFc1_simpleInstanceStruct *chartInstance,
  const mxArray *c1_b_x, const char_T *c1_identifier);
static real_T c1_g_emlrt_marshallIn(SFc1_simpleInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_emlrt_marshallIn(SFc1_simpleInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier);
static const mxArray *c1_i_emlrt_marshallIn(SFc1_simpleInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_simpleInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_simple(SFc1_simpleInstanceStruct *chartInstance)
{
  c1_state_name *c1_state;
  c1_state = (c1_state_name *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_tp_A = 0U;
  chartInstance->c1_tp_C = 0U;
  chartInstance->c1_tp_start = 0U;
  chartInstance->c1_is_active_c1_simple = 0U;
  chartInstance->c1_x = 0.0;
  chartInstance->c1_y = 0.0;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c1_state = state_name_None;
  }
}

static void initialize_params_c1_simple(SFc1_simpleInstanceStruct *chartInstance)
{
}

static void enable_c1_simple(SFc1_simpleInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_simple(SFc1_simpleInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_simple(SFc1_simpleInstanceStruct
  *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_state_name *c1_state;
  c1_state = (c1_state_name *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_simple == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (*c1_state == state_name_start) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  }

  if (*c1_state == state_name_C) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  }

  if (*c1_state == state_name_A) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_simple(SFc1_simpleInstanceStruct
  *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_b_y = NULL;
  c1_state_name c1_hoistedGlobal;
  c1_state_name c1_u;
  const mxArray *c1_c_y = NULL;
  static const int32_T c1_enumValues[4] = { 0, 1, 2, 3 };

  static const char * c1_enumNames[4] = { "None", "start", "C", "A" };

  int32_T c1_b_u;
  const mxArray *c1_d_y = NULL;
  const mxArray *c1_m0 = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_f_y = NULL;
  uint8_T c1_d_hoistedGlobal;
  uint8_T c1_e_u;
  const mxArray *c1_g_y = NULL;
  c1_state_name *c1_state;
  c1_state = (c1_state_name *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_createcellarray(4), FALSE);
  c1_hoistedGlobal = *c1_state;
  c1_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_check_enum("state_name", 4, c1_enumNames, c1_enumValues);
  c1_b_u = (int32_T)c1_u;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_b_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_m0, c1_d_y, FALSE);
  sf_mex_assign(&c1_c_y, sf_mex_create_enum("state_name", c1_m0), FALSE);
  sf_mex_destroy(&c1_m0);
  sf_mex_setcell(c1_b_y, 0, c1_c_y);
  c1_b_hoistedGlobal = chartInstance->c1_x;
  c1_c_u = c1_b_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_b_y, 1, c1_e_y);
  c1_c_hoistedGlobal = chartInstance->c1_y;
  c1_d_u = c1_c_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_b_y, 2, c1_f_y);
  c1_d_hoistedGlobal = chartInstance->c1_is_active_c1_simple;
  c1_e_u = c1_d_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_b_y, 3, c1_g_y);
  sf_mex_assign(&c1_st, c1_b_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_simple(SFc1_simpleInstanceStruct *chartInstance,
  const mxArray *c1_st)
{
  const mxArray *c1_u;
  c1_state_name *c1_state;
  c1_state = (c1_state_name *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_u = sf_mex_dup(c1_st);
  *c1_state = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 0)), "state");
  chartInstance->c1_x = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 1)), "x");
  chartInstance->c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 2)), "y");
  chartInstance->c1_is_active_c1_simple = c1_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 3)), "is_active_c1_simple");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 4)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_simple(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_simple(SFc1_simpleInstanceStruct
  *chartInstance)
{
  c1_state_name *c1_state;
  c1_state = (c1_state_name *)ssGetOutputPortSignal(chartInstance->S, 1);
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (*c1_state == state_name_A) {
      chartInstance->c1_tp_A = 1U;
    } else {
      chartInstance->c1_tp_A = 0U;
    }

    if (*c1_state == state_name_C) {
      chartInstance->c1_tp_C = 1U;
    } else {
      chartInstance->c1_tp_C = 0U;
    }

    if (*c1_state == state_name_start) {
      chartInstance->c1_tp_start = 1U;
    } else {
      chartInstance->c1_tp_start = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_simple(SFc1_simpleInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_c1_simple(SFc1_simpleInstanceStruct *chartInstance)
{
  boolean_T c1_out;
  boolean_T c1_b_out;
  c1_state_name *c1_state;
  real_T *c1_n;
  c1_n = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_state = (c1_state_name *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_set_sim_state_side_effects_c1_simple(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_c1_simple == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_simple = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
    *c1_state = state_name_start;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_start = 1U;
    chartInstance->c1_x = *c1_n;
    chartInstance->c1_y = 1.0;
  } else {
    switch (*c1_state) {
     case state_name_A:
      CV_CHART_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c1_sfEvent);
      c1_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
                  chartInstance->c1_x != 10.0 != 0U, chartInstance->c1_sfEvent))
                != 0);
      if (c1_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_A = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
        *c1_state = state_name_C;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_C = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c1_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
      break;

     case state_name_C:
      CV_CHART_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                   chartInstance->c1_sfEvent);
      c1_b_out = (CV_TRANSITION_EVAL(0U, (int32_T)_SFD_CCP_CALL(0U, 0,
        chartInstance->c1_x < 10.0 != 0U, chartInstance->c1_sfEvent)) != 0);
      if (c1_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_C = 0U;
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 1U,
                     chartInstance->c1_sfEvent);
        chartInstance->c1_y += 5.0;
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
        *c1_state = state_name_A;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_A = 1U;
        chartInstance->c1_x += 2.0;
        chartInstance->c1_y++;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c1_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
      break;

     case state_name_start:
      CV_CHART_EVAL(0, 0, 3);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_start = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
      *c1_state = state_name_C;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_C = 1U;
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);
      *c1_state = state_name_None;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_simpleMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_simple(SFc1_simpleInstanceStruct *chartInstance)
{
}

static void registerMessagesc1_simple(SFc1_simpleInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

const mxArray *sf_c1_simple_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_b_y = NULL;
  SFc1_simpleInstanceStruct *chartInstance;
  chartInstance = (SFc1_simpleInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_emlrt_marshallIn(SFc1_simpleInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_b_y;
  int32_T c1_i0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i0, 1, 6, 0U, 0, 0U, 0);
  c1_b_y = c1_i0;
  sf_mex_destroy(&c1_u);
  return c1_b_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_b_y;
  SFc1_simpleInstanceStruct *chartInstance;
  chartInstance = (SFc1_simpleInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_b_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_b_y = NULL;
  SFc1_simpleInstanceStruct *chartInstance;
  chartInstance = (SFc1_simpleInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, FALSE);
  return c1_mxArrayOutData;
}

static uint8_T c1_b_emlrt_marshallIn(SFc1_simpleInstanceStruct *chartInstance,
  const mxArray *c1_b_tp_start, const char_T *c1_identifier)
{
  uint8_T c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_start),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_start);
  return c1_b_y;
}

static uint8_T c1_c_emlrt_marshallIn(SFc1_simpleInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_b_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_b_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_b_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_start;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_b_y;
  SFc1_simpleInstanceStruct *chartInstance;
  chartInstance = (SFc1_simpleInstanceStruct *)chartInstanceVoid;
  c1_b_tp_start = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_start),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_start);
  *(uint8_T *)c1_outData = c1_b_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_state_name c1_u;
  const mxArray *c1_b_y = NULL;
  static const int32_T c1_enumValues[4] = { 0, 1, 2, 3 };

  static const char * c1_enumNames[4] = { "None", "start", "C", "A" };

  int32_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  const mxArray *c1_m1 = NULL;
  SFc1_simpleInstanceStruct *chartInstance;
  chartInstance = (SFc1_simpleInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_state_name *)c1_inData;
  c1_b_y = NULL;
  sf_mex_check_enum("state_name", 4, c1_enumNames, c1_enumValues);
  c1_b_u = (int32_T)c1_u;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_m1, c1_c_y, FALSE);
  sf_mex_assign(&c1_b_y, sf_mex_create_enum("state_name", c1_m1), FALSE);
  sf_mex_destroy(&c1_m1);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, FALSE);
  return c1_mxArrayOutData;
}

static c1_state_name c1_d_emlrt_marshallIn(SFc1_simpleInstanceStruct
  *chartInstance, const mxArray *c1_state, const char_T *c1_identifier)
{
  c1_state_name c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_state), &c1_thisId);
  sf_mex_destroy(&c1_state);
  return c1_b_y;
}

static c1_state_name c1_e_emlrt_marshallIn(SFc1_simpleInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  c1_state_name c1_b_y;
  static const int32_T c1_enumValues[4] = { 0, 1, 2, 3 };

  static const char * c1_enumNames[4] = { "None", "start", "C", "A" };

  sf_mex_check_enum("state_name", 4, c1_enumNames, c1_enumValues);
  sf_mex_check_builtin(c1_parentId, c1_u, "state_name", 0, 0U, 0);
  c1_b_y = (c1_state_name)sf_mex_get_enum_element(c1_u, 0);
  sf_mex_destroy(&c1_u);
  return c1_b_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_state;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  c1_state_name c1_b_y;
  SFc1_simpleInstanceStruct *chartInstance;
  chartInstance = (SFc1_simpleInstanceStruct *)chartInstanceVoid;
  c1_state = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_state), &c1_thisId);
  sf_mex_destroy(&c1_state);
  *(c1_state_name *)c1_outData = c1_b_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  SFc1_simpleInstanceStruct *chartInstance;
  chartInstance = (SFc1_simpleInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_b_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_f_emlrt_marshallIn(SFc1_simpleInstanceStruct *chartInstance,
  const mxArray *c1_b_x, const char_T *c1_identifier)
{
  real_T c1_b_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_x), &c1_thisId);
  sf_mex_destroy(&c1_b_x);
  return c1_b_y;
}

static real_T c1_g_emlrt_marshallIn(SFc1_simpleInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_b_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_b_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_b_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_x;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_b_y;
  SFc1_simpleInstanceStruct *chartInstance;
  chartInstance = (SFc1_simpleInstanceStruct *)chartInstanceVoid;
  c1_b_x = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_x), &c1_thisId);
  sf_mex_destroy(&c1_b_x);
  *(real_T *)c1_outData = c1_b_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_emlrt_marshallIn(SFc1_simpleInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier)
{
  const mxArray *c1_b_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_b_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_b_y, c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), FALSE);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_b_y;
}

static const mxArray *c1_i_emlrt_marshallIn(SFc1_simpleInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_b_y = NULL;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_duplicatearraysafe(&c1_u), FALSE);
  sf_mex_destroy(&c1_u);
  return c1_b_y;
}

static void init_dsm_address_info(SFc1_simpleInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_simple_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1957490776U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1124495895U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3097920676U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3538944180U);
}

mxArray *sf_c1_simple_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("6spKpdYlEfPqVBQeyf6GDF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(14));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_simple_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_simple(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[2],M[24],T\"state\",},{M[3],M[17],T\"x\",},{M[3],M[23],T\"y\",},{M[8],M[0],T\"is_active_c1_simple\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_simple_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_simpleInstanceStruct *chartInstance;
    chartInstance = (SFc1_simpleInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _simpleMachineNumber_,
           1,
           3,
           4,
           4,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_simpleMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_simpleMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _simpleMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"n");
          _SFD_SET_DATA_PROPS(1,0,0,0,"x");
          _SFD_SET_DATA_PROPS(2,0,0,0,"y");
          _SFD_SET_DATA_PROPS(3,2,0,1,"state");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(0,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_TRANS_COV_WTS(1,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(0,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 7 };

          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(3,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(3,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)c1_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);

        {
          real_T *c1_n;
          c1_state_name *c1_state;
          c1_n = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c1_state = (c1_state_name *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_n);
          _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance->c1_x);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c1_y);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_state);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _simpleMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "FrQYRmjQU1Ve942GhvoRFC";
}

static void sf_opaque_initialize_c1_simple(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_simpleInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c1_simple((SFc1_simpleInstanceStruct*) chartInstanceVar);
  initialize_c1_simple((SFc1_simpleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_simple(void *chartInstanceVar)
{
  enable_c1_simple((SFc1_simpleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_simple(void *chartInstanceVar)
{
  disable_c1_simple((SFc1_simpleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_simple(void *chartInstanceVar)
{
  sf_c1_simple((SFc1_simpleInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_simple(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_simple((SFc1_simpleInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_simple();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_simple(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_simple();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_simple((SFc1_simpleInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_simple(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_simple(S);
}

static void sf_opaque_set_sim_state_c1_simple(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_simple(S, st);
}

static void sf_opaque_terminate_c1_simple(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_simpleInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_simple_optimization_info();
    }

    finalize_c1_simple((SFc1_simpleInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_simple((SFc1_simpleInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_simple(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_simple((SFc1_simpleInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_simple(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_simple_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2731764004U));
  ssSetChecksum1(S,(185847110U));
  ssSetChecksum2(S,(3537621748U));
  ssSetChecksum3(S,(2679916314U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_simple(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_simple(SimStruct *S)
{
  SFc1_simpleInstanceStruct *chartInstance;
  chartInstance = (SFc1_simpleInstanceStruct *)utMalloc(sizeof
    (SFc1_simpleInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_simpleInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_simple;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_simple;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_simple;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_simple;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_simple;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_simple;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_simple;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_simple;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_simple;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_simple;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_simple;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_simple_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_simple(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_simple(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_simple(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_simple_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
