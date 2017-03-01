/*
 * Author: Jhonatan Casale (jhc)
 *
 * Contact : jhonatan@jhonatancasale.com
 *         : casale.jhon@gmail.com
 *         : https://github.com/jhonatancasale
 *         : https://twitter.com/jhonatancasale
 *         : http://jhonatancasale.github.io/
 *
 * Create date Wed  1 Mar 02:02:10 BRT 2017
 *
 */

#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv)
{
  int value = 0;

  do {
    printf ("Choose one:\n");
    printf ("[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]: ");
    scanf("%i", &value);
  } while ( value <= 0 || value > 10 );

  int i = 0;
  do printf ("%i\n", i);

  while ( ++i < value );

  return (EXIT_SUCCESS);
}
