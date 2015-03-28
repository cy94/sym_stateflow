#ifndef __c2_simple_h__
#define __c2_simple_h__

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

#ifndef typedef_c2_state_name
#define typedef_c2_state_name

typedef enum state_name c2_state_name;

#endif                                 /*typedef_c2_state_name*/

#ifndef typedef_SFc2_simpleInstanceStruct
#define typedef_SFc2_simpleInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_simple;
} SFc2_simpleInstanceStruct;

#endif                                 /*typedef_SFc2_simpleInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_simple_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_simple_get_check_sum(mxArray *plhs[]);
extern void c2_simple_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
