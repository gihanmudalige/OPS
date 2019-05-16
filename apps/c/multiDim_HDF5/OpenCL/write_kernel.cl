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

#undef OPS_ACC1
#undef OPS_ACC2

#undef OPS_ACC_MD0

#define OPS_ACC1(x, y, z)                                                      \
  (x + xdim1_write_kernel * (y) + xdim1_write_kernel * ydim1_write_kernel * (z))
#define OPS_ACC2(x, y, z)                                                      \
  (x + xdim2_write_kernel * (y) + xdim2_write_kernel * ydim2_write_kernel * (z))

#define OPS_ACC_MD0(d, x, y, z)                                                \
  ((x)*2 + (d) + (xdim0_write_kernel * (y)*2) +                                \
   (xdim0_write_kernel * ydim0_write_kernel * (z)*2))

// user function
void write_kernel(__global double *restrict mult,
                  __global double *restrict single,
                  __global int *restrict digit, const int *restrict idx)

{

  mult[OPS_ACC_MD0(0, 0, 0, 0)] = 1;

  mult[OPS_ACC_MD0(1, 0, 0, 0)] = 2;

  single[OPS_ACC1(0, 0, 0)] = 3;

  digit[OPS_ACC2(0, 0, 0)] = idx[0] * 100 + idx[1] * 10 + idx[2];
}

__kernel void ops_write_kernel(__global double *restrict arg0,
                               __global double *restrict arg1,
                               __global int *restrict arg2, const int base0,
                               const int base1, const int base2, int arg_idx0,
                               int arg_idx1, int arg_idx2, const int size0,
                               const int size1, const int size2) {

  int idx_y = get_global_id(1);
  int idx_z = get_global_id(2);
  int idx_x = get_global_id(0);

  int arg_idx[3];
  arg_idx[0] = arg_idx0 + idx_x;
  arg_idx[1] = arg_idx1 + idx_y;
  arg_idx[2] = arg_idx2 + idx_z;
  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    write_kernel(
        &arg0[base0 + idx_x * 1 * 2 + idx_y * 1 * 2 * xdim0_write_kernel +
              idx_z * 1 * 2 * xdim0_write_kernel * ydim0_write_kernel],
        &arg1[base1 + idx_x * 1 * 1 + idx_y * 1 * 1 * xdim1_write_kernel +
              idx_z * 1 * 1 * xdim1_write_kernel * ydim1_write_kernel],
        &arg2[base2 + idx_x * 1 * 1 + idx_y * 1 * 1 * xdim2_write_kernel +
              idx_z * 1 * 1 * xdim2_write_kernel * ydim2_write_kernel],
        arg_idx);
  }
}
