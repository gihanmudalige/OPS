//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64 : enable

#include "ops_opencl_reduction.h"
#include "user_types.h"

#ifndef MIN
#define MIN(a, b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b) ((a > b) ? (a) : (b))
#endif
#ifndef SIGN
#define SIGN(a, b) ((b < 0.0) ? (a * (-1)) : (a))
#endif
#define OPS_READ 0
#define OPS_WRITE 1
#define OPS_RW 2
#define OPS_INC 3
#define OPS_MIN 4
#define OPS_MAX 5
#define ZERO_double 0.0;
#define INFINITY_double INFINITY;
#define ZERO_float 0.0f;
#define INFINITY_float INFINITY;
#define ZERO_int 0;
#define INFINITY_int INFINITY;
#define ZERO_uint 0;
#define INFINITY_uint INFINITY;
#define ZERO_ll 0;
#define INFINITY_ll INFINITY;
#define ZERO_ull 0;
#define INFINITY_ull INFINITY;
#define ZERO_bool 0;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3

#define OPS_ACC0(x, y) (x + xdim0_tea_leaf_cg_calc_w_reduce_kernel * (y))
#define OPS_ACC1(x, y) (x + xdim1_tea_leaf_cg_calc_w_reduce_kernel * (y))
#define OPS_ACC2(x, y) (x + xdim2_tea_leaf_cg_calc_w_reduce_kernel * (y))
#define OPS_ACC3(x, y) (x + xdim3_tea_leaf_cg_calc_w_reduce_kernel * (y))

// user function
void tea_leaf_cg_calc_w_reduce_kernel(
    __global double *restrict w, const __global double *restrict Kx,
    const __global double *restrict Ky, const __global double *restrict p,
    const double *restrict rx, const double *restrict ry, double *restrict pw)

{
  w[OPS_ACC0(0, 0)] = (1.0 + (*ry) * (Ky[OPS_ACC2(0, 1)] + Ky[OPS_ACC2(0, 0)]) +
                       (*rx) * (Kx[OPS_ACC1(1, 0)] + Kx[OPS_ACC1(0, 0)])) *
                          p[OPS_ACC3(0, 0)] -
                      (*ry) * (Ky[OPS_ACC2(0, 1)] * p[OPS_ACC3(0, 1)] +
                               Ky[OPS_ACC2(0, 0)] * p[OPS_ACC3(0, -1)]) -
                      (*rx) * (Kx[OPS_ACC1(1, 0)] * p[OPS_ACC3(1, 0)] +
                               Kx[OPS_ACC1(0, 0)] * p[OPS_ACC3(-1, 0)]);
  *pw = *pw + w[OPS_ACC0(0, 0)] * p[OPS_ACC3(0, 0)];
}

__kernel void ops_tea_leaf_cg_calc_w_reduce_kernel(
    __global double *restrict arg0, __global const double *restrict arg1,
    __global const double *restrict arg2, __global const double *restrict arg3,
    const double arg4, const double arg5, __global double *restrict arg6,
    __local double *scratch6, int r_bytes6, const int base0, const int base1,
    const int base2, const int base3, const int size0, const int size1) {

  arg6 += r_bytes6;
  double arg6_l[1];
  for (int d = 0; d < 1; d++)
    arg6_l[d] = ZERO_double;

  int idx_y = get_global_id(1);
  int idx_x = get_global_id(0);

  if (idx_x < size0 && idx_y < size1) {
    tea_leaf_cg_calc_w_reduce_kernel(
        &arg0[base0 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim0_tea_leaf_cg_calc_w_reduce_kernel],
        &arg1[base1 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim1_tea_leaf_cg_calc_w_reduce_kernel],
        &arg2[base2 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim2_tea_leaf_cg_calc_w_reduce_kernel],
        &arg3[base3 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim3_tea_leaf_cg_calc_w_reduce_kernel],
        &arg4, &arg5, arg6_l);
  }
  int group_index = get_group_id(0) + get_group_id(1) * get_num_groups(0) +
                    get_group_id(2) * get_num_groups(0) * get_num_groups(1);
  for (int d = 0; d < 1; d++)
    reduce_double(arg6_l[d], scratch6, &arg6[group_index * 1 + d], OPS_INC);
}
