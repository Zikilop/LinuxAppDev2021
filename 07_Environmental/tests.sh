echo -n 123 | md5sum | awk '{print $1}' > orig1
echo 'MD5 "123' | ./rhasher | tail -n 1 > my1
cmp my1 orig1

echo -n 123 | sha1sum | awk '{print $1}' > orig2
echo 'SHA1 "123' | ./rhasher | tail -n 1 > my2
cmp my2 orig2

md5sum rhasher.c | awk '{print $1}' > origf1
echo 'MD5 rhasher.c' | ./rhasher | tail -n 1 > myf1
cmp myf1 origf1

sha1sum rhasher.c | awk '{print $1}' > origf2
echo 'SHA1 rhasher.c' | ./rhasher | tail -n 1 > myf2
cmp myf2 origf2
