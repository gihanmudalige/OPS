//
// auto-generated by ops.py
//

int xdim0_accelerate_kernel;
int xdim1_accelerate_kernel;
int xdim2_accelerate_kernel;
int xdim3_accelerate_kernel;
int xdim4_accelerate_kernel;
int xdim5_accelerate_kernel;
int xdim6_accelerate_kernel;
int xdim7_accelerate_kernel;
int xdim8_accelerate_kernel;
int xdim9_accelerate_kernel;
int xdim10_accelerate_kernel;


//user function



void accelerate_kernel_c_wrapper(
  double * restrict density0_p,
  double * restrict volume_p,
  double * restrict stepbymass_p,
  double * restrict xvel0_p,
  double * restrict xvel1_p,
  double * restrict xarea_p,
  double * restrict pressure_p,
  double * restrict yvel0_p,
  double * restrict yvel1_p,
  double * restrict yarea_p,
  double * restrict viscosity_p,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      const ptr_double density0 = { density0_p + n_x*1 + n_y * xdim0_accelerate_kernel*1, xdim0_accelerate_kernel};
      const ptr_double volume = { volume_p + n_x*1 + n_y * xdim1_accelerate_kernel*1, xdim1_accelerate_kernel};
      ptr_double stepbymass = { stepbymass_p + n_x*1 + n_y * xdim2_accelerate_kernel*1, xdim2_accelerate_kernel};
      const ptr_double xvel0 = { xvel0_p + n_x*1 + n_y * xdim3_accelerate_kernel*1, xdim3_accelerate_kernel};
      ptr_double xvel1 = { xvel1_p + n_x*1 + n_y * xdim4_accelerate_kernel*1, xdim4_accelerate_kernel};
      const ptr_double xarea = { xarea_p + n_x*1 + n_y * xdim5_accelerate_kernel*1, xdim5_accelerate_kernel};
      const ptr_double pressure = { pressure_p + n_x*1 + n_y * xdim6_accelerate_kernel*1, xdim6_accelerate_kernel};
      const ptr_double yvel0 = { yvel0_p + n_x*1 + n_y * xdim7_accelerate_kernel*1, xdim7_accelerate_kernel};
      ptr_double yvel1 = { yvel1_p + n_x*1 + n_y * xdim8_accelerate_kernel*1, xdim8_accelerate_kernel};
      const ptr_double yarea = { yarea_p + n_x*1 + n_y * xdim9_accelerate_kernel*1, xdim9_accelerate_kernel};
      const ptr_double viscosity = { viscosity_p + n_x*1 + n_y * xdim10_accelerate_kernel*1, xdim10_accelerate_kernel};
      

  double nodal_mass;

  nodal_mass = ( OPS_ACC(density0, -1,-1) * OPS_ACC(volume, -1,-1)
    + OPS_ACC(density0, 0,-1) * OPS_ACC(volume, 0,-1)
    + OPS_ACC(density0, 0,0) * OPS_ACC(volume, 0,0)
    + OPS_ACC(density0, -1,0) * OPS_ACC(volume, -1,0) ) * 0.25;

  OPS_ACC(stepbymass, 0,0) = 0.5*dt/ nodal_mass;



  OPS_ACC(xvel1, 0,0) = OPS_ACC(xvel0, 0,0) - OPS_ACC(stepbymass, 0,0) *
            ( OPS_ACC(xarea, 0,0)  * ( OPS_ACC(pressure, 0,0) - OPS_ACC(pressure, -1,0) ) +
              OPS_ACC(xarea, 0,-1) * ( OPS_ACC(pressure, 0,-1) - OPS_ACC(pressure, -1,-1) ) );



  OPS_ACC(yvel1, 0,0) = OPS_ACC(yvel0, 0,0) - OPS_ACC(stepbymass, 0,0) *
            ( OPS_ACC(yarea, 0,0)  * ( OPS_ACC(pressure, 0,0) - OPS_ACC(pressure, 0,-1) ) +
              OPS_ACC(yarea, -1,0) * ( OPS_ACC(pressure, -1,0) - OPS_ACC(pressure, -1,-1) ) );



  OPS_ACC(xvel1, 0,0) = OPS_ACC(xvel1, 0,0) - OPS_ACC(stepbymass, 0,0) *
            ( OPS_ACC(xarea, 0,0) * ( OPS_ACC(viscosity, 0,0) - OPS_ACC(viscosity, -1,0) ) +
              OPS_ACC(xarea, 0,-1) * ( OPS_ACC(viscosity, 0,-1) - OPS_ACC(viscosity, -1,-1) ) );



  OPS_ACC(yvel1, 0,0) = OPS_ACC(yvel1, 0,0) - OPS_ACC(stepbymass, 0,0) *
            ( OPS_ACC(yarea, 0,0) * ( OPS_ACC(viscosity, 0,0) - OPS_ACC(viscosity, 0,-1) ) +
              OPS_ACC(yarea, -1,0) * ( OPS_ACC(viscosity, -1,0) - OPS_ACC(viscosity, -1,-1) ) );


    }
  }
}
