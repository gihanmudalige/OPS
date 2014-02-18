//
// auto-generated by ops.py on 2014-02-18 13:25
//



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


#include  "ops_lib_cpp.h"

//
// ops_par_loop declarations
//

void ops_par_loop_ideal_gas_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );

void ops_par_loop_ideal_gas_kernel(char const *, ops_block, int , int*,
  ops_arg,
  ops_arg,
  ops_arg,
  ops_arg );



#include "data.h"
#include "definitions.h"

//#include "ideal_gas_kernel.h"

void ideal_gas(int predict)
{

  int x_cells = grid->x_cells;
  int y_cells = grid->y_cells;
  int x_min = field->x_min;
  int x_max = field->x_max;
  int y_min = field->y_min;
  int y_max = field->y_max;

  int rangexy_inner[] = {x_min,x_max,y_min,y_max};

  if(predict != TRUE) {
    ops_par_loop_ideal_gas_kernel("ideal_gas_kernel", clover_grid, 2, rangexy_inner,
                 ops_arg_dat(density0, S2D_00, "double", OPS_READ),
                 ops_arg_dat(energy0, S2D_00, "double", OPS_READ),
                 ops_arg_dat(pressure, S2D_00, "double", OPS_READ),
                 ops_arg_dat(soundspeed, S2D_00, "double", OPS_READ));
  }
  else {
    ops_par_loop_ideal_gas_kernel("ideal_gas_kernel", clover_grid, 2, rangexy_inner,
                 ops_arg_dat(density1, S2D_00, "double", OPS_READ),
                 ops_arg_dat(energy1, S2D_00, "double", OPS_READ),
                 ops_arg_dat(pressure, S2D_00, "double", OPS_READ),
                 ops_arg_dat(soundspeed, S2D_00, "double", OPS_READ));
  }
}
