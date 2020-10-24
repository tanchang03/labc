#include <stdio.h>
  
  int glob_val;               //global uninitialized
  int glob_val2 = 2;          //global initialized
  //int glob_val5 = 4;
  //int glob_val6 = 4;
  static int glob_val3;       //static global uninitialized
  static int glob_val4 = 1;   //static global initialized
  
  int main(int argc , char *argv[]){
      int auto_val ;          //local uninitialized
      int auto_val2 = 3;      //local initialized
      static int stat_val ;   //static local uninitialized
      static int stat_val2 = 4;   //static local initialized
      char *p = "Hello World!";   //point to constant
  //  register reg_val = 5 ;      //register
  
      printf( "global uninitialized var's addr:"
              " %#08lx\n " , &glob_val );
      printf( "global initialized var's addr:"
              " %#08lx\n " , &glob_val2 );
      printf( "global initialized var's addr:"
              " %#08lx\n " , &glob_val3 );
      printf( "static global initialized var's addr:"
              " %#08lx\n " , &glob_val4 );
  
      printf( "constant value's addr:  %#08lx \n "
              "pointer's addr: %#08lx\n" , p , &p );
  //  printf( "register uninitialized var's addr:"
  //          " %#x\n " , &reg_val );
  
      printf( "local uninitialized var's addr:"
              " %#08lx\n " , &auto_val );
      printf( "local initialized var's addr:"
              " %#08lx\n " , &auto_val2 );
      printf( "static local uninitialized var's addr:"
              " %#08lx\n " , &stat_val );
      printf( "static local initialized var's addr:"
              " %#08lx\n " , &stat_val2 );
     return 0;
  }