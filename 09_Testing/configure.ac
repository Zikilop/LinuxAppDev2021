#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([hw 8(09)], [0.00], [zikilop@yandex.ru])
AM_INIT_AUTOMAKE([foreign])
LT_INIT([disable-static])
AC_CONFIG_SRCDIR([src/buf.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Joint pkgconfig library/include tests
PKG_CHECK_MODULES([CHECK],check)

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stddef.h stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC

AC_ARG_ENABLE([gcov],
	      [AS_HELP_STRING([--enable-gcov], [gcov ON])],
	      [], [enable_gcov=no])

AM_CONDITIONAL([COND_GCOV],[test '!' "$enable_gcov" = no])

AC_CONFIG_FILES([Makefile 
		 src/Makefile
		 tests/Makefile])

AC_OUTPUT
