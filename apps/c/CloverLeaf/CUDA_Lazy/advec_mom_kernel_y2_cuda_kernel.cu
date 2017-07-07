//
// auto-generated by ops.py
//
__constant__ int xdim0_advec_mom_kernel_y2;
int xdim0_advec_mom_kernel_y2_h = -1;
int ydim0_advec_mom_kernel_y2_h = -1;
__constant__ int xdim1_advec_mom_kernel_y2;
int xdim1_advec_mom_kernel_y2_h = -1;
int ydim1_advec_mom_kernel_y2_h = -1;
__constant__ int xdim2_advec_mom_kernel_y2;
int xdim2_advec_mom_kernel_y2_h = -1;
int ydim2_advec_mom_kernel_y2_h = -1;
__constant__ int xdim3_advec_mom_kernel_y2;
int xdim3_advec_mom_kernel_y2_h = -1;
int ydim3_advec_mom_kernel_y2_h = -1;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3


#define OPS_ACC0(x,y) (x+xdim0_advec_mom_kernel_y2*(y))
#define OPS_ACC1(x,y) (x+xdim1_advec_mom_kernel_y2*(y))
#define OPS_ACC2(x,y) (x+xdim2_advec_mom_kernel_y2*(y))
#define OPS_ACC3(x,y) (x+xdim3_advec_mom_kernel_y2*(y))

//user function
__device__

inline void advec_mom_kernel_y2_gpu( double *pre_vol, double *post_vol,
                          const double *volume,
                          const double *vol_flux_x) {

  post_vol[OPS_ACC1(0,0)]  = volume[OPS_ACC2(0,0)] ;
  pre_vol[OPS_ACC0(0,0)]   = post_vol[OPS_ACC1(0,0)]  + vol_flux_x[OPS_ACC3(1,0)] - vol_flux_x[OPS_ACC3(0,0)];

}



#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3


__global__ void ops_advec_mom_kernel_y2(
double* __restrict arg0,
double* __restrict arg1,
const double* __restrict arg2,
const double* __restrict arg3,
int size0,
int size1 ){


  int idx_y = blockDim.y * blockIdx.y + threadIdx.y;
  int idx_x = blockDim.x * blockIdx.x + threadIdx.x;

  arg0 += idx_x * 1*1 + idx_y * 1*1 * xdim0_advec_mom_kernel_y2;
  arg1 += idx_x * 1*1 + idx_y * 1*1 * xdim1_advec_mom_kernel_y2;
  arg2 += idx_x * 1*1 + idx_y * 1*1 * xdim2_advec_mom_kernel_y2;
  arg3 += idx_x * 1*1 + idx_y * 1*1 * xdim3_advec_mom_kernel_y2;

  if (idx_x < size0 && idx_y < size1) {
    advec_mom_kernel_y2_gpu(arg0, arg1, arg2, arg3);
  }

}

// host stub function
// host stub function
void ops_par_loop_advec_mom_kernel_y2_execute(ops_kernel_descriptor *desc) {
  #ifdef OPS_MPI
  ops_block block = desc->block;
  #endif
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
  if (!ops_checkpointing_before(args,4,range,18)) return;
  #endif

  if (OPS_diags > 1) {
    ops_timing_realloc(18,"advec_mom_kernel_y2");
    OPS_kernels[18].count++;
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

  if (xdim0 != xdim0_advec_mom_kernel_y2_h || xdim1 != xdim1_advec_mom_kernel_y2_h || xdim2 != xdim2_advec_mom_kernel_y2_h || xdim3 != xdim3_advec_mom_kernel_y2_h) {
    cudaMemcpyToSymbolAsync( xdim0_advec_mom_kernel_y2, &xdim0, sizeof(int),0,cudaMemcpyHostToDevice,stream );
    xdim0_advec_mom_kernel_y2_h = xdim0;
    cudaMemcpyToSymbolAsync( xdim1_advec_mom_kernel_y2, &xdim1, sizeof(int),0,cudaMemcpyHostToDevice,stream );
    xdim1_advec_mom_kernel_y2_h = xdim1;
    cudaMemcpyToSymbolAsync( xdim2_advec_mom_kernel_y2, &xdim2, sizeof(int),0,cudaMemcpyHostToDevice,stream );
    xdim2_advec_mom_kernel_y2_h = xdim2;
    cudaMemcpyToSymbolAsync( xdim3_advec_mom_kernel_y2, &xdim3, sizeof(int),0,cudaMemcpyHostToDevice,stream );
    xdim3_advec_mom_kernel_y2_h = xdim3;
  }



  dim3 grid( (x_size-1)/OPS_block_size_x+ 1, (y_size-1)/OPS_block_size_y + 1, 1);
  dim3 tblock(OPS_block_size_x,OPS_block_size_y,1);



  int dat0 = args[0].dat->elem_size;
  int dat1 = args[1].dat->elem_size;
  int dat2 = args[2].dat->elem_size;
  int dat3 = args[3].dat->elem_size;

  char *p_a[4];

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


  ops_H_D_exchanges_device(args, 4);
  ops_halo_exchanges(args,4,range);

  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
    OPS_kernels[18].mpi_time += t2-t1;
  }


  //call kernel wrapper function, passing in pointers to data
  ops_advec_mom_kernel_y2<<<grid, tblock, 0, stream >>> (  (double *)p_a[0], (double *)p_a[1],
           (double *)p_a[2], (double *)p_a[3],x_size, y_size);

  if (OPS_diags>1) {
    cutilSafeCall(cudaStreamSynchronize(stream));
    ops_timers_core(&c1,&t1);
    OPS_kernels[18].time += t1-t2;
  }

  ops_set_dirtybit_device(args, 4);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
    OPS_kernels[18].mpi_time += t2-t1;
    OPS_kernels[18].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[18].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[18].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[18].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}

void ops_par_loop_advec_mom_kernel_y2(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->index = 18;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 18;
  for ( int i=0; i<4; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 4;
  desc->args = (ops_arg*)malloc(4*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->function = ops_par_loop_advec_mom_kernel_y2_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(18,"advec_mom_kernel_y2");
  }
  ops_enqueue_kernel(desc);
}
