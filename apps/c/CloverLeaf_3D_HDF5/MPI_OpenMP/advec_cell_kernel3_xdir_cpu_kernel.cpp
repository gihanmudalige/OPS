//
// auto-generated by ops.py
//
#define OPS_ACC0(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim0_advec_cell_kernel3_xdir + (n_z*1+(z))*xdim0_advec_cell_kernel3_xdir*ydim0_advec_cell_kernel3_xdir)
#define OPS_ACC1(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim1_advec_cell_kernel3_xdir + (n_z*1+(z))*xdim1_advec_cell_kernel3_xdir*ydim1_advec_cell_kernel3_xdir)
#define OPS_ACC2(x,y,z) (n_x*1 + x + (n_y*0+(y))*xdim2_advec_cell_kernel3_xdir + (n_z*0+(z))*xdim2_advec_cell_kernel3_xdir*ydim2_advec_cell_kernel3_xdir)
#define OPS_ACC3(x,y,z) (n_x*1 + x + (n_y*0+(y))*xdim3_advec_cell_kernel3_xdir + (n_z*0+(z))*xdim3_advec_cell_kernel3_xdir*ydim3_advec_cell_kernel3_xdir)
#define OPS_ACC4(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim4_advec_cell_kernel3_xdir + (n_z*1+(z))*xdim4_advec_cell_kernel3_xdir*ydim4_advec_cell_kernel3_xdir)
#define OPS_ACC5(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim5_advec_cell_kernel3_xdir + (n_z*1+(z))*xdim5_advec_cell_kernel3_xdir*ydim5_advec_cell_kernel3_xdir)
#define OPS_ACC6(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim6_advec_cell_kernel3_xdir + (n_z*1+(z))*xdim6_advec_cell_kernel3_xdir*ydim6_advec_cell_kernel3_xdir)
#define OPS_ACC7(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim7_advec_cell_kernel3_xdir + (n_z*1+(z))*xdim7_advec_cell_kernel3_xdir*ydim7_advec_cell_kernel3_xdir)

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_advec_cell_kernel3_xdir(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {
#else
void ops_par_loop_advec_cell_kernel3_xdir_execute(ops_kernel_descriptor *desc) {
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
  ops_arg arg7 = desc->args[7];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[8] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,8,range,110)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(110,"advec_cell_kernel3_xdir");
    OPS_kernels[110].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "advec_cell_kernel3_xdir");
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
  if (compute_ranges(args, 8,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_advec_cell_kernel3_xdir = args[0].dat->size[0];
  int ydim0_advec_cell_kernel3_xdir = args[0].dat->size[1];
  int xdim1_advec_cell_kernel3_xdir = args[1].dat->size[0];
  int ydim1_advec_cell_kernel3_xdir = args[1].dat->size[1];
  int xdim2_advec_cell_kernel3_xdir = args[2].dat->size[0];
  int ydim2_advec_cell_kernel3_xdir = args[2].dat->size[1];
  int xdim3_advec_cell_kernel3_xdir = args[3].dat->size[0];
  int ydim3_advec_cell_kernel3_xdir = args[3].dat->size[1];
  int xdim4_advec_cell_kernel3_xdir = args[4].dat->size[0];
  int ydim4_advec_cell_kernel3_xdir = args[4].dat->size[1];
  int xdim5_advec_cell_kernel3_xdir = args[5].dat->size[0];
  int ydim5_advec_cell_kernel3_xdir = args[5].dat->size[1];
  int xdim6_advec_cell_kernel3_xdir = args[6].dat->size[0];
  int ydim6_advec_cell_kernel3_xdir = args[6].dat->size[1];
  int xdim7_advec_cell_kernel3_xdir = args[7].dat->size[0];
  int ydim7_advec_cell_kernel3_xdir = args[7].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  const double * __restrict__ vol_flux_x = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  const double * __restrict__ pre_vol = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  const int * __restrict__ xx = (int *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  const double * __restrict__ vertexdx = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  const double * __restrict__ density1 = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  const double * __restrict__ energy1 = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  double * __restrict__ mass_flux_x = (double *)(args[6].data + base6);

  int base7 = args[7].dat->base_offset;
  double * __restrict__ ener_flux = (double *)(args[7].data + base7);



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 8);
  ops_halo_exchanges(args,8,range);
  ops_H_D_exchanges_host(args, 8);
  #endif

  if (OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    OPS_kernels[110].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for collapse(2)
  for ( int n_z=start[2]; n_z<end[2]; n_z++ ){
    for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
      #ifdef __INTEL_COMPILER
      #pragma loop_count(10000)
      #pragma omp simd aligned(vol_flux_x,pre_vol,xx,vertexdx,density1,energy1,mass_flux_x,ener_flux)
      #else
      #pragma simd
      #endif
      for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
        

  double sigmat, sigmav, sigmam, sigma3, sigma4;
  double diffuw, diffdw, limiter;
  double one_by_six = 1.0/6.0;

  int x_max=field.x_max;

  int upwind,donor,downwind,dif;





  if(vol_flux_x[OPS_ACC0(0,0,0)] > 0.0) {
    upwind   = -2;
    donor    = -1;
    downwind = 0;
    dif      = donor;
  }
  else if (xx[OPS_ACC2(1,0,0)] < x_max+2-2) {
    upwind   = 1;
    donor    = 0;
    downwind = -1;
    dif      = upwind;
  } else {
    upwind   = 0;
    donor    = 0;
    downwind = -1;
    dif      = upwind;
  }

  sigmat = fabs(vol_flux_x[OPS_ACC0(0,0,0)])/pre_vol[OPS_ACC1(donor,0,0)];
  sigma3 = (1.0 + sigmat)*(vertexdx[OPS_ACC3(0,0,0)]/vertexdx[OPS_ACC3(dif,0,0)]);
  sigma4 = 2.0 - sigmat;

  sigmav = sigmat;

  diffuw = density1[OPS_ACC4(donor,0,0)] - density1[OPS_ACC4(upwind,0,0)];
  diffdw = density1[OPS_ACC4(downwind,0,0)] - density1[OPS_ACC4(donor,0,0)];

  if( (diffuw*diffdw) > 0.0)
    limiter=(1.0 - sigmav) * SIGN(1.0 , diffdw) *
    MIN( MIN(fabs(diffuw), fabs(diffdw)),
    one_by_six * (sigma3*fabs(diffuw) + sigma4 * fabs(diffdw)));
  else
    limiter=0.0;

  mass_flux_x[OPS_ACC6(0,0,0)] = (vol_flux_x[OPS_ACC0(0,0,0)]) * ( density1[OPS_ACC4(donor,0,0)] + limiter );

  sigmam = fabs(mass_flux_x[OPS_ACC6(0,0,0)])/( density1[OPS_ACC4(donor,0,0)] * pre_vol[OPS_ACC1(donor,0,0)]);
  diffuw = energy1[OPS_ACC5(donor,0,0)] - energy1[OPS_ACC5(upwind,0,0)];
  diffdw = energy1[OPS_ACC5(downwind,0,0)] - energy1[OPS_ACC5(donor,0,0)];

  if( (diffuw*diffdw) > 0.0)
    limiter = (1.0 - sigmam) * SIGN(1.0,diffdw) *
    MIN( MIN(fabs(diffuw), fabs(diffdw)),
    one_by_six * (sigma3 * fabs(diffuw) + sigma4 * fabs(diffdw)));
  else
    limiter=0.0;

  ener_flux[OPS_ACC7(0,0,0)] = mass_flux_x[OPS_ACC6(0,0,0)] * ( energy1[OPS_ACC5(donor,0,0)] + limiter );

      }
    }
  }
  if (OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    OPS_kernels[110].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 8);
  ops_set_halo_dirtybit3(&args[6],range);
  ops_set_halo_dirtybit3(&args[7],range);
  #endif

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    OPS_kernels[110].mpi_time += __t1-__t2;
    OPS_kernels[110].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[110].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[110].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[110].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[110].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[110].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[110].transfer += ops_compute_transfer(dim, start, end, &arg6);
    OPS_kernels[110].transfer += ops_compute_transfer(dim, start, end, &arg7);
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
#undef OPS_ACC7


#ifdef OPS_LAZY
void ops_par_loop_advec_cell_kernel3_xdir(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 110;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 110;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 8;
  desc->args = (ops_arg*)malloc(8*sizeof(ops_arg));
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
  desc->args[7] = arg7;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg7.dat->index;
  desc->function = ops_par_loop_advec_cell_kernel3_xdir_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(110,"advec_cell_kernel3_xdir");
  }
  ops_enqueue_kernel(desc);
}
#endif
