#!/bin/bash

# this script will reformat the wolfSSL source code to be compatible with
# a Libelium project
# run as bash ./wolfssl-libelium.sh

DIR=${PWD##*/}
LPATH=../../wolfssl-libelium

if [ "$DIR" == "LIBELIUM" ]; then
    mkdir -p "$LPATH"
    mkdir -p "$LPATH"/wolfcrypt/src
    cp ../../src/*.c "$LPATH"/
    cp ../../wolfcrypt/src/*.c "$LPATH"/
    cp ../../wolfcrypt/src/misc.c "$LPATH"/wolfcrypt/src/misc.c
    cp -R ../../wolfssl  "$LPATH"/
    echo "/* stub header file for Libelium compatibility */" > "$LPATH"/wolfssl.h
else
    echo "ERROR: You must be in the IDE/LIBELIUM directory to run this script"
fi
