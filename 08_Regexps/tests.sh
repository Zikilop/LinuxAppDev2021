./esub "([[:alnum:]]+)@([[:alnum:]]+)\.([[:alnum:]]+)" "adress = \0\\\\ domain = \2\\\\ name = \1\\\\" "zikilop@yandex.ru" > test1.prog
echo 'zikilop@yandex.ru' | sed -E 's/([[:alnum:]]+)@([[:alnum:]]+)\.([[:alnum:]]+)/adress = \0\\ domain = \2\\ name = \1\\/' > test1.orig
cmp test1.prog test1.orig

./esub "([[:alnum:]]+)@([[:alnum:]]+)\.([[:alnum:]]+)" "adress = \0; domain = \2; name = \1;" "zikilop@yandexru" > test2.nomatch
echo "No match" > test2.check
cmp test2.nomatch test2.check

./esub "([[:alnum:]]+)@([[:alnum:]]+)\.([[:alnum:]]+)" "adress = \0; domain = \2; name = \1;\\" "zikilop@yandexru" 2> test3.bs
echo "invalid \ at the end" > test3.check
cmp test3.bs test3.check

./esub "([[:alnum:]]+)@([[:alnum:]]+)\.([[:alnum:]]+" "adress = \0; domain = \2; name = \1;" "zikilop@yandexru" 2> test4.compile
echo "compile error: Unmatched ( or \(" > test4.check
cmp test4.compile test4.check

./esub "([[:alnum:]]+)@([[:alnum:]]+)\.([[:alnum:]]+)" "adress = \0; domain = \2; \3\3" "zikilop@yandex.ru" > test5.end
echo 'zikilop@yandex.ru' | sed -E 's/([[:alnum:]]+)@([[:alnum:]]+)\.([[:alnum:]]+)/adress = \0; domain = \2; \3\3/' > test5.orig
cmp test5.end test5.orig

./esub "([[:alnum:]]+)@([[:alnum:]]+)\.([[:alnum:]]+)" "adress = \0; domain = \40;" "zikilop@yandex.ru" 2> test6.pocket
echo "invalid reference '\4'" > test6.check
cmp test6.pocket test6.check
