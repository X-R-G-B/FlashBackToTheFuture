/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** knockback.c
*/

#include "my_rpg.h"

<<<<<<< HEAD
void knockback(object_t *obj, __attribute__((unused)) scene_t *scene,
    window_t *win, __attribute__((unused)) float time)
=======
void knockback(object_t *obj, scene_t *scene, window_t *win,
    __attribute__((unused)) float time)
>>>>>>> dev
{
    player_t *player = NULL;

    if (is_player_on_square(win, obj) == false) {
        return;
    }
    player = dico_t_get_value(win->components, "player");
    if (player == NULL) {
        return;
    }
    change_player_pos(player, 10, scene);
    sfRenderWindow_setView(win->win, player->view);
}
