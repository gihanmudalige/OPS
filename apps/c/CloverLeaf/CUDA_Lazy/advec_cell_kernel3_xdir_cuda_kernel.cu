//
// auto-generated by ops.py
//
__constant__ int xdim0_advec_cell_kernel3_xdir;
int xdim0_advec_cell_kernel3_xdir_h = -1;
int ydim0_advec_cell_kernel3_xdir_h = -1;
__constant__ int xdim1_advec_cell_kernel3_xdir;
int xdim1_advec_cell_kernel3_xdir_h = -1;
int ydim1_advec_cell_kernel3_xdir_h = -1;
__constant__ int xdim2_advec_cell_kernel3_xdir;
int xdim2_advec_cell_kernel3_xdir_h = -1;
int ydim2_advec_cell_kernel3_xdir_h = -1;
__constant__ int xdim3_advec_cell_kernel3_xdir;
int xdim3_advec_cell_kernel3_xdir_h = -1;
int ydim3_advec_cell_kernel3_xdir_h = -1;
__constant__ int xdim4_advec_cell_kernel3_xdir;
int xdim4_advec_cell_kernel3_xdir_h = -1;
int ydim4_advec_cell_kernel3_xdir_h = -1;
__constant__ int xdim5_advec_cell_kernel3_xdir;
int xdim5_advec_cell_kernel3_xdir_h = -1;
int ydim5_advec_cell_kernel3_xdir_h = -1;
__constant__ int xdim6_advec_cell_kernel3_xdir;
int xdim6_advec_cell_kernel3_xdir_h = -1;
int ydim6_advec_cell_kernel3_xdir_h = -1;
__constant__ int xdim7_advec_cell_kernel3_xdir;
int xdim7_advec_cell_kernel3_xdir_h = -1;
int ydim7_advec_cell_kernel3_xdir_h = -1;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
#undef OPS_ACC7


#define OPS_ACC0(x,y) (x+xdim0_advec_cell_kernel3_xdir*(y))
#define OPS_ACC1(x,y) (x+xdim1_advec_cell_kernel3_xdir*(y))
#define OPS_ACC2(x,y) (x+xdim2_advec_cell_kernel3_xdir*(y))
#define OPS_ACC3(x,y) (x+xdim3_advec_cell_kernel3_xdir*(y))
#define OPS_ACC4(x,y) (x+xdim4_advec_cell_kernel3_xdir*(y))
#define OPS_ACC5(x,y) (x+xdim5_advec_cell_kernel3_xdir*(y))
#define OPS_ACC6(x,y) (x+xdim6_advec_cell_kernel3_xdir*(y))
#define OPS_ACC7(x,y) (x+xdim7_advec_cell_kernel3_xdir*(y))

//user function
__device__

