#ifndef _EMBOS_USER_SETTINGS_H_
#define _EMBOS_USER_SETTINGS_H_

    #define WOLFCRYPT_ONLY
    #define NO_64BIT
    #define SIZEOF_LONG 4
    #define SIZEOF_LONG_LONG 8
    #define HAVE_CHACHA
    #define HAVE_POLY1305
    #define ECC_SHAMIR
    #define HAVE_ECC
    #define WOLFSSL_SHA512
    #define WOLFSSL_SHA384
    #define HAVE_AESGCM
    #define NO_INLINE
    #define BENCH_EMBEDDED

#endif /* _EMBOS_USER_SETTINGS_H_ */