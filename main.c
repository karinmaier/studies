/**
 * @file main.c
 * 
 * Main entry point for assignment A2.
 * 
 * @author hpossegger
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_io.h"
#include "test.h"

int main(int argc, char **argv)
{
  int result = SUCCESS;

  if (argc != 2)
  {
    fprintf(stderr, "Usage: ./rno_a2 test_case\n");
    fprintf(stderr, "e.g.: ./rno_a2 pad0\n\n");
    return -1;
  }

  if (!strcmp(argv[1], "pad0"))
    result = test("0-padded String", TC_PAD0, strlen(TC_PAD0));
  else if (!strcmp(argv[1], "pad1"))
    result = test("1-padded String", TC_PAD1, strlen(TC_PAD1));
  else if (!strcmp(argv[1], "pad2"))
    result = test("2-padded String", TC_PAD2, strlen(TC_PAD2));
  else if (!strcmp(argv[1], "txt"))
    result = test("A Poem", TC_POEM, strlen(TC_POEM));
  else if (!strcmp(argv[1], "binary"))
  {
    char *binary = 0;
    long size = 0;
    size = readFileIntoBuffer("test/iaik.png", &binary);
    if (size > 0)
    {
      result = test("Binary File", binary, size);
      free(binary);
    }
  }
  else
  {
    fprintf(stderr, "Given testcase does not exist\n\n");
    return -2;
  }

  if (result == SUCCESS)
    fprintf(stdout, "\nSUCCESS - Test passed!\n\n");
  else
    fprintf(stdout, "\nFAILURE- Test failed!\n\n");
  return result;
}
