//
// auto-generated by ops.py on 2014-07-15 13:58
//

#include "./OpenACC/clover_leaf_common.h"

#define OPS_GPU

int xdim0_update_halo_kernel4_minus_4_a;
int ydim0_update_halo_kernel4_minus_4_a;
int xdim1_update_halo_kernel4_minus_4_a;
int ydim1_update_halo_kernel4_minus_4_a;

#define OPS_ACC0(x,y,z) (x+xdim0_update_halo_kernel4_minus_4_a*(y)+xdim0_update_halo_kernel4_minus_4_a*ydim0_update_halo_kernel4_minus_4_a*(z))
#define OPS_ACC1(x,y,z) (x+xdim1_update_halo_kernel4_minus_4_a*(y)+xdim1_update_halo_kernel4_minus_4_a*ydim1_update_halo_kernel4_minus_4_a*(z))

//user function

inline void update_halo_kernel4_minus_4_a(double *vol_flux_y, double *mass_flux_y, const int* fields) {
  if(fields[FIELD_VOL_FLUX_Y] == 1) vol_flux_y[OPS_ACC0(0,0,0)] = -(vol_flux_y[OPS_ACC0(0,4,0)]);
  if(fields[FIELD_MASS_FLUX_Y] == 1) mass_flux_y[OPS_ACC1(0,0,0)] = -(mass_flux_y[OPS_ACC1(0,4,0)]);
}



#undef OPS_ACC0
#undef OPS_ACC1


void update_halo_kernel4_minus_4_a_c_wrapper(
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
        update_halo_kernel4_minus_4_a(  p_a0 + n_x*1 + n_y*xdim0_update_halo_kernel4_minus_4_a*1 + n_z*xdim0_update_halo_kernel4_minus_4_a*ydim0_update_halo_kernel4_minus_4_a*1,
           p_a1 + n_x*1 + n_y*xdim1_update_halo_kernel4_minus_4_a*1 + n_z*xdim1_update_halo_kernel4_minus_4_a*ydim1_update_halo_kernel4_minus_4_a*1,
           p_a2 );

      }
    }
  }
}
