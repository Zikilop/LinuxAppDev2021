SUBDIRS = src tests

gcov: check
	$(MAKE) $(MAKEFLAGS) -C src gcov

distclean:
	find . ! -name buf.c ! -name buf.h ! -name libbuf.c ! -name Makefile.am ! -name configure.ac ! -name Makefile.am ! -name test1.ts ! -name test2.ts ! -name test3.ts ! -name test4.ts ! -name test5.ts ! -name Makefile.am ! -name src ! -name tests -delete
