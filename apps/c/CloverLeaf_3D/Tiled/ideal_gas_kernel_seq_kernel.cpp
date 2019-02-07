//
// auto-generated by ops.py
//
#define OPS_ACC0(x, y, z)                                                      \
  (n_x * 1 + n_y * xdim0_ideal_gas_kernel * 1 +                                \
   n_z * xdim0_ideal_gas_kernel * ydim0_ideal_gas_kernel * 1 + x +             \
   xdim0_ideal_gas_kernel * (y) +                                              \
   xdim0_ideal_gas_kernel * ydim0_ideal_gas_kernel * (z))
#define OPS_ACC1(x, y, z)                                                      \
  (n_x * 1 + n_y * xdim1_ideal_gas_kernel * 1 +                                \
   n_z * xdim1_ideal_gas_kernel * ydim1_ideal_gas_kernel * 1 + x +             \
   xdim1_ideal_gas_kernel * (y) +                                              \
   xdim1_ideal_gas_kernel * ydim1_ideal_gas_kernel * (z))
#define OPS_ACC2(x, y, z)                                                      \
  (n_x * 1 + n_y * xdim2_ideal_gas_kernel * 1 +                                \
   n_z * xdim2_ideal_gas_kernel * ydim2_ideal_gas_kernel * 1 + x +             \
   xdim2_ideal_gas_kernel * (y) +                                              \
   xdim2_ideal_gas_kernel * ydim2_ideal_gas_kernel * (z))
#define OPS_ACC3(x, y, z)                                                      \
  (n_x * 1 + n_y * xdim3_ideal_gas_kernel * 1 +                                \
   n_z * xdim3_ideal_gas_kernel * ydim3_ideal_gas_kernel * 1 + x +             \
   xdim3_ideal_gas_kernel * (y) +                                              \
   xdim3_ideal_gas_kernel * ydim3_ideal_gas_kernel * (z))

// user function

// host stub function
void ops_par_loop_ideal_gas_kernel_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];

  // Timing
  double t1, t2, c1, c2;

  ops_arg args[4] = {arg0, arg1, arg2, arg3};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 4, range, 11))
    return;
#endif

  if (OPS_diags > 1) {
    OPS_kernels[11].count++;
    ops_timers_core(&c2, &t2);
  }

  // compute locally allocated range for the sub-block
  int start[3];
  int end[3];

  for (int n = 0; n < 3; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }

#ifdef OPS_DEBUG
  ops_register_args(args, "ideal_gas_kernel");
#endif

  // set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  const double *__restrict__ density = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  const double *__restrict__ energy = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double *__restrict__ pressure = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double *__restrict__ soundspeed = (double *)(args[3].data + base3);

  // initialize global variable with the dimension of dats
  int xdim0_ideal_gas_kernel = args[0].dat->size[0];
  int ydim0_ideal_gas_kernel = args[0].dat->size[1];
  int xdim1_ideal_gas_kernel = args[1].dat->size[0];
  int ydim1_ideal_gas_kernel = args[1].dat->size[1];
  int xdim2_ideal_gas_kernel = args[2].dat->size[0];
  int ydim2_ideal_gas_kernel = args[2].dat->size[1];
  int xdim3_ideal_gas_kernel = args[3].dat->size[0];
  int ydim3_ideal_gas_kernel = args[3].dat->size[1];

  if (OPS_diags > 1) {
    ops_timers_core(&c1, &t1);
    OPS_kernels[11].mpi_time += t1 - t2;
  }

#pragma omp parallel for collapse(2)
  for (int n_z = start[2]; n_z < end[2]; n_z++) {
    for (int n_y = start[1]; n_y < end[1]; n_y++) {
#ifdef intel
#pragma loop_count(10000)
#pragma omp simd aligned(density, energy, pressure, soundspeed)
#else
#pragma simd
#endif
      for (int n_x = start[0]; n_x < end[0]; n_x++) {

        double sound_speed_squared, v, pressurebyenergy, pressurebyvolume;

        v = 1.0 / density[OPS_ACC0(0, 0, 0)];
        pressure[OPS_ACC2(0, 0, 0)] = (1.4 - 1.0) * density[OPS_ACC0(0, 0, 0)] *
                                      energy[OPS_ACC1(0, 0, 0)];

        pressurebyenergy = (1.4 - 1.0) * density[OPS_ACC0(0, 0, 0)];
        pressurebyvolume =
            -1.0 * density[OPS_ACC0(0, 0, 0)] * pressure[OPS_ACC2(0, 0, 0)];
        sound_speed_squared =
            v * v *
            (pressure[OPS_ACC2(0, 0, 0)] * pressurebyenergy - pressurebyvolume);
        soundspeed[OPS_ACC3(0, 0, 0)] = sqrt(sound_speed_squared);
      }
    }
  }
  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[11].time += t2 - t1;
  }

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c1, &t1);
    OPS_kernels[11].mpi_time += t1 - t2;
    OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[11].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3

void ops_par_loop_ideal_gas_kernel(char const *name, ops_block block, int dim,
                                   int *range, ops_arg arg0, ops_arg arg1,
                                   ops_arg arg2, ops_arg arg3) {
  ops_kernel_descriptor *desc =
      (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 11;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 11;
  for (int i = 0; i < 6; i++) {
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 4;
  desc->args = (ops_arg *)malloc(4 * sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->function = ops_par_loop_ideal_gas_kernel_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(11, "ideal_gas_kernel");
  }
  ops_enqueue_kernel(desc);
}
