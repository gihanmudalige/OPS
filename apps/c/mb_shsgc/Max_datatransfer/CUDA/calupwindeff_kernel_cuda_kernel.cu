//
// auto-generated by ops.py
//
__constant__ int dims_calupwindeff_kernel [7][1];
static int dims_calupwindeff_kernel_h [7][1] = {0};

//user function
__device__

void calupwindeff_kernel_gpu(const ACC<double>& cmp,
  const ACC<double> &gt,
  const ACC<double>& cf,
  const ACC<double>& al,
  const ACC<double>& ep2,
  const ACC<double>& r,
  ACC<double>& eff) {
  double e1 = (cmp(0,0) * (gt(0,0) + gt(0,1))
  - cf(0,0) * al(0,0)) * ep2(0,0);
  double e2 = (cmp(1,0) * (gt(1,0) + gt(1,1))
  - cf(1,0) * al(1,0)) * ep2(1,0);
  double e3 = (cmp(2,0) * (gt(2,0) + gt(2,1))
  - cf(2,0) * al(2,0)) * ep2(2,0);

  eff(0,0)=e1 * r(0,0) + e2 * r(1,0) + e3 * r(2,0);
  eff(1,0)=e1 * r(3,0) + e2 * r(4,0) + e3 * r(5,0);
  eff(2,0)=e1 * r(6,0) + e2 * r(7,0) + e3 * r(8,0);
}



