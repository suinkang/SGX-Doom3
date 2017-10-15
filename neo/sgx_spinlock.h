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


#ifndef _SGX_SPINLOCK_H_
#define _SGX_SPINLOCK_H_

#include "sgx_defs.h"
#include <stdint.h>

typedef volatile uint32_t sgx_spinlock_t;

#define SGX_SPINLOCK_INITIALIZER 0

#if defined(__cplusplus)
extern "C" {
#endif

uint32_t SGXAPI sgx_spin_lock(sgx_spinlock_t *lock);
uint32_t SGXAPI sgx_spin_unlock(sgx_spinlock_t *lock);

#if defined(__cplusplus)
}
#endif

#endif /* !_SGX_SPINLOCK_H_ */
