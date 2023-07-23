#include <stdio.h>
#include <stdarg.h>

int print_string(char *s)
{
    int i;

    for (i = 0; s[i]; i++)
        putchar(s[i]);
    return i;
}

/**
 * _printf - prints
 *
 * @format: the formatter string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    unsigned long int i, printed = 0;
    char buffer[1024]; // Temporary buffer for integer to string conversion

    va_start(args, format);
    for (i = 0; format[i]; i++)
    {
        if (format[i] == '%')
        {
            i++; // Move past the '%'
            if (format[i] == '\0')
                break;

            if (format[i] == 'c')
            {
                printed += putchar(va_arg(args, int));
            }
            else if (format[i] == 's')
            {
                printed += print_string(va_arg(args, char *));
            }
            else if (format[i] == 'd' || format[i] == 'i')
            {
                sprintf(buffer, "%d", va_arg(args, int)); // Convert integer to string
                printed += print_string(buffer); // Print the string
            }
            else
            {
                putchar('%');
                putchar(format[i]);
                printed += 2;
            }
        }
        else /* usual character */
        {
            putchar(format[i]);
            printed++;
        }
    }
    va_end(args);

    return printed;
}

int main()
{
    _printf("Hello, %s! The answer is %d.\n", "John", 42);
    return 0;
}
