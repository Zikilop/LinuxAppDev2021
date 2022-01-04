#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([07(06) hw], [0.0], [zikilop@yandex.ru])
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([rhasher.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_AWK
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([rhash],[rhash_library_init, rhash_msg, rhash_file, rhash_print_bytes], [], [AC_MSG_ERROR([Rhash is needed])])
AC_CHECK_LIB([readline], [readline], [], [])

# Checks for header files.
AC_CHECK_HEADERS([string.h stdio.h readline/readline.h stdbool.h])
AC_CHECK_HEADER([rhash.h], [], [], [AC_MSG_ERROR([rhash.h is needed])])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

# Check --enable options
AC_ARG_ENABLE([readline], 
	      AS_HELP_STRING([--enable-readline], [Change getline 2 readline]),
	      AC_DEFINE(READL, [], [ON readline])
	      )
AC_ARG_ENABLE([bool],
	      AS_HELP_STRING([--enable-bool], [some boolean in C]),
	      AC_DEFINE(BOO,[],[ON bool])
	      )
# Check --without options
AC_ARG_WITH([readline],
	    [AS_HELP_STRING([--without-readline],  [NO readline])], 
	    [], [with_readline=yes])
AS_IF([ test "$with_readline" != "no" ],
      [AC_CHECK_LIB([readline], [readline], [], [AC_MSG_ERROR([Readline is needed])])
	AC_CHECK_HEADER([readline/readline.h], [], [], [AC_MSG_ERROR([readline/readline.h is needed])])])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
