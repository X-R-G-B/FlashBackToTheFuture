/*
** EPITECH PROJECT, 2022
** my_atof
** File description:
** change string to float (double)
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

int my_compute_power_rec(int, int);
int my_strlen(char *);
int my_atoi(char const *);

int get_float_gap(char *str)
{
    int len = 0;
    int i = 0;

    for (; str[i] != '.' && str[i] != '\0'; i++);
    if (str[i] == '\0') {
        return 0;
    }
    i++;
    for (; str[i] != '\0'; i++, len++);
    return len;
}

int increment_str(char str, char *result, int *indx)
{
    if (str != '.') {
        result[*indx] = str;
        (*indx) += 1;
        result[*indx] = '\0';
    }
    return 0;
}

char *get_int_str(char *str)
{
    char *result = NULL;
    int check = 0;
    int indx = 0;

    if (str == NULL) {
        return NULL;
    }
    for (; str[check] != '\0' && str[check] != '.'; check++);
    if (str[check] != '.') {
        return str;
    }
    result = malloc(sizeof(char) * my_strlen(str));
    for (int i = 0; str[i] != '\0'; i++) {
        increment_str(str[i], result, &indx);
    }
    return result;
}

double my_atof(char *str)
{
    char *int_str = NULL;
    int gap_float = 0;
    int int_nbr = 0;
    double res = 0.0;

    if (str == NULL) {
        return 0;
    }
    int_str = get_int_str(str);
    int_nbr = my_atoi(int_str);
    gap_float = get_float_gap(str);
    res = ((double) int_nbr) / ((double) my_compute_power_rec(10, gap_float));
    free(int_str);
    return res;
}
