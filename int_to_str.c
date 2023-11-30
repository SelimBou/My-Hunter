/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_$ACADEMIC_YEAR
** File description:
** int_to_str.c
*/

#include "hunter.h"

char *int_to_str(int num)
{
    int length = 1;
    int temp = num;
    char *str;
    int index;

    while (temp != 0) {
        temp = temp / 10;
        length++;
    }
    str = malloc(sizeof(char) * length);
    index = length - 1;
    while (num != 0) {
        index --;
        str[index] = (num % 10) + '0';
        num = num / 10;
    }
    str[length - 1] = '\0';
    return str;
}
