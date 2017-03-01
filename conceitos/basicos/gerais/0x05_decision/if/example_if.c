/*
 * Author: Jhonatan Casale (jhc)
 *
 * Contact : jhonatan@jhonatancasale.com
 *         : casale.jhon@gmail.com
 *         : https://github.com/jhonatancasale
 *         : https://twitter.com/jhonatancasale
 *         : http://jhonatancasale.github.io/
 *
 * Create date Wed  1 Mar 05:56:26 BRT 2017
 *
 */

#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv)
{
  int n = 0;
 
  printf ("Type a int: ");
  scanf ("%i", &n);

  // single if
  if ( n > 0 ) {
    printf ("Positive\n");
  }

  //I'm here just to enhance output messages
  printf ("\n");

  // if else
  if ( n > 0 ) {
    printf ("Positive\n");
  } else {
    printf ("Not positive\n");
  }

  //I'm here just to enhance output messages
  printf ("\n");

  // if else if
  if ( n > 0 ) {
    printf ("Positive\n");
  } else if ( n == 0 ) {
    printf ("Neutral\n");
  } else {
    printf ("Not positive\n");
  }

  // if else if without optionals {}
  if ( n > 0 ) printf ("Positive\n");
  else if ( n == 0 ) printf ("Neutral\n");
  else printf ("Not positive\n");

  return (EXIT_SUCCESS);
}
