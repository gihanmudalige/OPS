//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_mgrid_populate_kernel_3;

//user function
#pragma acc routine
inline 
void mgrid_populate_kernel_3(ptr_double val,
  int *idx) {
  OPS_ACC(val, 0,0) = (double)(idx[0]+24*idx[1]);
}


void mgrid_populate_kernel_3_c_wrapper(
  double *p_a0,
  int *p_a1,
  int arg_idx0, int arg_idx1,
  int x_size, int y_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0)
  #pragma acc loop
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      int arg_idx[] = {arg_idx0+n_x, arg_idx1+n_y};
      ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_mgrid_populate_kernel_3*1*1, xdim0_mgrid_populate_kernel_3};
      mgrid_populate_kernel_3( ptr0,
          arg_idx );

    }
  }
}
