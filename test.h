/**
 * @file test.h
 * 
 * Functions for testing your implementation. Make sure you complete all TODOs!!
 * 
 * @author <MNR> <NAME>
 */
#ifndef __TEST_H_
#define __TEST_H_

// Do NOT change these definitions!
#define SUCCESS 0x0
#define FAILURE 0x1

#define TC_PAD0 "RNO"
#define TC_PAD1 "rnoA2"
#define TC_PAD2 "2010"
#define TC_POEM "Remember, remember the Fifth of November,\n\
The Gunpowder Treason and Plot,\n\
I see no reason;\n\
Why the Gunpowder Treason\n\
Should ever be forgot.\n\
Guy Fawkes, Guy Fawkes, t'was his intent\n\
To blow up the King and Parli'ment.\n\
Three-score barrels of powder below\n\
To prove old England's overthrow;\n\
By God's providence he was catch'd\n\
With a dark lantern and burning match.\n\
Holla boys, Holla boys, let the bells ring.\n\
Holloa boys, holloa boys, God save the King!\n\
And what should we do with him? Burn him!"

/**
 * Prints each element of the given array as character onto the terminal -
 * for debug purposes.
 * Values below 0x20 (' ') will not be printed to prevent errors with the
 * terminal display while testing binary files...
 *
 * @param prefix - will be printed before the array like "<prefix>: "
 * @param buffer
 * @param size
 */
void printChars(const char *prefix, const char *buffer, unsigned long size);

/**
 * Prints the hex value of each element of the given array onto the terminal -
 * for debug purposes.
 *
 * @param prefix - will be printed before the array like "<prefix>: "
 * @param buffer
 * @param size
 */
void printBytes(const char *prefix, const char *buffer, unsigned long size);

/**
 * Runs a testcase with the given data under the provided title.
 * 
 * @param title testcase title
 * @param data original data
 * @param size length of the original data in bytes
 * @return SUCCESS or FAILURE
 */
int test(const char *title, const char *data, unsigned long size);

/**
 * Checks whether the given buffers are the same or not.
 * 
 * @param encoded first buffer
 * @param size_encoded length of the first buffer
 * @param expected second buffer holding the expected values
 * @param size_expected length of the second buffer
 * @return SUCCESS if the given buffers are the same, FAILURE if they differ 
 */
int equals(const char *encoded, unsigned long size_encoded, const char *expected, unsigned long size_expected);


#endif // __TEST_H_
