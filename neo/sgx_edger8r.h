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

/*
 * Here contains functions intended to be used by `sgx_edger8r' only.
 *
 * -------------------------------------
 * Be warned: use them at your own risk.
 * -------------------------------------
 *
 */

#ifndef _SGX_EDGER8R_H_
#define _SGX_EDGER8R_H_

#include "sgx_defs.h"
#include "sgx_error.h"
#include "sgx_eid.h"
#include <stddef.h>         /* for size_t */

/* The `sgx_edger8r' tool will generate C interfaces. */
#ifdef __cplusplus
#    define SGX_EXTERNC extern "C"
#else
#    define SGX_EXTERNC
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* sgx_ocalloc()
 * Parameters:
 *     size - bytes to allocate on the outside stack
 * Return Value:
 *     the pointer to the allocated space on the outside stack
 *     NULL - fail to allocate
*/
void* SGXAPI sgx_ocalloc(size_t size);

/* sgx_ocfree()
 * Parameters:
 *      N/A
 * Return Value:
 *      N/A
*/
void SGXAPI sgx_ocfree(void);

/* sgx_ecall()
 * Parameters:
 *     eid         - the enclave id
 *     index       - the index of the trusted function
 *     ocall_table - the address of the OCALL table
 *     ms          - the pointer to the marshaling struct
 * Return Value:
 *     SGX_SUCCESS on success
*/
sgx_status_t SGXAPI sgx_ecall(const sgx_enclave_id_t eid,
                              const int index,
                              const void* ocall_table,
                              void* ms);

/* sgx_ocall()
 * Parameters:
 *     index       - the index of the untrusted function
 *     ms          - the pointer to the marshaling struct
 * Return Value:
 *     SGX_SUCCESS on success
*/
sgx_status_t SGXAPI sgx_ocall(const unsigned int index,
                              void* ms);

#ifdef __cplusplus
}
#endif

#endif /* !_SGX_EDGER8R_H_ */
