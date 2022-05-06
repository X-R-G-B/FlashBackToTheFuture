/*
** EPITECH PROJECT, 2022
** button generator
** File description:
** tests
*/

#include <stdbool.h>
#include "my_strings.h"
#include "my_puts.h"
#include "my_rpg.h"

int print_help(const char *exe)
{
    my_printf(1, "USAGE: %s [-h] [-f]\n", exe);
    my_putstr(1, "DESCRIPTION:\n\ta mini RPG\n");
    my_putstr(1, "OPTIONS:\n\t-h\tprint this message\n");
    my_putstr(1, "\t-f\trender the game in full screen\n\t\t");
    my_putstr(1, "(the default is in 1920x1080)\n");
    my_putstr(1, "\nmore explanation in game\n");
    my_putstr(1, "web site: https://x-r-g-b.github.io/\n");
    my_putstr(1, "source code : " \
        "https://github.com/X-R-G-B/FlashBackToTheFuture\n");
    return (0);
}

int main(int ac, char **av)
{
    bool is_full_screen = false;

    if (ac == 1) {
        return (launch_game(is_full_screen));
    }
    if (my_strcmp(av[1], "-h") == 0) {
        return (print_help(av[0]));
    } else if (my_strcmp(av[1], "-f") == 0) {
        is_full_screen = true;
    } else {
        return (84);
    }
    return launch_game(is_full_screen);
}
