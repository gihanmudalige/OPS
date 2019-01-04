//
// auto-generated by ops.py
//

#define OPS_GPU

extern int xdim0_advec_mom_kernel1_x_nonvector;
int xdim0_advec_mom_kernel1_x_nonvector_h = -1;
extern int ydim0_advec_mom_kernel1_x_nonvector;
int ydim0_advec_mom_kernel1_x_nonvector_h = -1;
extern int xdim1_advec_mom_kernel1_x_nonvector;
int xdim1_advec_mom_kernel1_x_nonvector_h = -1;
extern int ydim1_advec_mom_kernel1_x_nonvector;
int ydim1_advec_mom_kernel1_x_nonvector_h = -1;
extern int xdim2_advec_mom_kernel1_x_nonvector;
int xdim2_advec_mom_kernel1_x_nonvector_h = -1;
extern int ydim2_advec_mom_kernel1_x_nonvector;
int ydim2_advec_mom_kernel1_x_nonvector_h = -1;
extern int xdim3_advec_mom_kernel1_x_nonvector;
int xdim3_advec_mom_kernel1_x_nonvector_h = -1;
extern int ydim3_advec_mom_kernel1_x_nonvector;
int ydim3_advec_mom_kernel1_x_nonvector_h = -1;
extern int xdim4_advec_mom_kernel1_x_nonvector;
int xdim4_advec_mom_kernel1_x_nonvector_h = -1;
extern int ydim4_advec_mom_kernel1_x_nonvector;
int ydim4_advec_mom_kernel1_x_nonvector_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void advec_mom_kernel1_x_nonvector_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  int x_size, int y_size, int z_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_advec_mom_kernel1_x_nonvector(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4) {

  //Timing
  double t1,t2,c1,c2;
  ops_arg args[5] = { arg0, arg1, arg2, arg3, arg4};


  #ifdef CHECKPOINTING
<<<<<<< HEAD
  if (!ops_checkpointing_before(args, 5, range, 27))
=======
  if (!ops_checkpointing_before(args, 5, range, 129))
>>>>>>> 3f8b285... Regenerating files to resolve conflicts
    return;
  #endif

  if (OPS_diags > 1) {
<<<<<<< HEAD
    ops_timing_realloc(27, "advec_mom_kernel1_x_nonvector");
    OPS_kernels[27].count++;
=======
    ops_timing_realloc(129, "advec_mom_kernel1_x_nonvector");
    OPS_kernels[129].count++;
>>>>>>> 3f8b285... Regenerating files to resolve conflicts
    ops_timers_core(&c1,&t1);
  }

  //compute localy allocated range for the sub-block

  int start[3];
  int end[3];
  #ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned) return;
  for ( int n=0; n<3; n++ ){
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
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #endif

  int x_size = MAX(0,end[0]-start[0]);
  int y_size = MAX(0,end[1]-start[1]);
  int z_size = MAX(0,end[2]-start[2]);


  xdim0 = args[0].dat->size[0];
  ydim0 = args[0].dat->size[1];
  xdim1 = args[1].dat->size[0];
  ydim1 = args[1].dat->size[1];
  xdim2 = args[2].dat->size[0];
  ydim2 = args[2].dat->size[1];
  xdim3 = args[3].dat->size[0];
  ydim3 = args[3].dat->size[1];
  xdim4 = args[4].dat->size[0];
  ydim4 = args[4].dat->size[1];
  if (xdim0 != xdim0_advec_mom_kernel1_x_nonvector_h || ydim0 != ydim0_advec_mom_kernel1_x_nonvector_h || xdim1 != xdim1_advec_mom_kernel1_x_nonvector_h || ydim1 != ydim1_advec_mom_kernel1_x_nonvector_h || xdim2 != xdim2_advec_mom_kernel1_x_nonvector_h || ydim2 != ydim2_advec_mom_kernel1_x_nonvector_h || xdim3 != xdim3_advec_mom_kernel1_x_nonvector_h || ydim3 != ydim3_advec_mom_kernel1_x_nonvector_h || xdim4 != xdim4_advec_mom_kernel1_x_nonvector_h || ydim4 != ydim4_advec_mom_kernel1_x_nonvector_h) {
    xdim0_advec_mom_kernel1_x_nonvector = xdim0;
    xdim0_advec_mom_kernel1_x_nonvector_h = xdim0;
    ydim0_advec_mom_kernel1_x_nonvector = ydim0;
    ydim0_advec_mom_kernel1_x_nonvector_h = ydim0;
    xdim1_advec_mom_kernel1_x_nonvector = xdim1;
    xdim1_advec_mom_kernel1_x_nonvector_h = xdim1;
    ydim1_advec_mom_kernel1_x_nonvector = ydim1;
    ydim1_advec_mom_kernel1_x_nonvector_h = ydim1;
    xdim2_advec_mom_kernel1_x_nonvector = xdim2;
    xdim2_advec_mom_kernel1_x_nonvector_h = xdim2;
    ydim2_advec_mom_kernel1_x_nonvector = ydim2;
    ydim2_advec_mom_kernel1_x_nonvector_h = ydim2;
    xdim3_advec_mom_kernel1_x_nonvector = xdim3;
    xdim3_advec_mom_kernel1_x_nonvector_h = xdim3;
    ydim3_advec_mom_kernel1_x_nonvector = ydim3;
    ydim3_advec_mom_kernel1_x_nonvector_h = ydim3;
    xdim4_advec_mom_kernel1_x_nonvector = xdim4;
    xdim4_advec_mom_kernel1_x_nonvector_h = xdim4;
    ydim4_advec_mom_kernel1_x_nonvector = ydim4;
    ydim4_advec_mom_kernel1_x_nonvector_h = ydim4;
  }



  //set up initial pointers
  int base0 = args[0].dat->base_offset + (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) * start[0] * args[0].stencil->stride[0];
  base0 = base0 + (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    start[1] * args[0].stencil->stride[1];
  base0 = base0 + (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    start[2] * args[0].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a0 = (double *)((char *)args[0].data_d + base0);
  #else
  double *p_a0 = (double *)((char *)args[0].data + base0);
  #endif

  int base1 = args[1].dat->base_offset + (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) * start[0] * args[1].stencil->stride[0];
  base1 = base1 + (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    start[1] * args[1].stencil->stride[1];
  base1 = base1 + (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    start[2] * args[1].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a1 = (double *)((char *)args[1].data_d + base1);
  #else
  double *p_a1 = (double *)((char *)args[1].data + base1);
  #endif

  int base2 = args[2].dat->base_offset + (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) * start[0] * args[2].stencil->stride[0];
  base2 = base2 + (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    start[1] * args[2].stencil->stride[1];
  base2 = base2 + (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    start[2] * args[2].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a2 = (double *)((char *)args[2].data_d + base2);
  #else
  double *p_a2 = (double *)((char *)args[2].data + base2);
  #endif

  int base3 = args[3].dat->base_offset + (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) * start[0] * args[3].stencil->stride[0];
  base3 = base3 + (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    start[1] * args[3].stencil->stride[1];
  base3 = base3 + (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
    args[3].dat->size[0] *
    args[3].dat->size[1] *
    start[2] * args[3].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a3 = (double *)((char *)args[3].data_d + base3);
  #else
  double *p_a3 = (double *)((char *)args[3].data + base3);
  #endif

  int base4 = args[4].dat->base_offset + (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) * start[0] * args[4].stencil->stride[0];
  base4 = base4 + (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    start[1] * args[4].stencil->stride[1];
  base4 = base4 + (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
    args[4].dat->size[0] *
    args[4].dat->size[1] *
    start[2] * args[4].stencil->stride[2];
  #ifdef OPS_GPU
  double *p_a4 = (double *)((char *)args[4].data_d + base4);
  #else
  double *p_a4 = (double *)((char *)args[4].data + base4);
  #endif


  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 5);
  #else
  ops_H_D_exchanges_host(args, 5);
  #endif
  ops_halo_exchanges(args,5,range);

  #ifdef OPS_GPU
  ops_H_D_exchanges_device(args, 5);
  #else
  ops_H_D_exchanges_host(args, 5);
  #endif
  if (OPS_diags > 1) {
    ops_timers_core(&c2,&t2);
<<<<<<< HEAD
    OPS_kernels[27].mpi_time += t2 - t1;
=======
    OPS_kernels[129].mpi_time += t2 - t1;
>>>>>>> 3f8b285... Regenerating files to resolve conflicts
  }

  advec_mom_kernel1_x_nonvector_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    p_a4,
    x_size, y_size, z_size);

  if (OPS_diags > 1) {
    ops_timers_core(&c1,&t1);
<<<<<<< HEAD
    OPS_kernels[27].time += t1 - t2;
=======
    OPS_kernels[129].time += t1 - t2;
>>>>>>> 3f8b285... Regenerating files to resolve conflicts
  }
  #ifdef OPS_GPU
  ops_set_dirtybit_device(args, 5);
  #else
  ops_set_dirtybit_host(args, 5);
  #endif
  ops_set_halo_dirtybit3(&args[2],range);

  if (OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&c2,&t2);
<<<<<<< HEAD
    OPS_kernels[27].mpi_time += t2 - t1;
    OPS_kernels[27].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[27].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[27].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[27].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[27].transfer += ops_compute_transfer(dim, start, end, &arg4);
=======
    OPS_kernels[129].mpi_time += t2 - t1;
    OPS_kernels[129].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[129].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[129].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[129].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[129].transfer += ops_compute_transfer(dim, start, end, &arg4);
>>>>>>> 3f8b285... Regenerating files to resolve conflicts
  }
}
