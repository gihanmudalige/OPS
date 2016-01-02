//
// auto-generated by ops.py
//
#include "./MPI_inline/clover_leaf_common.h"

int xdim0_calc_dt_kernel_print;
int ydim0_calc_dt_kernel_print;
int xdim1_calc_dt_kernel_print;
int ydim1_calc_dt_kernel_print;
int xdim2_calc_dt_kernel_print;
int ydim2_calc_dt_kernel_print;
int xdim3_calc_dt_kernel_print;
int ydim3_calc_dt_kernel_print;
int xdim4_calc_dt_kernel_print;
int ydim4_calc_dt_kernel_print;
int xdim5_calc_dt_kernel_print;
int ydim5_calc_dt_kernel_print;
int xdim6_calc_dt_kernel_print;
int ydim6_calc_dt_kernel_print;

#define OPS_ACC0(x,y,z) (n_x*1+n_y*xdim0_calc_dt_kernel_print*1+n_z*xdim0_calc_dt_kernel_print*ydim0_calc_dt_kernel_print*1+x+xdim0_calc_dt_kernel_print*(y)+xdim0_calc_dt_kernel_print*ydim0_calc_dt_kernel_print*(z))
#define OPS_ACC1(x,y,z) (n_x*1+n_y*xdim1_calc_dt_kernel_print*1+n_z*xdim1_calc_dt_kernel_print*ydim1_calc_dt_kernel_print*1+x+xdim1_calc_dt_kernel_print*(y)+xdim1_calc_dt_kernel_print*ydim1_calc_dt_kernel_print*(z))
#define OPS_ACC2(x,y,z) (n_x*1+n_y*xdim2_calc_dt_kernel_print*1+n_z*xdim2_calc_dt_kernel_print*ydim2_calc_dt_kernel_print*1+x+xdim2_calc_dt_kernel_print*(y)+xdim2_calc_dt_kernel_print*ydim2_calc_dt_kernel_print*(z))
#define OPS_ACC3(x,y,z) (n_x*1+n_y*xdim3_calc_dt_kernel_print*1+n_z*xdim3_calc_dt_kernel_print*ydim3_calc_dt_kernel_print*1+x+xdim3_calc_dt_kernel_print*(y)+xdim3_calc_dt_kernel_print*ydim3_calc_dt_kernel_print*(z))
#define OPS_ACC4(x,y,z) (n_x*1+n_y*xdim4_calc_dt_kernel_print*1+n_z*xdim4_calc_dt_kernel_print*ydim4_calc_dt_kernel_print*1+x+xdim4_calc_dt_kernel_print*(y)+xdim4_calc_dt_kernel_print*ydim4_calc_dt_kernel_print*(z))
#define OPS_ACC5(x,y,z) (n_x*1+n_y*xdim5_calc_dt_kernel_print*1+n_z*xdim5_calc_dt_kernel_print*ydim5_calc_dt_kernel_print*1+x+xdim5_calc_dt_kernel_print*(y)+xdim5_calc_dt_kernel_print*ydim5_calc_dt_kernel_print*(z))
#define OPS_ACC6(x,y,z) (n_x*1+n_y*xdim6_calc_dt_kernel_print*1+n_z*xdim6_calc_dt_kernel_print*ydim6_calc_dt_kernel_print*1+x+xdim6_calc_dt_kernel_print*(y)+xdim6_calc_dt_kernel_print*ydim6_calc_dt_kernel_print*(z))

//user function



void calc_dt_kernel_print_c_wrapper(
  const double * restrict xvel0,
  const double * restrict yvel0,
  const double * restrict zvel0,
  const double * restrict density0,
  const double * restrict energy0,
  const double * restrict pressure,
  const double * restrict soundspeed,
  double * restrict output_g,
  int x_size, int y_size, int z_size) {
  double output_v = *output_g;
  #pragma omp parallel for reduction(+:output_v)
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        double * restrict output = &output_v;
        
  output[0] = xvel0[OPS_ACC0(0,0,0)];
  output[1] = yvel0[OPS_ACC1(0,0,0)];
  output[2] = zvel0[OPS_ACC2(0,0,0)];
  output[3] = xvel0[OPS_ACC0(1,0,0)];
  output[4] = yvel0[OPS_ACC1(1,0,0)];
  output[5] = zvel0[OPS_ACC2(0,0,0)];
  output[6] = xvel0[OPS_ACC0(1,1,0)];
  output[7] = yvel0[OPS_ACC1(1,1,0)];
  output[8] = zvel0[OPS_ACC2(0,0,0)];
  output[9] = xvel0[OPS_ACC0(0,1,0)];
  output[10] = yvel0[OPS_ACC1(0,1,0)];
  output[11] = zvel0[OPS_ACC2(0,0,0)];
  output[12] = xvel0[OPS_ACC0(0,0,1)];
  output[13] = yvel0[OPS_ACC1(0,0,1)];
  output[14] = zvel0[OPS_ACC2(0,0,1)];
  output[15] = xvel0[OPS_ACC0(1,0,1)];
  output[16] = yvel0[OPS_ACC1(1,0,1)];
  output[17] = zvel0[OPS_ACC2(0,0,1)];
  output[18] = xvel0[OPS_ACC0(1,1,1)];
  output[19] = yvel0[OPS_ACC1(1,1,1)];
  output[20] = zvel0[OPS_ACC2(0,0,1)];
  output[21] = xvel0[OPS_ACC0(0,1,1)];
  output[22] = yvel0[OPS_ACC1(0,1,1)];
  output[23] = zvel0[OPS_ACC2(0,0,1)];
  output[24] = density0[OPS_ACC3(0,0,0)];
  output[25] = energy0[OPS_ACC4(0,0,0)];
  output[26] = pressure[OPS_ACC5(0,0,0)];
  output[27] = soundspeed[OPS_ACC6(0,0,0)];


      }
    }
  }
  *output_g = output_v;
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6

