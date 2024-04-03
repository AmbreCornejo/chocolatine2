/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-navy-ambre.cornejo
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/my.h"

int is_same(int i, int j, int *len_boat);
char **place_boat_in_map(char **map, char **pos);
int number_in_line(char **map, int i);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_putchar, should_print_a_character, .init = redirect_all_std)
{
    my_putchar('a');
    cr_assert_stdout_eq_str("a");
}

Test(my_getnbr, should_return_0, .init = redirect_all_std)
{
    int nb = my_getnbr("0");

    cr_assert_eq(nb, 0);
}

Test(my_getnbr, should_return_42, .init = redirect_all_std)
{
    int nb = my_getnbr("42");

    cr_assert_eq(nb, 42);
}

Test(my_getnbr, should_return_84, .init = redirect_all_std)
{
    int nb = my_getnbr("-84");

    cr_assert_eq(nb, -84);
}

Test(my_getnbr, should_return_02, .init = redirect_all_std)
{
    int nb = my_getnbr("e5");

    cr_assert_eq(nb, 0);
}

Test(my_getnbr, should_return_03, .init = redirect_all_std)
{
    int nb = my_getnbr("-2147483649");

    cr_assert_eq(nb, 0);
}

Test(my_getnbr, should_return_04, .init = redirect_all_std)
{
    int nb = my_getnbr("2147483649");

    cr_assert_eq(nb, 0);
}

Test(my_getnbr, should_return_06, .init = redirect_all_std)
{
    int nb = my_getnbr("-+-+-+1");

    cr_assert_eq(nb, 0);
}

Test(my_getnbr, should_return_05, .init = redirect_all_std)
{
    int nb = my_getnbr("+-+-+-");

    cr_assert_eq(nb, 0);
}

Test(my_getnbr, should_return_5, .init = redirect_all_std)
{
    int nb = my_getnbr("+-5");

    cr_assert_eq(nb, -5);
}

Test(my_getnbr, should_return_1, .init = redirect_all_std)
{
    int nb = my_getnbr("1");

    cr_assert_eq(nb, 1);
}

Test(my_put_nbr, should_print_0, .init = redirect_all_std)
{
    my_put_nbr(0);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_nbr, should_print_1, .init = redirect_all_std)
{
    my_put_nbr(1);
    cr_assert_stdout_eq_str("1");
}

Test(my_put_nbr, should_print_42, .init = redirect_all_std)
{
    my_put_nbr(-420);
    cr_assert_stdout_eq_str("-420");
}

Test(my_put_nbr, test_my_put_nbr, .init = redirect_all_std)
{
    my_put_nbr(42);
    cr_assert_stdout_eq_str("42");
}


Test(my_strlen, test_my_strlen)
{
    cr_assert_eq(my_strlen("test"), 4);
}

Test(my_strcmp, test_my_strcmp)
{
    cr_assert_eq(my_strcmp("test", "test"), 0);
    cr_assert_eq(my_strcmp("test", "toto"), -10);
    cr_assert_eq(my_strcmp("toto", "test"), 10);
}

Test(display_h, test_display_h, .init = redirect_all_std)
{
    display_h("-h");
    cr_assert_stdout_neq_str("USAGE\n\t./navy [first_player_pid] navy_positions\nDESCRIPTION\n\tfirst_player_pid: only for the 2nd player. pid of the first player.\n\tnavy_positions: file representing the positions of the ships.\n");
}

Test(display_turn, test_display_turn, .init = redirect_all_std)
{
    char **map = malloc(sizeof(char *) * 9);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 9);
        for (int j = 0; j < 8; j++)
            map[i][j] = '.';
    }
    map[8] = NULL;
    display_turn(map, 1);
    cr_assert_stdout_eq_str("my navy:\n |A B C D E F G H\n-+---------------\n1|. . . . . . . .\n2|. . . . . . . .\n3|. . . . . . . .\n4|. . . . . . . .\n5|. . . . . . . .\n6|. . . . . . . .\n7|. . . . . . . .\n8|. . . . . . . .\n\n");
}

Test(bad_file, test_bad_file)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "C1";
    pos[2] = "C2";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 0);
}

Test(bad_file, test_bad_file2)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "A1";
    pos[2] = "A2";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 0);
}

Test(bad_file, test_bad_file4)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "9";
    pos[1] = "A1";
    pos[2] = "A3";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(bad_file, test_bad_file5)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "A1";
    pos[2] = "A9";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(bad_file, test_bad_file6)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "A1";
    pos[2] = "A9";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(bad_file, test_bad_file3)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "1";
    pos[1] = "A1";
    pos[2] = "A25";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(bad_file, test_bad_file7)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "A1";
    pos[2] = "A2";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 0);
}

