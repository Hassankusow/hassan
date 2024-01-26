#include <stdio.h>

int main(){
       printf("Size of basic c data types\n");

       printf("sizeof(int): %u bytes %u bits\n",  sizeof(char), sizeof(char)* 8);
       printf("sizeof(int):  %u bytes %u bits\n ",  sizeof(int), sizeof(int) * 8);
       printf("sizeof(short):  %u bytes %u bits\n  ",  sizeof(short), sizeof(short) * 8);
       printf("sizeof(float):  %u bytes %u bits\n ",  sizeof(float), sizeof(float) * 8);
       printf("sizeof(double):  %u bytes %u bits\n ",  sizeof(double), sizeof(double) * 8);
       printf("sizeof(long):  %u bytes %u bits\n  ",  sizeof(long), sizeof(long) * 8);
       printf("sizeof(double long):  %u bytes %u bits\n ",  sizeof(double long), sizeof(double long) * 8);
       printf("sizeof(void):  %u bytes%u bits\n ",  sizeof(void * ), sizeof(void * ) * 8);

       return 0;

}
