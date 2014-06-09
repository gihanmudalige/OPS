//
// auto-generated by ops.py on 2014-06-09 10:54
//


#pragma OPENCL EXTENSION cl_khr_fp64:enable

#include "user_types.h"
#include "ops_opencl_reduction.h"

#ifndef MIN
#define MIN(a,b) ((a<b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a>b) ? (a) : (b))
#endif
#ifndef SIGN
#define SIGN(a,b) ((b<0.0) ? (a*(-1)) : (a))
#endif
#define OPS_READ 0
#define OPS_WRITE 1
#define OPS_RW 2
#define OPS_INC 3
#define OPS_MIN 4
#define OPS_MAX 5
#define ZERO_double 0.0;
#define INFINITY_double INFINITY;
#define ZERO_float 0.0f;
#define INFINITY_float INFINITY;
#define ZERO_int 0;
#define INFINITY_int INFINITY;
#define ZERO_uint 0;
#define INFINITY_uint INFINITY;
#define ZERO_ll 0;
#define INFINITY_ll INFINITY;
#define ZERO_ull 0;
#define INFINITY_ull INFINITY;
#define ZERO_bool 0;
#define OPS_ACC0(x,y) (x+xdim0_generate_chunk_kernel*(y))
#define OPS_ACC1(x,y) (x+xdim1_generate_chunk_kernel*(y))
#define OPS_ACC2(x,y) (x+xdim2_generate_chunk_kernel*(y))
#define OPS_ACC3(x,y) (x+xdim3_generate_chunk_kernel*(y))
#define OPS_ACC4(x,y) (x+xdim4_generate_chunk_kernel*(y))
#define OPS_ACC5(x,y) (x+xdim5_generate_chunk_kernel*(y))
#define OPS_ACC6(x,y) (x+xdim6_generate_chunk_kernel*(y))
#define OPS_ACC7(x,y) (x+xdim7_generate_chunk_kernel*(y))


