//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_tea_leaf_jacobi_kernel;
int xdim1_tea_leaf_jacobi_kernel;
int xdim2_tea_leaf_jacobi_kernel;
int xdim3_tea_leaf_jacobi_kernel;
int xdim4_tea_leaf_jacobi_kernel;

//user function
#pragma acc routine
inline 
void tea_leaf_jacobi_kernel(ptr_double u1,
  const ptr_double Kx,
  const ptr_double Ky,
  const ptr_double un,
  const ptr_double u0,
  const double *rx,
  const double *ry,
  double *error) {
	OPS_ACC(u1, 0,0) = (OPS_ACC(u0, 0,0)
		+ (*rx)*(OPS_ACC(Kx, 1, 0) *OPS_ACC(un, 1, 0) + OPS_ACC(Kx, 0,0)*OPS_ACC(un, -1, 0))
		+ (*ry)*(OPS_ACC(Ky, 0, 1) *OPS_ACC(un, 0, 1) + OPS_ACC(Ky, 0,0)*OPS_ACC(un, 0, -1)))
			/(1.0
				+ (*rx)*(OPS_ACC(Kx, 1, 0) + OPS_ACC(Kx, 0,0))
				+ (*ry)*(OPS_ACC(Ky, 0, 1) + OPS_ACC(Ky, 0,0)));

    *error = *error + fabs(OPS_ACC(u1, 0,0) - OPS_ACC(un, 0,0));
}


void tea_leaf_jacobi_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double p_a5,
  double p_a6,
  double *p_a7,
  int x_size, int y_size) {
  double p_a7_0 = p_a7[0];
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4) reduction(+:p_a7_0)
  #pragma acc loop reduction(+:p_a7_0)
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop reduction(+:p_a7_0)
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_tea_leaf_jacobi_kernel*1*1, xdim0_tea_leaf_jacobi_kernel};
      const ptr_double ptr1 = {  p_a1 + n_x*1*1 + n_y*xdim1_tea_leaf_jacobi_kernel*1*1, xdim1_tea_leaf_jacobi_kernel};
      const ptr_double ptr2 = {  p_a2 + n_x*1*1 + n_y*xdim2_tea_leaf_jacobi_kernel*1*1, xdim2_tea_leaf_jacobi_kernel};
      const ptr_double ptr3 = {  p_a3 + n_x*1*1 + n_y*xdim3_tea_leaf_jacobi_kernel*1*1, xdim3_tea_leaf_jacobi_kernel};
      const ptr_double ptr4 = {  p_a4 + n_x*1*1 + n_y*xdim4_tea_leaf_jacobi_kernel*1*1, xdim4_tea_leaf_jacobi_kernel};
      tea_leaf_jacobi_kernel( ptr0,
          ptr1,ptr2,
          ptr3,ptr4,
           &p_a5, &p_a6,
           &p_a7_0 );

    }
  }
  p_a7[0] = p_a7_0;
}
