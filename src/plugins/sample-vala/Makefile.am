modules_flags = -export_dynamic -avoid-version -module

plugindir = $(PLUGINDIR)/sample-vala
#plugin_LTLIBRARIES = libsample-vala.la

plugin_in_files = sample-vala.totem-plugin.in

%.totem-plugin: %.totem-plugin.in $(INTLTOOL_MERGE) $(wildcard $(top_srcdir)/po/*po) ; $(INTLTOOL_MERGE) $(top_srcdir)/po $< $@ -d -u -c $(top_builddir)/po/.intltool-merge-cache

#plugin_DATA = $(plugin_in_files:.totem-plugin.in=.totem-plugin)

%.c %.h: %.vala
	$(VALAC) --vapidir=$(top_srcdir)/bindings/vala --pkg=totem $^

common_defines = \
	-D_REENTRANT					\
	-DDBUS_API_SUBJECT_TO_CHANGE			\
	-DGNOMELOCALEDIR=\""$(datadir)/locale"\"	\
	-DGCONF_PREFIX=\""/apps/totem"\"		\
	-DDATADIR=\""$(datadir)"\"			\
	-DLIBEXECDIR=\""$(libexecdir)"\"		\
	-DBINDIR=\""$(bindir)"\"			\
	-DTOTEM_PLUGIN_DIR=\""$(libdir)/totem/plugins"\"\
	$(DISABLE_DEPRECATED)

libsample_vala_la_SOURCES = \
	totem-sample-vala-plugin.c		\
	totem-sample-vala-plugin.h		\
	totem-sample-vala-plugin.vala
libsample_vala_la_LDFLAGS = $(modules_flags)
libsample_vala_la_LIBADD = $(top_builddir)/lib/libtotemscrsaver.la
libsample_vala_la_CPPFLAGS = $(common_defines)

libsample_vala_la_CFLAGS = \
	$(EXTRA_GNOME_CFLAGS)	\
	$(WARN_CFLAGS)		\
	$(DBUS_CFLAGS)		\
	$(AM_CFLAGS)		\
	-I$(top_srcdir)/lib	\
	-I$(top_srcdir)/src	\
	-I$(top_srcdir)/src/plugins

EXTRA_DIST = $(plugin_in_files)

CLEANFILES = $(plugin_DATA) $(BUILT_SOURCES)
DISTCLEANFILES = $(plugin_DATA)