//
// auto-generated by ops.py
//

int xdim0_update_halo_kernel2_xvel_plus_2_bot;
int ydim0_update_halo_kernel2_xvel_plus_2_bot;
int xdim1_update_halo_kernel2_xvel_plus_2_bot;
int ydim1_update_halo_kernel2_xvel_plus_2_bot;

#define OPS_ACC0(x, y, z)                                                      \
  (n_x * 1 + n_y * xdim0_update_halo_kernel2_xvel_plus_2_bot * 1 +             \
   n_z * xdim0_update_halo_kernel2_xvel_plus_2_bot *                           \
       ydim0_update_halo_kernel2_xvel_plus_2_bot * 1 +                         \
   x + xdim0_update_halo_kernel2_xvel_plus_2_bot * (y) +                       \
   xdim0_update_halo_kernel2_xvel_plus_2_bot *                                 \
       ydim0_update_halo_kernel2_xvel_plus_2_bot * (z))
#define OPS_ACC1(x, y, z)                                                      \
  (n_x * 1 + n_y * xdim1_update_halo_kernel2_xvel_plus_2_bot * 1 +             \
   n_z * xdim1_update_halo_kernel2_xvel_plus_2_bot *                           \
       ydim1_update_halo_kernel2_xvel_plus_2_bot * 1 +                         \
   x + xdim1_update_halo_kernel2_xvel_plus_2_bot * (y) +                       \
   xdim1_update_halo_kernel2_xvel_plus_2_bot *                                 \
       ydim1_update_halo_kernel2_xvel_plus_2_bot * (z))

// user function

void update_halo_kernel2_xvel_plus_2_bot_c_wrapper(double *restrict xvel0,
                                                   double *restrict xvel1,
                                                   const int *restrict fields,
                                                   int x_size, int y_size,
                                                   int z_size) {
#pragma omp parallel for
  for (int n_z = 0; n_z < z_size; n_z++) {
    for (int n_y = 0; n_y < y_size; n_y++) {
      for (int n_x = 0; n_x < x_size; n_x++) {

        if (fields[FIELD_XVEL0] == 1)
          xvel0[OPS_ACC0(0, 0, 0)] = xvel0[OPS_ACC0(0, 2, 0)];
        if (fields[FIELD_XVEL1] == 1)
          xvel1[OPS_ACC1(0, 0, 0)] = xvel1[OPS_ACC1(0, 2, 0)];
      }
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
