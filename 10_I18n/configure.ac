#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([hw 9(10)], [0.0.0], [zikilop@yandex.ru])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([./src/founder.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h locale.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([setlocale strcmp])

AC_CONFIG_FILES([Makefile
		 src/Makefile
		 po/Makefile])
AC_OUTPUT
