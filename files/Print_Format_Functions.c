#include "main.h"

/**
* _printpointer - Print the value of a pointer variable
* @types: List of argument types
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed.
*/
int _printpointer(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    char extra_c = 0, padd = ' ';
    int ind = BUFFERSIZE - 2, length = 2, padd_start = 1;
    unsigned long num_addrs;
    char map_to[] = "0123456789abcdef";
    void *addrs = va_arg(types, void *);
    UNUSED(width);
    UNUSED(size);

    if (addrs == NULL)
        return (write(1, "(nil)", 5));
    
    buffer[BUFFERSIZE - 1] = '\0';
    UNUSED(precision);
    num_addrs = (unsigned long)addrs;

    while (num_addrs > 0)
    {
        buffer[ind--] = map_to[num_addrs % 16];
        num_addrs /= 16;
        length++;
    }

    if ((flags & F_ZERO) && !(flags & F_MINUS))
        padd = '0';

    if (flags & F_PLUS)
        extra_c = '+', length++;
    else if (flags & F_SPACE)
        extra_c = ' ', length++;
    
    ind++;

    return (_writepointer(buffer, ind, length, width, flags, padd, extra_c, padd_start));
}

/**
* _printnonprintable - Print ascii codes in hexa of non printable chars
* @types: Lista of argument types
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int _printnonprintable(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    int i = 0, offset = 0;
    char *str = va_arg(types, char *);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (str == NULL)
        return (write(1, "(null)", 6));

    while (str[i] != '\0')
    {
        if (_isprintable(str[i]))
            buffer[i + offset] = str[i];
        else
            offset += _appendhexadecimal(str[i], buffer, i + offset);
        i++;
    }

    buffer[i + offset] = '\0';
    return (write(1, buffer, i + offset));
}

/**
* _printreverse - Print reverse string.
* @types: List of argument types
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Numbers of chars printed
*/
int _printreverse(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    char *str;
    int i, count = 0;
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(size);
    
    str = va_arg(types, char *);
    if (str == NULL)
    {
        UNUSED(precision);
        str = ")Null(";
    }

    for (i = 0; str[i]; i++)
        ;
    
    for (i = i - 1; i >= 0; i--)
    {
        char z = str[i];
        write(1, &z, 1);
        count++;
    }
    return (count);
}

/**
* _printrot13string - Print a string in rot13.
* @types: List of argument types
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Numbers of chars printed
*/
int _printrot13string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    char x;
    char *str;
    unsigned int i, j;
    int count = 0;
    char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
    
    str = va_arg(types, char *);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (str == NULL)
        str = "(AHYY)";

    for (i = 0; str[i]; i++)
    {
        for (j = 0; in[j]; j++)
        {
            if (in[j] == str[i])
            {
                x = out[j];
                write(1, &x, 1);
                count++;
                break;
            }
        }

        if (!in[j])
        {
            x = str[i];
            write(1, &x, 1);
            count++;
        }
    } return (count);
}