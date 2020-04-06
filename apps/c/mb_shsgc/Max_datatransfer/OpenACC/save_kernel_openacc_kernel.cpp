//
// auto-generated by ops.py
//

#define OPS_GPU

extern int xdim0_save_kernel;
int xdim0_save_kernel_h = -1;
extern int xdim1_save_kernel;
int xdim1_save_kernel_h = -1;
extern int xdim2_save_kernel;
int xdim2_save_kernel_h = -1;
extern int xdim3_save_kernel;
int xdim3_save_kernel_h = -1;
extern int xdim4_save_kernel;
int xdim4_save_kernel_h = -1;
extern int xdim5_save_kernel;
int xdim5_save_kernel_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void save_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  int x_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_save_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5) {

  //Timing
  double t1,t2,c1,c2;
  ops_arg args[6] = { arg0, arg1, arg2, arg3, arg4, arg5};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,6,range,2)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,2,"save_kernel");
    block->instance->OPS_kernels[2].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block

  int start[1];
  int end[1];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  int arg_idx[1];
  int arg_idx_base[1];
  #ifdef OPS_MPI
  if (compute_ranges(args, 6,block, range, start, end, arg_idx) < 0) return;
  #else //OPS_MPI
  for ( int n=0; n<1; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
    arg_idx[n] = start[n];
  }
  #endif
  for ( int n=0; n<1; n++ ){
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
  #ifdef OPS_GPU
  double *p_a0 = (double *)((char *)args[0].data_d + base0);
  #else
  double *p_a0 = (double *)((char *)args[0].data + base0);
  #endif

  int base1 = args[1].dat->base_offset + (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  #ifdef OPS_GPU
  double *p_a1 = (double *)((char *)args[1].data_d + base1);
  #else
  double *p_a1 = (double *)((char *)args[1].data + base1);
  #endif

  int base2 = args[2].dat->base_offset + (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) * start[0] * args[2].stencil->stride[0];
  #ifdef OPS_GPU
  double *p_a2 = (double *)((char *)args[2].data_d + base2);
  #else
  double *p_a2 = (double *)((char *)args[2].data + base2);
  #endif

  int base3 = args[3].dat->base_offset + (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) * start[0] * args[3].stencil->stride[0];
  #ifdef OPS_GPU
  double *p_a3 = (double *)((char *)args[3].data_d + base3);
  #else
  double *p_a3 = (double *)((char *)args[3].data + base3);
  #endif

  int base4 = args[4].dat->base_offset + (block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) * start[0] * args[4].stencil->stride[0];
  #ifdef OPS_GPU
  double *p_a4 = (double *)((char *)args[4].data_d + base4);
  #else
  double *p_a4 = (double *)((char *)args[4].data + base4);
  #endif

  int base5 = args[5].dat->base_offset + (block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) * start[0] * args[5].stencil->stride[0];
  #ifdef OPS_GPU
  double *p_a5 = (double *)((char *)args[5].data_d + base5);
  #else
  double *p_a5 = (double *)((char *)args[5].data + base5);
  #endif


  int x_size = MAX(0,end[0]-start[0]);

  //initialize global variable with the dimension of dats
  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];
  int xdim2 = args[2].dat->size[0];
  int xdim3 = args[3].dat->size[0];
  int xdim4 = args[4].dat->size[0];
  int xdim5 = args[5].dat->size[0];
  if (xdim0 != xdim0_save_kernel_h || xdim1 != xdim1_save_kernel_h || xdim2 != xdim2_save_kernel_h || xdim3 != xdim3_save_kernel_h || xdim4 != xdim4_save_kernel_h || xdim5 != xdim5_save_kernel_h) {
    xdim0_save_kernel = xdim0;
    xdim0_save_kernel_h = xdim0;
    xdim1_save_kernel = xdim1;
    xdim1_save_kernel_h = xdim1;
    xdim2_save_kernel = xdim2;
    xdim2_save_kernel_h = xdim2;
    xdim3_save_kernel = xdim3;
    xdim3_save_kernel_h = xdim3;
    xdim4_save_kernel = xdim4;
    xdim4_save_kernel_h = xdim4;
    xdim5_save_kernel = xdim5;
    xdim5_save_kernel_h = xdim5;
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
    block->instance->OPS_kernels[2].mpi_time += t2-t1;
  }

  save_kernel_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    p_a4,
    p_a5,
    x_size);

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[2].time += t1-t2;
  }
  #ifdef OPS_GPU
  ops_set_dirtybit_device(args, 6);
  #else
  ops_set_dirtybit_host(args, 6);
  #endif
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);
  ops_set_halo_dirtybit3(&args[2],range);

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[2].mpi_time += t2-t1;
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[2].transfer += ops_compute_transfer(dim, start, end, &arg5);
  }
}
