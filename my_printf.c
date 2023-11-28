/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Infos
*/
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "hunter.h"

int verify_printf(char ltr, va_list args)
{
    int result = 0;
    char *str;
    char cara;
    int nb;

    if (ltr == 's') {
        str = va_arg(args, char *);
        my_putstr(str);
    }
    if (ltr == 'c') {
        cara = va_arg(args, int);
        my_putchar(cara);
    }
    if (ltr == 'd' || ltr == 'i') {
        nb = va_arg(args, int);
        my_put_nbr(nb);
    }
    return result;
}

int my_printf(const char *format, ...)
{
    int result = 0;
    va_list args;

    va_start(args, format);
    while (*format != '\0') {
        if (*format == '%') {
            verify_printf(*++format, args);
        } else {
            result += write(1, format, 1);
        }
        ++format;
    }
    va_end(args);
    return result;
}
