#include <stdio.h>
#include <libintl.h>
#include <locale.h>

const int beg = 1;
const int end = 100;

#define _(string) gettext(string)

int found(int b, int e){
	if(b == e){
		return e;
	}
	char *line = NULL;
	size_t len = 0;
	printf(_("Is it greater than %d?\n"), (int)((b + e)/2));
	printf(_("y or n?\n"));
	if(getline(&line, &len, stdin) != 2 || line[1] != '\n'){
		fprintf(stderr, _("error: wrong input, too many symbols\n"));
		return found(b, e);
	} else {
		if(line[0] ==  *_("y")){
			return found((int)((b + e)/2) + 1, e);
		} else if(line[0] ==  *_("n")){
			return found(b, (int)((b + e)/2));
		} else {
			fprintf(stderr, _("error: wrong input, 1st symbol must be 'y' or 'n'\n"));
			return found(b, e);
		}
	}
	
}

int main(void){
	setlocale(LC_ALL, "");
	bindtextdomain("founder", "po");
	textdomain("founder");
	printf(_("Guess a number from %d to %d\n"), beg, end);
	printf(_("Some abracadabra! Your number is %d!\n"), found(beg, end));
	return 0;
}
