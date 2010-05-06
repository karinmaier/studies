/**
 * @file crypto.h
 * 
 * Encryption and decryption functions.
 * 
 * @author <MNR> <NAME>
 */

#ifndef __CRYPTO_H_
#define __CRYPTO_H_

/**
 * Encrypts the given data array using a linear feedback shift register.
 * 
 * @param data array to be encrypted
 * @param size length of the array in bytes
 */
extern void encrypt(char **data, unsigned long size);

#endif //__CRYPTO_H_
