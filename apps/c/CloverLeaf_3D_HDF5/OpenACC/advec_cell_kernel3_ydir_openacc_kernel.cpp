//
// auto-generated by ops.py
//

#define OPS_GPU

extern int xdim0_advec_cell_kernel3_ydir;
int xdim0_advec_cell_kernel3_ydir_h = -1;
extern int ydim0_advec_cell_kernel3_ydir;
int ydim0_advec_cell_kernel3_ydir_h = -1;
extern int xdim1_advec_cell_kernel3_ydir;
int xdim1_advec_cell_kernel3_ydir_h = -1;
extern int ydim1_advec_cell_kernel3_ydir;
int ydim1_advec_cell_kernel3_ydir_h = -1;
extern int xdim2_advec_cell_kernel3_ydir;
int xdim2_advec_cell_kernel3_ydir_h = -1;
extern int ydim2_advec_cell_kernel3_ydir;
int ydim2_advec_cell_kernel3_ydir_h = -1;
extern int xdim3_advec_cell_kernel3_ydir;
int xdim3_advec_cell_kernel3_ydir_h = -1;
extern int ydim3_advec_cell_kernel3_ydir;
int ydim3_advec_cell_kernel3_ydir_h = -1;
extern int xdim4_advec_cell_kernel3_ydir;
int xdim4_advec_cell_kernel3_ydir_h = -1;
extern int ydim4_advec_cell_kernel3_ydir;
int ydim4_advec_cell_kernel3_ydir_h = -1;
extern int xdim5_advec_cell_kernel3_ydir;
int xdim5_advec_cell_kernel3_ydir_h = -1;
extern int ydim5_advec_cell_kernel3_ydir;
int ydim5_advec_cell_kernel3_ydir_h = -1;
extern int xdim6_advec_cell_kernel3_ydir;
int xdim6_advec_cell_kernel3_ydir_h = -1;
extern int ydim6_advec_cell_kernel3_ydir;
int ydim6_advec_cell_kernel3_ydir_h = -1;
extern int xdim7_advec_cell_kernel3_ydir;
int xdim7_advec_cell_kernel3_ydir_h = -1;
extern int ydim7_advec_cell_kernel3_ydir;
int ydim7_advec_cell_kernel3_ydir_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void advec_cell_kernel3_ydir_c_wrapper(
  double *p_a0,
  double *p_a1,
  int *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  double *p_a7,
  int x_size, int y_size, int z_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_advec_cell_kernel3_ydir(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {

  //Timing
  double t1,t2,c1,c2;
  ops_arg args[8] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,8,range,114)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(114,"advec_cell_kernel3_ydir");
    OPS_kernels[114].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute localy allocated range for the sub-block

  int start[3];
  int end[3];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  int arg_idx[3];
  int arg_idx_base[3];
  #ifdef OPS_MPI
  if (compute_ranges(args, 8,block, range, start, end, arg_idx) < 0) return;
  #else //OPS_MPI
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif
  for ( int n=0; n<3; n++ ){
    arg_idx_base[n] = arg_idx[n];
  }

  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;
  int dat3 = args[3].dat->elem_size;
  int dat4 = args[4].dat->elem_size;
  int dat5 = args[5].dat->elem_size;
  int dat6 = args[6].dat->elem_size;
  int dat7 = args[7].dat->elem_size;


  //set up initial pointers
  int base0 = args[0].dat->base_offset + (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start[0] * args[0].stencil->stride[0];
  base0 = base0 + (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    start[1] * args[0].stencil->stride[1];
  base0 = base0 + (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    start[2] * args[0].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a0 = (double *)((char *)args[0].data_d + base0);
  #else
  double *p_a0 = (double *)((char *)args[0].data + base0);
  #endif

  int base1 = args[1].dat->base_offset + (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  base1 = base1 + (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    start[1] * args[1].stencil->stride[1];
  base1 = base1 + (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    start[2] * args[1].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a1 = (double *)((char *)args[1].data_d + base1);
  #else
  double *p_a1 = (double *)((char *)args[1].data + base1);
  #endif

  int base2 = args[2].dat->base_offset + (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) * start[0] * args[2].stencil->stride[0];
  base2 = base2 + (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    start[1] * args[2].stencil->stride[1];
  base2 = base2 + (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    start[2] * args[2].stencil->stride[2];
  #ifdef OPS_GPU
  int *p_a2 = (int *)((char *)args[2].data_d + base2);
  #else
  int *p_a2 = (int *)((char *)args[2].data + base2);
  #endif

  int base3 = args[3].dat->base_offset + (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) * start[0] * args[3].stencil->stride[0];
  base3 = base3 + (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    start[1] * args[3].stencil->stride[1];
  base3 = base3 + (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    args[3].dat->size[1] *
    start[2] * args[3].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a3 = (double *)((char *)args[3].data_d + base3);
  #else
  double *p_a3 = (double *)((char *)args[3].data + base3);
  #endif

  int base4 = args[4].dat->base_offset + (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) * start[0] * args[4].stencil->stride[0];
  base4 = base4 + (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    start[1] * args[4].stencil->stride[1];
  base4 = base4 + (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    args[4].dat->size[1] *
    start[2] * args[4].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a4 = (double *)((char *)args[4].data_d + base4);
  #else
  double *p_a4 = (double *)((char *)args[4].data + base4);
  #endif

  int base5 = args[5].dat->base_offset + (OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) * start[0] * args[5].stencil->stride[0];
  base5 = base5 + (OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) *
    args[5].dat->size[0] *
    start[1] * args[5].stencil->stride[1];
  base5 = base5 + (OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) *
    args[5].dat->size[0] *
    args[5].dat->size[1] *
    start[2] * args[5].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a5 = (double *)((char *)args[5].data_d + base5);
  #else
  double *p_a5 = (double *)((char *)args[5].data + base5);
  #endif

  int base6 = args[6].dat->base_offset + (OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size) * start[0] * args[6].stencil->stride[0];
  base6 = base6 + (OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size) *
    args[6].dat->size[0] *
    start[1] * args[6].stencil->stride[1];
  base6 = base6 + (OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size) *
    args[6].dat->size[0] *
    args[6].dat->size[1] *
    start[2] * args[6].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a6 = (double *)((char *)args[6].data_d + base6);
  #else
  double *p_a6 = (double *)((char *)args[6].data + base6);
  #endif

  int base7 = args[7].dat->base_offset + (OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size) * start[0] * args[7].stencil->stride[0];
  base7 = base7 + (OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size) *
    args[7].dat->size[0] *
    start[1] * args[7].stencil->stride[1];
  base7 = base7 + (OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size) *
    args[7].dat->size[0] *
    args[7].dat->size[1] *
    start[2] * args[7].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a7 = (double *)((char *)args[7].data_d + base7);
  #else
  double *p_a7 = (double *)((char *)args[7].data + base7);
  #endif


  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  //initialize global variable with the dimension of dats
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
  if (xdim0 != xdim0_advec_cell_kernel3_ydir_h || ydim0 != ydim0_advec_cell_kernel3_ydir_h || xdim1 != xdim1_advec_cell_kernel3_ydir_h || ydim1 != ydim1_advec_cell_kernel3_ydir_h || xdim2 != xdim2_advec_cell_kernel3_ydir_h || ydim2 != ydim2_advec_cell_kernel3_ydir_h || xdim3 != xdim3_advec_cell_kernel3_ydir_h || ydim3 != ydim3_advec_cell_kernel3_ydir_h || xdim4 != xdim4_advec_cell_kernel3_ydir_h || ydim4 != ydim4_advec_cell_kernel3_ydir_h || xdim5 != xdim5_advec_cell_kernel3_ydir_h || ydim5 != ydim5_advec_cell_kernel3_ydir_h || xdim6 != xdim6_advec_cell_kernel3_ydir_h || ydim6 != ydim6_advec_cell_kernel3_ydir_h || xdim7 != xdim7_advec_cell_kernel3_ydir_h || ydim7 != ydim7_advec_cell_kernel3_ydir_h) {
    xdim0_advec_cell_kernel3_ydir = xdim0;
    xdim0_advec_cell_kernel3_ydir_h = xdim0;
    ydim0_advec_cell_kernel3_ydir = ydim0;
    ydim0_advec_cell_kernel3_ydir_h = ydim0;
    xdim1_advec_cell_kernel3_ydir = xdim1;
    xdim1_advec_cell_kernel3_ydir_h = xdim1;
    ydim1_advec_cell_kernel3_ydir = ydim1;
    ydim1_advec_cell_kernel3_ydir_h = ydim1;
    xdim2_advec_cell_kernel3_ydir = xdim2;
    xdim2_advec_cell_kernel3_ydir_h = xdim2;
    ydim2_advec_cell_kernel3_ydir = ydim2;
    ydim2_advec_cell_kernel3_ydir_h = ydim2;
    xdim3_advec_cell_kernel3_ydir = xdim3;
    xdim3_advec_cell_kernel3_ydir_h = xdim3;
    ydim3_advec_cell_kernel3_ydir = ydim3;
    ydim3_advec_cell_kernel3_ydir_h = ydim3;
    xdim4_advec_cell_kernel3_ydir = xdim4;
    xdim4_advec_cell_kernel3_ydir_h = xdim4;
    ydim4_advec_cell_kernel3_ydir = ydim4;
    ydim4_advec_cell_kernel3_ydir_h = ydim4;
    xdim5_advec_cell_kernel3_ydir = xdim5;
    xdim5_advec_cell_kernel3_ydir_h = xdim5;
    ydim5_advec_cell_kernel3_ydir = ydim5;
    ydim5_advec_cell_kernel3_ydir_h = ydim5;
    xdim6_advec_cell_kernel3_ydir = xdim6;
    xdim6_advec_cell_kernel3_ydir_h = xdim6;
    ydim6_advec_cell_kernel3_ydir = ydim6;
    ydim6_advec_cell_kernel3_ydir_h = ydim6;
    xdim7_advec_cell_kernel3_ydir = xdim7;
    xdim7_advec_cell_kernel3_ydir_h = xdim7;
    ydim7_advec_cell_kernel3_ydir = ydim7;
    ydim7_advec_cell_kernel3_ydir_h = ydim7;
  }

  //Halo Exchanges

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 8);
  #else
  ops_H_D_exchanges_host(args, 8);
  #endif
  ops_halo_exchanges(args,8,range);

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 8);
  #else
  ops_H_D_exchanges_host(args, 8);
  #endif
  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[114].mpi_time += t2-t1;
  }

  advec_cell_kernel3_ydir_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    p_a4,
    p_a5,
    p_a6,
    p_a7,
    x_size, y_size, z_size);

  if (OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    OPS_kernels[114].time += t1-t2;
  }
  #ifdef OPS_GPU
  ops_set_dirtybit_device(args, 8);
  #else
  ops_set_dirtybit_host(args, 8);
  #endif
  ops_set_halo_dirtybit3(&args[6],range);
  ops_set_halo_dirtybit3(&args[7],range);

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_kernels[114].mpi_time += t2-t1;
    OPS_kernels[114].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[114].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[114].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[114].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[114].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[114].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[114].transfer += ops_compute_transfer(dim, start, end, &arg6);
    OPS_kernels[114].transfer += ops_compute_transfer(dim, start, end, &arg7);
  }
}
