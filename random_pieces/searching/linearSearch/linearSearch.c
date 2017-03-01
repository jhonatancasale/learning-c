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
#include <time.h>

void random_int_init(void);
int get_random_int(int range, int shift);
void print_int_vector(int *v, size_t size);
int * fill_with_random_integers(int *a, const size_t size);
int search(int value, int values[], int n);

#define SIZE 32

int main (int argc, char **argv)
{

  int haystack[ SIZE ];
  fill_with_random_integers(haystack, SIZE);

  int needle = get_random_int(100, 0);
  int position = get_random_int( SIZE, 0 );
  haystack[ position ] = needle;

  printf("%i[%i]::%s\n", needle, position, search(needle, haystack, SIZE) ? "True" : "False");
  print_int_vector( haystack, SIZE);
  printf ("\n");

  needle = get_random_int(100, SIZE + 1);
  for (int i = 0; i < SIZE; i++ ) haystack[ i ] = i;
  printf("%i[%i]::%s\n", needle, position, search(needle, haystack, SIZE) ? "True" : "False");

  print_int_vector( haystack, SIZE);
  printf ("\n");

  return (EXIT_SUCCESS);
}


int search(int value, int values[], int n)
{
  for ( int i = 0; i < n; i++ )
    if ( value == values[ i ] ) return 1;

  return 0;
}

/**
 * Plant the `seed` in the ground
 */
void random_int_init(void) {
  static int already_run = 0;

  if ( !already_run ) {
    already_run = 1;
    srand(time(NULL));
  }
}

/**
 * Return a random int number in [shift, range -1]
 */
int get_random_int(int range, int shift) {
  random_int_init();

  return ( rand() % range ) + shift;
}

void print_int_vector(int *v, size_t size)
{
  printf ("[");
  for (int i = 0; i < size; i++)
    printf ("%i%s", v[ i ], (i != size -1) ? ", " : "]" );
}

int * fill_with_random_integers(int *a, const size_t size)
{
  for (int i = 0; i < size; i++) a[i] = get_random_int(100, 0);

  return a;
}
