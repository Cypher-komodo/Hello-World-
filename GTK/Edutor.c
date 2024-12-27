#include <gtk/gtk.h>

static void open_file(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;
    GtkWidget *text_view = GTK_WIDGET(data);
    GtkTextBuffer *buffer;
    GtkTextIter start, end;

    dialog = gtk_file_chooser_dialog_new("Open File",
                                         GTK_WINDOW(gtk_widget_get_toplevel(widget)),
                                         GTK_FILE_CHOOSER_ACTION_OPEN,
                                         "_Cancel", GTK_RESPONSE_CANCEL,
                                         "_Open", GTK_RESPONSE_ACCEPT,
                                         NULL);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        char *filename;
        char *content;
        gsize length;
        GError *error = NULL;

        filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));

        if (g_file_get_contents(filename, &content, &length, &error)) {
            buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
            gtk_text_buffer_set_text(buffer, content, length);
            g_free(content);
        } else {
            g_print("Error: %s\n", error->message);
            g_error_free(error);
        }

        g_free(filename);
    }

    gtk_widget_destroy(dialog);
}

static void save_file(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;
    GtkWidget *text_view = GTK_WIDGET(data);
    GtkTextBuffer *buffer;
    GtkTextIter start, end;

    dialog = gtk_file_chooser_dialog_new("Save File",
                                         GTK_WINDOW(gtk_widget_get_toplevel(widget)),
                                         GTK_FILE_CHOOSER_ACTION_SAVE,
                                         "_Cancel", GTK_RESPONSE_CANCEL,
                                         "_Save", GTK_RESPONSE_ACCEPT,
                                         NULL);

    gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(dialog), TRUE);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        char *filename;
        gchar *content;
        GError *error = NULL;

        filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));

        buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
        gtk_text_buffer_get_bounds(buffer, &start, &end);
        content = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

        if (!g_file_set_contents(filename, content, -1, &error)) {
            g_print("Error: %s\n", error->message);
            g_error_free(error);
        }

        g_free(content);
        g_free(filename);
    }

    gtk_widget_destroy(dialog);
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *text_view;
    GtkWidget *scrolled_window;
    GtkWidget *menu_bar;
    GtkWidget *file_menu;
    GtkWidget *file_item;
    GtkWidget *open_item;
    GtkWidget *save_item;
    GtkWidget *box;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Text Editor");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box);

    menu_bar = gtk_menu_bar_new();
    gtk_box_pack_start(GTK_BOX(box), menu_bar, FALSE, FALSE, 0);

    file_menu = gtk_menu_new();

    open_item = gtk_menu_item_new_with_label("Open");
    g_signal_connect(open_item, "activate", G_CALLBACK(open_file), text_view);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), open_item);

    save_item = gtk_menu_item_new_with_label("Save");
    g_signal_connect(save_item, "activate", G_CALLBACK(save_file), text_view);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), save_item);

    file_item = gtk_menu_item_new_with_label("File");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_item), file_menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), file_item);

    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_box_pack_start(GTK_BOX(box), scrolled_window, TRUE, TRUE, 0);

    text_view = gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}


// #include <gtk/gtk.h>

// static void open_file(GtkWidget *widget, gpointer data) {
//     GtkWidget *dialog;
//     GtkWidget *text_view = GTK_WIDGET(data);
//     GtkTextBuffer *buffer;
//     GtkTextIter start, end;

//     dialog = gtk_file_chooser_dialog_new("Open File",
//                                          GTK_WINDOW(gtk_widget_get_toplevel(widget)),
//                                          GTK_FILE_CHOOSER_ACTION_OPEN,
//                                          "_Cancel", GTK_RESPONSE_CANCEL,
//                                          "_Open", GTK_RESPONSE_ACCEPT,
//                                          NULL);

//     if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
//         char *filename;
//         char *content;
//         gsize length;
//         GError *error = NULL;

//         filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));

//         if (g_file_get_contents(filename, &content, &length, &error)) {
//             buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
//             gtk_text_buffer_set_text(buffer, content, length);
//             g_free(content);
//         } else {
//             g_print("Error: %s\n", error->message);
//             g_error_free(error);
//         }

//         g_free(filename);
//     }

//     gtk_widget_destroy(dialog);
// }

// static void save_file(GtkWidget *widget, gpointer data) {
//     GtkWidget *dialog;
//     GtkWidget *text_view = GTK_WIDGET(data);
//     GtkTextBuffer *buffer;
//     GtkTextIter start, end;

//     dialog = gtk_file_chooser_dialog_new("Save File",
//                                          GTK_WINDOW(gtk_widget_get_toplevel(widget)),
//                                          GTK_FILE_CHOOSER_ACTION_SAVE,
//                                          "_Cancel", GTK_RESPONSE_CANCEL,
//                                          "_Save", GTK_RESPONSE_ACCEPT,
//                                          NULL);

//     gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(dialog), TRUE);

//     if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
//         char *filename;
//         gchar *content;
//         GError *error = NULL;

//         filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));

//         buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
//         gtk_text_buffer_get_bounds(buffer, &start, &end);
//         content = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

//         if (!g_file_set_contents(filename, content, -1, &error)) {
//             g_print("Error: %s\n", error->message);
//             g_error_free(error);
//         }

//         g_free(content);
//         g_free(filename);
//     }

//     gtk_widget_destroy(dialog);
// }

// static void activate(GtkApplication *app, gpointer user_data) {
//     GtkWidget *window;
//     GtkWidget *text_view;
//     GtkWidget *scrolled_window;
//     GtkWidget *menu_bar;
//     GtkWidget *file_menu;
//     GtkWidget *file_item;
//     GtkWidget *open_item;
//     GtkWidget *save_item;
//     GtkWidget *box;

//     window = gtk_application_window_new(app);
//     gtk_window_set_title(GTK_WINDOW(window), "Text Editor");
//     gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);

//     box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
//     gtk_container_add(GTK_CONTAINER(window), box);

//     menu_bar = gtk_menu_bar_new();
//     gtk_box_pack_start(GTK_BOX(box), menu_bar, FALSE, FALSE, 0);

//     file_menu = gtk_menu_new();

//     open_item = gtk_menu_item_new_with_label("Open");
//     g_signal_connect(open_item, "activate", G_CALLBACK(open_file), text_view);
//     gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), open_item);

//     save_item = gtk_menu_item_new_with_label("Save");
//     g_signal_connect(save_item, "activate", G_CALLBACK(save_file), text_view);
//     gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), save_item);

//     file_item = gtk_menu_item_new_with_label("File");
//     gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_item), file_menu);
//     gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), file_item);

//     scrolled_window = gtk_scrolled_window_new(NULL, NULL);
//     gtk_box_pack_start(GTK_BOX(box), scrolled_window, TRUE, TRUE, 0);

//     text_view = gtk_text_view_new();
//     gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);

//     gtk_widget_show_all(window);
// }

// int main(int argc, char **argv) {
//     GtkApplication *app;
//     int status;

//     app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
//     g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
//     status = g_application_run(G_APPLICATION(app), argc, argv);
//     g_object_unref(app);

//     return status;
// }
