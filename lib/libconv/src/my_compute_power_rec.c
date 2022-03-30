/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p < 0) {
        return (0);
    }
    if (p == 0) {
        return (1);
    } else {
        result = nb * my_compute_power_rec(nb, p - 1);
    }
    return (result);
}
