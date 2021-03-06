//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_tea_leaf_ppcg_init1_kernel;
int xdim1_tea_leaf_ppcg_init1_kernel;
int xdim2_tea_leaf_ppcg_init1_kernel;
int xdim3_tea_leaf_ppcg_init1_kernel;
int xdim4_tea_leaf_ppcg_init1_kernel;

//user function
inline 
void tea_leaf_ppcg_init1_kernel(ptr_double sd,
  ptr_double rtemp,
  ptr_double utemp,
  const ptr_double z,
  const ptr_double r,
  const double *theta_r) {
	OPS_ACC(sd, 0,0) = OPS_ACC(z, 0,0)*(*theta_r);
	OPS_ACC(rtemp, 0,0) = OPS_ACC(r, 0,0);
	OPS_ACC(utemp, 0,0) = OPS_ACC(sd, 0,0);
}


void tea_leaf_ppcg_init1_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double p_a5,
  int x_size, int y_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4)
  #pragma acc loop
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_tea_leaf_ppcg_init1_kernel*1*1, xdim0_tea_leaf_ppcg_init1_kernel};
      ptr_double ptr1 = {  p_a1 + n_x*1*1 + n_y*xdim1_tea_leaf_ppcg_init1_kernel*1*1, xdim1_tea_leaf_ppcg_init1_kernel};
      ptr_double ptr2 = {  p_a2 + n_x*1*1 + n_y*xdim2_tea_leaf_ppcg_init1_kernel*1*1, xdim2_tea_leaf_ppcg_init1_kernel};
      const ptr_double ptr3 = {  p_a3 + n_x*1*1 + n_y*xdim3_tea_leaf_ppcg_init1_kernel*1*1, xdim3_tea_leaf_ppcg_init1_kernel};
      const ptr_double ptr4 = {  p_a4 + n_x*1*1 + n_y*xdim4_tea_leaf_ppcg_init1_kernel*1*1, xdim4_tea_leaf_ppcg_init1_kernel};
      tea_leaf_ppcg_init1_kernel( ptr0,
          ptr1,ptr2,
          ptr3,ptr4,
           &p_a5 );

    }
  }
}
