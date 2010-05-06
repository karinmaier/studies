# @file crypto.s
# 
# Implementation of the encryption function using a 32-bit LFSR
# 
# @author <MNR> <NAME>
#
# ATTENTION: we strongly recommend you that you implement the LFSR NOT HERE, but
# inside crypto.c. By doing so, you will implement this function in C and auto-generate
# (and understand) the Assembler-code afterwards.
# However, if you want to, you can do everything in Assembler too - by simply implementing
# the functionality below...



.data
# You might use this variable to store the current state of the LFSR in
# it. However, you don't have to use it if you prefer another method (like
# putting everything on the stack, ...).
lfsr:
	.long 0x0

.text
.globl encrypt
encrypt: 
# Prepare the stack frame for the encrypt-function
  pushl %ebp
  movl %esp,%ebp

# ebp+8 is the location of the first argument (data to be encrypted)
# ebp+12 is the location of the second argument (size)
# e.g. the command 'movl 12(%ebp), %ecx' moves the value of the size parameter
# into the counter register (ECX) - you might need this to loop over all
# the bytes...

# TODO Start your implementation of the LFSR encryption here



# Clean up stack frame (restore base pointer) and return from function
return: 
  movl %ebp, %esp
  popl %ebp
  ret


