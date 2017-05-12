/*
 * Author: Jhonatan Casale (jhc)
 *
 * Contact : jhonatan@jhonatancasale.com
 *         : casale.jhon@gmail.com
 *         : https://github.com/jhonatancasale
 *         : https://twitter.com/jhonatancasale
 *         : http://jhonatancasale.github.io/
 *
 * Create date Fri 12 May 15:26:40 -03 2017
 *
 */

#include <stdlib.h>
#include <stdio.h>

int sum_divs_interval(int m, int n);
int sum_divs(int m);

int main (int argc, char **argv)
{
  int m, n;

  scanf("%d", &m);
  scanf("%d", &n);

  printf("Sum of divisors from %d, to %d is %d\n", 
          m, n, sum_divs_interval(m, n));

  return (EXIT_SUCCESS);
}

int sum_divs_interval(int m, int n) {
  if(m > n) 
    return (-1);

  int sum = 0;

  for(int i = m; i <= n; ++i)
    sum += sum_divs(i);

  return sum;
}

int sum_divs(int m) {
  int sum = 0;

  for(int i = 1; i <= m; ++i)
    if(m % i == 0)
      sum += i;

  return sum;
}