Test(bad_str, test_bad_str)
{
    cr_assert_eq(bad_str("A1:A2"), 84);
}

Test(bad_str, test_bad_str2)
{
    cr_assert_eq(bad_str("A1A2"), 84);
}

Test(bad_str, test_bad_str3)
{
    cr_assert_eq(bad_str(""), 84);
}

Test(same_boat_len, test_same_boat_len)
{
    int len_boat[4] = {2, 3, 4, 5};

    cr_assert_eq(same_boat_len(len_boat), 0);
}

Test(bad_attack, test_bad_attack4)
{
    cr_assert_eq(bad_attack(NULL), 84);
}

Test(bad_attack, test_bad_attack)
{
    cr_assert_eq(bad_attack("C4\n"), 0);
}

Test(bad_attack, test_bad_attack2)
{
    cr_assert_eq(bad_attack("A9"), 84);
}

Test(same_boat_len, test_same_boat_len2)
{
    int len_boat[4] = {2, 3, 4, 4};

    cr_assert_eq(same_boat_len(len_boat), 84);
}

Test(same_boat_len, test_same_boat_len3)
{
    int len_boat[4] = {2, 3, 4, 5};

    cr_assert_eq(same_boat_len(len_boat), 0);
}

Test(open_read, test_open_read)
{
    cr_assert_neq(open_read("pos1"), NULL);
}

Test(create_map, test_create_map)
{
    cr_assert_neq(create_map(), NULL);
}

// Test(create_map, test_create_map2)
// {
//     char **map = create_map();

//     cr_assert_eq(map[1], "........\n");
// }

Test(load_2d_array, test_load_2d_array)
{
    cr_assert_neq(load_2d_array("pos1"), NULL);
}

Test(str_in_array, test_str_in_array)
{
    cr_assert_neq(str_in_array("A1:A2"), NULL);
}

Test(load_map, test_load_map)
{
    cr_assert_neq(load_map("pos1"), NULL);
}

Test(load_map, test_load_map2)
{
    cr_assert_eq(load_map(""), NULL);
}

Test(nb_row, test_nb_row)
{
    cr_assert_eq(nb_row("A1:A2\nA1:A2\nA1:A2\nA1:A2\n"), 4);
}

Test(letter_to_int, test_letter_to_int)
{
    cr_assert_eq(letter_to_int('A'), 0);
}

// Test(place_boat_in_map, test_place_boat_in_map)
// {
//     char **map = malloc(sizeof(char *) * 9);
//     char **pos = malloc(sizeof(char *) * 3);

//     pos[0] = "2";
//     pos[1] = "A1";
//     pos[2] = "A2";
//     map = place_boat_in_map(map, pos);
//     cr_assert_eq(map[0][0], '2');
// }

Test(parsing, test_parsing)
{
    cr_assert_neq(parsing("pos1"), NULL);
}

Test(parsing, test_parsing2)
{
    cr_assert_eq(parsing(""), NULL);
}

Test(parsing, test_parsing3)
{
    cr_assert_neq(parsing("wrongpos"), NULL);
}

Test(parsing, test_parsing4)
{
    cr_assert_eq(parsing("wrongpos2"), NULL);
}

Test(prev_count, test_prev_count)
{
    cr_assert_neq(prev_count(), 0);
}

Test(get_pid, test_get_pid)
{
    cr_assert_neq(get_pid(), 0);
}

Test(attack_count, test_attack_count)
{
    cr_assert_neq(attack_count(), 0);
}

Test(mode, test_mode)
{
    cr_assert_neq(mode(), 0);
}

Test(return_signal, test_return_signal)
{
    cr_assert_neq(return_signal(), 0);
}

Test(display_pid, test_display_pid, .init = redirect_all_std)
{
    display_pid();
    cr_assert_stdout_neq_str("my_pid: 42\n");
}

Test(display_turn, test_display_turn2, .init = redirect_all_std)
{
    char **map = malloc(sizeof(char *) * 9);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 9);
        for (int j = 0; j < 8; j++)
            map[i][j] = '.';
    }
    map[8] = NULL;
    display_turn(map, 2);
    cr_assert_stdout_eq_str("enemy navy:\n |A B C D E F G H\n-+---------------\n1|. . . . . . . .\n2|. . . . . . . .\n3|. . . . . . . .\n4|. . . . . . . .\n5|. . . . . . . .\n6|. . . . . . . .\n7|. . . . . . . .\n8|. . . . . . . .\n\n");
}

