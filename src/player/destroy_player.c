/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destroy player_t
*/

#include <stdlib.h>
#include <SFML/Graphics/View.h>
#include "my_rpg.h"

void destroy_player(void *player_void)
{
    player_t *player = player_void;
    scene_t *scene = NULL;

    if (player == NULL) {
        return;
    }
    scene = dico_t_get_value(player->obj->components, "scene");
    if (scene == NULL) {
        return;
    }
    list_add_to_end(scene->to_remove, player->obj);
    sfView_destroy(player->view);
    free(player);
}
