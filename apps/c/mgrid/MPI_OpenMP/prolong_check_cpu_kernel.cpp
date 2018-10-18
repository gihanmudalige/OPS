//
// auto-generated by ops.py
//
#define OPS_ACC0(x,y) (n_x*1 + x + (n_y*1+(y))*xdim0_prolong_check)

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_prolong_check(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4) {
#else
void ops_par_loop_prolong_check_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[5] = { arg0, arg1, arg2, arg3, arg4};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,5,range,3)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(3,"prolong_check");
    OPS_kernels[3].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "prolong_check");
  #endif


  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];
  int arg_idx[2];
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 5,block, range, start, end, arg_idx) < 0) return;
  #endif

  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  arg_idx[0] = sb->decomp_disp[0];
  arg_idx[1] = sb->decomp_disp[1];
  #else //OPS_MPI
  arg_idx[0] = 0;
  arg_idx[1] = 0;
  #endif //OPS_MPI

  //initialize global variable with the dimension of dats
  int xdim0_prolong_check = args[0].dat->size[0];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  const double * __restrict__ val = (double *)(args[0].data + base0);


  #ifdef OPS_MPI
  int * __restrict__ p_a2 = (int *)(((ops_reduction)args[2].data)->data + ((ops_reduction)args[2].data)->size * block->index);
  #else //OPS_MPI
  int * __restrict__ p_a2 = (int *)((ops_reduction)args[2].data)->data;
  #endif //OPS_MPI


  const int * __restrict__ sizex = (int *)args[3].data;


  const int * __restrict__ sizey = (int *)args[4].data;




  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 5);
  ops_halo_exchanges(args,5,range);
  ops_H_D_exchanges_host(args, 5);
  #endif

  if (OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    OPS_kernels[3].mpi_time += __t1-__t2;
  }

  int p_a2_0 = p_a2[0];
  #pragma omp parallel for reduction(max:p_a2_0)
  for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
    #ifdef __INTEL_COMPILER
    #pragma loop_count(10000)
    #pragma omp simd reduction(max:p_a2_0) aligned(val)
    #else
    #pragma simd
    #endif
    for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
      int idx[] = {arg_idx[0]+n_x, arg_idx[1]+n_y};
      int err[1];
      err[0] = p_a2[0];
      
  int lerr = 0;
  lerr |= (val[OPS_ACC0(0,0)] != idx[0]/4 + (idx[1]/4)*(*sizex/4));
  if (lerr) printf("ERR (%d, %d): value %g, expected %d\n", idx[0], idx[1], val[OPS_ACC0(0,0)], idx[0]/4 + (idx[1]/4)*(*sizex/4));
  int xm = (idx[0]-1)<0 ? *sizex-1 : idx[0]-1;
  int xp = (idx[0]+1)>=*sizex ? 0 : idx[0]+1;
  int ym = (idx[1]-1)<0 ? *sizey-1 : idx[1]-1;
  int yp = (idx[1]+1)>=*sizey ? 0 : idx[1]+1;
  lerr |= (val[OPS_ACC0(1,0)] != xp/4 + (idx[1]/4)*(*sizex/4));
  if (lerr) printf("ERR (%d+1, %d): value %g, expected %d\n", idx[0], idx[1], val[OPS_ACC0(1,0)], xp/4 + (idx[1]/4)*(*sizex/4));
  lerr |= (val[OPS_ACC0(-1,0)] != xm/4 + (idx[1]/4)*(*sizex/4));
  if (lerr) printf("ERR (%d-1, %d): value %g, expected %d\n", idx[0], idx[1], val[OPS_ACC0(-1,0)], xm/4 + (idx[1]/4)*(*sizex/4));
  lerr |= (val[OPS_ACC0(0,1)] != idx[0]/4 + (yp/4)*(*sizex/4));
  if (lerr) printf("ERR (%d, %d+1): value %g, expected %d\n", idx[0], idx[1], val[OPS_ACC0(0,1)], idx[0]/4 + (xm/4)*(*sizex/4));
  lerr |= (val[OPS_ACC0(0,-1)] != idx[0]/4 + (ym/4)*(*sizex/4));
  if (lerr) printf("ERR (%d, %d-1): value %g, expected %d\n", idx[0], idx[1], val[OPS_ACC0(0,-1)], idx[0]/4 + (ym/4)*(*sizex/4));

  if (lerr != 0) *err = 1;
  else *err = 0;


      p_a2_0 = MAX(p_a2_0,err[0]);
    }
  }
  p_a2[0] = p_a2_0;
  if (OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    OPS_kernels[3].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 5);
  #endif

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    OPS_kernels[3].mpi_time += __t1-__t2;
    OPS_kernels[3].transfer += ops_compute_transfer(dim, start, end, &arg0);
  }
}
#undef OPS_ACC0


#ifdef OPS_LAZY
void ops_par_loop_prolong_check(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 3;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 3;
  for ( int i=0; i<4; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 5;
  desc->args = (ops_arg*)malloc(5*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->args[2] = arg2;
  desc->args[3] = arg3;
  char *tmp = (char*)malloc(1*sizeof(int));
  memcpy(tmp, arg3.data,1*sizeof(int));
  desc->args[3].data = tmp;
  desc->args[4] = arg4;
  tmp = (char*)malloc(1*sizeof(int));
  memcpy(tmp, arg4.data,1*sizeof(int));
  desc->args[4].data = tmp;
  desc->function = ops_par_loop_prolong_check_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(3,"prolong_check");
  }
  ops_enqueue_kernel(desc);
}
#endif
