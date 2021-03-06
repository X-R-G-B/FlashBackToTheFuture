/*
** EPITECH PROJECT, 2022
** defender
** File description:
** object update
*/

#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include "my_bgs_components.h"
#include "my_bgs.h"

static sfVector2i get_mouse_pos(window_t *win)
{
    sfVector2i vector;
    const sfView *view = NULL;
    sfVector2f pos;
    sfVector2f size;

    if (win == NULL) {
        return ((sfVector2i) {0, 0});
    }
    vector = sfMouse_getPositionRenderWindow(win->win);
    view = sfRenderWindow_getView(win->win);
    if (view == NULL) {
        return vector;
    }
    pos = sfView_getCenter(view);
    size = sfView_getSize(view);
    vector.x += (int) pos.x - (size.x / 2);
    vector.y += (int) pos.y - (size.y / 2);
    return vector;
}

int check_hover(object_t *object, window_t *win)
{
    sfFloatRect rect;
    sfVector2i vector;

    if (object == NULL || win == NULL) {
        return (false);
    }
    if (object->type == SPRITE) {
        rect = sfSprite_getGlobalBounds(object->drawable.sprite);
    } else if (object->type == TEXT) {
        rect = sfText_getGlobalBounds(object->drawable.text);
    } else {
        return false;
    }
    vector = get_mouse_pos(win);
    vector.y += 15;
    if (sfFloatRect_contains(&rect, vector.x, vector.y) == sfTrue) {
        return true;
    } else {
        return false;
    }
}

static int check_right_click(object_t *object, window_t *win)
{
    on_right_click_t *right = NULL;

    if (object == NULL || win == NULL) {
        return (false);
    }
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

    if (object == NULL || win == NULL) {
        return (false);
    }
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

    if (object == NULL || scene == NULL || win == NULL) {
        return;
    }
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
