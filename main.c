/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myhunter-selim.bouasker
** File description:
** main.c
*/

#include "hunter.h"
static void game_display(sfRenderWindow *window, var *args)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, args->sprite, NULL);
    sfRenderWindow_drawSprite(window, args->button, NULL);
    sfRenderWindow_display(window);
}

void window_display(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

static void start_game(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed)
        my_hunter(window, event);
}

void mouse_position(sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x >= 837 && mouse.x <= 1025) {
        if (mouse.y >= 474 && mouse.y <= 525)
            start_game(window, event);
    }
}

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfEvent event;
    sfRenderWindow *window;
    sfVector2f pos_boutton = {800, 400};
    var args;

    my_args(&args);
    sfSprite_setTexture(args.sprite, args.texture, sfTrue);
    sfSprite_setTexture(args.button, args.texture2, sfTrue);
    sfSprite_setPosition(args.button, pos_boutton);
    window = sfRenderWindow_create(mode, "My hunter", sfResize | sfClose,
        NULL);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            window_display(window, event);
        game_display(window, &args);
        mouse_position(window, event);
    }
    return 0;
}
