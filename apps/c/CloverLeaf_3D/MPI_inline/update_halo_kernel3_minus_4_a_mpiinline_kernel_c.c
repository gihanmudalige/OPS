//
// auto-generated by ops.py
//

int xdim0_update_halo_kernel3_minus_4_a;
int ydim0_update_halo_kernel3_minus_4_a;
int xdim1_update_halo_kernel3_minus_4_a;
int ydim1_update_halo_kernel3_minus_4_a;


#define OPS_ACC0(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim0_update_halo_kernel3_minus_4_a + (n_z*1+(z))*xdim0_update_halo_kernel3_minus_4_a*ydim0_update_halo_kernel3_minus_4_a)
#define OPS_ACC1(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim1_update_halo_kernel3_minus_4_a + (n_z*1+(z))*xdim1_update_halo_kernel3_minus_4_a*ydim1_update_halo_kernel3_minus_4_a)
//user function



void update_halo_kernel3_minus_4_a_c_wrapper(
  double * restrict vol_flux_x,
  double * restrict mass_flux_x,
  const int * restrict fields,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        
  if(fields[FIELD_VOL_FLUX_X] == 1)  vol_flux_x[OPS_ACC0(0,0,0)]  = -(vol_flux_x[OPS_ACC0(4,0,0)]);
  if(fields[FIELD_MASS_FLUX_X] == 1) mass_flux_x[OPS_ACC1(0,0,0)] = -(mass_flux_x[OPS_ACC1(4,0,0)]);

      }
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1

