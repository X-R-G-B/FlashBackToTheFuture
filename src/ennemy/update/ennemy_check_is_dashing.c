/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** check if ennemy can dash
*/

#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include "my_bgs.h"
#include "my_dico.h"
#include "my_json.h"
#include "my_puts.h"
#include "ennemies.h"
#include "my_rpg.h"
#include "math.h"

static const char range_dash[] = "range dash";

static float get_readius_dash(dico_t *components)
{
    any_t *data = NULL;
    any_t *float_val = NULL;

    data = dico_t_get_value(components, ENNEMY_DATA);
    float_val = get_from_any(data, "d", range_dash);
    if (float_val == NULL || float_val->type != FLOAT) {
        my_printf(1, "ennemy json should have %s of type float", range_dash);
        return (0);
    }
    return (float_val->value.f);
}

bool check_is_dashing(ennemy_t *ennemy, window_t *win)
{
    player_t *player = NULL;
    sfFloatRect rect = {0};
    sfVector2f center = {0};
    float radius = 0;

    if (ennemy == NULL || win == NULL || ennemy->obj == NULL) {
        return (false);
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL || player->obj == NULL) {
        return (false);
    }
    rect = sfSprite_getGlobalBounds(player->obj->drawable.sprite);
    center = ennemy->obj->bigdata.sprite_bigdata.pos;
    radius = get_readius_dash(ennemy->obj->components);
    return (check_circle_col(rect, center, radius));
}
