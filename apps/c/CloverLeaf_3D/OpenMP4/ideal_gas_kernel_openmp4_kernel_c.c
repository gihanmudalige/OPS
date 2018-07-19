//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"
#include <omp.h>
#define OPS_GPU

extern int xdim0_ideal_gas_kernel;
extern int ydim0_ideal_gas_kernel;
extern int xdim1_ideal_gas_kernel;
extern int ydim1_ideal_gas_kernel;
extern int xdim2_ideal_gas_kernel;
extern int ydim2_ideal_gas_kernel;
extern int xdim3_ideal_gas_kernel;
extern int ydim3_ideal_gas_kernel;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3

#define OPS_ACC0(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim0_ideal_gas_kernel * 1 * 1 +                        \
   n_z * xdim0_ideal_gas_kernel * ydim0_ideal_gas_kernel * 1 + x +             \
   xdim0_ideal_gas_kernel * (y) +                                              \
   xdim0_ideal_gas_kernel * ydim0_ideal_gas_kernel * (z))
#define OPS_ACC1(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim1_ideal_gas_kernel * 1 * 1 +                        \
   n_z * xdim1_ideal_gas_kernel * ydim1_ideal_gas_kernel * 1 + x +             \
   xdim1_ideal_gas_kernel * (y) +                                              \
   xdim1_ideal_gas_kernel * ydim1_ideal_gas_kernel * (z))
#define OPS_ACC2(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim2_ideal_gas_kernel * 1 * 1 +                        \
   n_z * xdim2_ideal_gas_kernel * ydim2_ideal_gas_kernel * 1 + x +             \
   xdim2_ideal_gas_kernel * (y) +                                              \
   xdim2_ideal_gas_kernel * ydim2_ideal_gas_kernel * (z))
#define OPS_ACC3(x, y, z)                                                      \
  (n_x * 1 * 1 + n_y * xdim3_ideal_gas_kernel * 1 * 1 +                        \
   n_z * xdim3_ideal_gas_kernel * ydim3_ideal_gas_kernel * 1 + x +             \
   xdim3_ideal_gas_kernel * (y) +                                              \
   xdim3_ideal_gas_kernel * ydim3_ideal_gas_kernel * (z))

// user function

void ideal_gas_kernel_c_wrapper(double *p_a0, double *p_a1, double *p_a2,
                                double *p_a3, int x_size, int y_size,
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
    const double *density = p_a0;

    const double *energy = p_a1;

    double *pressure = p_a2;

    double *soundspeed = p_a3;

    double sound_speed_squared, v, pressurebyenergy, pressurebyvolume;

    v = 1.0 / density[OPS_ACC0(0, 0, 0)];
    pressure[OPS_ACC2(0, 0, 0)] =
        (1.4 - 1.0) * density[OPS_ACC0(0, 0, 0)] * energy[OPS_ACC1(0, 0, 0)];

    pressurebyenergy = (1.4 - 1.0) * density[OPS_ACC0(0, 0, 0)];
    pressurebyvolume =
        -1.0 * density[OPS_ACC0(0, 0, 0)] * pressure[OPS_ACC2(0, 0, 0)];
    sound_speed_squared =
        v * v *
        (pressure[OPS_ACC2(0, 0, 0)] * pressurebyenergy - pressurebyvolume);
    soundspeed[OPS_ACC3(0, 0, 0)] = sqrt(sound_speed_squared);
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
