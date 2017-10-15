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

#ifndef _SGX_THREAD_H_
#define _SGX_THREAD_H_

#include <stdint.h>
#include <stddef.h>
#include "sgx_defs.h"

typedef uintptr_t sgx_thread_t;

typedef struct _sgx_thread_queue_t
{
    sgx_thread_t        m_first;  /* first element */
    sgx_thread_t        m_last;   /* last element */
} sgx_thread_queue_t;

/* Mutex */
typedef struct _sgx_thread_mutex_t
{
    size_t              m_refcount;
    uint32_t            m_control;
    volatile uint32_t   m_lock;   /* use sgx_spinlock_t */
    sgx_thread_t        m_owner;
    sgx_thread_queue_t  m_queue;
} sgx_thread_mutex_t;

#define SGX_THREAD_T_NULL   ((sgx_thread_t)(NULL))

#define SGX_THREAD_MUTEX_NONRECURSIVE   0x01
#define SGX_THREAD_MUTEX_RECURSIVE      0x02
#define SGX_THREAD_NONRECURSIVE_MUTEX_INITIALIZER \
            {0, SGX_THREAD_MUTEX_NONRECURSIVE, 0, SGX_THREAD_T_NULL, {SGX_THREAD_T_NULL, SGX_THREAD_T_NULL}}
#define SGX_THREAD_RECURSIVE_MUTEX_INITIALIZER \
            {0, SGX_THREAD_MUTEX_RECURSIVE, 0, SGX_THREAD_T_NULL, {SGX_THREAD_T_NULL, SGX_THREAD_T_NULL}}
#define SGX_THREAD_MUTEX_INITIALIZER \
            SGX_THREAD_NONRECURSIVE_MUTEX_INITIALIZER

typedef struct _sgx_thread_mutex_attr_t
{
    unsigned char       m_dummy;  /* for C syntax check */
} sgx_thread_mutexattr_t;

/* Condition Variable */
typedef struct _sgx_thread_cond_t
{
    volatile uint32_t   m_lock;   /* use sgx_spinlock_t */
    sgx_thread_queue_t  m_queue;
} sgx_thread_cond_t;

#define SGX_THREAD_COND_INITIALIZER  {0, {SGX_THREAD_T_NULL, SGX_THREAD_T_NULL}}

typedef struct _sgx_thread_cond_attr_t
{
    unsigned char       m_dummy;  /* for C syntax check */
} sgx_thread_condattr_t;


/* event */

#define WAIT_FUNC_TIMEOUT_INFINITE UINT32_MAX

#ifdef __cplusplus
extern "C" {
#endif

/* Mutex */
int SGXAPI sgx_thread_mutex_init(sgx_thread_mutex_t *mutex, const sgx_thread_mutexattr_t *unused);
int SGXAPI sgx_thread_mutex_destroy(sgx_thread_mutex_t *mutex);

int SGXAPI sgx_thread_mutex_lock(sgx_thread_mutex_t *mutex);
int SGXAPI sgx_thread_mutex_trylock(sgx_thread_mutex_t *mutex);
int SGXAPI sgx_thread_mutex_unlock(sgx_thread_mutex_t *mutex);

/* Condition Variable */
int SGXAPI sgx_thread_cond_init(sgx_thread_cond_t *cond, const sgx_thread_condattr_t *unused);
int SGXAPI sgx_thread_cond_destroy(sgx_thread_cond_t *cond);

int SGXAPI sgx_thread_cond_wait(sgx_thread_cond_t *cond, sgx_thread_mutex_t *mutex);
int SGXAPI sgx_thread_cond_signal(sgx_thread_cond_t *cond);
int SGXAPI sgx_thread_cond_broadcast(sgx_thread_cond_t *cond);


/* Event */

#define SGX_MAX_WAIT_HANDLE_NUM 64

typedef struct _sgx_thread_sync_object_t *sgx_thread_sync_object_handle_t;

int SGXAPI sgx_create_event(sgx_thread_sync_object_handle_t* handle, int is_manual_reset, int is_signaled_init_state);
int SGXAPI sgx_destroy_event(sgx_thread_sync_object_handle_t handle);
int SGXAPI sgx_set_event(sgx_thread_sync_object_handle_t handle);
int SGXAPI sgx_reset_event(sgx_thread_sync_object_handle_t handle);

// The time-out interval elapsed, and the object's state is nonsignaled.
#define SGX_THREAD_ERROR_WAIT_TIMEOUT   -1
// The wait function has failed. 
#define SGX_THREAD_ERROR_WAIT_FAILED    -2

// Wait Functions
int SGXAPI sgx_wait_for_single_object(sgx_thread_sync_object_handle_t handle, uint32_t timeout);
// Function Name: sgx_wait_for_multiple_objects
// Parameter Description
// @handles : address of a sgx_thread_sync_object_handle_t array.
// @count : number of items of the handles array.
// @wait_all : flag to indicate return behavior
//                 0 - will return if any specified object is signaled;
//                 1 - will return if all specified objects are signaled;
// @timeout : flag to indicate blocking or non-blocking function calling. 
//                 0 - nonblocking calling
//                 WAIT_FUNC_TIMEOUT_INFINITE - blocking calling
int SGXAPI sgx_wait_for_multiple_objects(uint32_t count, sgx_thread_sync_object_handle_t* handles, int wait_all, uint32_t timeout);

sgx_thread_t SGXAPI sgx_thread_self(void);
int sgx_thread_equal(sgx_thread_t a, sgx_thread_t b);

#ifdef __cplusplus
}
#endif

#endif /* _SGX_THREAD_H_ */
