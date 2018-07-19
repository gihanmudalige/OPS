//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"
#include <omp.h>
#define OPS_GPU

extern int xdim0_update_halo_kernel1_t2;
extern int ydim0_update_halo_kernel1_t2;
extern int xdim1_update_halo_kernel1_t2;
extern int ydim1_update_halo_kernel1_t2;
extern int xdim2_update_halo_kernel1_t2;
extern int ydim2_update_halo_kernel1_t2;
extern int xdim3_update_halo_kernel1_t2;
extern int ydim3_update_halo_kernel1_t2;
extern int xdim4_update_halo_kernel1_t2;
extern int ydim4_update_halo_kernel1_t2;
extern int xdim5_update_halo_kernel1_t2;
extern int ydim5_update_halo_kernel1_t2;
extern int xdim6_update_halo_kernel1_t2;
extern int ydim6_update_halo_kernel1_t2;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6

#define OPS_ACC0(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim0_update_halo_kernel1_t2 * 1 * 1 +                  \
   n_z * xdim0_update_halo_kernel1_t2 * ydim0_update_halo_kernel1_t2 * 1 + x + \
   xdim0_update_halo_kernel1_t2 * (y) +                                        \
   xdim0_update_halo_kernel1_t2 * ydim0_update_halo_kernel1_t2 * (z))
#define OPS_ACC1(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim1_update_halo_kernel1_t2 * 1 * 1 +                  \
   n_z * xdim1_update_halo_kernel1_t2 * ydim1_update_halo_kernel1_t2 * 1 + x + \
   xdim1_update_halo_kernel1_t2 * (y) +                                        \
   xdim1_update_halo_kernel1_t2 * ydim1_update_halo_kernel1_t2 * (z))
#define OPS_ACC2(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim2_update_halo_kernel1_t2 * 1 * 1 +                  \
   n_z * xdim2_update_halo_kernel1_t2 * ydim2_update_halo_kernel1_t2 * 1 + x + \
   xdim2_update_halo_kernel1_t2 * (y) +                                        \
   xdim2_update_halo_kernel1_t2 * ydim2_update_halo_kernel1_t2 * (z))
#define OPS_ACC3(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim3_update_halo_kernel1_t2 * 1 * 1 +                  \
   n_z * xdim3_update_halo_kernel1_t2 * ydim3_update_halo_kernel1_t2 * 1 + x + \
   xdim3_update_halo_kernel1_t2 * (y) +                                        \
   xdim3_update_halo_kernel1_t2 * ydim3_update_halo_kernel1_t2 * (z))
#define OPS_ACC4(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim4_update_halo_kernel1_t2 * 1 * 1 +                  \
   n_z * xdim4_update_halo_kernel1_t2 * ydim4_update_halo_kernel1_t2 * 1 + x + \
   xdim4_update_halo_kernel1_t2 * (y) +                                        \
   xdim4_update_halo_kernel1_t2 * ydim4_update_halo_kernel1_t2 * (z))
#define OPS_ACC5(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim5_update_halo_kernel1_t2 * 1 * 1 +                  \
   n_z * xdim5_update_halo_kernel1_t2 * ydim5_update_halo_kernel1_t2 * 1 + x + \
   xdim5_update_halo_kernel1_t2 * (y) +                                        \
   xdim5_update_halo_kernel1_t2 * ydim5_update_halo_kernel1_t2 * (z))
#define OPS_ACC6(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim6_update_halo_kernel1_t2 * 1 * 1 +                  \
   n_z * xdim6_update_halo_kernel1_t2 * ydim6_update_halo_kernel1_t2 * 1 + x + \
   xdim6_update_halo_kernel1_t2 * (y) +                                        \
   xdim6_update_halo_kernel1_t2 * ydim6_update_halo_kernel1_t2 * (z))

// user function

void update_halo_kernel1_t2_c_wrapper(double *p_a0, double *p_a1, double *p_a2,
                                      double *p_a3, double *p_a4, double *p_a5,
                                      double *p_a6, int *p_a7, int tot7,
                                      int x_size, int y_size, int z_size) {
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for
#endif
  for (int i = 0; i < y_size * x_size * z_size; i++) {
    const int id =
        omp_get_num_threads() * omp_get_team_num() + omp_get_thread_num();
    const int n_x = id % x_size;
    const int n_y = (id / x_size) % y_size;
    const int n_z = id / (x_size * y_size);
    double *density0 = p_a0;

    double *density1 = p_a1;

    double *energy0 = p_a2;

    double *energy1 = p_a3;

    double *pressure = p_a4;

    double *viscosity = p_a5;

    double *soundspeed = p_a6;

    const int *fields = p_a7;

    if (fields[FIELD_DENSITY0] == 1)
      density0[OPS_ACC0(0, 0, 0)] = density0[OPS_ACC0(0, -3, 0)];
    if (fields[FIELD_DENSITY1] == 1)
      density1[OPS_ACC1(0, 0, 0)] = density1[OPS_ACC1(0, -3, 0)];
    if (fields[FIELD_ENERGY0] == 1)
      energy0[OPS_ACC2(0, 0, 0)] = energy0[OPS_ACC2(0, -3, 0)];
    if (fields[FIELD_ENERGY1] == 1)
      energy1[OPS_ACC3(0, 0, 0)] = energy1[OPS_ACC3(0, -3, 0)];
    if (fields[FIELD_PRESSURE] == 1)
      pressure[OPS_ACC4(0, 0, 0)] = pressure[OPS_ACC4(0, -3, 0)];
    if (fields[FIELD_VISCOSITY] == 1)
      viscosity[OPS_ACC5(0, 0, 0)] = viscosity[OPS_ACC5(0, -3, 0)];
    if (fields[FIELD_SOUNDSPEED] == 1)
      soundspeed[OPS_ACC6(0, 0, 0)] = soundspeed[OPS_ACC6(0, -3, 0)];
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
