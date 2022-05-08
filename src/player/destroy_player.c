/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** destroy player_t
*/

#include <stdlib.h>
#include <SFML/Graphics/View.h>
#include "my_bgs_framebuffer.h"
#include "my_rpg.h"

void destroy_player(void *player_void)
{
    player_t *player = player_void;

    if (player == NULL) {
        return;
    }
    if (player->view != NULL) {
        sfView_destroy(player->view);
    }
    if (player->buf != NULL) {
        destroy_framebuffer(player->buf);
    }
    free(player);
}
