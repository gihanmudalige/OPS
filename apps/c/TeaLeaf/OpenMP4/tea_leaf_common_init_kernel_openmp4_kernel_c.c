//
// auto-generated by ops.py
//
#include "./OpenMP4/tea_leaf_common.h"
#include <omp.h>
#define OPS_GPU

extern int xdim0_tea_leaf_common_init_kernel;
extern int xdim1_tea_leaf_common_init_kernel;
extern int xdim2_tea_leaf_common_init_kernel;
extern int xdim3_tea_leaf_common_init_kernel;
extern int xdim4_tea_leaf_common_init_kernel;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4

#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim0_tea_leaf_common_init_kernel * 1 * 1 + x +         \
   xdim0_tea_leaf_common_init_kernel * (y))
#define OPS_ACC1(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim1_tea_leaf_common_init_kernel * 1 * 1 + x +         \
   xdim1_tea_leaf_common_init_kernel * (y))
#define OPS_ACC2(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim2_tea_leaf_common_init_kernel * 1 * 1 + x +         \
   xdim2_tea_leaf_common_init_kernel * (y))
#define OPS_ACC3(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim3_tea_leaf_common_init_kernel * 1 * 1 + x +         \
   xdim3_tea_leaf_common_init_kernel * (y))
#define OPS_ACC4(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim4_tea_leaf_common_init_kernel * 1 * 1 + x +         \
   xdim4_tea_leaf_common_init_kernel * (y))

// user function

void tea_leaf_common_init_kernel_c_wrapper(double *p_a0, double *p_a1,
                                           double *p_a2, double *p_a3,
                                           double *p_a4, double p_a5,
                                           double p_a6, int x_size,
                                           int y_size) {
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for
#endif
  for (int i = 0; i < y_size * x_size; i++) {
    const int id =
        omp_get_num_threads() * omp_get_team_num() + omp_get_thread_num();
    const int n_x = id % x_size;
    const int n_y = id / x_size;
    double *w = p_a0;

    double *r = p_a1;
    const double *Kx = p_a2;

    const double *Ky = p_a3;
    const double *u = p_a4;

    const double *rx = &p_a5;
    const double *ry = &p_a6;

    w[OPS_ACC0(0, 0)] =
        (1.0 + (*ry) * (Ky[OPS_ACC3(0, 1)] + Ky[OPS_ACC3(0, 0)]) +
         (*rx) * (Kx[OPS_ACC2(1, 0)] + Kx[OPS_ACC2(0, 0)])) *
            u[OPS_ACC4(0, 0)] -
        (*ry) * (Ky[OPS_ACC3(0, 1)] * u[OPS_ACC4(0, 1)] +
                 Ky[OPS_ACC3(0, 0)] * u[OPS_ACC4(0, -1)]) -
        (*rx) * (Kx[OPS_ACC2(1, 0)] * u[OPS_ACC4(1, 0)] +
                 Kx[OPS_ACC2(0, 0)] * u[OPS_ACC4(-1, 0)]);
    r[OPS_ACC1(0, 0)] = u[OPS_ACC4(0, 0)] - w[OPS_ACC0(0, 0)];
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
