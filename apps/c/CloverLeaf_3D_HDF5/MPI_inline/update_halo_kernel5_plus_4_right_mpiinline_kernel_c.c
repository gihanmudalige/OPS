//
// auto-generated by ops.py
//

int xdim0_update_halo_kernel5_plus_4_right;
int ydim0_update_halo_kernel5_plus_4_right;
int xdim1_update_halo_kernel5_plus_4_right;
int ydim1_update_halo_kernel5_plus_4_right;

// user function

void update_halo_kernel5_plus_4_right_c_wrapper(double *restrict vol_flux_z_p,
                                                double *restrict mass_flux_z_p,
                                                const int *restrict fields,
                                                int x_size, int y_size,
                                                int z_size) {
#pragma omp parallel for
  for (int n_z = 0; n_z < z_size; n_z++) {
    for (int n_y = 0; n_y < y_size; n_y++) {
      for (int n_x = 0; n_x < x_size; n_x++) {
        ptr_double vol_flux_z = {
            vol_flux_z_p + n_x * 1 +
                n_y * xdim0_update_halo_kernel5_plus_4_right * 1 +
                n_z * xdim0_update_halo_kernel5_plus_4_right *
                    ydim0_update_halo_kernel5_plus_4_right * 1,
            xdim0_update_halo_kernel5_plus_4_right,
            ydim0_update_halo_kernel5_plus_4_right};
        ptr_double mass_flux_z = {
            mass_flux_z_p + n_x * 1 +
                n_y * xdim1_update_halo_kernel5_plus_4_right * 1 +
                n_z * xdim1_update_halo_kernel5_plus_4_right *
                    ydim1_update_halo_kernel5_plus_4_right * 1,
            xdim1_update_halo_kernel5_plus_4_right,
            ydim1_update_halo_kernel5_plus_4_right};

        if (fields[FIELD_VOL_FLUX_Z] == 1)
          OPS_ACC(vol_flux_z, 0, 0, 0) = (OPS_ACC(vol_flux_z, -4, 0, 0));
        if (fields[FIELD_MASS_FLUX_Z] == 1)
          OPS_ACC(mass_flux_z, 0, 0, 0) = (OPS_ACC(mass_flux_z, -4, 0, 0));
      }
    }
  }
}
