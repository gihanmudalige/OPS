//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"
#include <omp.h>
#define OPS_GPU

extern int xdim0_advec_mom_kernel2_y;
extern int ydim0_advec_mom_kernel2_y;
extern int xdim1_advec_mom_kernel2_y;
extern int ydim1_advec_mom_kernel2_y;
extern int xdim2_advec_mom_kernel2_y;
extern int ydim2_advec_mom_kernel2_y;
extern int xdim3_advec_mom_kernel2_y;
extern int ydim3_advec_mom_kernel2_y;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3

#define OPS_ACC0(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim0_advec_mom_kernel2_y * 1 * 1 +                     \
   n_z * xdim0_advec_mom_kernel2_y * ydim0_advec_mom_kernel2_y * 1 + x +       \
   xdim0_advec_mom_kernel2_y * (y) +                                           \
   xdim0_advec_mom_kernel2_y * ydim0_advec_mom_kernel2_y * (z))
#define OPS_ACC1(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim1_advec_mom_kernel2_y * 1 * 1 +                     \
   n_z * xdim1_advec_mom_kernel2_y * ydim1_advec_mom_kernel2_y * 1 + x +       \
   xdim1_advec_mom_kernel2_y * (y) +                                           \
   xdim1_advec_mom_kernel2_y * ydim1_advec_mom_kernel2_y * (z))
#define OPS_ACC2(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim2_advec_mom_kernel2_y * 1 * 1 +                     \
   n_z * xdim2_advec_mom_kernel2_y * ydim2_advec_mom_kernel2_y * 1 + x +       \
   xdim2_advec_mom_kernel2_y * (y) +                                           \
   xdim2_advec_mom_kernel2_y * ydim2_advec_mom_kernel2_y * (z))
#define OPS_ACC3(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim3_advec_mom_kernel2_y * 1 * 1 +                     \
   n_z * xdim3_advec_mom_kernel2_y * ydim3_advec_mom_kernel2_y * 1 + x +       \
   xdim3_advec_mom_kernel2_y * (y) +                                           \
   xdim3_advec_mom_kernel2_y * ydim3_advec_mom_kernel2_y * (z))

// user function

void advec_mom_kernel2_y_c_wrapper(double *p_a0, double *p_a1, double *p_a2,
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
    double *vel1 = p_a0;

    const double *node_mass_post = p_a1;

    const double *node_mass_pre = p_a2;

    const double *mom_flux = p_a3;

    vel1[OPS_ACC0(0, 0, 0)] =
        (vel1[OPS_ACC0(0, 0, 0)] * node_mass_pre[OPS_ACC2(0, 0, 0)] +
         mom_flux[OPS_ACC3(0, -1, 0)] - mom_flux[OPS_ACC3(0, 0, 0)]) /
        node_mass_post[OPS_ACC1(0, 0, 0)];
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3