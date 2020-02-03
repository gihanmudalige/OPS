//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_reset_field_kernel2;
int xdim1_reset_field_kernel2;
int xdim2_reset_field_kernel2;
int xdim3_reset_field_kernel2;

//user function
#pragma acc routine
inline 
void reset_field_kernel2(ptr_double xvel0,
  const ptr_double xvel1,
  ptr_double yvel0,
  const ptr_double yvel1) {

  OPS_ACC(xvel0, 0,0)  = OPS_ACC(xvel1, 0,0) ;
  OPS_ACC(yvel0, 0,0)  = OPS_ACC(yvel1, 0,0) ;

}


void reset_field_kernel2_c_wrapper(
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
      ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_reset_field_kernel2*1*1, xdim0_reset_field_kernel2};
      const ptr_double ptr1 = {  p_a1 + n_x*1*1 + n_y*xdim1_reset_field_kernel2*1*1, xdim1_reset_field_kernel2};
      ptr_double ptr2 = {  p_a2 + n_x*1*1 + n_y*xdim2_reset_field_kernel2*1*1, xdim2_reset_field_kernel2};
      const ptr_double ptr3 = {  p_a3 + n_x*1*1 + n_y*xdim3_reset_field_kernel2*1*1, xdim3_reset_field_kernel2};
      reset_field_kernel2( ptr0,
          ptr1,ptr2,
          ptr3 );

    }
  }
}
