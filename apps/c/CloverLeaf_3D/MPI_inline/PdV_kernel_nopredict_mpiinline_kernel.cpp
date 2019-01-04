//
// auto-generated by ops.py
//

extern int xdim0_PdV_kernel_nopredict;
int xdim0_PdV_kernel_nopredict_h = -1;
extern int ydim0_PdV_kernel_nopredict;
int ydim0_PdV_kernel_nopredict_h = -1;
extern int xdim1_PdV_kernel_nopredict;
int xdim1_PdV_kernel_nopredict_h = -1;
extern int ydim1_PdV_kernel_nopredict;
int ydim1_PdV_kernel_nopredict_h = -1;
extern int xdim2_PdV_kernel_nopredict;
int xdim2_PdV_kernel_nopredict_h = -1;
extern int ydim2_PdV_kernel_nopredict;
int ydim2_PdV_kernel_nopredict_h = -1;
extern int xdim3_PdV_kernel_nopredict;
int xdim3_PdV_kernel_nopredict_h = -1;
extern int ydim3_PdV_kernel_nopredict;
int ydim3_PdV_kernel_nopredict_h = -1;
extern int xdim4_PdV_kernel_nopredict;
int xdim4_PdV_kernel_nopredict_h = -1;
extern int ydim4_PdV_kernel_nopredict;
int ydim4_PdV_kernel_nopredict_h = -1;
extern int xdim5_PdV_kernel_nopredict;
int xdim5_PdV_kernel_nopredict_h = -1;
extern int ydim5_PdV_kernel_nopredict;
int ydim5_PdV_kernel_nopredict_h = -1;
extern int xdim6_PdV_kernel_nopredict;
int xdim6_PdV_kernel_nopredict_h = -1;
extern int ydim6_PdV_kernel_nopredict;
int ydim6_PdV_kernel_nopredict_h = -1;
extern int xdim7_PdV_kernel_nopredict;
int xdim7_PdV_kernel_nopredict_h = -1;
extern int ydim7_PdV_kernel_nopredict;
int ydim7_PdV_kernel_nopredict_h = -1;
extern int xdim8_PdV_kernel_nopredict;
int xdim8_PdV_kernel_nopredict_h = -1;
extern int ydim8_PdV_kernel_nopredict;
int ydim8_PdV_kernel_nopredict_h = -1;
extern int xdim9_PdV_kernel_nopredict;
int xdim9_PdV_kernel_nopredict_h = -1;
extern int ydim9_PdV_kernel_nopredict;
int ydim9_PdV_kernel_nopredict_h = -1;
extern int xdim10_PdV_kernel_nopredict;
int xdim10_PdV_kernel_nopredict_h = -1;
extern int ydim10_PdV_kernel_nopredict;
int ydim10_PdV_kernel_nopredict_h = -1;
extern int xdim11_PdV_kernel_nopredict;
int xdim11_PdV_kernel_nopredict_h = -1;
extern int ydim11_PdV_kernel_nopredict;
int ydim11_PdV_kernel_nopredict_h = -1;
extern int xdim12_PdV_kernel_nopredict;
int xdim12_PdV_kernel_nopredict_h = -1;
extern int ydim12_PdV_kernel_nopredict;
int ydim12_PdV_kernel_nopredict_h = -1;
extern int xdim13_PdV_kernel_nopredict;
int xdim13_PdV_kernel_nopredict_h = -1;
extern int ydim13_PdV_kernel_nopredict;
int ydim13_PdV_kernel_nopredict_h = -1;
extern int xdim14_PdV_kernel_nopredict;
int xdim14_PdV_kernel_nopredict_h = -1;
extern int ydim14_PdV_kernel_nopredict;
int ydim14_PdV_kernel_nopredict_h = -1;
extern int xdim15_PdV_kernel_nopredict;
int xdim15_PdV_kernel_nopredict_h = -1;
extern int ydim15_PdV_kernel_nopredict;
int ydim15_PdV_kernel_nopredict_h = -1;
extern int xdim16_PdV_kernel_nopredict;
int xdim16_PdV_kernel_nopredict_h = -1;
extern int ydim16_PdV_kernel_nopredict;
int ydim16_PdV_kernel_nopredict_h = -1;

