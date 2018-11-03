//
// auto-generated by ops.py
//

int xdim0_update_halo_kernel2_yvel_plus_4_a;
int xdim1_update_halo_kernel2_yvel_plus_4_a;


//user function



void update_halo_kernel2_yvel_plus_4_a_c_wrapper(
  double * restrict yvel0_p,
  double * restrict yvel1_p,
  const int * restrict fields,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      ptr_double yvel0 = { yvel0_p + n_x*1 + n_y * xdim0_update_halo_kernel2_yvel_plus_4_a*1, xdim0_update_halo_kernel2_yvel_plus_4_a};
      ptr_double yvel1 = { yvel1_p + n_x*1 + n_y * xdim1_update_halo_kernel2_yvel_plus_4_a*1, xdim1_update_halo_kernel2_yvel_plus_4_a};
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1

