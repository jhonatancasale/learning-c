/*
 * Author: Jhonatan Casale (jhc)
 *
 * Contact : jhonatan@jhonatancasale.com
 *         : casale.jhon@gmail.com
 *         : https://github.com/jhonatancasale
 *         : https://twitter.com/jhonatancasale
 *         : http://jhonatancasale.github.io/
 *
 * Create date Sun 26 Feb 09:18:28 BRT 2017
 *
 */

#include <stdlib.h>
#include <stdio.h>

int validTriangle(double lengths[]);

int main (int argc, char **argv)
{
  double case_a[] = {1.0, 1.0, 4.0};
  double case_b[] = {1.0, 1.0, 1.0};
  double case_c[] = {3.0, 4.0, 5.0};

  printf ("[1, 1, 4]::%s\n", (validTriangle(case_a)) ? "True" : "False");
  printf ("[1, 1, 1]::%s\n", (validTriangle(case_b)) ? "True" : "False");
  printf ("[3, 4, 5]::%s\n", (validTriangle(case_c)) ? "True" : "False");

  return (EXIT_SUCCESS);
}

int validTriangle(double lengths[])
{
  for (int i = 0; i < 3; i++ )
    if ( lengths[i] < 0 ) 
      return 0;

  double sum = 0.0;

  for (int i = 0; i < 3; i++ ) sum += lengths[ i ];

  for (int i = 0; i < 3; i++ )
    if ( lengths[ i ] > (sum - lengths[ i ]) ) return 0;

  return 1;
}
