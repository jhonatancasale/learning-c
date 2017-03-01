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
#include <ctype.h>

int main (int argc, char **argv)
{
  char str[] = "Hello, world!";

  int i = 0;
  while ( str[i] != '\0' ) {
    printf ("%c\n", str[i]); 
    i++;
  }

  printf ("\n");

  i = 0;
  while ( str[i] != '\0' )
    printf ("%c", toupper(str[i++])); 

  printf ("\n");

  return (EXIT_SUCCESS);
}
