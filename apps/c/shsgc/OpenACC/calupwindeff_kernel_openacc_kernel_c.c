//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_calupwindeff_kernel;
int xdim1_calupwindeff_kernel;
int xdim2_calupwindeff_kernel;
int xdim3_calupwindeff_kernel;
int xdim4_calupwindeff_kernel;
int xdim5_calupwindeff_kernel;
int xdim6_calupwindeff_kernel;

//user function
#pragma acc routine
inline 
void calupwindeff_kernel(const ptrm_double  cmp,
  const ptrm_double gt,
  const ptrm_double  cf,
  const ptrm_double  al,
  const ptrm_double  ep2,
  const ptrm_double  r,
  ptrm_double  eff) {

		double e1 = (OPS_ACC(cmp, 0,0) * (OPS_ACC(gt, 0,0) + OPS_ACC(gt, 0,1)) - OPS_ACC(cf, 0,0) * OPS_ACC(al, 0,0)) * OPS_ACC(ep2, 0,0);
		double e2 = (OPS_ACC(cmp, 1,0) * (OPS_ACC(gt, 1,0) + OPS_ACC(gt, 1,1)) - OPS_ACC(cf, 1,0) * OPS_ACC(al, 1,0)) * OPS_ACC(ep2, 1,0);
		double e3 = (OPS_ACC(cmp, 2,0) * (OPS_ACC(gt, 2,0) + OPS_ACC(gt, 2,1)) - OPS_ACC(cf, 2,0) * OPS_ACC(al, 2,0)) * OPS_ACC(ep2, 2,0);

		OPS_ACC(eff, 0,0)=e1 * OPS_ACC(r, 0,0) + e2 * OPS_ACC(r, 1,0) + e3 * OPS_ACC(r, 2,0);
		OPS_ACC(eff, 1,0)=e1 * OPS_ACC(r, 3,0) + e2 * OPS_ACC(r, 4,0) + e3 * OPS_ACC(r, 5,0);
		OPS_ACC(eff, 2,0)=e1 * OPS_ACC(r, 6,0) + e2 * OPS_ACC(r, 7,0) + e3 * OPS_ACC(r, 8,0);
}


void calupwindeff_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  double *p_a2,
  double *p_a3,
  double *p_a4,
  double *p_a5,
  double *p_a6,
  int x_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6)
  #pragma acc loop
  #endif
  for ( int n_x=0; n_x<x_size; n_x++ ){
    #ifdef OPS_SOA
    const ptrm_double ptr0 = {  p_a0 + n_x*1*3, xdim0_calupwindeff_kernel};
    #else
    const ptrm_double ptr0 = {  p_a0 + n_x*1*3, 3};
    #endif
    #ifdef OPS_SOA
    const ptrm_double ptr1 = {  p_a1 + n_x*1*3, xdim1_calupwindeff_kernel};
    #else
    const ptrm_double ptr1 = {  p_a1 + n_x*1*3, 3};
    #endif
    #ifdef OPS_SOA
    const ptrm_double ptr2 = {  p_a2 + n_x*1*3, xdim2_calupwindeff_kernel};
    #else
    const ptrm_double ptr2 = {  p_a2 + n_x*1*3, 3};
    #endif
    #ifdef OPS_SOA
    const ptrm_double ptr3 = {  p_a3 + n_x*1*3, xdim3_calupwindeff_kernel};
    #else
    const ptrm_double ptr3 = {  p_a3 + n_x*1*3, 3};
    #endif
    #ifdef OPS_SOA
    const ptrm_double ptr4 = {  p_a4 + n_x*1*3, xdim4_calupwindeff_kernel};
    #else
    const ptrm_double ptr4 = {  p_a4 + n_x*1*3, 3};
    #endif
    #ifdef OPS_SOA
    const ptrm_double ptr5 = {  p_a5 + n_x*1*9, xdim5_calupwindeff_kernel};
    #else
    const ptrm_double ptr5 = {  p_a5 + n_x*1*9, 9};
    #endif
    #ifdef OPS_SOA
    ptrm_double ptr6 = {  p_a6 + n_x*1*3, xdim6_calupwindeff_kernel};
    #else
    ptrm_double ptr6 = {  p_a6 + n_x*1*3, 3};
    #endif
    calupwindeff_kernel( ptr0,
          ptr1,ptr2,
          ptr3,ptr4,
          ptr5,ptr6 );

  }
}
