//
// auto-generated by ops.py
//
#include "./OpenMP4/tea_leaf_common.h"
#include <omp.h>
#define OPS_GPU

extern int xdim0_update_halo_kernel1_b2;
extern int xdim1_update_halo_kernel1_b2;
extern int xdim2_update_halo_kernel1_b2;
extern int xdim3_update_halo_kernel1_b2;
extern int xdim4_update_halo_kernel1_b2;
extern int xdim5_update_halo_kernel1_b2;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5

#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim0_update_halo_kernel1_b2 * 1 * 1 + x +              \
   xdim0_update_halo_kernel1_b2 * (y))
#define OPS_ACC1(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim1_update_halo_kernel1_b2 * 1 * 1 + x +              \
   xdim1_update_halo_kernel1_b2 * (y))
#define OPS_ACC2(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim2_update_halo_kernel1_b2 * 1 * 1 + x +              \
   xdim2_update_halo_kernel1_b2 * (y))
#define OPS_ACC3(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim3_update_halo_kernel1_b2 * 1 * 1 + x +              \
   xdim3_update_halo_kernel1_b2 * (y))
#define OPS_ACC4(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim4_update_halo_kernel1_b2 * 1 * 1 + x +              \
   xdim4_update_halo_kernel1_b2 * (y))
#define OPS_ACC5(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim5_update_halo_kernel1_b2 * 1 * 1 + x +              \
   xdim5_update_halo_kernel1_b2 * (y))

// user function

void update_halo_kernel1_b2_c_wrapper(double *p_a0, double *p_a1, double *p_a2,
                                      double *p_a3, double *p_a4, double *p_a5,
                                      int *p_a6, int tot6, int x_size,
                                      int y_size) {
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for
#endif
  for (int i = 0; i < y_size * x_size; i++) {
    const int id =
        omp_get_num_threads() * omp_get_team_num() + omp_get_thread_num();
    const int n_x = id % x_size;
    const int n_y = id / x_size;
    double *density0 = p_a0;

    double *energy0 = p_a1;
    double *energy1 = p_a2;

    double *u = p_a3;
    double *p = p_a4;

    double *sd = p_a5;
    const int *fields = p_a6;

    if (fields[FIELD_DENSITY] == 1)
      density0[OPS_ACC0(0, 0)] = density0[OPS_ACC0(0, 3)];
    if (fields[FIELD_ENERGY0] == 1)
      energy0[OPS_ACC1(0, 0)] = energy0[OPS_ACC1(0, 3)];
    if (fields[FIELD_ENERGY1] == 1)
      energy1[OPS_ACC2(0, 0)] = energy1[OPS_ACC2(0, 3)];
    if (fields[FIELD_U] == 1)
      u[OPS_ACC3(0, 0)] = u[OPS_ACC3(0, 3)];
    if (fields[FIELD_P] == 1)
      p[OPS_ACC4(0, 0)] = p[OPS_ACC4(0, 3)];
    if (fields[FIELD_SD] == 1)
      sd[OPS_ACC5(0, 0)] = sd[OPS_ACC5(0, 3)];
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
