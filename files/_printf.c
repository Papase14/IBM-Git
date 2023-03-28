#include "main.h"

void _printbuffer(char buffer[], int *bufferindex);
/**
* _printf - Printf function
* @format: format.
* Return: Printed chars.
*/
int _printf(const char *format, ...)
{
    int i, printed = 0, printed_chars = 0, flags, width, precision, size, bufferindex = 0;
    va_list list;
    char buffer[BUFFERSIZE];

    if (format == NULL)
        return (-1);

    va_start(list, format);
    for (i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[bufferindex++] = format[i];
            if (bufferindex == BUFFERSIZE)
                _printbuffer(buffer, &bufferindex);
            printed_chars++;
        }
        else
        {
            _printbuffer(buffer, &bufferindex);
            flags = _getflags(format, &i);
            width = _getwidth(format, &i, list);
            precision = _getprecision(format, &i, list);
            size = _getsize(format, &i);
            ++i;
            printed = _handleprint(format, &i, list, buffer, flags, width, precision, size);
            if (printed == -1)
                return (-1);
            printed_chars += printed;
        }
    }
    _printbuffer(buffer, &bufferindex);
    va_end(list);
    return (printed_chars);
}

/**
* _printbuffer - Prints the contents of the buffer if it exist
* @buffer: Array of chars
* @bufferindex: Index at which to add next char, represents the length.
*/
void _printbuffer(char buffer[], int *bufferindex)
{
    if (*bufferindex > 0)
    write(1, &buffer[0], *bufferindex);
    *bufferindex = 0;
}