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

//TODO comment me!
void random_int_init(void);
//TODO comment me!
int get_random_int(int range, int shift);

//TODO comment me!
void print_int_vector(int *v, size_t size);
//TODO comment me!
void vprintl(int *v, size_t size);
//TODO comment me!
void print_last_line (size_t length);
//TODO comment me!
void print_line (size_t length);

//TODO comment me!
int * fill_with_random_integers(int *a, const size_t size);
//TODO comment me!
int descending(const void *a, const void *b);
//TODO comment me!
int ascending(const void *a, const void *b);

//TODO comment me!
void memomy_allocation_failure_routine(void);
//TODO comment me!
void memomy_deallocation_failure_routine(void);

//TODO comment me!
int assert_sorted(int *values, 
    size_t size, int (*cmp)(const void *a, const void *b));

//TODO comment me!
int * get_sample(size_t nmemb);
//TODO comment me!
int * give_back_sample(int ** sample);

//TODO comment me!
int effectiveness_test (
    int *(*sort_algorithm)
      (int *values, const size_t size, 
        int (*cmp)(const void *a, const void *b)),
    int (*cmp)(const void *a, const void *b),
    size_t nmemb, 
    unsigned int ntimes
);

//TODO comment me!
void test_case ( unsigned int failures, 
    unsigned int run_times, char * function_name, int verbose_mode);

//TODO comment me!
void effectiveness_switch( size_t sample_size, unsigned int run_times);
//TODO comment me!
void efficiency_switch( size_t sample_size, unsigned int run_times);

#endif
