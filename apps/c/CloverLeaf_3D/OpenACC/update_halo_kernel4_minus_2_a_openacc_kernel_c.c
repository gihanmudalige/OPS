//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_update_halo_kernel4_minus_2_a;
int ydim0_update_halo_kernel4_minus_2_a;
int xdim1_update_halo_kernel4_minus_2_a;
int ydim1_update_halo_kernel4_minus_2_a;

//user function

inline void update_halo_kernel4_minus_2_a(ptr_double vol_flux_y,
  ptr_double mass_flux_y,
  const int* fields) {
  if(fields[FIELD_VOL_FLUX_Y] == 1) OPS_ACC(vol_flux_y, 0,0,0) = -(OPS_ACC(vol_flux_y, 0,2,0));
  if(fields[FIELD_MASS_FLUX_Y] == 1) OPS_ACC(mass_flux_y, 0,0,0) = -(OPS_ACC(mass_flux_y, 0,2,0));
}


void update_halo_kernel4_minus_2_a_c_wrapper(
  double *p_a0,
  double *p_a1,
  int *p_a2,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2)
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
        ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_update_halo_kernel4_minus_2_a*1*1 + n_z*xdim0_update_halo_kernel4_minus_2_a*ydim0_update_halo_kernel4_minus_2_a*1*1, xdim0_update_halo_kernel4_minus_2_a, ydim0_update_halo_kernel4_minus_2_a};
        ptr_double ptr1 = {  p_a1 + n_x*1*1 + n_y*xdim1_update_halo_kernel4_minus_2_a*1*1 + n_z*xdim1_update_halo_kernel4_minus_2_a*ydim1_update_halo_kernel4_minus_2_a*1*1, xdim1_update_halo_kernel4_minus_2_a, ydim1_update_halo_kernel4_minus_2_a};
        update_halo_kernel4_minus_2_a( ptr0,
          ptr1,
           p_a2 );

      }
    }
  }
}
