/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* 
 * Copyright (C) 2007 Bastien Nocera <hadess@hadess.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * The Totem project hereby grant permission for non-gpl compatible GStreamer
 * plugins to be used and distributed together with GStreamer and Totem. This
 * permission are above and beyond the permissions granted by the GPL license
 * Totem is covered by.
 *
 * Monday 7th February 2005: Christian Schaller: Add excemption clause.
 * See license_change file for details.
 *
 */

#include "config.h"

#include <glib.h>
#include <glib-object.h>
#include <glib/gi18n-lib.h>
#include <gmodule.h>
#include <string.h>

#include "totem-plugin.h"
#include "totem.h"

#define TOTEM_TYPE_SIDEBAR_TEST_PLUGIN		(totem_sidebar_test_plugin_get_type ())
#define TOTEM_SIDEBAR_TEST_PLUGIN(o)		(G_TYPE_CHECK_INSTANCE_CAST ((o), TOTEM_TYPE_SIDEBAR_TEST_PLUGIN, TotemSidebarTestPlugin))
#define TOTEM_SIDEBAR_TEST_PLUGIN_CLASS(k)	(G_TYPE_CHECK_CLASS_CAST((k), TOTEM_TYPE_SIDEBAR_TEST_PLUGIN, TotemSidebarTestPluginClass))
#define TOTEM_IS_SIDEBAR_TEST_PLUGIN(o)		(G_TYPE_CHECK_INSTANCE_TYPE ((o), TOTEM_TYPE_SIDEBAR_TEST_PLUGIN))
#define TOTEM_IS_SIDEBAR_TEST_PLUGIN_CLASS(k)	(G_TYPE_CHECK_CLASS_TYPE ((k), TOTEM_TYPE_SIDEBAR_TEST_PLUGIN))
#define TOTEM_SIDEBAR_TEST_PLUGIN_GET_CLASS(o)	(G_TYPE_INSTANCE_GET_CLASS ((o), TOTEM_TYPE_SIDEBAR_TEST_PLUGIN, TotemSidebarTestPluginClass))

typedef struct
{
	TotemPlugin   parent;
} TotemSidebarTestPlugin;

typedef struct
{
	TotemPluginClass parent_class;
} TotemSidebarTestPluginClass;


G_MODULE_EXPORT GType register_totem_plugin		(GTypeModule *module);
GType	totem_sidebar_test_plugin_get_type		(void) G_GNUC_CONST;

static void totem_sidebar_test_plugin_init		(TotemSidebarTestPlugin *plugin);
static void totem_sidebar_test_plugin_finalize		(GObject *object);
static void impl_activate				(TotemPlugin *plugin, TotemObject *totem);
static void impl_deactivate				(TotemPlugin *plugin, TotemObject *totem);

TOTEM_PLUGIN_REGISTER(TotemSidebarTestPlugin, totem_sidebar_test_plugin)

static void
totem_sidebar_test_plugin_class_init (TotemSidebarTestPluginClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);
	TotemPluginClass *plugin_class = TOTEM_PLUGIN_CLASS (klass);

	object_class->finalize = totem_sidebar_test_plugin_finalize;

	plugin_class->activate = impl_activate;
	plugin_class->deactivate = impl_deactivate;
}

static void
totem_sidebar_test_plugin_init (TotemSidebarTestPlugin *plugin)
{
}

static void
totem_sidebar_test_plugin_finalize (GObject *object)
{
	G_OBJECT_CLASS (totem_sidebar_test_plugin_parent_class)->finalize (object);
}

static void
impl_activate (TotemPlugin *plugin,
	       TotemObject *totem)
{
	GtkWidget *label;

	label = gtk_label_new ("This is a test sidebar main widget");
	gtk_widget_show (label);
	totem_add_sidebar_page (totem,
				"sidebar-test",
				"Sidebar Test",
				label);
	g_message ("Just added a test sidebar");
}

static void
impl_deactivate	(TotemPlugin *plugin,
		 TotemObject *totem)
{
	totem_remove_sidebar_page (totem, "sidebar-test");
	g_message ("Just removed a test sidebar");
}
