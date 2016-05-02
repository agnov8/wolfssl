#ifndef _EMBOS_USER_SETTINGS_H_
#define _EMBOS_USER_SETTINGS_H_

    #define WOLFCRYPT_ONLY
    #define NO_64BIT
    #define SIZEOF_LONG 4
    #define SIZEOF_LONG_LONG 8
    #define HAVE_CHACHA
    #define HAVE_POLY1305
    #define HAVE_ECC
    #define WOLFSSL_SHA512
    #define WOLFSSL_SHA384
    #define HAVE_AESGCM
    #define NO_INLINE
    #define BENCH_EMBEDDED
	
	#ifdef USE_FAST_MATH
        /* Max ECC bits (curve size * 8). ECC521 is (66*8) = 528. */
        #undef  ALT_ECC_SIZE
        #define ALT_ECC_SIZE
        #undef  FP_MAX_BITS_ECC
        #define FP_MAX_BITS_ECC     528

        /* Enable TFM optimizations for ECC */
        #define TFM_ECC192
        #define TFM_ECC224
        #define TFM_ECC256
        #define TFM_ECC384
        #define TFM_ECC521
    #endif

#endif /* _EMBOS_USER_SETTINGS_H_ */