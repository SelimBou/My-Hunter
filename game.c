/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_$ACADEMIC_YEAR
** File description:
** game.c
*/

#include "hunter.h"

void kill_bird(sfRenderWindow *window, sfEvent event, var *args, struct2 *vars)
{
    sfVector2i mousePosition;
    sfFloatRect viseur_bounds;
    sfFloatRect bird_bounds;
    sfVector2f canard_pos;

    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft) {
        mousePosition = sfMouse_getPositionRenderWindow(window);
        viseur_bounds = sfSprite_getGlobalBounds(args->viseur_s);
        bird_bounds = sfSprite_getGlobalBounds(args->player_s);
        if (sfFloatRect_intersects(&viseur_bounds, &bird_bounds, NULL)) {
            canard_pos = (sfVector2f){-100, vars->y_canard};
            vars->x_canard = rand() % 700;
            vars->y_canard = rand() % 700;
            sfSprite_setPosition(args->player_s, canard_pos);
        }
    }
}

static void sprite_to_texture(var *args)
{
    sfVector2f scale_viseur = {0.3, 0.3};

    sfSprite_setTexture(args->floor_s, args->floor_t, sfTrue);
    sfSprite_setTexture(args->player_s, args->player_t, sfTrue);
    sfSprite_setTexture(args->viseur_s, args->viseur_t, sfTrue);
    sfSprite_setScale(args->viseur_s, scale_viseur);
}

static void viseur_mouse(sfRenderWindow *window, var *args)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f viseur_pos = {mouse_pos.x - 66, mouse_pos.y - 60};

    sfSprite_setPosition(args->viseur_s, viseur_pos);
}

void move_floor(sfRenderWindow *window, var *args, struct2 *vars)
{
    sfVector2f canard_pos = {vars->x_canard, vars->y_canard};

    vars->x_canard = vars->x_canard + 0.5;
    sfSprite_setPosition(args->player_s, canard_pos);
    if (vars->x_canard > 1920) {
        vars->y_canard = rand() % 700;
        vars->x_canard = rand() % 700;
    }
    sfRenderWindow_drawSprite(window, args->player_s, NULL);
}

void move_rect(sfIntRect *rect, var *args, struct2 *vars)
{
    sfTime time_spent = sfClock_getElapsedTime(vars->clock);

    if (sfTime_asMilliseconds(time_spent) >= 80) {
        if (rect->left >= 220) {
            rect->left = 0;
        } else {
            rect->left += 110;
        }
        sfSprite_setTextureRect(args->player_s, *rect);
        sfClock_restart(vars->clock);
    }
}

void my_hunter(sfRenderWindow *window, sfEvent event)
{
    var args;
    sfIntRect rect;
    struct2 vars = my_variables();

    my_args(&args);
    my_rect(&rect);
    sprite_to_texture(&args);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            window_display(window, event);
        move_rect(&rect, &args, &vars);
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, args.floor_s, NULL);
        move_floor(window, &args, &vars);
        sfRenderWindow_drawSprite(window, args.viseur_s, NULL);
        viseur_mouse(window, &args);
        sfRenderWindow_display(window);
        kill_bird(window, event, &args, &vars);
    }
}
