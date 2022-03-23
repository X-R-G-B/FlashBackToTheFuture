/*
** EPITECH PROJECT, 2022
** defender
** File description:
** object update
*/

#include <stdbool.h>
#include "my_bgs_components.h"
#include "my_bgs.h"
// !!!
// unused functions
int check_hover(object_t *object, window_t *win)
{
    sfFloatRect rect;
    sfVector2i vector;

    if (object->type == SPRITE) {
        rect = sfSprite_getGlobalBounds(object->drawable.sprite);
    } else if (object->type == TEXT) {
        rect = sfText_getGlobalBounds(object->drawable.text);
    } else {
        return false;
    }
    vector = sfMouse_getPositionRenderWindow(win->win);
    if (sfFloatRect_contains(&rect, vector.x, vector.y) == sfTrue) {
        return true;
    } else {
        return false;
    }
}

static int check_right_click(object_t *object, window_t *win)
{
    on_right_click_t *right = NULL;

    right = dico_t_get_value(object->components, ON_RIGHT_KEY);
    if (check_hover(object, win) == 0) {
        return false;
    }
    if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue) {
        return (right->prev_right_click == false) ? true : false;
    }
    right->prev_right_click = false;
    return (false);
}

static int check_left_click(object_t *object, window_t *win)
{
    on_left_click_t *left = NULL;

    left = dico_t_get_value(object->components, ON_LEFT_KEY);
    if (left == NULL || check_hover(object, win) == false) {
        return false;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        return (left->prev_left_click == false) ? true : false;
    }
    left->prev_left_click = false;
    return (false);
}

void object_update_mouse_event(object_t *object, scene_t *scene,
    window_t *win)
{
    void *data = NULL;

    data = dico_t_get_value(object->components, ON_HOVER_KEY);
    if (data != NULL && check_hover(object, win) == 1) {
        ((on_hover_t *) data)->hover(object, scene, win);
    }
    data = dico_t_get_value(object->components, ON_RIGHT_KEY);
    if (data != NULL && check_right_click(object, win) == 1) {
        ((on_right_click_t *) data)->right_click(object, scene, win);
    }
    data = dico_t_get_value(object->components, ON_LEFT_KEY);
    if (data != NULL && check_left_click(object, win) == 1) {
        ((on_left_click_t *) data)->left_click(object, scene, win);
    }
}
