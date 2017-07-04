//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"

#define OPS_GPU

extern int xdim0_calc_dt_kernel_min;

#undef OPS_ACC0

#define OPS_ACC0(x, y) (x + xdim0_calc_dt_kernel_min * (y))

// user function

void calc_dt_kernel_min_c_wrapper(double *p_a0, int base0, int tot0,
                                  double *p_a1, int x_size, int y_size) {
  double p_a1_0 = p_a1[0];
#ifdef OPS_GPU

#pragma omp target teams distribute parallel for num_teams(OPS_threads)        \
    thread_limit(OPS_threads_for_block)                                        \
        schedule(static, 1) map(tofrom : p_a1_0) reduction(min : p_a1_0)
#endif
  for (int i = 0; i < y_size * x_size; i++) {
    int n_x = i % x_size;
    int n_y = i / x_size;
    const double *dt_min =
        p_a0 + base0 + n_x * 1 * 1 + n_y * xdim0_calc_dt_kernel_min * 1 * 1;

    double *dt_min_val = &p_a1_0;

    *dt_min_val = MIN(*dt_min_val, dt_min[OPS_ACC0(0, 0)]);
  }
  p_a1[0] = p_a1_0;
}
#undef OPS_ACC0