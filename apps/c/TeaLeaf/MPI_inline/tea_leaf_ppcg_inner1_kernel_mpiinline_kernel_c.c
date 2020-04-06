//
// auto-generated by ops.py
//

int xdim0_tea_leaf_ppcg_inner1_kernel;
int xdim1_tea_leaf_ppcg_inner1_kernel;
int xdim2_tea_leaf_ppcg_inner1_kernel;
int xdim3_tea_leaf_ppcg_inner1_kernel;


//user function



void tea_leaf_ppcg_inner1_kernel_c_wrapper(
  double * restrict rtemp_p,
  double * restrict Kx_p,
  double * restrict Ky_p,
  double * restrict sd_p,
  const double * restrict rx,
  const double * restrict ry,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      ptr_double rtemp = { rtemp_p + n_x*1 + n_y * xdim0_tea_leaf_ppcg_inner1_kernel*1, xdim0_tea_leaf_ppcg_inner1_kernel};
      const ptr_double Kx = { Kx_p + n_x*1 + n_y * xdim1_tea_leaf_ppcg_inner1_kernel*1, xdim1_tea_leaf_ppcg_inner1_kernel};
      const ptr_double Ky = { Ky_p + n_x*1 + n_y * xdim2_tea_leaf_ppcg_inner1_kernel*1, xdim2_tea_leaf_ppcg_inner1_kernel};
      const ptr_double sd = { sd_p + n_x*1 + n_y * xdim3_tea_leaf_ppcg_inner1_kernel*1, xdim3_tea_leaf_ppcg_inner1_kernel};
      
	double smvp = 0.0;
  smvp = (1.0
    + (*ry)*(OPS_ACC(Ky, 0, 1) + OPS_ACC(Ky, 0,0))
    + (*rx)*(OPS_ACC(Kx, 1, 0) + OPS_ACC(Kx, 0,0)))*OPS_ACC(sd, 0,0)
    - (*ry)*(OPS_ACC(Ky, 0, 1) *OPS_ACC(sd, 0, 1) + OPS_ACC(Ky, 0,0)*OPS_ACC(sd, 0, -1))
    - (*rx)*(OPS_ACC(Kx, 1, 0) *OPS_ACC(sd, 1, 0) + OPS_ACC(Kx, 0,0)*OPS_ACC(sd, -1, 0));
  OPS_ACC(rtemp, 0,0) = OPS_ACC(rtemp, 0,0) - smvp;

    }
  }
}
