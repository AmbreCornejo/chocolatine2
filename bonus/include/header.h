/*
** EPITECH PROJECT, 2024
** bonus
** File description:
** header
*/

#pragma once

#include <gtk-3.0/gtk/gtk.h>
#include <gtk-3.0/gdk/gdk.h>

typedef struct {
    GtkWidget *window;
    GtkWidget *buttonCreate;
    GtkWidget *buttonInsert;
    GtkWidget *buttonDelete;
    GtkWidget *buttonSearch;
    GtkWidget *buttonDump;
    GtkWidget *outputLabel;
    GtkWidget *entryKey;
    GtkWidget *entryValue;
    hashtable_t *hashTable;
} AppData;

void create_button_clicked(GtkWidget *widget, gpointer data);
void insert_button_clicked(GtkWidget *widget, gpointer data);
void delete_button_clicked(GtkWidget *widget, gpointer data);
void search_button_clicked(GtkWidget *widget, gpointer data);
void dump_button_clicked(GtkWidget *widget, gpointer data);
void update_output_label(AppData *appData, const char *message);
