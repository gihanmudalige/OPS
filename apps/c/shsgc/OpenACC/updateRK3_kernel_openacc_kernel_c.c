//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_updateRK3_kernel;
int xdim1_updateRK3_kernel;
int xdim2_updateRK3_kernel;
int xdim3_updateRK3_kernel;
int xdim4_updateRK3_kernel;
int xdim5_updateRK3_kernel;
int xdim6_updateRK3_kernel;
int xdim7_updateRK3_kernel;
int xdim8_updateRK3_kernel;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
#undef OPS_ACC7
#undef OPS_ACC8

#define OPS_ACC0(x) (x)
#define OPS_ACC1(x) (x)
#define OPS_ACC2(x) (x)
#define OPS_ACC3(x) (x)
#define OPS_ACC4(x) (x)
#define OPS_ACC5(x) (x)
#define OPS_ACC6(x) (x)
#define OPS_ACC7(x) (x)
#define OPS_ACC8(x) (x)

// user function
inline void updateRK3_kernel(double *rho_new, double *rhou_new,
                             double *rhoE_new, double *rho_old,
                             double *rhou_old, double *rhoE_old,
                             const double *rho_res, const double *rhou_res,
                             const double *rhoE_res, const double *a1,
                             const double *a2) {

  rho_new[OPS_ACC0(0)] =
      rho_old[OPS_ACC3(0)] + dt * a1[0] * (-rho_res[OPS_ACC6(0)]);
  rhou_new[OPS_ACC1(0)] =
      rhou_old[OPS_ACC4(0)] + dt * a1[0] * (-rhou_res[OPS_ACC7(0)]);
  rhoE_new[OPS_ACC2(0)] =
      rhoE_old[OPS_ACC5(0)] + dt * a1[0] * (-rhoE_res[OPS_ACC8(0)]);

  rho_old[OPS_ACC3(0)] =
      rho_old[OPS_ACC3(0)] + dt * a2[0] * (-rho_res[OPS_ACC6(0)]);
  rhou_old[OPS_ACC4(0)] =
      rhou_old[OPS_ACC4(0)] + dt * a2[0] * (-rhou_res[OPS_ACC7(0)]);
  rhoE_old[OPS_ACC5(0)] =
      rhoE_old[OPS_ACC5(0)] + dt * a2[0] * (-rhoE_res[OPS_ACC8(0)]);
}

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
#undef OPS_ACC7
#undef OPS_ACC8

void updateRK3_kernel_c_wrapper(double *p_a0, double *p_a1, double *p_a2,
                                double *p_a3, double *p_a4, double *p_a5,
                                double *p_a6, double *p_a7, double *p_a8,
                                double p_a9, double p_a10, int x_size) {
#ifdef OPS_GPU
#pragma acc parallel deviceptr(p_a0, p_a1, p_a2, p_a3, p_a4, p_a5, p_a6, p_a7, \
                               p_a8)
#pragma acc loop
#endif
  for (int n_x = 0; n_x < x_size; n_x++) {
    updateRK3_kernel(p_a0 + n_x * 1 * 1, p_a1 + n_x * 1 * 1, p_a2 + n_x * 1 * 1,
                     p_a3 + n_x * 1 * 1, p_a4 + n_x * 1 * 1, p_a5 + n_x * 1 * 1,
                     p_a6 + n_x * 1 * 1, p_a7 + n_x * 1 * 1, p_a8 + n_x * 1 * 1,
                     &p_a9, &p_a10);
  }
}
