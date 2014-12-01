//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64:enable

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
#define OPS_ACC0(x) (x)
#define OPS_ACC1(x) (x)
#define OPS_ACC2(x) (x)

#define OPS_ACC_MD3(d,x) ((x)*3+(d))
#define OPS_ACC_MD4(d,x) ((x)*9+(d))
#define OPS_ACC_MD5(d,x) ((x)*3+(d))

//user function
void Riemann_kernel(const __global double* restrict  rho_new, const __global double * restrict rhou_new, const __global double* restrict  rhoE_new, 
__global double* restrict  alam, __global double* restrict  r, __global double* restrict  al, 
  const double gam1)

 {

  double rl, rr, rho, leftu, rightu, u, hl, hr, h, Vsq, csq, c, g;
  double dw1, dw2, dw3, delpc2, rdeluc;
  double ri[3][3];

  rl = sqrt(rho_new[OPS_ACC0(0)]);
  rr = sqrt(rho_new[OPS_ACC0(1)]);
  rho = rl + rr;
  u = ((rhou_new[OPS_ACC1(0)] / rl) + (rhou_new[OPS_ACC1(1)] / rr)) / rho ;
  double fni = rhou_new[OPS_ACC1(0)] * rhou_new[OPS_ACC1(0)] / rho_new[OPS_ACC0(0)] ;
  double p = gam1 * (rhoE_new[OPS_ACC2(0)] - 0.5 * fni);
  hl = (rhoE_new[OPS_ACC2(0)] + p)  / rl ;
  fni = rhou_new[OPS_ACC1(1)] * rhou_new[OPS_ACC1(1)] / rho_new[OPS_ACC0(1)] ;
  p = gam1 * (rhoE_new[OPS_ACC2(1)] - 0.5 * fni);
  hr = (rhoE_new[OPS_ACC2(1)] + p)  / rr ;
  h = (hl + hr)/rho;
  Vsq = u*u;
  csq = gam1 * (h - 0.5 * Vsq);
  g = gam1 / csq;
  c = sqrt(csq);

  alam[OPS_ACC_MD3(0,0)] = u - c;
  alam[OPS_ACC_MD3(1,0)] = u;
  alam[OPS_ACC_MD3(2,0)] = u + c;

  r[OPS_ACC_MD4(0,0)] = 1.0;
  r[OPS_ACC_MD4(1,0)] = 1.0;
  r[OPS_ACC_MD4(2,0)] = 1.0;

  r[OPS_ACC_MD4(3,0)] = u - c;
  r[OPS_ACC_MD4(4,0)] = u;
  r[OPS_ACC_MD4(5,0)] = u + c;

  r[OPS_ACC_MD4(6,0)] = h - u * c;
  r[OPS_ACC_MD4(7,0)] = 0.5 * Vsq;
  r[OPS_ACC_MD4(8,0)] = h + u * c;

  for (int m=0; m<9; m++)
    r[OPS_ACC_MD4(m,0)] = r[OPS_ACC_MD4(m,0)] / csq;

  dw1 = rho_new[OPS_ACC0(1)] - rho_new[OPS_ACC0(0)];
  dw2 = rhou_new[OPS_ACC1(1)] - rhou_new[OPS_ACC1(0)];
  dw3 = rhoE_new[OPS_ACC2(1)] - rhoE_new[OPS_ACC2(0)];

  delpc2 = gam1 * ( dw3 + 0.50 * Vsq * dw1  - u * dw2) / csq;
  rdeluc = ( dw2 - u * dw1) / c ;

  al[OPS_ACC_MD5(0,0)] = 0.5 * (delpc2 - rdeluc);
  al[OPS_ACC_MD5(1,0)] = dw1 - delpc2 ;
  al[OPS_ACC_MD5(2,0)] = 0.5 * ( delpc2 + rdeluc );

  for (int m=0; m<3; m++)
    al[OPS_ACC_MD5(m,0)] = al[OPS_ACC_MD5(m,0)] * csq;
}



#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2

#undef OPS_ACC_MD3
#undef OPS_ACC_MD4
#undef OPS_ACC_MD5


__kernel void ops_Riemann_kernel(
__global const double* restrict arg0,
__global const double* restrict arg1,
__global const double* restrict arg2,
__global double* restrict arg3,
__global double* restrict arg4,
__global double* restrict arg5,
const double gam1,
const int base0,
const int base1,
const int base2,
const int base3,
const int base4,
const int base5,
const int size0 ){


  int idx_x = get_global_id(0);

  if (idx_x < size0) {
    Riemann_kernel(&arg0[base0 + idx_x * 1*1],
                   &arg1[base1 + idx_x * 1*1],
                   &arg2[base2 + idx_x * 1*1],
                   &arg3[base3 + idx_x * 1*3],
                   &arg4[base4 + idx_x * 1*9],
                   &arg5[base5 + idx_x * 1*3],
                   gam1);
  }

}
