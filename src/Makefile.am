bin_PROGRAMS = ejex

ejex_SOURCES = \
	ejex-discover.c \
	ejex-discover.h \
	ejex-application.c \
	ejex-application.h \
	ejex-application-window.c \
	ejex-application-window.h \
	ejex-main.c \
	$(NULL)

ejex_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""${datadir}/locale"\" \
	$(AM_CPPFLAGS) \
	$(NULL)

ejex_CFLAGS = \
	$(WARN_CFLAGS) \
	$(GTK_CFLAGS) \
	$(GUPNP_CFLAGS) \
	$(AM_CFLAGS) \
	$(NULL)

ejex_LDFLAGS =

ejex_LDADD = \
	$(GTK_LIBS) \
	$(GUPNP_LIBS) \
	$(NULL)

-include $(top_srcdir)/git.mk
