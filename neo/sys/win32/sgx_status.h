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

#ifndef _SGX_STATUS_H_
#define _SGX_STATUS_H_

#include "sgx_error.h"

#ifdef _MSC_VER
#include <windows.h>
#ifdef  __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER)
#ifdef UNICODE
#define sgx_register_wl_cert_chain  sgx_register_wl_cert_chainw
#else
#define sgx_register_wl_cert_chain  sgx_register_wl_cert_chaina
#endif /* !UNICODE */
#endif

/*
 * Function used to register white list cert chain
 *
 * @param CertChainPath[in] The full path of the cert chain.
 * @return If the function succeeds, return SGX_SUCCESS, any other value indicates an error.
 */
sgx_status_t sgx_register_wl_cert_chainw(const LPCWSTR CertChainPath);
sgx_status_t sgx_register_wl_cert_chaina(const LPCSTR CertChainPath);

#ifdef  __cplusplus
}
#endif

#endif

#endif
