AC_INIT([Ejex],
        [0.0.1],
        [],
        [ejex],
        [])
AC_PREREQ(2.63)

AC_CONFIG_AUX_DIR([config])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src])

m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

AM_INIT_AUTOMAKE([dist-xz no-dist-gzip serial-tests tar-ustar])
AM_MAINTAINER_MODE([enable])

AC_PROG_CC
AC_PROG_CC_C_O
AC_HEADER_STDC

AC_CHECK_LIBM
AC_SUBST(LIBM)

GLIB_GSETTINGS

GTK_MIN_VERSION=3.12

GNOME_COMPILE_WARNINGS([maximum])
GNOME_DEBUG_CHECK
GNOME_MAINTAINER_MODE_DEFINES

IT_PROG_INTLTOOL([0.50.1])

GETTEXT_PACKAGE=AC_PACKAGE_TARNAME
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED([GETTEXT_PACKAGE], ["$GETTEXT_PACKAGE"],
                   [GETTEXT package name])
AM_GLIB_GNU_GETTEXT

LT_INIT

PKG_CHECK_MODULES(GTK, [gtk+-3.0 >= $GTK_MIN_VERSION gupnp-1.0])
PKG_CHECK_MODULES(GUPNP, [gupnp-1.0 gssdp-1.0])

AC_ARG_VAR([DESKTOP_FILE_VALIDATE], [the desktop-file-validate program])
AC_PATH_PROG([DESKTOP_FILE_VALIDATE], [desktop-file-validate], [])
if test -z "$DESKTOP_FILE_VALIDATE"; then
  AC_MSG_ERROR([desktop-file-validate not found])
fi

AC_CONFIG_FILES([
Makefile
data/Makefile
data/org.alvaropg.Ejex.desktop.in
src/Makefile
po/Makefile.in
])
AC_OUTPUT
