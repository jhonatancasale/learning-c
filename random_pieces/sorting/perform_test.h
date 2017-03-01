/*
 * Author: Jhonatan Casale (jhc)
 *
 * Contact : jhonatan@jhonatancasale.com
 *         : casale.jhon@gmail.com
 *         : https://github.com/jhonatancasale
 *         : https://twitter.com/jhonatancasale
 *         : http://jhonatancasale.github.io/
 *
 * Create date Tue 28 Feb 01:30:48 BRT 2017
 *
 */

#ifndef __PERFORM_TEST_H__
#define __PERFORM_TEST_H__

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sort.h>
#include <string.h>

#include "utils.h"

#define ERRORS_ONLY 0
#define SUCCESS_PROPORTION 1

void random_int_init(void);
int get_random_int(int range, int shift);

void print_int_vector(int *v, size_t size);
void vprintl(int *v, size_t size);

int * fill_with_random_integers(int *a, const size_t size);
int descending(const void *a, const void *b);
int ascending(const void *a, const void *b);

void memomy_allocation_failure_routine(void);
void memomy_deallocation_failure_routine(void);

int assert_sorted(int *values, 
    size_t size, int (*cmp)(const void *a, const void *b));

int * get_sample(size_t nmemb);
int * give_back_sample(int ** sample);

int effectiveness_test (
    int *(*sort_algorithm)
      (int *values, const size_t size, 
        int (*cmp)(const void *a, const void *b)),
    int (*cmp)(const void *a, const void *b),
    size_t nmemb, 
    unsigned int ntimes
);

void test_case ( unsigned int failures, 
    unsigned int run_times, char * function_name, int verbose_mode);

void effectiveness_switch( size_t sample_size, unsigned int run_times);
void efficiency_switch( size_t sample_size, unsigned int run_times);

#endif
