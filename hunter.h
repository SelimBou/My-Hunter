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
    sfTexture *floor_t1;
    sfSprite *floor_s1;
}var;
typedef struct struct2 {
    sfTexture *leave_t;
    sfSprite *leave_s;
    sfTexture *over_t;
    sfTexture *win_t;
    sfFont *font;
    sfFont *font2;

} struct2;
typedef struct mini_s {
    sfSprite *win_s;
    sfSprite *over_s;
    sfText *scoreText;
    sfTexture *floor_t;
    sfSprite *floor_s;
    sfTexture *viseur_t;
    sfSprite *viseur_s;
    sfTexture *player_t;
    sfSprite *player_s;
    sfClock *clock;
    sfText *my_score;
    float x_canard;
    float y_canard;
    int cpt_life;
    int score;
    int code_retour;
    char *sco;
} mini;
int check_if_shoot2(sfRenderWindow *window, sfEvent event, mini *last);
int my_hunter(sfRenderWindow *window, sfEvent event);
void sprite_to_texture1(var *args, struct2 *vars);
int check_if_shoot(sfRenderWindow *window, sfEvent event, mini *last);
void cases(sfRenderWindow *window, sfEvent event, sfIntRect *rect, mini *last);
struct2 my_variables(void);
var my_args(void);
void move_rect(sfIntRect *rect, mini *last);
void move_floor(sfRenderWindow *window, mini *last, sfIntRect *rect);
sfIntRect my_rect(void);
int str_to_int(char *str);
void window_display(sfRenderWindow *window, sfEvent event);
char *int_to_str(int num);
int my_put_nbr(int nb);
int my_putstr(char *str);
int my_put_nbr_recursive(int nb);
char my_putchar(char c);
int my_printf(const char *format, ...);
void game_display(sfRenderWindow *window, var *args);
void mouse_position(sfRenderWindow *window, sfEvent event, var *args,
    struct2 *vars);
int my_menu(sfRenderWindow *window, sfEvent event, var *args,
    struct2 *vars);
void destroy_all(sfRenderWindow *window, var *args, struct2 *vars, mini *last);
void case_one(sfRenderWindow *window, sfEvent event, mini *last,
    sfIntRect *rect);
void case_two(sfRenderWindow *window, sfEvent event, mini *last);
void case_three(sfRenderWindow *window, sfEvent event, mini *last);
int win_game(mini *last);
void viseur_mouse(sfRenderWindow *window, mini *last);
int kill_bird(sfRenderWindow *window, sfEvent event, mini *last);
int lose_game(sfRenderWindow *window, mini *last);
mini my_var(void);
#endif
