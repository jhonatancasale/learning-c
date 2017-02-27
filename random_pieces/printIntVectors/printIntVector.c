/*
 * Author: Jhonatan Casale (jhc)
 *
 * Contact : jhonatan@jhonatancasale.com
 *         : casale.jhon@gmail.com
 *         : https://github.com/jhonatancasale
 *         : https://twitter.com/jhonatancasale
 *         : http://jhonatancasale.github.io/
 *
 * Create date Mon 27 Feb 05:04:21 BRT 2017
 *
 */

#include <stdlib.h>
#include <stdio.h>

void print_int_vector(int *v, const size_t size);

int main (int argc, char **argv)
{
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1};


  for (int i = 0; i <= 10; i++) {
    print_int_vector(a, i);
    printf ("\n");
  }

  return (EXIT_SUCCESS);
}

void print_int_vector(int *v, const size_t size) {
  printf ("[");

  if (size != 0) {
    for (int i = 0; i < size; i++)
      printf ("%i%s", v[ i ], (i != size -1) ? ", " : "]" );
  } else {
    printf ("]");
  }
}
