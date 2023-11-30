/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_$ACADEMIC_YEAR
** File description:
** game.c
*/

#include "hunter.h"

int win_game(mini *last)
{
    if (last->score >= 60)
        return 1;
    return 0;
}

int kill_bird(sfRenderWindow *window, sfEvent event, mini *last)
{
    check_if_shoot(window, event, last);
    return last->code_retour;
}

static void sprite_to_texture(struct2 *vars, mini *last)
{
    sfVector2f scale_viseur = {0.3, 0.3};

    sfSprite_setTexture(last->floor_s, last->floor_t, sfTrue);
    sfSprite_setTexture(last->win_s, vars->win_t, sfTrue);
    sfSprite_setTexture(last->player_s, last->player_t, sfTrue);
    sfSprite_setTexture(last->viseur_s, last->viseur_t, sfTrue);
    sfSprite_setTexture(last->viseur_s, last->viseur_t, sfTrue);
    sfSprite_setTexture(last->over_s, vars->over_t, sfTrue);
    sfSprite_setScale(last->viseur_s, scale_viseur);
}

static void sprite_to_texture3(struct2 *vars, mini *last)
{
    sfVector2f score_pos = {3, 20};
    sfVector2f myscore_pos = {320, 20};

    sfText_setFont(last->scoreText, vars->font);
    sfText_setString(last->scoreText, "Score:");
    sfText_setCharacterSize(last->scoreText, 50);
    sfText_setFillColor(last->scoreText, sfRed);
    sfText_setPosition(last->scoreText, score_pos);
    sfText_setFont(last->my_score, vars->font2);
    sfText_setString(last->my_score, "0");
    sfText_setCharacterSize(last->my_score, 50);
    sfText_setFillColor(last->my_score, sfBlack);
    sfText_setPosition(last->my_score, myscore_pos);
}

void move_floor(sfRenderWindow *window, mini *last, sfIntRect *rect)
{
    sfVector2f canard_pos = {last->x_canard, last->y_canard};

    last->x_canard = last->x_canard + 1;
    sfSprite_setPosition(last->player_s, canard_pos);
    if (last->x_canard > 1920) {
        last->cpt_life -= 1;
        last->y_canard = rand() % 700;
        last->x_canard = rand() % 700;
    }
    sfSprite_setTextureRect(last->player_s, *rect);
    sfRenderWindow_drawSprite(window, last->player_s, NULL);
}

void move_rect(sfIntRect *rect, mini *last)
{
    sfTime time_spent = sfClock_getElapsedTime(last->clock);

    if (sfTime_asMilliseconds(time_spent) >= 80) {
        if (rect->left >= 220) {
            rect->left = 0;
        } else {
            rect->left += 110;
        }
        sfSprite_setTextureRect(last->player_s, *rect);
        sfClock_restart(last->clock);
    }
}

int my_hunter(sfRenderWindow *window, sfEvent event)
{
    sfIntRect rect = my_rect();
    struct2 vars = my_variables();
    mini last = my_var();

    sprite_to_texture(&vars, &last);
    sprite_to_texture3(&vars, &last);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        cases(window, event, &rect, &last);
    }
    return 0;
}
