/*
** EPITECH PROJECT, 2023
** B-MUL-100-MAR-1-1-myhunter-selim.bouasker
** File description:
** main.c
*/

#include "hunter.h"

int game_description(char **argv)
{
    if (argv[1][1] == 'h') {
        my_printf("Duck Hunt est un jeu classique de tir aux canards sorti");
        my_printf(" en 1984 pour la NES. Les joueurs utilisent le pistolet");
        my_printf(" NES Zapper pour abattre");
        my_printf(" des canards volants. Le jeu propose des modes de tir aux");
        my_printf(" canards et de tir aux");
        my_printf(" pigeons d'argile. Le défi augmente avec la vitesse");
        my_printf(" et l'angle des canards.");
        my_printf(" Le jeu est célèbre pour son utilisation novatrice");
        my_printf(" du pistolet et sa nostalgie associée à la NES.\n");
    }
}

static int start_game2(sfRenderWindow *window, sfEvent event, var *args)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x >= 1722 && mouse.x <= 1972) {
        if (mouse.y >= 0 && mouse.y <= 100)
            return 1;
    }
    return 0;
}

static void sprite_to_texture1(var *args)
{
    sfVector2f pos_boutton = {800, 400};
    sfVector2f pos_rule = {800, 550};

    sfSprite_setTexture(args->sprite, args->texture, sfTrue);
    sfSprite_setTexture(args->button, args->texture2, sfTrue);
    sfSprite_setPosition(args->button, pos_boutton);
    sfSprite_setTexture(args->back2_s, args->back2_t, sfTrue);
    sfSprite_setTexture(args->leave_s, args->leave_t, sfTrue);
    sfSprite_setTexture(args->rules_s, args->rules_t, sfTrue);
    sfSprite_setPosition(args->rules_s, pos_rule);
}

void destroy_all(sfRenderWindow *window, var *args)
{
    sfSprite_destroy(args->sprite);
    sfTexture_destroy(args->texture);
    sfSprite_destroy(args->button);
    sfTexture_destroy(args->texture2);
    sfSprite_destroy(args->floor_s);
    sfTexture_destroy(args->floor_t);
    sfSprite_destroy(args->back2_s);
    sfTexture_destroy(args->back2_t);
    sfSprite_destroy(args->player_s);
    sfTexture_destroy(args->player_t);
    sfSprite_destroy(args->viseur_s);
    sfTexture_destroy(args->viseur_t);
    sfSprite_destroy(args->rules_s);
    sfTexture_destroy(args->rules_t);
    sfRenderWindow_destroy(window);
}

static void rule_display(sfRenderWindow *window, var *args, sfEvent event)
{
    int code_retour = 0;
    sfVector2f leave_pos = {1722, 0};

    sfSprite_setPosition(args->leave_s, leave_pos);
    while (sfRenderWindow_isOpen(window) && code_retour == 0) {
        while (sfRenderWindow_pollEvent(window, &event))
            window_display(window, event);
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, args->back2_s, NULL);
        sfRenderWindow_drawSprite(window, args->leave_s, NULL);
        if (event.type == sfEvtMouseButtonPressed) {
            code_retour = start_game2(window, event, args);
        }
        sfRenderWindow_display(window);
    }
}

static void game_display(sfRenderWindow *window, var *args)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, args->sprite, NULL);
    sfRenderWindow_drawSprite(window, args->button, NULL);
    sfRenderWindow_drawSprite(window, args->rules_s, NULL);
    sfRenderWindow_display(window);
}

void window_display(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

static void start_game(sfRenderWindow *window, sfEvent event, var *args)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x >= 837 && mouse.x <= 1025) {
        if (mouse.y >= 474 && mouse.y <= 525)
            my_hunter(window, event);
    }
    if (mouse.x >= 766 && mouse.x <= 1027) {
        if (mouse.y >= 540 && mouse.y <= 590)
            rule_display(window, args, event);
    }
}

void mouse_position(sfRenderWindow *window, sfEvent event, var *args)
{
    if (event.type == sfEvtMouseButtonPressed)
        start_game(window, event, args);
}

int main(int argc, char **argv)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfEvent event;
    sfRenderWindow *window;
    var args = my_args();

    if (argc == 2 && argv[1][0] == '-') {
        game_description(argv);
        return 0;
    }
    sprite_to_texture1(&args);
    window = sfRenderWindow_create(mode, "MyHunter", sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            window_display(window, event);
        game_display(window, &args);
        mouse_position(window, event, &args);
    }
    destroy_all(window, &args);
    return 0;
}
