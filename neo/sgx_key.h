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
 *	This file is to define Enclave's keys
*/
#pragma once

#ifndef _SGX_KEY_H_
#define _SGX_KEY_H_

#include <stdint.h>
#include "sgx_attributes.h"

/* Key Name */
#define SGX_KEYSELECT_EINITTOKEN       0x0000
#define SGX_KEYSELECT_PROVISION        0x0001
#define SGX_KEYSELECT_PROVISION_SEAL   0x0002
#define SGX_KEYSELECT_REPORT           0x0003
#define SGX_KEYSELECT_SEAL             0x0004

/* Key Policy */
#define SGX_KEYPOLICY_MRENCLAVE        0x0001      /* Derive key using the enclave's ENCLAVE measurement register */
#define SGX_KEYPOLICY_MRSIGNER         0x0002      /* Derive key using the enclave's SINGER measurement register */

#define SGX_KEYID_SIZE    32
#define SGX_CPUSVN_SIZE   16

typedef uint8_t                    sgx_key_128bit_t[16];
typedef uint16_t                   sgx_isv_svn_t;

typedef struct _sgx_cpu_svn_t
{
    uint8_t                        svn[SGX_CPUSVN_SIZE];
} sgx_cpu_svn_t;

typedef struct _sgx_key_id_t
{
    uint8_t                        id[SGX_KEYID_SIZE];
} sgx_key_id_t;

#define SGX_KEY_REQUEST_RESERVED2_BYTES 436

typedef struct _key_request_t
{
   uint16_t                        key_name;        /* Identifies the key required */
   uint16_t                        key_policy;      /* Identifies which inputs should be used in the key derivation */
   sgx_isv_svn_t                   isv_svn;         /* Security Version of the Enclave */
   uint16_t                        reserved1;       /* Must be 0 */
   sgx_cpu_svn_t                   cpu_svn;         /* Security Version of the CPU */
   sgx_attributes_t                attribute_mask;  /* Mask which ATTRIBUTES Seal keys should be bound to */
   sgx_key_id_t                    key_id;          /* Value for key wear-out protection */
   sgx_misc_select_t               misc_mask;       /* Mask what MISCSELECT Seal keys bound to */
   uint8_t                         reserved2[SGX_KEY_REQUEST_RESERVED2_BYTES];  /* Struct size is 512 bytes */
} sgx_key_request_t;


#endif
