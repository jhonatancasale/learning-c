/*
 * Author: Jhonatan Casale (jhc)
 *
 * Contact : jhonatan@jhonatancasale.com
 *         : casale.jhon@gmail.com
 *         : https://github.com/jhonatancasale
 *         : https://twitter.com/jhonatancasale
 *         : http://jhonatancasale.github.io/
 *
 * Create date Tue 28 Feb 01:30:34 BRT 2017
 *
 */

#ifndef __SORT_H__
#define __SORT_H__

#include <stdlib.h>
#include <stdio.h>

int * bubble_sort
  (int *values, const size_t size, int (*cmp)(const void *, const void *) );

int * insertion_sort
  (int *values, const size_t size, int (*cmp)(const void *, const void *) );

int * bubble_sort_t
  (int *values, const size_t size, 
    int * times, int (*cmp)(const void *, const void *) );

void swap_values(int *a, int *b);

#endif
