//
// auto-generated by ops.py
//
#include "./OpenMP4/advec_cell_kernel1_ydir_openmp4_kernel_c.c"
#include "./OpenMP4/clover_leaf_common.h"

#define OPS_GPU

int xdim0_advec_cell_kernel1_ydir;
int xdim0_advec_cell_kernel1_ydir_h = -1;
int ydim0_advec_cell_kernel1_ydir;
int ydim0_advec_cell_kernel1_ydir_h = -1;
int xdim1_advec_cell_kernel1_ydir;
int xdim1_advec_cell_kernel1_ydir_h = -1;
int ydim1_advec_cell_kernel1_ydir;
int ydim1_advec_cell_kernel1_ydir_h = -1;
int xdim2_advec_cell_kernel1_ydir;
int xdim2_advec_cell_kernel1_ydir_h = -1;
int ydim2_advec_cell_kernel1_ydir;
int ydim2_advec_cell_kernel1_ydir_h = -1;
int xdim3_advec_cell_kernel1_ydir;
int xdim3_advec_cell_kernel1_ydir_h = -1;
int ydim3_advec_cell_kernel1_ydir;
int ydim3_advec_cell_kernel1_ydir_h = -1;
int xdim4_advec_cell_kernel1_ydir;
int xdim4_advec_cell_kernel1_ydir_h = -1;
int ydim4_advec_cell_kernel1_ydir;
int ydim4_advec_cell_kernel1_ydir_h = -1;

void ops_par_loop_advec_cell_kernel1_ydir(char const *name, ops_block block,
                                          int dim, int *range, ops_arg arg0,
                                          ops_arg arg1, ops_arg arg2,
                                          ops_arg arg3, ops_arg arg4) {

  // Timing
  double t1, t2, c1, c2;
  ops_arg args[5] = {arg0, arg1, arg2, arg3, arg4};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 5, range, 11))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(11, "advec_cell_kernel1_ydir");
    OPS_kernels[11].count++;
    ops_timers_core(&c1, &t1);
  }

  // compute localy allocated range for the sub-block

  int start[3];
  int end[3];
#ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned)
    return;
  for (int n = 0; n < 3; n++) {
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
  for (int n = 0; n < 3; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }
#endif

  int x_size = MAX(0, end[0] - start[0]);
  int y_size = MAX(0, end[1] - start[1]);
  int z_size = MAX(0, end[2] - start[2]);

  xdim0 = args[0].dat->size[0];
  ydim0 = args[0].dat->size[1];
  xdim1 = args[1].dat->size[0];
  ydim1 = args[1].dat->size[1];
  xdim2 = args[2].dat->size[0];
  ydim2 = args[2].dat->size[1];
  xdim3 = args[3].dat->size[0];
  ydim3 = args[3].dat->size[1];
  xdim4 = args[4].dat->size[0];
  ydim4 = args[4].dat->size[1];
  if (xdim0 != xdim0_advec_cell_kernel1_ydir_h ||
      ydim0 != ydim0_advec_cell_kernel1_ydir_h ||
      xdim1 != xdim1_advec_cell_kernel1_ydir_h ||
      ydim1 != ydim1_advec_cell_kernel1_ydir_h ||
      xdim2 != xdim2_advec_cell_kernel1_ydir_h ||
      ydim2 != ydim2_advec_cell_kernel1_ydir_h ||
      xdim3 != xdim3_advec_cell_kernel1_ydir_h ||
      ydim3 != ydim3_advec_cell_kernel1_ydir_h ||
      xdim4 != xdim4_advec_cell_kernel1_ydir_h ||
      ydim4 != ydim4_advec_cell_kernel1_ydir_h) {
    xdim0_advec_cell_kernel1_ydir = xdim0;
    xdim0_advec_cell_kernel1_ydir_h = xdim0;
    ydim0_advec_cell_kernel1_ydir = ydim0;
    ydim0_advec_cell_kernel1_ydir_h = ydim0;
    xdim1_advec_cell_kernel1_ydir = xdim1;
    xdim1_advec_cell_kernel1_ydir_h = xdim1;
    ydim1_advec_cell_kernel1_ydir = ydim1;
    ydim1_advec_cell_kernel1_ydir_h = ydim1;
    xdim2_advec_cell_kernel1_ydir = xdim2;
    xdim2_advec_cell_kernel1_ydir_h = xdim2;
    ydim2_advec_cell_kernel1_ydir = ydim2;
    ydim2_advec_cell_kernel1_ydir_h = ydim2;
    xdim3_advec_cell_kernel1_ydir = xdim3;
    xdim3_advec_cell_kernel1_ydir_h = xdim3;
    ydim3_advec_cell_kernel1_ydir = ydim3;
    ydim3_advec_cell_kernel1_ydir_h = ydim3;
    xdim4_advec_cell_kernel1_ydir = xdim4;
    xdim4_advec_cell_kernel1_ydir_h = xdim4;
    ydim4_advec_cell_kernel1_ydir = ydim4;
    ydim4_advec_cell_kernel1_ydir_h = ydim4;
  }

  int tot0 = 1;
  for (int i = 0; i < args[0].dat->block->dims; i++)
    tot0 = tot0 * args[0].dat->size[i];
  int tot1 = 1;
  for (int i = 0; i < args[1].dat->block->dims; i++)
    tot1 = tot1 * args[1].dat->size[i];
  int tot2 = 1;
  for (int i = 0; i < args[2].dat->block->dims; i++)
    tot2 = tot2 * args[2].dat->size[i];
  int tot3 = 1;
  for (int i = 0; i < args[3].dat->block->dims; i++)
    tot3 = tot3 * args[3].dat->size[i];
  int tot4 = 1;
  for (int i = 0; i < args[4].dat->block->dims; i++)
    tot4 = tot4 * args[4].dat->size[i];

  // set up initial pointers
  int base0 = args[0].dat->base_offset +
              args[0].dat->elem_size * start[0] * args[0].stencil->stride[0];
  base0 = base0 +
          args[0].dat->elem_size * args[0].dat->size[0] * start[1] *
              args[0].stencil->stride[1];
  base0 = base0 +
          args[0].dat->elem_size * args[0].dat->size[0] * args[0].dat->size[1] *
              start[2] * args[0].stencil->stride[2];
#ifdef OPS_GPU
  double *p_a0 = (double *)((char *)args[0].data_d + base0);
#else
  double *p_a0 = (double *)((char *)args[0].data);
#endif

  int base1 = args[1].dat->base_offset +
              args[1].dat->elem_size * start[0] * args[1].stencil->stride[0];
  base1 = base1 +
          args[1].dat->elem_size * args[1].dat->size[0] * start[1] *
              args[1].stencil->stride[1];
  base1 = base1 +
          args[1].dat->elem_size * args[1].dat->size[0] * args[1].dat->size[1] *
              start[2] * args[1].stencil->stride[2];
#ifdef OPS_GPU
  double *p_a1 = (double *)((char *)args[1].data_d + base1);
#else
  double *p_a1 = (double *)((char *)args[1].data);
#endif

  int base2 = args[2].dat->base_offset +
              args[2].dat->elem_size * start[0] * args[2].stencil->stride[0];
  base2 = base2 +
          args[2].dat->elem_size * args[2].dat->size[0] * start[1] *
              args[2].stencil->stride[1];
  base2 = base2 +
          args[2].dat->elem_size * args[2].dat->size[0] * args[2].dat->size[1] *
              start[2] * args[2].stencil->stride[2];
#ifdef OPS_GPU
  double *p_a2 = (double *)((char *)args[2].data_d + base2);
#else
  double *p_a2 = (double *)((char *)args[2].data);
#endif

  int base3 = args[3].dat->base_offset +
              args[3].dat->elem_size * start[0] * args[3].stencil->stride[0];
  base3 = base3 +
          args[3].dat->elem_size * args[3].dat->size[0] * start[1] *
              args[3].stencil->stride[1];
  base3 = base3 +
          args[3].dat->elem_size * args[3].dat->size[0] * args[3].dat->size[1] *
              start[2] * args[3].stencil->stride[2];
#ifdef OPS_GPU
  double *p_a3 = (double *)((char *)args[3].data_d + base3);
#else
  double *p_a3 = (double *)((char *)args[3].data);
#endif

  int base4 = args[4].dat->base_offset +
              args[4].dat->elem_size * start[0] * args[4].stencil->stride[0];
  base4 = base4 +
          args[4].dat->elem_size * args[4].dat->size[0] * start[1] *
              args[4].stencil->stride[1];
  base4 = base4 +
          args[4].dat->elem_size * args[4].dat->size[0] * args[4].dat->size[1] *
              start[2] * args[4].stencil->stride[2];
#ifdef OPS_GPU
  double *p_a4 = (double *)((char *)args[4].data_d + base4);
#else
  double *p_a4 = (double *)((char *)args[4].data);
#endif

#ifdef OPS_GPU
  for (int n = 0; n < 5; n++)
    if (args[n].argtype == OPS_ARG_DAT && args[n].dat->dirty_hd == 1) {
      int size = 1;
      for (int i = 0; i < args[n].dat->block->dims; i++)
        size = size * args[n].dat->size[i];
      args[n].dat->dirty_hd = 0;
    }
// ops_H_D_exchanges_device(args, 5);
#else
  for (int n = 0; n < 5; n++)
    if (args[n].argtype == OPS_ARG_DAT && args[n].dat->dirty_hd == 2) {
      int size = 1;
      for (int i = 0; i < args[n].dat->block->dims; i++)
        size = size * args[n].dat->size[i];
      args[n].dat->dirty_hd = 0;
    }
// ops_H_D_exchanges_host(args, 5);
#endif
  ops_halo_exchanges(args, 5, range);

#ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 5);
#else
  ops_H_D_exchanges_host(args, 5);
#endif
  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[11].mpi_time += t2 - t1;
  }

  advec_cell_kernel1_ydir_c_wrapper(p_a0, p_a1, p_a2, p_a3, p_a4, x_size,
                                    y_size, z_size);

  if (OPS_diags > 1) {
    ops_timers_core(&c1, &t1);
    OPS_kernels[11].time += t1 - t2;
  }
#ifdef OPS_GPU
  // for (int n = 0; n < 5; n++) {
  // if ((args[n].argtype == OPS_ARG_DAT) &&
  //(args[n].acc == OPS_INC || args[n].acc == OPS_WRITE ||
  // args[n].acc == OPS_RW)) {
  // args[n].dat->dirty_hd = 2;
  //}
  //}
  ops_set_dirtybit_device(args, 5);
#else
  // for (int n = 0; n < 5; n++) {
  // if ((args[n].argtype == OPS_ARG_DAT) &&
  //(args[n].acc == OPS_INC || args[n].acc == OPS_WRITE ||
  // args[n].acc == OPS_RW)) {
  // args[n].dat->dirty_hd = 1;
  //}
  //}
  ops_set_dirtybit_host(args, 5);
#endif
  ops_set_halo_dirtybit3(&args[0], range);
  ops_set_halo_dirtybit3(&args[1], range);

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c2, &t2);
    OPS_kernels[11].mpi_time += t2 - t1;
    OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg4);
  }
}
