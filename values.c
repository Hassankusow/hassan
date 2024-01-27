#include <stdio.h>

int main(int argc, char **argv)
{
     char str[] = "assembly is fun";	

     char *charp = (char *) str;
     short *shortp = (short *) str;
     int *intp = (int *) str;
     long *longp = (long *) str;
     unsigned int *un_intp = (unsigned int *) str;
     float *floatp = (float *) str;
     double *doublep = (double *) str;
      

     printf("as a string:        %s\n", str);
     printf("as a char:          %hhd %#hhx  %#hho\n", *charp, *charp, *charp);
     printf("as a  short:        %hd   %#hx  %#ho\n", *shortp, *shortp, *shortp);
     printf("as an int:          %d    %#x  %#o\n", *intp, *intp, *intp);
     printf("as a long:          %ld   %#lx  %#lo\n", *longp, *longp, *longp);
     printf("as an unsigned int: %u    %#x  %#o\n", *un_intp, *un_intp, *un_intp);
     printf("as a float:         %f\n", *floatp);
     printf("as a double:        %lf\n", *doublep);
     
    

     return 0;
}
