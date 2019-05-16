//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_multidim_reduce_kernel;
int ydim0_multidim_reduce_kernel;

#undef OPS_ACC_MD0

#define OPS_ACC_MD0(d, x, y)                                                   \
  ((x) + (xdim0_multidim_reduce_kernel * (y)) +                                \
   (d)*xdim0_multidim_reduce_kernel * ydim0_multidim_reduce_kernel)
// user function
inline void multidim_reduce_kernel(const double *val, double *redu_dat1) {

  redu_dat1[0] = redu_dat1[0] + val[OPS_ACC_MD0(0, 0, 0)];
  redu_dat1[1] = redu_dat1[1] + val[OPS_ACC_MD0(1, 0, 0)];
}

#undef OPS_ACC_MD0

void multidim_reduce_kernel_c_wrapper(double *p_a0, double *p_a1, int x_size,
                                      int y_size) {
  double p_a1_0 = p_a1[0];
  double p_a1_1 = p_a1[1];
#ifdef OPS_GPU
#pragma acc parallel deviceptr(p_a0) reduction(+ : p_a1_0) reduction(+ : p_a1_1)
#pragma acc loop reduction(+ : p_a1_0) reduction(+ : p_a1_1)
#endif
  for (int n_y = 0; n_y < y_size; n_y++) {
#ifdef OPS_GPU
#pragma acc loop reduction(+ : p_a1_0) reduction(+ : p_a1_1)
#endif
    for (int n_x = 0; n_x < x_size; n_x++) {
      double p_a1_local[2];
      p_a1_local[0] = ZERO_double;
      p_a1_local[1] = ZERO_double;
      multidim_reduce_kernel(
          p_a0 + n_x * 1 + n_y * xdim0_multidim_reduce_kernel * 1, p_a1_local);

      p_a1_0 += p_a1_local[0];
      p_a1_1 += p_a1_local[1];
    }
  }
  p_a1[0] = p_a1_0;
  p_a1[1] = p_a1_1;
}
