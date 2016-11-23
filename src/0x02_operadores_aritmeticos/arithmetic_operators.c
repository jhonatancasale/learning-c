/*
 * Author: Jhonatan Casale (jhc)
 *
 * Contact : jhonatan@jhonatancasale.com
 *         : casale.jhon@gmail.com
 *         : https://github.com/jhonatancasale
 *         : https://twitter.com/jhonatancasale
 *         : http://jhonatancasale.github.io/
 *
 * Create date Wed 23 Nov 06:30:01 BRST 2016
 *
 */

#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv)
{
  int a = 3, b = 7;

  printf ( "soma = a + b = %d\n", a + b );
  printf ( "sub = a - b = %d\n", a - b );
  printf ( "mult = a * b = %d\n", a * b );
  printf ( "div = a / b = %d\n", a / b );
  printf ( "div = a / b = %f\n", (float)a / b );
  printf ( "resto = a %% b = %d\n", a % b );

  printf ( "\n" );

  printf ( "(a, b) == (%d, %d)\n", a, b );
  a += b;
  printf ( "[a += b]=> (a, b) == (%d, %d)\n", a, b );

  printf ( "\n" );

  printf ( "(a) == (%d)\n", a);
  a++;
  printf ( "[a++]=> (a) == (%d)\n", a);
  printf ( "(a++) == (%d)\n", a++);
  printf ( "(++a) == (%d)\n", ++a);

  printf ( "\n" );
  b = 3;
  a = b++;
  printf ( "[a = b++]=>(a, b) == (%d, %d)\n", a, b );
  b = 3;
  a = ++b;
  printf ( "[a = ++b]=>(a, b) == (%d, %d)\n", a, b );

  return (EXIT_SUCCESS);
}
