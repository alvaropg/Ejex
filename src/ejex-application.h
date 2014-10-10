/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 8; tab-width: 8 -*- */
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

#ifndef __EJEX_APPLICATION_H__
#define __EJEX_APPLICATION_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define EJEX_TYPE_APPLICATION             (ejex_application_get_type())
#define EJEX_APPLICATION(obj)             (G_TYPE_CHECK_INSTANCE_CAST((obj),EJEX_TYPE_APPLICATION,EjexApplication))
#define EJEX_APPLICATION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST((klass),EJEX_TYPE_APPLICATION,EjexApplicationClass))
#define EJEX_IS_APPLICATION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE((obj),EJEX_TYPE_APPLICATION))
#define EJEX_IS_APPLICATION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE((klass),EJEX_TYPE_APPLICATION))
#define EJEX_APPLICATION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS((obj),EJEX_TYPE_APPLICATION,EjexApplicationClass))

typedef struct _EjexApplication        EjexApplication;
typedef struct _EjexApplicationClass   EjexApplicationClass;
typedef struct _EjexApplicationPrivate EjexApplicationPrivate;

struct _EjexApplication {
        GtkApplication parent;
        EjexApplicationPrivate *priv;
};

struct _EjexApplicationClass {
        GtkApplicationClass parent_class;
};

GType ejex_application_get_type (void) G_GNUC_CONST;

GtkApplication* ejex_application_new (void);

G_END_DECLS

#endif /* __EJEX_APPLICATION_H__ */
