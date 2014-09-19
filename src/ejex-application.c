/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
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

#include "ejex-application.h"
#include "ejex-application-window.h"
#include "ejex-discover.h"

static void ejex_application_class_init (EjexApplicationClass *klass);
static void ejex_application_init       (EjexApplication *obj);
static void ejex_application_activate   (GApplication *application);

struct _EjexApplicationPrivate {
	EjexDiscover *discover;
        GtkWidget *window;
        guint32 activation_timestamp;
};

G_DEFINE_TYPE_WITH_CODE (EjexApplication, ejex_application, GTK_TYPE_APPLICATION, G_ADD_PRIVATE (EjexApplication));

static void
ejex_application_class_init (EjexApplicationClass *klass)
{
        GApplicationClass *application_class = G_APPLICATION_CLASS (klass);

        application_class->activate = ejex_application_activate;
}

static void
ejex_application_init (EjexApplication *obj)
{
        EjexApplicationPrivate *priv = ejex_application_get_instance_private(obj);

        priv->window = NULL;
        priv->activation_timestamp = GDK_CURRENT_TIME;

	priv->discover = ejex_discover_new ();
}

static void
ejex_application_activate (GApplication *application)
{
        EjexApplication *self = EJEX_APPLICATION (application);
        EjexApplicationPrivate *priv = ejex_application_get_instance_private (self);

        if (priv->window == NULL) {
                priv->window = ejex_application_window_new (GTK_APPLICATION (self));
        }

        gtk_window_present_with_time (GTK_WINDOW (priv->window), priv->activation_timestamp);
        priv->activation_timestamp = GDK_CURRENT_TIME;

	ejex_discover_launch_async (priv->discover);
}

GtkApplication*
ejex_application_new (void)
{
        return GTK_APPLICATION (g_object_new (EJEX_TYPE_APPLICATION, NULL));
}
