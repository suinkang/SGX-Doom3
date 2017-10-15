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

#ifndef _SGX_TAE_SERVICE_H_
#define _SGX_TAE_SERVICE_H_

/**
* File:
*		sgx_tae_service.h
*Description:
*  header for trusted AE support library.
*  ADD from path/sgx_tae_service.edl import *; to your edl file
*  to use sgx_tae_service.lib
*/

#include "sgx.h"
#include "sgx_defs.h"


#ifdef  __cplusplus
extern "C" {
#endif

#pragma pack(push, 1)

typedef uint64_t sgx_time_t;

typedef uint8_t sgx_time_source_nonce_t[32];

#define SGX_MC_UUID_COUNTER_ID_SIZE 3
#define SGX_MC_UUID_NONCE_SIZE       13
typedef struct _mc_uuid {
    uint8_t counter_id[SGX_MC_UUID_COUNTER_ID_SIZE];
    uint8_t nonce[SGX_MC_UUID_NONCE_SIZE];
} sgx_mc_uuid_t;

/* fixed length to align with internal structure */
typedef struct _ps_sec_prop_desc
{
    uint8_t  sgx_ps_sec_prop_desc[256];
} sgx_ps_sec_prop_desc_t;

typedef struct _ps_sec_prop_desc_ex
{
    sgx_ps_sec_prop_desc_t  ps_sec_prop_desc;
    sgx_measurement_t pse_mrsigner;
    sgx_prod_id_t pse_prod_id;
    sgx_isv_svn_t pse_isv_svn;
} sgx_ps_sec_prop_desc_ex_t;

#pragma pack(pop)

/* create a session, call it before using Platform Service */
sgx_status_t SGXAPI sgx_create_pse_session(void);

/* close a created session, call it after finishing using Platform Service */
sgx_status_t SGXAPI sgx_close_pse_session(void);

/* get a data structure describing the Security Property of the Platform Service */
sgx_status_t SGXAPI sgx_get_ps_sec_prop(sgx_ps_sec_prop_desc_t* security_property);

/* get a data structure describing the Security Property of the Platform Service */
sgx_status_t SGXAPI sgx_get_ps_sec_prop_ex(sgx_ps_sec_prop_desc_ex_t* security_property);

/* provides the trusted platform current time */
sgx_status_t SGXAPI sgx_get_trusted_time(
    sgx_time_t* current_time,
    sgx_time_source_nonce_t* time_source_nonce
    );

/* monotonic counter policy */
#define SGX_MC_POLICY_SIGNER  0x1
#define SGX_MC_POLICY_ENCLAVE 0x2
/* create a monotonic counter using given policy(SIGNER 0x1 or ENCLAVE 0x2) and attribute_mask */
sgx_status_t SGXAPI sgx_create_monotonic_counter_ex(
    uint16_t  owner_policy,
    const sgx_attributes_t* owner_attribute_mask,
    sgx_mc_uuid_t* counter_uuid,
    uint32_t* counter_value
    );

/* create a monotonic counter using default policy SIGNER and default attribute_mask */
sgx_status_t SGXAPI sgx_create_monotonic_counter(
    sgx_mc_uuid_t* counter_uuid,
    uint32_t* counter_value
    );

/* destroy a specified monotonic counter */
sgx_status_t SGXAPI sgx_destroy_monotonic_counter(const sgx_mc_uuid_t* counter_uuid);

/* increment a specified monotonic counter by 1 */
sgx_status_t SGXAPI sgx_increment_monotonic_counter(
    const sgx_mc_uuid_t* counter_uuid,
    uint32_t* counter_value
    );

/* read a specified monotonic counter */
sgx_status_t SGXAPI sgx_read_monotonic_counter(
    const sgx_mc_uuid_t* counter_uuid,
    uint32_t* counter_value
    );

#ifdef  __cplusplus
}
#endif

#endif
