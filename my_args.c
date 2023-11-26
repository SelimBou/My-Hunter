/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_$ACADEMIC_YEAR
** File description:
** my_args.c
*/

#include "hunter.h"

void my_args(var *args)
{
    args->texture = sfTexture_createFromFile("fond.jpg", NULL);
    args->sprite = sfSprite_create();
    args->texture2 = sfTexture_createFromFile("start.png", NULL);
    args->button = sfSprite_create();
    args->floor_t = sfTexture_createFromFile("back.png", NULL);
    args->floor_s = sfSprite_create();
    args->player_t = sfTexture_createFromFile("duck.png", NULL);
    args->player_s = sfSprite_create();
    args->max_value = 1920;
    args->offset = 5;
    args->direction = 1;
    args->current_frame = 0;
    args->x_floor = 0;
}

void my_rect(sfIntRect *rect)
{
    rect->top = 0;
    rect->left = 0;
    rect->width = 110;
    rect->height = 110;
}
