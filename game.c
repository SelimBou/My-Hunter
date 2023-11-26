/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_$ACADEMIC_YEAR
** File description:
** game.c
*/

#include "hunter.h"

void move_rect(sfIntRect *rect, var *args)
{
    int tot_frame = 3;

    if (args->current_frame < tot_frame - 1) {
        (args->current_frame)++;
    } else {
        args->current_frame = 0;
    }
    rect->left += args->offset;
    if (rect->left >= args->max_value) {
        rect->left = 0;
    }
    rect->left = args->current_frame * rect->width;
}

void my_hunter(sfRenderWindow *window, sfEvent event)
{
    var args;
    sfIntRect rect;

    my_args(&args);
    my_rect(&rect);
    sfSprite_setTexture(args.floor_s, args.floor_t, sfTrue);
    sfSprite_setTexture(args.player_s, args.player_t, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            window_display(window, event);
        move_rect(&rect, &args);
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, args.floor_s, NULL);
        sfSprite_setTextureRect(args.player_s, rect);
        sfRenderWindow_drawSprite(window, args.player_s, NULL);
        sfRenderWindow_display(window);
    }
}
