//
// auto-generated by ops.py
//

// user function
inline void tea_leaf_norm2_kernel(const double *x, double *norm) {
  *norm = *norm + x[OPS_ACC0(0, 0)] * x[OPS_ACC0(0, 0)];
}

// host stub function
void ops_par_loop_tea_leaf_norm2_kernel(char const *name, ops_block block,
                                        int dim, int *range, ops_arg arg0,
                                        ops_arg arg1) {

  // Timing
  double t1, t2, c1, c2;

  char *p_a[2];
  int offs[2][2];
  ops_arg args[2] = {arg0, arg1};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 2, range, 39))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(39, "tea_leaf_norm2_kernel");
    OPS_kernels[39].count++;
    ops_timers_core(&c2, &t2);
  }

  // compute locally allocated range for the sub-block
  int start[2];
  int end[2];

#ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
#endif
#ifdef OPS_DEBUG
  ops_register_args(args, "tea_leaf_norm2_kernel");
#endif

  int arg_idx[2];
  int arg_idx_base[2];
#ifdef OPS_MPI
  if (compute_ranges(args, 2, block, range, start, end, arg_idx) < 0)
    return;
#else  // OPS_MPI
  for (int n = 0; n < 2; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
    arg_idx[n] = start[n];
  }
#endif // OPS_MPI
  for (int n = 0; n < 2; n++) {
    arg_idx_base[n] = arg_idx[n];
  }
  offs[0][0] = args[0].stencil->stride[0] * 1; // unit step in x dimension
  offs[0][1] =
      off2D(1, &start[0], &end[0], args[0].dat->size, args[0].stencil->stride) -
      offs[0][0];

  int off0_0 = offs[0][0];
  int off0_1 = offs[0][1];
  int dat0 = (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);

  // set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset +
              (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
                  start[0] * args[0].stencil->stride[0];
  base0 = base0 +
          (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
              args[0].dat->size[0] * start[1] * args[0].stencil->stride[1];
  p_a[0] = (char *)args[0].data + base0;

#ifdef OPS_MPI
  p_a[1] = ((ops_reduction)args[1].data)->data +
           ((ops_reduction)args[1].data)->size * block->index;
#else
  p_a[1] = ((ops_reduction)args[1].data)->data;
#endif

  // initialize global variable with the dimension of dats
  xdim0 = args[0].dat->size[0];

  // Halo Exchanges
  ops_H_D_exchanges_host(args, 2);
  ops_halo_exchanges(args, 2, range);
  ops_H_D_exchanges_host(args, 2);

  if (OPS_diags > 1) {
    ops_timers_core(&c1, &t1);
    OPS_kernels[39].mpi_time += t1 - t2;
  }

  int n_x;
  for (int n_y = start[1]; n_y < end[1]; n_y++) {
#pragma novector
    for (n_x = start[0];
         n_x < start[0] + ((end[0] - start[0]) / SIMD_VEC) * SIMD_VEC;
         n_x += SIMD_VEC) {
      // call kernel function, passing in pointers to data -vectorised
      for (int i = 0; i < SIMD_VEC; i++) {
        tea_leaf_norm2_kernel((double *)p_a[0] + i * 1 * 1, (double *)p_a[1]);
      }

      // shift pointers to data x direction
      p_a[0] = p_a[0] + (dat0 * off0_0) * SIMD_VEC;
    }

    for (int n_x = start[0] + ((end[0] - start[0]) / SIMD_VEC) * SIMD_VEC;
         n_x < end[0]; n_x++) {
      // call kernel function, passing in pointers to data - remainder
      tea_leaf_norm2_kernel((double *)p_a[0], (double *)p_a[1]);

      // shift pointers to data x direction
      p_a[0] = p_a[0] + (dat0 * off0_0);
    }

    // shift pointers to data y direction
    p_a[0] = p_a[0] + (dat0 * off0_1);
  }
  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[39].time += t2 - t1;
  }
  ops_set_dirtybit_host(args, 2);

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c1, &t1);
    OPS_kernels[39].mpi_time += t1 - t2;
    OPS_kernels[39].transfer += ops_compute_transfer(dim, start, end, &arg0);
  }
}
