#include <stdarg.h>
#include <stdio.h>      /* vsnprintf */
#include <map>
#include "Enclave_t.h"  /* print_string */
#include "sgx_trts.h"

using namespace std;
map<int, unsigned char*> g_ValuePool;

void sgx_memcpy(unsigned char * pDest, const unsigned char * pSrc, int Size)
{
	for (int i = 0; i < Size; i++)
		pDest[i] = pSrc[i];
}

int SGX_SetData(int Key, unsigned char * pValue, int Size)
{
	if (NULL == g_ValuePool[Key])
		g_ValuePool[Key] = new unsigned char[Size];


	sgx_memcpy(g_ValuePool[Key], pValue, Size);
	return 1;
}
int SGX_GetData(int Key, unsigned char * pGet, int Size)
{
	if (NULL == pGet)
		return 0;
	if (NULL == g_ValuePool[Key])
		g_ValuePool[Key] = new unsigned char[Size];
	sgx_memcpy(pGet, g_ValuePool[Key], Size);
	return 1;
}
