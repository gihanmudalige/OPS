//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_advec_mom_kernel2_z(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {
#else
void ops_par_loop_advec_mom_kernel2_z_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[4] = { arg0, arg1, arg2, arg3};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,4,range,138)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,138,"advec_mom_kernel2_z");
    block->instance->OPS_kernels[138].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "advec_mom_kernel2_z");
  #endif


  //compute locally allocated range for the sub-block
  int start[3];
  int end[3];
  #if defined(OPS_MPI) && !defined(OPS_LAZY)
  int arg_idx[3];
  #endif
  #if defined(OPS_LAZY) || !defined(OPS_MPI)
  for ( int n=0; n<3; n++ ){
    start[n] = range[2*n];end[n] = range[2*n+1];
  }
  #else
  if (compute_ranges(args, 4,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_advec_mom_kernel2_z = args[0].dat->size[0];
  int ydim0_advec_mom_kernel2_z = args[0].dat->size[1];
  int xdim1_advec_mom_kernel2_z = args[1].dat->size[0];
  int ydim1_advec_mom_kernel2_z = args[1].dat->size[1];
  int xdim2_advec_mom_kernel2_z = args[2].dat->size[0];
  int ydim2_advec_mom_kernel2_z = args[2].dat->size[1];
  int xdim3_advec_mom_kernel2_z = args[3].dat->size[0];
  int ydim3_advec_mom_kernel2_z = args[3].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset/sizeof(double);
  cl::sycl::buffer<double,1> vel1_p = static_cast<cl::sycl::buffer<char,1> *>((void*)args[0].data_d)->reinterpret<double,1>(cl::sycl::range<1>(args[0].dat->mem/sizeof(double)));

  int base1 = args[1].dat->base_offset/sizeof(double);
  cl::sycl::buffer<double,1> node_mass_post_p = static_cast<cl::sycl::buffer<char,1> *>((void*)args[1].data_d)->reinterpret<double,1>(cl::sycl::range<1>(args[1].dat->mem/sizeof(double)));

  int base2 = args[2].dat->base_offset/sizeof(double);
  cl::sycl::buffer<double,1> node_mass_pre_p = static_cast<cl::sycl::buffer<char,1> *>((void*)args[2].data_d)->reinterpret<double,1>(cl::sycl::range<1>(args[2].dat->mem/sizeof(double)));

  int base3 = args[3].dat->base_offset/sizeof(double);
  cl::sycl::buffer<double,1> mom_flux_p = static_cast<cl::sycl::buffer<char,1> *>((void*)args[3].data_d)->reinterpret<double,1>(cl::sycl::range<1>(args[3].dat->mem/sizeof(double)));



  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_device(args, 4);
  ops_halo_exchanges(args,4,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[138].mpi_time += __t1-__t2;
  }

  int start_0 = start[0];
  int end_0 = end[0];
  int start_1 = start[1];
  int end_1 = end[1];
  int start_2 = start[2];
  int end_2 = end[2];
  block->instance->sycl_instance->queue->submit([&](cl::sycl::handler &cgh) {
    //accessors
    auto Accessor_vel1 = vel1_p.get_access<cl::sycl::access::mode::read_write>(cgh);
    auto Accessor_node_mass_post = node_mass_post_p.get_access<cl::sycl::access::mode::read_write>(cgh);
    auto Accessor_node_mass_pre = node_mass_pre_p.get_access<cl::sycl::access::mode::read_write>(cgh);
    auto Accessor_mom_flux = mom_flux_p.get_access<cl::sycl::access::mode::read_write>(cgh);


    cgh.parallel_for<class advec_mom_kernel2_z_kernel>(cl::sycl::nd_range<3>(cl::sycl::range<3>(
          ((end[0]-start[0]-1)/block->instance->OPS_block_size_x+1)*block->instance->OPS_block_size_x
         ,((end[1]-start[1]-1)/block->instance->OPS_block_size_y+1)*block->instance->OPS_block_size_y
         ,((end[2]-start[2]-1)/block->instance->OPS_block_size_z+1)*block->instance->OPS_block_size_z
           ),cl::sycl::range<3>(block->instance->OPS_block_size_x
           , block->instance->OPS_block_size_y
           , block->instance->OPS_block_size_z
           )), [=](cl::sycl::nd_item<3> item) {
      cl::sycl::cl_int n_z = item.get_global_id()[2]+start_2;
      cl::sycl::cl_int n_y = item.get_global_id()[1]+start_1;
      cl::sycl::cl_int n_x = item.get_global_id()[0]+start_0;
      ACC<double> vel1(xdim0_advec_mom_kernel2_z, ydim0_advec_mom_kernel2_z, &Accessor_vel1[0] + base0 + n_x*1 + n_y * xdim0_advec_mom_kernel2_z*1 + n_z * xdim0_advec_mom_kernel2_z * ydim0_advec_mom_kernel2_z*1);
      const ACC<double> node_mass_post(xdim1_advec_mom_kernel2_z, ydim1_advec_mom_kernel2_z, &Accessor_node_mass_post[0] + base1 + n_x*1 + n_y * xdim1_advec_mom_kernel2_z*1 + n_z * xdim1_advec_mom_kernel2_z * ydim1_advec_mom_kernel2_z*1);
      const ACC<double> node_mass_pre(xdim2_advec_mom_kernel2_z, ydim2_advec_mom_kernel2_z, &Accessor_node_mass_pre[0] + base2 + n_x*1 + n_y * xdim2_advec_mom_kernel2_z*1 + n_z * xdim2_advec_mom_kernel2_z * ydim2_advec_mom_kernel2_z*1);
      const ACC<double> mom_flux(xdim3_advec_mom_kernel2_z, ydim3_advec_mom_kernel2_z, &Accessor_mom_flux[0] + base3 + n_x*1 + n_y * xdim3_advec_mom_kernel2_z*1 + n_z * xdim3_advec_mom_kernel2_z * ydim3_advec_mom_kernel2_z*1);
      //USER CODE
      if (n_x < end_0 && n_y < end_1 && n_z < end_2) {
        

  vel1(0,0,0) = ( vel1(0,0,0) * node_mass_pre(0,0,0)  +
    mom_flux(0,0,-1) - mom_flux(0,0,0) ) / node_mass_post(0,0,0);

      }
    });
  });
  if (block->instance->OPS_diags > 1) {
    block->instance->sycl_instance->queue->wait();
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[138].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 4);
  ops_set_halo_dirtybit3(&args[0],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[138].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[138].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[138].transfer += ops_compute_transfer(dim, start, end, &arg1);
    block->instance->OPS_kernels[138].transfer += ops_compute_transfer(dim, start, end, &arg2);
    block->instance->OPS_kernels[138].transfer += ops_compute_transfer(dim, start, end, &arg3);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_advec_mom_kernel2_z(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2, ops_arg arg3) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 138;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 138;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 4;
  desc->args = (ops_arg*)ops_malloc(4*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->function = ops_par_loop_advec_mom_kernel2_z_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,138,"advec_mom_kernel2_z");
  }
  ops_enqueue_kernel(desc);
}
#endif