//
// auto-generated by op2.py on 2014-04-10 10:52
//

// header
#define OPS_2D
#include "ops_lib_core.h"

#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif

// this is a custom include -- not produced by the code generator
#include "data.h"
#include "definitions.h"

// user kernel files
/*
#include "../MPI_OpenMP/PdV_kernel_nopredict_cpu_kernel.cpp"
#include "../MPI_OpenMP/PdV_kernel_predict_cpu_kernel.cpp"
#include "../MPI_OpenMP/accelerate_kernel_cpu_kernel.cpp"
#include "../MPI_OpenMP/ideal_gas_kernel_cpu_kernel.cpp"
#include "../MPI_OpenMP/reset_field_kernel1_cpu_kernel.cpp"
#include "../MPI_OpenMP/reset_field_kernel2_cpu_kernel.cpp"
#include "../MPI_OpenMP/revert_kernel_cpu_kernel.cpp"

#include "../MPI_OpenMP/advec_cell_kernel1_xdir_cpu_kernel.cpp"
#include "../MPI_OpenMP/advec_cell_kernel1_ydir_cpu_kernel.cpp"
#include "../MPI_OpenMP/advec_cell_kernel2_xdir_cpu_kernel.cpp"
#include "../MPI_OpenMP/advec_cell_kernel2_ydir_cpu_kernel.cpp"
#include "../MPI_OpenMP/advec_cell_kernel3_xdir_cpu_kernel.cpp"
#include "../MPI_OpenMP/advec_cell_kernel3_ydir_cpu_kernel.cpp"
#include "../MPI_OpenMP/advec_cell_kernel4_xdir_cpu_kernel.cpp"
#include "../MPI_OpenMP/advec_cell_kernel4_ydir_cpu_kernel.cpp"


#include "../MPI_OpenMP/advec_mom_kernel1_x_nonvector_cpu_kernel.cpp"
#include "../MPI_OpenMP/advec_mom_kernel1_y_nonvector_cpu_kernel.cpp"
#include "../MPI_OpenMP/advec_mom_kernel2_x_cpu_kernel.cpp"
#include "../MPI_OpenMP/advec_mom_kernel2_y_cpu_kernel.cpp"
#include "../MPI_OpenMP/advec_mom_kernel_mass_flux_x_cpu_kernel.cpp"
#include "../MPI_OpenMP/advec_mom_kernel_mass_flux_y_cpu_kernel.cpp"
#include "../MPI_OpenMP/advec_mom_kernel_post_pre_advec_x_cpu_kernel.cpp"
#include "../MPI_OpenMP/advec_mom_kernel_post_pre_advec_y_cpu_kernel.cpp"
#include "../MPI_OpenMP/advec_mom_kernel_x1_cpu_kernel.cpp"
#include "../MPI_OpenMP/advec_mom_kernel_x2_cpu_kernel.cpp"
#include "../MPI_OpenMP/advec_mom_kernel_y1_cpu_kernel.cpp"
#include "../MPI_OpenMP/advec_mom_kernel_y2_cpu_kernel.cpp"

#include "../MPI_OpenMP/calc_dt_kernel_get_cpu_kernel.cpp"
#include "../MPI_OpenMP/calc_dt_kernel_min_cpu_kernel.cpp"
#include "../MPI_OpenMP/calc_dt_kernel_print_cpu_kernel.cpp"
#include "../MPI_OpenMP/calc_dt_kernel_cpu_kernel.cpp"
#include "../MPI_OpenMP/field_summary_kernel_cpu_kernel.cpp"
#include "../MPI_OpenMP/flux_calc_kernelx_cpu_kernel.cpp"
#include "../MPI_OpenMP/flux_calc_kernely_cpu_kernel.cpp"
#include "../MPI_OpenMP/viscosity_kernel_cpu_kernel.cpp"
*/

#include "../MPI_OpenMP/generate_chunk_kernel_cpu_kernel.cpp"
#include "../MPI_OpenMP/initialise_chunk_kernel_cellx_cpu_kernel.cpp"
#include "../MPI_OpenMP/initialise_chunk_kernel_celly_cpu_kernel.cpp"
#include "../MPI_OpenMP/initialise_chunk_kernel_volume_cpu_kernel.cpp"
#include "../MPI_OpenMP/initialise_chunk_kernel_x_cpu_kernel.cpp"
#include "../MPI_OpenMP/initialise_chunk_kernel_xx_cpu_kernel.cpp"
#include "../MPI_OpenMP/initialise_chunk_kernel_y_cpu_kernel.cpp"
#include "../MPI_OpenMP/initialise_chunk_kernel_yy_cpu_kernel.cpp"
/*
#include "../MPI_OpenMP/update_halo_kernel1_b1_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel1_b2_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel1_l1_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel1_l2_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel1_r1_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel1_r2_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel1_t1_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel1_t2_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel2_xvel_minus_2_a_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel2_xvel_minus_2_b_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel2_xvel_minus_4_a_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel2_xvel_minus_4_b_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel2_xvel_plus_2_a_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel2_xvel_plus_2_b_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel2_xvel_plus_4_a_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel2_xvel_plus_4_b_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel2_yvel_minus_2_a_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel2_yvel_minus_2_b_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel2_yvel_minus_4_a_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel2_yvel_minus_4_b_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel2_yvel_plus_2_a_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel2_yvel_plus_2_b_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel2_yvel_plus_4_a_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel2_yvel_plus_4_b_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel3_minus_2_a_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel3_minus_2_b_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel3_minus_4_a_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel3_minus_4_b_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel3_plus_2_a_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel3_plus_2_b_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel3_plus_4_a_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel3_plus_4_b_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel4_minus_2_a_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel4_minus_2_b_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel4_minus_4_a_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel4_minus_4_b_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel4_plus_2_a_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel4_plus_2_b_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel4_plus_4_a_cpu_kernel.cpp"
#include "../MPI_OpenMP/update_halo_kernel4_plus_4_b_cpu_kernel.cpp"
*/
