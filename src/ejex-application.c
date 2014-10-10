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

#include "ejex-application.h"
#include "ejex-application-window.h"
#include "ejex-camera.h"
#include "ejex-discover.h"

static void ejex_application_class_init (EjexApplicationClass *klass);
static void ejex_application_init       (EjexApplication      *self);
static void ejex_application_activate   (GApplication         *application);

static void ejex_application_camera_available_cb (EjexCamera *camera, gpointer user_data);
static void ejex_application_populate_store (EjexApplication *self);

struct _EjexApplicationPrivate {
        EjexDiscover *discover;
        GtkWidget *window;
        guint32 activation_timestamp;
        GHashTable *camera_hash;
};

enum {
        COLUMN_NAME,
        COLUMN_IP,
        COLUMN_WIDGET,
        N_COLUMNS
};


G_DEFINE_TYPE_WITH_CODE (EjexApplication, ejex_application, GTK_TYPE_APPLICATION, G_ADD_PRIVATE (EjexApplication));

static void
ejex_application_class_init (EjexApplicationClass *klass)
{
        GApplicationClass *application_class = G_APPLICATION_CLASS (klass);

        application_class->activate = ejex_application_activate;
}

static void
ejex_application_init (EjexApplication *self)
{
        EjexApplicationPrivate *priv = ejex_application_get_instance_private(self);

        priv->window = NULL;
        priv->activation_timestamp = GDK_CURRENT_TIME;
        priv->discover = ejex_discover_new ();
        ejex_application_populate_store (self);
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

        /* TODO: implement cancellable pattern  */
        ejex_discover_launch_async (priv->discover, ejex_application_camera_available_cb, self);
}

static void
ejex_application_camera_available_cb (EjexCamera *camera, gpointer user_data)
{
        gchar *sn;
        EjexApplicationPrivate *priv = ejex_application_get_instance_private (EJEX_APPLICATION (user_data));

        sn = ejex_camera_get_sn (camera);
        if (sn == NULL)
                g_warning ("Detected a camera without a serial number\n");
        else
                if (g_hash_table_insert (priv->camera_hash, sn, camera) == FALSE)
                        g_info ("Camera %s already detected\n", sn);
                else
                        g_message ("Inserted %s\n", sn);
}

static void
ejex_application_populate_store (EjexApplication *self)
{
        EjexApplicationPrivate *priv = ejex_application_get_instance_private(self);

        priv->camera_hash = g_hash_table_new (g_str_hash, g_str_equal);
}

GtkApplication*
ejex_application_new (void)
{
        return GTK_APPLICATION (g_object_new (EJEX_TYPE_APPLICATION, NULL));
}
