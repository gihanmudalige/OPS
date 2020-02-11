//
// auto-generated by ops.py
//

int xdim0_flux_calc_kernelz;
int ydim0_flux_calc_kernelz;
int xdim1_flux_calc_kernelz;
int ydim1_flux_calc_kernelz;
int xdim2_flux_calc_kernelz;
int ydim2_flux_calc_kernelz;
int xdim3_flux_calc_kernelz;
int ydim3_flux_calc_kernelz;

// user function

void flux_calc_kernelz_c_wrapper(double *restrict vol_flux_z_p,
                                 double *restrict zarea_p,
                                 double *restrict zvel0_p,
                                 double *restrict zvel1_p, int x_size,
                                 int y_size, int z_size) {
#pragma omp parallel for
  for (int n_z = 0; n_z < z_size; n_z++) {
    for (int n_y = 0; n_y < y_size; n_y++) {
      for (int n_x = 0; n_x < x_size; n_x++) {
        ptr_double vol_flux_z = {
            vol_flux_z_p + n_x * 1 + n_y * xdim0_flux_calc_kernelz * 1 +
                n_z * xdim0_flux_calc_kernelz * ydim0_flux_calc_kernelz * 1,
            xdim0_flux_calc_kernelz, ydim0_flux_calc_kernelz};
        const ptr_double zarea = {
            zarea_p + n_x * 1 + n_y * xdim1_flux_calc_kernelz * 1 +
                n_z * xdim1_flux_calc_kernelz * ydim1_flux_calc_kernelz * 1,
            xdim1_flux_calc_kernelz, ydim1_flux_calc_kernelz};
        const ptr_double zvel0 = {
            zvel0_p + n_x * 1 + n_y * xdim2_flux_calc_kernelz * 1 +
                n_z * xdim2_flux_calc_kernelz * ydim2_flux_calc_kernelz * 1,
            xdim2_flux_calc_kernelz, ydim2_flux_calc_kernelz};
        const ptr_double zvel1 = {
            zvel1_p + n_x * 1 + n_y * xdim3_flux_calc_kernelz * 1 +
                n_z * xdim3_flux_calc_kernelz * ydim3_flux_calc_kernelz * 1,
            xdim3_flux_calc_kernelz, ydim3_flux_calc_kernelz};

        OPS_ACC(vol_flux_z, 0, 0, 0) =
            0.125 * dt * (OPS_ACC(zarea, 0, 0, 0)) *
            (OPS_ACC(zvel0, 0, 0, 0) + OPS_ACC(zvel0, 1, 0, 0) +
             OPS_ACC(zvel0, 1, 0, 0) + OPS_ACC(zvel0, 1, 1, 0) +
             OPS_ACC(zvel1, 0, 0, 0) + OPS_ACC(zvel1, 1, 0, 0) +
             OPS_ACC(zvel1, 0, 1, 0) + OPS_ACC(zvel1, 1, 1, 0));
      }
    }
  }
}