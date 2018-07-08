//
// auto-generated by ops.py
//
#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 + n_y * xdim0_advec_mom_kernel2_x * 1 + x +                         \
   xdim0_advec_mom_kernel2_x * (y))
#define OPS_ACC1(x, y)                                                         \
  (n_x * 1 + n_y * xdim1_advec_mom_kernel2_x * 1 + x +                         \
   xdim1_advec_mom_kernel2_x * (y))
#define OPS_ACC2(x, y)                                                         \
  (n_x * 1 + n_y * xdim2_advec_mom_kernel2_x * 1 + x +                         \
   xdim2_advec_mom_kernel2_x * (y))
#define OPS_ACC3(x, y)                                                         \
  (n_x * 1 + n_y * xdim3_advec_mom_kernel2_x * 1 + x +                         \
   xdim3_advec_mom_kernel2_x * (y))

// user function

// host stub function
void ops_par_loop_advec_mom_kernel2_x_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];

  // Timing
  double t1, t2, c1, c2;

  ops_arg args[4] = {arg0, arg1, arg2, arg3};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 4, range, 76))
    return;
#endif

  if (OPS_diags > 1) {
    OPS_kernels[76].count++;
    ops_timers_core(&c2, &t2);
  }

  // compute locally allocated range for the sub-block
  int start[2];
  int end[2];

  for (int n = 0; n < 2; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }

#ifdef OPS_DEBUG
  ops_register_args(args, "advec_mom_kernel2_x");
#endif

  // set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double *__restrict__ vel1 = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  const double *__restrict__ node_mass_post = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  const double *__restrict__ node_mass_pre = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  const double *__restrict__ mom_flux = (double *)(args[3].data + base3);

  // initialize global variable with the dimension of dats
  int xdim0_advec_mom_kernel2_x = args[0].dat->size[0];
  int xdim1_advec_mom_kernel2_x = args[1].dat->size[0];
  int xdim2_advec_mom_kernel2_x = args[2].dat->size[0];
  int xdim3_advec_mom_kernel2_x = args[3].dat->size[0];

  if (OPS_diags > 1) {
    ops_timers_core(&c1, &t1);
    OPS_kernels[76].mpi_time += t1 - t2;
  }

#pragma omp parallel for
  for (int n_y = start[1]; n_y < end[1]; n_y++) {
#ifdef intel
#pragma loop_count(10000)
#pragma omp simd aligned(vel1, node_mass_post, node_mass_pre, mom_flux)
#else
#pragma simd
#endif
    for (int n_x = start[0]; n_x < end[0]; n_x++) {

      vel1[OPS_ACC0(0, 0)] =
          (vel1[OPS_ACC0(0, 0)] * node_mass_pre[OPS_ACC2(0, 0)] +
           mom_flux[OPS_ACC3(-1, 0)] - mom_flux[OPS_ACC3(0, 0)]) /
          node_mass_post[OPS_ACC1(0, 0)];
    }
  }
  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[76].time += t2 - t1;
  }

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c1, &t1);
    OPS_kernels[76].mpi_time += t1 - t2;
    OPS_kernels[76].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[76].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[76].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[76].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3

void ops_par_loop_advec_mom_kernel2_x(char const *name, ops_block block,
                                      int dim, int *range, ops_arg arg0,
                                      ops_arg arg1, ops_arg arg2,
                                      ops_arg arg3) {
  ops_kernel_descriptor *desc =
      (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 76;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 76;
  for (int i = 0; i < 4; i++) {
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 4;
  desc->args = (ops_arg *)malloc(4 * sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->function = ops_par_loop_advec_mom_kernel2_x_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(76, "advec_mom_kernel2_x");
  }
  ops_enqueue_kernel(desc);
}
