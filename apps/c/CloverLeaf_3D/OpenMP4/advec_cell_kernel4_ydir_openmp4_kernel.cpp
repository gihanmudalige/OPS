//
// auto-generated by ops.py
//
#include "./OpenMP4/advec_cell_kernel4_ydir_openmp4_kernel_c.c"
#include "./OpenMP4/clover_leaf_common.h"

#define OPS_GPU

int xdim0_advec_cell_kernel4_ydir;
int xdim0_advec_cell_kernel4_ydir_h = -1;
int ydim0_advec_cell_kernel4_ydir;
int ydim0_advec_cell_kernel4_ydir_h = -1;
int xdim1_advec_cell_kernel4_ydir;
int xdim1_advec_cell_kernel4_ydir_h = -1;
int ydim1_advec_cell_kernel4_ydir;
int ydim1_advec_cell_kernel4_ydir_h = -1;
int xdim2_advec_cell_kernel4_ydir;
int xdim2_advec_cell_kernel4_ydir_h = -1;
int ydim2_advec_cell_kernel4_ydir;
int ydim2_advec_cell_kernel4_ydir_h = -1;
int xdim3_advec_cell_kernel4_ydir;
int xdim3_advec_cell_kernel4_ydir_h = -1;
int ydim3_advec_cell_kernel4_ydir;
int ydim3_advec_cell_kernel4_ydir_h = -1;
int xdim4_advec_cell_kernel4_ydir;
int xdim4_advec_cell_kernel4_ydir_h = -1;
int ydim4_advec_cell_kernel4_ydir;
int ydim4_advec_cell_kernel4_ydir_h = -1;
int xdim5_advec_cell_kernel4_ydir;
int xdim5_advec_cell_kernel4_ydir_h = -1;
int ydim5_advec_cell_kernel4_ydir;
int ydim5_advec_cell_kernel4_ydir_h = -1;
int xdim6_advec_cell_kernel4_ydir;
int xdim6_advec_cell_kernel4_ydir_h = -1;
int ydim6_advec_cell_kernel4_ydir;
int ydim6_advec_cell_kernel4_ydir_h = -1;
int xdim7_advec_cell_kernel4_ydir;
int xdim7_advec_cell_kernel4_ydir_h = -1;
int ydim7_advec_cell_kernel4_ydir;
int ydim7_advec_cell_kernel4_ydir_h = -1;
int xdim8_advec_cell_kernel4_ydir;
int xdim8_advec_cell_kernel4_ydir_h = -1;
int ydim8_advec_cell_kernel4_ydir;
int ydim8_advec_cell_kernel4_ydir_h = -1;
int xdim9_advec_cell_kernel4_ydir;
int xdim9_advec_cell_kernel4_ydir_h = -1;
int ydim9_advec_cell_kernel4_ydir;
int ydim9_advec_cell_kernel4_ydir_h = -1;
int xdim10_advec_cell_kernel4_ydir;
int xdim10_advec_cell_kernel4_ydir_h = -1;
int ydim10_advec_cell_kernel4_ydir;
int ydim10_advec_cell_kernel4_ydir_h = -1;

