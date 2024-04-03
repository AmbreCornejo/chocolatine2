/*
** EPITECH PROJECT, 2024
** B-CPE-110-MPL-1-1-secured-alexyan.comino
** File description:
** main
*/

#include <gtk-3.0/gtk/gtk.h>
#include <gtk-3.0/gdk/gdk.h>
#include "include/hashtable.h"
#include "include/header.h"

int main(int argc, char *argv[])
{
    AppData appData;

    gtk_init(&argc, &argv);
    appData.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    appData.hashTable = NULL;
    gtk_window_set_title(GTK_WINDOW(appData.window), "Hash Table Operations");
    g_signal_connect(appData.window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    appData.buttonCreate = gtk_button_new_with_label("Create Hashtable");
    appData.buttonInsert = gtk_button_new_with_label("Insert Entry");
    appData.buttonDelete = gtk_button_new_with_label("Delete Entry");
    appData.buttonSearch = gtk_button_new_with_label("Search Entry");
    appData.buttonDump = gtk_button_new_with_label("Dump Hashtable");
    appData.outputLabel = gtk_label_new("Output:");
    appData.entryKey = gtk_entry_new();
    appData.entryValue = gtk_entry_new();
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    GtkWidget *hboxButtons = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    GtkWidget *hboxEntry = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(vbox), hboxButtons, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(vbox), hboxEntry, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(vbox), appData.outputLabel, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hboxButtons), appData.buttonCreate, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(hboxButtons), appData.buttonInsert, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(hboxButtons), appData.buttonDelete, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(hboxButtons), appData.buttonSearch, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(hboxButtons), appData.buttonDump, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(hboxEntry), gtk_label_new("Key:"), FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hboxEntry), appData.entryKey, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(hboxEntry), gtk_label_new("Value:"), FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(hboxEntry), appData.entryValue, TRUE, TRUE, 5);
    g_signal_connect(appData.buttonCreate, "clicked", G_CALLBACK(create_button_clicked), &appData);
    g_signal_connect(appData.buttonInsert, "clicked", G_CALLBACK(insert_button_clicked), &appData);
    g_signal_connect(appData.buttonDelete, "clicked", G_CALLBACK(delete_button_clicked), &appData);
    g_signal_connect(appData.buttonSearch, "clicked", G_CALLBACK(search_button_clicked), &appData);
    g_signal_connect(appData.buttonDump, "clicked", G_CALLBACK(dump_button_clicked), &appData);
    gtk_container_add(GTK_CONTAINER(appData.window), vbox);
    gtk_widget_show_all(appData.window);
    gtk_main();
    return 0;
}

void create_button_clicked(GtkWidget *widget, gpointer data)
{
    AppData *appData = (AppData *)data;

    if (appData->hashTable != NULL) {
        update_output_label(appData, "Hashtable already exists.");
        return;
    }
    appData->hashTable = new_hashtable(&hash, 10);
    if (appData->hashTable != NULL)
        update_output_label(appData, "Hashtable created successfully.");
    else
        update_output_label(appData, "Failed to create hashtable.");
}

void insert_button_clicked(GtkWidget *widget, gpointer data)
{
    AppData *appData = (AppData *)data;
    const char *key = gtk_entry_get_text(GTK_ENTRY(appData->entryKey));
    const char *value = gtk_entry_get_text(GTK_ENTRY(appData->entryValue));
    int result = ht_insert(appData->hashTable, (char *)key, (char *)value);

    if (appData->hashTable == NULL) {
        update_output_label(appData, "Hashtable does not exist. Create it first.");
        return;
    }
    if (result == 84)
        update_output_label(appData, "Insertion failed.");
    else
        update_output_label(appData, "Insertion successful.");
}

void delete_button_clicked(GtkWidget *widget, gpointer data)
{
    AppData *appData = (AppData *)data;
    const char *key = gtk_entry_get_text(GTK_ENTRY(appData->entryKey));
    int result = ht_delete(appData->hashTable, (char *)key);

    if (appData->hashTable == NULL) {
        update_output_label(appData, "Hashtable does not exist. Create it first.");
        return;
    }
    if (result == 84)
        update_output_label(appData, "Deletion successful.");
    else
        update_output_label(appData, "Deletion failed.");
}

void search_button_clicked(GtkWidget *widget, gpointer data)
{
    AppData *appData = (AppData *)data;
    const char *key = gtk_entry_get_text(GTK_ENTRY(appData->entryKey));
    char *result = ht_search(appData->hashTable, (char *)key);
    char message[256];

    if (appData->hashTable == NULL) {
        update_output_label(appData, "Hashtable does not exist. Create it first.");
        return;
    }
    if (result != NULL) {
        snprintf(message, sizeof(message), "Search result: %s", result);
        update_output_label(appData, message);
    } else
        update_output_label(appData, "Key not found.");
}

char *dump_hashtable(hashtable_t *ht)
{
    char *dumpMessage = NULL;
    list_t *current = NULL;

    if (ht == NULL)
        return strdup("Hashtable does not exist.");
    for (int i = 0; i < ht->len; i++) {
        current = ht->array[i];
        while (current != NULL) {
            asprintf(&dumpMessage, "%s[%d]: %d - %s\n", dumpMessage ? dumpMessage : "",
                    i, current->key, current->value);
            current = current->next;
        }
    }
    if (!dumpMessage)
        dumpMessage = strdup("Hashtable is empty.");
    return dumpMessage;
}

void dump_button_clicked(GtkWidget *widget, gpointer data)
{
    AppData *appData = (AppData *)data;
    char *dumpMessage = dump_hashtable(appData->hashTable);

    if (appData->hashTable == NULL) {
        update_output_label(appData, "Hashtable does not exist. Create it first.");
        return;
    }
    update_output_label(appData, dumpMessage);
    free(dumpMessage);
}

void update_output_label(AppData *appData, const char *message)
{
    gtk_label_set_text(GTK_LABEL(appData->outputLabel), message);
}
