/*
 * Author: Jhonatan Casale (jhc)
 *
 * Contact : jhonatan@jhonatancasale.com
 *         : casale.jhon@gmail.com
 *         : https://github.com/jhonatancasale
 *         : https://twitter.com/jhonatancasale
 *         : http://jhonatancasale.github.io/
 *
 * Create date Tue 31 Jan 18:40:15 BRST 2017
 *
 */

#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv)
{
  float value = 9.87657;
  char format[] = "%.2f";

  printf(format, value);

  return (EXIT_SUCCESS);
}
