//
// auto-generated by ops.py
//

int xdim0_viscosity_kernel;
int xdim1_viscosity_kernel;
int xdim2_viscosity_kernel;
int xdim3_viscosity_kernel;
int xdim4_viscosity_kernel;
int xdim5_viscosity_kernel;
int xdim6_viscosity_kernel;

#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 + n_y * xdim0_viscosity_kernel * 1 + x +                            \
   xdim0_viscosity_kernel * (y))
#define OPS_ACC1(x, y)                                                         \
  (n_x * 1 + n_y * xdim1_viscosity_kernel * 1 + x +                            \
   xdim1_viscosity_kernel * (y))
#define OPS_ACC2(x, y)                                                         \
  (n_x * 1 + n_y * xdim2_viscosity_kernel * 0 + x +                            \
   xdim2_viscosity_kernel * (y))
#define OPS_ACC3(x, y)                                                         \
  (n_x * 0 + n_y * xdim3_viscosity_kernel * 1 + x +                            \
   xdim3_viscosity_kernel * (y))
#define OPS_ACC4(x, y)                                                         \
  (n_x * 1 + n_y * xdim4_viscosity_kernel * 1 + x +                            \
   xdim4_viscosity_kernel * (y))
#define OPS_ACC5(x, y)                                                         \
  (n_x * 1 + n_y * xdim5_viscosity_kernel * 1 + x +                            \
   xdim5_viscosity_kernel * (y))
#define OPS_ACC6(x, y)                                                         \
  (n_x * 1 + n_y * xdim6_viscosity_kernel * 1 + x +                            \
   xdim6_viscosity_kernel * (y))

// user function

void viscosity_kernel_c_wrapper(
    const double *restrict xvel0, const double *restrict yvel0,
    const double *restrict celldx, const double *restrict celldy,
    const double *restrict pressure, const double *restrict density0,
    double *restrict viscosity, int x_size, int y_size) {
#pragma omp parallel for
  for (int n_y = 0; n_y < y_size; n_y++) {
    for (int n_x = 0; n_x < x_size; n_x++) {

      double ugrad, vgrad, grad2, pgradx, pgrady, pgradx2, pgrady2, grad, ygrad,
          xgrad, div, strain2, limiter, pgrad;

      ugrad = (xvel0[OPS_ACC0(1, 0)] + xvel0[OPS_ACC0(1, 1)]) -
              (xvel0[OPS_ACC0(0, 0)] + xvel0[OPS_ACC0(0, 1)]);
      vgrad = (yvel0[OPS_ACC1(0, 1)] + yvel0[OPS_ACC1(1, 1)]) -
              (yvel0[OPS_ACC1(0, 0)] + yvel0[OPS_ACC1(1, 0)]);

      div = (celldx[OPS_ACC2(0, 0)]) * (ugrad) +
            (celldy[OPS_ACC3(0, 0)]) * (vgrad);

      strain2 = 0.5 * (xvel0[OPS_ACC0(0, 1)] + xvel0[OPS_ACC0(1, 1)] -
                       xvel0[OPS_ACC0(0, 0)] - xvel0[OPS_ACC0(1, 0)]) /
                    (celldy[OPS_ACC3(0, 0)]) +
                0.5 * (yvel0[OPS_ACC1(1, 0)] + yvel0[OPS_ACC1(1, 1)] -
                       yvel0[OPS_ACC1(0, 0)] - yvel0[OPS_ACC1(0, 1)]) /
                    (celldx[OPS_ACC2(0, 0)]);

      pgradx = (pressure[OPS_ACC4(1, 0)] - pressure[OPS_ACC4(-1, 0)]) /
               (celldx[OPS_ACC2(0, 0)] + celldx[OPS_ACC2(1, 0)]);
      pgrady = (pressure[OPS_ACC4(0, 1)] - pressure[OPS_ACC4(0, -1)]) /
               (celldy[OPS_ACC3(0, 0)] + celldy[OPS_ACC3(0, 1)]);

      pgradx2 = pgradx * pgradx;
      pgrady2 = pgrady * pgrady;

      limiter = ((0.5 * (ugrad) / celldx[OPS_ACC2(0, 0)]) * pgradx2 +
                 (0.5 * (vgrad) / celldy[OPS_ACC3(0, 0)]) * pgrady2 +
                 strain2 * pgradx * pgrady) /
                MAX(pgradx2 + pgrady2, 1.0e-16);

      if ((limiter > 0.0) || (div >= 0.0)) {
        viscosity[OPS_ACC6(0, 0)] = 0.0;
      } else {
        pgradx = SIGN(MAX(1.0e-16, fabs(pgradx)), pgradx);
        pgrady = SIGN(MAX(1.0e-16, fabs(pgrady)), pgrady);
        pgrad = sqrt(pgradx * pgradx + pgrady * pgrady);
        xgrad = fabs(celldx[OPS_ACC2(0, 0)] * pgrad / pgradx);
        ygrad = fabs(celldy[OPS_ACC3(0, 0)] * pgrad / pgrady);
        grad = MIN(xgrad, ygrad);
        grad2 = grad * grad;

        viscosity[OPS_ACC6(0, 0)] =
            2.0 * (density0[OPS_ACC5(0, 0)]) * grad2 * limiter * limiter;
      }
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
