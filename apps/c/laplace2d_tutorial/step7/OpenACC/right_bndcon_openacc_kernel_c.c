//
// auto-generated by ops.py
//
#include "./OpenACC/laplace2d_common.h"

#define OPS_GPU

int xdim0_right_bndcon;


#undef OPS_ACC0


#define OPS_ACC0(x,y) (x+xdim0_right_bndcon*(y))

//user function
inline 
void right_bndcon(double *A, const int *idx) {
  A[OPS_ACC0(0,0)] = sin(pi * (idx[1]+1) / (jmax+1))*exp(-pi);
}


#undef OPS_ACC0



void right_bndcon_c_wrapper(
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
      right_bndcon(  p_a0 + n_x*1*1 + n_y*xdim0_right_bndcon*1*1,
          arg_idx );

    }
  }
}
