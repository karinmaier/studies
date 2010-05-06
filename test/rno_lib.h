/**
 * @file rno_lib.h
 * 
 * Functions providing base64 encoding and lfsr encryption 
 * required to test your implementation.
 * 
 * @author hpossegger
 */
#ifndef __RNO_TEST_H_
#define __RNO_TEST_H_

/**
 * Type definitions
 */
typedef unsigned long ulong;
typedef unsigned int uint32;

/**
 * Base64 encoding of the given data.
 * 
 * @param data
 * @param size
 * @param encoded
 * @return encoded size
 */
ulong b64enc(const char *data, ulong size, char **encoded);

/**
 * Base64 decoding of the given b64 encoded data.
 * 
 * @param data
 * @param size
 * @param decoded
 * @return size of the decoded buffer
 */
ulong b64dec(const char *data, ulong size, char **decoded);

/**
 * Encrypts the given data with a 32-bit LFSR.
 * @param data
 * @param size
 * @param seed MNR as seed for the lfsr
 */
void lfsrenc(char **data, ulong size, uint32 seed);

#endif // __RNO_TEST_H_
