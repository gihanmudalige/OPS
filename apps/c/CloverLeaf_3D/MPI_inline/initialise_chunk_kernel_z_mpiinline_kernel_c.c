//
// auto-generated by ops.py
//

int xdim0_initialise_chunk_kernel_z;
int ydim0_initialise_chunk_kernel_z;
int xdim1_initialise_chunk_kernel_z;
int ydim1_initialise_chunk_kernel_z;
int xdim2_initialise_chunk_kernel_z;
int ydim2_initialise_chunk_kernel_z;


#define OPS_ACC0(x,y,z) (n_x*0 + x + (n_y*0+(y))*xdim0_initialise_chunk_kernel_z + (n_z*1+(z))*xdim0_initialise_chunk_kernel_z*ydim0_initialise_chunk_kernel_z)
#define OPS_ACC1(x,y,z) (n_x*0 + x + (n_y*0+(y))*xdim1_initialise_chunk_kernel_z + (n_z*1+(z))*xdim1_initialise_chunk_kernel_z*ydim1_initialise_chunk_kernel_z)
#define OPS_ACC2(x,y,z) (n_x*0 + x + (n_y*0+(y))*xdim2_initialise_chunk_kernel_z + (n_z*1+(z))*xdim2_initialise_chunk_kernel_z*ydim2_initialise_chunk_kernel_z)
//user function



void initialise_chunk_kernel_z_c_wrapper(
  double * restrict vertexz,
  const int * restrict zz,
  double * restrict vertexdz,
  int x_size, int y_size, int z_size) {
  #pragma omp parallel for
  for ( int n_z=0; n_z<z_size; n_z++ ){
    for ( int n_y=0; n_y<y_size; n_y++ ){
      for ( int n_x=0; n_x<x_size; n_x++ ){
        
  int z_min=field.z_min-2;

  double min_z, d_z;
  d_z = (grid.zmax - grid.zmin)/(double)grid.z_cells;
  min_z=grid.zmin+d_z*field.back;

  vertexz[OPS_ACC0(0,0,0)] = min_z + d_z * (zz[OPS_ACC1(0,0,0)] - z_min);
  vertexdz[OPS_ACC2(0,0,0)] = (double)d_z;

      }
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2

