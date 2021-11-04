TRASH = *.o *~ o.*
GENERATES = liboutput_static.a liboutput.so prog prog-a prog-so
TEST1 =  
TEST2 = mytest2
TEST3 = 1 + 2

all: prog prog-a prog-so

prog: const.o fun.o prog.o

prog-a: prog.o liboutput_static.a
	cc -L. $^ -o $@

prog.o: outlib.h

liboutput_static.a: const.o fun.o
	ar -rcs $@ $^

fun.o: outlib.h

prog-so: prog_so.o liboutput.so
	cc -L. $< -loutput -o $@

liboutput.so: const_so.o fun_so.o
	cc -shared $^ -o liboutput.so	

%_so.o:    %.c
	cc -fPIC -c -o $@ $<

test: test_1 test_2 test_3

test_%: prog_%.txt prog-a_%.txt prog-so_%.txt
	cmp prog_$*.txt prog-a_$*.txt
	cmp prog-a_$*.txt prog-so_$*.txt

%_1.txt : %
	LD_LIBRARY_PATH=`pwd` /bin/bash -c "(exec -a prog ./$< $(TEST1))" > $@ 2>&1

%_2.txt : %
	LD_LIBRARY_PATH=`pwd` /bin/bash -c "(exec ./$< $(TEST2))" > $@ 2>&1

%_3.txt : %
	LD_LIBRARY_PATH=`pwd` /bin/bash -c "(exec ./$< $(TEST3))" > $@ 2>&1


clean:
	rm -f $(TRASH)

distclean: clean
	rm -rf $(GENERATES)