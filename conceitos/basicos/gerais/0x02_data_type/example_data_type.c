/*
 * Author: Jhonatan Casale (jhc)
 *
 * Contact : jhonatan@jhonatancasale.com
 *         : casale.jhon@gmail.com
 *         : https://github.com/jhonatancasale
 *         : https://twitter.com/jhonatancasale
 *         : http://jhonatancasale.github.io/
 *
 * Create date Fri  3 Mar 13:14:07 BRT 2017
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main (int argc, char **argv)
{
  // int for integers
  int i = 0;

  // float for floating point numbers
  float f = 10.0 / 3;

  // double to double precision with decimal cases
  double d = 10.0 / 3;

  // char to one single character
  char c = 'f';

  // actually what we call `strings` doesn't exist in C, but more details soon
  char str[] = "Hello, World!";

  // ok
  printf ("int(eger):%lu bytes\nvalue:%i\n\n", sizeof(i), i );

  // Notice the decimal cases
  printf ("float (point):%lu bytes\nvalue:%.32f\n\n", sizeof(f), f );
  printf ("double (precision):%lu bytes\nvalue:%.32f\n\n", sizeof(d), d );
  // without typecast
  d = 10 / 3;
  printf ("d = 10 / 3;\n");
  printf ("(10 / 3):%lu bytes\nvalue:%.32f\n", sizeof(10 / 3), d);
  // with typecast
  printf ("((double)10 / 3):%lu bytes\nvalue:%.32f\n\n", 
                      sizeof((double) 10 / 3), (double) 10 / 3);

  printf ("char(acter):%lu byte(s)\nvalue:%c\n\n", sizeof(c), c );

  // Notice the difference between size in memory e strlen
  printf ("(string = \"Hello, World!\"):%lu "
      "bytes\nvalue:%s\nlen(str): %lu\n\n", sizeof(str), str, strlen(str) );

  // 2 ** 64 = 18446744073709551616 - 1 = 18446744073709551615
  // but `error: integer constant is so large that it is unsigned [-Werror]`
  // So, assign 0xffffffffffffffff should works
  uint64_t u64 = 0xffffffffffffffff;
  printf ("uint64_t u64:%lu bytes\nvalue:%lu\n\n", sizeof(u64), u64);

  uint8_t u8 = 0xff;
  printf ("uint8 u8:%lu byte\nvalue:%u\n", sizeof(u8), u8);
  printf ("(u8 += 1):%u\n\n", u8 += 1);

  // Using char arithmetic
  printf ("A:%i, a:%i\n", 'A', 'a');

  for ( c = 'A'; c <= 'Z'; c++ ) printf("%c%c", c, c + 'a' - 'A');
  printf ("\n");

  return (EXIT_SUCCESS);
}
