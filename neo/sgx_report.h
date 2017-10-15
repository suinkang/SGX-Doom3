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
 *  This file is to define Enclave's Report
*/

#ifndef _SGX_REPORT_H_
#define _SGX_REPORT_H_

#include "sgx_attributes.h"
#include "sgx_key.h"

#define SGX_HASH_SIZE        32              /* SHA256 */
#define SGX_MAC_SIZE         16              /* Message Authentication Code - 16 bytes */

#define SGX_REPORT_DATA_SIZE    64

typedef struct _sgx_measurement_t
{
    uint8_t                 m[SGX_HASH_SIZE];
} sgx_measurement_t;

typedef uint8_t             sgx_mac_t[SGX_MAC_SIZE];

typedef struct _sgx_report_data_t
{
    uint8_t                 d[SGX_REPORT_DATA_SIZE];
} sgx_report_data_t;

typedef uint16_t            sgx_prod_id_t;

#define SGX_TARGET_INFO_RESERVED1_BYTES 4
#define SGX_TARGET_INFO_RESERVED2_BYTES 456

typedef struct _target_info_t
{
    sgx_measurement_t       mr_enclave;     /* (  0) The MRENCLAVE of the target enclave */
    sgx_attributes_t        attributes;     /* ( 32) The ATTRIBUTES field of the target enclave */
    uint8_t                 reserved1[SGX_TARGET_INFO_RESERVED1_BYTES];   /* ( 48) Reserved */
    sgx_misc_select_t       misc_select;    /* ( 52) The MISCSELECT of the target enclave */
    uint8_t                 reserved2[SGX_TARGET_INFO_RESERVED2_BYTES]; /* ( 56) Struct size is 512 bytes */
} sgx_target_info_t;

typedef struct _report_body_t
{
    sgx_cpu_svn_t           cpu_svn;        /* (  0) Security Version of the CPU */
    sgx_misc_select_t       misc_select;    /* ( 16) Which fields defined in SSA.MISC */
    uint8_t                 reserved1[28];  /* ( 20) */
    sgx_attributes_t        attributes;     /* ( 48) Any special Capabilities the Enclave possess */
    sgx_measurement_t       mr_enclave;     /* ( 64) The value of the enclave's ENCLAVE measurement */
    uint8_t                 reserved2[32];  /* ( 96) */
    sgx_measurement_t       mr_signer;      /* (128) The value of the enclave's SIGNER measurement */
    uint8_t                 reserved3[96];  /* (160) */
    sgx_prod_id_t           isv_prod_id;    /* (256) Product ID of the Enclave */
    sgx_isv_svn_t           isv_svn;        /* (258) Security Version of the Enclave */
    uint8_t                 reserved4[60];  /* (260) */
    sgx_report_data_t       report_data;    /* (320) Data provided by the user */
} sgx_report_body_t;

typedef struct _report_t                    /* 432 bytes */
{
    sgx_report_body_t       body;
    sgx_key_id_t            key_id;         /* (384) KeyID used for diversifying the key tree */
    sgx_mac_t               mac;            /* (416) The Message Authentication Code over this structure. */
} sgx_report_t;

#endif
