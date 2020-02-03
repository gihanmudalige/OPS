//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_reset_field_kernel1;
int ydim0_reset_field_kernel1;
int xdim1_reset_field_kernel1;
int ydim1_reset_field_kernel1;
int xdim2_reset_field_kernel1;
int ydim2_reset_field_kernel1;
int xdim3_reset_field_kernel1;
int ydim3_reset_field_kernel1;

//user function
#pragma acc routine
inline 
void reset_field_kernel1(ptr_double density0,
  const ptr_double density1,
  ptr_double energy0,
  const ptr_double energy1) {

  OPS_ACC(density0, 0,0,0)  = OPS_ACC(density1, 0,0,0) ;
  OPS_ACC(energy0, 0,0,0)  = OPS_ACC(energy1, 0,0,0) ;

}


void reset_field_kernel1_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3)
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
        ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_reset_field_kernel1*1*1 + n_z*xdim0_reset_field_kernel1*ydim0_reset_field_kernel1*1*1, xdim0_reset_field_kernel1, ydim0_reset_field_kernel1};
        const ptr_double ptr1 = {  p_a1 + n_x*1*1 + n_y*xdim1_reset_field_kernel1*1*1 + n_z*xdim1_reset_field_kernel1*ydim1_reset_field_kernel1*1*1, xdim1_reset_field_kernel1, ydim1_reset_field_kernel1};
        ptr_double ptr2 = {  p_a2 + n_x*1*1 + n_y*xdim2_reset_field_kernel1*1*1 + n_z*xdim2_reset_field_kernel1*ydim2_reset_field_kernel1*1*1, xdim2_reset_field_kernel1, ydim2_reset_field_kernel1};
        const ptr_double ptr3 = {  p_a3 + n_x*1*1 + n_y*xdim3_reset_field_kernel1*1*1 + n_z*xdim3_reset_field_kernel1*ydim3_reset_field_kernel1*1*1, xdim3_reset_field_kernel1, ydim3_reset_field_kernel1};
        reset_field_kernel1( ptr0,
          ptr1,
          ptr2,
          ptr3 );

      }
    }
  }
}
