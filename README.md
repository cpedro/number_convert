# Number Convert

Standalone C program that takes number from various bases and converts them to 
other bases:
* Decimal
* Octal
* Hexadecimal
* Binary

Although the program only prints out the number in the above bases, the input
base can be any base.

This program was written mainly for a bit of practice in C, but I have used it
numerous times to convert numbers from one base to another.

## Compiling and running

```
$ gcc num_convert.c -o num_convert
$ ./num_convert 10 10
Dec:	10
Oct:	012
Hex:	0xa
Bin:	1010
$ ./num_convert 10 2
Dec:	2
Oct:	02
Hex:	0x2
Bin:	10
$ ./num_convert beef 16
Dec:	48879
Oct:	0137357
Hex:	0xbeef
Bin:	1011111011101111
$ ./num_convert 755 8
Dec:	493
Oct:	0755
Hex:	0x1ed
Bin:	111101101
$ ./num_convert 212 3
Dec:	23
Oct:	027
Hex:	0x17
Bin:	10111
```
