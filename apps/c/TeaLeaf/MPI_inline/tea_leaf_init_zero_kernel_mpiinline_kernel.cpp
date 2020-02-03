//
// auto-generated by ops.py
//

extern int xdim0_tea_leaf_init_zero_kernel;
int xdim0_tea_leaf_init_zero_kernel_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void tea_leaf_init_zero_kernel_c_wrapper(
  double *p_a0,
  int x_size, int y_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_tea_leaf_init_zero_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0) {

  ops_arg args[1] = { arg0};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,1,range,45)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,45,"tea_leaf_init_zero_kernel");
    block->instance->OPS_kernels[45].count++;
  }

  //compute localy allocated range for the sub-block
  int start[2];
  int end[2];
  int arg_idx[2];

  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (compute_ranges(args, 1,block, range, start, end, arg_idx) < 0) return;
  #else
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  int xdim0 = args[0].dat->size[0];

  //Timing
  double t1,t2,c1,c2;
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
  }

  if (xdim0 != xdim0_tea_leaf_init_zero_kernel_h) {
    xdim0_tea_leaf_init_zero_kernel = xdim0;
    xdim0_tea_leaf_init_zero_kernel_h = xdim0;
  }


  int dat0 = (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset + (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start[0] * args[0].stencil->stride[0];
  base0 = base0+ (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    start[1] * args[0].stencil->stride[1];
  double *p_a0 = (double *)(args[0].data + base0);



  ops_H_D_exchanges_host(args, 1);
  ops_halo_exchanges(args,1,range);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[45].mpi_time += t1-t2;
  }

  tea_leaf_init_zero_kernel_c_wrapper(
    p_a0,
    x_size, y_size);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[45].time += t2-t1;
  }
  ops_set_dirtybit_host(args, 1);
  ops_set_halo_dirtybit3(&args[0],range);

  //Update kernel record
  if (block->instance->OPS_diags > 1) {
    block->instance->OPS_kernels[45].transfer += ops_compute_transfer(dim, start, end, &arg0);
  }
}
