bin_PROGRAMS = ejex

ejex_SOURCES = \
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
	$(AM_CFLAGS) \
	$(NULL)

ejex_LDFLAGS =

ejex_LDADD = \
	$(GTK_LIBS) \
	$(NULL)

-include $(top_srcdir)/git.mk
