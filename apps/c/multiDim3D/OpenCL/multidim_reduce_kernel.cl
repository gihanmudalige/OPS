//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64:enable

#define OPS_3D
#define OPS_API 2
#define OPS_NO_GLOBALS
#include "ops_macros.h"
#include "ops_opencl_reduction.h"

#ifndef MIN
#define MIN(a,b) ((a<b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a>b) ? (a) : (b))
#endif
#ifndef SIGN
#define SIGN(a,b) ((b<0.0) ? (a*(-1)) : (a))
#endif
#define OPS_READ 0
#define OPS_WRITE 1
#define OPS_RW 2
#define OPS_INC 3
#define OPS_MIN 4
#define OPS_MAX 5

//user function

void multidim_reduce_kernel(const ptrm_double val,
  double *redu_dat1) {

  redu_dat1[0] = redu_dat1[0] + OPS_ACCM(val, 0,0,0,0);
  redu_dat1[1] = redu_dat1[1] + OPS_ACCM(val, 1,0,0,0);
  redu_dat1[2] = redu_dat1[2] + OPS_ACCM(val, 2,0,0,0);
}


__kernel void ops_multidim_reduce_kernel(
__global const double* restrict arg0,
__global double* restrict arg1,
__local double* scratch1,
int r_bytes1,
const int base0,
const int size0,
const int size1,
const int size2 ){

  arg1 += r_bytes1;
  double arg1_l[3];
  for (int d=0; d<3; d++) arg1_l[d] = ZERO_double;

  int idx_y = get_global_id(1);
  int idx_z = get_global_id(2);
  int idx_x = get_global_id(0);

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    #ifdef OPS_SOA
    const ptrm_double ptr0 = { &arg0[base0 + idx_x * 1 + idx_y * 1 * xdim0_multidim_reduce_kernel + idx_z * 1 * xdim0_multidim_reduce_kernel * ydim0_multidim_reduce_kernel], xdim0_multidim_reduce_kernel, ydim0_multidim_reduce_kernel, zdim0_multidim_reduce_kernel};
    #else
    const ptrm_double ptr0 = { &arg0[base0 + idx_x * 1 + idx_y * 1 * xdim0_multidim_reduce_kernel + idx_z * 1 * xdim0_multidim_reduce_kernel * ydim0_multidim_reduce_kernel], xdim0_multidim_reduce_kernel, ydim0_multidim_reduce_kernel, 3};
    #endif
    multidim_reduce_kernel(ptr0,
                           arg1_l);
  }
  int group_index = get_group_id(0) + get_group_id(1)*get_num_groups(0)+ get_group_id(2)*get_num_groups(0)*get_num_groups(1);
  for (int d=0; d<3; d++)
    reduce_double(arg1_l[d], scratch1, &arg1[group_index*3+d], OPS_INC);

}
