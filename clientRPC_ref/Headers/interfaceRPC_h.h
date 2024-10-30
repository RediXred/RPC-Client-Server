

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 06:14:07 2038
 */
/* Compiler settings for interfaceRPC.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __interfaceRPC_h_h__
#define __interfaceRPC_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __InterfaceRPC_INTERFACE_DEFINED__
#define __InterfaceRPC_INTERFACE_DEFINED__

/* interface InterfaceRPC */
/* [version][uuid] */ 

#define	INT_ARRAY_LEN	( 100 )

unsigned int _size( 
    /* [in] */ handle_t IDL_handle,
    /* [string][in] */ const unsigned char *file_name);

int _delete( 
    /* [in] */ handle_t IDL_handle,
    /* [string][in] */ const unsigned char *file_name);

int _check( 
    /* [in] */ handle_t IDL_handle,
    /* [string][in] */ unsigned char *login,
    /* [string][in] */ unsigned char *password);

int _download( 
    /* [in] */ handle_t IDL_handle,
    /* [string][in] */ const unsigned char *name,
    /* [size_is][out][in] */ unsigned char *bytes,
    /* [in] */ unsigned int size);

int _upload( 
    /* [in] */ handle_t IDL_handle,
    /* [string][in] */ const unsigned char *name,
    /* [size_is][in] */ const unsigned char *bytes,
    /* [in] */ unsigned int size);

void rpc_close( 
    /* [in] */ handle_t IDL_handle);



extern RPC_IF_HANDLE InterfaceRPC_v1_0_c_ifspec;
extern RPC_IF_HANDLE InterfaceRPC_v1_0_s_ifspec;
#endif /* __InterfaceRPC_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


