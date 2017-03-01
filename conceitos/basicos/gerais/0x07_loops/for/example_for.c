/*
 * Author: Jhonatan Casale (jhc)
 *
 * Contact : jhonatan@jhonatancasale.com
 *         : casale.jhon@gmail.com
 *         : https://github.com/jhonatancasale
 *         : https://twitter.com/jhonatancasale
 *         : http://jhonatancasale.github.io/
 *
 * Create date Wed  1 Mar 01:51:51 BRT 2017
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char **argv)
{
  char str[] = "Hello, world!";

  for ( int i = 0, n = strlen(str); i < n; i++ ) {
    printf ("%c\n", str[i]); 
  }
  printf("\n");

  for ( int i = 0, n = strlen(str); i < n; i++ ) 
    printf ("%c", toupper(str[i])); 
  printf("\n\n");

  // Can I calculate the sum of a range of numbers?
  int sum = 0;

  for ( int i = 1; i <= 100; sum += i++ );

  printf("Sum from 0 to 100: %i\n\n", sum);

  // Can I calculate fact inner a loop?
  int fat = 1;

  for ( int i = 1; i <= 5; fat *= i++ );

  printf("factorial(5):%i\n", fat);

  return (EXIT_SUCCESS);
}
