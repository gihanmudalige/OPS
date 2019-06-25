//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_ideal_gas_kernel;
int ydim0_ideal_gas_kernel;
int xdim1_ideal_gas_kernel;
int ydim1_ideal_gas_kernel;
int xdim2_ideal_gas_kernel;
int ydim2_ideal_gas_kernel;
int xdim3_ideal_gas_kernel;
int ydim3_ideal_gas_kernel;

//user function
inline void ideal_gas_kernel(const ptr_double density, const ptr_double energy,
                             ptr_double pressure, ptr_double soundspeed) {

  double sound_speed_squared, v, pressurebyenergy, pressurebyvolume;

  v = 1.0 / OPS_ACC(density, 0, 0, 0);
  OPS_ACC(pressure, 0, 0, 0) =
      (1.4 - 1.0) * OPS_ACC(density, 0, 0, 0) * OPS_ACC(energy, 0, 0, 0);

  pressurebyenergy = (1.4 - 1.0) * OPS_ACC(density, 0, 0, 0);
  pressurebyvolume =
      -1.0 * OPS_ACC(density, 0, 0, 0) * OPS_ACC(pressure, 0, 0, 0);
  sound_speed_squared = v * v * (OPS_ACC(pressure, 0, 0, 0) * pressurebyenergy -
                                 pressurebyvolume);
  OPS_ACC(soundspeed, 0, 0, 0) = sqrt(sound_speed_squared);
}


void ideal_gas_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3)
  #pragma acc loop
  #endif
  for ( int n_z=0; n_z<z_size; n_z++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_y=0; n_y<y_size; n_y++ ){
      #ifdef OPS_GPU
      #pragma acc loop
      #endif
      for ( int n_x=0; n_x<x_size; n_x++ ){
        const ptr_double ptr0 = {
            p_a0 + n_x * 1 * 1 + n_y * xdim0_ideal_gas_kernel * 1 * 1 +
                n_z * xdim0_ideal_gas_kernel * ydim0_ideal_gas_kernel * 1 * 1,
            xdim0_ideal_gas_kernel, ydim0_ideal_gas_kernel};
        const ptr_double ptr1 = {
            p_a1 + n_x * 1 * 1 + n_y * xdim1_ideal_gas_kernel * 1 * 1 +
                n_z * xdim1_ideal_gas_kernel * ydim1_ideal_gas_kernel * 1 * 1,
            xdim1_ideal_gas_kernel, ydim1_ideal_gas_kernel};
        ptr_double ptr2 = {
            p_a2 + n_x * 1 * 1 + n_y * xdim2_ideal_gas_kernel * 1 * 1 +
                n_z * xdim2_ideal_gas_kernel * ydim2_ideal_gas_kernel * 1 * 1,
            xdim2_ideal_gas_kernel, ydim2_ideal_gas_kernel};
        ptr_double ptr3 = {
            p_a3 + n_x * 1 * 1 + n_y * xdim3_ideal_gas_kernel * 1 * 1 +
                n_z * xdim3_ideal_gas_kernel * ydim3_ideal_gas_kernel * 1 * 1,
            xdim3_ideal_gas_kernel, ydim3_ideal_gas_kernel};
        ideal_gas_kernel(ptr0, ptr1, ptr2, ptr3);
      }
    }
  }
}
