//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"
#include <omp.h>
#define OPS_GPU

extern int xdim0_flux_calc_kernelz;
extern int ydim0_flux_calc_kernelz;
extern int xdim1_flux_calc_kernelz;
extern int ydim1_flux_calc_kernelz;
extern int xdim2_flux_calc_kernelz;
extern int ydim2_flux_calc_kernelz;
extern int xdim3_flux_calc_kernelz;
extern int ydim3_flux_calc_kernelz;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3

#define OPS_ACC0(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim0_flux_calc_kernelz * 1 * 1 +                       \
   n_z * xdim0_flux_calc_kernelz * ydim0_flux_calc_kernelz * 1 + x +           \
   xdim0_flux_calc_kernelz * (y) +                                             \
   xdim0_flux_calc_kernelz * ydim0_flux_calc_kernelz * (z))
#define OPS_ACC1(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim1_flux_calc_kernelz * 1 * 1 +                       \
   n_z * xdim1_flux_calc_kernelz * ydim1_flux_calc_kernelz * 1 + x +           \
   xdim1_flux_calc_kernelz * (y) +                                             \
   xdim1_flux_calc_kernelz * ydim1_flux_calc_kernelz * (z))
#define OPS_ACC2(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim2_flux_calc_kernelz * 1 * 1 +                       \
   n_z * xdim2_flux_calc_kernelz * ydim2_flux_calc_kernelz * 1 + x +           \
   xdim2_flux_calc_kernelz * (y) +                                             \
   xdim2_flux_calc_kernelz * ydim2_flux_calc_kernelz * (z))
#define OPS_ACC3(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim3_flux_calc_kernelz * 1 * 1 +                       \
   n_z * xdim3_flux_calc_kernelz * ydim3_flux_calc_kernelz * 1 + x +           \
   xdim3_flux_calc_kernelz * (y) +                                             \
   xdim3_flux_calc_kernelz * ydim3_flux_calc_kernelz * (z))

// user function

void flux_calc_kernelz_c_wrapper(double *p_a0, double *p_a1, double *p_a2,
                                 double *p_a3, int x_size, int y_size,
                                 int z_size) {
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for
#endif
  for (int i = 0; i < y_size * x_size * z_size; i++) {
    const int id =
        omp_get_num_threads() * omp_get_team_num() + omp_get_thread_num();
    const int n_x = id % x_size;
    const int n_y = (id / x_size) % y_size;
    const int n_z = id / (x_size * y_size);
    double *vol_flux_z = p_a0;

    const double *zarea = p_a1;

    const double *zvel0 = p_a2;

    const double *zvel1 = p_a3;

    vol_flux_z[OPS_ACC0(0, 0, 0)] =
        0.125 * dt * (zarea[OPS_ACC1(0, 0, 0)]) *
        (zvel0[OPS_ACC2(0, 0, 0)] + zvel0[OPS_ACC2(1, 0, 0)] +
         zvel0[OPS_ACC2(1, 0, 0)] + zvel0[OPS_ACC2(1, 1, 0)] +
         zvel1[OPS_ACC3(0, 0, 0)] + zvel1[OPS_ACC3(1, 0, 0)] +
         zvel1[OPS_ACC3(0, 1, 0)] + zvel1[OPS_ACC3(1, 1, 0)]);
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