__global__ void ops_calupwindeff_kernel(
double* __restrict arg0,
double* __restrict arg1,
double* __restrict arg2,
double* __restrict arg3,
double* __restrict arg4,
double* __restrict arg5,
double* __restrict arg6,
int size0 ){


  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1*3;
  arg1 += idx_x * 1*3;
  arg2 += idx_x * 1*3;
  arg3 += idx_x * 1*3;
  arg4 += idx_x * 1*3;
  arg5 += idx_x * 1*9;
  arg6 += idx_x * 1*3;

  if (idx_x < size0) {
    const ACC<double> argp0(3, dims_calupwindeff_kernel[0][0], arg0);
    const ACC<double> argp1(3, dims_calupwindeff_kernel[1][0], arg1);
    const ACC<double> argp2(3, dims_calupwindeff_kernel[2][0], arg2);
    const ACC<double> argp3(3, dims_calupwindeff_kernel[3][0], arg3);
    const ACC<double> argp4(3, dims_calupwindeff_kernel[4][0], arg4);
    const ACC<double> argp5(9, dims_calupwindeff_kernel[5][0], arg5);
    ACC<double> argp6(3, dims_calupwindeff_kernel[6][0], arg6);
    calupwindeff_kernel_gpu(argp0, argp1, argp2, argp3,
                   argp4, argp5, argp6);
  }

}

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_calupwindeff_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6) {
#else
void ops_par_loop_calupwindeff_kernel_execute(ops_kernel_descriptor *desc) {
  int dim = desc->dim;
  #if OPS_MPI
  ops_block block = desc->block;
  #endif
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  ops_arg arg5 = desc->args[5];
  ops_arg arg6 = desc->args[6];
  #endif

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[7] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6};


  #if CHECKPOINTING && !OPS_LAZY
  if (!ops_checkpointing_before(args,7,range,11)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,11,"calupwindeff_kernel");
    block->instance->OPS_kernels[11].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[1];
  int end[1];
  #if OPS_MPI && !OPS_LAZY
  sub_block_list sb = OPS_sub_block_list[block->index];
  #endif //OPS_MPI

  #ifdef OPS_MPI
  int arg_idx[1];
  #endif
  #ifdef OPS_MPI
  if (compute_ranges(args, 7,block, range, start, end, arg_idx) < 0) return;
  #else //OPS_MPI
  for ( int n=0; n<1; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif
  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];
  int xdim2 = args[2].dat->size[0];
  int xdim3 = args[3].dat->size[0];
  int xdim4 = args[4].dat->size[0];
  int xdim5 = args[5].dat->size[0];
  int xdim6 = args[6].dat->size[0];

  if (xdim0 != dims_calupwindeff_kernel_h[0][0] || xdim1 != dims_calupwindeff_kernel_h[1][0] || xdim2 != dims_calupwindeff_kernel_h[2][0] || xdim3 != dims_calupwindeff_kernel_h[3][0] || xdim4 != dims_calupwindeff_kernel_h[4][0] || xdim5 != dims_calupwindeff_kernel_h[5][0] || xdim6 != dims_calupwindeff_kernel_h[6][0]) {
    dims_calupwindeff_kernel_h[0][0] = xdim0;
    dims_calupwindeff_kernel_h[1][0] = xdim1;
    dims_calupwindeff_kernel_h[2][0] = xdim2;
    dims_calupwindeff_kernel_h[3][0] = xdim3;
    dims_calupwindeff_kernel_h[4][0] = xdim4;
    dims_calupwindeff_kernel_h[5][0] = xdim5;
    dims_calupwindeff_kernel_h[6][0] = xdim6;
    cutilSafeCall(block->instance->ostream(), cudaMemcpyToSymbol( dims_calupwindeff_kernel, dims_calupwindeff_kernel_h, sizeof(dims_calupwindeff_kernel)));
  }



  int x_size = MAX(0,end[0]-start[0]);

  dim3 grid( (x_size-1)/block->instance->OPS_block_size_x+ 1, 1, 1);
  dim3 tblock(block->instance->OPS_block_size_x,1,1);



  int dat0 = (block->instance->OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  int dat1 = (block->instance->OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  int dat2 = (block->instance->OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);
  int dat3 = (block->instance->OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);
  int dat4 = (block->instance->OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size);
  int dat5 = (block->instance->OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size);
  int dat6 = (block->instance->OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size);

  char *p_a[7];

  //set up initial pointers
  int base0 = args[0].dat->base_offset + 
           dat0 * 1 * (start[0] * args[0].stencil->stride[0]);
  p_a[0] = (char *)args[0].data_d + base0;

  int base1 = args[1].dat->base_offset + 
           dat1 * 1 * (start[0] * args[1].stencil->stride[0]);
  p_a[1] = (char *)args[1].data_d + base1;

  int base2 = args[2].dat->base_offset + 
           dat2 * 1 * (start[0] * args[2].stencil->stride[0]);
  p_a[2] = (char *)args[2].data_d + base2;

  int base3 = args[3].dat->base_offset + 
           dat3 * 1 * (start[0] * args[3].stencil->stride[0]);
  p_a[3] = (char *)args[3].data_d + base3;

  int base4 = args[4].dat->base_offset + 
           dat4 * 1 * (start[0] * args[4].stencil->stride[0]);
  p_a[4] = (char *)args[4].data_d + base4;

  int base5 = args[5].dat->base_offset + 
           dat5 * 1 * (start[0] * args[5].stencil->stride[0]);
  p_a[5] = (char *)args[5].data_d + base5;

  int base6 = args[6].dat->base_offset + 
           dat6 * 1 * (start[0] * args[6].stencil->stride[0]);
  p_a[6] = (char *)args[6].data_d + base6;


  #ifndef OPS_LAZY
  ops_H_D_exchanges_device(args, 7);
  ops_halo_exchanges(args,7,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[11].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  if (x_size > 0)
    ops_calupwindeff_kernel<<<grid, tblock >>> (  (double *)p_a[0], (double *)p_a[1],
         (double *)p_a[2], (double *)p_a[3],
         (double *)p_a[4], (double *)p_a[5],
         (double *)p_a[6],x_size);

  cutilSafeCall(block->instance->ostream(), cudaGetLastError());

  if (block->instance->OPS_diags>1) {
    cutilSafeCall(block->instance->ostream(), cudaDeviceSynchronize());
    ops_timers_core(&c1,&t1);
    block->instance->OPS_kernels[11].time += t1-t2;
  }

  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 7);
  ops_set_halo_dirtybit3(&args[6],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    block->instance->OPS_kernels[11].mpi_time += t2-t1;
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg5);
    block->instance->OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg6);
  }
}

#ifdef OPS_LAZY
void ops_par_loop_calupwindeff_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 11;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 11;
  for ( int i=0; i<2; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 7;
  desc->args = (ops_arg*)malloc(7*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->args[4] = arg4;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg4.dat->index;
  desc->args[5] = arg5;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg5.dat->index;
  desc->args[6] = arg6;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg6.dat->index;
  desc->function = ops_par_loop_calupwindeff_kernel_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,11,"calupwindeff_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
