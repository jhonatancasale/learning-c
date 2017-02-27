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

void sort(int values[], int n);
void swap_values(int *a, int *b);
int ascending(const void *a, const void *b);
void sample();

#define SIZE 32
#define RANDRANGE 1024

int did_all_the_values_match_question_mark(int *values, size_t size);

int debug_enabe = 0;

int main (int argc, char **argv)
{
  for (int i = 0; i < 1000000; i++ ) sample();

  return (EXIT_SUCCESS);
}

int search(int value, int values[], int n)
{
  int start = 0, end = n - 1, middle = (start + end) / 2;

  while ( start < end ) 
  {
    if (debug_enabe) printf ("[%i,%i,%i]\n", start, middle, end);

    if (values[ middle ] == value ) return 1;
    else {
      if ( value > values[ middle ] ) start = middle + 1; 

      else end = middle - 1; 

      middle = (start + end) / 2;
    }
  }

  return ( value == values[ end ] ) ? 1 : 0;
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
  for (int i = 0; i < size; i++) a[i] = get_random_int(RANDRANGE, 0);

  return a;
}

int ascending(const void *a, const void *b) { return *(int *)a - *(int *)b; }


void sample()
{
  int values[ SIZE ];
  fill_with_random_integers(values, SIZE);
  sort(values, SIZE);

  if ( !did_all_the_values_match_question_mark(values, SIZE) ) {
    print_int_vector( values, SIZE );
    printf("\n");

    qsort(values, SIZE, sizeof(int), ascending);
    print_int_vector( values, SIZE );
    printf("\n\n");
  }

}

int did_all_the_values_match_question_mark(int *values, size_t size)
{
  int ref[ SIZE ];

  for ( int i = 0; i < size; i++ ) ref[i] = values[i];

  qsort(ref, SIZE, sizeof(int), ascending);

  for ( int i = 0; i < size; i++ ) if ( ref[i] != values[i] ) return 0;

  return 1;
}

void sort(int values[], int n)
{
  for ( int i = 1; i < n; i++ )
    for ( int j = i; j > 0; j-- )
      if ( values[ j ] < values[ j - 1 ] ) 
        swap_values(&values[ j ], &values[ j - 1 ]);
}

void swap_values(int *a, int *b){
  int aux = *a;
  *a = *b;
  *b = aux;
}
