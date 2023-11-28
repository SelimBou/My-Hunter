/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_$ACADEMIC_YEAR
** File description:
** my_args.c
*/

#include "hunter.h"

struct2 my_variables(void)
{
    struct2 vars;

    vars.max_value = 1920;
    vars.offset = 40;
    vars.current_frame = 0;
    vars.x_canard = rand() % 300;
    vars.y_canard = rand() % 300;
    vars.clock = sfClock_create();
    return vars;
}

void my_args(var *args)
{
    args->texture = sfTexture_createFromFile("fond.jpg", NULL);
    args->sprite = sfSprite_create();
    args->texture2 = sfTexture_createFromFile("start.png", NULL);
    args->button = sfSprite_create();
    args->rules_t = sfTexture_createFromFile("rule.png", NULL);
    args->rules_s = sfSprite_create();
    args->back2_t = sfTexture_createFromFile("rule1.png", NULL);
    args->back2_s = sfSprite_create();
    args->floor_t = sfTexture_createFromFile("back.png", NULL);
    args->floor_s = sfSprite_create();
    args->floor_t1 = sfTexture_createFromFile("back.png", NULL);
    args->floor_s1 = sfSprite_create();
    args->player_t = sfTexture_createFromFile("duck.png", NULL);
    args->player_s = sfSprite_create();
    args->viseur_t = sfTexture_createFromFile("viseur.png", NULL);
    args->viseur_s = sfSprite_create();
    args->leave_t = sfTexture_createFromFile("leave.png", NULL);
    args->leave_s = sfSprite_create();
}

void my_rect(sfIntRect *rect)
{
    rect->top = 0;
    rect->left = 0;
    rect->width = 110;
    rect->height = 110;
}
