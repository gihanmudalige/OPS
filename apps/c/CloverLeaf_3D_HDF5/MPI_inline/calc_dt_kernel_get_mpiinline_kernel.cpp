//
// auto-generated by ops.py
//

extern int xdim0_calc_dt_kernel_get;
int xdim0_calc_dt_kernel_get_h = -1;
extern int ydim0_calc_dt_kernel_get;
int ydim0_calc_dt_kernel_get_h = -1;
extern int xdim1_calc_dt_kernel_get;
int xdim1_calc_dt_kernel_get_h = -1;
extern int ydim1_calc_dt_kernel_get;
int ydim1_calc_dt_kernel_get_h = -1;
extern int xdim4_calc_dt_kernel_get;
int xdim4_calc_dt_kernel_get_h = -1;
extern int ydim4_calc_dt_kernel_get;
int ydim4_calc_dt_kernel_get_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void calc_dt_kernel_get_c_wrapper(double *p_a0, double *p_a1, double *p_a2,
                                  double *p_a3, double *p_a4, double *p_a5,
                                  int x_size, int y_size, int z_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_calc_dt_kernel_get(char const *name, ops_block block, int dim,
                                     int *range, ops_arg arg0, ops_arg arg1,
                                     ops_arg arg2, ops_arg arg3, ops_arg arg4,
                                     ops_arg arg5) {

  ops_arg args[6] = {arg0, arg1, arg2, arg3, arg4, arg5};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 6, range, 99))
    return;
#endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance, 99, "calc_dt_kernel_get");
    block->instance->OPS_kernels[99].count++;
  }

  // compute localy allocated range for the sub-block
  int start[3];
  int end[3];
  int arg_idx[3];

#ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (compute_ranges(args, 6, block, range, start, end, arg_idx) < 0)
    return;
#else
  for (int n = 0; n < 3; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
    arg_idx[n] = start[n];
  }
#endif

  int x_size = MAX(0, end[0] - start[0]);
  int y_size = MAX(0, end[1] - start[1]);
  int z_size = MAX(0, end[2] - start[2]);

  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int xdim1 = args[1].dat->size[0];
  int ydim1 = args[1].dat->size[1];
  int xdim4 = args[4].dat->size[0];
  int ydim4 = args[4].dat->size[1];

  // Timing
  double t1, t2, c1, c2;
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
  }

  if (xdim0 != xdim0_calc_dt_kernel_get_h ||
      ydim0 != ydim0_calc_dt_kernel_get_h ||
      xdim1 != xdim1_calc_dt_kernel_get_h ||
      ydim1 != ydim1_calc_dt_kernel_get_h ||
      xdim4 != xdim4_calc_dt_kernel_get_h ||
      ydim4 != ydim4_calc_dt_kernel_get_h) {
    xdim0_calc_dt_kernel_get = xdim0;
    xdim0_calc_dt_kernel_get_h = xdim0;
    ydim0_calc_dt_kernel_get = ydim0;
    ydim0_calc_dt_kernel_get_h = ydim0;
    xdim1_calc_dt_kernel_get = xdim1;
    xdim1_calc_dt_kernel_get_h = xdim1;
    ydim1_calc_dt_kernel_get = ydim1;
    ydim1_calc_dt_kernel_get_h = ydim1;
    xdim4_calc_dt_kernel_get = xdim4;
    xdim4_calc_dt_kernel_get_h = xdim4;
    ydim4_calc_dt_kernel_get = ydim4;
    ydim4_calc_dt_kernel_get_h = ydim4;
  }

#ifdef OPS_MPI
  double *arg2h =
      (double *)(((ops_reduction)args[2].data)->data +
                 ((ops_reduction)args[2].data)->size * block->index);
#else
  double *arg2h = (double *)(((ops_reduction)args[2].data)->data);
#endif
#ifdef OPS_MPI
  double *arg3h =
      (double *)(((ops_reduction)args[3].data)->data +
                 ((ops_reduction)args[3].data)->size * block->index);
#else
  double *arg3h = (double *)(((ops_reduction)args[3].data)->data);
#endif
#ifdef OPS_MPI
  double *arg5h =
      (double *)(((ops_reduction)args[5].data)->data +
                 ((ops_reduction)args[5].data)->size * block->index);
