/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_$ACADEMIC_YEAR
** File description:
** return.c
*/

#include "hunter.h"

static void destroy_all2(sfRenderWindow *window, struct2 *vars, mini *last)
{
    sfSprite_destroy(last->win_s);
    sfTexture_destroy(vars->win_t);
    sfSprite_destroy(last->over_s);
    sfTexture_destroy(vars->over_t);
}

int check_if_shoot2(sfRenderWindow *window, sfEvent event, mini *last)
{
    sfVector2i mousePosition;
    sfFloatRect viseur_bounds;
    sfFloatRect bird_bounds;
    sfVector2f canard_pos;

    mousePosition = sfMouse_getPositionRenderWindow(window);
    viseur_bounds = sfSprite_getGlobalBounds(last->viseur_s);
    bird_bounds = sfSprite_getGlobalBounds(last->player_s);
    if (sfFloatRect_intersects(&viseur_bounds, &bird_bounds, NULL)) {
        canard_pos = (sfVector2f){-100, last->y_canard};
        last->x_canard = rand() % 700;
        last->y_canard = rand() % 700;
        last->score += 5;
        last->sco = int_to_str(last->score);
        last->code_retour = win_game(last);
        sfText_setString(last->my_score, last->sco);
        sfSprite_setPosition(last->player_s, canard_pos);
    }
}

int check_if_shoot(sfRenderWindow *window, sfEvent event, mini *last)
{
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft)
        check_if_shoot2(window, event, last);
}

int my_menu(sfRenderWindow *window, sfEvent event, var *args, struct2 *vars)
{
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            window_display(window, event);
        game_display(window, args);
        mouse_position(window, event, args, vars);
    }
}

void destroy_all(sfRenderWindow *window, var *args, struct2 *vars, mini *last)
{
    sfSprite_destroy(args->sprite);
    sfTexture_destroy(args->texture);
    sfSprite_destroy(args->button);
    sfTexture_destroy(args->texture2);
    sfSprite_destroy(last->floor_s);
    sfTexture_destroy(last->floor_t);
    sfSprite_destroy(args->back2_s);
    sfTexture_destroy(args->back2_t);
    sfSprite_destroy(last->player_s);
    sfTexture_destroy(last->player_t);
    sfSprite_destroy(last->viseur_s);
    sfTexture_destroy(last->viseur_t);
    sfSprite_destroy(args->rules_s);
    sfTexture_destroy(args->rules_t);
    sfSprite_destroy(vars->leave_s);
    sfTexture_destroy(vars->leave_t);
    sfRenderWindow_destroy(window);
    destroy_all2(window, vars, last);
}

void sprite_to_texture1(var *args, struct2 *vars)
{
    sfVector2f pos_boutton = {800, 400};
    sfVector2f pos_rule = {800, 550};

    sfSprite_setTexture(args->sprite, args->texture, sfTrue);
    sfSprite_setTexture(args->button, args->texture2, sfTrue);
    sfSprite_setPosition(args->button, pos_boutton);
    sfSprite_setTexture(args->back2_s, args->back2_t, sfTrue);
    sfSprite_setTexture(vars->leave_s, vars->leave_t, sfTrue);
    sfSprite_setTexture(args->rules_s, args->rules_t, sfTrue);
    sfSprite_setPosition(args->rules_s, pos_rule);
}
