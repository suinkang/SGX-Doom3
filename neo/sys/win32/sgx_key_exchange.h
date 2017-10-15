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

#ifndef _SGX_KEY_EXCHANGE_H_
#define _SGX_KEY_EXCHANGE_H_

#include <stdint.h>
#include "sgx_quote.h"
#include "sgx_ecp_types.h"
#include "sgx_tae_service.h"

#ifdef  __cplusplus
extern "C" {
#endif

typedef uint32_t sgx_ra_context_t;

typedef sgx_key_128bit_t sgx_ra_key_128_t;

typedef enum _ra_key_type_t
{
    SGX_RA_KEY_SK = 1,
    SGX_RA_KEY_MK,
    SGX_RA_KEY_VK,
} sgx_ra_key_type_t;

typedef struct _ra_msg1_t
{
    sgx_ec256_public_t       g_a;         /* the Endian-ness of Ga is Little-Endian */
    sgx_epid_group_id_t      gid;         /* the Endian-ness of GID is Little-Endian */
} sgx_ra_msg1_t;


typedef struct _ra_msg2_t
{
    sgx_ec256_public_t       g_b;         /* the Endian-ness of Gb is Little-Endian */
    sgx_spid_t               spid;
    uint16_t                 quote_type;  /* unlinkable Quote(0) or linkable Quote(1) in little endian*/
    uint16_t                 kdf_id;      /* key derivation function id in little endian. */
    sgx_ec256_signature_t    sign_gb_ga;  /* In little endian */
    sgx_mac_t                mac;         /* mac_smk(g_b||spid||quote_type||kdf_id||sign_gb_ga) */
    uint32_t                 sig_rl_size;
#ifdef _MSC_VER
#pragma warning(push)
/* Disable warning that array payload has size 0 */
#ifdef __INTEL_COMPILER
#pragma warning ( disable:94 )
#else
#pragma warning ( disable: 4200 )
#endif
#endif
    uint8_t                  sig_rl[];
#ifdef _MSC_VER
#pragma warning(pop)
#endif
} sgx_ra_msg2_t;

typedef struct _ra_msg3_t
{
    sgx_mac_t                mac;         /* mac_smk(g_a||ps_sec_prop||quote) */
    sgx_ec256_public_t       g_a;         /* the Endian-ness of Ga is Little-Endian */
    sgx_ps_sec_prop_desc_t   ps_sec_prop;
#ifdef _MSC_VER
#pragma warning(push)
    /* Disable warning that array payload has size 0 */
#ifdef __INTEL_COMPILER
#pragma warning ( disable:94 )
#else
#pragma warning ( disable: 4200 )
#endif
#endif
    uint8_t                  quote[];
#ifdef _MSC_VER
#pragma warning(pop)
#endif
} sgx_ra_msg3_t;

#ifdef  __cplusplus
}
#endif

#endif
