/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-navy-ambre.cornejo
** File description:
** main
*/

#include "includes/my.h"

void load_items(navy_t *navy, char **av)
{
    navy->enemy_pid = my_getnbr(av[1]);
    navy->map = load_map(av[2]);
}

int main(int ac, char **av)
{
    navy_t *navy = malloc(sizeof(navy_t));

    navy->enemy_map = create_map();
    if (ac != 2 && ac != 3)
        return 84;
    display_h(av[1]);
    if (ac == 2) {
        navy->map = load_map(av[1]);
        if (navy->map == NULL) {
            return 84;
        }
        player1(navy);
    }
    if (ac == 3) {
        load_items(navy, av);
        if (navy->map == NULL)
            return 84;
        player2(navy, av);
    }
    return 0;
}
