//
// auto-generated by ops.py
//

// user function
inline void generate_chunk_kernel(const double *vertexx, const double *vertexy,
                                  double *energy0, double *density0,
                                  double *xvel0, double *yvel0,
                                  const double *cellx, const double *celly) {

  double radius, x_cent, y_cent;
  int is_in = 0;
  int is_in2 = 0;

  energy0[OPS_ACC2(0, 0)] = states[0].energy;
  density0[OPS_ACC3(0, 0)] = states[0].density;
  xvel0[OPS_ACC4(0, 0)] = states[0].xvel;
  yvel0[OPS_ACC5(0, 0)] = states[0].yvel;

  for (int i = 1; i < number_of_states; i++) {

    x_cent = states[i].xmin;
    y_cent = states[i].ymin;
    is_in = 0;
    is_in2 = 0;

    if (states[i].geometry == g_rect) {
      for (int i1 = -1; i1 <= 0; i1++) {
        for (int j1 = -1; j1 <= 0; j1++) {
          if (vertexx[OPS_ACC0(1 + i1, 0)] >= states[i].xmin &&
              vertexx[OPS_ACC0(0 + i1, 0)] < states[i].xmax) {
            if (vertexy[OPS_ACC1(0, 1 + j1)] >= states[i].ymin &&
                vertexy[OPS_ACC1(0, 0 + j1)] < states[i].ymax) {
              is_in = 1;
            }
          }
        }
      }
      if (vertexx[OPS_ACC0(1, 0)] >= states[i].xmin &&
          vertexx[OPS_ACC0(0, 0)] < states[i].xmax) {
        if (vertexy[OPS_ACC1(0, 1)] >= states[i].ymin &&
            vertexy[OPS_ACC1(0, 0)] < states[i].ymax) {
          is_in2 = 1;
        }
      }
      if (is_in2) {
        energy0[OPS_ACC2(0, 0)] = states[i].energy;
        density0[OPS_ACC3(0, 0)] = states[i].density;
      }
      if (is_in) {
        xvel0[OPS_ACC4(0, 0)] = states[i].xvel;
        yvel0[OPS_ACC5(0, 0)] = states[i].yvel;
      }
    } else if (states[i].geometry == g_circ) {
      for (int i1 = -1; i1 <= 0; i1++) {
        for (int j1 = -1; j1 <= 0; j1++) {
          radius = sqrt((cellx[OPS_ACC6(i1, 0)] - x_cent) *
                            (cellx[OPS_ACC6(i1, 0)] - x_cent) +
                        (celly[OPS_ACC7(0, j1)] - y_cent) *
                            (celly[OPS_ACC7(0, j1)] - y_cent));
          if (radius <= states[i].radius) {
            is_in = 1;
          }
        }
      }
      if (radius <= states[i].radius)
        is_in2 = 1;

      if (is_in2) {
        energy0[OPS_ACC2(0, 0)] = states[i].energy;
        density0[OPS_ACC3(0, 0)] = states[i].density;
      }

      if (is_in) {
        xvel0[OPS_ACC4(0, 0)] = states[i].xvel;
        yvel0[OPS_ACC5(0, 0)] = states[i].yvel;
      }
    } else if (states[i].geometry == g_point) {
      for (int i1 = -1; i1 <= 0; i1++) {
        for (int j1 = -1; j1 <= 0; j1++) {
          if (vertexx[OPS_ACC0(i1, 0)] == x_cent &&
              vertexy[OPS_ACC1(0, j1)] == y_cent) {
            is_in = 1;
          }
        }
      }
      if (vertexx[OPS_ACC0(0, 0)] == x_cent &&
          vertexy[OPS_ACC1(0, 0)] == y_cent)
        is_in2 = 1;

      if (is_in2) {
        energy0[OPS_ACC2(0, 0)] = states[i].energy;
        density0[OPS_ACC3(0, 0)] = states[i].density;
      }

      if (is_in) {
        xvel0[OPS_ACC4(0, 0)] = states[i].xvel;
        yvel0[OPS_ACC5(0, 0)] = states[i].yvel;
      }
    }
  }
}

