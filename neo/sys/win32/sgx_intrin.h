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

#ifndef _SGX_INTRIN_H_
#define _SGX_INTRIN_H_

#if defined(__STDC__) || defined(__cplusplus) || defined(_MSC_VER)
# define __STRING(x)    #x
#else
# define __STRING(x)    "x"
#endif

#define _DEPR_MESSAGE(func) __STRING(func)" is deprecated in enclave."

/* Deprecated MSVC Intrinsics */
#if defined(_MSC_VER)
#include <intrin.h> /* Include MS intrin.h */
#include <sgx_cpuid.h>

/* Throw warnings if warning level >= 1 */
#if defined(__INTEL_COMPILER)
# pragma warning(1: 1786)
#else 
# pragma warning(1: 4996)
#endif

#define _SGX_DEPRECATED(__ret_type, __func_name, ...)         \
    __declspec(deprecated(_DEPR_MESSAGE(__func_name)))       \
    __ret_type __func_name(__VA_ARGS__)

#ifdef __cplusplus
extern "C" {
#endif

/*** Stack frame juggling ***/
_SGX_DEPRECATED(void *, _ReturnAddress, void);
_SGX_DEPRECATED(void *, _AddressOfReturnAddress, void);
_SGX_DEPRECATED(unsigned int, __getcallerseflags, void);

/*** GS segment addressing ***/
#ifdef _M_AMD64
_SGX_DEPRECATED(void, __writegsbyte, unsigned long, unsigned char);
_SGX_DEPRECATED(void, __writegsword, unsigned long, unsigned short);
_SGX_DEPRECATED(void, __writegsdword, unsigned long, unsigned long);
_SGX_DEPRECATED(void, __writegsqword, unsigned long, unsigned __int64);
/*_SGX_DEPRECATED(unsigned char, __readgsbyte, unsigned long); */
/*_SGX_DEPRECATED(unsigned short, __readgsword, unsigned long); */
/*_SGX_DEPRECATED(unsigned long, __readgsdword, unsigned long); */
/*_SGX_DEPRECATED(unsigned __int64, __readgsqword, unsigned long); */
_SGX_DEPRECATED(void, __incgsbyte, unsigned long);
_SGX_DEPRECATED(void, __incgsword, unsigned long);
_SGX_DEPRECATED(void, __incgsdword, unsigned long);
_SGX_DEPRECATED(void, __incgsqword, unsigned long);
_SGX_DEPRECATED(void, __addgsbyte, unsigned long, unsigned char);
_SGX_DEPRECATED(void, __addgsword, unsigned long, unsigned short);
_SGX_DEPRECATED(void, __addgsdword, unsigned long, unsigned long);
_SGX_DEPRECATED(void, __addgsqword, unsigned long, unsigned __int64);
#endif

/*** FS segment addressing ***/
#ifdef _M_IX86
_SGX_DEPRECATED(void, __writefsbyte, unsigned long, unsigned char);
_SGX_DEPRECATED(void, __writefsword, unsigned long, unsigned short);
_SGX_DEPRECATED(void, __writefsdword, unsigned long, unsigned long);
_SGX_DEPRECATED(void, __writefsqword, unsigned long, unsigned __int64);
/*_SGX_DEPRECATED(unsigned char, __readfsbyte, unsigned long); */
/*_SGX_DEPRECATED(unsigned short, __readfsword, unsigned long); */
/*_SGX_DEPRECATED(unsigned long, __readfsdword, unsigned long); */
/*_SGX_DEPRECATED(unsigned __int64, __readfsqword, unsigned long); */
_SGX_DEPRECATED(void, __incfsbyte, unsigned long);
_SGX_DEPRECATED(void, __incfsword, unsigned long);
_SGX_DEPRECATED(void, __incfsdword, unsigned long);
_SGX_DEPRECATED(void, __addfsbyte, unsigned long, unsigned char);
_SGX_DEPRECATED(void, __addfsword, unsigned long, unsigned short);
_SGX_DEPRECATED(void, __addfsdword, unsigned long, unsigned long);
#endif

/*** I/O ***/
_SGX_DEPRECATED(int __cdecl, _inp, unsigned short);
_SGX_DEPRECATED(int __cdecl, inp, unsigned short);
_SGX_DEPRECATED(unsigned long __cdecl, _inpd, unsigned short);
_SGX_DEPRECATED(unsigned long __cdecl, inpd, unsigned short);
_SGX_DEPRECATED(unsigned short __cdecl, _inpw, unsigned short);
_SGX_DEPRECATED(unsigned short __cdecl, inpw, unsigned short);
_SGX_DEPRECATED(int __cdecl, _outp, unsigned short,int);
_SGX_DEPRECATED(int __cdecl, outp, unsigned short,int);
_SGX_DEPRECATED(unsigned long __cdecl, _outpd, unsigned short,unsigned long);
_SGX_DEPRECATED(unsigned long __cdecl, outpd, unsigned short,unsigned long);
_SGX_DEPRECATED(unsigned short __cdecl, _outpw, unsigned short,unsigned short);
_SGX_DEPRECATED(unsigned short __cdecl, outpw, unsigned short,unsigned short);
_SGX_DEPRECATED(unsigned char, __inbyte, unsigned short);
_SGX_DEPRECATED(unsigned short, __inword, unsigned short);
_SGX_DEPRECATED(unsigned long, __indword, unsigned short);
_SGX_DEPRECATED(void, __outbyte, unsigned short, unsigned char);
_SGX_DEPRECATED(void, __outword, unsigned short, unsigned short);
_SGX_DEPRECATED(void, __outdword, unsigned short, unsigned long);
_SGX_DEPRECATED(void, __inbytestring, unsigned short, unsigned char *, unsigned long);
_SGX_DEPRECATED(void, __inwordstring, unsigned short, unsigned short *, unsigned long);
_SGX_DEPRECATED(void, __indwordstring, unsigned short, unsigned long *, unsigned long);
_SGX_DEPRECATED(void, __outbytestring, unsigned short, unsigned char *, unsigned long);
_SGX_DEPRECATED(void, __outwordstring, unsigned short, unsigned short *, unsigned long);
_SGX_DEPRECATED(void, __outdwordstring, unsigned short, unsigned long *, unsigned long);

/*** System information ***/
#define __cpuid(x, y)       sgx_cpuid(x, y)
#define __cpuidex(x, y, z)  sgx_cpuidex(x, y, z)

_SGX_DEPRECATED(unsigned __int64, __rdtsc, void);
_SGX_DEPRECATED(unsigned __int64, __rdtscp, unsigned int*);

#ifdef _M_AMD64
_SGX_DEPRECATED(void, __writeeflags, unsigned __int64);
_SGX_DEPRECATED(unsigned __int64, __readeflags, void);
#else
_SGX_DEPRECATED(void, __writeeflags, unsigned);
_SGX_DEPRECATED(unsigned, __readeflags, void);
#endif

/*** Interrupts ***/
/*_SGX_DEPRECATED(void __cdecl, __debugbreak, void); */
_SGX_DEPRECATED(void __cdecl, _disable, void);
_SGX_DEPRECATED(void __cdecl, _enable, void);
_SGX_DEPRECATED(void, __int2c, void);
_SGX_DEPRECATED(void, __halt, void);

/*** Protected memory management ***/
#ifdef _M_AMD64
_SGX_DEPRECATED(void, __writecr0, unsigned __int64);
_SGX_DEPRECATED(void, __writecr3, unsigned __int64);
_SGX_DEPRECATED(void, __writecr4, unsigned __int64);
_SGX_DEPRECATED(void, __writecr8, unsigned __int64);
_SGX_DEPRECATED(unsigned __int64, __readcr0, void);
_SGX_DEPRECATED(unsigned __int64, __readcr2, void);
_SGX_DEPRECATED(unsigned __int64, __readcr3, void);
_SGX_DEPRECATED(unsigned __int64, __readcr4, void);
_SGX_DEPRECATED(unsigned __int64, __readcr8, void);
_SGX_DEPRECATED(unsigned __int64, __readdr, unsigned int reg);
_SGX_DEPRECATED(void, __writedr, unsigned reg, unsigned __int64);
#else
_SGX_DEPRECATED(void, __writecr0, unsigned);
_SGX_DEPRECATED(void, __writecr3, unsigned);
_SGX_DEPRECATED(void, __writecr4, unsigned);
_SGX_DEPRECATED(void, __writecr8, unsigned);
_SGX_DEPRECATED(unsigned long, __readcr0, void);
_SGX_DEPRECATED(unsigned long, __readcr2, void);
_SGX_DEPRECATED(unsigned long, __readcr3, void);
_SGX_DEPRECATED(unsigned long, __readcr4, void);
_SGX_DEPRECATED(unsigned long, __readcr8, void);
_SGX_DEPRECATED(unsigned int, __readdr, unsigned int);
_SGX_DEPRECATED(void, __writedr, unsigned, unsigned int);
#endif
_SGX_DEPRECATED(void, __invlpg, void *); 

/*** System operations ***/
_SGX_DEPRECATED(unsigned __int64, __readmsr, unsigned long); 
_SGX_DEPRECATED(void, __writemsr, unsigned long, unsigned __int64); 
_SGX_DEPRECATED(unsigned __int64, __readpmc, unsigned long); 
_SGX_DEPRECATED(unsigned long, __segmentlimit, unsigned long); 
_SGX_DEPRECATED(void, wbinvd, void); 
_SGX_DEPRECATED(void, __lidt, void *); 
_SGX_DEPRECATED(void, __sidt, void *); 

/*** Libc functions ***/
_SGX_DEPRECATED(char * __cdecl, strcat, char *, const char *);
_SGX_DEPRECATED(char * __cdecl, strcpy, char *, const char *);
_SGX_DEPRECATED(char * __cdecl, _strset, char *, int);

_SGX_DEPRECATED(wchar_t * __cdecl, wcscat, wchar_t *, const wchar_t *);
_SGX_DEPRECATED(wchar_t * __cdecl, wcscpy, wchar_t *, const wchar_t *);
_SGX_DEPRECATED(wchar_t * __cdecl, _wcsset, wchar_t *, wchar_t);

/*** Other intrinsics disabled ***/
_SGX_DEPRECATED(void, __nvreg_save_fence, void);
_SGX_DEPRECATED(void, __nvreg_restore_fence, void);
_SGX_DEPRECATED(void, __vmx_vmptrst, unsigned __int64 *);
_SGX_DEPRECATED(void, __vmx_off, void);
#ifdef _M_AMD64
_SGX_DEPRECATED(unsigned char, __vmx_vmclear, unsigned __int64*);
_SGX_DEPRECATED(unsigned char, __vmx_vmlaunch, void);
_SGX_DEPRECATED(unsigned char, __vmx_vmptrld, unsigned __int64*);
_SGX_DEPRECATED(unsigned char, __vmx_vmread, size_t, size_t*);
_SGX_DEPRECATED(unsigned char, __vmx_vmresume, void);
_SGX_DEPRECATED(unsigned char, __vmx_vmwrite, size_t, size_t);
_SGX_DEPRECATED(unsigned char, __vmx_on, unsigned __int64*);
#endif
_SGX_DEPRECATED(void, __svm_clgi, void);
_SGX_DEPRECATED(void, __svm_invlpga, void*, int);
_SGX_DEPRECATED(void, __svm_skinit, int);
_SGX_DEPRECATED(void, __svm_stgi, void);
_SGX_DEPRECATED(void, __svm_vmload, size_t);
_SGX_DEPRECATED(void, __svm_vmrun, size_t);
_SGX_DEPRECATED(void, __svm_vmsave, size_t);
_SGX_DEPRECATED(int __cdecl, _setjmp, jmp_buf);
#ifdef _M_AMD64
_SGX_DEPRECATED(int __cdecl, _setjmpex, jmp_buf);
#endif

_SGX_DEPRECATED(void, __wbinvd, void);

__int64 __cdecl _abs64(__int64);

#ifdef __cplusplus
}
#endif

#endif /* _MSC_VER */

/* Deprecated GCC Built-ins */
#ifdef __GNUC__

#ifndef ANDROID
# include <x86intrin.h>
#endif

/*#pragma GCC diagnostic error "-Wdeprecated-declarations" */
#define _SGX_DEPRECATED(__ret_type, __func_name, ...)         \
    __attribute__((deprecated(_DEPR_MESSAGE(__func_name))))  \
    __ret_type __func_name(__VA_ARGS__)

_SGX_DEPRECATED(void, _writefsbase_u32, unsigned int);
_SGX_DEPRECATED(void, _writefsbase_u64, unsigned long long);
_SGX_DEPRECATED(void, _writegsbase_u32, unsigned int);
_SGX_DEPRECATED(void, _writegsbase_u64, unsigned long long);

_SGX_DEPRECATED(unsigned long long, __rdpmc,  int);
_SGX_DEPRECATED(unsigned long long, __rdtsc,  void);
_SGX_DEPRECATED(unsigned long long, __rdtscp, unsigned int *);

#endif /* __GNUC__ */

#endif /* _SGX_INTRIN_H_ */
