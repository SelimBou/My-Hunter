/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myhunter-selim.bouasker
** File description:
** hunter.h
*/
#ifndef HUNTER_H
    #define HUNTER_H
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <math.h>
typedef struct var_t {
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *texture2;
    sfSprite *button;
    sfTexture *rules_t;
    sfSprite *rules_s;
    sfTexture *back2_t;
    sfSprite *back2_s;
    sfTexture *floor_t;
    sfSprite *floor_s;
    sfTexture *floor_t1;
    sfSprite *floor_s1;
    sfTexture *player_t;
    sfSprite *player_s;
    sfTexture *viseur_t;
    sfSprite *viseur_s;
    sfTexture *leave_t;
    sfSprite *leave_s;
}var;
typedef struct struct2 {
    int max_value;
    int offset;
    int current_frame;
    float x_canard;
    float y_canard;
    sfClock *clock;
} struct2;

void my_hunter(sfRenderWindow *window, sfEvent event);
struct2 my_variables(void);
void my_args(var *args);
void my_rect(sfIntRect *rect);
void window_display(sfRenderWindow *window, sfEvent event);
#endif
