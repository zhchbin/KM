// Practice code from: http://zetcode.com/tutorials/gtktutorial/firstprograms/
//
// Compile and run:
//   gcc filename -o executable_file `pkg-config --libs --cflags gtk+-2.0`
//   ./executable_file

#include <gtk/gtk.h>

gint count = 0;
char buf[5];

void increase(GtkWidget* widget, gpointer label) {
  count++;
  sprintf(buf, "%d", count);
  gtk_label_set_text(GTK_LABEL(label), buf);
}

void decrease(GtkWidget* widget, gpointer label) {
  count--;
  sprintf(buf, "%d", count);
  gtk_label_set_text(GTK_LABEL(label), buf);
}

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  GtkWidget *window, *frame, *plus_btn, *minus_btn, *label;
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "+-");
  gtk_window_set_default_size(GTK_WINDOW(window), 230, 150);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  frame = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window), frame);

  plus_btn = gtk_button_new_with_label("+");
  gtk_widget_set_size_request(plus_btn, 80, 35);
  gtk_fixed_put(GTK_FIXED(frame), plus_btn, 50, 20);

  minus_btn = gtk_button_new_with_label("-");
  gtk_widget_set_size_request(minus_btn, 80, 35);
  gtk_fixed_put(GTK_FIXED(frame), minus_btn, 50, 80);

  label = gtk_label_new("0");
  gtk_fixed_put(GTK_FIXED(frame), label, 190, 58);

  gtk_widget_show_all(window);
  
  g_signal_connect_swapped(G_OBJECT(window),
                           "destroy",
                           G_CALLBACK(gtk_main_quit),
                           NULL);
  g_signal_connect(plus_btn, "clicked", G_CALLBACK(increase), label);
  g_signal_connect(minus_btn, "clicked", G_CALLBACK(decrease), label);

  gtk_main();
  return 0;
}
