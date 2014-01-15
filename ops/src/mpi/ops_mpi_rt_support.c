/*
* Open source copyright declaration based on BSD open source template:
* http://www.opensource.org/licenses/bsd-license.php
*
* This file is part of the OPS distribution.
*
* Copyright (c) 2013, Mike Giles and others. Please see the AUTHORS file in
* the main source directory for a full list of copyright holders.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* * Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* * Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
* * The name of Mike Giles may not be used to endorse or promote products
* derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY Mike Giles ''AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL Mike Giles BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/** @brief ops mpi run-time support routines
  * @author Gihan Mudalige
  * @details Implements the runtime support routines for the OPS mpi backend
  */

#include <ops_lib_core.h>

#include <mpi.h>
#include <ops_mpi_core.h>

int ops_is_root()
{
  int my_rank;
  MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
  return (my_rank==MPI_ROOT);
}

void pack(ops_dat dat, char* buff, int depth, int dim, sub_block_list sb)
{
  //remember that the packing for some dimensions is done in strides

}



/* halo exchange for an arg->dat
  for each dimension of the block on which this dat is declared on {

    for both directions in dimension {
      pack send_buffer
    }
    send and receive messages in both directions

    MPI_wait_all() //barrier in dimenssion

    for both directions in dimension {
      unpack recieve_buffer
    }
  }
*/
void ops_exchange_halo(ops_arg* arg, int depth)
{
  ops_dat dat = arg->dat;
  sub_block_list sb = OPS_sub_block_list[dat->block->index];

  for(int n=0;n<sb->ndim;n++){
    //pack possitive send buffer
    if(sb->id_p[n] != MPI_PROC_NULL)
      pack(dat, dat->send_buff_p[n], depth, n, sb);
    //pack negative send buffer
    if(sb->id_m[n] != MPI_PROC_NULL)
      pack(dat, dat->send_buff_n[n], depth, n, sb);

    //Isend possitive buffer
    //Isend negative buffer

    //Ireceive possitive buffer
    //Ireceive negative buffer

    //MPI_Wait_all()

    //ukpack possitive send buffer
    //ukpack negative send buffer
  }
}
