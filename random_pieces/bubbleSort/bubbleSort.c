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

void swap_values(int *a, int *b);

int * bubble_sort(int *a, const size_t size, 
    int (*compar)(const void *, const void *) );
int * bubble_sort_t(int *a, const size_t size, 
    int * times, int (*compar)(const void *, const void *) );

int descending(const void *a, const void *b);
int ascending(const void *a, const void *b);


#define SIZE 32

int main (int argc, char **argv)
{

  int a[ SIZE ];
  int times = 0;

  print_int_vector( fill_with_random_integers(a, SIZE), SIZE);
  printf ("\n");

  print_int_vector( bubble_sort_t(a, SIZE, &times, ascending), SIZE);
  printf ("::%i\n", times);
  print_int_vector( bubble_sort_t(a, SIZE, &times, ascending), SIZE);
  printf ("::%i\n", times);
  print_int_vector( bubble_sort_t(a, SIZE, &times, descending), SIZE);
  printf ("::%i\n", times);

  print_int_vector( bubble_sort(a, SIZE, ascending), SIZE);
  printf ("\n");

  qsort(a, SIZE, sizeof(int), ascending);
  print_int_vector( a,  SIZE);
  printf ("\n");

  return (EXIT_SUCCESS);
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

int * bubble_sort_t(int *a, const size_t size, 
    int * times, int (*cmp)(const void *a, const void *b) )
{
  int run_times = 0;
  int swapped = 0;

  for ( int i = 0; i < size - 1; i++ )
  {
    for ( int j = 0; j < size - 1 - i; j++, run_times++ )
    {
      if ( (*cmp)( (const void *)&a[ j ], (const void *)&a[ j + 1 ] ) > 0 ) {
        swapped = 1;

        swap_values(&a[j], &a[j + 1]);
      }
    } 

    if (!swapped) break;
    swapped = 0;
  }

  *times = run_times;

  return a;
}

int * bubble_sort(int *a, const size_t size, 
    int (*cmp)(const void *a, const void *b) )
{
  int swapped = 0;

  for ( int i = 0; i < size - 1; i++ )
  {
    for ( int j = 0; j < size - 1 - i; j++ )
    {
      if ( (*cmp)( (const void *)&a[ j ], (const void *)&a[ j + 1 ] ) > 0 ) {
        swapped = 1;

        swap_values(&a[j], &a[j + 1]);
      }
    } 

    if (!swapped) break;
    swapped = 0;
  }

  return a;
}

void swap_values(int *a, int *b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

int ascending(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int descending(const void *a, const void *b) { return *(int *)b - *(int *)a; }
