//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"
#include <omp.h>
#define OPS_GPU

extern int xdim0_update_halo_kernel2_zvel_plus_4_bot;
extern int ydim0_update_halo_kernel2_zvel_plus_4_bot;
extern int xdim1_update_halo_kernel2_zvel_plus_4_bot;
extern int ydim1_update_halo_kernel2_zvel_plus_4_bot;

#undef OPS_ACC0
#undef OPS_ACC1

#define OPS_ACC0(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim0_update_halo_kernel2_zvel_plus_4_bot * 1 * 1 +     \
   n_z * xdim0_update_halo_kernel2_zvel_plus_4_bot *                           \
       ydim0_update_halo_kernel2_zvel_plus_4_bot * 1 +                         \
   x + xdim0_update_halo_kernel2_zvel_plus_4_bot * (y) +                       \
   xdim0_update_halo_kernel2_zvel_plus_4_bot *                                 \
       ydim0_update_halo_kernel2_zvel_plus_4_bot * (z))
#define OPS_ACC1(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim1_update_halo_kernel2_zvel_plus_4_bot * 1 * 1 +     \
   n_z * xdim1_update_halo_kernel2_zvel_plus_4_bot *                           \
       ydim1_update_halo_kernel2_zvel_plus_4_bot * 1 +                         \
   x + xdim1_update_halo_kernel2_zvel_plus_4_bot * (y) +                       \
   xdim1_update_halo_kernel2_zvel_plus_4_bot *                                 \
       ydim1_update_halo_kernel2_zvel_plus_4_bot * (z))

// user function

void update_halo_kernel2_zvel_plus_4_bot_c_wrapper(double *p_a0, double *p_a1,
                                                   int *p_a2, int tot2,
                                                   int x_size, int y_size,
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
    double *zvel0 = p_a0;

    double *zvel1 = p_a1;

    const int *fields = p_a2;

    if (fields[FIELD_ZVEL0] == 1)
      zvel0[OPS_ACC0(0, 0, 0)] = zvel0[OPS_ACC0(0, 4, 0)];
    if (fields[FIELD_ZVEL1] == 1)
      zvel1[OPS_ACC1(0, 0, 0)] = zvel1[OPS_ACC1(0, 4, 0)];
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
