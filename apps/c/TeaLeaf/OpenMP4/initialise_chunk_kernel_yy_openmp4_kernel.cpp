//
// auto-generated by ops.py
//
#include "./OpenMP4/initialise_chunk_kernel_yy_openmp4_kernel_c.c"
#include "./OpenMP4/tea_leaf_common.h"

#define OPS_GPU

int xdim0_initialise_chunk_kernel_yy;
int xdim0_initialise_chunk_kernel_yy_h = -1;

void ops_par_loop_initialise_chunk_kernel_yy(char const *name, ops_block block,
                                             int dim, int *range, ops_arg arg0,
                                             ops_arg arg1) {

  // Timing
  double t1, t2, c1, c2;
  ops_arg args[2] = {arg0, arg1};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 2, range, 9))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(9, "initialise_chunk_kernel_yy");
    OPS_kernels[9].count++;
    ops_timers_core(&c1, &t1);
  }

  // compute localy allocated range for the sub-block

  int start[2];
  int end[2];
#ifdef OPS_MPI
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

  int arg_idx[2];
#ifdef OPS_MPI
  arg_idx[0] = sb->decomp_disp[0] + start[0];
  arg_idx[1] = sb->decomp_disp[1] + start[1];
#else
  arg_idx[0] = start[0];
  arg_idx[1] = start[1];
#endif

  xdim0 = args[0].dat->size[0];
  if (xdim0 != xdim0_initialise_chunk_kernel_yy_h) {
    xdim0_initialise_chunk_kernel_yy = xdim0;
    xdim0_initialise_chunk_kernel_yy_h = xdim0;
  }

  int tot0 = 1;
  for (int i = 0; i < args[0].dat->block->dims; i++)
    tot0 = tot0 * args[0].dat->size[i];

  // set up initial pointers
  int base0 = args[0].dat->base_offset +
              args[0].dat->elem_size * start[0] * args[0].stencil->stride[0];
  base0 = base0 +
          args[0].dat->elem_size * args[0].dat->size[0] * start[1] *
              args[0].stencil->stride[1];
#ifdef OPS_GPU
  int *p_a0 = (int *)((char *)args[0].data_d + base0);
#else
  int *p_a0 = (int *)((char *)args[0].data);
#endif

  int *p_a1 = NULL;

#ifdef OPS_GPU
  for (int n = 0; n < 2; n++)
    if (args[n].argtype == OPS_ARG_DAT && args[n].dat->dirty_hd == 1) {
      int size = 1;
      for (int i = 0; i < args[n].dat->block->dims; i++)
        size = size * args[n].dat->size[i];
      args[n].dat->dirty_hd = 0;
    }
// ops_H_D_exchanges_device(args, 2);
#else
  for (int n = 0; n < 2; n++)
    if (args[n].argtype == OPS_ARG_DAT && args[n].dat->dirty_hd == 2) {
      int size = 1;
      for (int i = 0; i < args[n].dat->block->dims; i++)
        size = size * args[n].dat->size[i];
      args[n].dat->dirty_hd = 0;
    }
// ops_H_D_exchanges_host(args, 2);
#endif
  ops_halo_exchanges(args, 2, range);

#ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 2);
#else
  ops_H_D_exchanges_host(args, 2);
#endif
  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[9].mpi_time += t2 - t1;
  }

  initialise_chunk_kernel_yy_c_wrapper(p_a0, p_a1, arg_idx[0], arg_idx[1],
                                       x_size, y_size);

  if (OPS_diags > 1) {
    ops_timers_core(&c1, &t1);
    OPS_kernels[9].time += t1 - t2;
  }
#ifdef OPS_GPU
  // for (int n = 0; n < 2; n++) {
  // if ((args[n].argtype == OPS_ARG_DAT) &&
  //(args[n].acc == OPS_INC || args[n].acc == OPS_WRITE ||
  // args[n].acc == OPS_RW)) {
  // args[n].dat->dirty_hd = 2;
  //}
  //}
  ops_set_dirtybit_device(args, 2);
#else
  // for (int n = 0; n < 2; n++) {
  // if ((args[n].argtype == OPS_ARG_DAT) &&
  //(args[n].acc == OPS_INC || args[n].acc == OPS_WRITE ||
  // args[n].acc == OPS_RW)) {
  // args[n].dat->dirty_hd = 1;
  //}
  //}
  ops_set_dirtybit_host(args, 2);
#endif
  ops_set_halo_dirtybit3(&args[0], range);

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c2, &t2);
    OPS_kernels[9].mpi_time += t2 - t1;
    OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg0);
  }
}
