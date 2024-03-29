#include "main.h"

/**
* _printchar - Prints a char
* @types: List a of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: Width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int _printchar(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    char c = va_arg(types, int);
    return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
* _printstring - Prints a string
* @types: List a of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int _printstring(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    int length = 0, i;
    char *str = va_arg(types, char *);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    
    if (str == NULL)
    {
        str = "(null)";
        if (precision >= 6)
            str = " ";
    }
    
    while (str[length] != '\0')
        length++;
    
    if (precision >= 0 && precision < length)
        length = precision;
    
    if (width > length)
    {
        if (flags & F_MINUS)
        {
            write(1, &str[0], length);
            for (i = width - length; i > 0; i--)
                write(1, " ", 1);
            return (width);
        }
        else
        {
            for (i = width - length; i > 0; i--)
                write(1, " ", 1);
            write(1, &str[0], length);
            return (width);
        }
    }
    return (write(1, str, length));
}

/**
* _printpercent - Prints a percent sign
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int _printpercent(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    UNUSED(types);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    
    return (write(1, "%%", 1));
}

/**
* _printint - Print int
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int _printint(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    int i = BUFFERSIZE - 2;
    int is_negative = 0;
    long int n = va_arg(types, long int);
    unsigned long int num;

    n = _convertSizeNumber(n, size);
    if (n == 0)
        buffer[i--] = '0';

    buffer[BUFFERSIZE - 1] = '\0';
    num = (unsigned long int)n;
    if (n < 0)
    {
        num = (unsigned long int)((-1) * n);
        is_negative = 1;
    }

    while (num > 0)
    {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    } i++;
    return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
* _printbinary - Prints an unsigned number
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: Numbers of char printed.
*/
int _printbinary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    unsigned int n, m, i, sum;
    unsigned int a[32];
    int count;
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    n = va_arg(types, unsigned int);
    m = 2147483648;
    a[0] = n / m;
    
    for (i = 1; i < 32; i++)
    {
        m /= 2;
        a[i] = (n / m) % 2;
    }

    for (i = 0, sum = 0, count = 0; i < 32; i++)
    {
        sum += a[i];
        if (sum || i == 31)
        {
            char z = '0' + a[i];
            write(1, &z, 1);
            count++;
        }
    } return (count);
}