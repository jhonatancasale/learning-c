%: include <stdlib.h>
%: include <stdio.h>
%: include <stdint.h>

int main ( int argc, char ** argv )
{
  int var = 1;

  float fl_var = 1.1;

  double dl_var = 1.2;

  char ch_var = 'a';

  printf("%d\n", var);
  printf("%f\n", fl_var);
  printf("%f\n", dl_var);
  printf("%c\n", ch_var);

  return ( EXIT_SUCCESS );
}