//user function
void generate_chunk_kernel(  __global double *vertexx, __global double *vertexy, __global double *energy0, 
__global double *density0, __global double *xvel0, __global double *yvel0, __global double *cellx, 
__global double *celly, 
  int number_of_states,
  __constant state_type *states,
  int g_circ,
  int g_point,
  int g_rect,
  int xdim0_generate_chunk_kernel,
int xdim1_generate_chunk_kernel,
int xdim2_generate_chunk_kernel,
int xdim3_generate_chunk_kernel,
int xdim4_generate_chunk_kernel,
int xdim5_generate_chunk_kernel,
int xdim6_generate_chunk_kernel,
int xdim7_generate_chunk_kernel)

  {

  double radius, x_cent, y_cent;


  energy0[OPS_ACC2(0,0)]= states[0].energy;
  density0[OPS_ACC3(0,0)]= states[0].density;
  xvel0[OPS_ACC4(0,0)]=states[0].xvel;
  yvel0[OPS_ACC5(0,0)]=states[0].yvel;

  for(int i = 1; i<number_of_states; i++) {

    x_cent=states[i].xmin;
    y_cent=states[i].ymin;

    if (states[i].geometry == g_rect) {
      if(vertexx[OPS_ACC0(1,0)] >= states[i].xmin  && vertexx[OPS_ACC0(0,0)] < states[i].xmax) {
        if(vertexy[OPS_ACC1(0,1)] >= states[i].ymin && vertexy[OPS_ACC1(0,0)] < states[i].ymax) {

          energy0[OPS_ACC2(0,0)] = states[i].energy;
          density0[OPS_ACC3(0,0)] = states[i].density;

          xvel0[OPS_ACC4(0,0)] = states[i].xvel;
          xvel0[OPS_ACC4(1,0)] = states[i].xvel;
          xvel0[OPS_ACC4(0,1)] = states[i].xvel;
          xvel0[OPS_ACC4(1,1)] = states[i].xvel;

          yvel0[OPS_ACC5(0,0)] = states[i].yvel;
          yvel0[OPS_ACC5(1,0)] = states[i].yvel;
          yvel0[OPS_ACC5(0,1)] = states[i].yvel;
          yvel0[OPS_ACC5(1,1)] = states[i].yvel;
        }
      }

    }
    else if(states[i].geometry == g_circ) {
      radius = sqrt ((cellx[OPS_ACC6(0,0)] - x_cent) * (cellx[OPS_ACC6(0,0)] - x_cent) +
                     (celly[OPS_ACC7(0,0)] - y_cent) * (celly[OPS_ACC7(0,0)] - y_cent));
      if(radius <= states[i].radius) {
        energy0[OPS_ACC2(0,0)] = states[i].energy;
        density0[OPS_ACC3(0,0)] = states[i].density;

        xvel0[OPS_ACC4(0,0)] = states[i].xvel;
        xvel0[OPS_ACC4(1,0)] = states[i].xvel;
        xvel0[OPS_ACC4(0,1)] = states[i].xvel;
        xvel0[OPS_ACC4(1,1)] = states[i].xvel;

        yvel0[OPS_ACC5(0,0)] = states[i].yvel;
        yvel0[OPS_ACC5(1,0)] = states[i].yvel;
        yvel0[OPS_ACC5(0,1)] = states[i].yvel;
        yvel0[OPS_ACC5(1,1)] = states[i].yvel;
      }
    }
    else if(states[i].geometry == g_point) {
      if(vertexx[OPS_ACC0(0,0)] == x_cent && vertexy[OPS_ACC1(0,0)] == y_cent) {
        energy0[OPS_ACC2(0,0)] = states[i].energy;
        density0[OPS_ACC3(0,0)] = states[i].density;

        xvel0[OPS_ACC4(0,0)] = states[i].xvel;
        xvel0[OPS_ACC4(1,0)] = states[i].xvel;
        xvel0[OPS_ACC4(0,1)] = states[i].xvel;
        xvel0[OPS_ACC4(1,1)] = states[i].xvel;

        yvel0[OPS_ACC5(0,0)] = states[i].yvel;
        yvel0[OPS_ACC5(1,0)] = states[i].yvel;
        yvel0[OPS_ACC5(0,1)] = states[i].yvel;
        yvel0[OPS_ACC5(1,1)] = states[i].yvel;
      }
    }
  }
}



 #undef OPS_ACC0
 #undef OPS_ACC1
 #undef OPS_ACC2
 #undef OPS_ACC3
 #undef OPS_ACC4
 #undef OPS_ACC5
 #undef OPS_ACC6
 #undef OPS_ACC7


 __kernel void ops_generate_chunk_kernel(
 __global double* arg0,
 __global double* arg1,
 __global double* arg2,
 __global double* arg3,
 __global double* arg4,
 __global double* arg5,
 __global double* arg6,
 __global double* arg7,
 __global int *number_of_states,
 __constant struct state_type *states,
 __global int *g_circ,
 __global int *g_point,
 __global int *g_rect,
 int xdim0_generate_chunk_kernel,
 int xdim1_generate_chunk_kernel,
 int xdim2_generate_chunk_kernel,
 int xdim3_generate_chunk_kernel,
 int xdim4_generate_chunk_kernel,
 int xdim5_generate_chunk_kernel,
 int xdim6_generate_chunk_kernel,
 int xdim7_generate_chunk_kernel,
 const int base0,
 const int base1,
 const int base2,
 const int base3,
 const int base4,
 const int base5,
 const int base6,
 const int base7,
 int size0,
 int size1 ){


   int idx_y = get_global_id(1);
   int idx_x = get_global_id(0);

   if (idx_x < size0 && idx_y < size1) {
     generate_chunk_kernel(&arg0[base0 + idx_x * 1 + idx_y * 0 * xdim0_generate_chunk_kernel],
                           &arg1[base1 + idx_x * 0 + idx_y * 1 * xdim1_generate_chunk_kernel],
                           &arg2[base2 + idx_x * 1 + idx_y * 1 * xdim2_generate_chunk_kernel],
                           &arg3[base3 + idx_x * 1 + idx_y * 1 * xdim3_generate_chunk_kernel],
                           &arg4[base4 + idx_x * 1 + idx_y * 1 * xdim4_generate_chunk_kernel],
                           &arg5[base5 + idx_x * 1 + idx_y * 1 * xdim5_generate_chunk_kernel],
                           &arg6[base6 + idx_x * 1 + idx_y * 0 * xdim6_generate_chunk_kernel],
                           &arg7[base7 + idx_x * 0 + idx_y * 1 * xdim7_generate_chunk_kernel],
                           *number_of_states,states,*g_circ,*g_point,*g_rect,
                           xdim0_generate_chunk_kernel,
                           xdim1_generate_chunk_kernel,
                           xdim2_generate_chunk_kernel,
                           xdim3_generate_chunk_kernel,
                           xdim4_generate_chunk_kernel,
                           xdim5_generate_chunk_kernel,
                           xdim6_generate_chunk_kernel,
                           xdim7_generate_chunk_kernel);
   }

 }
