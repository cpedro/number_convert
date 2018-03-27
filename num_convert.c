
/*
 * num_convert.c
 *
 * Takes a number and a base from command line arguments, parses the number then
 * prints out the same number in 4 different bases, decimal, octal, hexadecimal
 * and binary.
 * 
 *
 * Command line arguments:
 *   <number> - the number to parse.
 *   <base> - the base that number is in.
 *
 * Author: E. Chris Pedro
 * Version: 2018-03-27
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*
 * decimal_to_binary - Converts a decimal number to a binary string.  Note that
 *                     the binary number is passed back as a character string.
 *                     This function calls malloc to allocate memory for the
 *                     string that is returned.
 * @n - the number to convert.
 * Return the binary string of the number n.
 */
char *decimal_to_binary(unsigned long n)
{
  int i, c, size = (sizeof(unsigned long) * 8);
  char *bin;
  
  bin = (char *)malloc(size + 1);
  if (bin == NULL)
    exit(EXIT_FAILURE);
 
  for (c = --size, i = 0; c >= 0; --c, ++i)
    bin[i] = ((n >> c) & 1) ? '1' : '0';
  bin[i] = '\0';
 
  return bin;
}

/*
 * strip_leading_zeros - strips leading zeros from a character string of binary
 *                       digits.  Function asumes that the string is binary
 *                       digits only, and is properly null terminated.
 *                       This function calls malloc to allocate memory for the
 *                       string that is returned.
 * @str - the binary text string to stip.
 * @len - the length of the string.
 * Return the same binary string with all leading zeros stripped off.
 */
char *strip_leading_zeros(char *str, int len)
{
  int i, j;
  char *new_str;
  
  /* find index of first 1, if it exists */
  for (i = 0; i < len && str[i] != '\0'; ++i)
    if (str[i] == '1')
      break;
  
  /* case for no leading zeros */
  if (str[i] == '\0')
  {
    new_str = (char *)malloc(2);
    strncpy(new_str, "0", 1);
    
    return new_str;
  }
  
  /* copy remaining characters from str to new_str */
  new_str = (char *)malloc(len - i);
  for (j = 0; i < len; ++i, ++j)
    new_str[j] = str[i];
  
  return new_str;
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
  char *bin, *bin_s;
  int len = (sizeof(unsigned long) * 8) + 1;

  n = strtoul(str, 0, base);
  bin = decimal_to_binary(n);
  bin_s = strip_leading_zeros(bin, len);

  printf("Dec:\t%lu\nOct:\t%#lo\nHex:\t%#lx\nBin:\t%s\n", n, n, n, bin_s);

  free(bin);
  free(bin_s);
  bin_s = NULL;
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

