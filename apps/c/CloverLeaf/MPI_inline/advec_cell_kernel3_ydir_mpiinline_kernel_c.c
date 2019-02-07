//
// auto-generated by ops.py
//

int xdim0_advec_cell_kernel3_ydir;
int xdim1_advec_cell_kernel3_ydir;
int xdim2_advec_cell_kernel3_ydir;
int xdim3_advec_cell_kernel3_ydir;
int xdim4_advec_cell_kernel3_ydir;
int xdim5_advec_cell_kernel3_ydir;
int xdim6_advec_cell_kernel3_ydir;
int xdim7_advec_cell_kernel3_ydir;


#define OPS_ACC0(x,y) (n_x*1+n_y*xdim0_advec_cell_kernel3_ydir*1+x+xdim0_advec_cell_kernel3_ydir*(y))
#define OPS_ACC1(x,y) (n_x*1+n_y*xdim1_advec_cell_kernel3_ydir*1+x+xdim1_advec_cell_kernel3_ydir*(y))
#define OPS_ACC2(x,y) (n_x*0+n_y*xdim2_advec_cell_kernel3_ydir*1+x+xdim2_advec_cell_kernel3_ydir*(y))
#define OPS_ACC3(x,y) (n_x*0+n_y*xdim3_advec_cell_kernel3_ydir*1+x+xdim3_advec_cell_kernel3_ydir*(y))
#define OPS_ACC4(x,y) (n_x*1+n_y*xdim4_advec_cell_kernel3_ydir*1+x+xdim4_advec_cell_kernel3_ydir*(y))
#define OPS_ACC5(x,y) (n_x*1+n_y*xdim5_advec_cell_kernel3_ydir*1+x+xdim5_advec_cell_kernel3_ydir*(y))
#define OPS_ACC6(x,y) (n_x*1+n_y*xdim6_advec_cell_kernel3_ydir*1+x+xdim6_advec_cell_kernel3_ydir*(y))
#define OPS_ACC7(x,y) (n_x*1+n_y*xdim7_advec_cell_kernel3_ydir*1+x+xdim7_advec_cell_kernel3_ydir*(y))

//user function



void advec_cell_kernel3_ydir_c_wrapper(
  const double * restrict vol_flux_y,
  const double * restrict pre_vol,
  const int * restrict yy,
  const double * restrict vertexdy,
  const double * restrict density1,
  const double * restrict energy1,
  double * restrict mass_flux_y,
  double * restrict ener_flux,
  int x_size, int y_size) {
  #pragma omp parallel for
  for ( int n_y=0; n_y<y_size; n_y++ ){
    for ( int n_x=0; n_x<x_size; n_x++ ){
      

  double sigmat, sigmav, sigmam, sigma3, sigma4;
  double diffuw, diffdw, limiter;
  double one_by_six = 1.0/6.0;

  int y_max=field.y_max;

  int upwind,donor,downwind,dif;





  if(vol_flux_y[OPS_ACC0(0,0)] > 0.0) {
    upwind   = -2;
    donor    = -1;
    downwind = 0;
    dif      = donor;
  }
  else if (yy[OPS_ACC2(0,1)] < y_max+2-2) {
    upwind   = 1;
    donor    = 0;
    downwind = -1;
    dif      = upwind;
  } else {
    upwind   = 0;
    donor    = 0;
    downwind = -1;
    dif      = upwind;
  }


  sigmat = fabs(vol_flux_y[OPS_ACC0(0,0)])/pre_vol[OPS_ACC1(0,donor)];
  sigma3 = (1.0 + sigmat)*(vertexdy[OPS_ACC3(0,0)]/vertexdy[OPS_ACC3(0,dif)]);
  sigma4 = 2.0 - sigmat;

  sigmav = sigmat;

  diffuw = density1[OPS_ACC4(0,donor)] - density1[OPS_ACC4(0,upwind)];
  diffdw = density1[OPS_ACC4(0,downwind)] - density1[OPS_ACC4(0,donor)];

  if( (diffuw*diffdw) > 0.0)
    limiter=(1.0 - sigmav) * SIGN(1.0 , diffdw) *
    MIN( MIN(fabs(diffuw), fabs(diffdw)),
    one_by_six * (sigma3*fabs(diffuw) + sigma4 * fabs(diffdw)));
  else
    limiter=0.0;

  mass_flux_y[OPS_ACC6(0,0)] = (vol_flux_y[OPS_ACC0(0,0)]) * ( density1[OPS_ACC4(0,donor)] + limiter );

  sigmam = fabs(mass_flux_y[OPS_ACC6(0,0)])/( density1[OPS_ACC4(0,donor)] * pre_vol[OPS_ACC1(0,donor)]);
  diffuw = energy1[OPS_ACC5(0,donor)] - energy1[OPS_ACC5(0,upwind)];
  diffdw = energy1[OPS_ACC5(0,downwind)] - energy1[OPS_ACC5(0,donor)];

  if( (diffuw*diffdw) > 0.0)
    limiter = (1.0 - sigmam) * SIGN(1.0,diffdw) *
    MIN( MIN(fabs(diffuw), fabs(diffdw)),
    one_by_six * (sigma3 * fabs(diffuw) + sigma4 * fabs(diffdw)));
  else
    limiter=0.0;

  ener_flux[OPS_ACC7(0,0)] = mass_flux_y[OPS_ACC6(0,0)] * ( energy1[OPS_ACC5(0,donor)] + limiter );

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

