//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_tea_leaf_common_init_u_u0_kernel;
int xdim1_tea_leaf_common_init_u_u0_kernel;
int xdim2_tea_leaf_common_init_u_u0_kernel;
int xdim3_tea_leaf_common_init_u_u0_kernel;

//user function
#pragma acc routine
inline 
void tea_leaf_common_init_u_u0_kernel(ptr_double u,
  ptr_double u0,
  const ptr_double energy,
  const ptr_double density) {
	OPS_ACC(u, 0,0)=OPS_ACC(energy, 0,0)*OPS_ACC(density, 0,0);
	OPS_ACC(u0, 0,0)=OPS_ACC(energy, 0,0)*OPS_ACC(density, 0,0);
}


void tea_leaf_common_init_u_u0_kernel_c_wrapper(
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
      ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_tea_leaf_common_init_u_u0_kernel*1*1, xdim0_tea_leaf_common_init_u_u0_kernel};
      ptr_double ptr1 = {  p_a1 + n_x*1*1 + n_y*xdim1_tea_leaf_common_init_u_u0_kernel*1*1, xdim1_tea_leaf_common_init_u_u0_kernel};
      const ptr_double ptr2 = {  p_a2 + n_x*1*1 + n_y*xdim2_tea_leaf_common_init_u_u0_kernel*1*1, xdim2_tea_leaf_common_init_u_u0_kernel};
      const ptr_double ptr3 = {  p_a3 + n_x*1*1 + n_y*xdim3_tea_leaf_common_init_u_u0_kernel*1*1, xdim3_tea_leaf_common_init_u_u0_kernel};
      tea_leaf_common_init_u_u0_kernel( ptr0,
          ptr1,ptr2,
          ptr3 );

    }
  }
}
