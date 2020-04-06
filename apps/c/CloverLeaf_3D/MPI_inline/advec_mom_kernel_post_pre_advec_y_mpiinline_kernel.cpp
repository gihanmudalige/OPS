//
// auto-generated by ops.py
//

extern int xdim0_advec_mom_kernel_post_pre_advec_y;
int xdim0_advec_mom_kernel_post_pre_advec_y_h = -1;
extern int ydim0_advec_mom_kernel_post_pre_advec_y;
int ydim0_advec_mom_kernel_post_pre_advec_y_h = -1;
extern int xdim1_advec_mom_kernel_post_pre_advec_y;
int xdim1_advec_mom_kernel_post_pre_advec_y_h = -1;
extern int ydim1_advec_mom_kernel_post_pre_advec_y;
int ydim1_advec_mom_kernel_post_pre_advec_y_h = -1;
extern int xdim2_advec_mom_kernel_post_pre_advec_y;
int xdim2_advec_mom_kernel_post_pre_advec_y_h = -1;
extern int ydim2_advec_mom_kernel_post_pre_advec_y;
int ydim2_advec_mom_kernel_post_pre_advec_y_h = -1;
extern int xdim3_advec_mom_kernel_post_pre_advec_y;
int xdim3_advec_mom_kernel_post_pre_advec_y_h = -1;
extern int ydim3_advec_mom_kernel_post_pre_advec_y;
int ydim3_advec_mom_kernel_post_pre_advec_y_h = -1;
extern int xdim4_advec_mom_kernel_post_pre_advec_y;
int xdim4_advec_mom_kernel_post_pre_advec_y_h = -1;
extern int ydim4_advec_mom_kernel_post_pre_advec_y;
int ydim4_advec_mom_kernel_post_pre_advec_y_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void advec_mom_kernel_post_pre_advec_y_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  int x_size, int y_size, int z_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_advec_mom_kernel_post_pre_advec_y(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4) {

  ops_arg args[5] = { arg0, arg1, arg2, arg3, arg4};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,5,range,132)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,132,"advec_mom_kernel_post_pre_advec_y");
    block->instance->OPS_kernels[132].count++;
  }

  //compute localy allocated range for the sub-block
  int start[3];
  int end[3];
  int arg_idx[3];

  #ifdef OPS_MPI
  if (compute_ranges(args, 5,block, range, start, end, arg_idx) < 0) return;
  #else
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);

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

  //Timing
  double t1,t2,c1,c2;
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
  }

  if (xdim0 != xdim0_advec_mom_kernel_post_pre_advec_y_h || ydim0 != ydim0_advec_mom_kernel_post_pre_advec_y_h || xdim1 != xdim1_advec_mom_kernel_post_pre_advec_y_h || ydim1 != ydim1_advec_mom_kernel_post_pre_advec_y_h || xdim2 != xdim2_advec_mom_kernel_post_pre_advec_y_h || ydim2 != ydim2_advec_mom_kernel_post_pre_advec_y_h || xdim3 != xdim3_advec_mom_kernel_post_pre_advec_y_h || ydim3 != ydim3_advec_mom_kernel_post_pre_advec_y_h || xdim4 != xdim4_advec_mom_kernel_post_pre_advec_y_h || ydim4 != ydim4_advec_mom_kernel_post_pre_advec_y_h) {
    xdim0_advec_mom_kernel_post_pre_advec_y = xdim0;
    xdim0_advec_mom_kernel_post_pre_advec_y_h = xdim0;
    ydim0_advec_mom_kernel_post_pre_advec_y = ydim0;
    ydim0_advec_mom_kernel_post_pre_advec_y_h = ydim0;
    xdim1_advec_mom_kernel_post_pre_advec_y = xdim1;
    xdim1_advec_mom_kernel_post_pre_advec_y_h = xdim1;
    ydim1_advec_mom_kernel_post_pre_advec_y = ydim1;
    ydim1_advec_mom_kernel_post_pre_advec_y_h = ydim1;
    xdim2_advec_mom_kernel_post_pre_advec_y = xdim2;
    xdim2_advec_mom_kernel_post_pre_advec_y_h = xdim2;
    ydim2_advec_mom_kernel_post_pre_advec_y = ydim2;
    ydim2_advec_mom_kernel_post_pre_advec_y_h = ydim2;
    xdim3_advec_mom_kernel_post_pre_advec_y = xdim3;
    xdim3_advec_mom_kernel_post_pre_advec_y_h = xdim3;
    ydim3_advec_mom_kernel_post_pre_advec_y = ydim3;
    ydim3_advec_mom_kernel_post_pre_advec_y_h = ydim3;
    xdim4_advec_mom_kernel_post_pre_advec_y = xdim4;
    xdim4_advec_mom_kernel_post_pre_advec_y_h = xdim4;
    ydim4_advec_mom_kernel_post_pre_advec_y = ydim4;
    ydim4_advec_mom_kernel_post_pre_advec_y_h = ydim4;
  }



  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset + (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start[0] * args[0].stencil->stride[0];
  base0 = base0+ (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    start[1] * args[0].stencil->stride[1];
  base0 = base0+ (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    start[2] * args[0].stencil->stride[2];
  double *p_a0 = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset + (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  base1 = base1+ (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    start[1] * args[1].stencil->stride[1];
  base1 = base1+ (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    start[2] * args[1].stencil->stride[2];
  double *p_a1 = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset + (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) * start[0] * args[2].stencil->stride[0];
  base2 = base2+ (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    start[1] * args[2].stencil->stride[1];
  base2 = base2+ (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    start[2] * args[2].stencil->stride[2];
  double *p_a2 = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset + (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) * start[0] * args[3].stencil->stride[0];
  base3 = base3+ (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    start[1] * args[3].stencil->stride[1];
  base3 = base3+ (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    args[3].dat->size[1] *
    start[2] * args[3].stencil->stride[2];
  double *p_a3 = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset + (block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) * start[0] * args[4].stencil->stride[0];
  base4 = base4+ (block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    start[1] * args[4].stencil->stride[1];
  base4 = base4+ (block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    args[4].dat->size[1] *
    start[2] * args[4].stencil->stride[2];
  double *p_a4 = (double *)(args[4].data + base4);



  ops_H_D_exchanges_host(args, 5);
  ops_halo_exchanges(args,5,range);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[132].mpi_time += t1-t2;
  }

  advec_mom_kernel_post_pre_advec_y_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    p_a4,
    x_size, y_size, z_size);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[132].time += t2-t1;
  }
  ops_set_dirtybit_host(args, 5);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[3],range);

  //Update kernel record
  if (block->instance->OPS_diags > 1) {
    block->instance->OPS_kernels[132].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[132].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[132].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[132].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[132].transfer += ops_compute_transfer(dim, start, end, &arg4);
  }
}
