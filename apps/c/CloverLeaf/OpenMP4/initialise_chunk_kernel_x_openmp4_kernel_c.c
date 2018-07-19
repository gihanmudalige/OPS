//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"
#include <omp.h>
#define OPS_GPU

extern int xdim0_initialise_chunk_kernel_x;
extern int xdim1_initialise_chunk_kernel_x;
extern int xdim2_initialise_chunk_kernel_x;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2

#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim0_initialise_chunk_kernel_x * 0 * 1 + x +           \
   xdim0_initialise_chunk_kernel_x * (y))
#define OPS_ACC1(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim1_initialise_chunk_kernel_x * 0 * 1 + x +           \
   xdim1_initialise_chunk_kernel_x * (y))
#define OPS_ACC2(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim2_initialise_chunk_kernel_x * 0 * 1 + x +           \
   xdim2_initialise_chunk_kernel_x * (y))

// user function

void initialise_chunk_kernel_x_c_wrapper(double *p_a0, int *p_a1, double *p_a2,
                                         int x_size, int y_size) {
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for
#endif
  for (int i = 0; i < y_size * x_size; i++) {
    const int id =
        omp_get_num_threads() * omp_get_team_num() + omp_get_thread_num();
    const int n_x = id % x_size;
    const int n_y = id / x_size;
    double *vertexx = p_a0;

    const int *xx = p_a1;
    double *vertexdx = p_a2;

    int x_min = field.x_min - 2;
    double min_x, d_x;

    d_x = (grid.xmax - grid.xmin) / (double)grid.x_cells;
    min_x = grid.xmin + d_x * field.left;

    vertexx[OPS_ACC0(0, 0)] = min_x + d_x * (xx[OPS_ACC1(0, 0)] - x_min);
    vertexdx[OPS_ACC2(0, 0)] = (double)d_x;
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
