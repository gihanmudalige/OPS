//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_set_zero;

//user function
inline 
void set_zero(ptr_double A) {
  OPS_ACC(A, 0,0) = 0.0;
}


void set_zero_c_wrapper(
  double *p_a0,
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
      ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_set_zero*1*1, xdim0_set_zero};
      set_zero( ptr0 );

    }
  }
}
