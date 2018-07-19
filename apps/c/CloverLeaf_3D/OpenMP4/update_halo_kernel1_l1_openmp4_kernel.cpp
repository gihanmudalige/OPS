//
// auto-generated by ops.py
//
#include "./OpenMP4/clover_leaf_common.h"
#include "./OpenMP4/update_halo_kernel1_l1_openmp4_kernel_c.c"

#define OPS_GPU

int xdim0_update_halo_kernel1_l1;
int xdim0_update_halo_kernel1_l1_h = -1;
int ydim0_update_halo_kernel1_l1;
int ydim0_update_halo_kernel1_l1_h = -1;
int xdim1_update_halo_kernel1_l1;
int xdim1_update_halo_kernel1_l1_h = -1;
int ydim1_update_halo_kernel1_l1;
int ydim1_update_halo_kernel1_l1_h = -1;
int xdim2_update_halo_kernel1_l1;
int xdim2_update_halo_kernel1_l1_h = -1;
int ydim2_update_halo_kernel1_l1;
int ydim2_update_halo_kernel1_l1_h = -1;
int xdim3_update_halo_kernel1_l1;
int xdim3_update_halo_kernel1_l1_h = -1;
int ydim3_update_halo_kernel1_l1;
int ydim3_update_halo_kernel1_l1_h = -1;
int xdim4_update_halo_kernel1_l1;
int xdim4_update_halo_kernel1_l1_h = -1;
int ydim4_update_halo_kernel1_l1;
int ydim4_update_halo_kernel1_l1_h = -1;
int xdim5_update_halo_kernel1_l1;
int xdim5_update_halo_kernel1_l1_h = -1;
int ydim5_update_halo_kernel1_l1;
int ydim5_update_halo_kernel1_l1_h = -1;
int xdim6_update_halo_kernel1_l1;
int xdim6_update_halo_kernel1_l1_h = -1;
int ydim6_update_halo_kernel1_l1;
int ydim6_update_halo_kernel1_l1_h = -1;

