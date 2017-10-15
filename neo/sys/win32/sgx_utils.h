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

/**
 * File: sgx_utils.h
 * Description:
 *     Trusted library for SGX instructions
 */
#pragma once

#ifndef _SGX_UTILS_H_
#define _SGX_UTILS_H_

#include "sgx.h"
#include "sgx_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/*sgx_create_report
 *  Purpose: Create a cryptographic report of the enclave using the input information if any.
 *
 *  Parameters:
 *      target_info - [IN] pointer to the information of the target enclave.
 *      report_data - [IN] pointer to a set of data used for communication between the enclaves.
 *      report - [OUT] pointer to the cryptographic report of the enclave
 *
 *  Return value:
 *     sgx_status_t  - SGX_SUCCESS or failure as defined in sgx_error.h.
*/
sgx_status_t SGXAPI sgx_create_report(const sgx_target_info_t *target_info, const sgx_report_data_t *report_data, sgx_report_t *report);

/* sgx_verify_report
 * Purpose: Software verification for  the input report
 *
 *  Paramters:
 *      report - [IN] ponter to the cryptographic report to be verified.
 *
 *  Return value:
 *      sgx_status_t  - SGX_SUCCESS or failure as defined in sgx_error.h.
*/
sgx_status_t SGXAPI sgx_verify_report(const sgx_report_t *report);

/*sgx_get_key
 *  Purpose: Generates a 128-bit secret key with the input information.
 *
 *  Parameters:
 *      key_request - [IN] pointer to the sgx_key_request_t object used for selecting the appropriate key.
 *      key  - [OUT] Pointer to the buffer that receives the cryptographic key output.
 *
 *  Return value:
 *       sgx_status_t  - SGX_SUCCESS or failure as defined in sgx_error.h.
*/
sgx_status_t SGXAPI sgx_get_key(const sgx_key_request_t *key_request, sgx_key_128bit_t *key);

#ifdef __cplusplus
}
#endif

#endif
