#include "main.h"
#include <stdarg.h>

/**
 * print_string - prints a string without printf
 *
 * @s: the string
 * Return: the number of characters printed
 */
int print_string(char *s)
{
    int i;

    for (i = 0; s[i]; i++)
        _putchar(s[i]);
    return (i);
}

/**
 * _printf - prints
 *
 * @format: the formatter string
 * Return: the nubmer of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    unsigned long int i, printed = 0;

    va_start(args, format);
    for (i = 0; format[i]; i++)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == 'c') /* character placeholder */
                printed += _putchar(va_arg(args, int));
            else if (format[i + 1] == 's') /* string placeholder */
                printed += print_string(va_arg(args, char *));
        }
        else /* usual character */
            _putchar(format[i]);
    }
    va_end(args);

    return printed;
}
