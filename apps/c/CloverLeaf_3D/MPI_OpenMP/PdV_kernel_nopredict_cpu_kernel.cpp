//
// auto-generated by ops.py
//
#define OPS_ACC0(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim0_PdV_kernel_nopredict + (n_z*1+(z))*xdim0_PdV_kernel_nopredict*ydim0_PdV_kernel_nopredict)
#define OPS_ACC1(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim1_PdV_kernel_nopredict + (n_z*1+(z))*xdim1_PdV_kernel_nopredict*ydim1_PdV_kernel_nopredict)
#define OPS_ACC2(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim2_PdV_kernel_nopredict + (n_z*1+(z))*xdim2_PdV_kernel_nopredict*ydim2_PdV_kernel_nopredict)
#define OPS_ACC3(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim3_PdV_kernel_nopredict + (n_z*1+(z))*xdim3_PdV_kernel_nopredict*ydim3_PdV_kernel_nopredict)
#define OPS_ACC4(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim4_PdV_kernel_nopredict + (n_z*1+(z))*xdim4_PdV_kernel_nopredict*ydim4_PdV_kernel_nopredict)
#define OPS_ACC5(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim5_PdV_kernel_nopredict + (n_z*1+(z))*xdim5_PdV_kernel_nopredict*ydim5_PdV_kernel_nopredict)
#define OPS_ACC6(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim6_PdV_kernel_nopredict + (n_z*1+(z))*xdim6_PdV_kernel_nopredict*ydim6_PdV_kernel_nopredict)
#define OPS_ACC7(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim7_PdV_kernel_nopredict + (n_z*1+(z))*xdim7_PdV_kernel_nopredict*ydim7_PdV_kernel_nopredict)
#define OPS_ACC8(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim8_PdV_kernel_nopredict + (n_z*1+(z))*xdim8_PdV_kernel_nopredict*ydim8_PdV_kernel_nopredict)
#define OPS_ACC9(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim9_PdV_kernel_nopredict + (n_z*1+(z))*xdim9_PdV_kernel_nopredict*ydim9_PdV_kernel_nopredict)
#define OPS_ACC10(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim10_PdV_kernel_nopredict + (n_z*1+(z))*xdim10_PdV_kernel_nopredict*ydim10_PdV_kernel_nopredict)
#define OPS_ACC11(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim11_PdV_kernel_nopredict + (n_z*1+(z))*xdim11_PdV_kernel_nopredict*ydim11_PdV_kernel_nopredict)
#define OPS_ACC12(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim12_PdV_kernel_nopredict + (n_z*1+(z))*xdim12_PdV_kernel_nopredict*ydim12_PdV_kernel_nopredict)
#define OPS_ACC13(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim13_PdV_kernel_nopredict + (n_z*1+(z))*xdim13_PdV_kernel_nopredict*ydim13_PdV_kernel_nopredict)
#define OPS_ACC14(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim14_PdV_kernel_nopredict + (n_z*1+(z))*xdim14_PdV_kernel_nopredict*ydim14_PdV_kernel_nopredict)
#define OPS_ACC15(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim15_PdV_kernel_nopredict + (n_z*1+(z))*xdim15_PdV_kernel_nopredict*ydim15_PdV_kernel_nopredict)
#define OPS_ACC16(x,y,z) (n_x*1 + x + (n_y*1+(y))*xdim16_PdV_kernel_nopredict + (n_z*1+(z))*xdim16_PdV_kernel_nopredict*ydim16_PdV_kernel_nopredict)

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_PdV_kernel_nopredict(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11,
 ops_arg arg12, ops_arg arg13, ops_arg arg14, ops_arg arg15,
 ops_arg arg16) {
#else
void ops_par_loop_PdV_kernel_nopredict_execute(ops_kernel_descriptor *desc) {
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
  ops_arg arg8 = desc->args[8];
  ops_arg arg9 = desc->args[9];
  ops_arg arg10 = desc->args[10];
  ops_arg arg11 = desc->args[11];
  ops_arg arg12 = desc->args[12];
  ops_arg arg13 = desc->args[13];
  ops_arg arg14 = desc->args[14];
  ops_arg arg15 = desc->args[15];
  ops_arg arg16 = desc->args[16];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[17] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,17,range,103)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(103,"PdV_kernel_nopredict");
    OPS_kernels[103].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(args, "PdV_kernel_nopredict");
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
  if (compute_ranges(args, 17,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_PdV_kernel_nopredict = args[0].dat->size[0];
  int ydim0_PdV_kernel_nopredict = args[0].dat->size[1];
  int xdim1_PdV_kernel_nopredict = args[1].dat->size[0];
  int ydim1_PdV_kernel_nopredict = args[1].dat->size[1];
  int xdim2_PdV_kernel_nopredict = args[2].dat->size[0];
  int ydim2_PdV_kernel_nopredict = args[2].dat->size[1];
  int xdim3_PdV_kernel_nopredict = args[3].dat->size[0];
  int ydim3_PdV_kernel_nopredict = args[3].dat->size[1];
  int xdim4_PdV_kernel_nopredict = args[4].dat->size[0];
  int ydim4_PdV_kernel_nopredict = args[4].dat->size[1];
  int xdim5_PdV_kernel_nopredict = args[5].dat->size[0];
  int ydim5_PdV_kernel_nopredict = args[5].dat->size[1];
  int xdim6_PdV_kernel_nopredict = args[6].dat->size[0];
  int ydim6_PdV_kernel_nopredict = args[6].dat->size[1];
  int xdim7_PdV_kernel_nopredict = args[7].dat->size[0];
  int ydim7_PdV_kernel_nopredict = args[7].dat->size[1];
  int xdim8_PdV_kernel_nopredict = args[8].dat->size[0];
  int ydim8_PdV_kernel_nopredict = args[8].dat->size[1];
  int xdim9_PdV_kernel_nopredict = args[9].dat->size[0];
  int ydim9_PdV_kernel_nopredict = args[9].dat->size[1];
  int xdim10_PdV_kernel_nopredict = args[10].dat->size[0];
  int ydim10_PdV_kernel_nopredict = args[10].dat->size[1];
  int xdim11_PdV_kernel_nopredict = args[11].dat->size[0];
  int ydim11_PdV_kernel_nopredict = args[11].dat->size[1];
  int xdim12_PdV_kernel_nopredict = args[12].dat->size[0];
  int ydim12_PdV_kernel_nopredict = args[12].dat->size[1];
  int xdim13_PdV_kernel_nopredict = args[13].dat->size[0];
  int ydim13_PdV_kernel_nopredict = args[13].dat->size[1];
  int xdim14_PdV_kernel_nopredict = args[14].dat->size[0];
  int ydim14_PdV_kernel_nopredict = args[14].dat->size[1];
  int xdim15_PdV_kernel_nopredict = args[15].dat->size[0];
  int ydim15_PdV_kernel_nopredict = args[15].dat->size[1];
  int xdim16_PdV_kernel_nopredict = args[16].dat->size[0];
  int ydim16_PdV_kernel_nopredict = args[16].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  const double * __restrict__ xarea = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  const double * __restrict__ xvel0 = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  const double * __restrict__ xvel1 = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  const double * __restrict__ yarea = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  const double * __restrict__ yvel0 = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  const double * __restrict__ yvel1 = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  double * __restrict__ volume_change = (double *)(args[6].data + base6);

  int base7 = args[7].dat->base_offset;
  const double * __restrict__ volume = (double *)(args[7].data + base7);

  int base8 = args[8].dat->base_offset;
  const double * __restrict__ pressure = (double *)(args[8].data + base8);

  int base9 = args[9].dat->base_offset;
  const double * __restrict__ density0 = (double *)(args[9].data + base9);

  int base10 = args[10].dat->base_offset;
  double * __restrict__ density1 = (double *)(args[10].data + base10);

  int base11 = args[11].dat->base_offset;
  const double * __restrict__ viscosity = (double *)(args[11].data + base11);

  int base12 = args[12].dat->base_offset;
  const double * __restrict__ energy0 = (double *)(args[12].data + base12);

  int base13 = args[13].dat->base_offset;
  double * __restrict__ energy1 = (double *)(args[13].data + base13);

  int base14 = args[14].dat->base_offset;
  const double * __restrict__ zarea = (double *)(args[14].data + base14);

  int base15 = args[15].dat->base_offset;
  const double * __restrict__ zvel0 = (double *)(args[15].data + base15);

  int base16 = args[16].dat->base_offset;
  const double * __restrict__ zvel1 = (double *)(args[16].data + base16);



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_host(args, 17);
  ops_halo_exchanges(args,17,range);
  ops_H_D_exchanges_host(args, 17);
  #endif

  if (OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    OPS_kernels[103].mpi_time += __t1-__t2;
  }

  #pragma omp parallel for collapse(2)
  for ( int n_z=start[2]; n_z<end[2]; n_z++ ){
    for ( int n_y=start[1]; n_y<end[1]; n_y++ ){
      #ifdef __INTEL_COMPILER
      #pragma loop_count(10000)
      #pragma omp simd aligned(xarea,xvel0,xvel1,yarea,yvel0,yvel1,volume_change,volume,pressure,density0,density1,viscosity,energy0,energy1,zarea,zvel0,zvel1)
      #else
      #pragma simd
      #endif
      for ( int n_x=start[0]; n_x<end[0]; n_x++ ){
        

  double recip_volume, energy_change;
  double right_flux, left_flux, top_flux, bottom_flux, back_flux, front_flux, total_flux;

  left_flux = ( xarea[OPS_ACC0(0,0,0)] * ( xvel0[OPS_ACC1(0,0,0)] + xvel0[OPS_ACC1(0,1,0)] +
                                           xvel0[OPS_ACC1(0,0,1)] + xvel0[OPS_ACC1(0,1,1)] +
                                           xvel1[OPS_ACC2(0,0,0)] + xvel1[OPS_ACC2(0,1,0)] +
                                           xvel1[OPS_ACC2(0,0,1)] + xvel1[OPS_ACC2(0,1,1)] ) ) * 0.125 * dt;
  right_flux = ( xarea[OPS_ACC0(1,0,0)] * ( xvel0[OPS_ACC1(1,0,0)] + xvel0[OPS_ACC1(1,1,0)] +
                                            xvel0[OPS_ACC1(1,0,1)] + xvel0[OPS_ACC1(1,1,1)] +
                                            xvel1[OPS_ACC2(1,0,0)] + xvel1[OPS_ACC2(1,1,0)] +
                                            xvel1[OPS_ACC2(1,0,1)] + xvel1[OPS_ACC2(1,1,1)] ) ) * 0.125 * dt;

  bottom_flux = ( yarea[OPS_ACC3(0,0,0)] * ( yvel0[OPS_ACC4(0,0,0)] + yvel0[OPS_ACC4(1,0,0)] +
                                             yvel0[OPS_ACC4(0,0,1)] + yvel0[OPS_ACC4(1,0,1)] +
                                             yvel1[OPS_ACC5(0,0,0)] + yvel1[OPS_ACC5(1,0,0)] +
                                             yvel1[OPS_ACC5(0,0,1)] + yvel1[OPS_ACC5(1,0,1)] ) ) * 0.125* dt;
  top_flux = ( yarea[OPS_ACC3(0,1,0)] * ( yvel0[OPS_ACC4(0,1,0)] + yvel0[OPS_ACC4(1,1,0)] +
                                          yvel0[OPS_ACC4(0,1,1)] + yvel0[OPS_ACC4(1,1,1)] +
                                          yvel1[OPS_ACC5(0,1,0)] + yvel1[OPS_ACC5(1,1,0)] +
                                          yvel1[OPS_ACC5(0,1,1)] + yvel1[OPS_ACC5(1,1,1)]) ) * 0.125 * dt;

  back_flux = ( zarea[OPS_ACC14(0,0,0)] * ( zvel0[OPS_ACC15(0,0,0)] + zvel0[OPS_ACC15(1,0,0)] +
                                            zvel0[OPS_ACC15(0,1,0)] + zvel0[OPS_ACC15(1,1,0)] +
                                            zvel1[OPS_ACC16(0,0,0)] + zvel1[OPS_ACC16(1,0,0)] +
                                            zvel1[OPS_ACC16(0,1,0)] + zvel1[OPS_ACC16(1,1,0)] ) ) * 0.125* dt;
  front_flux = ( zarea[OPS_ACC14(0,0,1)] * ( zvel0[OPS_ACC15(0,0,1)] + zvel0[OPS_ACC15(1,0,1)] +
                                             zvel0[OPS_ACC15(0,1,1)] + zvel0[OPS_ACC15(1,1,1)] +
                                             zvel1[OPS_ACC16(0,0,1)] + zvel1[OPS_ACC16(1,0,1)] +
                                             zvel1[OPS_ACC16(0,1,1)] + zvel1[OPS_ACC16(1,1,1)]) ) * 0.125 * dt;

  total_flux = right_flux - left_flux + top_flux - bottom_flux + front_flux - back_flux;

  volume_change[OPS_ACC6(0,0,0)] = (volume[OPS_ACC7(0,0,0)])/(volume[OPS_ACC7(0,0,0)] + total_flux);
  recip_volume = 1.0/volume[OPS_ACC7(0,0,0)];
  energy_change = ( pressure[OPS_ACC8(0,0,0)]/density0[OPS_ACC9(0,0,0)] +
                    viscosity[OPS_ACC11(0,0,0)]/density0[OPS_ACC9(0,0,0)] ) * total_flux * recip_volume;
  energy1[OPS_ACC13(0,0,0)] = energy0[OPS_ACC12(0,0,0)] - energy_change;
  density1[OPS_ACC10(0,0,0)] = density0[OPS_ACC9(0,0,0)] * volume_change[OPS_ACC6(0,0,0)];


      }
    }
  }
  if (OPS_diags > 1) {
    ops_timers_core(&__c2,&__t2);
    OPS_kernels[103].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_host(args, 17);
  ops_set_halo_dirtybit3(&args[6],range);
  ops_set_halo_dirtybit3(&args[10],range);
  ops_set_halo_dirtybit3(&args[13],range);
  #endif

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    OPS_kernels[103].mpi_time += __t1-__t2;
    OPS_kernels[103].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[103].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[103].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[103].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[103].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[103].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[103].transfer += ops_compute_transfer(dim, start, end, &arg6);
    OPS_kernels[103].transfer += ops_compute_transfer(dim, start, end, &arg7);
    OPS_kernels[103].transfer += ops_compute_transfer(dim, start, end, &arg8);
    OPS_kernels[103].transfer += ops_compute_transfer(dim, start, end, &arg9);
    OPS_kernels[103].transfer += ops_compute_transfer(dim, start, end, &arg10);
    OPS_kernels[103].transfer += ops_compute_transfer(dim, start, end, &arg11);
    OPS_kernels[103].transfer += ops_compute_transfer(dim, start, end, &arg12);
    OPS_kernels[103].transfer += ops_compute_transfer(dim, start, end, &arg13);
    OPS_kernels[103].transfer += ops_compute_transfer(dim, start, end, &arg14);
    OPS_kernels[103].transfer += ops_compute_transfer(dim, start, end, &arg15);
    OPS_kernels[103].transfer += ops_compute_transfer(dim, start, end, &arg16);
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
#undef OPS_ACC8
#undef OPS_ACC9
#undef OPS_ACC10
#undef OPS_ACC11
#undef OPS_ACC12
#undef OPS_ACC13
#undef OPS_ACC14
#undef OPS_ACC15
#undef OPS_ACC16


#ifdef OPS_LAZY
void ops_par_loop_PdV_kernel_nopredict(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3,
 ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7,
 ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11,
 ops_arg arg12, ops_arg arg13, ops_arg arg14, ops_arg arg15,
 ops_arg arg16) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 103;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 103;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 17;
  desc->args = (ops_arg*)malloc(17*sizeof(ops_arg));
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
  desc->args[8] = arg8;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg8.dat->index;
  desc->args[9] = arg9;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg9.dat->index;
  desc->args[10] = arg10;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg10.dat->index;
  desc->args[11] = arg11;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg11.dat->index;
  desc->args[12] = arg12;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg12.dat->index;
  desc->args[13] = arg13;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg13.dat->index;
  desc->args[14] = arg14;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg14.dat->index;
  desc->args[15] = arg15;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg15.dat->index;
  desc->args[16] = arg16;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg16.dat->index;
  desc->function = ops_par_loop_PdV_kernel_nopredict_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(103,"PdV_kernel_nopredict");
  }
  ops_enqueue_kernel(desc);
}
#endif
