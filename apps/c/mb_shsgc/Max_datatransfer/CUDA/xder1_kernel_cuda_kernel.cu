//
// auto-generated by ops.py
//
__constant__ int xdim0_xder1_kernel;
int xdim0_xder1_kernel_h = -1;
__constant__ int xdim1_xder1_kernel;
int xdim1_xder1_kernel_h = -1;

#undef OPS_ACC0
#undef OPS_ACC1

#define OPS_ACC0(x) (x)
#define OPS_ACC1(x) (x)

// user function
__device__

    void
    xder1_kernel_gpu(const double *inp, double *out) {
  double dix = 1 / (12.00 * dx);
  out[OPS_ACC1(0)] = (inp[OPS_ACC0(-2)] - inp[OPS_ACC0(2)] +
                      8.0 * (inp[OPS_ACC0(1)] - inp[OPS_ACC0(-1)])) *
                     dix;
}

#undef OPS_ACC0
#undef OPS_ACC1

__global__ void ops_xder1_kernel(const double *__restrict arg0,
                                 double *__restrict arg1, int size0) {

  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1 * 1;
  arg1 += idx_x * 1 * 1;

  if (idx_x < size0) {
    xder1_kernel_gpu(arg0, arg1);
  }
}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_xder1_kernel(char const *name, ops_block block, int dim,
                               int *range, ops_arg arg0, ops_arg arg1) {
#else
void ops_par_loop_xder1_kernel_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
#if OPS_MPI
  ops_block block = desc->block;
#endif
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
#endif

  // Timing
  double t1, t2, c1, c2;

  ops_arg args[2] = {arg0, arg1};

#if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args, 2, range, 4))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(4, "xder1_kernel");
    OPS_kernels[4].count++;
    ops_timers_core(&c1, &t1);
  }

  // compute locally allocated range for the sub-block
  int start[1];
  int end[1];
#if OPS_MPI && !OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
#endif // OPS_MPI

  int arg_idx[1];
  int arg_idx_base[1];
#ifdef OPS_MPI
  if (compute_ranges(args, 2, block, range, start, end, arg_idx) < 0)
    return;
#else // OPS_MPI
  for (int n = 0; n < 1; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
    arg_idx[n] = start[n];
  }
#endif
  for (int n = 0; n < 1; n++) {
    arg_idx_base[n] = arg_idx[n];
  }
  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];

  if (xdim0 != xdim0_xder1_kernel_h || xdim1 != xdim1_xder1_kernel_h) {
    cudaMemcpyToSymbol(xdim0_xder1_kernel, &xdim0, sizeof(int));
    xdim0_xder1_kernel_h = xdim0;
    cudaMemcpyToSymbol(xdim1_xder1_kernel, &xdim1, sizeof(int));
    xdim1_xder1_kernel_h = xdim1;
  }

  int x_size = MAX(0, end[0] - start[0]);

  dim3 grid((x_size - 1) / OPS_block_size_x + 1, 1, 1);
  dim3 tblock(OPS_block_size_x, 1, 1);

  int dat0 = (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  int dat1 = (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);

  char *p_a[2];

  // set up initial pointers
  int base0 = args[0].dat->base_offset +
              dat0 * 1 * (start[0] * args[0].stencil->stride[0]);
  p_a[0] = (char *)args[0].data_d + base0;

  int base1 = args[1].dat->base_offset +
              dat1 * 1 * (start[0] * args[1].stencil->stride[0]);
  p_a[1] = (char *)args[1].data_d + base1;

#ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 2);
  ops_halo_exchanges(args, 2, range);
#endif

  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[4].mpi_time += t2 - t1;
  }

  // call kernel wrapper function, passing in pointers to data
  if (x_size > 0)
    ops_xder1_kernel<<<grid, tblock>>>((double *)p_a[0], (double *)p_a[1],
                                       x_size);

  cutilSafeCall(cudaGetLastError());

  if (OPS_diags > 1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1, &t1);
    OPS_kernels[4].time += t1 - t2;
  }

#ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 2);
  ops_set_halo_dirtybit3(&args[1], range);
#endif

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c2, &t2);
    OPS_kernels[4].mpi_time += t2 - t1;
    OPS_kernels[4].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[4].transfer += ops_compute_transfer(dim, start, end, &arg1);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_xder1_kernel(char const *name, ops_block block, int dim,
                               int *range, ops_arg arg0, ops_arg arg1) {
  ops_kernel_descriptor *desc =
      (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 4;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 4;
  for (int i = 0; i < 2; i++) {
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 2;
  desc->args = (ops_arg *)malloc(2 * sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->function = ops_par_loop_xder1_kernel_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(4, "xder1_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
