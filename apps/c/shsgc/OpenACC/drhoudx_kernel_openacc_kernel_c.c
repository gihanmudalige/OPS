//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_drhoudx_kernel;
int xdim1_drhoudx_kernel;


#undef OPS_ACC0
#undef OPS_ACC1


#define OPS_ACC0(x) (x)
#define OPS_ACC1(x) (x)

//user function
inline 
void drhoudx_kernel(const double *rhou_new, double *rho_res) {

        double fnim1 = rhou_new[OPS_ACC0(-1)];
        double fnim2 = rhou_new[OPS_ACC0(-2)];
        double fnip1 = rhou_new[OPS_ACC0(1)];
        double fnip2 = rhou_new[OPS_ACC0(2)];

        double deriv = (fnim2 - fnip2 + 8.0* (fnip1 - fnim1))/(12.00*dx);
        rho_res[OPS_ACC1(0)] = deriv;
}


#undef OPS_ACC0
#undef OPS_ACC1



void drhoudx_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  int x_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1)
  #pragma acc loop
  #endif
  for ( int n_x=0; n_x<x_size; n_x++ ){
    drhoudx_kernel(  p_a0 + n_x*1*1,
           p_a1 + n_x*1*1 );

  }
}
