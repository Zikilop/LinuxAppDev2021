#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([hw 07 at 08 leson], [0.0], [zikilop@yandex.ru])
AC_CONFIG_SRCDIR([esub.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign subdir-objects])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([string.h stdio.h regex.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([regcomp regerror regexec strlen])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
