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

#include <libgupnp/gupnp-control-point.h>
#include <string.h>

#include "ejex-discover.h"

struct _EjexDiscoverPrivate {
	GUPnPContext *context;
};

G_DEFINE_TYPE_WITH_PRIVATE (EjexDiscover, ejex_discover, G_TYPE_OBJECT)


static void
ejex_discover_class_init(__attribute__ ((unused)) EjexDiscoverClass *klass)
{
}

static void
ejex_discover_init(EjexDiscover *self)
{
	self->priv = ejex_discover_get_instance_private (self);

	self->priv->context = gupnp_context_new (NULL, NULL, 0, NULL);
}

static void
device_proxy_available_cb (__attribute__ ((unused)) GUPnPControlPoint *cp, GUPnPDeviceProxy *proxy,__attribute__ ((unused)) gpointer user_data)
{
	gchar *manufacturer;

	manufacturer = gupnp_device_info_get_manufacturer (GUPNP_DEVICE_INFO (proxy));

	if (strcmp(manufacturer, "AXIS") != 0)
		return;

	g_print ("Found: %s\n", gupnp_device_info_get_friendly_name (GUPNP_DEVICE_INFO (proxy)));
}

EjexDiscover*
ejex_discover_new (void)
{
	return EJEX_DISCOVER (g_object_new (EJEX_TYPE_DISCOVER, NULL));
}

void
ejex_discover_launch_async (EjexDiscover *self)
{
	GUPnPControlPoint *cp;

	g_return_if_fail (EJEX_IS_DISCOVER (self));

	cp = gupnp_control_point_new (self->priv->context, "urn:schemas-upnp-org:device:Basic:1");
	g_signal_connect (cp, "device-proxy-available", G_CALLBACK (device_proxy_available_cb), NULL);
	gssdp_resource_browser_set_active (GSSDP_RESOURCE_BROWSER (cp), TRUE);
}
