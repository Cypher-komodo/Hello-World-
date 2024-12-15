 #include <gtk-3.0/gdk/gdk.h>    
/*
static void activate(GtkApplication* app, gpointer user_data) {
    GtkWidget *window;
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "My Desktop App");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.example.desktop", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}*/
/*#include <gtk/gtk.h>

// Correct function signature for activate
static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    
    // Create the window
    window = gtk_application_window_new(app);
    
    // Set window properties
    gtk_window_set_title(GTK_WINDOW(window), "My GTK App");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    
    // Show the window
    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    // Initialize the application
    app = gtk_application_new("org.example.desktop", G_APPLICATION_FLAGS_NONE);
    
    // Connect the activate signal
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    
    // Run the application
    status = g_application_run(G_APPLICATION(app), argc, argv);
    
    // Clean up
    g_object_unref(app);

    return status;
}*/

#include <gtk/gtk.h>

static void activate(GtkApplication* app, gpointer user_data) {
    GtkWidget *window;
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "My KOMODO App");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 500);
    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.example.desktop", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}