//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"
#include <omp.h>
#define OPS_GPU

extern int xdim0_reset_field_kernel1;
extern int xdim1_reset_field_kernel1;
extern int xdim2_reset_field_kernel1;
extern int xdim3_reset_field_kernel1;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3

#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim0_reset_field_kernel1 * 1 * 1 + x +                 \
   xdim0_reset_field_kernel1 * (y))
#define OPS_ACC1(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim1_reset_field_kernel1 * 1 * 1 + x +                 \
   xdim1_reset_field_kernel1 * (y))
#define OPS_ACC2(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim2_reset_field_kernel1 * 1 * 1 + x +                 \
   xdim2_reset_field_kernel1 * (y))
#define OPS_ACC3(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim3_reset_field_kernel1 * 1 * 1 + x +                 \
   xdim3_reset_field_kernel1 * (y))

// user function

void reset_field_kernel1_c_wrapper(double *p_a0, double *p_a1, double *p_a2,
                                   double *p_a3, int x_size, int y_size) {
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for
#endif
  for (int i = 0; i < y_size * x_size; i++) {
    const int id =
        omp_get_num_threads() * omp_get_team_num() + omp_get_thread_num();
    const int n_x = id % x_size;
    const int n_y = id / x_size;
    double *density0 = p_a0;

    const double *density1 = p_a1;
    double *energy0 = p_a2;

    const double *energy1 = p_a3;

    density0[OPS_ACC0(0, 0)] = density1[OPS_ACC1(0, 0)];
    energy0[OPS_ACC2(0, 0)] = energy1[OPS_ACC3(0, 0)];
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
