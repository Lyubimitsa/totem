modules_flags = -export_dynamic -avoid-version -module

plugindir = $(PLUGINDIR)/skipto
uidir = $(plugindir)
plugin_LTLIBRARIES = libskipto.la

plugin_in_files = skipto.totem-plugin.in

%.totem-plugin: %.totem-plugin.in $(INTLTOOL_MERGE) $(wildcard $(top_srcdir)/po/*po) ; $(INTLTOOL_MERGE) $(top_srcdir)/po $< $@ -d -u -c $(top_builddir)/po/.intltool-merge-cache

plugin_DATA = $(plugin_in_files:.totem-plugin.in=.totem-plugin)
ui_DATA = skipto.ui

common_defines = \
	-D_REENTRANT					\
	-DDBUS_API_SUBJECT_TO_CHANGE			\
	-DGNOMELOCALEDIR=\""$(datadir)/locale"\"	\
	-DGCONF_PREFIX=\""/apps/totem"\"		\
	-DDATADIR=\""$(datadir)"\"			\
	-DLIBEXECDIR=\""$(libexecdir)"\"		\
	-DBINDIR=\""$(bindir)"\"			\
	-DTOTEM_PLUGIN_DIR=\""$(libdir)/totem/plugins"\"\
	-DG_LOG_DOMAIN=\""Totem"\"			\
	$(DISABLE_DEPRECATED)

libskipto_la_SOURCES = \
	totem-skipto-plugin.c	\
	totem-skipto-plugin.h	\
	totem-time-entry.c	\
	totem-time-entry.h	\
	totem-skipto.c		\
	totem-skipto.h
libskipto_la_LDFLAGS = $(modules_flags)
libskipto_la_CPPFLAGS = \
	$(common_defines)		\
	-I$(top_srcdir)/src/backend

libskipto_la_CFLAGS = 			\
	$(DEPENDENCY_CFLAGS)		\
	$(PEAS_CFLAGS)			\
	$(WARN_CFLAGS)			\
	$(DBUS_CFLAGS)			\
	$(AM_CFLAGS)			\
	-I$(top_srcdir)/		\
	-I$(top_srcdir)/lib		\
	-I$(top_srcdir)/src		\
	-I$(top_srcdir)/src/plugins	\
	-I$(srcdir)/

EXTRA_DIST = $(plugin_in_files) $(ui_DATA)

CLEANFILES = $(plugin_DATA) $(BUILT_SOURCES)
DISTCLEANFILES = $(plugin_DATA)
