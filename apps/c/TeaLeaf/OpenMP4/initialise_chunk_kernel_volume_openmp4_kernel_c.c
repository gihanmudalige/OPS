//
// auto-generated by ops.py
//
#include "./OpenMP4/tea_leaf_common.h"
#include <omp.h>
#define OPS_GPU

extern int xdim0_initialise_chunk_kernel_volume;
extern int xdim1_initialise_chunk_kernel_volume;
extern int xdim2_initialise_chunk_kernel_volume;
extern int xdim3_initialise_chunk_kernel_volume;
extern int xdim4_initialise_chunk_kernel_volume;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4

#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim0_initialise_chunk_kernel_volume * 1 * 1 + x +      \
   xdim0_initialise_chunk_kernel_volume * (y))
#define OPS_ACC1(x, y)                                                         \
  (n_x * 0 * 1 + n_y * xdim1_initialise_chunk_kernel_volume * 1 * 1 + x +      \
   xdim1_initialise_chunk_kernel_volume * (y))
#define OPS_ACC2(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim2_initialise_chunk_kernel_volume * 1 * 1 + x +      \
   xdim2_initialise_chunk_kernel_volume * (y))
#define OPS_ACC3(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim3_initialise_chunk_kernel_volume * 0 * 1 + x +      \
   xdim3_initialise_chunk_kernel_volume * (y))
#define OPS_ACC4(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim4_initialise_chunk_kernel_volume * 1 * 1 + x +      \
   xdim4_initialise_chunk_kernel_volume * (y))

// user function

void initialise_chunk_kernel_volume_c_wrapper(double *p_a0, double *p_a1,
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
    double *volume = p_a0;

    const double *celldy = p_a1;
    double *xarea = p_a2;

    const double *celldx = p_a3;
    double *yarea = p_a4;

    double d_x, d_y;

    d_x = (grid.xmax - grid.xmin) / (double)grid.x_cells;
    d_y = (grid.ymax - grid.ymin) / (double)grid.y_cells;

    volume[OPS_ACC0(0, 0)] = d_x * d_y;
    xarea[OPS_ACC2(0, 0)] = celldy[OPS_ACC1(0, 0)];
    yarea[OPS_ACC4(0, 0)] = celldx[OPS_ACC3(0, 0)];
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
