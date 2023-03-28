#include "main.h"

/**
* _isprintable - Evaluates if a char is printable
* @c: Char to be evaluated.
* Return: 1 if c is printable, 0 otherwise
*/
int _isprintable(char c)
{
    if (c >= 32 && c < 127)
        return (1);
    return (0);
}

/**
* _appendhexadecimal - Append ascci in hexadecimal code to buffer
* @buffer: Array of chars.
* @i: Index at which to start appending.
* @ascii_code: ASSCI CODE.
* Return: Always 3
*/
int _appendhexadecimal(char ascii_code, char buffer[], int i)
{
    char map_to[] = "0123456789ABCDEF";

    if (ascii_code < 0)
        ascii_code *= -1;
    
    buffer[i++] = '\\';
    buffer[i++] = 'x';
    buffer[i++] = map_to[ascii_code / 16];
    buffer[i] = map_to[ascii_code % 16];
    return (3);
}

/**
* _isdigit - Verifies if a char is a digit
* @c: Char to be evaluated
* Return: 1 if c is a digit, 0 otherwise
*/
int _isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

/**
* _convertSizeNumber - Casts a number to the specified size
* @num: Number to be casted.
* @size: Number indicating the type to be casted.
* Return: Casted value of num
*/
long int _convertSizeNumber(long int num, int size)
{
    if (size == S_LONG)
        return (num);
    else if (size == S_SHORT)
        return ((short)num);
    return ((int)num);
}

/**
* _convertSizeUnsgnd - Casts a number to the specified size
* @num: Number to be casted
* @size: Number indicating the type to be casted
* Return: Casted value of num
*/
long int _convertSizeUnsgnd(unsigned long int num, int size)
{
    if (size == S_LONG)
        return (num);
    else if (size == S_SHORT)
        return ((unsigned short)num);
    return ((unsigned int)num);
}