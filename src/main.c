/*
** EPITECH PROJECT, 2022
** button generator
** File description:
** tests
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my_strings.h"
#include "my_puts.h"
#include "stage.h"
#include "my_wordarray.h"

static bool is_graphic_env(char **env)
{
    if (env == NULL) {
        return false;
    }
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strstartswith(env[i], "DISPLAY=") == 1) {
            return true;
        }
    }
    return false;
}

static const char *get_path_root_from_arg(int ac, char **av)
{
    char **wa = NULL;
    static char buffer[1024] = {0};
    int len = 0;

    buffer[0] = '\0';
    if (ac >= 1) {
        wa = my_wordarray_from_str(av[0], '/');
        if (wa == NULL) {
            return "./";
        }
        if (my_wordarray_len(wa) == 0 || my_wordarray_len(wa) == 1) {
            my_wordarray_free(wa);
            return "./";
        }
        free(wa[my_wordarray_len(wa) - 1]);
        wa[my_wordarray_len(wa) - 1] = NULL;
        for (int i = 0; wa[i] != NULL && wa[i + 1] != NULL; i++) {
            if (len + my_strlen(wa[i]) + 1 >= 1024) {
                my_wordarray_free(wa);
                return NULL;
            }
            my_strcat(buffer, wa[i]);
            my_strcat(buffer, "/");
            len += my_strlen(wa[i]);
        }
        return buffer;
    }
    return NULL;
}

static const char *get_path_root(char **env, int ac, char **av)
{
    static char buffer[1014] = {0};

    buffer[0] = '\0';
    if (env == NULL) {
        return get_path_root_from_arg(ac, av);
    }
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strstartswith(env[i], "APPDIR=") == 1) {
            if (my_strlen(env[i] + my_strlen("APPDIR=")) + 1 >= 1024) {
                return NULL;
            }
            my_strcat(buffer, env[i] + my_strlen("APPDIR="));
            my_strcat(buffer, "/");
            return buffer;
        }
    }
    return get_path_root_from_arg(ac, av);
}

static int print_help(const char *exe)
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

int main(int ac, char **av, char **env)
{
    const char *path_root = get_path_root(env, ac, av);
    bool is_full_screen = false;

    if (is_graphic_env(env) == false) {
        my_putstr(2, "No graphics environment :( sorry\n");
        return (0);
    }
    if (ac == 1) {
        return (launch_game(is_full_screen, path_root));
    }
    if (my_strcmp(av[1], "-h") == 0) {
        return (print_help(av[0]));
    } else if (my_strcmp(av[1], "-f") == 0) {
        is_full_screen = true;
    } else {
        return (84);
    }
    return launch_game(is_full_screen, path_root);
}
