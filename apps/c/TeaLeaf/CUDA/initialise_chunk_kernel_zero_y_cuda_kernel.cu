//
// auto-generated by ops.py
//
__constant__ int xdim0_initialise_chunk_kernel_zero_y;
int xdim0_initialise_chunk_kernel_zero_y_h = -1;

#undef OPS_ACC0

#define OPS_ACC0(x, y) (x + xdim0_initialise_chunk_kernel_zero_y * (y))

// user function
__device__

    void
    initialise_chunk_kernel_zero_y_gpu(double *var) {
  *var = 0.0;
}

#undef OPS_ACC0

__global__ void ops_initialise_chunk_kernel_zero_y(double *__restrict arg0,
                                                   int size0, int size1) {

  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 0 * 1 + idx_y * 1 * 1 * xdim0_initialise_chunk_kernel_zero_y;

  if (idx_x < size0 && idx_y < size1) {
    initialise_chunk_kernel_zero_y_gpu(arg0);
  }
}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_initialise_chunk_kernel_zero_y(char const *name,
                                                 ops_block block, int dim,
                                                 int *range, ops_arg arg0) {
#else
void ops_par_loop_initialise_chunk_kernel_zero_y_execute(
    ops_kernel_descriptor *desc) {
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
#endif

  // Timing
  double t1, t2, c1, c2;

  ops_arg args[1] = {arg0};

#if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args, 1, range, 7))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(7, "initialise_chunk_kernel_zero_y");
    OPS_kernels[7].count++;
    ops_timers_core(&c1, &t1);
  }

  // compute locally allocated range for the sub-block
  int start[2];
  int end[2];
#if OPS_MPI && !OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned)
    return;
  for (int n = 0; n < 2; n++) {
    start[n] = sb->decomp_disp[n];
    end[n] = sb->decomp_disp[n] + sb->decomp_size[n];
    if (start[n] >= range[2 * n]) {
      start[n] = 0;
    } else {
      start[n] = range[2 * n] - start[n];
    }
    if (sb->id_m[n] == MPI_PROC_NULL && range[2 * n] < 0)
      start[n] = range[2 * n];
    if (end[n] >= range[2 * n + 1]) {
      end[n] = range[2 * n + 1] - sb->decomp_disp[n];
    } else {
      end[n] = sb->decomp_size[n];
    }
    if (sb->id_p[n] == MPI_PROC_NULL &&
        (range[2 * n + 1] > sb->decomp_disp[n] + sb->decomp_size[n]))
      end[n] += (range[2 * n + 1] - sb->decomp_disp[n] - sb->decomp_size[n]);
  }
#else
  for (int n = 0; n < 2; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }
#endif

  int x_size = MAX(0, end[0] - start[0]);
  int y_size = MAX(0, end[1] - start[1]);

  int xdim0 = args[0].dat->size[0];

  if (xdim0 != xdim0_initialise_chunk_kernel_zero_y_h) {
    cudaMemcpyToSymbol(xdim0_initialise_chunk_kernel_zero_y, &xdim0,
                       sizeof(int));
    xdim0_initialise_chunk_kernel_zero_y_h = xdim0;
  }

  dim3 grid((x_size - 1) / OPS_block_size_x + 1,
            (y_size - 1) / OPS_block_size_y + 1, 1);
  dim3 tblock(OPS_block_size_x, OPS_block_size_y, 1);

  int dat0 = (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);

  char *p_a[1];

  // set up initial pointers
  int base0 = args[0].dat->base_offset +
              dat0 * 1 * (start[0] * args[0].stencil->stride[0]);
  base0 = base0 +
          dat0 * args[0].dat->size[0] * (start[1] * args[0].stencil->stride[1]);
  p_a[0] = (char *)args[0].data_d + base0;

#ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 1);
  ops_halo_exchanges(args, 1, range);
#endif

  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[7].mpi_time += t2 - t1;
  }

  // call kernel wrapper function, passing in pointers to data
  if (x_size > 0 && y_size > 0)
    ops_initialise_chunk_kernel_zero_y<<<grid, tblock>>>((double *)p_a[0],
                                                         x_size, y_size);

  cutilSafeCall(cudaGetLastError());

  if (OPS_diags > 1) {
    cutilSafeCall(cudaDeviceSynchronize());
    ops_timers_core(&c1, &t1);
    OPS_kernels[7].time += t1 - t2;
  }

#ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 1);
  ops_set_halo_dirtybit3(&args[0], range);
#endif

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c2, &t2);
    OPS_kernels[7].mpi_time += t2 - t1;
    OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg0);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_initialise_chunk_kernel_zero_y(char const *name,
                                                 ops_block block, int dim,
                                                 int *range, ops_arg arg0) {
  ops_kernel_descriptor *desc =
      (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 7;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 7;
  for (int i = 0; i < 4; i++) {
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 1;
  desc->args = (ops_arg *)malloc(1 * sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->function = ops_par_loop_initialise_chunk_kernel_zero_y_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(7, "initialise_chunk_kernel_zero_y");
  }
  ops_enqueue_kernel(desc);
}
#endif
