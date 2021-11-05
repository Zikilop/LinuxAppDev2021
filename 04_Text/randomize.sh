#!/bin/bash
timer_s=0
if [ $# -ge 1 ]; then timer_s=$1; fi
hex_text=$(od -A n -t x1 -v)
SPACE=20
ENTER=0a
x=0
y=0
mas=''
for c in $hex_text; do
	if [ $c = $SPACE ]; then
		x=$(($x+1))
	fi
	if [ $c = $ENTER ]; then
		x=0
		y=$(($y+1))
	fi
	if [ $c != $ENTER ] && [ $c != $SPACE ]; then
		mas+="$y $x $c\n"
		x=$(($x+1))
	fi
done
shuf_text=$(echo -e "$mas" | shuf)
tput clear
echo "$shuf_text" | while read x y c; do
	if [[ $c != "" ]]; then
		tput cup $x $y
		echo -ne "\x$c"
	fi	
	if [ $timer_s != 0 ]; then sleep $timer_s; fi
done
tput cup $(tput lines) 0
