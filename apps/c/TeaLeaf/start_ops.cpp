//
// auto-generated by ops.py//



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include  "ops_lib_cpp.h"




#include "data.h"
#include "definitions.h"


void initialise_chunk();
void generate();
void build_field();
void update_halo(int* fields, int depth);
void set_field();
void field_summary();

void start()
{

  if (ops_is_root()) {
    ops_fprintf(g_out," Setting up initial geometry\n");
    ops_fprintf(g_out,"\n");
  }

  time = 0.0;
  step  = 0;
  dt    = dtinit;

  build_field();

    ops_decl_const2( "field",1, "field_type",&field);
  ops_decl_const2( "grid",1, "grid_type",&grid);
  ops_decl_const2( "number_of_states",1, "int",&number_of_states);
  ops_decl_const2( "states",number_of_states, "state_type",states);
  ops_decl_const2( "g_circ",1, "int",&g_circ);
  ops_decl_const2( "g_point",1, "int",&g_point);
  ops_decl_const2( "g_rect",1, "int",&g_rect);


  initialise_chunk();



  ops_fprintf(g_out,"\n");
  ops_fprintf(g_out," Generating chunks\n");
  ops_fprintf(g_out,"\n");

  generate();


  fields[0]=0;fields[1]=0;fields[2]=0;fields[3]=0;fields[4]=0;fields[5]=0;fields[6]=0;
  fields[FIELD_DENSITY]  = 1;
  fields[FIELD_ENERGY0]   = 1;
  fields[FIELD_ENERGY1]   = 1;

  update_halo(fields, 1);

  ops_fprintf(g_out,"\n");
  ops_fprintf(g_out," Problem initialised and generated\n");
  ops_fprintf(g_out,"\n");


  set_field();

  field_summary();

}
