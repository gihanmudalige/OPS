//
// auto-generated by ops.py
//

int xdim0_tea_leaf_common_residual_kernel;
int xdim1_tea_leaf_common_residual_kernel;
int xdim2_tea_leaf_common_residual_kernel;
int xdim3_tea_leaf_common_residual_kernel;
int xdim4_tea_leaf_common_residual_kernel;


#define OPS_ACC0(x,y) (n_x*1 + x + (n_y*1+(y))*xdim0_tea_leaf_common_residual_kernel)
#define OPS_ACC1(x,y) (n_x*1 + x + (n_y*1+(y))*xdim1_tea_leaf_common_residual_kernel)
#define OPS_ACC2(x,y) (n_x*1 + x + (n_y*1+(y))*xdim2_tea_leaf_common_residual_kernel)
#define OPS_ACC3(x,y) (n_x*1 + x + (n_y*1+(y))*xdim3_tea_leaf_common_residual_kernel)
#define OPS_ACC4(x,y) (n_x*1 + x + (n_y*1+(y))*xdim4_tea_leaf_common_residual_kernel)
//user function



void tea_leaf_common_residual_kernel_c_wrapper(
  double * restrict r,
  const double * restrict Kx,
  const double * restrict Ky,
  const double * restrict u,
  const double * restrict u0,
  const double * restrict rx,
  const double * restrict ry,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      
	double smvp = 0.0;
  smvp = (1.0
        + (*ry)*(Ky[OPS_ACC2(0, 1)] + Ky[OPS_ACC2(0,0)])
        + (*rx)*(Kx[OPS_ACC1(1, 0)] + Kx[OPS_ACC1(0,0)]))*u[OPS_ACC3(0,0)]
        - (*ry)*(Ky[OPS_ACC2(0, 1)] *u[OPS_ACC3(0, 1)] + Ky[OPS_ACC2(0,0)]*u[OPS_ACC3(0, -1)])
        - (*rx)*(Kx[OPS_ACC1(1, 0)] *u[OPS_ACC3(1, 0)] + Kx[OPS_ACC1(0,0)]*u[OPS_ACC3(-1, 0)]);
    r[OPS_ACC0(0,0)] = u0[OPS_ACC4(0,0)] - smvp;

    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4

