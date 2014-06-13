//
<<<<<<< HEAD
<<<<<<< HEAD
// auto-generated by op2.py on 2014-06-17 17:28
=======
// auto-generated by op2.py on 2014-06-05 13:43
>>>>>>> 56d4657... Testing all other backends
=======
// auto-generated by op2.py on 2014-06-13 14:56
>>>>>>> 7792f7b... removed cuda syncs based on ops_diags .. but need to make this application agnostic
//

//header
#include "ops_lib_cpp.h"
#include "ops_cuda_rt_support.h"
#include "ops_cuda_reduction.h"
#include "user_types.h"

// global constants
__constant__ double g_small;
__constant__ double g_big;
__constant__ double dtc_safe;
__constant__ double dtu_safe;
__constant__ double dtv_safe;
__constant__ double dtdiv_safe;
__constant__ field_type field;
__constant__ grid_type grid;
__constant__ int number_of_states;
__constant__ state_type *states;
__constant__ int g_circ;
__constant__ int g_point;
__constant__ int g_rect;
__constant__ double dt;

void ops_decl_const_char(int dim, char const *type,
int size, char *dat, char const *name){
  if (!strcmp(name,"g_small")) {
    cutilSafeCall(cudaMemcpyToSymbol(g_small, dat, dim*size));
  }
  else
  if (!strcmp(name,"g_big")) {
    cutilSafeCall(cudaMemcpyToSymbol(g_big, dat, dim*size));
  }
  else
  if (!strcmp(name,"dtc_safe")) {
    cutilSafeCall(cudaMemcpyToSymbol(dtc_safe, dat, dim*size));
  }
  else
  if (!strcmp(name,"dtu_safe")) {
    cutilSafeCall(cudaMemcpyToSymbol(dtu_safe, dat, dim*size));
  }
  else
  if (!strcmp(name,"dtv_safe")) {
    cutilSafeCall(cudaMemcpyToSymbol(dtv_safe, dat, dim*size));
  }
  else
  if (!strcmp(name,"dtdiv_safe")) {
    cutilSafeCall(cudaMemcpyToSymbol(dtdiv_safe, dat, dim*size));
  }
  else
  if (!strcmp(name,"field")) {
    cutilSafeCall(cudaMemcpyToSymbol(field, dat, dim*size));
  }
  else
  if (!strcmp(name,"grid")) {
    cutilSafeCall(cudaMemcpyToSymbol(grid, dat, dim*size));
  }
  else
  if (!strcmp(name,"number_of_states")) {
    cutilSafeCall(cudaMemcpyToSymbol(number_of_states, dat, dim*size));
  }
  else
  if (!strcmp(name,"states")) {
    char *temp; cutilSafeCall(cudaMalloc((void**)&temp,dim*size));
    cutilSafeCall(cudaMemcpy(temp,dat,dim*size,cudaMemcpyHostToDevice));
    cutilSafeCall(cudaMemcpyToSymbol(states, &temp, sizeof(char *)));
  }
  else
  if (!strcmp(name,"g_circ")) {
    cutilSafeCall(cudaMemcpyToSymbol(g_circ, dat, dim*size));
  }
  else
  if (!strcmp(name,"g_point")) {
    cutilSafeCall(cudaMemcpyToSymbol(g_point, dat, dim*size));
  }
  else
  if (!strcmp(name,"g_rect")) {
    cutilSafeCall(cudaMemcpyToSymbol(g_rect, dat, dim*size));
  }
  else
  if (!strcmp(name,"dt")) {
    cutilSafeCall(cudaMemcpyToSymbol(dt, dat, dim*size));
  }
  else
  {
    printf("error: unknown const name\n"); exit(1);
  }
}


