/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** pathfind add to scene
*/

#include "ennemy_pathfind.h"
#include "my_bgs.h"
#include "my_dico.h"
#include "my_rpg.h"
#include <SFML/System/Vector2.h>

static sfVector2i get_player_pos_in_map(player_t *obj)
{
    sfVector2f pos = {10, 10};
    sfVector2i new = {20, 20};

    if (obj == NULL) {
        return (new);
    }
    pos = obj->obj->bigdata.sprite_bigdata.pos;
    new = (sfVector2i) {pos.x / SQUARE_SIZE, pos.y / SQUARE_SIZE};
    if (new.x < 0 || new.y < 0) {
        return ((sfVector2i) {20, 20});
    }
    return (new);
}

static void pathfind_update_path(__attribute__((unused)) object_t *obj_cust,
    scene_t *scene, window_t *win,
    float dtime)
{
    char **collision_array = NULL;
    char tmp = '\0';
    sfVector2i vect = {0};
    static float timer = 0;

    timer += dtime;
    if (timer < TIME_UPDATE_PATH || scene == NULL) {
        return;
    }
    collision_array = dico_t_get_value(scene->components, COLLISION_ARRAY);
    if (collision_array == NULL) {
        return;
    }
    vect = get_player_pos_in_map(dico_t_get_value(win->components, PLAYER));
    tmp = collision_array[vect.y][vect.x];
    collision_array[vect.y][vect.x] = 'P';
    init_pathfind(collision_array, 'P', '#', scene);
    collision_array[vect.y][vect.x] = tmp;
    timer -= 0.5;
}

int pathfind_add_to_scene(scene_t *scene)
{
    object_t *obj = NULL;

    if (scene == NULL) {
        return (RET_ERR_INPUT);
    }
    obj = create_object(pathfind_update_path, NULL, scene, 50);
    if (obj == NULL) {
        return (RET_ERR_MALLOC);
    }
    if (object_set_custom(obj) != BGS_OK) {
        return (RET_ERR_MALLOC);
    }
    return (RET_OK);
}
