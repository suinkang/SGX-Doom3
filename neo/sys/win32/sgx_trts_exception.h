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

/**
 * File: sgx_trts_exception.h
 * Description:
 *     Header file for custom exception handling support.
 */
#pragma once

#ifndef _SGX_TRTS_EXCEPTION_H_
#define _SGX_TRTS_EXCEPTION_H_

#include <stdint.h>
#include <stddef.h>
#include "sgx_defs.h"

#define EXCEPTION_CONTINUE_SEARCH       0
#define EXCEPTION_CONTINUE_EXECUTION    -1

typedef enum _sgx_exception_vector_t
{
    SGX_EXCEPTION_VECTOR_DE = 0,  /* DIV and DIV instructions */
    SGX_EXCEPTION_VECTOR_DB = 1,  /* For Intel use only */
    SGX_EXCEPTION_VECTOR_BP = 3,  /* INT 3 instruction */
    SGX_EXCEPTION_VECTOR_BR = 5,  /* BOUND instruction */
    SGX_EXCEPTION_VECTOR_UD = 6,  /* UD2 instruction or reserved opcode */
    SGX_EXCEPTION_VECTOR_MF = 16, /* x87 FPU floating-point or WAIT/FWAIT instruction */
    SGX_EXCEPTION_VECTOR_AC = 17, /* Any data reference in memory */
    SGX_EXCEPTION_VECTOR_XM = 19, /* SSE/SSE2/SSE3 floating-point instruction */
} sgx_exception_vector_t;

typedef enum _sgx_exception_type_t
{
    SGX_EXCEPTION_HARDWARE = 3,
    SGX_EXCEPTION_SOFTWARE = 6,
} sgx_exception_type_t;

#if defined (_M_X64) || defined (__x86_64__)
typedef struct _cpu_context_t
{
    uint64_t rax;
    uint64_t rcx;
    uint64_t rdx;
    uint64_t rbx;
    uint64_t rsp;
    uint64_t rbp;
    uint64_t rsi;
    uint64_t rdi;
    uint64_t r8;
    uint64_t r9;
    uint64_t r10;
    uint64_t r11;
    uint64_t r12;
    uint64_t r13;
    uint64_t r14;
    uint64_t r15;
    uint64_t rflags;
    uint64_t rip;
} sgx_cpu_context_t;
#else
typedef struct _cpu_context_t
{
    uint32_t eax;
    uint32_t ecx;
    uint32_t edx;
    uint32_t ebx;
    uint32_t esp;
    uint32_t ebp;
    uint32_t esi;
    uint32_t edi;
    uint32_t eflags;
    uint32_t eip;
} sgx_cpu_context_t;
#endif

typedef struct _exception_info_t
{
    sgx_exception_vector_t exception_vector;
    sgx_exception_type_t   exception_type;
    sgx_cpu_context_t      cpu_context;
} sgx_exception_info_t;

typedef int (*sgx_exception_handler_t)(sgx_exception_info_t *info);

#ifdef __cplusplus
extern "C" {
#endif

/* sgx_register_exception_handler()
 *      register a custom exception handler
 * Parameter
 *      is_first_handler - the order in which the handler should be called.
 *          If the parameter is nonzero, the handler is the first handler to be called.
 *          If the parameter is zero, the handler is the last handler to be called.
 *      exception_handler - a pointer to the handler to be called.
 * Return Value
 *      handler - success
 *         NULL - fail
*/
void * SGXAPI sgx_register_exception_handler(int is_first_handler, sgx_exception_handler_t exception_handler);

/* sgx_unregister_exception_handler()
 *      unregister a custom exception handler.
 * Parameter
 *      handler - a handler to the custom excepetion handler previously
 *          registered using the sgx_register_exception_handler function.
 * Return Value
 *      none zero - success
 *              0 - fail
*/
int SGXAPI sgx_unregister_exception_handler(void *handler);


#ifdef __cplusplus
}
#endif

#endif
