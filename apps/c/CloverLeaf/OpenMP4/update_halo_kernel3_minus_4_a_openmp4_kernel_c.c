//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"
#include <omp.h>
#define OPS_GPU

extern int xdim0_update_halo_kernel3_minus_4_a;
extern int xdim1_update_halo_kernel3_minus_4_a;

#undef OPS_ACC0
#undef OPS_ACC1

#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim0_update_halo_kernel3_minus_4_a * 1 * 1 + x +       \
   xdim0_update_halo_kernel3_minus_4_a * (y))
#define OPS_ACC1(x, y)                                                         \
  (n_x * 1 * 1 + n_y * xdim1_update_halo_kernel3_minus_4_a * 1 * 1 + x +       \
   xdim1_update_halo_kernel3_minus_4_a * (y))

// user function

void update_halo_kernel3_minus_4_a_c_wrapper(double *p_a0, double *p_a1,
                                             int *p_a2, int tot2, int x_size,
                                             int y_size) {
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for
#endif
  for (int i = 0; i < y_size * x_size; i++) {
    const int id =
        omp_get_num_threads() * omp_get_team_num() + omp_get_thread_num();
    const int n_x = id % x_size;
    const int n_y = id / x_size;
    double *vol_flux_x = p_a0;

    double *mass_flux_x = p_a1;
    const int *fields = p_a2;

    if (fields[FIELD_VOL_FLUX_X] == 1)
      vol_flux_x[OPS_ACC0(0, 0)] = -(vol_flux_x[OPS_ACC0(4, 0)]);
    if (fields[FIELD_MASS_FLUX_X] == 1)
      mass_flux_x[OPS_ACC1(0, 0)] = -(mass_flux_x[OPS_ACC1(4, 0)]);
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
