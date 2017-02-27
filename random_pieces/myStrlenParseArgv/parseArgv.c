/*
 * Author:	Jhonatan Casale (jhc)
 *
 * Contact : jhonatan@jhonatancasale.com
 *         : casale.jhon@gmail.com
 *         : https://github.com/jhonatancasale
 *         : https://twitter.com/jhonatancasale
 *         : http://jhonatancasale.github.io/
 *
 * Create date Sun 26 Feb 08:56:31 BRT 2017
 *
 */

#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv)
{

  for ( int i = 0; i < argc; i++ )
  {
    int count = 0;

    while (argv[i][count] != '\0') count++;

    printf ("len(%s):[%i]\n", argv[i], count);
  }

  return (EXIT_SUCCESS);
}
