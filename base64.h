/**
 * @file base64.h
 * 
 * Functions related to Base64 en-/decoding.
 * 
 * @author <MNR> <NAME>
 */

#ifndef __BASE64_H_
#define __BASE64_H_

/**
 * Encodes the given data array using Base64.
 * 
 * @param data the data to be encoded
 * @param size number of bytes to be encoded
 * @param encoded pointer to store the encoded bytes in
 * @return size of the encoded data
 */
unsigned long encodeBase64(const char *data, unsigned long size, char** encoded);

/**
 * Decodes the given Base64 encoded array.
 * 
 * @param data the data to be decoded
 * @param size number of bytes to be decoded
 * @param decoded pointer to store the decoded bytes in
 * @return size of the decoded data
 */
unsigned long decodeBase64(const char *data, unsigned long size, char** decoded);

/**
 * Returns the index inside the base64 lookup table for a given character c.
 * 
 * @param c the character for index determination
 * @return index [0-63] if found, or -1 if not found (e.g. '=' sign...)
 */
int getIndexFromLookupTable(char c);

/**
 * Computes the required size of the encoded data.
 * 
 * @param original_size size of the data (in bytes) to be encoded
 * @return size of the byte-array required to encode the data 
 */
unsigned long computeBase64EncodedSize(unsigned long original_size);

/**
 * Computes the required size of the decoded data.
 * 
 * @param data the base64 encoded data (needed to check paddings...)
 * @param encoded_size size of the data (in bytes) to be decoded
 * @return size of the byte-array required to decode the given data 
 */
unsigned long computeBase64DecodedSize(const char* data, unsigned long encoded_size);

#endif // __BASE64_H_
