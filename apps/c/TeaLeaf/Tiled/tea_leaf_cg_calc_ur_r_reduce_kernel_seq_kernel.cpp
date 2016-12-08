//
// auto-generated by ops.py
//
#define OPS_ACC0(x,y) (n_x*1+n_y*xdim0_tea_leaf_cg_calc_ur_r_reduce_kernel*1+x+xdim0_tea_leaf_cg_calc_ur_r_reduce_kernel*(y))
#define OPS_ACC1(x,y) (n_x*1+n_y*xdim1_tea_leaf_cg_calc_ur_r_reduce_kernel*1+x+xdim1_tea_leaf_cg_calc_ur_r_reduce_kernel*(y))


//user function

// host stub function
void ops_par_loop_tea_leaf_cg_calc_ur_r_reduce_kernel_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[4] = { arg0, arg1, arg2, arg3};



  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,4,range,21)) return;
  #endif

  if (OPS_diags > 1) {
    OPS_kernels[21].count++;
    ops_timers_core(&c2,&t2);
  }

  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];

  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "tea_leaf_cg_calc_ur_r_reduce_kernel");
  #endif



  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ r = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  const double * __restrict__ w = (double *)(args[1].data + base1);

  const double * __restrict__ alpha = (double *)args[2].data;


  #ifdef OPS_MPI
  double * __restrict__ p_a3 = (double *)(((ops_reduction)args[3].data)->data + ((ops_reduction)args[3].data)->size * block->index);
  #else //OPS_MPI
  double * __restrict__ p_a3 = (double *)((ops_reduction)args[3].data)->data;
  #endif //OPS_MPI



  //initialize global variable with the dimension of dats
  int xdim0_tea_leaf_cg_calc_ur_r_reduce_kernel = args[0].dat->size[0];
  int xdim1_tea_leaf_cg_calc_ur_r_reduce_kernel = args[1].dat->size[0];

  if (OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
    OPS_kernels[21].mpi_time += t1-t2;
  }

  double p_a3_0 = p_a3[0];
  #pragma omp parallel for reduction(+:p_a3_0)
  for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
    #ifdef intel
    #pragma omp simd reduction(+:p_a3_0)
    #else
    #pragma simd reduction(+:p_a3_0)
    #endif
    for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
      double *rnn = &p_a3_0;
      
  r[OPS_ACC0(0,0)] = r[OPS_ACC0(0,0)] - (*alpha)*w[OPS_ACC1(0,0)];
  *rnn = *rnn +  r[OPS_ACC0(0,0)]*r[OPS_ACC0(0,0)];

    }
  }
  p_a3[0] = p_a3_0;
  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[21].time += t2-t1;
  }

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c1,&t1);
    OPS_kernels[21].mpi_time += t1-t2;
    OPS_kernels[21].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[21].transfer += ops_compute_transfer(dim, start, end, &arg1);
  }
}
#undef OPS_ACC0
#undef OPS_ACC1


void ops_par_loop_tea_leaf_cg_calc_ur_r_reduce_kernel(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->index = 21;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 21;
  for ( int i=0; i<4; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
  }
  desc->nargs = 4;
  desc->args = (ops_arg*)malloc(4*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  char *tmp = (char*)malloc(1*sizeof(double));
  memcpy(tmp, arg2.data,1*sizeof(double));
  desc->args[2].data = tmp;
  desc->args[3] = arg3;
  desc->function = ops_par_loop_tea_leaf_cg_calc_ur_r_reduce_kernel_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(21,"tea_leaf_cg_calc_ur_r_reduce_kernel");
  }
  ops_enqueue_kernel(desc);
  }
