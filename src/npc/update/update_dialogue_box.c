/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** update dialog box
*/

#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_bgs.h"
#include "my_dico.h"
#include "my_rpg.h"
#include "my_strings.h"
#include "npc.h"

static void set_new_text(dialog_manager_t *dialog, text_dialog_t *text,
    window_t *win)
{
    player_t *player = NULL;

    if (win == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (dialog->text == NULL || dialog->text != text->str) {
        dialog->text = text->str;
    }
    if (player != NULL && text->need_pause == true) {
        player->state = IN_POP_UP;
    }
}

static void update_position(object_t *obj, window_t *win)
{
    const sfView *view = NULL;
    sfVector2f center = {0};

    if (win == NULL) {
        return;
    }
    view = sfRenderWindow_getView(win->win);
    if (view == NULL) {
        return;
    }
    center = sfView_getCenter(view);
    obj->bigdata.sprite_bigdata.pos.x = center.x + pos_dialog.x;
    obj->bigdata.sprite_bigdata.pos.y = center.y + pos_dialog.y;
}

void update_dialog(object_t *obj, scene_t *scene,
    window_t *win,
    __attribute__((unused)) float dtime)
{
    dialog_manager_t *dialog = NULL;
    text_dialog_t *text = NULL;

    if (scene == NULL || obj == NULL || scene->pause == true) {
        return;
    }
    update_position(obj, win);
    dialog = dico_t_get_value(scene->components, compo_dialog);
    if (dialog == NULL || dialog->dialogues == NULL ||
            dialog->dialogues->len <= 0) {
        obj->is_visible = false;
        return;
    }
    obj->is_visible = true;
    text = dialog->dialogues->start->var;
    set_new_text(dialog, text, win);
}
