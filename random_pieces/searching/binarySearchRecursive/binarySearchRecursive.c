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
int search(int value, int values[], int const start, const int end);
void issues(void);

int ascending(const void *a, const void *b);
#define SIZE 32

void must_be_true_sample(void);
void must_be_false_sample(void);

int debug_enabe = 0;

int main (int argc, char **argv)
{
  for (int i = 0; i < 4000000; i++ ) must_be_true_sample();

  for (int i = 0; i < 4000000; i++ ) must_be_false_sample();

  issues();

  return (EXIT_SUCCESS);
}

int search(int value, int values[], int const start, const int end)
{
  int middle = (start + end) / 2;

  if (debug_enabe) printf ("[%i,%i,%i]\n", start, middle, end);

  if ( start > end ) return ( value == values[ end ] ) ? 1 : 0;

  if (values[ middle ] == value ) return 1;

  if ( value > values[ middle ] ) 
    return search(value, values, middle + 1, end);

  else 
    return search(value, values, start, middle - 1);

  return search(value, values, start, end);
}

void issues(void)
{
  int haystack[ SIZE ];
  int needle = 94;


  for (int i = 0; i < SIZE; i++ ) haystack[ i ] = i;

  if ( search(needle, haystack, 0, SIZE) ) {
    debug_enabe = 1;
    search(needle, haystack, 0, SIZE);
    debug_enabe = 0;

    printf("\n");
    print_int_vector( haystack, SIZE);
    printf ("::%i\n", needle);
  }
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

int ascending(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void must_be_true_sample(void)
{
  int haystack[ SIZE ];
  int needle = 0;

  fill_with_random_integers(haystack, SIZE);
  needle = get_random_int(100, 0);
  haystack[ 0 ] = needle;

  qsort(haystack, SIZE, sizeof(int), ascending);
  if ( !search(needle, haystack, 0, SIZE - 1) ) {
    debug_enabe = 1;
    search(needle, haystack, 0, SIZE - 1);
    debug_enabe = 0;

    printf("\n");
    print_int_vector( haystack, SIZE);
    printf ("::%i\n", needle);
  }
}

void must_be_false_sample(void)
{
  int haystack[ SIZE ];
  int needle = get_random_int(100, SIZE + 1);
  for (int i = 0; i < SIZE; i++ ) haystack[ i ] = i;

  if ( search(needle, haystack, 0, SIZE - 1) ) {
    debug_enabe = 1;
    search(needle, haystack, 0, SIZE - 1);
    debug_enabe = 0;

    printf("\n");
    print_int_vector( haystack, SIZE);
    printf ("::%i\n", needle);
  }
}
