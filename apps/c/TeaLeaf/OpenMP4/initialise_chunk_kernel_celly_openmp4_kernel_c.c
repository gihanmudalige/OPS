//
// auto-generated by ops.py
//
#include "./OpenMP4/tea_leaf_common.h"
#include <omp.h>
#define OPS_GPU

extern int xdim0_initialise_chunk_kernel_celly;
extern int xdim1_initialise_chunk_kernel_celly;
extern int xdim2_initialise_chunk_kernel_celly;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2

#define OPS_ACC0(x, y)                                                         \
  (n_x * 0 * 1 + n_y * xdim0_initialise_chunk_kernel_celly * 1 * 1 + x +       \
   xdim0_initialise_chunk_kernel_celly * (y))
#define OPS_ACC1(x, y)                                                         \
  (n_x * 0 * 1 + n_y * xdim1_initialise_chunk_kernel_celly * 1 * 1 + x +       \
   xdim1_initialise_chunk_kernel_celly * (y))
#define OPS_ACC2(x, y)                                                         \
  (n_x * 0 * 1 + n_y * xdim2_initialise_chunk_kernel_celly * 1 * 1 + x +       \
   xdim2_initialise_chunk_kernel_celly * (y))

// user function

void initialise_chunk_kernel_celly_c_wrapper(double *p_a0, double *p_a1,
                                             double *p_a2, int x_size,
                                             int y_size) {
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for
#endif
  for (int i = 0; i < y_size * x_size; i++) {
    const int id =
        omp_get_num_threads() * omp_get_team_num() + omp_get_thread_num();
    const int n_x = id % x_size;
    const int n_y = id / x_size;
    const double *vertexy = p_a0;

    double *celly = p_a1;
    double *celldy = p_a2;

    double d_y;
    d_y = (grid.ymax - grid.ymin) / (double)grid.y_cells;

    celly[OPS_ACC1(0, 0)] =
        0.5 * (vertexy[OPS_ACC0(0, 0)] + vertexy[OPS_ACC0(0, 1)]);
    celldy[OPS_ACC2(0, 0)] = d_y;
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