#ifdef __cplusplus
extern "C" {
#endif
void PdV_kernel_nopredict_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  double *p_a7,
  double *p_a8,
  double *p_a9,
  double *p_a10,
  double *p_a11,
  double *p_a12,
  double *p_a13,
  double *p_a14,
  double *p_a15,
  double *p_a16,
  int x_size, int y_size, int z_size);

#ifdef __cplusplus
}
#endif

// host stub function
void ops_par_loop_PdV_kernel_nopredict(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3, ops_arg arg4, ops_arg arg5, ops_arg arg6, ops_arg arg7, ops_arg arg8, ops_arg arg9, ops_arg arg10, ops_arg arg11, ops_arg arg12, ops_arg arg13, ops_arg arg14, ops_arg arg15, ops_arg arg16) {

  ops_arg args[17] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16};


  #ifdef CHECKPOINTING
<<<<<<< HEAD
  if (!ops_checkpointing_before(args, 17, range, 5))
    return;
  #endif

  ops_timing_realloc(5, "PdV_kernel_nopredict");
  OPS_kernels[5].count++;
=======
  if (!ops_checkpointing_before(args, 17, range, 103))
    return;
  #endif

  ops_timing_realloc(103, "PdV_kernel_nopredict");
  OPS_kernels[103].count++;
