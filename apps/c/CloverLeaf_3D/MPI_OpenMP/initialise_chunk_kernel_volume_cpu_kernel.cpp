//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_initialise_chunk_kernel_volume(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6) {
#else
void ops_par_loop_initialise_chunk_kernel_volume_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
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
  double __t1,__t2,__c1,__c2;

  ops_arg args[7] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,7,range,9)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,9,"initialise_chunk_kernel_volume");
    block->instance->OPS_kernels[9].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "initialise_chunk_kernel_volume");
  #endif


  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #if defined(OPS_MPI) && !defined(OPS_LAZY)
  int arg_idx[3];
  #endif
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 7,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_initialise_chunk_kernel_volume = args[0].dat->size[0];
  int ydim0_initialise_chunk_kernel_volume = args[0].dat->size[1];
  int xdim1_initialise_chunk_kernel_volume = args[1].dat->size[0];
  int ydim1_initialise_chunk_kernel_volume = args[1].dat->size[1];
  int xdim2_initialise_chunk_kernel_volume = args[2].dat->size[0];
  int ydim2_initialise_chunk_kernel_volume = args[2].dat->size[1];
  int xdim3_initialise_chunk_kernel_volume = args[3].dat->size[0];
  int ydim3_initialise_chunk_kernel_volume = args[3].dat->size[1];
  int xdim4_initialise_chunk_kernel_volume = args[4].dat->size[0];
  int ydim4_initialise_chunk_kernel_volume = args[4].dat->size[1];
  int xdim5_initialise_chunk_kernel_volume = args[5].dat->size[0];
  int ydim5_initialise_chunk_kernel_volume = args[5].dat->size[1];
  int xdim6_initialise_chunk_kernel_volume = args[6].dat->size[0];
  int ydim6_initialise_chunk_kernel_volume = args[6].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ volume_p = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double * __restrict__ celldy_p = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double * __restrict__ xarea_p = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double * __restrict__ celldx_p = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  double * __restrict__ yarea_p = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  double * __restrict__ celldz_p = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  double * __restrict__ zarea_p = (double *)(args[6].data + base6);



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 7);
  ops_halo_exchanges(args,7,range);
  ops_H_D_exchanges_host(args, 7);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[9].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for collapse(2)
  for ( int n_z=start[2]; n_z<end[2]; n_z++ ){
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
        ACC<double> volume(xdim0_initialise_chunk_kernel_volume, ydim0_initialise_chunk_kernel_volume, volume_p + n_x*1 + n_y * xdim0_initialise_chunk_kernel_volume*1 + n_z * xdim0_initialise_chunk_kernel_volume * ydim0_initialise_chunk_kernel_volume*1);
        const ACC<double> celldy(xdim1_initialise_chunk_kernel_volume, ydim1_initialise_chunk_kernel_volume, celldy_p + n_x*0 + n_y * xdim1_initialise_chunk_kernel_volume*1 + n_z * xdim1_initialise_chunk_kernel_volume * ydim1_initialise_chunk_kernel_volume*0);
        ACC<double> xarea(xdim2_initialise_chunk_kernel_volume, ydim2_initialise_chunk_kernel_volume, xarea_p + n_x*1 + n_y * xdim2_initialise_chunk_kernel_volume*1 + n_z * xdim2_initialise_chunk_kernel_volume * ydim2_initialise_chunk_kernel_volume*1);
        const ACC<double> celldx(xdim3_initialise_chunk_kernel_volume, ydim3_initialise_chunk_kernel_volume, celldx_p + n_x*1 + n_y * xdim3_initialise_chunk_kernel_volume*0 + n_z * xdim3_initialise_chunk_kernel_volume * ydim3_initialise_chunk_kernel_volume*0);
        ACC<double> yarea(xdim4_initialise_chunk_kernel_volume, ydim4_initialise_chunk_kernel_volume, yarea_p + n_x*1 + n_y * xdim4_initialise_chunk_kernel_volume*1 + n_z * xdim4_initialise_chunk_kernel_volume * ydim4_initialise_chunk_kernel_volume*1);
        const ACC<double> celldz(xdim5_initialise_chunk_kernel_volume, ydim5_initialise_chunk_kernel_volume, celldz_p + n_x*0 + n_y * xdim5_initialise_chunk_kernel_volume*0 + n_z * xdim5_initialise_chunk_kernel_volume * ydim5_initialise_chunk_kernel_volume*1);
        ACC<double> zarea(xdim6_initialise_chunk_kernel_volume, ydim6_initialise_chunk_kernel_volume, zarea_p + n_x*1 + n_y * xdim6_initialise_chunk_kernel_volume*1 + n_z * xdim6_initialise_chunk_kernel_volume * ydim6_initialise_chunk_kernel_volume*1);
        

  double d_x, d_y, d_z;

  d_x = (grid.xmax - grid.xmin)/(double)grid.x_cells;
  d_y = (grid.ymax - grid.ymin)/(double)grid.y_cells;
  d_z = (grid.zmax - grid.zmin)/(double)grid.z_cells;

  volume(0,0,0) = d_x*d_y*d_z;
  xarea(0,0,0) = celldy(0,0,0)*celldz(0,0,0);
  yarea(0,0,0) = celldx(0,0,0)*celldz(0,0,0);
  zarea(0,0,0) = celldx(0,0,0)*celldy(0,0,0);

      }
    }
  }
  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[9].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 7);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[2],range);
  ops_set_halo_dirtybit3(&args[4],range);
  ops_set_halo_dirtybit3(&args[6],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[9].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg3);
    block->instance->OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg4);
    block->instance->OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg5);
    block->instance->OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg6);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_initialise_chunk_kernel_volume(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 0;
  desc->index = 9;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 9;
  for ( int i=0; i<6; i++ ){
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
  desc->function = ops_par_loop_initialise_chunk_kernel_volume_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,9,"initialise_chunk_kernel_volume");
  }
  ops_enqueue_kernel(desc);
}
#endif
