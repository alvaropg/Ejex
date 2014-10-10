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

#ifndef __EJEX_DISCOVER_H__
#define __EJEX_DISCOVER_H__

#include <glib-object.h>

#include <ejex-camera.h>

G_BEGIN_DECLS

#define EJEX_TYPE_DISCOVER             (ejex_discover_get_type())
#define EJEX_DISCOVER(obj)             (G_TYPE_CHECK_INSTANCE_CAST((obj),EJEX_TYPE_DISCOVER,EjexDiscover))
#define EJEX_DISCOVER_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST((klass),EJEX_TYPE_DISCOVER,EjexDiscoverClass))
#define EJEX_IS_DISCOVER(obj)          (G_TYPE_CHECK_INSTANCE_TYPE((obj),EJEX_TYPE_DISCOVER))
#define EJEX_IS_DISCOVER_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE((klass),EJEX_TYPE_DISCOVER))
#define EJEX_DISCOVER_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS((obj),EJEX_TYPE_DISCOVER,EjexDiscoverClass))

typedef struct _EjexDiscover        EjexDiscover;
typedef struct _EjexDiscoverClass   EjexDiscoverClass;
typedef struct _EjexDiscoverPrivate EjexDiscoverPrivate;

struct _EjexDiscover {
        GObject parent;

        EjexDiscoverPrivate *priv;
};

struct _EjexDiscoverClass {
        GObjectClass parent_class;
};

typedef void (*EjexDiscoverCameraAvailableCb) (EjexCamera *camera, gpointer user_data);

GType ejex_discover_get_type (void) G_GNUC_CONST;

EjexDiscover* ejex_discover_new (void);
void          ejex_discover_launch_async (EjexDiscover *self, EjexDiscoverCameraAvailableCb c_handler, gpointer user_data);

G_END_DECLS

#endif /* __EJEX_DISCOVER_H__ */
