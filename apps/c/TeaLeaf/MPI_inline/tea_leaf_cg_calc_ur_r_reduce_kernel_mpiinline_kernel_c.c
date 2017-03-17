//
// auto-generated by ops.py
//
#include "./MPI_inline/tea_leaf_common.h"

int xdim0_tea_leaf_cg_calc_ur_r_reduce_kernel;
int xdim1_tea_leaf_cg_calc_ur_r_reduce_kernel;

#define OPS_ACC0(x,y) (n_x*1+n_y*xdim0_tea_leaf_cg_calc_ur_r_reduce_kernel*1+x+xdim0_tea_leaf_cg_calc_ur_r_reduce_kernel*(y))
#define OPS_ACC1(x,y) (n_x*1+n_y*xdim1_tea_leaf_cg_calc_ur_r_reduce_kernel*1+x+xdim1_tea_leaf_cg_calc_ur_r_reduce_kernel*(y))

//user function



void tea_leaf_cg_calc_ur_r_reduce_kernel_c_wrapper(
  double * restrict r,
  const double * restrict w,
  const double * restrict alpha,
  double * restrict rnn_g,
  int x_size, int y_size) {
  double rnn_v = *rnn_g;
  #pragma omp parallel for reduction(+:rnn_v)
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      double * restrict rnn = &rnn_v;
      
  r[OPS_ACC0(0,0)] = r[OPS_ACC0(0,0)] - (*alpha)*w[OPS_ACC1(0,0)];
  *rnn = *rnn +  r[OPS_ACC0(0,0)]*r[OPS_ACC0(0,0)];

    }
  }
  *rnn_g = rnn_v;
}
#undef OPS_ACC0
#undef OPS_ACC1

