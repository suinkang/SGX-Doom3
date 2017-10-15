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

#ifndef _SGX_ATTRIBUTES_H_
#define _SGX_ATTRIBUTES_H_

#include <stdint.h>

/* Enclave Flags Bit Masks */
#define SGX_FLAGS_INITTED        0x0000000000000001ULL     /* If set, then the enclave is initialized */
#define SGX_FLAGS_DEBUG          0x0000000000000002ULL     /* If set, then the enclave is debug */
#define SGX_FLAGS_MODE64BIT      0x0000000000000004ULL     /* If set, then the enclave is 64 bit */
#define SGX_FLAGS_PROVISION_KEY  0x0000000000000010ULL     /* If set, then the enclave has access to provision key */
#define SGX_FLAGS_EINITTOKEN_KEY 0x0000000000000020ULL     /* If set, then the enclave has access to EINITTOKEN key */
#define SGX_FLAGS_RESERVED       (~(SGX_FLAGS_INITTED | SGX_FLAGS_DEBUG | SGX_FLAGS_MODE64BIT | SGX_FLAGS_PROVISION_KEY | SGX_FLAGS_EINITTOKEN_KEY))

/* XSAVE Feature Request Mask */
#define SGX_XFRM_LEGACY          0x0000000000000003ULL     /* Legacy XFRM which includes the basic feature bits required by SGX, x87 state(0x01) and SSE state(0x02) */
#define SGX_XFRM_AVX             0x0000000000000006ULL     /* AVX XFRM which includes AVX state(0x04) and SSE state(0x02) required by AVX */
#define SGX_XFRM_RESERVED        (~(SGX_XFRM_LEGACY | SGX_XFRM_AVX))

typedef struct _attributes_t
{
    uint64_t      flags;
    uint64_t      xfrm;
} sgx_attributes_t;

/* define MISCSELECT - all bits are currently reserved */
typedef uint32_t    sgx_misc_select_t;

typedef struct _sgx_misc_attribute_t {
    sgx_attributes_t    secs_attr;
    sgx_misc_select_t   misc_select;
} sgx_misc_attribute_t;

#endif/* _SGX_ATTRIBUTES_H_ */
