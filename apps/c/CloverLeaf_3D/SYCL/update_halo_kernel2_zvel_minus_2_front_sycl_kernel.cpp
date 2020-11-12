//
// auto-generated by ops.py
//

//user function

// host stub function
#ifndef OPS_LAZY
void ops_par_loop_update_halo_kernel2_zvel_minus_2_front(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {
#else
void ops_par_loop_update_halo_kernel2_zvel_minus_2_front_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  #endif

  //Timing
  double __t1,__t2,__c1,__c2;

  ops_arg args[3] = { arg0, arg1, arg2};



  #if defined(CHECKPOINTING) && !defined(OPS_LAZY)
  if (!ops_checkpointing_before(args,3,range,59)) return;
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,59,"update_halo_kernel2_zvel_minus_2_front");
    block->instance->OPS_kernels[59].count++;
    ops_timers_core(&__c2,&__t2);
  }

  #ifdef OPS_DEBUG
  ops_register_args(block->instance, args, "update_halo_kernel2_zvel_minus_2_front");
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
  if (compute_ranges(args, 3,block, range, start, end, arg_idx) < 0) return;
  #endif


  //initialize global variable with the dimension of dats
  int xdim0_update_halo_kernel2_zvel_minus_2_front = args[0].dat->size[0];
  int ydim0_update_halo_kernel2_zvel_minus_2_front = args[0].dat->size[1];
  int xdim1_update_halo_kernel2_zvel_minus_2_front = args[1].dat->size[0];
  int ydim1_update_halo_kernel2_zvel_minus_2_front = args[1].dat->size[1];

  //set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset/sizeof(double);
  cl::sycl::buffer<double,1> zvel0_p = static_cast<cl::sycl::buffer<char,1> *>((void*)args[0].data_d)->reinterpret<double,1>(cl::sycl::range<1>(args[0].dat->mem/sizeof(double)));

  int base1 = args[1].dat->base_offset/sizeof(double);
  cl::sycl::buffer<double,1> zvel1_p = static_cast<cl::sycl::buffer<char,1> *>((void*)args[1].data_d)->reinterpret<double,1>(cl::sycl::range<1>(args[1].dat->mem/sizeof(double)));

  int *arg2h = (int *)args[2].data;


  int consts_bytes = 0;

  consts_bytes += ROUND_UP(NUM_FIELDS*sizeof(int));

  reallocConstArrays(block->instance,consts_bytes);
  consts_bytes = 0;
  arg2.data = block->instance->OPS_consts_h + consts_bytes;
  int arg2_offset = consts_bytes;
  for (int d=0; d<NUM_FIELDS; d++) ((int *)arg2.data)[d] = arg2h[d];
  consts_bytes += ROUND_UP(NUM_FIELDS*sizeof(int));
  mvConstArraysToDevice(block->instance,consts_bytes);
  cl::sycl::buffer<char,1> *consts = static_cast<cl::sycl::buffer<char,1> *>((void*)block->instance->OPS_consts_d);

  #ifndef OPS_LAZY
  //Halo Exchanges
  ops_H_D_exchanges_device(args, 3);
  ops_halo_exchanges(args,3,range);
  #endif

  if (block->instance->OPS_diags > 1) {
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[59].mpi_time += __t1-__t2;
  }

  int start_0 = start[0];
  int end_0 = end[0];
  int start_1 = start[1];
  int end_1 = end[1];
  int start_2 = start[2];
  int end_2 = end[2];
  block->instance->sycl_instance->queue->submit([&](cl::sycl::handler &cgh) {
    //accessors
    auto Accessor_zvel0 = zvel0_p.get_access<cl::sycl::access::mode::read_write>(cgh);
    auto Accessor_zvel1 = zvel1_p.get_access<cl::sycl::access::mode::read_write>(cgh);
    auto Accessor_consts_char = consts->get_access<cl::sycl::access::mode::read_write>(cgh);


    cgh.parallel_for<class update_halo_kernel2_zvel_minus_2_front_kernel>(cl::sycl::nd_range<3>(cl::sycl::range<3>(
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
      ACC<double> zvel0(xdim0_update_halo_kernel2_zvel_minus_2_front, ydim0_update_halo_kernel2_zvel_minus_2_front, &Accessor_zvel0[0] + base0 + n_x*1 + n_y * xdim0_update_halo_kernel2_zvel_minus_2_front*1 + n_z * xdim0_update_halo_kernel2_zvel_minus_2_front * ydim0_update_halo_kernel2_zvel_minus_2_front*1);
      ACC<double> zvel1(xdim1_update_halo_kernel2_zvel_minus_2_front, ydim1_update_halo_kernel2_zvel_minus_2_front, &Accessor_zvel1[0] + base1 + n_x*1 + n_y * xdim1_update_halo_kernel2_zvel_minus_2_front*1 + n_z * xdim1_update_halo_kernel2_zvel_minus_2_front * ydim1_update_halo_kernel2_zvel_minus_2_front*1);
      const int *fields = (int*)&Accessor_consts_char[arg2_offset];
      //USER CODE
      if (n_x < end_0 && n_y < end_1 && n_z < end_2) {
        
  if(fields[FIELD_ZVEL0] == 1) zvel0(0,0,0) = -zvel0(0,0,-2);
  if(fields[FIELD_ZVEL1] == 1) zvel1(0,0,0) = -zvel1(0,0,-2);

      }
    });
  });
  if (block->instance->OPS_diags > 1) {
    block->instance->sycl_instance->queue->wait();
    ops_timers_core(&__c2,&__t2);
    block->instance->OPS_kernels[59].time += __t2-__t1;
  }
  #ifndef OPS_LAZY
  ops_set_dirtybit_device(args, 3);
  ops_set_halo_dirtybit3(&args[0],range);
  ops_set_halo_dirtybit3(&args[1],range);
  #endif

  if (block->instance->OPS_diags > 1) {
    //Update kernel record
    ops_timers_core(&__c1,&__t1);
    block->instance->OPS_kernels[59].mpi_time += __t1-__t2;
    block->instance->OPS_kernels[59].transfer += ops_compute_transfer(dim, start, end, &arg0);
    block->instance->OPS_kernels[59].transfer += ops_compute_transfer(dim, start, end, &arg1);
  }
}


#ifdef OPS_LAZY
void ops_par_loop_update_halo_kernel2_zvel_minus_2_front(char const *name, ops_block block, int dim, int* range,
 ops_arg arg0, ops_arg arg1, ops_arg arg2) {
  ops_kernel_descriptor *desc = (ops_kernel_descriptor *)calloc(1,sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 59;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 59;
  for ( int i=0; i<6; i++ ){
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 3;
  desc->args = (ops_arg*)ops_malloc(3*sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  char *tmp = (char*)ops_malloc(NUM_FIELDS*sizeof(int));
  memcpy(tmp, arg2.data,NUM_FIELDS*sizeof(int));
  desc->args[2].data = tmp;
  desc->function = ops_par_loop_update_halo_kernel2_zvel_minus_2_front_execute;
  if (block->instance->OPS_diags > 1) {
    ops_timing_realloc(block->instance,59,"update_halo_kernel2_zvel_minus_2_front");
  }
  ops_enqueue_kernel(desc);
}
#endif
