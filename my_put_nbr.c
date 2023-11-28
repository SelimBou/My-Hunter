/*
** EPITECH PROJECT, 2023
** cpoolday03
** File description:
** Infos
*/
#include "hunter.h"

int my_put_nbr(int nb)
{
    if (nb == 0) {
        my_putchar('0');
    } else {
        my_put_nbr_recursive(nb);
    }
    return 0;
}
