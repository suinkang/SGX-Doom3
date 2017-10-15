/**
*   Copyright(C) 2011-2015 Intel Corporation All Rights Reserved.
*
*   The source code, information  and  material ("Material") contained herein is
*   owned  by Intel Corporation or its suppliers or licensors, and title to such
*   Material remains  with Intel Corporation  or its suppliers or licensors. The
*   Material  contains proprietary information  of  Intel or  its  suppliers and
*   licensors. The  Material is protected by worldwide copyright laws and treaty
*   provisions. No  part  of  the  Material  may  be  used,  copied, reproduced,
*   modified, published, uploaded, posted, transmitted, distributed or disclosed
*   in any way  without Intel's  prior  express written  permission. No  license
*   under  any patent, copyright  or  other intellectual property rights  in the
*   Material  is  granted  to  or  conferred  upon  you,  either  expressly,  by
*   implication, inducement,  estoppel or  otherwise.  Any  license  under  such
*   intellectual  property  rights must  be express  and  approved  by  Intel in
*   writing.
*
*   *Third Party trademarks are the property of their respective owners.
*
*   Unless otherwise  agreed  by Intel  in writing, you may not remove  or alter
*   this  notice or  any other notice embedded  in Materials by Intel or Intel's
*   suppliers or licensors in any way.
*/

#pragma once

#ifndef _SGX_TRTS_H_
#define _SGX_TRTS_H_

#include "sgx_error.h"
#include "stddef.h"
#include "sgx_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/* sgx_is_within_enclave()
 * Parameters:
 *      addr - the start address of the buffer
 *      size - the size of the buffer
 * Return Value:
 *      1 - the buffer is strictly within the enclave
 *      0 - the whole buffer or part of the buffer is not within the enclave,
 *          or the buffer is wrap around
*/
int SGXAPI sgx_is_within_enclave(const void *addr, size_t size);

/* sgx_is_outside_enclave()
 * Parameters:
 *      addr - the start address of the buffer
 *      size - the size of the buffer
 * Return Value:
 *      1 - the buffer is strictly outside the enclave
 *      0 - the whole buffer or part of the buffer is not outside the enclave,
 *          or the buffer is wrap around
*/
int SGXAPI sgx_is_outside_enclave(const void *addr, size_t size);


/* sgx_read_rand()
 * Parameters:
 *      rand - the buffer to receive the random number
 *      length_in_bytes - the number of bytes to read the random number
 * Return Value:
 *      SGX_SUCCESS - success
 *      SGX_ERROR_INVALID_PARAMETER - the parameter is invalid
 *      SGX_ERROR_UNEXPECTED - HW failure of RDRAND instruction
*/
sgx_status_t SGXAPI sgx_read_rand(unsigned char *rand, size_t length_in_bytes);

#ifdef __cplusplus
}
#endif

#endif
