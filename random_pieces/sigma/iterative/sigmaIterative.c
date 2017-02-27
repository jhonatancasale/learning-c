/*
 * Author: Jhonatan Casale (jhc)
 *
 * Contact : jhonatan@jhonatancasale.com
 *         : casale.jhon@gmail.com
 *         : https://github.com/jhonatancasale
 *         : https://twitter.com/jhonatancasale
 *         : http://jhonatancasale.github.io/
 *
 * Create date Mon 27 Feb 04:55:37 BRT 2017
 *
 */

#include <stdlib.h>
#include <stdio.h>

int sigma(int n);

int main (int argc, char **argv)
{
  int n = 0;

  do {
    printf ("Input a positive integer number: ");
    scanf ("%d", &n);
  } while ( n <= 0 );

  printf ("sum(0, %i)::%i\n", n, sigma(n));

  return (EXIT_SUCCESS);
}

int sigma(int n) {
  int sum = 0;

  for (int i = 0; i <= n; i++) sum += i;

  return sum;
}
