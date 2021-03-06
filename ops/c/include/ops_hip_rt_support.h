#ifndef __OPS_HIP_RT_SUPPORT_H
#define __OPS_HIP_RT_SUPPORT_H
#ifndef DOXYGEN_SHOULD_SKIP_THIS
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
* Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
* The name of Mike Giles may not be used to endorse or promote products
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

/** @file
  * @brief OPS cuda specific runtime support functions
  * @author Gihan Mudalige, Istvan Reguly
  * @details Implements cuda backend runtime support functions
  */

/*
* This header file declares the CUDA back-end specific run-time functions
* to be used by the code generated by OPS compiler.
*/

#include <hip/hip_runtime.h>

#include <ops_lib_core.h>

/* define HIP warpsize for OPS */

#define OPS_WARPSIZE 32

/*
* personal stripped-down version of cutil_inline.h
*/

#define hipSafeCall(stream, err) __hipSafeCall(stream, err, __FILE__, __LINE__)
#define hipCheckMsg(stream, msg) __hipCheckMsg(stream, msg, __FILE__, __LINE__)

void hipDeviceInit(OPS_instance *instance, const int argc, const char *const argv[]);
void __hipSafeCall(std::ostream &stream, hipError_t err, const char *file, const int line);//?
void ops_hip_get_data(ops_dat dat);
void ops_hip_put_data(ops_dat dat);
void reallocConstArrays(OPS_instance *instance, int consts_bytes);
void reallocReductArrays(OPS_instance *instance, int reduct_bytes);
void mvConstArraysToDevice(OPS_instance *instance, int consts_bytes);
void mvReductArraysToDevice(OPS_instance *instance, int reduct_bytes);
void mvReductArraysToHost(OPS_instance *instance, int reduct_bytes);
void ops_hip_exit(OPS_instance *instance);
void ops_internal_copy_hip(ops_kernel_descriptor *desc);
void ops_upload_dat(ops_dat dat);
void ops_download_dat(ops_dat dat);

void ops_set_dirtybit_device_dat(ops_dat dat);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
#endif /* __OPS_HIP_RT_SUPPORT_H */
