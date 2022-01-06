#include <regex.h>
#include <stdio.h>
#include <string.h>
#include "config.h"

#define PM 10

int main(int argc, char *argv[]){
	if(argc != 4){
		fprintf (stderr, "Usage: ./esub <regexp> <substitution> <string>\n");
		return 4;
	}
	char *regexp = argv[1], *substitution = argv[2], *string = argv[3];
	regex_t regex;
	regmatch_t  pmatch[PM];
	int regres, i;
	int int_ch;
	char errbuf[256];
	// some kostil
	if(strlen(substitution) != 1 && substitution[strlen(substitution) - 1] == '\\' && substitution[strlen(substitution) - 2] != '\\'){
		fprintf(stderr, "invalid \\ at the end\n");
		return 1;
	}
	if((regres = regcomp(&regex, regexp, REG_EXTENDED))){
		regerror(regres, &regex, errbuf, sizeof(errbuf));
		fprintf(stderr, "compile error: %s\n", errbuf);
		return 1;
	}
	if(!(regres = regexec(&regex, string, PM, pmatch, 0))){
		for(i = 0; i < pmatch[0].rm_so; ++i) printf("%c", string[i]);
		for(i = 0; i < strlen(substitution) - 1; ++i){
			int_ch = (int)substitution[i + 1] - (int)'0';
			if(substitution[i] == '\\'){
				if(substitution[i + 1] == '\\'){
					printf("\\");
					++i;
				} else if(int_ch <= 9 || int_ch >= 0){
					if(pmatch[int_ch].rm_so < 0){
						fprintf(stderr, "invalid reference '\\%c'\n", substitution[i + 1]);
						return 1;
					} else {
						for(int j = pmatch[int_ch].rm_so; j < pmatch[int_ch].rm_eo; ++j) printf("%c", string[j]);
						++i;
					}
				}
			} else {
				printf("%c", substitution[i]);
			}
		}
		if(i == strlen(substitution) - 1) printf("%c", substitution[i]);
		for(i = pmatch[0].rm_eo; i < strlen(string); ++i) printf("%c", string[i]);
		printf("\n");
	} else if(regres == REG_NOMATCH){
		printf("No match\n");
	} else {
		regerror(regres, &regex, errbuf, sizeof(errbuf));
		fprintf(stderr, "regexec error: %s\n", errbuf);
	}
	regfree(&regex);
	return 0;
}
