//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_calvar_kernel;
int xdim1_calvar_kernel;
int xdim2_calvar_kernel;
int xdim3_calvar_kernel;
int xdim4_calvar_kernel;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4

#define OPS_ACC0(x) (x)
#define OPS_ACC1(x) (x)
#define OPS_ACC2(x) (x)
#define OPS_ACC3(x) (x)
#define OPS_ACC4(x) (x)

// user function
inline void calvar_kernel(const double *rho_new, const double *rhou_new,
                          const double *rhoE_new, double *workarray2,
                          double *workarray3) {
  double p, rhoi, u;
  rhoi = 1 / rho_new[OPS_ACC0(0)];
  u = rhou_new[OPS_ACC1(0)] * rhoi;
  p = gam1 * (rhoE_new[OPS_ACC2(0)] - 0.5 * rho_new[OPS_ACC0(0)] * u * u);

  workarray2[OPS_ACC3(0)] = p + rhou_new[OPS_ACC1(0)] * u;
  workarray3[OPS_ACC4(0)] = (p + rhoE_new[OPS_ACC2(0)]) * u;
}

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4

void calvar_kernel_c_wrapper(double *p_a0, double *p_a1, double *p_a2,
                             double *p_a3, double *p_a4, int x_size) {
#ifdef OPS_GPU
#pragma acc parallel deviceptr(p_a0, p_a1, p_a2, p_a3, p_a4)
#pragma acc loop
#endif
  for (int n_x = 0; n_x < x_size; n_x++) {
    calvar_kernel(p_a0 + n_x * 1 * 1, p_a1 + n_x * 1 * 1, p_a2 + n_x * 1 * 1,
                  p_a3 + n_x * 1 * 1, p_a4 + n_x * 1 * 1);
  }
}
