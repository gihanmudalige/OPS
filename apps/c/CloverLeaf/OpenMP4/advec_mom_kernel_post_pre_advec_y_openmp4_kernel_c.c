//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"
#include <omp.h>
#define OPS_GPU

extern int xdim0_advec_mom_kernel_post_pre_advec_y;
extern int xdim1_advec_mom_kernel_post_pre_advec_y;
extern int xdim2_advec_mom_kernel_post_pre_advec_y;
extern int xdim3_advec_mom_kernel_post_pre_advec_y;
extern int xdim4_advec_mom_kernel_post_pre_advec_y;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4

#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim0_advec_mom_kernel_post_pre_advec_y * 1 * 1 + x +   \
   xdim0_advec_mom_kernel_post_pre_advec_y * (y))
#define OPS_ACC1(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim1_advec_mom_kernel_post_pre_advec_y * 1 * 1 + x +   \
   xdim1_advec_mom_kernel_post_pre_advec_y * (y))
#define OPS_ACC2(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim2_advec_mom_kernel_post_pre_advec_y * 1 * 1 + x +   \
   xdim2_advec_mom_kernel_post_pre_advec_y * (y))
#define OPS_ACC3(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim3_advec_mom_kernel_post_pre_advec_y * 1 * 1 + x +   \
   xdim3_advec_mom_kernel_post_pre_advec_y * (y))
#define OPS_ACC4(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim4_advec_mom_kernel_post_pre_advec_y * 1 * 1 + x +   \
   xdim4_advec_mom_kernel_post_pre_advec_y * (y))

// user function

void advec_mom_kernel_post_pre_advec_y_c_wrapper(double *p_a0, double *p_a1,
                                                 double *p_a2, double *p_a3,
                                                 double *p_a4, int x_size,
                                                 int y_size) {
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for
#endif
  for (int i = 0; i < y_size * x_size; i++) {
    const int id =
        omp_get_num_threads() * omp_get_team_num() + omp_get_thread_num();
    const int n_x = id % x_size;
    const int n_y = id / x_size;
    double *node_mass_post = p_a0;

    const double *post_vol = p_a1;
    const double *density1 = p_a2;

    double *node_mass_pre = p_a3;
    const double *node_flux = p_a4;

    node_mass_post[OPS_ACC0(0, 0)] =
        0.25 * (density1[OPS_ACC2(0, -1)] * post_vol[OPS_ACC1(0, -1)] +
                density1[OPS_ACC2(0, 0)] * post_vol[OPS_ACC1(0, 0)] +
                density1[OPS_ACC2(-1, -1)] * post_vol[OPS_ACC1(-1, -1)] +
                density1[OPS_ACC2(-1, 0)] * post_vol[OPS_ACC1(-1, 0)]);

    node_mass_pre[OPS_ACC3(0, 0)] = node_mass_post[OPS_ACC0(0, 0)] -
                                    node_flux[OPS_ACC4(0, -1)] +
                                    node_flux[OPS_ACC4(0, 0)];
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
