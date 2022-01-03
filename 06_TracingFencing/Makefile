GEN = safe.so move
TRASH = igoPROTECTed newfile newfile2 killme

test: safe.so move
	ls | cat > igodeleted
	ls | cat > igoPROTECTed
	LD_PRELOAD=./safe.so ./move igodeleted newfile
	LD_PRELOAD=./safe.so ./move igoPROTECTed newfile2
	if [ -f igodeleted ]; then echo "not deleted("; else echo "deleted)"; fi
	if [ -f igoPROTECTed ]; then echo "not deleted)"; else echo "deleted("; fi
	if [ -f newfile ] && [ -f newfile2 ]; then echo "exist)"; else echo "not exist("; fi
	sh tests

move: move.c
	gcc -O0 -g move.c -o move

safe.so: safe.c
	gcc safe.c -shared -ldl -o safe.so

clean:
	rm $(GEN) $(TRASH)