#else
  double *arg5h = (double *)(((ops_reduction)args[5].data)->data);
#endif
  int dat0 = (block->instance->OPS_soa ? args[0].dat->type_size
                                       : args[0].dat->elem_size);
  int dat1 = (block->instance->OPS_soa ? args[1].dat->type_size
                                       : args[1].dat->elem_size);
  int dat4 = (block->instance->OPS_soa ? args[4].dat->type_size
                                       : args[4].dat->elem_size);

  // set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset +
              (block->instance->OPS_soa ? args[0].dat->type_size
                                        : args[0].dat->elem_size) *
                  start[0] * args[0].stencil->stride[0];
  base0 = base0 +
          (block->instance->OPS_soa ? args[0].dat->type_size
                                    : args[0].dat->elem_size) *
              args[0].dat->size[0] * start[1] * args[0].stencil->stride[1];
  base0 = base0 +
          (block->instance->OPS_soa ? args[0].dat->type_size
                                    : args[0].dat->elem_size) *
              args[0].dat->size[0] * args[0].dat->size[1] * start[2] *
              args[0].stencil->stride[2];
  double *p_a0 = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset +
              (block->instance->OPS_soa ? args[1].dat->type_size
                                        : args[1].dat->elem_size) *
                  start[0] * args[1].stencil->stride[0];
  base1 = base1 +
          (block->instance->OPS_soa ? args[1].dat->type_size
                                    : args[1].dat->elem_size) *
              args[1].dat->size[0] * start[1] * args[1].stencil->stride[1];
  base1 = base1 +
          (block->instance->OPS_soa ? args[1].dat->type_size
                                    : args[1].dat->elem_size) *
              args[1].dat->size[0] * args[1].dat->size[1] * start[2] *
              args[1].stencil->stride[2];
  double *p_a1 = (double *)(args[1].data + base1);

#ifdef OPS_MPI
  double *p_a2 = (double *)(((ops_reduction)args[2].data)->data +
                            ((ops_reduction)args[2].data)->size * block->index);
#else
  double *p_a2 = (double *)(((ops_reduction)args[2].data)->data);
#endif

#ifdef OPS_MPI
  double *p_a3 = (double *)(((ops_reduction)args[3].data)->data +
                            ((ops_reduction)args[3].data)->size * block->index);
#else
  double *p_a3 = (double *)(((ops_reduction)args[3].data)->data);
#endif

  int base4 = args[4].dat->base_offset +
              (block->instance->OPS_soa ? args[4].dat->type_size
                                        : args[4].dat->elem_size) *
                  start[0] * args[4].stencil->stride[0];
  base4 = base4 +
          (block->instance->OPS_soa ? args[4].dat->type_size
                                    : args[4].dat->elem_size) *
              args[4].dat->size[0] * start[1] * args[4].stencil->stride[1];
  base4 = base4 +
          (block->instance->OPS_soa ? args[4].dat->type_size
                                    : args[4].dat->elem_size) *
              args[4].dat->size[0] * args[4].dat->size[1] * start[2] *
              args[4].stencil->stride[2];
  double *p_a4 = (double *)(args[4].data + base4);

#ifdef OPS_MPI
  double *p_a5 = (double *)(((ops_reduction)args[5].data)->data +
                            ((ops_reduction)args[5].data)->size * block->index);
#else
  double *p_a5 = (double *)(((ops_reduction)args[5].data)->data);
#endif

  ops_H_D_exchanges_host(args, 6);
  ops_halo_exchanges(args, 6, range);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1, &t1);
    block->instance->OPS_kernels[99].mpi_time += t1 - t2;
  }

  calc_dt_kernel_get_c_wrapper(p_a0, p_a1, p_a2, p_a3, p_a4, p_a5, x_size,
                               y_size, z_size);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    block->instance->OPS_kernels[99].time += t2 - t1;
  }
  ops_set_dirtybit_host(args, 6);

  // Update kernel record
  if (block->instance->OPS_diags > 1) {
    block->instance->OPS_kernels[99].transfer +=
        ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[99].transfer +=
        ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[99].transfer +=
        ops_compute_transfer(dim, start, end, &arg4);
  }
}
