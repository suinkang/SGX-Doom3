#pragma once

#ifndef _APP_H_
#define _APP_H_	__declspec(dllimport)

#include "sgx_error.h"       /* sgx_status_t */
#include "sgx_eid.h"     /* sgx_enclave_id_t */

#include "sgx_urts.h"
#include "sgx_uae_service.h"
#include "../../Enclave_u.h"

//typedef unsigned long long sgx_enclave_id_t;

# define ENCLAVE_FILENAME "Enclave.signed.dll"

#ifndef TRUE
# define TRUE 1
#endif

#ifndef FALSE
# define FALSE 0
#endif

//extern sgx_enclave_id_t global_eid;    /* global enclave id */

#endif /* !_APP_H_ */
