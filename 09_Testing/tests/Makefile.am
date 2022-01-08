TESTS=test1 test2 test3 test4 test5
check_PROGRAMS = test1 test2 test3 test4 test5

AM_CFLAGS = -I$(top_builddir)/src @CHECK_CFLAGS@
LDADD = $(top_builddir)/src/libbuf.la @CHECK_LIBS@

.ts.c:
	checkmk $< > $@
