//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_tea_leaf_norm2_kernel;


#undef OPS_ACC0


#define OPS_ACC0(x,y) (x+xdim0_tea_leaf_norm2_kernel*(y))

//user function
inline 
void tea_leaf_norm2_kernel(const double *x, double * norm) {
	*norm = *norm + x[OPS_ACC0(0,0)]*x[OPS_ACC0(0,0)];
}


#undef OPS_ACC0



void tea_leaf_norm2_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  int x_size, int y_size) {
  double p_a1_0 = p_a1[0];
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0) reduction(+:p_a1_0)
  #pragma acc loop reduction(+:p_a1_0)
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop reduction(+:p_a1_0)
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      tea_leaf_norm2_kernel(  p_a0 + n_x*1*1 + n_y*xdim0_tea_leaf_norm2_kernel*1*1,
           &p_a1_0 );

    }
  }
  p_a1[0] = p_a1_0;
}