void ops_par_loop_advec_cell_kernel4_ydir(
    char const *name, ops_block block, int dim, int *range, ops_arg arg0,
    ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5,
    ops_arg arg6, ops_arg arg7, ops_arg arg8, ops_arg arg9, ops_arg arg10) {

  // Timing
  double t1, t2, c1, c2;
  ops_arg args[11] = {arg0, arg1, arg2, arg3, arg4, arg5,
                      arg6, arg7, arg8, arg9, arg10};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 11, range, 14))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(14, "advec_cell_kernel4_ydir");
    OPS_kernels[14].count++;
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
  xdim5 = args[5].dat->size[0];
  ydim5 = args[5].dat->size[1];
  xdim6 = args[6].dat->size[0];
  ydim6 = args[6].dat->size[1];
  xdim7 = args[7].dat->size[0];
  ydim7 = args[7].dat->size[1];
  xdim8 = args[8].dat->size[0];
  ydim8 = args[8].dat->size[1];
  xdim9 = args[9].dat->size[0];
  ydim9 = args[9].dat->size[1];
  xdim10 = args[10].dat->size[0];
  ydim10 = args[10].dat->size[1];
  if (xdim0 != xdim0_advec_cell_kernel4_ydir_h ||
      ydim0 != ydim0_advec_cell_kernel4_ydir_h ||
      xdim1 != xdim1_advec_cell_kernel4_ydir_h ||
      ydim1 != ydim1_advec_cell_kernel4_ydir_h ||
      xdim2 != xdim2_advec_cell_kernel4_ydir_h ||
      ydim2 != ydim2_advec_cell_kernel4_ydir_h ||
      xdim3 != xdim3_advec_cell_kernel4_ydir_h ||
      ydim3 != ydim3_advec_cell_kernel4_ydir_h ||
      xdim4 != xdim4_advec_cell_kernel4_ydir_h ||
      ydim4 != ydim4_advec_cell_kernel4_ydir_h ||
      xdim5 != xdim5_advec_cell_kernel4_ydir_h ||
      ydim5 != ydim5_advec_cell_kernel4_ydir_h ||
      xdim6 != xdim6_advec_cell_kernel4_ydir_h ||
      ydim6 != ydim6_advec_cell_kernel4_ydir_h ||
      xdim7 != xdim7_advec_cell_kernel4_ydir_h ||
      ydim7 != ydim7_advec_cell_kernel4_ydir_h ||
      xdim8 != xdim8_advec_cell_kernel4_ydir_h ||
      ydim8 != ydim8_advec_cell_kernel4_ydir_h ||
      xdim9 != xdim9_advec_cell_kernel4_ydir_h ||
      ydim9 != ydim9_advec_cell_kernel4_ydir_h ||
      xdim10 != xdim10_advec_cell_kernel4_ydir_h ||
      ydim10 != ydim10_advec_cell_kernel4_ydir_h) {
    xdim0_advec_cell_kernel4_ydir = xdim0;
    xdim0_advec_cell_kernel4_ydir_h = xdim0;
    ydim0_advec_cell_kernel4_ydir = ydim0;
    ydim0_advec_cell_kernel4_ydir_h = ydim0;
    xdim1_advec_cell_kernel4_ydir = xdim1;
    xdim1_advec_cell_kernel4_ydir_h = xdim1;
    ydim1_advec_cell_kernel4_ydir = ydim1;
    ydim1_advec_cell_kernel4_ydir_h = ydim1;
    xdim2_advec_cell_kernel4_ydir = xdim2;
    xdim2_advec_cell_kernel4_ydir_h = xdim2;
    ydim2_advec_cell_kernel4_ydir = ydim2;
    ydim2_advec_cell_kernel4_ydir_h = ydim2;
    xdim3_advec_cell_kernel4_ydir = xdim3;
    xdim3_advec_cell_kernel4_ydir_h = xdim3;
    ydim3_advec_cell_kernel4_ydir = ydim3;
    ydim3_advec_cell_kernel4_ydir_h = ydim3;
    xdim4_advec_cell_kernel4_ydir = xdim4;
    xdim4_advec_cell_kernel4_ydir_h = xdim4;
    ydim4_advec_cell_kernel4_ydir = ydim4;
    ydim4_advec_cell_kernel4_ydir_h = ydim4;
    xdim5_advec_cell_kernel4_ydir = xdim5;
    xdim5_advec_cell_kernel4_ydir_h = xdim5;
    ydim5_advec_cell_kernel4_ydir = ydim5;
    ydim5_advec_cell_kernel4_ydir_h = ydim5;
    xdim6_advec_cell_kernel4_ydir = xdim6;
    xdim6_advec_cell_kernel4_ydir_h = xdim6;
    ydim6_advec_cell_kernel4_ydir = ydim6;
    ydim6_advec_cell_kernel4_ydir_h = ydim6;
    xdim7_advec_cell_kernel4_ydir = xdim7;
    xdim7_advec_cell_kernel4_ydir_h = xdim7;
    ydim7_advec_cell_kernel4_ydir = ydim7;
    ydim7_advec_cell_kernel4_ydir_h = ydim7;
    xdim8_advec_cell_kernel4_ydir = xdim8;
    xdim8_advec_cell_kernel4_ydir_h = xdim8;
    ydim8_advec_cell_kernel4_ydir = ydim8;
    ydim8_advec_cell_kernel4_ydir_h = ydim8;
    xdim9_advec_cell_kernel4_ydir = xdim9;
    xdim9_advec_cell_kernel4_ydir_h = xdim9;
    ydim9_advec_cell_kernel4_ydir = ydim9;
    ydim9_advec_cell_kernel4_ydir_h = ydim9;
    xdim10_advec_cell_kernel4_ydir = xdim10;
    xdim10_advec_cell_kernel4_ydir_h = xdim10;
    ydim10_advec_cell_kernel4_ydir = ydim10;
    ydim10_advec_cell_kernel4_ydir_h = ydim10;
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
  int tot5 = 1;
  for (int i = 0; i < args[5].dat->block->dims; i++)
    tot5 = tot5 * args[5].dat->size[i];
  int tot6 = 1;
  for (int i = 0; i < args[6].dat->block->dims; i++)
    tot6 = tot6 * args[6].dat->size[i];
  int tot7 = 1;
  for (int i = 0; i < args[7].dat->block->dims; i++)
    tot7 = tot7 * args[7].dat->size[i];
  int tot8 = 1;
  for (int i = 0; i < args[8].dat->block->dims; i++)
    tot8 = tot8 * args[8].dat->size[i];
  int tot9 = 1;
  for (int i = 0; i < args[9].dat->block->dims; i++)
    tot9 = tot9 * args[9].dat->size[i];
  int tot10 = 1;
  for (int i = 0; i < args[10].dat->block->dims; i++)
    tot10 = tot10 * args[10].dat->size[i];

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

  int base5 = args[5].dat->base_offset +
              args[5].dat->elem_size * start[0] * args[5].stencil->stride[0];
  base5 = base5 +
          args[5].dat->elem_size * args[5].dat->size[0] * start[1] *
              args[5].stencil->stride[1];
  base5 = base5 +
          args[5].dat->elem_size * args[5].dat->size[0] * args[5].dat->size[1] *
              start[2] * args[5].stencil->stride[2];
#ifdef OPS_GPU
  double *p_a5 = (double *)((char *)args[5].data_d + base5);
#else
  double *p_a5 = (double *)((char *)args[5].data);
#endif

  int base6 = args[6].dat->base_offset +
              args[6].dat->elem_size * start[0] * args[6].stencil->stride[0];
  base6 = base6 +
          args[6].dat->elem_size * args[6].dat->size[0] * start[1] *
              args[6].stencil->stride[1];
  base6 = base6 +
          args[6].dat->elem_size * args[6].dat->size[0] * args[6].dat->size[1] *
              start[2] * args[6].stencil->stride[2];
#ifdef OPS_GPU
  double *p_a6 = (double *)((char *)args[6].data_d + base6);
#else
  double *p_a6 = (double *)((char *)args[6].data);
#endif

  int base7 = args[7].dat->base_offset +
              args[7].dat->elem_size * start[0] * args[7].stencil->stride[0];
  base7 = base7 +
          args[7].dat->elem_size * args[7].dat->size[0] * start[1] *
              args[7].stencil->stride[1];
  base7 = base7 +
          args[7].dat->elem_size * args[7].dat->size[0] * args[7].dat->size[1] *
              start[2] * args[7].stencil->stride[2];
#ifdef OPS_GPU
  double *p_a7 = (double *)((char *)args[7].data_d + base7);
#else
  double *p_a7 = (double *)((char *)args[7].data);
#endif

  int base8 = args[8].dat->base_offset +
              args[8].dat->elem_size * start[0] * args[8].stencil->stride[0];
  base8 = base8 +
          args[8].dat->elem_size * args[8].dat->size[0] * start[1] *
              args[8].stencil->stride[1];
  base8 = base8 +
          args[8].dat->elem_size * args[8].dat->size[0] * args[8].dat->size[1] *
              start[2] * args[8].stencil->stride[2];
#ifdef OPS_GPU
  double *p_a8 = (double *)((char *)args[8].data_d + base8);
#else
  double *p_a8 = (double *)((char *)args[8].data);
#endif

  int base9 = args[9].dat->base_offset +
              args[9].dat->elem_size * start[0] * args[9].stencil->stride[0];
  base9 = base9 +
          args[9].dat->elem_size * args[9].dat->size[0] * start[1] *
              args[9].stencil->stride[1];
  base9 = base9 +
          args[9].dat->elem_size * args[9].dat->size[0] * args[9].dat->size[1] *
              start[2] * args[9].stencil->stride[2];
#ifdef OPS_GPU
  double *p_a9 = (double *)((char *)args[9].data_d + base9);
#else
  double *p_a9 = (double *)((char *)args[9].data);
#endif

  int base10 = args[10].dat->base_offset +
               args[10].dat->elem_size * start[0] * args[10].stencil->stride[0];
  base10 = base10 +
           args[10].dat->elem_size * args[10].dat->size[0] * start[1] *
               args[10].stencil->stride[1];
  base10 = base10 +
           args[10].dat->elem_size * args[10].dat->size[0] *
               args[10].dat->size[1] * start[2] * args[10].stencil->stride[2];
#ifdef OPS_GPU
  double *p_a10 = (double *)((char *)args[10].data_d + base10);
#else
  double *p_a10 = (double *)((char *)args[10].data);
#endif

#ifdef OPS_GPU
  for (int n = 0; n < 11; n++)
    if (args[n].argtype == OPS_ARG_DAT && args[n].dat->dirty_hd == 1) {
      int size = 1;
      for (int i = 0; i < args[n].dat->block->dims; i++)
        size = size * args[n].dat->size[i];
      args[n].dat->dirty_hd = 0;
    }
// ops_H_D_exchanges_device(args, 11);
#else
  for (int n = 0; n < 11; n++)
    if (args[n].argtype == OPS_ARG_DAT && args[n].dat->dirty_hd == 2) {
      int size = 1;
      for (int i = 0; i < args[n].dat->block->dims; i++)
        size = size * args[n].dat->size[i];
      args[n].dat->dirty_hd = 0;
    }
// ops_H_D_exchanges_host(args, 11);
#endif
  ops_halo_exchanges(args, 11, range);

#ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 11);
#else
  ops_H_D_exchanges_host(args, 11);
#endif
  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[14].mpi_time += t2 - t1;
  }

  advec_cell_kernel4_ydir_c_wrapper(p_a0, p_a1, p_a2, p_a3, p_a4, p_a5, p_a6,
                                    p_a7, p_a8, p_a9, p_a10, x_size, y_size,
                                    z_size);

  if (OPS_diags > 1) {
    ops_timers_core(&c1, &t1);
    OPS_kernels[14].time += t1 - t2;
  }
