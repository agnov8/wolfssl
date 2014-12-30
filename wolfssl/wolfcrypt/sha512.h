/* sha512.h
 *
 * Copyright (C) 2006-2014 wolfSSL Inc.
 *
 * This file is part of wolfSSL. (formerly known as CyaSSL)
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
 */

/* check for old macro */
#if defined(CYASSL_SHA512) && !defined(WOLFSSL_SHA512)
    #define WOLFSSL_SHA512
#endif
#if defined(CYASSL_SHA384) && !defined(WOLFSSL_SHA384)
    #define WOLFSSL_SHA384
#endif

#ifdef WOLFSSL_SHA512

#ifndef WOLF_CRYPT_SHA512_H
#define WOLF_CRYPT_SHA512_H

#include <wolfssl/wolfcrypt/types.h>

/* since using old code turn on old macros @wc_fips */
#if !defined(CYASSL_SHA512)
    #define CYASSL_SHA512
#endif
#if !defined(CYASSL_SHA384) && defined(WOLFSSL_SHA384)
    #define CYASSL_SHA384
#endif
/* for fips */
#include <cyassl/ctaocrypt/sha512.h>


#ifdef __cplusplus
    extern "C" {
#endif

WOLFSSL_API int wc_InitSha512(Sha512*);
WOLFSSL_API int wc_Sha512Update(Sha512*, const byte*, word32);
WOLFSSL_API int wc_Sha512Final(Sha512*, byte*);
WOLFSSL_API int wc_Sha512Hash(const byte*, word32, byte*);

#if defined(WOLFSSL_SHA384) || defined(HAVE_AESGCM)

WOLFSSL_API int wc_InitSha384(Sha384*);
WOLFSSL_API int wc_Sha384Update(Sha384*, const byte*, word32);
WOLFSSL_API int wc_Sha384Final(Sha384*, byte*);
WOLFSSL_API int wc_Sha384Hash(const byte*, word32, byte*);


#ifdef HAVE_FIPS
    /* fips wrapper calls, user can call direct */
    WOLFSSL_API int wc_InitSha512_fips(Sha512*);
    WOLFSSL_API int wc_Sha512Update_fips(Sha512*, const byte*, word32);
    WOLFSSL_API int wc_Sha512Final_fips(Sha512*, byte*);
    #ifndef FIPS_NO_WRAPPERS
        /* if not impl or fips.c impl wrapper force fips calls if fips build */
        #define InitSha512   InitSha512_fips
        #define Sha512Update Sha512Update_fips
        #define Sha512Final  Sha512Final_fips
    #endif /* FIPS_NO_WRAPPERS */

    /* fips wrapper calls, user can call direct */
    WOLFSSL_API int wc_InitSha384_fips(Sha384*);
    WOLFSSL_API int wc_Sha384Update_fips(Sha384*, const byte*, word32);
    WOLFSSL_API int wc_Sha384Final_fips(Sha384*, byte*);
    #ifndef FIPS_NO_WRAPPERS
        /* if not impl or fips.c impl wrapper force fips calls if fips build */
        #define InitSha384   InitSha384_fips
        #define Sha384Update Sha384Update_fips
        #define Sha384Final  Sha384Final_fips
    #endif /* FIPS_NO_WRAPPERS */

#endif /* HAVE_FIPS */


#endif /* WOLFSSL_SHA384 */

#ifdef __cplusplus
    } /* extern "C" */
#endif

#endif /* WOLF_CRYPT_SHA512_H */
#endif /* WOLFSSL_SHA512 */