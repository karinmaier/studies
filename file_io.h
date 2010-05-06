/**
 * @file file_io.h
 * 
 * File I/O required for assignment A2.
 * 
 * @author <MNR> <NAME>
 */
#ifndef __FILE_IO_H_
#define __FILE_IO_H_

/**
 * Error codes
 */
#define ERR_FILE_NOT_FOUND -1
#define ERR_OUT_OF_MEMORY  -2
#define ERR_FILE_ACCESS    -3


/**
 * Reads the given file into the specified buffer. The buffer mustn't be 
 * allocated before this method call (to prevent memory leaks...)
 * 
 * @param path filename
 * @param buffer storage for read bytes
 * @return number of read bytes or negative number indicating an error (see above)
 */
long readFileIntoBuffer(const char* path, char** buffer);

#endif //__FILE_IO_H_
