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
typedef struct var_t {
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *texture2;
    sfSprite *button;
    sfVector2f pos_boutton;
    sfTexture *floor_t;
    sfSprite *floor_s;
    sfTexture *player_t;
    sfSprite *player_s;
    int max_value;
    int offset;
    int direction;
    int current_frame;
    int x_floor;
}var;
void my_hunter(sfRenderWindow *window, sfEvent event);
void my_args(var *args);
void my_rect(sfIntRect *rect);
void window_display(sfRenderWindow *window, sfEvent event);
#endif
