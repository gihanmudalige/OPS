//
// auto-generated by ops.py
//
#define OPS_ACC_MD0(d,x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim0_multidim_kernel + (n_z*1+(z))*xdim0_multidim_kernel*ydim0_multidim_kernel+(d)*xdim0_multidim_kernel*ydim0_multidim_kernel*zdim0_multidim_kernel)

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_multidim_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1) {
#else
void ops_par_loop_multidim_kernel_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[2] = { arg0, arg1};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,2,range,0)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(0,"multidim_kernel");
    OPS_kernels[0].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "multidim_kernel");
  #endif


  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  int arg_idx[3];
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 2,block, range, start, end, arg_idx) < 0) return;
  #endif

  #ifdef OPS_MPI
  sub_dat_list sd = OPS_sub_dat_list[args[0].dat->index];
  arg_idx[0] = MAX(0,sd->decomp_disp[0]);
  arg_idx[1] = MAX(0,sd->decomp_disp[1]);
  arg_idx[2] = MAX(0,sd->decomp_disp[2]);
  #else //OPS_MPI
  arg_idx[0] = 0;
  arg_idx[1] = 0;
  arg_idx[2] = 0;
  #endif //OPS_MPI

  //initialize global variable with the dimension of dats
  int xdim0_multidim_kernel = args[0].dat->size[0];
  int ydim0_multidim_kernel = args[0].dat->size[1];
  int zdim0_multidim_kernel = args[0].dat->size[2];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ val = (double *)(args[0].data + base0);




  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 2);
  ops_halo_exchanges(args,2,range);
  ops_H_D_exchanges_host(args, 2);
  #endif

  if (OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    OPS_kernels[0].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for collapse(2)
  for ( int n_z=start[2]; n_z<end[2]; n_z++ ){
    for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
      #ifdef __INTEL_COMPILER
      #pragma loop_count(10000)
      #pragma omp simd aligned(val)
      #else
      #pragma simd
      #endif
      for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
        int idx[] = {arg_idx[0]+n_x, arg_idx[1]+n_y, arg_idx[2]+n_z};
        
  val[OPS_ACC_MD0(0,0,0,0)] = (double)(idx[0]);
  val[OPS_ACC_MD0(1,0,0,0)] = (double)(idx[1]);
  val[OPS_ACC_MD0(2,0,0,0)] = (double)(idx[2]);




      }
    }
  }
  if (OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    OPS_kernels[0].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 2);
  ops_set_halo_dirtybit3(&args[0],range);
  #endif

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    OPS_kernels[0].mpi_time += __t1-__t2;
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg0);
  }
}
#undef OPS_ACC_MD0


#ifdef OPS_LAZY
void ops_par_loop_multidim_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 0;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 0;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 2;
  desc->args = (ops_arg*)malloc(2*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->function = ops_par_loop_multidim_kernel_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(0,"multidim_kernel");
  }
  ops_enqueue_kernel(desc);
}
#endif
