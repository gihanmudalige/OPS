//
// auto-generated by ops.py//

//header
#define OPS_ACC_MD_MACROS
#define OPS_2D
#include "stdlib.h"
#include "stdio.h"
#include "ops_lib_cpp.h"
#include "ops_opencl_rt_support.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif
//global constants
extern int imax;
extern int jmax;
extern double pi;

extern ops_opencl_core OPS_opencl_core;

void ops_init_backend() {}

//this needs to be a platform specific copy symbol to device function
void ops_decl_const_char( int dim, char const * type, int typeSize, char * dat, char const * name ) {
  cl_int ret = 0;
  if (OPS_opencl_core.constant == NULL) {
    OPS_opencl_core.constant = (cl_mem*) malloc((3)*sizeof(cl_mem));
    for ( int i=0; i<3; i++ ){
      OPS_opencl_core.constant[i] = NULL;
    }
  }
  if (!strcmp(name,"imax")) {
    if (OPS_opencl_core.constant[0] == NULL) {
      OPS_opencl_core.constant[0] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[0], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"jmax")) {
    if (OPS_opencl_core.constant[1] == NULL) {
      OPS_opencl_core.constant[1] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[1], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  if (!strcmp(name,"pi")) {
    if (OPS_opencl_core.constant[2] == NULL) {
      OPS_opencl_core.constant[2] = clCreateBuffer(OPS_opencl_core.context, CL_MEM_READ_ONLY, dim*typeSize, NULL, &ret);
      clSafeCall( ret );
    }
    //Write the new constant to the memory of the device
    clSafeCall( clEnqueueWriteBuffer(OPS_opencl_core.command_queue, OPS_opencl_core.constant[2], CL_TRUE, 0, dim*typeSize, (void*) dat, 0, NULL, NULL) );
    clSafeCall( clFlush(OPS_opencl_core.command_queue) );
    clSafeCall( clFinish(OPS_opencl_core.command_queue) );
  }
  else
  {
    printf("error: unknown const name\n"); exit(1);
  }
}

extern ops_opencl_core OPS_opencl_core;

void buildOpenCLKernels() {
  static bool isbuilt = false;

  if(!isbuilt) {
    //clSafeCall( clUnloadCompiler() );

    OPS_opencl_core.n_kernels = 6;
    OPS_opencl_core.kernel = (cl_kernel*) malloc(6*sizeof(cl_kernel));
  }
  isbuilt = true;
}

//user kernel files
#include "apply_stencil_opencl_kernel.cpp"
#include "set_zero_opencl_kernel.cpp"
#include "copy_opencl_kernel.cpp"
#include "right_bndcon_opencl_kernel.cpp"
#include "left_bndcon_opencl_kernel.cpp"
