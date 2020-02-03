//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_calc_dt_kernel;
int xdim1_calc_dt_kernel;
int xdim2_calc_dt_kernel;
int xdim3_calc_dt_kernel;
int xdim4_calc_dt_kernel;
int xdim5_calc_dt_kernel;
int xdim6_calc_dt_kernel;
int xdim7_calc_dt_kernel;
int xdim8_calc_dt_kernel;
int xdim9_calc_dt_kernel;
int xdim10_calc_dt_kernel;

//user function
#pragma acc routine
inline 
void calc_dt_kernel(const ptr_double celldx,
  const ptr_double celldy,
  const ptr_double soundspeed,
  const ptr_double viscosity,
  const ptr_double density0,
  const ptr_double xvel0,
  const ptr_double xarea,
  const ptr_double volume,
  const ptr_double yvel0,
  const ptr_double yarea,
  ptr_double dt_min) {

  double div, dsx, dsy, dtut, dtvt, dtct, dtdivt, cc, dv1, dv2;

  dsx = OPS_ACC(celldx, 0,0);
  dsy = OPS_ACC(celldy, 0,0);

  cc = OPS_ACC(soundspeed, 0,0) * OPS_ACC(soundspeed, 0,0);
  cc = cc + 2.0 * OPS_ACC(viscosity, 0,0)/OPS_ACC(density0, 0,0);
  cc = MAX(sqrt(cc),g_small);

  dtct = dtc_safe * MIN(dsx,dsy)/cc;

  div=0.0;


  dv1 = (OPS_ACC(xvel0, 0,0) + OPS_ACC(xvel0, 0,1)) * OPS_ACC(xarea, 0,0);
  dv2 = (OPS_ACC(xvel0, 1,0) + OPS_ACC(xvel0, 1,1)) * OPS_ACC(xarea, 1,0);

  div = div + dv2 - dv1;

  dtut = dtu_safe * 2.0 * OPS_ACC(volume, 0,0)/MAX(MAX(fabs(dv1), fabs(dv2)), g_small * OPS_ACC(volume, 0,0));

  dv1 = (OPS_ACC(yvel0, 0,0) + OPS_ACC(yvel0, 1,0)) * OPS_ACC(yarea, 0,0);
  dv2 = (OPS_ACC(yvel0, 0,1) + OPS_ACC(yvel0, 1,1)) * OPS_ACC(yarea, 0,1);

  div = div + dv2 - dv1;

  dtvt = dtv_safe * 2.0 * OPS_ACC(volume, 0,0)/MAX(MAX(fabs(dv1),fabs(dv2)), g_small * OPS_ACC(volume, 0,0));

  div = div/(2.0 * OPS_ACC(volume, 0,0));

  if(div < -g_small)
    dtdivt = dtdiv_safe * (-1.0/div);
  else
    dtdivt = g_big;

  OPS_ACC(dt_min, 0,0) = MIN(MIN(dtct, dtut), MIN(dtvt, dtdivt));


}


void calc_dt_kernel_c_wrapper(
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
  int x_size, int y_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6,p_a7,p_a8,p_a9,p_a10)
  #pragma acc loop
  #endif
  for ( int n_y=0; n_y<y_size; n_y++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_x=0; n_x<x_size; n_x++ ){
      const ptr_double ptr0 = {  p_a0 + n_x*1*1 + n_y*xdim0_calc_dt_kernel*0*1, xdim0_calc_dt_kernel};
      const ptr_double ptr1 = {  p_a1 + n_x*0*1 + n_y*xdim1_calc_dt_kernel*1*1, xdim1_calc_dt_kernel};
      const ptr_double ptr2 = {  p_a2 + n_x*1*1 + n_y*xdim2_calc_dt_kernel*1*1, xdim2_calc_dt_kernel};
      const ptr_double ptr3 = {  p_a3 + n_x*1*1 + n_y*xdim3_calc_dt_kernel*1*1, xdim3_calc_dt_kernel};
      const ptr_double ptr4 = {  p_a4 + n_x*1*1 + n_y*xdim4_calc_dt_kernel*1*1, xdim4_calc_dt_kernel};
      const ptr_double ptr5 = {  p_a5 + n_x*1*1 + n_y*xdim5_calc_dt_kernel*1*1, xdim5_calc_dt_kernel};
      const ptr_double ptr6 = {  p_a6 + n_x*1*1 + n_y*xdim6_calc_dt_kernel*1*1, xdim6_calc_dt_kernel};
      const ptr_double ptr7 = {  p_a7 + n_x*1*1 + n_y*xdim7_calc_dt_kernel*1*1, xdim7_calc_dt_kernel};
      const ptr_double ptr8 = {  p_a8 + n_x*1*1 + n_y*xdim8_calc_dt_kernel*1*1, xdim8_calc_dt_kernel};
      const ptr_double ptr9 = {  p_a9 + n_x*1*1 + n_y*xdim9_calc_dt_kernel*1*1, xdim9_calc_dt_kernel};
      ptr_double ptr10 = {  p_a10 + n_x*1*1 + n_y*xdim10_calc_dt_kernel*1*1, xdim10_calc_dt_kernel};
      calc_dt_kernel( ptr0,
          ptr1,ptr2,
          ptr3,ptr4,
          ptr5,ptr6,
          ptr7,ptr8,
          ptr9,ptr10 );

    }
  }
}
