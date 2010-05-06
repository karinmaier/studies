# Makefile for compiling/running assignment A2
#
# author hpossegger
#
# Info: if you want to implement the encryption module in the provided
# crypto.c file first, you have to change the target 'crypto.o'
# from
#      crypto.o: crypto.h\
#	     crypto.s
#	     $(ASM) $(ASM_FLAGS) crypto.s
# to
#      crypto.o: crypto.h\
#	     crypto.c
#	     $(CC) $(CC_FLAGS) crypto.c
#
# If you do so, DO NOT FORGET TO switch it back and test your 
# Assembler-module as well!!! 



# define all objects influenced
OBJECTS = main.o\
	file_io.o\
	base64.o\
	crypto.o\
	test.o

# define compiler flags
CC = gcc
LD = gcc
ASM = gcc
CC_FLAGS = -m32 -Wall -g -Wno-char-subscripts -c
LD_FLAGS = -m32 -L/usr/lib32 -L./test -Wall -g -o
LD_LIBS = -lrno_lib_neu
ASM_FLAGS = -m32 -c

# define name of executable file
EXECUTABLE = rno_a2

# if make is called without any arguments, call the main target
all	: $(EXECUTABLE)

# cleanup
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) *~ Assignment_A2.zip
	
# run - starts the application
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# target for building the application
$(EXECUTABLE) : $(OBJECTS)
	$(LD) $(LD_FLAGS) $(EXECUTABLE) $(OBJECTS) $(LD_LIBS)

# submission - prepare the archive for submission
submission : $(EXECUTABLE).zip
	@echo
	@echo "Submit the archive at the RNO website."
	@echo "Please don't forget to fill out your README.txt!"
	@echo

$(EXECUTABLE).zip : base64.h base64.c crypto.h crypto.s crypto.c test.h test.c README.txt Makefile
	zip Assignment_A2.zip $^


# test case targets below
test_all: $(EXECUTABLE)
	./runalltests.sh

test_pad0: $(EXECUTABLE)
	./$(EXECUTABLE) pad0

test_pad1: $(EXECUTABLE)
	./$(EXECUTABLE) pad1

test_pad2: $(EXECUTABLE)
	./$(EXECUTABLE) pad2

test_txt: $(EXECUTABLE)
	./$(EXECUTABLE) txt

test_binary: $(EXECUTABLE)
	./$(EXECUTABLE) binary
	

# object targets below

main.o:	main.c
	$(CC) $(CC_FLAGS) main.c

file_io.o: file_io.c\
	file_io.h
	$(CC) $(CC_FLAGS) file_io.c
	
base64.o: base64.c\
	base64.h
	$(CC) $(CC_FLAGS) base64.c

test.o: test.c\
	test.h
	$(CC) $(CC_FLAGS) test.c

   crypto.o: crypto.h\
#	     crypto.c
#	     $(CC) $(CC_FLAGS) crypto.c


