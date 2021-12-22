GEN = range *_logger 

range: range.c
	gcc -O0 -g $^ -o range

test: sc_1 sc_2
	cmp sc_1_logger test1.txt
	cmp sc_2_logger test2.txt

sc_% : range script_%
	cgdb -x script_$* ./range
	cat script_$*_logger | grep "@@@" | tr -d "@" > sc_$*_logger

clean:
	rm $(GEN)
