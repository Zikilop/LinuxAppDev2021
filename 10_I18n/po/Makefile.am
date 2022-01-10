pkgdata_DATA=ru/LC_MESSAGES/founder.mo

ru.po:	messages.pot
	msgmerge -U $@ $<

ru/LC_MESSAGES/founder.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

messages.pot: founder.pot ../src/founder.c
	xgettext -k_ -c ../src/founder.c -o messages.new.pot
	cp founder.pot $@
	msgmerge -U $@ messages.new.pot