// host stub function
void ops_par_loop_generate_chunk_kernel(char const *name, ops_block block,
                                        int dim, int *range, ops_arg arg0,
                                        ops_arg arg1, ops_arg arg2,
                                        ops_arg arg3, ops_arg arg4,
                                        ops_arg arg5, ops_arg arg6,
                                        ops_arg arg7) {

  // Timing
  double t1, t2, c1, c2;

  char *p_a[8];
  int offs[8][2];
  ops_arg args[8] = {arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 8, range, 7))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(7, "generate_chunk_kernel");
    OPS_kernels[7].count++;
    ops_timers_core(&c2, &t2);
  }

  // compute locally allocated range for the sub-block
  int start[2];
  int end[2];

#ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned)
    return;
  for (int n = 0; n < 2; n++) {
    start[n] = sb->decomp_disp[n];
    end[n] = sb->decomp_disp[n] + sb->decomp_size[n];
    if (start[n] >= range[2 * n]) {
      start[n] = 0;
    } else {
      start[n] = range[2 * n] - start[n];
    }
    if (sb->id_m[n] == MPI_PROC_NULL && range[2 * n] < 0)
      start[n] = range[2 * n];
    if (end[n] >= range[2 * n + 1]) {
      end[n] = range[2 * n + 1] - sb->decomp_disp[n];
    } else {
      end[n] = sb->decomp_size[n];
    }
    if (sb->id_p[n] == MPI_PROC_NULL &&
        (range[2 * n + 1] > sb->decomp_disp[n] + sb->decomp_size[n]))
      end[n] += (range[2 * n + 1] - sb->decomp_disp[n] - sb->decomp_size[n]);
  }
#else
  for (int n = 0; n < 2; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }
#endif
#ifdef OPS_DEBUG
  ops_register_args(args, "generate_chunk_kernel");
