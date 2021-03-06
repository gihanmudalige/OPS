//
// auto-generated by ops.py//

// header
#define OPS_3D
#define OPS_ACC_MACROS
#define OPS_ACC_MD_MACROS
#include "ops_lib_cpp.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif
#include "user_types.h"

// global constants
extern double g_small;
extern double g_big;
extern double dtc_safe;
extern double dtu_safe;
extern double dtv_safe;
extern double dtw_safe;
extern double dtdiv_safe;
extern field_type field;
extern grid_type grid;
extern state_type *states;
extern int number_of_states;
extern int g_sphe;
extern int g_point;
extern int g_cube;
extern double dt;

void ops_init_backend() {}

// user kernel files
#include "PdV_kernel_nopredict_seq_kernel.cpp"
#include "PdV_kernel_predict_seq_kernel.cpp"
#include "accelerate_kernel_seq_kernel.cpp"
#include "advec_cell_kernel1_xdir_seq_kernel.cpp"
#include "advec_cell_kernel1_ydir_seq_kernel.cpp"
#include "advec_cell_kernel1_zdir_seq_kernel.cpp"
#include "advec_cell_kernel2_xdir_seq_kernel.cpp"
#include "advec_cell_kernel2_ydir_seq_kernel.cpp"
#include "advec_cell_kernel2_zdir_seq_kernel.cpp"
#include "advec_cell_kernel3_xdir_seq_kernel.cpp"
#include "advec_cell_kernel3_ydir_seq_kernel.cpp"
#include "advec_cell_kernel3_zdir_seq_kernel.cpp"
#include "advec_cell_kernel4_xdir_seq_kernel.cpp"
#include "advec_cell_kernel4_ydir_seq_kernel.cpp"
#include "advec_cell_kernel4_zdir_seq_kernel.cpp"
#include "advec_mom_kernel1_x_nonvector_seq_kernel.cpp"
#include "advec_mom_kernel1_y_nonvector_seq_kernel.cpp"
#include "advec_mom_kernel1_z_nonvector_seq_kernel.cpp"
#include "advec_mom_kernel2_x_seq_kernel.cpp"
#include "advec_mom_kernel2_y_seq_kernel.cpp"
#include "advec_mom_kernel2_z_seq_kernel.cpp"
#include "advec_mom_kernel_mass_flux_x_seq_kernel.cpp"
#include "advec_mom_kernel_mass_flux_y_seq_kernel.cpp"
#include "advec_mom_kernel_mass_flux_z_seq_kernel.cpp"
#include "advec_mom_kernel_post_pre_advec_x_seq_kernel.cpp"
#include "advec_mom_kernel_post_pre_advec_y_seq_kernel.cpp"
#include "advec_mom_kernel_post_pre_advec_z_seq_kernel.cpp"
#include "advec_mom_kernel_x1_seq_kernel.cpp"
#include "advec_mom_kernel_x2_seq_kernel.cpp"
#include "advec_mom_kernel_x3_seq_kernel.cpp"
#include "advec_mom_kernel_y2_seq_kernel.cpp"
#include "advec_mom_kernel_z1_seq_kernel.cpp"
#include "advec_mom_kernel_z3_seq_kernel.cpp"
#include "calc_dt_kernel_get_seq_kernel.cpp"
#include "calc_dt_kernel_min_seq_kernel.cpp"
#include "calc_dt_kernel_print_seq_kernel.cpp"
#include "calc_dt_kernel_seq_kernel.cpp"
#include "field_summary_kernel_seq_kernel.cpp"
#include "flux_calc_kernelx_seq_kernel.cpp"
#include "flux_calc_kernely_seq_kernel.cpp"
#include "flux_calc_kernelz_seq_kernel.cpp"
#include "ideal_gas_kernel_seq_kernel.cpp"
#include "initialise_chunk_kernel_cellx_seq_kernel.cpp"
#include "initialise_chunk_kernel_celly_seq_kernel.cpp"
#include "initialise_chunk_kernel_cellz_seq_kernel.cpp"
#include "initialise_chunk_kernel_volume_seq_kernel.cpp"
#include "initialise_chunk_kernel_x_seq_kernel.cpp"
#include "initialise_chunk_kernel_xx_seq_kernel.cpp"
#include "initialise_chunk_kernel_y_seq_kernel.cpp"
#include "initialise_chunk_kernel_yy_seq_kernel.cpp"
#include "initialise_chunk_kernel_z_seq_kernel.cpp"
#include "initialise_chunk_kernel_zz_seq_kernel.cpp"
#include "reset_field_kernel1_seq_kernel.cpp"
#include "reset_field_kernel2_seq_kernel.cpp"
#include "revert_kernel_seq_kernel.cpp"
#include "update_halo_kernel1_b1_seq_kernel.cpp"
#include "update_halo_kernel1_b2_seq_kernel.cpp"
#include "update_halo_kernel1_ba1_seq_kernel.cpp"
#include "update_halo_kernel1_ba2_seq_kernel.cpp"
#include "update_halo_kernel1_fr1_seq_kernel.cpp"
#include "update_halo_kernel1_fr2_seq_kernel.cpp"
#include "update_halo_kernel1_l1_seq_kernel.cpp"
#include "update_halo_kernel1_l2_seq_kernel.cpp"
#include "update_halo_kernel1_r1_seq_kernel.cpp"
#include "update_halo_kernel1_r2_seq_kernel.cpp"
#include "update_halo_kernel1_t1_seq_kernel.cpp"
#include "update_halo_kernel1_t2_seq_kernel.cpp"
#include "update_halo_kernel2_xvel_minus_2_left_seq_kernel.cpp"
#include "update_halo_kernel2_xvel_minus_2_right_seq_kernel.cpp"
#include "update_halo_kernel2_xvel_minus_4_left_seq_kernel.cpp"
#include "update_halo_kernel2_xvel_minus_4_right_seq_kernel.cpp"
#include "update_halo_kernel2_xvel_plus_2_back_seq_kernel.cpp"
#include "update_halo_kernel2_xvel_plus_2_bot_seq_kernel.cpp"
#include "update_halo_kernel2_xvel_plus_2_front_seq_kernel.cpp"
#include "update_halo_kernel2_xvel_plus_2_top_seq_kernel.cpp"
#include "update_halo_kernel2_xvel_plus_4_back_seq_kernel.cpp"
#include "update_halo_kernel2_xvel_plus_4_bot_seq_kernel.cpp"
#include "update_halo_kernel2_xvel_plus_4_front_seq_kernel.cpp"
#include "update_halo_kernel2_xvel_plus_4_top_seq_kernel.cpp"
#include "update_halo_kernel2_yvel_minus_2_bot_seq_kernel.cpp"
#include "update_halo_kernel2_yvel_minus_2_top_seq_kernel.cpp"
#include "update_halo_kernel2_yvel_minus_4_bot_seq_kernel.cpp"
#include "update_halo_kernel2_yvel_minus_4_top_seq_kernel.cpp"
#include "update_halo_kernel2_yvel_plus_2_back_seq_kernel.cpp"
#include "update_halo_kernel2_yvel_plus_2_front_seq_kernel.cpp"
#include "update_halo_kernel2_yvel_plus_2_left_seq_kernel.cpp"
#include "update_halo_kernel2_yvel_plus_2_right_seq_kernel.cpp"
#include "update_halo_kernel2_yvel_plus_4_back_seq_kernel.cpp"
#include "update_halo_kernel2_yvel_plus_4_front_seq_kernel.cpp"
#include "update_halo_kernel2_yvel_plus_4_left_seq_kernel.cpp"
#include "update_halo_kernel2_yvel_plus_4_right_seq_kernel.cpp"
#include "update_halo_kernel2_zvel_minus_2_back_seq_kernel.cpp"
#include "update_halo_kernel2_zvel_minus_2_front_seq_kernel.cpp"
#include "update_halo_kernel2_zvel_minus_4_back_seq_kernel.cpp"
#include "update_halo_kernel2_zvel_minus_4_front_seq_kernel.cpp"
#include "update_halo_kernel2_zvel_plus_2_bot_seq_kernel.cpp"
#include "update_halo_kernel2_zvel_plus_2_left_seq_kernel.cpp"
#include "update_halo_kernel2_zvel_plus_2_right_seq_kernel.cpp"
#include "update_halo_kernel2_zvel_plus_2_top_seq_kernel.cpp"
#include "update_halo_kernel2_zvel_plus_4_bot_seq_kernel.cpp"
#include "update_halo_kernel2_zvel_plus_4_left_seq_kernel.cpp"
#include "update_halo_kernel2_zvel_plus_4_right_seq_kernel.cpp"
#include "update_halo_kernel2_zvel_plus_4_top_seq_kernel.cpp"
#include "update_halo_kernel3_minus_2_a_seq_kernel.cpp"
#include "update_halo_kernel3_minus_2_b_seq_kernel.cpp"
#include "update_halo_kernel3_minus_4_a_seq_kernel.cpp"
#include "update_halo_kernel3_minus_4_b_seq_kernel.cpp"
#include "update_halo_kernel3_plus_2_a_seq_kernel.cpp"
#include "update_halo_kernel3_plus_2_b_seq_kernel.cpp"
#include "update_halo_kernel3_plus_2_back_seq_kernel.cpp"
#include "update_halo_kernel3_plus_2_front_seq_kernel.cpp"
#include "update_halo_kernel3_plus_4_a_seq_kernel.cpp"
#include "update_halo_kernel3_plus_4_b_seq_kernel.cpp"
#include "update_halo_kernel3_plus_4_back_seq_kernel.cpp"
#include "update_halo_kernel3_plus_4_front_seq_kernel.cpp"
#include "update_halo_kernel4_minus_2_a_seq_kernel.cpp"
#include "update_halo_kernel4_minus_2_b_seq_kernel.cpp"
#include "update_halo_kernel4_minus_4_a_seq_kernel.cpp"
#include "update_halo_kernel4_minus_4_b_seq_kernel.cpp"
#include "update_halo_kernel4_plus_2_a_seq_kernel.cpp"
#include "update_halo_kernel4_plus_2_b_seq_kernel.cpp"
#include "update_halo_kernel4_plus_2_back_seq_kernel.cpp"
#include "update_halo_kernel4_plus_2_front_seq_kernel.cpp"
#include "update_halo_kernel4_plus_4_a_seq_kernel.cpp"
#include "update_halo_kernel4_plus_4_b_seq_kernel.cpp"
#include "update_halo_kernel4_plus_4_back_seq_kernel.cpp"
#include "update_halo_kernel4_plus_4_front_seq_kernel.cpp"
#include "update_halo_kernel5_minus_2_back_seq_kernel.cpp"
#include "update_halo_kernel5_minus_2_front_seq_kernel.cpp"
#include "update_halo_kernel5_minus_4_back_seq_kernel.cpp"
#include "update_halo_kernel5_minus_4_front_seq_kernel.cpp"
#include "update_halo_kernel5_plus_2_a_seq_kernel.cpp"
#include "update_halo_kernel5_plus_2_b_seq_kernel.cpp"
#include "update_halo_kernel5_plus_2_left_seq_kernel.cpp"
#include "update_halo_kernel5_plus_2_right_seq_kernel.cpp"
#include "update_halo_kernel5_plus_4_a_seq_kernel.cpp"
#include "update_halo_kernel5_plus_4_b_seq_kernel.cpp"
#include "update_halo_kernel5_plus_4_left_seq_kernel.cpp"
#include "update_halo_kernel5_plus_4_right_seq_kernel.cpp"
#include "viscosity_kernel_seq_kernel.cpp"
