/*
 * Author: Jhonatan Casale (jhc)
 *
 * Contact : jhonatan@jhonatancasale.com
 *         : casale.jhon@gmail.com
 *         : https://github.com/jhonatancasale
 *         : https://twitter.com/jhonatancasale
 *         : http://jhonatancasale.github.io/
 *
 * Create date Tue 28 Feb 01:30:43 BRT 2017
 *
 */

#include <perform_test.h>

#define SIZE 2048

void random_int_init(void) {
  static int already_run = 0;

  if ( !already_run ) {
    already_run = 1;
    srand(time(NULL));
  }
}

void memomy_allocation_failure_routine(void) {
  fprintf ( stderr, "Memory allocation failed at [%s]\n", __FILE__);
  exit(-1);
}

void memomy_deallocation_failure_routine(void) {
  fprintf ( stderr, "Memory deallocation failed at [%s]\n", __FILE__);
  exit(-1);
}

int effectiveness_test ( 
    int *(*sort_algorithm)(int *a, const size_t size,
                    int (*cmp)(const void *a, const void *b)),
    int (*cmp)(const void *a, const void *b),
    size_t nmemb, 
    unsigned int ntimes
)
{
  int failures = 0;

  for ( int i = 0; i < ntimes; i++ ) 
  {
    int * sample = get_sample(nmemb);

    if ( sample == NULL ) memomy_allocation_failure_routine();

#ifdef SHOWCASES
    vprintl( sample, nmemb );
#endif

    sort_algorithm(sample, nmemb, cmp);

#ifdef SHOWCASES
    vprintl( sample, nmemb );
#endif

    if ( !assert_sorted(sample, nmemb, cmp) ) failures++;

    sample = give_back_sample(&sample);
    if ( sample != NULL ) memomy_deallocation_failure_routine();
  }

  return failures;
}

/**
 * Return a random int number in [shift, range -1]
 */
int get_random_int(int range, int shift) {
  random_int_init();

  return ( rand() % range ) + shift;
}

void vprintl(int *v, size_t size) {
  printf ("[");
  for (int i = 0; i < size; i++)
    printf ("%i%s", v[ i ], (i != size -1) ? ", " : "]\n" );
}

int * fill_with_random_integers(int *values, const size_t nmemb) {
  for (int i = 0; i < nmemb; i++) values[i] = get_random_int(100, 0);

  return values;
}

int ascending(const void *a, const void *b) { 
  return *(int *)a - *(int *)b; 
}

int descending(const void *a, const void *b) { 
  return *(int *)b - *(int *)a; 
}

int * get_sample(size_t nmemb) {
  int * sample = (int *)malloc(sizeof(int) * nmemb);
  if ( sample != NULL)
    fill_with_random_integers(sample, nmemb);
  return sample;
}

int * give_back_sample(int **sample) {
  if (*sample != NULL ) free( *sample);
  *sample = NULL;
  return *sample;
}

int assert_sorted(int *values, size_t nmemb,
    int (*cmp)(const void *a, const void *b) )
{
  for ( int i = 0; i < nmemb - 1; i++ )
    if ( cmp((const void *)&values[i], (const void *)&values[i + 1]) > 0 ) return 0;
  return 1;
}

void print_line(size_t length)
{
  static size_t last_length = 0;

  if ( length != - 1 ) last_length = length;

  if ( length == -1 ) length = last_length;

  if ( length > 0 ) {
    for ( int i = 0; i < length - 1; i++ ) printf("-");

    printf("\n");
  }
}

inline void show_test_greeting_msg
      (const string test_purpose, const size_t sample_size, 
       const unsigned int run_times)
{
  size_t length = printf("Beginning tests for %s with %u sample sets "
      "with %lu elements each\n", test_purpose, run_times, sample_size);

  print_line(length);
  printf("\n");
}

inline void show_test_end_msg(const string test_purpose) {
  printf("\n");

  printf("End of tests for %s\n", test_purpose);

  print_line(-1);
}

void effectiveness_switch( size_t sample_size, unsigned int run_times)
{
  show_test_greeting_msg("effectiveness", sample_size, run_times);

  test_case (
      effectiveness_test ( bubble_sort, ascending, sample_size, run_times),
      run_times, "Bubble Sort", SUCCESS_PROPORTION
  );

  test_case (
      effectiveness_test ( insertion_sort, ascending, sample_size, run_times),
      run_times, "Insertion Sort", SUCCESS_PROPORTION
  );

  show_test_end_msg("effectiveness");
}

void efficiency_switch( size_t sample_size, unsigned int run_times)
{
  show_test_greeting_msg("efficiency", sample_size, run_times);
  show_test_end_msg("efficiency");
}

void test_case ( unsigned int failures, 
    unsigned int run_times, string function_name, int verbose_mode) {

  if ( verbose_mode ) printf("%s [%u Success / %u Tests]::%.2f%% Effective\n", 
      function_name, run_times - failures, run_times, 
        (double)(run_times - failures) * 100 / run_times);
  else if ( failures ) fprintf ( stderr, 
      "%s [Failures::%u]\n", function_name, failures );
}
