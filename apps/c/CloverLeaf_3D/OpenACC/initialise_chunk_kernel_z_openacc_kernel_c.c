//
// auto-generated by ops.py
//

#define OPS_GPU

int xdim0_initialise_chunk_kernel_z;
int ydim0_initialise_chunk_kernel_z;
int xdim1_initialise_chunk_kernel_z;
int ydim1_initialise_chunk_kernel_z;
int xdim2_initialise_chunk_kernel_z;
int ydim2_initialise_chunk_kernel_z;


#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2


#define OPS_ACC0(x,y,z) (x+xdim0_initialise_chunk_kernel_z*(y)+xdim0_initialise_chunk_kernel_z*ydim0_initialise_chunk_kernel_z*(z))
#define OPS_ACC1(x,y,z) (x+xdim1_initialise_chunk_kernel_z*(y)+xdim1_initialise_chunk_kernel_z*ydim1_initialise_chunk_kernel_z*(z))
#define OPS_ACC2(x,y,z) (x+xdim2_initialise_chunk_kernel_z*(y)+xdim2_initialise_chunk_kernel_z*ydim2_initialise_chunk_kernel_z*(z))

//user function
inline 
void initialise_chunk_kernel_z(double *vertexz, const int *zz, double *vertexdz) {
  int z_min=field.z_min-2;

  double min_z, d_z;
  d_z = (grid.zmax - grid.zmin)/(double)grid.z_cells;
  min_z=grid.zmin+d_z*field.back;

  vertexz[OPS_ACC0(0,0,0)] = min_z + d_z * (zz[OPS_ACC1(0,0,0)] - z_min);
  vertexdz[OPS_ACC2(0,0,0)] = (double)d_z;
}


#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2



void initialise_chunk_kernel_z_c_wrapper(
  double *p_a0,
  int *p_a1,
  double *p_a2,
  int x_size, int y_size, int z_size) {
  #ifdef OPS_GPU
  #pragma acc parallel deviceptr(p_a0,p_a1,p_a2)
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
        initialise_chunk_kernel_z(  p_a0 + n_x*0*1 + n_y*xdim0_initialise_chunk_kernel_z*0*1 + n_z*xdim0_initialise_chunk_kernel_z*ydim0_initialise_chunk_kernel_z*1*1,
           p_a1 + n_x*0*1 + n_y*xdim1_initialise_chunk_kernel_z*0*1 + n_z*xdim1_initialise_chunk_kernel_z*ydim1_initialise_chunk_kernel_z*1*1,
           p_a2 + n_x*0*1 + n_y*xdim2_initialise_chunk_kernel_z*0*1 + n_z*xdim2_initialise_chunk_kernel_z*ydim2_initialise_chunk_kernel_z*1*1 );

      }
    }
  }
}
