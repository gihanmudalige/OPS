//
// auto-generated by ops.py
//

#define OPS_GPU

extern int xdim0_advec_mom_kernel_z1;
int xdim0_advec_mom_kernel_z1_h = -1;
extern int ydim0_advec_mom_kernel_z1;
int ydim0_advec_mom_kernel_z1_h = -1;
extern int xdim1_advec_mom_kernel_z1;
int xdim1_advec_mom_kernel_z1_h = -1;
extern int ydim1_advec_mom_kernel_z1;
int ydim1_advec_mom_kernel_z1_h = -1;
extern int xdim2_advec_mom_kernel_z1;
int xdim2_advec_mom_kernel_z1_h = -1;
extern int ydim2_advec_mom_kernel_z1;
int ydim2_advec_mom_kernel_z1_h = -1;
extern int xdim3_advec_mom_kernel_z1;
int xdim3_advec_mom_kernel_z1_h = -1;
extern int ydim3_advec_mom_kernel_z1;
int ydim3_advec_mom_kernel_z1_h = -1;
extern int xdim4_advec_mom_kernel_z1;
int xdim4_advec_mom_kernel_z1_h = -1;
extern int ydim4_advec_mom_kernel_z1;
int ydim4_advec_mom_kernel_z1_h = -1;
extern int xdim5_advec_mom_kernel_z1;
int xdim5_advec_mom_kernel_z1_h = -1;
extern int ydim5_advec_mom_kernel_z1;
int ydim5_advec_mom_kernel_z1_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void advec_mom_kernel_z1_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  int x_size, int y_size, int z_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_advec_mom_kernel_z1(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5) {

  //Timing
  double t1,t2,c1,c2;
  ops_arg args[6] = { arg0, arg1, arg2, arg3, arg4, arg5};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,6,range,122)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,122,"advec_mom_kernel_z1");
    block->instance->OPS_kernels[122].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block

  int start[3];
  int end[3];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  int arg_idx[3];
  int arg_idx_base[3];
  #ifdef OPS_MPI
  if (compute_ranges(args, 6,block, range, start, end, arg_idx) < 0) return;
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


  //set up initial pointers
  int base0 = args[0].dat->base_offset + (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start[0] * args[0].stencil->stride[0];
  base0 = base0 + (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    start[1] * args[0].stencil->stride[1];
  base0 = base0 + (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    start[2] * args[0].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a0 = (double *)((char *)args[0].data_d + base0);
  #else
  double *p_a0 = (double *)((char *)args[0].data + base0);
  #endif

  int base1 = args[1].dat->base_offset + (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  base1 = base1 + (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    start[1] * args[1].stencil->stride[1];
  base1 = base1 + (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    start[2] * args[1].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a1 = (double *)((char *)args[1].data_d + base1);
  #else
  double *p_a1 = (double *)((char *)args[1].data + base1);
  #endif

  int base2 = args[2].dat->base_offset + (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) * start[0] * args[2].stencil->stride[0];
  base2 = base2 + (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    start[1] * args[2].stencil->stride[1];
  base2 = base2 + (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    start[2] * args[2].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a2 = (double *)((char *)args[2].data_d + base2);
  #else
  double *p_a2 = (double *)((char *)args[2].data + base2);
  #endif

  int base3 = args[3].dat->base_offset + (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) * start[0] * args[3].stencil->stride[0];
  base3 = base3 + (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    start[1] * args[3].stencil->stride[1];
  base3 = base3 + (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    args[3].dat->size[1] *
    start[2] * args[3].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a3 = (double *)((char *)args[3].data_d + base3);
  #else
  double *p_a3 = (double *)((char *)args[3].data + base3);
  #endif

  int base4 = args[4].dat->base_offset + (block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) * start[0] * args[4].stencil->stride[0];
  base4 = base4 + (block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    start[1] * args[4].stencil->stride[1];
  base4 = base4 + (block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    args[4].dat->size[1] *
    start[2] * args[4].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a4 = (double *)((char *)args[4].data_d + base4);
  #else
  double *p_a4 = (double *)((char *)args[4].data + base4);
  #endif

  int base5 = args[5].dat->base_offset + (block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) * start[0] * args[5].stencil->stride[0];
  base5 = base5 + (block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) *
    args[5].dat->size[0] *
    start[1] * args[5].stencil->stride[1];
  base5 = base5 + (block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) *
    args[5].dat->size[0] *
    args[5].dat->size[1] *
    start[2] * args[5].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a5 = (double *)((char *)args[5].data_d + base5);
  #else
  double *p_a5 = (double *)((char *)args[5].data + base5);
  #endif


  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

  //initialize global variable with the dimension of dats
  int xdim0 = args[0].dat->size[0];
  int ydim0 = args[0].dat->size[1];
  int xdim1 = args[1].dat->size[0];
  int ydim1 = args[1].dat->size[1];
  int xdim2 = args[2].dat->size[0];
  int ydim2 = args[2].dat->size[1];
  int xdim3 = args[3].dat->size[0];
  int ydim3 = args[3].dat->size[1];
  int xdim4 = args[4].dat->size[0];
  int ydim4 = args[4].dat->size[1];
  int xdim5 = args[5].dat->size[0];
  int ydim5 = args[5].dat->size[1];
  if (xdim0 != xdim0_advec_mom_kernel_z1_h || ydim0 != ydim0_advec_mom_kernel_z1_h || xdim1 != xdim1_advec_mom_kernel_z1_h || ydim1 != ydim1_advec_mom_kernel_z1_h || xdim2 != xdim2_advec_mom_kernel_z1_h || ydim2 != ydim2_advec_mom_kernel_z1_h || xdim3 != xdim3_advec_mom_kernel_z1_h || ydim3 != ydim3_advec_mom_kernel_z1_h || xdim4 != xdim4_advec_mom_kernel_z1_h || ydim4 != ydim4_advec_mom_kernel_z1_h || xdim5 != xdim5_advec_mom_kernel_z1_h || ydim5 != ydim5_advec_mom_kernel_z1_h) {
    xdim0_advec_mom_kernel_z1 = xdim0;
    xdim0_advec_mom_kernel_z1_h = xdim0;
    ydim0_advec_mom_kernel_z1 = ydim0;
    ydim0_advec_mom_kernel_z1_h = ydim0;
    xdim1_advec_mom_kernel_z1 = xdim1;
    xdim1_advec_mom_kernel_z1_h = xdim1;
    ydim1_advec_mom_kernel_z1 = ydim1;
    ydim1_advec_mom_kernel_z1_h = ydim1;
    xdim2_advec_mom_kernel_z1 = xdim2;
    xdim2_advec_mom_kernel_z1_h = xdim2;
    ydim2_advec_mom_kernel_z1 = ydim2;
    ydim2_advec_mom_kernel_z1_h = ydim2;
    xdim3_advec_mom_kernel_z1 = xdim3;
    xdim3_advec_mom_kernel_z1_h = xdim3;
    ydim3_advec_mom_kernel_z1 = ydim3;
    ydim3_advec_mom_kernel_z1_h = ydim3;
    xdim4_advec_mom_kernel_z1 = xdim4;
    xdim4_advec_mom_kernel_z1_h = xdim4;
    ydim4_advec_mom_kernel_z1 = ydim4;
    ydim4_advec_mom_kernel_z1_h = ydim4;
    xdim5_advec_mom_kernel_z1 = xdim5;
    xdim5_advec_mom_kernel_z1_h = xdim5;
    ydim5_advec_mom_kernel_z1 = ydim5;
    ydim5_advec_mom_kernel_z1_h = ydim5;
  }

  //Halo Exchanges

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 6);
  #else
  ops_H_D_exchanges_host(args, 6);
  #endif
  ops_halo_exchanges(args,6,range);

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 6);
  #else
  ops_H_D_exchanges_host(args, 6);
  #endif
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[122].mpi_time += t2-t1;
  }

  advec_mom_kernel_z1_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    p_a4,
    p_a5,
    x_size, y_size, z_size);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[122].time += t1-t2;
  }
  #ifdef OPS_GPU
  ops_set_dirtybit_device(args, 6);
  #else
  ops_set_dirtybit_host(args, 6);
  #endif
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[122].mpi_time += t2-t1;
    block->instance->OPS_kernels[122].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[122].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[122].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[122].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[122].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[122].transfer += ops_compute_transfer(dim, start, end, &arg5);
  }
}
