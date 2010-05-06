/**
 * @file file_io.c
 * 
 * File I/O required for assignment A2.
 * 
 * @author <MNR> <NAME>
 */

#include "file_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long readFileIntoBuffer(const char *path, char **buffer)
{
  FILE *fd;
  long file_size;
  long bytes_read;

  fd = fopen(path, "rb");
  if (fd == NULL)
  {
    fputs("File error", stderr);
    return ERR_FILE_NOT_FOUND;
  }

  // obtain file size:
  fseek(fd, 0, SEEK_END);
  file_size = ftell(fd);
  rewind(fd);

  // allocate memory to contain the whole file:
  *buffer = (char*) malloc(sizeof(char) * file_size);
  if (*buffer == NULL)
  {
    fputs("Memory error", stderr);
    fclose(fd);
    return ERR_OUT_OF_MEMORY;
  }

  // copy the file into the buffer:
  bytes_read = fread(*buffer, sizeof(char), file_size, fd);
  fclose(fd);
  if (bytes_read != file_size)
  {
    fputs("Reading error", stderr);
    return ERR_FILE_ACCESS;
  }

  return bytes_read;
}