//user kernel files
#include "viscosity_kernel_cuda_kernel.cu"
#include "accelerate_kernel_cuda_kernel.cu"
#include "revert_kernel_cuda_kernel.cu"
#include "reset_field_kernel1_cuda_kernel.cu"
#include "reset_field_kernel2_cuda_kernel.cu"
#include "PdV_kernel_predict_cuda_kernel.cu"
#include "PdV_kernel_nopredict_cuda_kernel.cu"
#include "ideal_gas_kernel_cuda_kernel.cu"
#include "flux_calc_kernelx_cuda_kernel.cu"
#include "flux_calc_kernely_cuda_kernel.cu"
#include "advec_mom_kernel_x1_cuda_kernel.cu"
#include "advec_mom_kernel_y1_cuda_kernel.cu"
#include "advec_mom_kernel_x2_cuda_kernel.cu"
#include "advec_mom_kernel_y2_cuda_kernel.cu"
#include "advec_mom_kernel_mass_flux_x_cuda_kernel.cu"
#include "advec_mom_kernel_post_pre_advec_x_cuda_kernel.cu"
#include "advec_mom_kernel1_x_nonvector_cuda_kernel.cu"
#include "advec_mom_kernel2_x_cuda_kernel.cu"
#include "advec_mom_kernel_mass_flux_y_cuda_kernel.cu"
#include "advec_mom_kernel_post_pre_advec_y_cuda_kernel.cu"
#include "advec_mom_kernel1_y_nonvector_cuda_kernel.cu"
#include "advec_mom_kernel2_y_cuda_kernel.cu"
#include "advec_cell_kernel1_xdir_cuda_kernel.cu"
#include "advec_cell_kernel2_xdir_cuda_kernel.cu"
#include "advec_cell_kernel3_xdir_cuda_kernel.cu"
#include "advec_cell_kernel4_xdir_cuda_kernel.cu"
#include "advec_cell_kernel1_ydir_cuda_kernel.cu"
#include "advec_cell_kernel2_ydir_cuda_kernel.cu"
#include "advec_cell_kernel3_ydir_cuda_kernel.cu"
#include "advec_cell_kernel4_ydir_cuda_kernel.cu"
#include "update_halo_kernel1_b2_cuda_kernel.cu"
#include "update_halo_kernel1_b1_cuda_kernel.cu"
#include "update_halo_kernel1_t2_cuda_kernel.cu"
#include "update_halo_kernel1_t1_cuda_kernel.cu"
#include "update_halo_kernel1_l2_cuda_kernel.cu"
#include "update_halo_kernel1_l1_cuda_kernel.cu"
#include "update_halo_kernel1_r2_cuda_kernel.cu"
#include "update_halo_kernel1_r1_cuda_kernel.cu"
#include "update_halo_kernel2_xvel_plus_4_a_cuda_kernel.cu"
#include "update_halo_kernel2_xvel_plus_2_a_cuda_kernel.cu"
#include "update_halo_kernel2_xvel_plus_4_b_cuda_kernel.cu"
#include "update_halo_kernel2_xvel_plus_2_b_cuda_kernel.cu"
#include "update_halo_kernel2_xvel_minus_4_a_cuda_kernel.cu"
#include "update_halo_kernel2_xvel_minus_2_a_cuda_kernel.cu"
#include "update_halo_kernel2_xvel_minus_4_b_cuda_kernel.cu"
#include "update_halo_kernel2_xvel_minus_2_b_cuda_kernel.cu"
#include "update_halo_kernel2_yvel_minus_4_a_cuda_kernel.cu"
#include "update_halo_kernel2_yvel_minus_2_a_cuda_kernel.cu"
#include "update_halo_kernel2_yvel_minus_4_b_cuda_kernel.cu"
#include "update_halo_kernel2_yvel_minus_2_b_cuda_kernel.cu"
#include "update_halo_kernel2_yvel_plus_4_a_cuda_kernel.cu"
#include "update_halo_kernel2_yvel_plus_2_a_cuda_kernel.cu"
#include "update_halo_kernel2_yvel_plus_4_b_cuda_kernel.cu"
#include "update_halo_kernel2_yvel_plus_2_b_cuda_kernel.cu"
#include "update_halo_kernel3_plus_4_a_cuda_kernel.cu"
#include "update_halo_kernel3_plus_2_a_cuda_kernel.cu"
#include "update_halo_kernel3_plus_4_b_cuda_kernel.cu"
#include "update_halo_kernel3_plus_2_b_cuda_kernel.cu"
#include "update_halo_kernel3_minus_4_a_cuda_kernel.cu"
#include "update_halo_kernel3_minus_2_a_cuda_kernel.cu"
#include "update_halo_kernel3_minus_4_b_cuda_kernel.cu"
#include "update_halo_kernel3_minus_2_b_cuda_kernel.cu"
#include "update_halo_kernel4_minus_4_a_cuda_kernel.cu"
#include "update_halo_kernel4_minus_2_a_cuda_kernel.cu"
#include "update_halo_kernel4_minus_4_b_cuda_kernel.cu"
#include "update_halo_kernel4_minus_2_b_cuda_kernel.cu"
#include "update_halo_kernel4_plus_4_a_cuda_kernel.cu"
#include "update_halo_kernel4_plus_2_a_cuda_kernel.cu"
#include "update_halo_kernel4_plus_4_b_cuda_kernel.cu"
#include "update_halo_kernel4_plus_2_b_cuda_kernel.cu"
#include "field_summary_kernel_cuda_kernel.cu"
#include "calc_dt_kernel_cuda_kernel.cu"
#include "calc_dt_kernel_min_cuda_kernel.cu"
#include "calc_dt_kernel_get_cuda_kernel.cu"
#include "calc_dt_kernel_print_cuda_kernel.cu"
#include "initialise_chunk_kernel_x_cuda_kernel.cu"
#include "initialise_chunk_kernel_y_cuda_kernel.cu"
#include "initialise_chunk_kernel_cellx_cuda_kernel.cu"
#include "initialise_chunk_kernel_celly_cuda_kernel.cu"
#include "initialise_chunk_kernel_volume_cuda_kernel.cu"
<<<<<<< HEAD
<<<<<<< HEAD
=======
#include "field_summary_kernel_cuda_kernel.cu"
>>>>>>> 56d4657... Testing all other backends
=======
>>>>>>> 7792f7b... removed cuda syncs based on ops_diags .. but need to make this application agnostic
#include "generate_chunk_kernel_cuda_kernel.cu"
