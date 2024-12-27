/*#include <gtk/gtk.h>
static void print_hello (GtkWidget *widget,gpointer   data){
  g_print ("Hello World\n");
}
static void activate(GtkApplication* app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), " KOMODO App");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
    //gtk_widget_show_all(window);
//  window = gtk_application_window_new (app);
// gtk_window_set_title (GTK_WINDOW (window), "Window");
// gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign (box, GTK_ALIGN_CENTER);

  gtk_window_set_child (GTK_WINDOW (window), box);

  button = gtk_button_new_with_label ("Hello World");

  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window);

  gtk_box_append (GTK_BOX (box), button);

  gtk_window_present (GTK_WINDOW (window));
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.example.desktop", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);// Clean up
    return status;
}*/
#include <gtk/gtk.h>

// static void
// print_hello (GtkWidget *widget,gpointer   data)
// {
//   g_print ("Hello World\n");
// }

// static void
// activate (GtkApplication *app,  gpointer user_data){
//   GtkWidget *window;
//   GtkWidget *button;
//   GtkWidget *box;

//   window = gtk_application_window_new (app);
//   gtk_window_set_title (GTK_WINDOW (window), "Window");
//   gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

//   box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
//   gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
//   gtk_widget_set_valign (box, GTK_ALIGN_CENTER);

//   gtk_window_set_child (GTK_WINDOW (window), box);

//   button = gtk_button_new_with_label ("Hello World");

//   g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
//   g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window);

//   gtk_box_append (GTK_BOX (box), button);

//   gtk_window_present (GTK_WINDOW (window));
// }

// int main (int    argc,char **argv){
//   GtkApplication *app;
//   int status;

//   app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
//   g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
//   status = g_application_run (G_APPLICATION (app), argc, argv);
//   g_object_unref (app);

//   return status;
// }

#include <gtk/gtk.h>

static void show_about_dialog(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;
    GtkWindow *parent = GTK_WINDOW(data);

    dialog = gtk_message_dialog_new(
        parent,
        GTK_DIALOG_DESTROY_WITH_PARENT,
        GTK_MESSAGE_INFO,
        GTK_BUTTONS_OK,
        "This is a simple GTK application."
    );
    gtk_window_set_title(GTK_WINDOW(dialog), "About");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *menu_bar;
    GtkWidget *menu;
    GtkWidget *menu_item;
    GtkWidget *box;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "GTK Menu and Dialog Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box);

    menu_bar = gtk_menu_bar_new();
    gtk_box_pack_start(GTK_BOX(box), menu_bar, FALSE, FALSE, 0);

    menu = gtk_menu_new();

    menu_item = gtk_menu_item_new_with_label("About");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
    g_signal_connect(menu_item, "activate", G_CALLBACK(show_about_dialog), window);

    menu_item = gtk_menu_item_new_with_label("Help");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item), menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_item);

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

