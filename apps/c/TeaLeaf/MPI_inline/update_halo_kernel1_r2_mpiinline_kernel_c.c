//
// auto-generated by ops.py
//

int xdim0_update_halo_kernel1_r2;
int xdim1_update_halo_kernel1_r2;
int xdim2_update_halo_kernel1_r2;
int xdim3_update_halo_kernel1_r2;
int xdim4_update_halo_kernel1_r2;
int xdim5_update_halo_kernel1_r2;


#define OPS_ACC0(x,y) (n_x*1 + x + (n_y*1+(y))*xdim0_update_halo_kernel1_r2)
#define OPS_ACC1(x,y) (n_x*1 + x + (n_y*1+(y))*xdim1_update_halo_kernel1_r2)
#define OPS_ACC2(x,y) (n_x*1 + x + (n_y*1+(y))*xdim2_update_halo_kernel1_r2)
#define OPS_ACC3(x,y) (n_x*1 + x + (n_y*1+(y))*xdim3_update_halo_kernel1_r2)
#define OPS_ACC4(x,y) (n_x*1 + x + (n_y*1+(y))*xdim4_update_halo_kernel1_r2)
#define OPS_ACC5(x,y) (n_x*1 + x + (n_y*1+(y))*xdim5_update_halo_kernel1_r2)
//user function



void update_halo_kernel1_r2_c_wrapper(
  double * restrict density0,
  double * restrict energy0,
  double * restrict energy1,
  double * restrict u,
  double * restrict p,
  double * restrict sd,
  const int * restrict fields,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      
  if(fields[FIELD_DENSITY] == 1) density0[OPS_ACC0(0,0)] = density0[OPS_ACC0(-3,0)];
  if(fields[FIELD_ENERGY0] == 1) energy0[OPS_ACC1(0,0)] = energy0[OPS_ACC1(-3,0)];
  if(fields[FIELD_ENERGY1] == 1) energy1[OPS_ACC2(0,0)] = energy1[OPS_ACC2(-3,0)];
  if(fields[FIELD_U] == 1) u[OPS_ACC3(0,0)] = u[OPS_ACC3(-3,0)];
  if(fields[FIELD_P] == 1) p[OPS_ACC4(0,0)] = p[OPS_ACC4(-3,0)];
  if(fields[FIELD_SD] == 1) sd[OPS_ACC5(0,0)] = sd[OPS_ACC5(-3,0)];


    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5

