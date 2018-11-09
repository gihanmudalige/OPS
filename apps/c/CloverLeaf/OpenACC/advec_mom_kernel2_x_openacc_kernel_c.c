//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_advec_mom_kernel2_x;
int xdim1_advec_mom_kernel2_x;
int xdim2_advec_mom_kernel2_x;
int xdim3_advec_mom_kernel2_x;

//user function

inline void advec_mom_kernel2_x(ptr_double vel1, const ptr_double node_mass_post,
                       const  ptr_double node_mass_pre, const ptr_double mom_flux) {

  OPS_ACC(vel1, 0,0) = ( OPS_ACC(vel1, 0,0) * OPS_ACC(node_mass_pre, 0,0)  +
    OPS_ACC(mom_flux, -1,0) - OPS_ACC(mom_flux, 0,0) ) / OPS_ACC(node_mass_post, 0,0);

}


void advec_mom_kernel2_x_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  int x_size, int y_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3)
  #pragma acc loop
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_advec_mom_kernel2_x*1*1, xdim0_advec_mom_kernel2_x};
      const ptr_double ptr1 = {  p_a1 + n_x*1*1 + n_y*xdim1_advec_mom_kernel2_x*1*1, xdim1_advec_mom_kernel2_x};
      const ptr_double ptr2 = {  p_a2 + n_x*1*1 + n_y*xdim2_advec_mom_kernel2_x*1*1, xdim2_advec_mom_kernel2_x};
      const ptr_double ptr3 = {  p_a3 + n_x*1*1 + n_y*xdim3_advec_mom_kernel2_x*1*1, xdim3_advec_mom_kernel2_x};
      advec_mom_kernel2_x( ptr0,
          ptr1,ptr2,
          ptr3 );

    }
  }
}
