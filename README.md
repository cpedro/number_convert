Number Convert
==============

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

Compiling and running
=====================
```
$ gcc num_convert.c -o num_convert
 > ./num_convert 10 10
Dec:	10
Oct:	012
Hex:	0xa
Bin:	0000000000000000000000000000000000000000000000000000000000001010
$ ./num_convert 10 2
Dec:	2
Oct:	02
Hex:	0x2
Bin:	0000000000000000000000000000000000000000000000000000000000000010
$ ./num_convert beef 16
Dec:	48879
Oct:	0137357
Hex:	0xbeef
Bin:	0000000000000000000000000000000000000000000000001011111011101111
$ ./num_convert 755 8
Dec:	493
Oct:	0755
Hex:	0x1ed
Bin:	0000000000000000000000000000000000000000000000000000000111101101
$ ./num_convert 221 3
Dec:	25
Oct:	031
Hex:	0x19
Bin:	0000000000000000000000000000000000000000000000000000000000011001
```
