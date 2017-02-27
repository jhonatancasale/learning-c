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

size_t myStrlen(const char *s);

int main (int argc, char **argv)
{
  for ( int i = 0; i < argc; i++ )
    printf ("len(%s):[%i]\n", argv[i], myStrlen(argv[i]));

  return (EXIT_SUCCESS);
}

size_t myStrlen(const char *s)
{
  size_t n = 0;

  while ( s[n] != '\0') n++;

  return n;
}
