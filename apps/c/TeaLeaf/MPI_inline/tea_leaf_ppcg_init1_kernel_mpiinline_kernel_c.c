//
// auto-generated by ops.py
//

int xdim0_tea_leaf_ppcg_init1_kernel;
int xdim1_tea_leaf_ppcg_init1_kernel;
int xdim2_tea_leaf_ppcg_init1_kernel;
int xdim3_tea_leaf_ppcg_init1_kernel;
int xdim4_tea_leaf_ppcg_init1_kernel;


#define OPS_ACC0(x,y) (n_x*1 + x + (n_y*1+(y))*xdim0_tea_leaf_ppcg_init1_kernel)
#define OPS_ACC1(x,y) (n_x*1 + x + (n_y*1+(y))*xdim1_tea_leaf_ppcg_init1_kernel)
#define OPS_ACC2(x,y) (n_x*1 + x + (n_y*1+(y))*xdim2_tea_leaf_ppcg_init1_kernel)
#define OPS_ACC3(x,y) (n_x*1 + x + (n_y*1+(y))*xdim3_tea_leaf_ppcg_init1_kernel)
#define OPS_ACC4(x,y) (n_x*1 + x + (n_y*1+(y))*xdim4_tea_leaf_ppcg_init1_kernel)
//user function



void tea_leaf_ppcg_init1_kernel_c_wrapper(
  double * restrict sd,
  double * restrict rtemp,
  double * restrict utemp,
  const double * restrict z,
  const double * restrict r,
  const double * restrict theta_r,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      
	sd[OPS_ACC0(0,0)] = z[OPS_ACC3(0,0)]*(*theta_r);
	rtemp[OPS_ACC1(0,0)] = r[OPS_ACC4(0,0)];
	utemp[OPS_ACC2(0,0)] = sd[OPS_ACC0(0,0)];

    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4

