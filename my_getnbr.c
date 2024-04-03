/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** getnbr
*/

#include <stdio.h>
#include <limits.h>

static void number_find(char const *str, int i, long int *number)
{
    int j = i + 1;

    while (str[j] >= 48 && str[j] <= 57) {
        *number = (*number * 10) + (str[j] - '0');
        j++;
    }
}

static void if_not_int(long int *number)
{
    long long unsigned int nb = *number;

    if (*number < -2147483648 || *number > INT_MAX || nb == ULLONG_MAX) {
        *number = 0;
    }
}

static int nb_chain(char const *str, int j, int type)
{
    long int number;

    for (int i = j; str[i] != 0; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            number = str[i] - '0';
            number_find(str, i, &number);
            number *= type;
            if_not_int(&number);
            return number;
        }
    }
    return 0;
}

int my_getnbr(char const *str)
{
    int type = 1;
    int j = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '-')
            type = type * (-1);
    }
    if (str[j] == '+' || str[j] == '-' || (str[j] <= 57 && str[j] >= 48)) {
        while (str[j] == '-' || str[j] == '+')
            j++;
        return nb_chain(str, j, type);
    }
    return 0;
}
