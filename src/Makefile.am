bin_PROGRAMS = ejex

ejex_SOURCES = \
	ejex-main.c \
	$(NULL)

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""${datadir}/locale"\" \
	$(GTK_CFLAGS) \
	-I$(top_srcdir)/libgd \
	$(NULL)

AM_CFLAGS = \
	$(WARN_CFLAGS) \
	$(NULL)

ejex_LDFLAGS =

ejex_LDADD = \
	$(GTK_LIBS) \
	$(top_builddir)/libgd/libgd.la \
	$(NULL)

-include $(top_srcdir)/git.mk
