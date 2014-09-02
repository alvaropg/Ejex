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

#ifndef __EJEX_APPLICATION_WINDOW_H__
#define __EJEX_APPLICATION_WINDOW_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define EJEX_TYPE_APPLICATION_WINDOW             (ejex_application_window_get_type())
#define EJEX_APPLICATION_WINDOW(obj)             (G_TYPE_CHECK_INSTANCE_CAST((obj),EJEX_TYPE_APPLICATION_WINDOW,EjexApplicationWindow))
#define EJEX_APPLICATION_WINDOW_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST((klass),EJEX_TYPE_APPLICATION_WINDOW,EjexApplicationWindowClass))
#define EJEX_IS_APPLICATION_WINDOW(obj)          (G_TYPE_CHECK_INSTANCE_TYPE((obj),EJEX_TYPE_APPLICATION_WINDOW))
#define EJEX_IS_APPLICATION_WINDOW_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE((klass),EJEX_TYPE_APPLICATION_WINDOW))
#define EJEX_APPLICATION_WINDOW_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS((obj),EJEX_TYPE_APPLICATION_WINDOW,EjexApplicationWindowClass))

typedef struct _EjexApplicationWindow        EjexApplicationWindow;
typedef struct _EjexApplicationWindowClass   EjexApplicationWindowClass;
typedef struct _EjexApplicationWindowPrivate EjexApplicationWindowPrivate;

struct _EjexApplicationWindow {
        GtkApplicationWindow parent;
        EjexApplicationWindowPrivate *priv;
};

struct _EjexApplicationWindowClass {
        GtkApplicationWindowClass parent_class;
};

GType        ejex_application_window_get_type    (void) G_GNUC_CONST;

GtkWidget*   ejex_application_window_new         (GtkApplication *application);

G_END_DECLS

#endif /* __EJEX_APPLICATION_WINDOW_H__ */
