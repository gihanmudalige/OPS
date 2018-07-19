//
// auto-generated by ops.py
//
#include "./OpenMP4/tea_leaf_common.h"
#include <omp.h>
#define OPS_GPU

extern int xdim0_tea_leaf_dot_kernel;
extern int xdim1_tea_leaf_dot_kernel;

#undef OPS_ACC0
#undef OPS_ACC1

#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim0_tea_leaf_dot_kernel * 1 * 1 + x +                 \
   xdim0_tea_leaf_dot_kernel * (y))
#define OPS_ACC1(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim1_tea_leaf_dot_kernel * 1 * 1 + x +                 \
   xdim1_tea_leaf_dot_kernel * (y))

// user function

void tea_leaf_dot_kernel_c_wrapper(double *p_a0, double *p_a1, double *p_a2,
                                   int x_size, int y_size) {
  double p_a2_0 = p_a2[0];
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for map(tofrom : p_a2_0)          \
    reduction(+ : p_a2_0)
#endif
  for (int i = 0; i < y_size * x_size; i++) {
    const int id =
        omp_get_num_threads() * omp_get_team_num() + omp_get_thread_num();
    const int n_x = id % x_size;
    const int n_y = id / x_size;
    const double *r = p_a0;

    const double *p = p_a1;
    double *rro = &p_a2_0;

    *rro = *rro + r[OPS_ACC0(0, 0)] * p[OPS_ACC1(0, 0)];
  }
  p_a2[0] = p_a2_0;
}
#undef OPS_ACC0
#undef OPS_ACC1
