/**
 * @file crypto.c
 * 
 * Encryption and decryption functions.
 * 
 * @Karin Maier 0730195 <NAME>
 */




#include "crypto.h"
#include <stdio.h>
#include <stdlib.h>

//globale vars go here
//
//

int lfsr_seed;
unsigned int seed = 0;
int bitmask = 0x1;
int tap1 = 0;
int tap2 = 0;
int xor_result = 0;
char output_bit = 0;
char output_tmp = 0;
int byte_count = 0;
int lfsr_count = 0;



void encrypt(char **data, unsigned long size)
{
  //TODO we recommend that you implement this method *here* in C
  // and generate ASM-code afterwards using the command
  //    gcc -S crypto.c
  // ATTENTION: this will OVERWRITE the current version of crypto.s!!!
  //
  // Next, you will have to *understand* the content of the generated
  // ASM-code and manually "optimize" it (place comments where necessary...)
  // Remember, that you will have to explain the ASM-version to us!
  //
  // Please do not forget to change the corresponding target in the 
  // Makefile (you will find an explanation of what to do there).

  

    //als erstes die output bit von seed lesen...
  //verxoren mit data
  //lsfr anwerfen für neuens seed outu



  while (byte_count < size)
  {
    //printf("------bytecount: %d -----\n", byte_count);
    //TODO output byte (=8bit) mit data jeweils byte weise verxoren
    if (byte_count == 0)
    {
      output_bit = lfsr_seed; //outputbit nimm kopie 8 bit vom lfsr
    }
     
    //printf("Original Data: ");
    //printf("%x\n", data[0][byte_count]);
    //printbin(data[0][byte_count]);
    
    data[0][byte_count] = (data[0][byte_count] ^output_bit);
    //printf("Nach XOR: ");
    //printbin(data[0][byte_count]);
    //printf("%x\n", data[0][byte_count]);
   
    output_bit = 0; //null setzen für nächste runde 
    lfsr_count = 0;
  
    while (lfsr_count < 8)
    {
      seed = lfsr_seed;
      bitmask = 0x1;

      if ((seed%4) == 0)
      {
        tap1 = (seed & bitmask);//x**32 und s0
        seed = (seed>>1);//x**31 
        tap2 = (seed & bitmask);
        xor_result = (tap1^tap2);

        seed = (seed>>1); //x**30
        tap1 = (seed & bitmask);
        xor_result = (xor_result^tap1);

        seed = (seed>>1); //x**29
        tap1 = (seed & bitmask);
        xor_result = (xor_result^tap1);

        seed = (seed>>1); //x**28
        tap1 = (seed & bitmask);
        xor_result = (xor_result^tap1);

        seed = (seed>>6); //x**22
        tap1 = (seed & bitmask);
        xor_result = (xor_result^tap1);

        xor_result = (xor_result << 31);
      //  printf("FB mod 0: ");
       // printbin(xor_result);
      }
      else if((seed%4) == 1)
      {
        tap1 = (seed & bitmask);//x**32 und s0
        seed = (seed>>1);//x**31 
        tap2 = (seed & bitmask);
        xor_result = (tap1^tap2);

        seed = (seed>>1); //x**30
        tap1 = (seed & bitmask);
        xor_result = (xor_result^tap1);

        seed = (seed>>3); //x**27
        tap1 = (seed & bitmask);
        xor_result = (xor_result^tap1);

        seed = (seed>>2); //x**25
        tap1 = (seed & bitmask);
        xor_result = (xor_result^tap1);
  
        seed = (seed>>7);//x**18
        tap1 = (seed & bitmask);
        xor_result = (xor_result^tap1);

        xor_result = (xor_result << 31);
      //printf("FB mod 1: ");
      //printbin(xor_result);
      }
      else if((seed%4)==2)
      {
        tap1 = (seed & bitmask);//x**32 und s0
        seed = (seed>>1);//x**31 
        tap2 = (seed & bitmask);
        xor_result = (tap1^tap2);

        seed = (seed>>1); //x**30
        tap1 = (seed & bitmask);
        xor_result = (xor_result^tap1);

        seed = (seed>>7); //x**23
        tap1 = (seed & bitmask);
        xor_result = (xor_result^tap1);

        seed = (seed>>6); //x**17
        tap1 = (seed & bitmask);
        xor_result = (xor_result^tap1);
  
        seed = (seed>>10); //x**7
        tap1 = (seed & bitmask);
        xor_result = (xor_result^tap1);
    
        xor_result = (xor_result << 31);
    //  printf("xor_result 2: ");
   //   printbin(xor_result);


      }
      else
      {
        tap1 = (seed & bitmask);//x**32 und s0
        seed = (seed>>1);//x**31 
        tap2 = (seed & bitmask);
        xor_result = (tap1^tap2);

        seed = (seed>>1); //x**30
        tap1 = (seed & bitmask);
        xor_result = (xor_result^tap1);

        seed = (seed>>8); //x**22
        tap1 = (seed & bitmask);
        xor_result = (xor_result^tap1);

        seed = (seed>>8); //x**14
        tap1 = (seed & bitmask);
        xor_result = (xor_result^tap1);
  
        seed = (seed>>2); //x**12
        tap1 = (seed & bitmask);
        xor_result = (xor_result^tap1);
    
        xor_result = (xor_result << 31);
    //  printf("xor_result else: ");
   //   printbin(xor_result);
      }
      
    //TODO hier vorher output bit speichern
      bitmask = 0x1; //bitmask füs lsb zurückssetzen
      //printf("-----output_bit vor: ");printbin(output_bit);
      output_bit = (output_bit <<1);
      //printf("-----output_bit shift: ");printbin(output_bit);
      output_tmp = (lfsr_seed & bitmask);
      output_bit = (output_bit + output_tmp); //dazukopieren
      //printf("--output_bit nach: ");printbin(output_bit);


      lfsr_seed = (lfsr_seed >>1);   //shiften

      lfsr_seed = (lfsr_seed +xor_result); //xor_result einfügen = feedbackbit
  
      lfsr_count++;
    }

  //danach 8 output bits gesammelt



    byte_count++;

  }

  
  
  
  

}


