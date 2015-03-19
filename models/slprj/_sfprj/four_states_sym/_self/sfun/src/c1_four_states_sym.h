#ifndef __c1_four_states_sym_h__
#define __c1_four_states_sym_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc1_four_states_symInstanceStruct
#define typedef_SFc1_four_states_symInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_A;
  uint8_T c1_tp_start;
  uint8_T c1_tp_C;
  uint8_T c1_tp_end;
  uint8_T c1_tp_B;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_four_states_sym;
  uint8_T c1_is_c1_four_states_sym;
  real_T c1_x;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_four_states_symInstanceStruct;

#endif                                 /*typedef_SFc1_four_states_symInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_four_states_sym_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_four_states_sym_get_check_sum(mxArray *plhs[]);
extern void c1_four_states_sym_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
