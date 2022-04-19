/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** init_plaer_view
*/

#include "my_bgs.h"
#include "my_rpg.h"

sfView *create_view(window_t *win, player_t *player, int *spawn)
{
    sfView *view = sfView_create();

    if (view == NULL) {
        return (NULL);
    }
    sfView_setCenter(view, (sfVector2f) {spawn[0], spawn[1]});
    sfView_setSize(view, (sfVector2f) {WIN_SIZE_X, WIN_SIZE_Y});
    sfRenderWindow_setView(win->win, view);
    player->view = view;
    return (view);
}