>>>>>>> 3f8b285... Regenerating files to resolve conflicts

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
  xdim5 = args[5].dat->size[0];
  ydim5 = args[5].dat->size[1];
  xdim6 = args[6].dat->size[0];
  ydim6 = args[6].dat->size[1];
  xdim7 = args[7].dat->size[0];
  ydim7 = args[7].dat->size[1];
  xdim8 = args[8].dat->size[0];
  ydim8 = args[8].dat->size[1];
  xdim9 = args[9].dat->size[0];
  ydim9 = args[9].dat->size[1];
  xdim10 = args[10].dat->size[0];
  ydim10 = args[10].dat->size[1];
  xdim11 = args[11].dat->size[0];
  ydim11 = args[11].dat->size[1];
  xdim12 = args[12].dat->size[0];
  ydim12 = args[12].dat->size[1];
  xdim13 = args[13].dat->size[0];
  ydim13 = args[13].dat->size[1];
  xdim14 = args[14].dat->size[0];
  ydim14 = args[14].dat->size[1];
  xdim15 = args[15].dat->size[0];
  ydim15 = args[15].dat->size[1];
  xdim16 = args[16].dat->size[0];
  ydim16 = args[16].dat->size[1];

  //Timing
  double t1,t2,c1,c2;
  ops_timers_core(&c2,&t2);

  if (xdim0 != xdim0_PdV_kernel_nopredict_h || ydim0 != ydim0_PdV_kernel_nopredict_h || xdim1 != xdim1_PdV_kernel_nopredict_h || ydim1 != ydim1_PdV_kernel_nopredict_h || xdim2 != xdim2_PdV_kernel_nopredict_h || ydim2 != ydim2_PdV_kernel_nopredict_h || xdim3 != xdim3_PdV_kernel_nopredict_h || ydim3 != ydim3_PdV_kernel_nopredict_h || xdim4 != xdim4_PdV_kernel_nopredict_h || ydim4 != ydim4_PdV_kernel_nopredict_h || xdim5 != xdim5_PdV_kernel_nopredict_h || ydim5 != ydim5_PdV_kernel_nopredict_h || xdim6 != xdim6_PdV_kernel_nopredict_h || ydim6 != ydim6_PdV_kernel_nopredict_h || xdim7 != xdim7_PdV_kernel_nopredict_h || ydim7 != ydim7_PdV_kernel_nopredict_h || xdim8 != xdim8_PdV_kernel_nopredict_h || ydim8 != ydim8_PdV_kernel_nopredict_h || xdim9 != xdim9_PdV_kernel_nopredict_h || ydim9 != ydim9_PdV_kernel_nopredict_h || xdim10 != xdim10_PdV_kernel_nopredict_h || ydim10 != ydim10_PdV_kernel_nopredict_h || xdim11 != xdim11_PdV_kernel_nopredict_h || ydim11 != ydim11_PdV_kernel_nopredict_h || xdim12 != xdim12_PdV_kernel_nopredict_h || ydim12 != ydim12_PdV_kernel_nopredict_h || xdim13 != xdim13_PdV_kernel_nopredict_h || ydim13 != ydim13_PdV_kernel_nopredict_h || xdim14 != xdim14_PdV_kernel_nopredict_h || ydim14 != ydim14_PdV_kernel_nopredict_h || xdim15 != xdim15_PdV_kernel_nopredict_h || ydim15 != ydim15_PdV_kernel_nopredict_h || xdim16 != xdim16_PdV_kernel_nopredict_h || ydim16 != ydim16_PdV_kernel_nopredict_h) {
    xdim0_PdV_kernel_nopredict = xdim0;
    xdim0_PdV_kernel_nopredict_h = xdim0;
    ydim0_PdV_kernel_nopredict = ydim0;
    ydim0_PdV_kernel_nopredict_h = ydim0;
    xdim1_PdV_kernel_nopredict = xdim1;
    xdim1_PdV_kernel_nopredict_h = xdim1;
    ydim1_PdV_kernel_nopredict = ydim1;
    ydim1_PdV_kernel_nopredict_h = ydim1;
    xdim2_PdV_kernel_nopredict = xdim2;
    xdim2_PdV_kernel_nopredict_h = xdim2;
    ydim2_PdV_kernel_nopredict = ydim2;
    ydim2_PdV_kernel_nopredict_h = ydim2;
    xdim3_PdV_kernel_nopredict = xdim3;
    xdim3_PdV_kernel_nopredict_h = xdim3;
    ydim3_PdV_kernel_nopredict = ydim3;
    ydim3_PdV_kernel_nopredict_h = ydim3;
    xdim4_PdV_kernel_nopredict = xdim4;
    xdim4_PdV_kernel_nopredict_h = xdim4;
    ydim4_PdV_kernel_nopredict = ydim4;
    ydim4_PdV_kernel_nopredict_h = ydim4;
    xdim5_PdV_kernel_nopredict = xdim5;
    xdim5_PdV_kernel_nopredict_h = xdim5;
    ydim5_PdV_kernel_nopredict = ydim5;
    ydim5_PdV_kernel_nopredict_h = ydim5;
    xdim6_PdV_kernel_nopredict = xdim6;
    xdim6_PdV_kernel_nopredict_h = xdim6;
    ydim6_PdV_kernel_nopredict = ydim6;
    ydim6_PdV_kernel_nopredict_h = ydim6;
    xdim7_PdV_kernel_nopredict = xdim7;
    xdim7_PdV_kernel_nopredict_h = xdim7;
    ydim7_PdV_kernel_nopredict = ydim7;
    ydim7_PdV_kernel_nopredict_h = ydim7;
    xdim8_PdV_kernel_nopredict = xdim8;
    xdim8_PdV_kernel_nopredict_h = xdim8;
    ydim8_PdV_kernel_nopredict = ydim8;
    ydim8_PdV_kernel_nopredict_h = ydim8;
    xdim9_PdV_kernel_nopredict = xdim9;
    xdim9_PdV_kernel_nopredict_h = xdim9;
    ydim9_PdV_kernel_nopredict = ydim9;
    ydim9_PdV_kernel_nopredict_h = ydim9;
    xdim10_PdV_kernel_nopredict = xdim10;
    xdim10_PdV_kernel_nopredict_h = xdim10;
    ydim10_PdV_kernel_nopredict = ydim10;
    ydim10_PdV_kernel_nopredict_h = ydim10;
    xdim11_PdV_kernel_nopredict = xdim11;
    xdim11_PdV_kernel_nopredict_h = xdim11;
    ydim11_PdV_kernel_nopredict = ydim11;
    ydim11_PdV_kernel_nopredict_h = ydim11;
    xdim12_PdV_kernel_nopredict = xdim12;
    xdim12_PdV_kernel_nopredict_h = xdim12;
    ydim12_PdV_kernel_nopredict = ydim12;
    ydim12_PdV_kernel_nopredict_h = ydim12;
    xdim13_PdV_kernel_nopredict = xdim13;
    xdim13_PdV_kernel_nopredict_h = xdim13;
    ydim13_PdV_kernel_nopredict = ydim13;
    ydim13_PdV_kernel_nopredict_h = ydim13;
    xdim14_PdV_kernel_nopredict = xdim14;
    xdim14_PdV_kernel_nopredict_h = xdim14;
    ydim14_PdV_kernel_nopredict = ydim14;
    ydim14_PdV_kernel_nopredict_h = ydim14;
    xdim15_PdV_kernel_nopredict = xdim15;
    xdim15_PdV_kernel_nopredict_h = xdim15;
    ydim15_PdV_kernel_nopredict = ydim15;
    ydim15_PdV_kernel_nopredict_h = ydim15;
    xdim16_PdV_kernel_nopredict = xdim16;
    xdim16_PdV_kernel_nopredict_h = xdim16;
    ydim16_PdV_kernel_nopredict = ydim16;
    ydim16_PdV_kernel_nopredict_h = ydim16;
  }

  int dat0 = (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  int dat1 = (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  int dat2 = (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);
  int dat3 = (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);
  int dat4 = (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size);
  int dat5 = (OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size);
  int dat6 = (OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size);
  int dat7 = (OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size);
  int dat8 = (OPS_soa ? args[8].dat->type_size : args[8].dat->elem_size);
  int dat9 = (OPS_soa ? args[9].dat->type_size : args[9].dat->elem_size);
  int dat10 = (OPS_soa ? args[10].dat->type_size : args[10].dat->elem_size);
  int dat11 = (OPS_soa ? args[11].dat->type_size : args[11].dat->elem_size);
  int dat12 = (OPS_soa ? args[12].dat->type_size : args[12].dat->elem_size);
  int dat13 = (OPS_soa ? args[13].dat->type_size : args[13].dat->elem_size);
  int dat14 = (OPS_soa ? args[14].dat->type_size : args[14].dat->elem_size);
  int dat15 = (OPS_soa ? args[15].dat->type_size : args[15].dat->elem_size);
  int dat16 = (OPS_soa ? args[16].dat->type_size : args[16].dat->elem_size);


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
  base0 = base0+ dat0 *
    args[0].dat->size[0] *
    args[0].dat->size[1] *
    (start[2] * args[0].stencil->stride[2] - args[0].dat->base[2] - d_m[2]);
  double *p_a0 = (double *)((char *)args[0].data + base0);

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
  base1 = base1+ dat1 *
    args[1].dat->size[0] *
    args[1].dat->size[1] *
    (start[2] * args[1].stencil->stride[2] - args[1].dat->base[2] - d_m[2]);
  double *p_a1 = (double *)((char *)args[1].data + base1);

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
  base2 = base2+ dat2 *
    args[2].dat->size[0] *
    args[2].dat->size[1] *
    (start[2] * args[2].stencil->stride[2] - args[2].dat->base[2] - d_m[2]);
  double *p_a2 = (double *)((char *)args[2].data + base2);

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
  base3 = base3+ dat3 *
    args[3].dat->size[0] *
    args[3].dat->size[1] *
    (start[2] * args[3].stencil->stride[2] - args[3].dat->base[2] - d_m[2]);
  double *p_a3 = (double *)((char *)args[3].data + base3);

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
  base4 = base4+ dat4 *
    args[4].dat->size[0] *
    args[4].dat->size[1] *
    (start[2] * args[4].stencil->stride[2] - args[4].dat->base[2] - d_m[2]);
  double *p_a4 = (double *)((char *)args[4].data + base4);

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
  base5 = base5+ dat5 *
    args[5].dat->size[0] *
    args[5].dat->size[1] *
    (start[2] * args[5].stencil->stride[2] - args[5].dat->base[2] - d_m[2]);
  double *p_a5 = (double *)((char *)args[5].data + base5);

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
  base6 = base6+ dat6 *
    args[6].dat->size[0] *
    args[6].dat->size[1] *
    (start[2] * args[6].stencil->stride[2] - args[6].dat->base[2] - d_m[2]);
  double *p_a6 = (double *)((char *)args[6].data + base6);

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
  base7 = base7+ dat7 *
    args[7].dat->size[0] *
    args[7].dat->size[1] *
    (start[2] * args[7].stencil->stride[2] - args[7].dat->base[2] - d_m[2]);
  double *p_a7 = (double *)((char *)args[7].data + base7);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[8].dat->d_m[d] + OPS_sub_dat_list[args[8].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[8].dat->d_m[d];
  #endif
  int base8 = dat8 * 1 * 
    (start[0] * args[8].stencil->stride[0] - args[8].dat->base[0] - d_m[0]);
  base8 = base8+ dat8 *
    args[8].dat->size[0] *
    (start[1] * args[8].stencil->stride[1] - args[8].dat->base[1] - d_m[1]);
  base8 = base8+ dat8 *
    args[8].dat->size[0] *
    args[8].dat->size[1] *
    (start[2] * args[8].stencil->stride[2] - args[8].dat->base[2] - d_m[2]);
  double *p_a8 = (double *)((char *)args[8].data + base8);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[9].dat->d_m[d] + OPS_sub_dat_list[args[9].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[9].dat->d_m[d];
  #endif
  int base9 = dat9 * 1 * 
    (start[0] * args[9].stencil->stride[0] - args[9].dat->base[0] - d_m[0]);
  base9 = base9+ dat9 *
    args[9].dat->size[0] *
    (start[1] * args[9].stencil->stride[1] - args[9].dat->base[1] - d_m[1]);
  base9 = base9+ dat9 *
    args[9].dat->size[0] *
    args[9].dat->size[1] *
    (start[2] * args[9].stencil->stride[2] - args[9].dat->base[2] - d_m[2]);
  double *p_a9 = (double *)((char *)args[9].data + base9);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[10].dat->d_m[d] + OPS_sub_dat_list[args[10].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[10].dat->d_m[d];
  #endif
  int base10 = dat10 * 1 * 
    (start[0] * args[10].stencil->stride[0] - args[10].dat->base[0] - d_m[0]);
  base10 = base10+ dat10 *
    args[10].dat->size[0] *
    (start[1] * args[10].stencil->stride[1] - args[10].dat->base[1] - d_m[1]);
  base10 = base10+ dat10 *
    args[10].dat->size[0] *
    args[10].dat->size[1] *
    (start[2] * args[10].stencil->stride[2] - args[10].dat->base[2] - d_m[2]);
  double *p_a10 = (double *)((char *)args[10].data + base10);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[11].dat->d_m[d] + OPS_sub_dat_list[args[11].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[11].dat->d_m[d];
  #endif
  int base11 = dat11 * 1 * 
    (start[0] * args[11].stencil->stride[0] - args[11].dat->base[0] - d_m[0]);
  base11 = base11+ dat11 *
    args[11].dat->size[0] *
    (start[1] * args[11].stencil->stride[1] - args[11].dat->base[1] - d_m[1]);
  base11 = base11+ dat11 *
    args[11].dat->size[0] *
    args[11].dat->size[1] *
    (start[2] * args[11].stencil->stride[2] - args[11].dat->base[2] - d_m[2]);
  double *p_a11 = (double *)((char *)args[11].data + base11);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[12].dat->d_m[d] + OPS_sub_dat_list[args[12].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[12].dat->d_m[d];
  #endif
  int base12 = dat12 * 1 * 
    (start[0] * args[12].stencil->stride[0] - args[12].dat->base[0] - d_m[0]);
  base12 = base12+ dat12 *
    args[12].dat->size[0] *
    (start[1] * args[12].stencil->stride[1] - args[12].dat->base[1] - d_m[1]);
  base12 = base12+ dat12 *
    args[12].dat->size[0] *
    args[12].dat->size[1] *
    (start[2] * args[12].stencil->stride[2] - args[12].dat->base[2] - d_m[2]);
  double *p_a12 = (double *)((char *)args[12].data + base12);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[13].dat->d_m[d] + OPS_sub_dat_list[args[13].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[13].dat->d_m[d];
  #endif
  int base13 = dat13 * 1 * 
    (start[0] * args[13].stencil->stride[0] - args[13].dat->base[0] - d_m[0]);
  base13 = base13+ dat13 *
    args[13].dat->size[0] *
    (start[1] * args[13].stencil->stride[1] - args[13].dat->base[1] - d_m[1]);
  base13 = base13+ dat13 *
    args[13].dat->size[0] *
    args[13].dat->size[1] *
    (start[2] * args[13].stencil->stride[2] - args[13].dat->base[2] - d_m[2]);
  double *p_a13 = (double *)((char *)args[13].data + base13);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[14].dat->d_m[d] + OPS_sub_dat_list[args[14].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[14].dat->d_m[d];
  #endif
  int base14 = dat14 * 1 * 
    (start[0] * args[14].stencil->stride[0] - args[14].dat->base[0] - d_m[0]);
  base14 = base14+ dat14 *
    args[14].dat->size[0] *
    (start[1] * args[14].stencil->stride[1] - args[14].dat->base[1] - d_m[1]);
  base14 = base14+ dat14 *
    args[14].dat->size[0] *
    args[14].dat->size[1] *
    (start[2] * args[14].stencil->stride[2] - args[14].dat->base[2] - d_m[2]);
  double *p_a14 = (double *)((char *)args[14].data + base14);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[15].dat->d_m[d] + OPS_sub_dat_list[args[15].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[15].dat->d_m[d];
  #endif
  int base15 = dat15 * 1 * 
    (start[0] * args[15].stencil->stride[0] - args[15].dat->base[0] - d_m[0]);
  base15 = base15+ dat15 *
    args[15].dat->size[0] *
    (start[1] * args[15].stencil->stride[1] - args[15].dat->base[1] - d_m[1]);
  base15 = base15+ dat15 *
    args[15].dat->size[0] *
    args[15].dat->size[1] *
    (start[2] * args[15].stencil->stride[2] - args[15].dat->base[2] - d_m[2]);
  double *p_a15 = (double *)((char *)args[15].data + base15);

  #ifdef OPS_MPI
  for (int d = 0; d < dim; d++) d_m[d] = args[16].dat->d_m[d] + OPS_sub_dat_list[args[16].dat->index]->d_im[d];
  #else
  for (int d = 0; d < dim; d++) d_m[d] = args[16].dat->d_m[d];
  #endif
  int base16 = dat16 * 1 * 
    (start[0] * args[16].stencil->stride[0] - args[16].dat->base[0] - d_m[0]);
  base16 = base16+ dat16 *
    args[16].dat->size[0] *
    (start[1] * args[16].stencil->stride[1] - args[16].dat->base[1] - d_m[1]);
  base16 = base16+ dat16 *
    args[16].dat->size[0] *
    args[16].dat->size[1] *
    (start[2] * args[16].stencil->stride[2] - args[16].dat->base[2] - d_m[2]);
  double *p_a16 = (double *)((char *)args[16].data + base16);


  ops_H_D_exchanges_host(args, 17);
  ops_halo_exchanges(args,17,range);

  ops_timers_core(&c1,&t1);
<<<<<<< HEAD
  OPS_kernels[5].mpi_time += t1 - t2;
=======
  OPS_kernels[103].mpi_time += t1 - t2;
>>>>>>> 3f8b285... Regenerating files to resolve conflicts

  PdV_kernel_nopredict_c_wrapper(
    p_a0,
    p_a1,
    p_a2,
    p_a3,
    p_a4,
    p_a5,
    p_a6,
    p_a7,
    p_a8,
    p_a9,
    p_a10,
    p_a11,
    p_a12,
    p_a13,
    p_a14,
    p_a15,
    p_a16,
    x_size, y_size, z_size);

  ops_timers_core(&c2,&t2);
<<<<<<< HEAD
  OPS_kernels[5].time += t2 - t1;
=======
  OPS_kernels[103].time += t2 - t1;
>>>>>>> 3f8b285... Regenerating files to resolve conflicts
  ops_set_dirtybit_host(args, 17);
  ops_set_halo_dirtybit3(&args[6],range);
  ops_set_halo_dirtybit3(&args[10],range);
  ops_set_halo_dirtybit3(&args[13],range);

  //Update kernel record
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
