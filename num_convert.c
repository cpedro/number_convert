
/*
 * num_convert.c
 *
 * Takes a number and a base from command line arguments, parses the number then
 * prints out the same number in 4 different bases, decimal, octal, hexadecimal
 * and binary.
 * 
 *
 * Command line arguments:
 *	 <number> - the number to parse.
 *   <base> - the base that number is in.
 *
 * Author: E. Chris Pedro
 * Version: 2018-03-27
 */

#include <stdlib.h>
#include <stdio.h>


/*
 * decimal_to_binary - Converts a decimal number to a binary string.  Note that
 *                     the binary number is passed back as a character string.
 * @n - the number to convert.
 */
char *decimal_to_binary(unsigned long n)
{
  int i, c, size = (sizeof(unsigned long) * 8);
  char *bin;

  bin = (char *)malloc(size + 1);
  if (bin == NULL)
    exit(EXIT_FAILURE);
 
  for (c = --size, i = 0; c >= 0; --c, ++i)
    bin[i] = ((n >> c) & 1) ? 1 + '0' : 0 + '0';
  bin[i] = '\0';
 
  return bin;
}

/*
 * print_number - Prints out the number passed as a character string in four
 *                different bases, decimal, octal, hexadecimal and binary.
 *                The number is parsed as type long, so it can read in some big
 *                numbers.
 * @str - the character string to parse and print.
 * @base - the base this number is currently in.
 */
void print_number(char *str, int base)
{
  unsigned long n;
  char *bin;

  n = strtoul(str, 0, base);
  bin = decimal_to_binary(n);

  printf("Dec:\t%lu\nOct:\t%#lo\nHex:\t%#lx\nBin:\t%s\n", n, n, n, bin);

  free(bin);
  bin = NULL;
}

/*
 * main
 */
int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    fprintf(stderr, "usage: %s <number> <base>\n", argv[0]);
    return EXIT_FAILURE;
  }

  print_number(argv[1], atoi(argv[2]));

  return EXIT_SUCCESS;
}