#endif

  offs[0][0] = args[0].stencil->stride[0] * 1; // unit step in x dimension
  offs[0][1] =
      off2D(1, &start[0], &end[0], args[0].dat->size, args[0].stencil->stride) -
      offs[0][0];

  offs[1][0] = args[1].stencil->stride[0] * 1; // unit step in x dimension
  offs[1][1] =
      off2D(1, &start[0], &end[0], args[1].dat->size, args[1].stencil->stride) -
      offs[1][0];

  offs[2][0] = args[2].stencil->stride[0] * 1; // unit step in x dimension
  offs[2][1] =
      off2D(1, &start[0], &end[0], args[2].dat->size, args[2].stencil->stride) -
      offs[2][0];

  offs[3][0] = args[3].stencil->stride[0] * 1; // unit step in x dimension
  offs[3][1] =
      off2D(1, &start[0], &end[0], args[3].dat->size, args[3].stencil->stride) -
      offs[3][0];

  offs[4][0] = args[4].stencil->stride[0] * 1; // unit step in x dimension
  offs[4][1] =
      off2D(1, &start[0], &end[0], args[4].dat->size, args[4].stencil->stride) -
      offs[4][0];

  offs[5][0] = args[5].stencil->stride[0] * 1; // unit step in x dimension
  offs[5][1] =
      off2D(1, &start[0], &end[0], args[5].dat->size, args[5].stencil->stride) -
      offs[5][0];

  offs[6][0] = args[6].stencil->stride[0] * 1; // unit step in x dimension
  offs[6][1] =
      off2D(1, &start[0], &end[0], args[6].dat->size, args[6].stencil->stride) -
      offs[6][0];

  offs[7][0] = args[7].stencil->stride[0] * 1; // unit step in x dimension
  offs[7][1] =
      off2D(1, &start[0], &end[0], args[7].dat->size, args[7].stencil->stride) -
      offs[7][0];

  int off0_0 = offs[0][0];
  int off0_1 = offs[0][1];
  int dat0 = (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size);
  int off1_0 = offs[1][0];
  int off1_1 = offs[1][1];
  int dat1 = (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size);
  int off2_0 = offs[2][0];
  int off2_1 = offs[2][1];
  int dat2 = (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size);
  int off3_0 = offs[3][0];
  int off3_1 = offs[3][1];
  int dat3 = (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size);
  int off4_0 = offs[4][0];
  int off4_1 = offs[4][1];
  int dat4 = (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size);
  int off5_0 = offs[5][0];
  int off5_1 = offs[5][1];
  int dat5 = (OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size);
  int off6_0 = offs[6][0];
  int off6_1 = offs[6][1];
  int dat6 = (OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size);
  int off7_0 = offs[7][0];
  int off7_1 = offs[7][1];
  int dat7 = (OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size);

  // set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset +
              (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
                  start[0] * args[0].stencil->stride[0];
  base0 = base0 +
          (OPS_soa ? args[0].dat->type_size : args[0].dat->elem_size) *
              args[0].dat->size[0] * start[1] * args[0].stencil->stride[1];
  p_a[0] = (char *)args[0].data + base0;

  int base1 = args[1].dat->base_offset +
              (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
                  start[0] * args[1].stencil->stride[0];
  base1 = base1 +
          (OPS_soa ? args[1].dat->type_size : args[1].dat->elem_size) *
              args[1].dat->size[0] * start[1] * args[1].stencil->stride[1];
  p_a[1] = (char *)args[1].data + base1;

  int base2 = args[2].dat->base_offset +
              (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
                  start[0] * args[2].stencil->stride[0];
  base2 = base2 +
          (OPS_soa ? args[2].dat->type_size : args[2].dat->elem_size) *
              args[2].dat->size[0] * start[1] * args[2].stencil->stride[1];
  p_a[2] = (char *)args[2].data + base2;

  int base3 = args[3].dat->base_offset +
              (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
                  start[0] * args[3].stencil->stride[0];
  base3 = base3 +
          (OPS_soa ? args[3].dat->type_size : args[3].dat->elem_size) *
              args[3].dat->size[0] * start[1] * args[3].stencil->stride[1];
  p_a[3] = (char *)args[3].data + base3;

  int base4 = args[4].dat->base_offset +
              (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
                  start[0] * args[4].stencil->stride[0];
  base4 = base4 +
          (OPS_soa ? args[4].dat->type_size : args[4].dat->elem_size) *
              args[4].dat->size[0] * start[1] * args[4].stencil->stride[1];
  p_a[4] = (char *)args[4].data + base4;

  int base5 = args[5].dat->base_offset +
              (OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) *
                  start[0] * args[5].stencil->stride[0];
  base5 = base5 +
          (OPS_soa ? args[5].dat->type_size : args[5].dat->elem_size) *
              args[5].dat->size[0] * start[1] * args[5].stencil->stride[1];
  p_a[5] = (char *)args[5].data + base5;

  int base6 = args[6].dat->base_offset +
              (OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size) *
                  start[0] * args[6].stencil->stride[0];
  base6 = base6 +
          (OPS_soa ? args[6].dat->type_size : args[6].dat->elem_size) *
              args[6].dat->size[0] * start[1] * args[6].stencil->stride[1];
  p_a[6] = (char *)args[6].data + base6;

  int base7 = args[7].dat->base_offset +
              (OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size) *
                  start[0] * args[7].stencil->stride[0];
  base7 = base7 +
          (OPS_soa ? args[7].dat->type_size : args[7].dat->elem_size) *
              args[7].dat->size[0] * start[1] * args[7].stencil->stride[1];
  p_a[7] = (char *)args[7].data + base7;

  // initialize global variable with the dimension of dats
  xdim0 = args[0].dat->size[0];
  xdim1 = args[1].dat->size[0];
  xdim2 = args[2].dat->size[0];
  xdim3 = args[3].dat->size[0];
  xdim4 = args[4].dat->size[0];
  xdim5 = args[5].dat->size[0];
  xdim6 = args[6].dat->size[0];
  xdim7 = args[7].dat->size[0];

  // Halo Exchanges
  ops_H_D_exchanges_host(args, 8);
  ops_halo_exchanges(args, 8, range);
  ops_H_D_exchanges_host(args, 8);

  if (OPS_diags > 1) {
    ops_timers_core(&c1, &t1);
    OPS_kernels[7].mpi_time += t1 - t2;
  }

  int n_x;
  for (int n_y = start[1]; n_y < end[1]; n_y++) {
#pragma novector
    for (n_x = start[0];
         n_x < start[0] + ((end[0] - start[0]) / SIMD_VEC) * SIMD_VEC;
         n_x += SIMD_VEC) {
// call kernel function, passing in pointers to data -vectorised
#pragma simd
      for (int i = 0; i < SIMD_VEC; i++) {
        generate_chunk_kernel(
            (double *)p_a[0] + i * 1 * 1, (double *)p_a[1] + i * 0 * 1,
            (double *)p_a[2] + i * 1 * 1, (double *)p_a[3] + i * 1 * 1,
            (double *)p_a[4] + i * 1 * 1, (double *)p_a[5] + i * 1 * 1,
            (double *)p_a[6] + i * 1 * 1, (double *)p_a[7] + i * 0 * 1);
      }

      // shift pointers to data x direction
      p_a[0] = p_a[0] + (dat0 * off0_0) * SIMD_VEC;
      p_a[1] = p_a[1] + (dat1 * off1_0) * SIMD_VEC;
      p_a[2] = p_a[2] + (dat2 * off2_0) * SIMD_VEC;
      p_a[3] = p_a[3] + (dat3 * off3_0) * SIMD_VEC;
      p_a[4] = p_a[4] + (dat4 * off4_0) * SIMD_VEC;
      p_a[5] = p_a[5] + (dat5 * off5_0) * SIMD_VEC;
      p_a[6] = p_a[6] + (dat6 * off6_0) * SIMD_VEC;
      p_a[7] = p_a[7] + (dat7 * off7_0) * SIMD_VEC;
    }

    for (int n_x = start[0] + ((end[0] - start[0]) / SIMD_VEC) * SIMD_VEC;
         n_x < end[0]; n_x++) {
      // call kernel function, passing in pointers to data - remainder
      generate_chunk_kernel((double *)p_a[0], (double *)p_a[1],
                            (double *)p_a[2], (double *)p_a[3],
                            (double *)p_a[4], (double *)p_a[5],
                            (double *)p_a[6], (double *)p_a[7]);

      // shift pointers to data x direction
      p_a[0] = p_a[0] + (dat0 * off0_0);
      p_a[1] = p_a[1] + (dat1 * off1_0);
      p_a[2] = p_a[2] + (dat2 * off2_0);
      p_a[3] = p_a[3] + (dat3 * off3_0);
      p_a[4] = p_a[4] + (dat4 * off4_0);
      p_a[5] = p_a[5] + (dat5 * off5_0);
      p_a[6] = p_a[6] + (dat6 * off6_0);
      p_a[7] = p_a[7] + (dat7 * off7_0);
    }

    // shift pointers to data y direction
    p_a[0] = p_a[0] + (dat0 * off0_1);
    p_a[1] = p_a[1] + (dat1 * off1_1);
    p_a[2] = p_a[2] + (dat2 * off2_1);
    p_a[3] = p_a[3] + (dat3 * off3_1);
    p_a[4] = p_a[4] + (dat4 * off4_1);
    p_a[5] = p_a[5] + (dat5 * off5_1);
    p_a[6] = p_a[6] + (dat6 * off6_1);
    p_a[7] = p_a[7] + (dat7 * off7_1);
  }
  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[7].time += t2 - t1;
  }
  ops_set_dirtybit_host(args, 8);
  ops_set_halo_dirtybit3(&args[2], range);
  ops_set_halo_dirtybit3(&args[3], range);
  ops_set_halo_dirtybit3(&args[4], range);
  ops_set_halo_dirtybit3(&args[5], range);

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c1, &t1);
    OPS_kernels[7].mpi_time += t1 - t2;
    OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg6);
    OPS_kernels[7].transfer += ops_compute_transfer(dim, start, end, &arg7);
  }
}
