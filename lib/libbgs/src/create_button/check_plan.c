/*
** EPITECH PROJECT, 2022
** create button
** File description:
** check plan
*/

#include "my_bgs_button_generator.h"

int check_plan(dico_t *dico)
{
    any_t *plan = dico_t_get_any(dico, "plan");

    if (plan == NULL || plan->type != INT) {
        return 0;
    }
    return plan->value.i;
}
