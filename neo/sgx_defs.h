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

#ifndef _SGX_DEFS_H_
#define _SGX_DEFS_H_

#if defined(_MSC_VER)
/* The following macros are MSVC only */
# define SGXAPI __cdecl
# define SGX_CXX_NATIVE_HEADER(header)   <stdc++/win/header>

# define SGX_CDECL      __cdecl
# define SGX_STDCALL    __stdcall
# define SGX_FASTCALL   __fastcall

# define SGX_DLLIMPORT  __declspec(dllimport)
# define SGX_UBRIDGE(attr, fname, ...) attr fname __VA_ARGS__

# define SGX_DEPRECATED __declspec(deprecated)

#elif defined(__GNUC__)
/* The following macros are GCC only */

# define SGXAPI

# ifdef linux
#  undef linux
# endif
# define SGX_CXX_NATIVE_HEADER(header)   <stdc++/linux/header>

# define SGX_CDECL
# define SGX_STDCALL
# define SGX_FASTCALL

# define SGX_DLLIMPORT
# define SGX_UBRIDGE(attr, fname, args...) attr fname args

# define SGX_DEPRECATED __attribute__((deprecated))

#endif /* __GNUC__ */

#define SGX_NOCONVENTION /* Empty.  No calling convention specified. */

#endif /* !_SGX_DEFS_H_ */
