//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_tea_leaf_ppcg_inner1_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {
#else
void ops_par_loop_tea_leaf_ppcg_inner1_kernel_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  ops_arg arg5 = desc->args[5];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[6] = { arg0, arg1, arg2, arg3, arg4, arg5};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,6,range,46)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,46,"tea_leaf_ppcg_inner1_kernel");
    block->instance->OPS_kernels[46].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "tea_leaf_ppcg_inner1_kernel");
  #endif


  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];
  #if defined(OPS_MPI) && !defined(OPS_LAZY)
  int arg_idx[2];
  #endif
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 6,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_tea_leaf_ppcg_inner1_kernel = args[0].dat->size[0];
  int xdim1_tea_leaf_ppcg_inner1_kernel = args[1].dat->size[0];
  int xdim2_tea_leaf_ppcg_inner1_kernel = args[2].dat->size[0];
  int xdim3_tea_leaf_ppcg_inner1_kernel = args[3].dat->size[0];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ rtemp_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ Kx_p = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double * __restrict__ Ky_p = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double * __restrict__ sd_p = (double *)(args[3].data + base3);

  double * __restrict__ rx = (double *)args[4].data;


  double * __restrict__ ry = (double *)args[5].data;




  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 6);
  ops_halo_exchanges(args,6,range);
  ops_H_D_exchanges_host(args, 6);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[46].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for
  for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
    #ifdef __INTEL_COMPILER
    #pragma loop_count(10000)
    #pragma omp simd
    #elif defined(__clang__)
    #pragma clang loop vectorize(assume_safety)
    #elif defined(__GNUC__)
    #pragma GCC ivdep
    #else
    #pragma simd
    #endif
    for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
      ACC<double> rtemp(xdim0_tea_leaf_ppcg_inner1_kernel, rtemp_p + n_x*1 + n_y * xdim0_tea_leaf_ppcg_inner1_kernel*1);
      const ACC<double> Kx(xdim1_tea_leaf_ppcg_inner1_kernel, Kx_p + n_x*1 + n_y * xdim1_tea_leaf_ppcg_inner1_kernel*1);
      const ACC<double> Ky(xdim2_tea_leaf_ppcg_inner1_kernel, Ky_p + n_x*1 + n_y * xdim2_tea_leaf_ppcg_inner1_kernel*1);
      const ACC<double> sd(xdim3_tea_leaf_ppcg_inner1_kernel, sd_p + n_x*1 + n_y * xdim3_tea_leaf_ppcg_inner1_kernel*1);
      
	double smvp = 0.0;
  smvp = (1.0
    + (*ry)*(Ky(0, 1) + Ky(0,0))
    + (*rx)*(Kx(1, 0) + Kx(0,0)))*sd(0,0)
    - (*ry)*(Ky(0, 1) *sd(0, 1) + Ky(0,0)*sd(0, -1))
    - (*rx)*(Kx(1, 0) *sd(1, 0) + Kx(0,0)*sd(-1, 0));
  rtemp(0,0) = rtemp(0,0) - smvp;

    }
  }
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[46].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 6);
  ops_set_halo_dirtybit3(&args[0],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[46].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[46].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[46].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[46].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[46].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_tea_leaf_ppcg_inner1_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 0;
  desc->index = 46;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 46;
  for ( int i=0; i<4; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 6;
  desc->args = (ops_arg*)malloc(6*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->args[4] = arg4;
  char *tmp = (char*)malloc(1*sizeof(double));
  memcpy(tmp, arg4.data,1*sizeof(double));
  desc->args[4].data = tmp;
  desc->args[5] = arg5;
  tmp = (char*)malloc(1*sizeof(double));
  memcpy(tmp, arg5.data,1*sizeof(double));
  desc->args[5].data = tmp;
  desc->function = ops_par_loop_tea_leaf_ppcg_inner1_kernel_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,46,"tea_leaf_ppcg_inner1_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
