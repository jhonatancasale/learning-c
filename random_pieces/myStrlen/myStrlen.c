/*
 * Author:	Jhonatan Casale (jhc)
 *
 * Contact : jhonatan@jhonatancasale.com
 *         : casale.jhon@gmail.com
 *         : https://github.com/jhonatancasale
 *         : https://twitter.com/jhonatancasale
 *         : http://jhonatancasale.github.io/
 *
 * Create date Sun 26 Feb 08:47:14 BRT 2017
 *
 */

#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv)
{
  if ( argc == 2 )
  {
    int count = 0;

    while (argv[1][count] != '\0') count++;

    printf ("%i\n", count);
  }

  return (EXIT_SUCCESS);
}