inline void advec_cell_kernel3_xdir_gpu( const double *vol_flux_x, const double *pre_vol, const int *xx,
                              const double *vertexdx,
                              const double *density1, const double *energy1 ,
                              double *mass_flux_x, double *ener_flux) {

  double sigmat, sigmav, sigmam, sigma3, sigma4;
  double diffuw, diffdw, limiter;
  double one_by_six = 1.0/6.0;

  int x_max=field.x_max;

  int upwind,donor,downwind,dif;





  if(vol_flux_x[OPS_ACC0(0,0)] > 0.0) {
    upwind   = -2;
    donor    = -1;
    downwind = 0;
    dif      = donor;
  }
  else if (xx[OPS_ACC2(1,0)] < x_max+2-2) {
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


  sigmat = fabs(vol_flux_x[OPS_ACC0(0,0)])/pre_vol[OPS_ACC1(donor,0)];
  sigma3 = (1.0 + sigmat)*(vertexdx[OPS_ACC3(0,0)]/vertexdx[OPS_ACC3(dif,0)]);
  sigma4 = 2.0 - sigmat;

  sigmav = sigmat;

  diffuw = density1[OPS_ACC4(donor,0)] - density1[OPS_ACC4(upwind,0)];
  diffdw = density1[OPS_ACC4(downwind,0)] - density1[OPS_ACC4(donor,0)];

  if( (diffuw*diffdw) > 0.0)
    limiter=(1.0 - sigmav) * SIGN(1.0 , diffdw) *
    MIN( MIN(fabs(diffuw), fabs(diffdw)),
    one_by_six * (sigma3*fabs(diffuw) + sigma4 * fabs(diffdw)));
  else
    limiter=0.0;

  mass_flux_x[OPS_ACC6(0,0)] = (vol_flux_x[OPS_ACC0(0,0)]) * ( density1[OPS_ACC4(donor,0)] + limiter );

  sigmam = fabs(mass_flux_x[OPS_ACC6(0,0)])/( density1[OPS_ACC4(donor,0)] * pre_vol[OPS_ACC1(donor,0)]);
  diffuw = energy1[OPS_ACC5(donor,0)] - energy1[OPS_ACC5(upwind,0)];
  diffdw = energy1[OPS_ACC5(downwind,0)] - energy1[OPS_ACC5(donor,0)];

  if( (diffuw*diffdw) > 0.0)
    limiter = (1.0 - sigmam) * SIGN(1.0,diffdw) *
    MIN( MIN(fabs(diffuw), fabs(diffdw)),
    one_by_six * (sigma3 * fabs(diffuw) + sigma4 * fabs(diffdw)));
  else
    limiter=0.0;

  ener_flux[OPS_ACC7(0,0)] = mass_flux_x[OPS_ACC6(0,0)] * ( energy1[OPS_ACC5(donor,0)] + limiter );
}



#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
#undef OPS_ACC7


__global__ void ops_advec_cell_kernel3_xdir(
const double* __restrict arg0,
const double* __restrict arg1,
const int* __restrict arg2,
const double* __restrict arg3,
const double* __restrict arg4,
const double* __restrict arg5,
double* __restrict arg6,
double* __restrict arg7,
int size0,
int size1 ){


  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1*1 + idx_y * 1*1 * xdim0_advec_cell_kernel3_xdir;
  arg1 += idx_x * 1*1 + idx_y * 1*1 * xdim1_advec_cell_kernel3_xdir;
  arg2 += idx_x * 1*1 + idx_y * 0*1 * xdim2_advec_cell_kernel3_xdir;
  arg3 += idx_x * 1*1 + idx_y * 0*1 * xdim3_advec_cell_kernel3_xdir;
  arg4 += idx_x * 1*1 + idx_y * 1*1 * xdim4_advec_cell_kernel3_xdir;
  arg5 += idx_x * 1*1 + idx_y * 1*1 * xdim5_advec_cell_kernel3_xdir;
  arg6 += idx_x * 1*1 + idx_y * 1*1 * xdim6_advec_cell_kernel3_xdir;
  arg7 += idx_x * 1*1 + idx_y * 1*1 * xdim7_advec_cell_kernel3_xdir;

  if (idx_x < size0 && idx_y < size1) {
    advec_cell_kernel3_xdir_gpu(arg0, arg1, arg2, arg3,
                   arg4, arg5, arg6, arg7);
  }

}

// host stub function
// host stub function
void ops_par_loop_advec_cell_kernel3_xdir_execute(ops_kernel_descriptor *desc) {
  #ifdef OPS_MPI
  ops_block block = desc->block;
  #endif
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

  //Timing
  double t1,t2,c1,c2;

  ops_arg args[8] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};


  #ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args,8,range,9)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(9,"advec_cell_kernel3_xdir");
    OPS_kernels[9].count++;
    ops_timers_core(&c1,&t1);
  }

  //compute locally allocated range for the sub-block
  int start[2];
  int end[2];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned) return;
  for ( int n=0; n<2; n++ ){
    start[n] = sb->decomp_disp[n];end[n] = sb->decomp_disp[n]+sb->decomp_size[n];
    if (start[n] >= range[2*n]) {
      start[n] = 0;
    }
    else {
      start[n] = range[2*n] - start[n];
    }
    if (sb->id_m[n]==MPI_PROC_NULL && range[2*n] < 0) start[n] = range[2*n];
    if (end[n] >= range[2*n+1]) {
      end[n] = range[2*n+1] - sb->decomp_disp[n];
    }
    else {
      end[n] = sb->decomp_size[n];
    }
    if (sb->id_p[n]==MPI_PROC_NULL && (range[2*n+1] > sb->decomp_disp[n]+sb->decomp_size[n]))
      end[n] += (range[2*n+1]-sb->decomp_disp[n]-sb->decomp_size[n]);
  }
  #else
  for ( int n=0; n<2; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);

  int xdim0 = args[0].dat->size[0];
  int xdim1 = args[1].dat->size[0];
  int xdim2 = args[2].dat->size[0];
  int xdim3 = args[3].dat->size[0];
  int xdim4 = args[4].dat->size[0];
  int xdim5 = args[5].dat->size[0];
  int xdim6 = args[6].dat->size[0];
  int xdim7 = args[7].dat->size[0];

  if (xdim0 != xdim0_advec_cell_kernel3_xdir_h || xdim1 != xdim1_advec_cell_kernel3_xdir_h || xdim2 != xdim2_advec_cell_kernel3_xdir_h || xdim3 != xdim3_advec_cell_kernel3_xdir_h || xdim4 != xdim4_advec_cell_kernel3_xdir_h || xdim5 != xdim5_advec_cell_kernel3_xdir_h || xdim6 != xdim6_advec_cell_kernel3_xdir_h || xdim7 != xdim7_advec_cell_kernel3_xdir_h) {
    cudaMemcpyToSymbolAsync( xdim0_advec_cell_kernel3_xdir, &xdim0, sizeof(int),0,cudaMemcpyHostToDevice,stream );
    xdim0_advec_cell_kernel3_xdir_h = xdim0;
    cudaMemcpyToSymbolAsync( xdim1_advec_cell_kernel3_xdir, &xdim1, sizeof(int),0,cudaMemcpyHostToDevice,stream );
    xdim1_advec_cell_kernel3_xdir_h = xdim1;
    cudaMemcpyToSymbolAsync( xdim2_advec_cell_kernel3_xdir, &xdim2, sizeof(int),0,cudaMemcpyHostToDevice,stream );
    xdim2_advec_cell_kernel3_xdir_h = xdim2;
    cudaMemcpyToSymbolAsync( xdim3_advec_cell_kernel3_xdir, &xdim3, sizeof(int),0,cudaMemcpyHostToDevice,stream );
    xdim3_advec_cell_kernel3_xdir_h = xdim3;
    cudaMemcpyToSymbolAsync( xdim4_advec_cell_kernel3_xdir, &xdim4, sizeof(int),0,cudaMemcpyHostToDevice,stream );
    xdim4_advec_cell_kernel3_xdir_h = xdim4;
    cudaMemcpyToSymbolAsync( xdim5_advec_cell_kernel3_xdir, &xdim5, sizeof(int),0,cudaMemcpyHostToDevice,stream );
    xdim5_advec_cell_kernel3_xdir_h = xdim5;
    cudaMemcpyToSymbolAsync( xdim6_advec_cell_kernel3_xdir, &xdim6, sizeof(int),0,cudaMemcpyHostToDevice,stream );
    xdim6_advec_cell_kernel3_xdir_h = xdim6;
    cudaMemcpyToSymbolAsync( xdim7_advec_cell_kernel3_xdir, &xdim7, sizeof(int),0,cudaMemcpyHostToDevice,stream );
    xdim7_advec_cell_kernel3_xdir_h = xdim7;
  }



  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, 1);
  dim3 tblock(OPS_block_size_x,OPS_block_size_y,1);



  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;
  int dat3 = args[3].dat->elem_size;
  int dat4 = args[4].dat->elem_size;
  int dat5 = args[5].dat->elem_size;
  int dat6 = args[6].dat->elem_size;
  int dat7 = args[7].dat->elem_size;

  char *p_a[8];

  //set up initial pointers
  int d_m[OPS_MAX_DIM];
  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d] + OPS_sub_dat_list[args[0].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[0].dat->d_m[d];
  #endif
  int base0 = dat0 * 1 *
  (start[0] * args[0].stencil->stride[0] - args[0].dat->base[0] - d_m[0]);
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    (start[1] * args[0].stencil->stride[1] - args[0].dat->base[1] - d_m[1]);
  p_a[0] = (char *)args[0].data_d + base0;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d] + OPS_sub_dat_list[args[1].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[1].dat->d_m[d];
  #endif
  int base1 = dat1 * 1 *
  (start[0] * args[1].stencil->stride[0] - args[1].dat->base[0] - d_m[0]);
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    (start[1] * args[1].stencil->stride[1] - args[1].dat->base[1] - d_m[1]);
  p_a[1] = (char *)args[1].data_d + base1;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d] + OPS_sub_dat_list[args[2].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[2].dat->d_m[d];
  #endif
  int base2 = dat2 * 1 *
  (start[0] * args[2].stencil->stride[0] - args[2].dat->base[0] - d_m[0]);
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    (start[1] * args[2].stencil->stride[1] - args[2].dat->base[1] - d_m[1]);
  p_a[2] = (char *)args[2].data_d + base2;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[3].dat->d_m[d] + OPS_sub_dat_list[args[3].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[3].dat->d_m[d];
  #endif
  int base3 = dat3 * 1 *
  (start[0] * args[3].stencil->stride[0] - args[3].dat->base[0] - d_m[0]);
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    (start[1] * args[3].stencil->stride[1] - args[3].dat->base[1] - d_m[1]);
  p_a[3] = (char *)args[3].data_d + base3;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[4].dat->d_m[d] + OPS_sub_dat_list[args[4].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[4].dat->d_m[d];
  #endif
  int base4 = dat4 * 1 *
  (start[0] * args[4].stencil->stride[0] - args[4].dat->base[0] - d_m[0]);
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    (start[1] * args[4].stencil->stride[1] - args[4].dat->base[1] - d_m[1]);
  p_a[4] = (char *)args[4].data_d + base4;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[5].dat->d_m[d] + OPS_sub_dat_list[args[5].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[5].dat->d_m[d];
  #endif
  int base5 = dat5 * 1 *
  (start[0] * args[5].stencil->stride[0] - args[5].dat->base[0] - d_m[0]);
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    (start[1] * args[5].stencil->stride[1] - args[5].dat->base[1] - d_m[1]);
  p_a[5] = (char *)args[5].data_d + base5;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[6].dat->d_m[d] + OPS_sub_dat_list[args[6].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[6].dat->d_m[d];
  #endif
  int base6 = dat6 * 1 *
  (start[0] * args[6].stencil->stride[0] - args[6].dat->base[0] - d_m[0]);
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    (start[1] * args[6].stencil->stride[1] - args[6].dat->base[1] - d_m[1]);
  p_a[6] = (char *)args[6].data_d + base6;

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[7].dat->d_m[d] + OPS_sub_dat_list[args[7].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[7].dat->d_m[d];
  #endif
  int base7 = dat7 * 1 *
  (start[0] * args[7].stencil->stride[0] - args[7].dat->base[0] - d_m[0]);
  base7 = base7+ dat7 *
    args[7].dat->size[0] *
    (start[1] * args[7].stencil->stride[1] - args[7].dat->base[1] - d_m[1]);
  p_a[7] = (char *)args[7].data_d + base7;


  ops_H_D_exchanges_device(args, 8);
  ops_halo_exchanges(args,8,range);

  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[9].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  ops_advec_cell_kernel3_xdir<<<grid, tblock, 0, stream >>> (  (double *)p_a[0], (double *)p_a[1],
           (int *)p_a[2], (double *)p_a[3],
           (double *)p_a[4], (double *)p_a[5],
           (double *)p_a[6], (double *)p_a[7],x_size, y_size);

  if (OPS_diags>1) {
    cutilSafeCall(cudaStreamSynchronize(stream));
    ops_timers_core(&c1,&t1);
    OPS_kernels[9].time += t1-t2;
  }

  ops_set_dirtybit_device(args, 8);
  ops_set_halo_dirtybit3(&args[6],range);
  ops_set_halo_dirtybit3(&args[7],range);

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_kernels[9].mpi_time += t2-t1;
    OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg6);
    OPS_kernels[9].transfer += ops_compute_transfer(dim, start, end, &arg7);
  }
}

void ops_par_loop_advec_cell_kernel3_xdir(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->index = 9;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 9;
  for ( int i=0; i<4; i++ ){
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
    ops_timing_realloc(9,"advec_cell_kernel3_xdir");
  }
  ops_enqueue_kernel(desc);
}
