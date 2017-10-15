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

#ifndef _SGX_ECP_TYPES_H_
#define _SGX_ECP_TYPES_H_

#include <stdint.h>

#pragma pack(push, 1)

#include "sgx_tcrypto.h"

#ifndef SGX_FEBITSIZE
#define SGX_FEBITSIZE                   256
#endif

typedef struct _ecc_param_t
{
    uint32_t eccP[SGX_NISTP_ECP256_KEY_SIZE];     /* EC prime field */
    uint32_t eccA[SGX_NISTP_ECP256_KEY_SIZE];     /* EC curve coefficient A */
    uint32_t eccB[SGX_NISTP_ECP256_KEY_SIZE];     /* EC curve coefficient B */
    uint32_t eccG[2][SGX_NISTP_ECP256_KEY_SIZE];  /* ECC base point */
    uint32_t eccR[SGX_NISTP_ECP256_KEY_SIZE];     /* ECC base point order */
} sgx_ecc_param_t;

typedef uint8_t sgx_ec_key_128bit_t[SGX_CMAC_KEY_SIZE];

#pragma pack(pop)

#endif
