#include "main.h"

/**
* _handleprint - Prints an argument based on its type
* @format: Formatted string in which to print the arguments.
* @list: List of arguments to be printed.
* @ind: ind.
* @buffer: Buffer array to handle print.
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: 1 or 2;
*/
int _handleprint(const char *format, int *ind, va_list list, char buffer[], int flags, int width, int precision, int size)
{
    int i, len = 0, printed_chars = -1;
    format_t formatTypes[] = 
    {
        {'c', _printchar}, {'s', _printstring}, {'%', _printpercent},
        {'i', _printint}, {'d', _printint}, {'b', _printbinary},
        {'u', _printunsignednumber}, {'o', _printoctal}, {'x', _printhexadecimal},
        {'X', _printhexadecimalupper}, {'p', _printpointer}, {'S', _printnonprintable},
        {'r', _printreverse}, {'R', _printrot13string}, {'\0', NULL}
    };

    for (i = 0; formatTypes[i].format != '\0'; i++)
        if (format[*ind] == formatTypes[i].format)
            return (formatTypes[i].fn(list, buffer, flags, width, precision, size));

    if (formatTypes[i].format == '\0')
    {
        if (format[*ind] == '\0')
            return (-1);

        len += write(1, "%%", 1);
        if (format[*ind - 1] == ' ')
            len += write(1, " ", 1);
        else if (width)
        {
            --(*ind);
            while (format[*ind] != ' ' && format[*ind] != '%')
                --(*ind);

            if (format[*ind] == ' ')
                --(*ind);
            return (1);
        }
        len += write(1, &format[*ind], 1);
        return (len);
    } return (printed_chars);
}