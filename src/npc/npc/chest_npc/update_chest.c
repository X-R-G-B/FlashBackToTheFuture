/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update chest
*/

#include <stdlib.h>
#include "npc.h"
#include "macro.h"
#include "player.h"
#include "my_rpg.h"
#include "macro.h"

extern const char npc_path_key[];

static const char check_into_chest_json[] =
        "./assets/data/npc/check_into_chest.json";

static const char sprite_path_key[] = "sprite path";

const char chest_key[] = "chest";

extern const char rect_key[];

extern const char infinity_sprite_path[];

const char time_key[] = "time";

const float dropping_86_move_actualisation = 0.003;

const char scd_rect_key[] = "scd rect";

static void check_collision_dialog(object_t *obj, sfFloatRect player_rect,
    window_t *win)
{
    sfFloatRect chest_rect = sfSprite_getGlobalBounds(obj->drawable.sprite);

    if (sfFloatRect_intersects(&chest_rect, &player_rect, NULL) == sfTrue) {
        add_text_dialog_json(win, check_into_chest_json, &reaload_dialogs, obj);
        obj->update = NULL;
    }
}

static sfFloatRect get_chest_detection_rect(object_t *obj)
{
    sfFloatRect chest_rect = sfSprite_getGlobalBounds(obj->drawable.sprite);

    chest_rect.left -= 50;
    chest_rect.top -= 50;
    chest_rect.width += 100;
    chest_rect.height += 300;
    return chest_rect;
}

static void update_chest(object_t *obj, scene_t *scene, window_t *win,
    __attribute__((unused)) float dtime)
{
    player_t *player = NULL;
    sfFloatRect player_rect = {0};
    sfFloatRect chest_rect = {0};

    if (obj == NULL || scene == NULL || win == NULL) {
        return;
    }
    chest_rect = get_chest_detection_rect(obj);
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || player->obj == NULL) {
        return;
    }
    player_rect = sfSprite_getGlobalBounds(player->obj->drawable.sprite);
    if (sfFloatRect_intersects(&player_rect, &chest_rect, NULL) == sfTrue &&
            dico_t_get_value(obj->components, scd_rect_key) != NULL) {
        check_have_enough_infinity_86(player, obj, win, scene);
    } else if (dico_t_get_value(obj->components, scd_rect_key) == NULL) {
        check_collision_dialog(obj, player_rect, win);
    }
}

static void create_chest(scene_t *scene, any_t *json, int *rect, object_t *obj)
{
    object_t *npc = NULL;
    sfIntRect *scd_rect = malloc(sizeof(sfIntRect));
    any_t *sprite_path = get_from_any(json, "d", sprite_path_key);
    int *rect_array = get_any_int_array(get_from_any(json, "d",
        scd_rect_key));

    if (sprite_path == NULL || sprite_path->type != STR || rect_array == NULL ||
            scd_rect == NULL) {
        return;
    }
    npc = create_object(update_chest, NULL, scene, LAYER_ENNEMY);
    if (object_set_sprite(npc, sprite_path->value.str, (sfIntRect)
            {rect[0], rect[1], rect[2], rect[3]},
            obj->bigdata.sprite_bigdata.pos) != RET_OK) {
        return;
    }
    *scd_rect = (sfIntRect) {rect_array[0], rect_array[1], rect_array[2],
        rect_array[3]};
    npc->components = dico_t_add_data(npc->components, scd_rect_key, scd_rect,
        free);
    free(rect_array);
}

void init_chest(object_t *obj, scene_t *scene, window_t *win,
    __attribute__((unused)) float dtime)
{
    int *rect = NULL;
    any_t *json = NULL;

    if (obj == NULL || obj->components == NULL || scene == NULL ||
            win == NULL) {
        return;
    }
    json = parse_json_file(dico_t_get_value(obj->components, npc_path_key));
    rect = get_any_int_array(get_from_any(json, "d", rect_key));
    if (rect == NULL) {
        return;
    }
    create_chest(scene, json, rect, obj);
    free(rect);
    destroy_any(json);
    obj->components = dico_t_rem(obj->components, npc_path_key);
}
