/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** configure_dead_screen
*/

#include "my_bgs.h"
#include "my_bgs_components.h"
#include "my_rpg.h"

static void configure_color_for_dead_screen(object_t *dead_message,
    object_t *dead_screen)
{
    sfColor color[] = {{0, 0, 0, 0}, {0, 0, 0, 0}};

    dead_message->is_visible = false;
    dead_screen->is_visible = false;
    color[0] = sfSprite_getColor(dead_message->drawable.sprite);
    color[1] = sfSprite_getColor(dead_screen->drawable.sprite);
    color[0].a = 0;
    color[1].a = 0;
    sfSprite_setColor(dead_message->drawable.sprite, color[0]);
    sfSprite_setColor(dead_screen->drawable.sprite, color[1]);
}

int init_dead_menu(window_t *win, scene_t *scene)
{
    player_t *player = dico_t_get_value(win->components, "player");
    object_t *dead_message =
        create_object(update_dead_message, NULL, scene, -3);
    object_t *dead_screen = create_object(update_dead_screen, NULL, scene, - 3);

    if (dead_message == NULL || dead_screen == NULL || player == NULL ||
        object_set_sprite(dead_message,
        "./assets/image/menu/dead/dead_message.png",
        (sfIntRect) {0, 0, 1920, 261}, (sfVector2f) {960, 410}) != BGS_OK ||
        object_set_sprite(dead_screen,
        "./assets/image/menu/dead/dead_screen.png",
        (sfIntRect) {0, 0, 1920, 1080}, (sfVector2f) {960, 540}) != BGS_OK) {
        return RET_ERR_INPUT;
    }
    configure_color_for_dead_screen(dead_message, dead_screen);
    window_add_component(win, dead_message, "dead_message", NULL);
    window_add_component(win, dead_screen, "dead_screen", NULL);
    return RET_OK;
}
