/*
** EPITECH PROJECT, 2024
** B-CPE-110-MPL-1-1-secured-alexyan.comino
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"
#include "../include/my.h"

int del(list_t **current, list_t **list, list_t **temp, int key);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(new_hashtable, test_new_hashtable)
{
    hashtable_t *table = new_hashtable(&hash, 3);
    hashtable_t *table2 = new_hashtable(&hash, -10);

    cr_assert_eq(table->len, 3);
    cr_assert_eq(table->hash, &hash);
    cr_assert_eq(table->array[0], NULL);
    cr_assert_eq(table->array[1], NULL);
    cr_assert_eq(table->array[2], NULL);
    cr_assert_eq(table2, NULL);
}

Test(delete_hashtable, test_delete_hashtable)
{
    hashtable_t *table = new_hashtable(&hash, 3);
    delete_hashtable(table);
}

Test(hash, test_hash)
{
    cr_assert_eq(hash("test", 3), 834821825);
}

Test(my_putchar, test_my_putchar, .init = redirect_all_std)
{
    my_putchar('c');
    cr_assert_stdout_eq_str("c");
}

Test(my_putstr, test_my_putstr, .init = redirect_all_std)
{
    my_putstr("test");
    cr_assert_stdout_eq_str("test");
}

Test(my_put_nbr, test_my_put_nbr, .init = redirect_all_std)
{
    my_put_nbr(42);
    cr_assert_stdout_eq_str("42");
}

Test(my_put_nbr, test_my_put_nbr2, .init = redirect_all_std)
{
    my_put_nbr(-42);
    cr_assert_stdout_eq_str("-42");
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

Test(my_strcpy, test_my_strcpy)
{
    char *str = malloc(sizeof(char) * 5);

    str = my_strcpy(str, "test");
    cr_assert_str_eq(str, "test");
}

Test(my_strdup, test_my_strdup)
{
    char *str = my_strdup("test");

    cr_assert_str_eq(str, "test");
}

Test(push_to_front, test_push_to_front)
{
    list_t *list = NULL;

    push_to_front(&list, 1, "test");
    cr_assert_eq(list->key, 1);
    cr_assert_str_eq(list->value, "test");
}

Test(display_list, test_display_list, .init = redirect_all_std)
{
    list_t *list = NULL;

    push_to_front(&list, 1, "test");
    push_to_front(&list, 2, "test2");
    display_list(list);
    cr_assert_stdout_eq_str("> 2 - test2\n> 1 - test\n");
}

Test(display_list, key_null, .init = redirect_all_std)
{
    list_t *list = NULL;

    push_to_front(&list, 1, "test");
    push_to_front(&list, 2, "test2");
    list->key = '\0';
    display_list(list);
    cr_assert_stdout_eq_str("> 1 - test\n");
}

Test(delete_list, test_delete_list)
{
    list_t *list = NULL;

    push_to_front(&list, 1, "test");
    push_to_front(&list, 2, "test2");
    delete_list(&list);
    cr_assert_eq(list, NULL);
}

Test(delete_in_list , test_delete_in_list)
{
    list_t *list = NULL;

    push_to_front(&list, 1, "test");
    push_to_front(&list, 2, "test2");
    delete_in_list(&list, hash("test", 4));
    cr_assert_eq(list->key, 2);
    cr_assert_str_eq(list->value, "test2");
}

Test(delete_in_list , test_delete_in_list2)
{
    list_t *list = NULL;

    push_to_front(&list, 1, "test");
    push_to_front(&list, 2, "test2");
    push_to_front(&list, 3, "test3");
    delete_in_list(&list, hash("test", 3));
    cr_assert_eq(list->key, 3);
    cr_assert_str_eq(list->value, "test3");
}

Test(delete_in_list, test_multiple_delete)
{
    list_t *list = NULL;

    push_to_front(&list, 2, "test2");
    push_to_front(&list, 3, "test3");
    push_to_front(&list, 3, "test3");
    push_to_front(&list, 3, "test3");
    push_to_front(&list, 3, "test3");
    push_to_front(&list, 3, "test3");
    delete_in_list(&list, 3);
    delete_in_list(&list, 2);
    push_to_front(&list, 1, "test");
    cr_assert_eq(list->key, 1);
    cr_assert_str_eq(list->value, "test");
}

Test(ht_insert, test_ht_insert)
{
    hashtable_t *table = new_hashtable(&hash, 3);

    ht_insert(table, "test", "test");
    cr_assert_eq(table->array[2]->key, 834821825);
    cr_assert_str_eq(table->array[2]->value, "test");
}

Test(ht_insert, ht_insert_null)
{
    hashtable_t *table = new_hashtable(&hash, 3);
    cr_assert_eq(ht_insert(table, "", "test"), 84);
    cr_assert_eq(ht_insert(table, "test", ""), 84);
    cr_assert_eq(ht_insert(table, NULL, "test"), 84);
    cr_assert_eq(ht_insert(table, "test", NULL), 84);
    cr_assert_eq(ht_insert(NULL, "test", "test"), 84);
}

Test(ht_delete, test_ht_delete)
{
    hashtable_t *hashtable = new_hashtable(&hash, 3);

    ht_insert(hashtable, "test", "test");
    ht_insert(hashtable, "test2", "test2");
    ht_insert(hashtable, "test3", "test3");
    ht_delete(hashtable, "test");
    cr_assert_eq(hashtable->array[0]->key, 435231558);
    cr_assert_neq(hashtable->array[0]->value, "test3");
}

Test(ht_delete, ht_delete_null)
{
    hashtable_t *table = new_hashtable(&hash, 3);

    cr_assert_eq(ht_delete(table, "Not Found"), 84);
    cr_assert_eq(ht_delete(table, ""), 84);
    cr_assert_eq(ht_delete(NULL, "test"), 84);
    cr_assert_eq(ht_delete(table, NULL), 84);
}

Test(ht_search, test_ht_search)
{
    hashtable_t *table = new_hashtable(&hash, 3);
    hashtable_t *table2 = new_hashtable(&hash, 3);

    ht_insert(table, "test", "test");
    ht_insert(table, "test2", "test2");
    cr_assert_str_eq(ht_search(table, "test"), "test");
    cr_assert_eq(ht_search(table, "caca"), NULL);
    cr_assert_eq(ht_search(table2, "test"), NULL);
    cr_assert_eq(ht_search(table, NULL), NULL);
}

Test(ht_search, test_ht_search2)
{
    hashtable_t *hashtable = new_hashtable(&hash, 3);

    ht_insert(hashtable, "test", "test");
    ht_insert(hashtable, "ababba", "boubou");
    ht_insert(hashtable, "test3", "test3");
    ht_insert(hashtable, "test2", "test2");
    ht_insert(hashtable, "test4", "test4");
    ht_insert(hashtable, "test5", "test5");
    ht_insert(hashtable, "test6", "test6");
    cr_assert_neq(ht_search(hashtable, "test3"), "test6");
}

Test(ht_search, ht_search_null)
{
    hashtable_t *table = new_hashtable(&hash, 3);

    cr_assert_eq(ht_search(table, ""), NULL);
    cr_assert_eq(ht_search(NULL, "test"), NULL);
}

Test(ht_dump, test_ht_dump, .init = redirect_all_std)
{
    hashtable_t *table = new_hashtable(&hash, 3);

    ht_insert(table, "test", "test");
    ht_dump(table);
    cr_assert_stdout_eq_str("[0]:\n[1]:\n[2]:\n> 834821825 - test\n");
}

Test(ht_dump, ht_dump_null, .init = redirect_all_std)
{
    ht_dump(NULL);
    cr_assert_stdout_neq_str("");
}

Test(ht_insert, test_ht_insert_edit)
{
    hashtable_t *table = new_hashtable(&hash, 3);

    ht_insert(table, "test", "test");
    ht_insert(table, "test", "test2");
    cr_assert_str_eq(table->array[2]->value, "test2");

}

Test(ht_edit, test_ht_edit)
{
    hashtable_t *table = new_hashtable(&hash, 3);

    ht_insert(table, "test", "test");
    ht_insert(table, "test2", "test2");
    ht_insert(table, "test3", "test3");
    ht_insert(table, "test4", "test4");
    ht_insert(table, "test5", "test5");
    ht_insert(table, "test6", "test6");
    ht_insert(table, "test7", "test7");
    ht_insert(table, "test8", "test8");
    ht_insert(table, "test9", "test9");
    ht_insert(table, "test10", "test10");
    ht_insert(table, "test11", "test11");
    ht_insert(table, "test12", "test12");
    ht_edit(table, "test", "temp");
    cr_assert_str_neq(table->array[2]->value, "test");
}

Test(ht_edit, test_ht_edit_not_found)
{
    hashtable_t *table = new_hashtable(&hash, 3);

    ht_insert(table, "temp", "test");
    cr_assert_eq(ht_edit(table, "test", "temp"), 84);
}

Test(ht_edit, test_ht_edit_null)
{
    hashtable_t *table = new_hashtable(&hash, 3);

    cr_assert_eq(ht_edit(table, "", "test"), 84);
    cr_assert_eq(ht_edit(table, "test", ""), 84);
    cr_assert_eq(ht_edit(table, NULL, "test"), 84);
    cr_assert_eq(ht_edit(table, "test", NULL), 84);
    cr_assert_eq(ht_edit(NULL, "test", "test"), 84);
}
