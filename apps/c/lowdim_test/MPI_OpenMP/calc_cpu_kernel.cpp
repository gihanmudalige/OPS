//
// auto-generated by ops.py
//
#define OPS_ACC0(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim0_calc + (n_z*1+(z))*xdim0_calc*ydim0_calc)
#define OPS_ACC1(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim1_calc + (n_z*0+(z))*xdim1_calc*ydim1_calc)
#define OPS_ACC2(x,y,z) (n_x*0 + x + (n_y*1+(y))*xdim2_calc + (n_z*1+(z))*xdim2_calc*ydim2_calc)
#define OPS_ACC3(x,y,z) (n_x*1 + x + (n_y*0+(y))*xdim3_calc + (n_z*1+(z))*xdim3_calc*ydim3_calc)
#define OPS_ACC4(x,y,z) (n_x*1 + x + (n_y*0+(y))*xdim4_calc + (n_z*0+(z))*xdim4_calc*ydim4_calc)
#define OPS_ACC5(x,y,z) (n_x*0 + x + (n_y*1+(y))*xdim5_calc + (n_z*0+(z))*xdim5_calc*ydim5_calc)
#define OPS_ACC6(x,y,z) (n_x*0 + x + (n_y*0+(y))*xdim6_calc + (n_z*1+(z))*xdim6_calc*ydim6_calc)

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_calc(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6) {
#else
void ops_par_loop_calc_execute(ops_kernel_descriptor *desc) {
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
  if (!ops_checkpointing_before(args,7,range,7)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(7,"calc");
    OPS_kernels[7].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "calc");
  #endif


  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #ifdef OPS_MPI
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
  int xdim0_calc = args[0].dat->size[0];
  int ydim0_calc = args[0].dat->size[1];
  int xdim1_calc = args[1].dat->size[0];
  int ydim1_calc = args[1].dat->size[1];
  int xdim2_calc = args[2].dat->size[0];
  int ydim2_calc = args[2].dat->size[1];
  int xdim3_calc = args[3].dat->size[0];
  int ydim3_calc = args[3].dat->size[1];
  int xdim4_calc = args[4].dat->size[0];
  int ydim4_calc = args[4].dat->size[1];
  int xdim5_calc = args[5].dat->size[0];
  int ydim5_calc = args[5].dat->size[1];
  int xdim6_calc = args[6].dat->size[0];
  int ydim6_calc = args[6].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double * __restrict__ dat3D = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  const double * __restrict__ dat2D_xy = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  const double * __restrict__ dat2D_yz = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  const double * __restrict__ dat2D_xz = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  const double * __restrict__ dat1D_x = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  const double * __restrict__ dat1D_y = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  const double * __restrict__ dat1D_z = (double *)(args[6].data + base6);



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 7);
  ops_halo_exchanges(args,7,range);
  ops_H_D_exchanges_host(args, 7);
  #endif

  if (OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    OPS_kernels[7].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for collapse(2)
  for ( int n_z=start[2]; n_z<end[2]; n_z++ ){
    for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
      #ifdef __INTEL_COMPILER
      #pragma loop_count(10000)
      #pragma omp simd aligned(dat3D,dat2D_xy,dat2D_yz,dat2D_xz,dat1D_x,dat1D_y,dat1D_z)
      #else
      #pragma simd
      #endif
      for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
        
  dat3D[OPS_ACC0(0,0,0)] = dat2D_xy[OPS_ACC1(0,0,0)] +
                           dat2D_yz[OPS_ACC2(0,0,0)] +
                           dat2D_xz[OPS_ACC3(0,0,0)] +
                           dat1D_x[OPS_ACC4(0,0,0)] +
                           dat1D_y[OPS_ACC5(0,0,0)] +
                           dat1D_z[OPS_ACC6(0,0,0)];

      }
    }
  }
  if (OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    OPS_kernels[7].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 7);
  ops_set_halo_dirtybit3(&args[0],range);
  #endif

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    OPS_kernels[7].mpi_time += __t1-__t2;
    OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg6);
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6


#ifdef OPS_LAZY
void ops_par_loop_calc(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 7;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 7;
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
  desc->function = ops_par_loop_calc_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(7,"calc");
  }
  ops_enqueue_kernel(desc);
}
#endif