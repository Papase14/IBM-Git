#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFERSIZE 1024

/* DEFINING FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* DEFINING SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
* typedef struct format format_t - Struct op
* @format: The format.
* @fn: The function associated.
*/
typedef struct format
{
    char format;
    int (*fn)(va_list, char[], int, int, int, int);
} format_t;

/* MAIN PROJECT*/
int _printf(const char *format, ...);

int _handleprint(const char *format, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** PROJECT FUNCTIONS ******************/
/* Funtions to print chars and strings */
int _printchar(va_list types, char buffer[], int flags, int width, int precision, int size);
int _printstring(va_list types, char buffer[], int flags, int width, int precision, int size);
int _printpercent(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Functions to print numbers */
int _printint(va_list types, char buffer[], int flags, int width, int precision, int size);
int _printbinary(va_list types, char buffer[], int flags, int width, int precision, int size);
int _printunsignednumber(va_list types, char buffer[], int flags, int width, int precision, int size);
int _printoctal(va_list types, char buffer[], int flags, int width, int precision, int size);
int _printhexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int _printhexadecimalupper(va_list types, char buffer[], int flags, int width, int precision, int size);
int _printhexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int _printnonprintable(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Function to print memory address */
int _printpointer(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Function to handle other specifiers */
int _getflags(const char *format, int *i);
int _getwidth(const char *format, int *i, va_list list);
int _getprecision(const char *format, int *i, va_list list);
int _getsize(const char *format, int *i);

/*Function to print string in reverse*/
int _printreverse(va_list types, char buffer[], int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int _printrot13string(va_list types, char buffer[], int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[], int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision, int length, char padd, char extra_c);
int _writepointer(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start);
int _writeunsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size);

/****************** UTILS ******************/
int _isprintable(char);
int _appendhexadecimal(char, char[], int);
int _isdigit(char);
long int _convertSizeNumber(long int num, int size);
long int _convertSizeUnsgnd(unsigned long int num, int size);

#endif