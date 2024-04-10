/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_$ACADEMIC_YEAR
** File description:
** my_args.c
*/

#include "hunter.h"

int lose_game(sfRenderWindow *window, mini *last)
{
    if (last->cpt_life == 0)
        return 2;
    return 0;
}

struct2 my_variables(void)
{
    struct2 vars;

    vars.leave_t = sfTexture_createFromFile("pics/leave.png", NULL);
    vars.leave_s = sfSprite_create();
    vars.over_t = sfTexture_createFromFile("pics/over.png", NULL);
    vars.win_t = sfTexture_createFromFile("pics/win.png", NULL);
    vars.font =
        sfFont_createFromFile("./Press_Start_2P/PressStart2P-Regular.ttf");
    vars.font2 =
        sfFont_createFromFile("./Press_Start_2P/PressStart2P-Regular.ttf");
    return vars;
}

var my_args(void)
{
    var args;

    args.texture = sfTexture_createFromFile("pics/fond.jpg", NULL);
    args.sprite = sfSprite_create();
    args.texture2 = sfTexture_createFromFile("pics/start.png", NULL);
    args.button = sfSprite_create();
    args.rules_t = sfTexture_createFromFile("pics/rule.png", NULL);
    args.rules_s = sfSprite_create();
    args.back2_t = sfTexture_createFromFile("pics/rule1.png", NULL);
    args.back2_s = sfSprite_create();
    args.floor_t1 = sfTexture_createFromFile("pics/back.png", NULL);
    args.floor_s1 = sfSprite_create();
    return args;
}

sfIntRect my_rect(void)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = 110;
    rect.height = 110;
    return rect;
}

mini my_var(void)
{
    mini last;

    last.over_s = sfSprite_create();
    last.win_s = sfSprite_create();
    last.scoreText = sfText_create();
    last.floor_t = sfTexture_createFromFile("pics/back.png", NULL);
    last.floor_s = sfSprite_create();
    last.viseur_t = sfTexture_createFromFile("pics/viseur.png", NULL);
    last.viseur_s = sfSprite_create();
    last.player_t = sfTexture_createFromFile("pics/duck.png", NULL);
    last.player_s = sfSprite_create();
    last.clock = sfClock_create();
    last.my_score = sfText_create();
    last.score = 0;
    last.code_retour = 0;
    last.sco = int_to_str(last.score);
    last.x_canard = rand() % 300;
    last.y_canard = rand() % 300;
    last.cpt_life = 3;
    return last;
}