Test(bad_file, test_bad_file8)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "I1";
    pos[2] = "B2";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}


Test(bad_file, test_bad_file9)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "B9";
    pos[2] = "B2";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(bad_file, test_bad_file10)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "B0";
    pos[2] = "B2";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(bad_file, test_bad_file11)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "B1";
    pos[2] = "I2";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(bad_file, test_bad_file12)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "B1";
    pos[2] = "B0";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(bad_file, test_bad_file13)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "B0";
    pos[2] = "B9";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(bad_file, test_bad_file14)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "0";
    pos[1] = "B0";
    pos[2] = "B2";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(bad_file, test_bad_file15)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "01";
    pos[2] = "B2";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(bad_file, test_bad_file16)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "91";
    pos[2] = "B2";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(bad_file, test_bad_file17)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "B1";
    pos[2] = "92";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(bad_file, test_bad_file18)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "B1";
    pos[2] = "B9";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(bad_file, test_bad_file19)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "21";
    pos[1] = "B1";
    pos[2] = "B2";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(bad_file, test_bad_file20)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "B11";
    pos[2] = "B2";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(bad_file, test_bad_file21)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "B1";
    pos[2] = "B23";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(bad_str, test_bad_str4)
{
    cr_assert_eq(bad_str("2:A1:A2"), 0);
}

Test(bad_str, test_bad_str5)
{
    cr_assert_eq(bad_str("2A:1:A2"), 84);
}

Test(bad_str, test_bad_str6)
{
    cr_assert_eq(bad_str("2:A1A2"), 84);
}

Test(bad_str, test_bad_str7)
{
    cr_assert_eq(bad_str("2:A1:A2A"), 84);
}

Test(bad_attack, test_bad_attack3)
{
    cr_assert_eq(bad_attack("I1\n"), 84);
}

Test(bad_attack, test_bad_attack5)
{
    cr_assert_eq(bad_attack("@9\n"), 84);
}

Test(bad_attack, test_bad_attack6)
{
    cr_assert_eq(bad_attack("A9\n"), 84);
}

Test(bad_attack, test_bad_attack7)
{
    cr_assert_eq(bad_attack("A0\n"), 84);
}

Test(bad_attack, test_bad_attack8)
{
    cr_assert_eq(bad_attack("A1A2\n"), 84);
}

Test(bad_file, test_bad_file22)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "@1";
    pos[2] = "B23";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(bad_file, test_bad_file23)
{
    int *boat_pos = malloc(sizeof(int) * 7);
    char **pos = malloc(sizeof(char *) * 3);

    pos[0] = "2";
    pos[1] = "91";
    pos[2] = "B23";
    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    cr_assert_eq(bad_file(boat_pos, pos), 84);
}

Test(hit_or_miss, test_hit_or_miss, .init = redirect_all_std)
{
    hit_or_miss("A1", 0);
    cr_assert_stdout_eq_str("\nresult: A1:missed\n\n");
}

Test(hit_or_miss, test_hit_or_miss2, .init = redirect_all_std)
{
    hit_or_miss("A1", 1);
    cr_assert_stdout_eq_str("\nresult: A1:hit\n\n");
}

Test(is_win, test_is_win)
{
    char **map = malloc(sizeof(char *) * 9);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 9);
        for (int j = 0; j < 8; j++)
            map[i][j] = '.';
    }
    map[8] = NULL;
    cr_assert_eq(is_win(map), 1);
}

Test(is_win, test_is_win2)
{
    char **map = malloc(sizeof(char *) * 9);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 9);
        for (int j = 0; j < 8; j++)
            map[i][j] = '.';
    }
    map[4][4] = '2';
    map[8] = NULL;
    map[0][0] = '2';
    cr_assert_eq(is_win(map), 0);
}

Test(is_win, test_is_win3)
{
    char **map = malloc(sizeof(char *) * 9);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 9);
        for (int j = 0; j < 8; j++)
            map[i][j] = '.';
    }
    map[4][4] = '8';
    map[8] = NULL;
    cr_assert_eq(is_win(map), 0);
}

Test(is_win, test_is_win4)
{
    char **map = malloc(sizeof(char *) * 9);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 9);
        for (int j = 0; j < 8; j++)
            map[i][j] = '.';
    }
    map[4][4] = '9';
    map[8] = NULL;
    cr_assert_eq(is_win(map), 1);
}