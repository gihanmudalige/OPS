//
// auto-generated by ops.py
//

int xdim0_update_halo_kernel2_yvel_minus_4_a;
int xdim1_update_halo_kernel2_yvel_minus_4_a;


#define OPS_ACC0(x,y) (n_x*1 + x + (n_y*1+(y))*xdim0_update_halo_kernel2_yvel_minus_4_a)
#define OPS_ACC1(x,y) (n_x*1 + x + (n_y*1+(y))*xdim1_update_halo_kernel2_yvel_minus_4_a)
//user function



void update_halo_kernel2_yvel_minus_4_a_c_wrapper(
  double * restrict yvel0,
  double * restrict yvel1,
  const int * restrict fields,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      
  if(fields[FIELD_YVEL0] == 1) yvel0[OPS_ACC0(0,0)] = -yvel0[OPS_ACC0(0,4)];
  if(fields[FIELD_YVEL1] == 1) yvel1[OPS_ACC1(0,0)] = -yvel1[OPS_ACC1(0,4)];

    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1

