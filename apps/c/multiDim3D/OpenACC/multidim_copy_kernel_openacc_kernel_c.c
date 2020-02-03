//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_multidim_copy_kernel;
int ydim0_multidim_copy_kernel;
int zdim0_multidim_copy_kernel;
int xdim1_multidim_copy_kernel;
int ydim1_multidim_copy_kernel;
int zdim1_multidim_copy_kernel;

//user function
#pragma acc routine
inline 
void multidim_copy_kernel(const ptrm_double src,
  ptrm_double dest){
  OPS_ACC(dest, 0,0,0,0) = OPS_ACC(src, 0,0,0,0);
  OPS_ACC(dest, 1,0,0,0) = OPS_ACC(src, 1,0,0,0);
  OPS_ACC(dest, 2,0,0,0) = OPS_ACC(src, 2,0,0,0);
}


void multidim_copy_kernel_c_wrapper(
  double *p_a0,
  double *p_a1,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1)
  #pragma acc loop
  #endif
  for ( int n_z=0; n_z<z_size; n_z++ ){
    #ifdef OPS_GPU
    #pragma acc loop
    #endif
    for ( int n_y=0; n_y<y_size; n_y++ ){
      #ifdef OPS_GPU
      #pragma acc loop
      #endif
      for ( int n_x=0; n_x<x_size; n_x++ ){
        #ifdef OPS_SOA
        const ptrm_double ptr0 = {  p_a0 + n_x*1 + n_y*xdim0_multidim_copy_kernel*1 + n_z*xdim0_multidim_copy_kernel*ydim0_multidim_copy_kernel*1, xdim0_multidim_copy_kernel, ydim0_multidim_copy_kernel, zdim0_multidim_copy_kernel};
        #else
        const ptrm_double ptr0 = {  p_a0 + n_x*1 + n_y*xdim0_multidim_copy_kernel*1 + n_z*xdim0_multidim_copy_kernel*ydim0_multidim_copy_kernel*1, xdim0_multidim_copy_kernel, ydim0_multidim_copy_kernel, 3};
        #endif
        #ifdef OPS_SOA
        ptrm_double ptr1 = {  p_a1 + n_x*1 + n_y*xdim1_multidim_copy_kernel*1 + n_z*xdim1_multidim_copy_kernel*ydim1_multidim_copy_kernel*1, xdim1_multidim_copy_kernel, ydim1_multidim_copy_kernel, zdim1_multidim_copy_kernel};
        #else
        ptrm_double ptr1 = {  p_a1 + n_x*1 + n_y*xdim1_multidim_copy_kernel*1 + n_z*xdim1_multidim_copy_kernel*ydim1_multidim_copy_kernel*1, xdim1_multidim_copy_kernel, ydim1_multidim_copy_kernel, 3};
        #endif
        multidim_copy_kernel( ptr0,
          ptr1 );

      }
    }
  }
}
