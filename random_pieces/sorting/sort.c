/*
 * Author: Jhonatan Casale (jhc)
 *
 * Contact : jhonatan@jhonatancasale.com
 *         : casale.jhon@gmail.com
 *         : https://github.com/jhonatancasale
 *         : https://twitter.com/jhonatancasale
 *         : http://jhonatancasale.github.io/
 *
 * Create date Tue 28 Feb 01:30:29 BRT 2017
 *
 */

#include <sort.h>

int * bubble_sort_t(int *a, const size_t size, 
    int * times, int (*cmp)(const void *a, const void *b) )
{
  int run_times = 0;
  int swapped = 0;

  for ( int i = 0; i < size - 1; i++ ) {
    for ( int j = 0; j < size - 1 - i; j++, run_times++ ) {
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

int * bubble_sort(int *values, const size_t size, 
    int (*cmp)(const void *a, const void *b) )
{
  int swapped = 0;

  for ( int i = 0; i < size - 1; i++ ) {
    for ( int j = 0; j < size - 1 - i; j++ ) {
      if ( (*cmp)((const void *)&values[ j ], 
                (const void *)&values[ j + 1 ]) > 0 ) 
      {
        swapped = 1;

        swap_values(&values[j], &values[j + 1]);
      }
    }

    if (!swapped) break;
    swapped = 0;
  }

  return values;
}

int * insertion_sort(int *values, const size_t size, 
    int (*cmp)(const void *a, const void *b) )
{
  for ( int i = 1; i < size; i++ )
    for ( int j = i; j > 0; j-- )
      //TODO use the cmp function
      if ( values[ j ] < values[ j - 1 ] ) 
        swap_values(&values[ j ], &values[ j - 1 ]);

  return values;
}

void swap_values(int *a, int *b){
  int aux = *a;
  *a = *b;
  *b = aux;
}
