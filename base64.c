/**
 * @file base64.c
 * 
 * Functions related to Base64 en-/decoding.
 * 
 * @author <MNR> <NAME>
 */

#include "base64.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * The lookup table containing the 64 characters for Base64 encoding.
 */
const char lookup_table[64] =
{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
    'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/' };


unsigned long encodeBase64(const char *data, unsigned long size, char** encoded)
{
  unsigned long encoded_size;

  encoded_size = computeBase64EncodedSize(size);
  *encoded = (char*) malloc(encoded_size * sizeof(char));
  
  // TODO you must implement the Base64 encoding functionality here

  
  // Do NOT change the return value!
  return encoded_size;
}

unsigned long decodeBase64(const char *data, unsigned long size, char** decoded)
{
  unsigned long decoded_size;

  decoded_size = computeBase64DecodedSize(data, size);
  *decoded = (char*) malloc(decoded_size * sizeof(char));
  
  // TODO you must implement the Base64 decoding functionality here


  // Do NOT change the return value!
  return decoded_size;
}

int getIndexFromLookupTable(char c)
{
  if (c >= 'A' && c <= 'Z')
    return c - 'A';
  if (c >= 'a' && c <= 'z')
    return c - 'a' + 26;
  if (c >= '0' && c <= '9')
    return c - '0' + 52;
  if (c == '+')
    return 62;
  if (c == '/')
    return 63;
  return -1;
}

unsigned long computeBase64EncodedSize(unsigned long original_size)
{
  // Check if we need padding bytes
  if (original_size % 3)
    original_size += (3 - (original_size % 3));
  return (original_size / 3) * 4;
}

unsigned long computeBase64DecodedSize(const char *data, unsigned long encoded_size)
{
  unsigned long length;
  // Valid base64 encoding's size must be a multiple of 4
  if ((encoded_size % 4) || (encoded_size < 2))
    return -1;

  length = (encoded_size / 4) * 3;
  // Correct computed length if the encoding contains padded bytes
  if (data[encoded_size - 1] == '=')
    --length;
  if (data[encoded_size - 2] == '=')
    --length;
  return length;
}
