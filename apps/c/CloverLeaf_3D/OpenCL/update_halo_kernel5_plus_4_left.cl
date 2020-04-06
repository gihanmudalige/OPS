//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64:enable

#include "user_types.h"
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

inline void update_halo_kernel5_plus_4_left(ptr_double vol_flux_z, 
  ptr_double mass_flux_z, 
  const __global int* restrict  fields) {
  if(fields[FIELD_VOL_FLUX_Z] == 1) OPS_ACCS(vol_flux_z, 0,0,0) = (OPS_ACCS(vol_flux_z, 4,0,0));
  if(fields[FIELD_MASS_FLUX_Z] == 1) OPS_ACCS(mass_flux_z, 0,0,0) = (OPS_ACCS(mass_flux_z, 4,0,0));
}


__kernel void ops_update_halo_kernel5_plus_4_left(
__global double* restrict arg0,
__global double* restrict arg1,
__global const int* restrict arg2,
const int base0,
const int base1,
const int size0,
const int size1,
const int size2 ){


  int idx_y = get_global_id(1);
  int idx_z = get_global_id(2);
  int idx_x = get_global_id(0);

  if (idx_x < size0 && idx_y < size1 && idx_z < size2) {
    ptr_double ptr0 = { &arg0[base0 + idx_x * 1*1 + idx_y * 1*1 * xdim0_update_halo_kernel5_plus_4_left + idx_z * 1*1 * xdim0_update_halo_kernel5_plus_4_left * ydim0_update_halo_kernel5_plus_4_left], xdim0_update_halo_kernel5_plus_4_left, ydim0_update_halo_kernel5_plus_4_left};
    ptr_double ptr1 = { &arg1[base1 + idx_x * 1*1 + idx_y * 1*1 * xdim1_update_halo_kernel5_plus_4_left + idx_z * 1*1 * xdim1_update_halo_kernel5_plus_4_left * ydim1_update_halo_kernel5_plus_4_left], xdim1_update_halo_kernel5_plus_4_left, ydim1_update_halo_kernel5_plus_4_left};
    update_halo_kernel5_plus_4_left(ptr0,
                       ptr1,
                       arg2);
  }

}
