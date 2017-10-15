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

#ifndef _SGX_UAE_SERVICE_H_
#define _SGX_UAE_SERVICE_H_

#include <stdint.h>
#if defined(_MSC_VER)
#include <windows.h>
#endif

#include "sgx_quote.h"
#include "sgx_error.h"
#include "sgx_urts.h"
#include "sgx_status.h"
#include "sgx_capable.h"


#define PS_CAP_TRUSTED_TIME         0x1
#define PS_CAP_MONOTONIC_COUNTER    0x2
#define PS_CAP_MESSAGE_EXCHANGE     0x8

/**
 * Platform service capabilities
 *      ps_cap0
 *       Bit 0 : Trusted Time
 *       Bit 1 : Monotonic Counter
 *       Bit 2 : Reserved
 *       Bit 3 : Message Exchange
 *       Bit 4-31 : Reserved
 *      ps_cap1
 *       Bit 0-31 : Reserved
 */
typedef struct _sgx_ps_cap_t
{
    uint32_t ps_cap0;
    uint32_t ps_cap1;
} sgx_ps_cap_t;

#ifdef  __cplusplus
extern "C" {
#endif

/*
 * Function used to initialize the process of quoting.
 *
 * @param p_target_info[out] Target info of quoting enclave.
 * @param p_gid[out] ID of platform's current EPID group.
 * @return If outputs are generated, return SGX_SUCCESS, otherwise return general error code
 *             or SGX_ERROR_AE_INVALID_EPIDBLOB to indicate special error condition.
 */
sgx_status_t SGXAPI sgx_init_quote(
    sgx_target_info_t *p_target_info,
    sgx_epid_group_id_t *p_gid);


/*
 * Function used to calculate quote size.
 *
 * @param p_sig_rl[in] OPTIONAL Signature Revocation List.
 * @param sig_rl_size[in] Signature Revocation List size, in bytes.
 * @param p_quote_size[out] Quote size, in bytes.
 * @return If quote size is calculated,return SGX_SUCCESS, otherwise return
 *            SGX_ERROR_INVALID_PARAMETER to indicate special error condition.
 */
sgx_status_t SGXAPI sgx_calc_quote_size(
    const uint8_t *p_sig_rl,
    uint32_t sig_rl_size,
    uint32_t* p_quote_size);

/*
 * [DEPRECATED] Use sgx_calc_quote_size function instead of this one
 * Function used to get quote size.
 *
 * @param p_sig_rl[in] OPTIONAL Signature Revocation List.
 * @param p_quote_size[out] Quote size, in bytes.
 * @return If quote size is calculated,return SGX_SUCCESS, otherwise return
*            SGX_ERROR_INVALID_PARAMETER to indicate special error condition.
 */
SGX_DEPRECATED
sgx_status_t SGXAPI sgx_get_quote_size(
    const uint8_t *p_sig_rl,
    uint32_t* p_quote_size);

/*
 * Function used to get quote.
 *
 * @param p_report[in] Report of enclave for which quote is being calculated.
 * @param quote_type[in] Linkable or unlinkable quote.
 * @param p_spid[in] Pointer of SPID.
 * @param p_nonce[in] OPTIONAL nonce.
 * @param p_sig_rl[in] OPTIONAL list of signature made fore EPID.
 * @param sig_rl_size[in] The size of p_sig_rl, in bytes.
 * @param p_qe_report[out] OPTIONAL The QE report.
 * @param p_quote[out] The quote buffer, can not be NULL.
 * @param quote_size[in] Quote buffer size, in bytes.
 * @return If quote is generated,return SGX_SUCCESS,
 *         error code or SGX_ERROR_AE_INVALID_EPIDBLOB,
 *         SGX_ERROR_INVALID_PARAMETER to indicate special error condition.
 *         SGX_ERROR_EPID_MEMBER_REVOKED to indicate the EPID group membership has been revoked.
 */
sgx_status_t SGXAPI sgx_get_quote(
    const sgx_report_t *p_report,
    sgx_quote_sign_type_t quote_type,
    const sgx_spid_t *p_spid,
    const sgx_quote_nonce_t *p_nonce,
    const uint8_t *p_sig_rl,
    uint32_t sig_rl_size,
    sgx_report_t *p_qe_report,
    sgx_quote_t *p_quote,
    uint32_t quote_size);

/**
 * Get the platform service capabilities
 *
 * @param sgx_ps_cap Platform capabilities reported by AESM.
 * @return if OK, return SGX_SUCCESS
 */
sgx_status_t SGXAPI sgx_get_ps_cap(sgx_ps_cap_t* p_sgx_ps_cap);

#define SGX_IS_TRUSTED_TIME_AVAILABLE(cap)           ((((uint32_t)PS_CAP_TRUSTED_TIME)&((cap).ps_cap0))!=0)
#define SGX_IS_MONOTONIC_COUNTER_AVAILABLE(cap)      ((((uint32_t)PS_CAP_MONOTONIC_COUNTER)&((cap).ps_cap0))!=0)
#define SGX_IS_MESSAGE_EXCHANGE_AVAILABLE(cap)      ((((uint32_t)PS_CAP_MESSAGE_EXCHANGE)&((cap).ps_cap0))!=0)

/*
 * Function used to report the status of the attestation.
 *
 * @param p_platform_info[in] platform information received from Intel Attestation Server.
 * @param attestation_status[in] Value representing status during attestation. 0 if attestation succeeds.
 * @param p_update_info[out] update information of the SGX platform.
 * @return If OK, return SGX_SUCCESS. If update is needed, return SGX_ERROR_UPDATE_NEEDED and update_info contains update information.
 */

sgx_status_t SGXAPI sgx_report_attestation_status(
    const sgx_platform_info_t* p_platform_info,
    int attestation_status,
    sgx_update_info_bit_t* p_update_info);

#ifdef _MSC_VER
typedef struct _ie_proxy_info_t
{
    DWORD auto_flag;/* Flag to indicate whether to use autoproxy */
    DWORD url_len;  /* Autoproxy script len if it is not zero and data[0]~data[url_len-1] for the autoproxy script url */
    DWORD proxy_len;/* Manual proxy len if it is not zero and data[url_len]~data[url_len+proxy_len-1] for the manual proxy */
    DWORD bypass_len;/* Bypass len if it is not zero and data[url_len+proxy_len]~data[url_len+proxy_len+bypass_len-1] for url to bypass the proxy */
    DWORD username_len;
    DWORD password_len;
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning ( disable:4200 )
#endif
    wchar_t data[];
#ifdef _MSC_VER
#pragma warning(pop)
#endif
}ie_proxy_info_t;

#endif

/*
 * Function used to query and enable SGX device.
 *
 * @param sgx_device_status[out] The status of SGX device.
 * @return If the function succeeds, return SGX_SUCCESS, any other value indicates an error.
 */
sgx_status_t sgx_enable_device(sgx_device_status_t* sgx_device_status);


/*
 * Function used to get whitelist size.
 *
 * @param p_whitelist_size[out] whitelist size, in bytes.
 * @return If whitelist size is returned,return SGX_SUCCESS, otherwise SGX_ERROR_UNEXPECTED
*             indicates current whitelist is invalid.
 */
sgx_status_t SGXAPI sgx_get_whitelist_size(
    uint32_t* p_whitelist_size);


/*
 * Function used to get whitelist.
 *
 * @param p_whitelist[out] The whitelist buffer.
 * @param whitelist_size[in] whitelist buffer size, in bytes.
 * @return If whitelist is retrieved, return SGX_SUCCESS, any other value indicates an error.
 */
sgx_status_t SGXAPI sgx_get_whitelist(
    uint8_t* p_whitelist,
    uint32_t whitelist_size);


/*
* Function used to get active extended epid group id.
*
* @param p_extended_epid_group_id[out] active extended epid group id to return.
* @return If extended epid group id is returned,return SGX_SUCCESS.
*/
sgx_status_t SGXAPI sgx_get_extended_epid_group_id(
    uint32_t* p_extended_epid_group_id);

#ifdef  __cplusplus
}
#endif

#endif
