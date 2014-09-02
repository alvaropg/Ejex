/*
 * Ejex - Axis camera browser application for GNOME
 * Copyright © 2014 Álvaro Peña <alvaropg@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#include "config.h"

#include <glib/gi18n.h>

#include "ejex-application-window.h"

#define WINDOW_MIN_WIDTH 600
#define WINDOW_MIN_HEIGHT 400

static void ejex_application_window_class_init (EjexApplicationWindowClass *klass);
static void ejex_application_window_init       (EjexApplicationWindow *self);

struct _EjexApplicationWindowPrivate {
        gchar *title;
};

G_DEFINE_TYPE_WITH_PRIVATE (EjexApplicationWindow, ejex_application_window, GTK_TYPE_APPLICATION_WINDOW);

static void
ejex_application_window_class_init (EjexApplicationWindowClass *klass)
{
}

static void
ejex_application_window_init (EjexApplicationWindow *self)
{
        GtkWidget *widget;

        widget = gtk_header_bar_new ();
        gtk_header_bar_set_title (GTK_HEADER_BAR (widget), "Ejex");
        gtk_header_bar_set_show_close_button (GTK_HEADER_BAR (widget), TRUE);

        gtk_window_set_titlebar (GTK_WINDOW (self), widget);
        gtk_widget_show (widget);
}

GtkWidget*
ejex_application_window_new (GtkApplication *application)
{
	return GTK_WIDGET (g_object_new (EJEX_TYPE_APPLICATION_WINDOW,
                                         "application", application,
                                         "title", _(PACKAGE_NAME),
                                         "width_request", WINDOW_MIN_WIDTH,
                                         "height_request", WINDOW_MIN_HEIGHT,
                                         "window-position", GTK_WIN_POS_CENTER,
                                         NULL));
}
