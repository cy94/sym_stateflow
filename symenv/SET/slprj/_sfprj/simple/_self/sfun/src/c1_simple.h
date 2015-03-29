#ifndef __c1_simple_h__
#define __c1_simple_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef enum_state_name
#define enum_state_name

enum state_name
{
  state_name_None,
  state_name_start,
  state_name_C,
  state_name_A
};

#endif                                 /*enum_state_name*/

#ifndef typedef_c1_state_name
#define typedef_c1_state_name

typedef enum state_name c1_state_name;

#endif                                 /*typedef_c1_state_name*/

#ifndef typedef_SFc1_simpleInstanceStruct
#define typedef_SFc1_simpleInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_A;
  uint8_T c1_tp_start;
  uint8_T c1_tp_C;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_simple;
  real_T c1_x;
  real_T c1_y;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_simpleInstanceStruct;

#endif                                 /*typedef_SFc1_simpleInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_simple_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_simple_get_check_sum(mxArray *plhs[]);
extern void c1_simple_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
