#include "main.h"

/**
* _printunsignednumber - Prints an unsigned number
* @types: List a of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed.
*/
int _printunsignednumber(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    int i = BUFFERSIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);

    num = _convertSizeUnsgnd(num, size);
    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFFERSIZE - 1] = '\0';
    while (num > 0)
    {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    } i++;
    return (_writeunsgnd(0, i, buffer, flags, width, precision, size));
}

/**
* _printoctal - Prints an unsigned number in octal notation
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int _printoctal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    int i = BUFFERSIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;
    UNUSED(width);

    num = _convertSizeUnsgnd(num, size);
    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFFERSIZE - 1] = '\0';
    while (num > 0)
    {
        buffer[i--] = (num % 8) + '0';
        num /= 8;
    }

    if (flags & F_HASH && init_num != 0)
        buffer[i--] = '0';

    i++;
    return (_writeunsgnd(0, i, buffer, flags, width, precision, size));
}

/**
* _printhexadecimal - Prints an unsigned number in hexadecimal notation
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int _printhexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    return (_printhexa(types, "0123456789abcdef", buffer, flags, 'x', width, precision, size));
}

/**
* _printhexadecimalupper - Prints an unsigned number in upper hexadecimal notation
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int _printhexadecimalupper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    return (_printhexa(types, "0123456789ABCDEF", buffer, flags, 'X', width, precision, size));
}

/**
* _printhexa - Prints a hexadecimal number in lower or upper
* @types: Lista of arguments
* @map_to: Array of values to map the number to
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @flag_ch: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* @size: Size specification
* Return: Number of chars printed
*/
int _printhexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size)
{
    int i = BUFFERSIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;
    UNUSED(width);

    num = _convertSizeUnsgnd(num, size);
    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFFERSIZE - 1] = '\0';
    while (num > 0)
    {
        buffer[i--] = map_to[num % 16];
        num /= 16;
    }

    if (flags & F_HASH && init_num != 0)
    {
        buffer[i--] = flag_ch;
        buffer[i--] = '0';
    } i++;
    return (_writeunsgnd(0, i, buffer, flags, width, precision, size));
}