#ifdef OPS_GPU
  // for (int n = 0; n < 11; n++) {
  // if ((args[n].argtype == OPS_ARG_DAT) &&
  //(args[n].acc == OPS_INC || args[n].acc == OPS_WRITE ||
  // args[n].acc == OPS_RW)) {
  // args[n].dat->dirty_hd = 2;
  //}
  //}
  ops_set_dirtybit_device(args, 11);
#else
  // for (int n = 0; n < 11; n++) {
  // if ((args[n].argtype == OPS_ARG_DAT) &&
  //(args[n].acc == OPS_INC || args[n].acc == OPS_WRITE ||
  // args[n].acc == OPS_RW)) {
  // args[n].dat->dirty_hd = 1;
  //}
  //}
  ops_set_dirtybit_host(args, 11);
#endif
  ops_set_halo_dirtybit3(&args[0], range);
  ops_set_halo_dirtybit3(&args[1], range);
  ops_set_halo_dirtybit3(&args[6], range);
  ops_set_halo_dirtybit3(&args[7], range);
  ops_set_halo_dirtybit3(&args[8], range);
  ops_set_halo_dirtybit3(&args[9], range);

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c2, &t2);
    OPS_kernels[14].mpi_time += t2 - t1;
    OPS_kernels[14].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[14].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[14].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[14].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[14].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[14].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[14].transfer += ops_compute_transfer(dim, start, end, &arg6);
    OPS_kernels[14].transfer += ops_compute_transfer(dim, start, end, &arg7);
    OPS_kernels[14].transfer += ops_compute_transfer(dim, start, end, &arg8);
    OPS_kernels[14].transfer += ops_compute_transfer(dim, start, end, &arg9);
    OPS_kernels[14].transfer += ops_compute_transfer(dim, start, end, &arg10);
  }
}
