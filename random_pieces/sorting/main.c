/*
 * Author: Jhonatan Casale (jhc)
 *
 * Contact : jhonatan@jhonatancasale.com
 *         : casale.jhon@gmail.com
 *         : https://github.com/jhonatancasale
 *         : https://twitter.com/jhonatancasale
 *         : http://jhonatancasale.github.io/
 *
 * Create date Tue 28 Feb 01:30:05 BRT 2017
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <perform_test.h>

#include "utils.h"

#define USAGE_ERROR_MSG "Usage: ./program_name sample_size [run_times]\n"
#define BAD_SAMPLE_SIZE_FORMAT "sample_size must be a positive integer\n"
#define BAD_RUN_TIMES_FORMAT "run_times [if passed] must be a positive integer\n"

#define SAMPLE_SIZE 4096
#define RUN_TIMES 2018

//#define WIP_MAIN
#define TEST_VALUES

void parse_command_line(int argc, string argv[], 
    size_t *sample_size, unsigned int *run_times);

int bad_sample_size_assignment(size_t *sample_size, int value);
int bad_run_times_assignment(unsigned int *run_times, int value);

int main (int argc, string argv[])
{
  size_t sample_size = SAMPLE_SIZE;
  unsigned int run_times = RUN_TIMES;

  parse_command_line(argc, argv, &sample_size, &run_times);

#ifdef TEST_VALUES
  if ( sample_size == SAMPLE_SIZE || run_times == RUN_TIMES )
  {
    /* Check to avoid override user's values */
    if ( sample_size == SAMPLE_SIZE ) sample_size = 256;
    if ( run_times == RUN_TIMES ) run_times = 128;

    printf("Running with small validation values: "
        "sample_size:%lu, run_times:%u\n\n", sample_size, run_times);
  }
#endif


  //TODO Unit test this
  printf("[%lu::%u]\n", sample_size, run_times);

  effectiveness_switch (sample_size, run_times);

  printf ("\n" );

  efficiency_switch (sample_size, run_times);

// WIP
#ifdef WIP_MAIN
  TestSwitch ts;

  ts.init();

  BubleSort buble;
  InsertionSort insertion;

  ts.append(&buble);
  ts.append(&insertion);

  ts.perform_all(sample_size, run_times);
  ts.perform_for_effectiveness(sample_size, run_times);
  ts.perform_for_efficiency(sample_size, run_times);

  buble.efficiency_test(sample_size, run_times);
  insert.efficiency_test(sample_size, run_times);

  ts.end();
#endif
// END WIP

  return (EXIT_SUCCESS);
}

void parse_command_line(int argc, string argv[], 
    size_t *sample_size, unsigned int *run_times)
{
  if ( argc == 3 ) {
    if ( bad_sample_size_assignment(sample_size, atoi( argv[ 1 ])) ) {
      printf(BAD_SAMPLE_SIZE_FORMAT);
      exit(1);
    }

    if ( bad_run_times_assignment(run_times, atoi( argv[ 2 ])) ) {
      printf(BAD_RUN_TIMES_FORMAT);
      exit(2);
    }

  } else if ( argc == 2 ) {
    if ( bad_sample_size_assignment(sample_size, atoi( argv[ 1 ])) ) {
      printf(BAD_SAMPLE_SIZE_FORMAT);
      exit(1);
    }
  } else if ( argc > 2 ) {
    printf(USAGE_ERROR_MSG);
    exit(3);
  }
}

int bad_sample_size_assignment(size_t *sample_size, int value) {
  if ( value > 0 ) *sample_size = value;

  return value <= 0;
}

int bad_run_times_assignment(unsigned int *run_times, int value) {
  if ( value > 0 ) *run_times = value;

  return value <= 0;
}
