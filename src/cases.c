/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_$ACADEMIC_YEAR
** File description:
** cases.c
*/

#include "hunter.h"

void viseur_mouse(sfRenderWindow *window, mini *last)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f viseur_pos = {mouse_pos.x - 66, mouse_pos.y - 60};

    sfSprite_setPosition(last->viseur_s, viseur_pos);
}

void cases(sfRenderWindow *window, sfEvent event, sfIntRect *rect, mini *last)
{
    if (last->code_retour == 0) {
        case_one(window, event, last, rect);
    } else if (last->code_retour == 1) {
        case_two(window, event, last);
    } else {
        case_three(window, event, last);
    }
}

void case_one(sfRenderWindow *window, sfEvent event, mini *last,
    sfIntRect *rect)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        window_display(window, event);
        last->code_retour = kill_bird(window, event, last);
    }
    last->code_retour = lose_game(window, last);
    if (last->code_retour == 0)
        last->code_retour = win_game(last);
    move_rect(rect, last);
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, last->floor_s, NULL);
    move_floor(window, last, rect);
    sfRenderWindow_drawSprite(window, last->viseur_s, NULL);
    sfRenderWindow_drawText(window, last->scoreText, NULL);
    sfRenderWindow_drawText(window, last->my_score, NULL);
    viseur_mouse(window, last);
    sfRenderWindow_display(window);
}

void case_two(sfRenderWindow *window, sfEvent event, mini *last)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
            last->my_score = 0;
            my_hunter(window, event);
        }
    }
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, last->win_s, NULL);
    sfRenderWindow_display(window);
}

void case_three(sfRenderWindow *window, sfEvent event, mini *last)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        window_display(window, event);
        if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
            last->my_score = 0;
            my_hunter(window, event);
        }
    }
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, last->over_s, NULL);
    sfRenderWindow_display(window);
}