void ops_par_loop_update_halo_kernel1_l1(char const *name, ops_block block,
                                         int dim, int *range, ops_arg arg0,
                                         ops_arg arg1, ops_arg arg2,
                                         ops_arg arg3, ops_arg arg4,
                                         ops_arg arg5, ops_arg arg6,
                                         ops_arg arg7) {

  // Timing
  double t1, t2, c1, c2;
  ops_arg args[8] = {arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 8, range, 62))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(62, "update_halo_kernel1_l1");
    OPS_kernels[62].count++;
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
  if (xdim0 != xdim0_update_halo_kernel1_l1_h ||
      ydim0 != ydim0_update_halo_kernel1_l1_h ||
      xdim1 != xdim1_update_halo_kernel1_l1_h ||
      ydim1 != ydim1_update_halo_kernel1_l1_h ||
      xdim2 != xdim2_update_halo_kernel1_l1_h ||
      ydim2 != ydim2_update_halo_kernel1_l1_h ||
      xdim3 != xdim3_update_halo_kernel1_l1_h ||
      ydim3 != ydim3_update_halo_kernel1_l1_h ||
      xdim4 != xdim4_update_halo_kernel1_l1_h ||
      ydim4 != ydim4_update_halo_kernel1_l1_h ||
      xdim5 != xdim5_update_halo_kernel1_l1_h ||
      ydim5 != ydim5_update_halo_kernel1_l1_h ||
      xdim6 != xdim6_update_halo_kernel1_l1_h ||
      ydim6 != ydim6_update_halo_kernel1_l1_h) {
    xdim0_update_halo_kernel1_l1 = xdim0;
    xdim0_update_halo_kernel1_l1_h = xdim0;
    ydim0_update_halo_kernel1_l1 = ydim0;
    ydim0_update_halo_kernel1_l1_h = ydim0;
    xdim1_update_halo_kernel1_l1 = xdim1;
    xdim1_update_halo_kernel1_l1_h = xdim1;
    ydim1_update_halo_kernel1_l1 = ydim1;
    ydim1_update_halo_kernel1_l1_h = ydim1;
    xdim2_update_halo_kernel1_l1 = xdim2;
    xdim2_update_halo_kernel1_l1_h = xdim2;
    ydim2_update_halo_kernel1_l1 = ydim2;
    ydim2_update_halo_kernel1_l1_h = ydim2;
    xdim3_update_halo_kernel1_l1 = xdim3;
    xdim3_update_halo_kernel1_l1_h = xdim3;
    ydim3_update_halo_kernel1_l1 = ydim3;
    ydim3_update_halo_kernel1_l1_h = ydim3;
    xdim4_update_halo_kernel1_l1 = xdim4;
    xdim4_update_halo_kernel1_l1_h = xdim4;
    ydim4_update_halo_kernel1_l1 = ydim4;
    ydim4_update_halo_kernel1_l1_h = ydim4;
    xdim5_update_halo_kernel1_l1 = xdim5;
    xdim5_update_halo_kernel1_l1_h = xdim5;
    ydim5_update_halo_kernel1_l1 = ydim5;
    ydim5_update_halo_kernel1_l1_h = ydim5;
    xdim6_update_halo_kernel1_l1 = xdim6;
    xdim6_update_halo_kernel1_l1_h = xdim6;
    ydim6_update_halo_kernel1_l1 = ydim6;
    ydim6_update_halo_kernel1_l1_h = ydim6;
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
  int *arg7h = (int *)arg7.data;
// Upload large globals
#ifdef OPS_GPU
  int consts_bytes = 0;
  consts_bytes += ROUND_UP(NUM_FIELDS * sizeof(int));
  int OPS_consts_bytes = 4 * consts_bytes;
  if (OPS_consts_h == NULL) {
    OPS_consts_h = (char *)malloc(OPS_consts_bytes);
    memset(OPS_consts_h, 0, OPS_consts_bytes);
  }
  consts_bytes = 0;
  args[7].data = OPS_consts_h + consts_bytes;
  args[7].data_d = OPS_consts_d + consts_bytes;
  for (int d = 0; d < NUM_FIELDS; d++)
    ((int *)args[7].data)[d] = arg7h[d];
  consts_bytes += ROUND_UP(NUM_FIELDS * sizeof(int));
  mvConstArraysToDevice(OPS_consts_bytes);
#endif // OPS_GPU

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

#ifdef OPS_GPU
  int *p_a7 = (int *)args[7].data;
#else
  int *p_a7 = arg7h;
#endif

#ifdef OPS_GPU
  for (int n = 0; n < 8; n++)
    if (args[n].argtype == OPS_ARG_DAT && args[n].dat->dirty_hd == 1) {
      int size = 1;
      for (int i = 0; i < args[n].dat->block->dims; i++)
        size = size * args[n].dat->size[i];
      args[n].dat->dirty_hd = 0;
    }
// ops_H_D_exchanges_device(args, 8);
#else
  for (int n = 0; n < 8; n++)
    if (args[n].argtype == OPS_ARG_DAT && args[n].dat->dirty_hd == 2) {
      int size = 1;
      for (int i = 0; i < args[n].dat->block->dims; i++)
        size = size * args[n].dat->size[i];
      args[n].dat->dirty_hd = 0;
    }
// ops_H_D_exchanges_host(args, 8);
#endif
  ops_halo_exchanges(args, 8, range);

#ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 8);
#else
  ops_H_D_exchanges_host(args, 8);
#endif
  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[62].mpi_time += t2 - t1;
  }

  update_halo_kernel1_l1_c_wrapper(p_a0, p_a1, p_a2, p_a3, p_a4, p_a5, p_a6,
                                   p_a7, NUM_FIELDS, x_size, y_size, z_size);

  if (OPS_diags > 1) {
    ops_timers_core(&c1, &t1);
    OPS_kernels[62].time += t1 - t2;
  }
#ifdef OPS_GPU
  // for (int n = 0; n < 8; n++) {
  // if ((args[n].argtype == OPS_ARG_DAT) &&
  //(args[n].acc == OPS_INC || args[n].acc == OPS_WRITE ||
  // args[n].acc == OPS_RW)) {
  // args[n].dat->dirty_hd = 2;
  //}
  //}
  ops_set_dirtybit_device(args, 8);
#else
  // for (int n = 0; n < 8; n++) {
  // if ((args[n].argtype == OPS_ARG_DAT) &&
  //(args[n].acc == OPS_INC || args[n].acc == OPS_WRITE ||
  // args[n].acc == OPS_RW)) {
  // args[n].dat->dirty_hd = 1;
  //}
  //}
  ops_set_dirtybit_host(args, 8);
#endif
  ops_set_halo_dirtybit3(&args[0], range);
  ops_set_halo_dirtybit3(&args[1], range);
  ops_set_halo_dirtybit3(&args[2], range);
  ops_set_halo_dirtybit3(&args[3], range);
  ops_set_halo_dirtybit3(&args[4], range);
  ops_set_halo_dirtybit3(&args[5], range);
  ops_set_halo_dirtybit3(&args[6], range);

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c2, &t2);
    OPS_kernels[62].mpi_time += t2 - t1;
    OPS_kernels[62].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[62].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[62].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[62].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[62].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[62].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[62].transfer += ops_compute_transfer(dim, start, end, &arg6);
  }
}
