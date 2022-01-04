#include <stdio.h>
#include <string.h>
#include <rhash.h>
#include "config.h"

#ifdef BOO
#include <stdbool.h>
#else
#define bool int
#define true 1
#define false 0
#endif

#ifdef READL
#include <readline/readline.h>
#endif

int HASHING, CODE;

bool check_mode(char* mode){
	if(strcmp(mode, "MD5") == 0){
		HASHING = RHASH_MD5;
		CODE = RHPR_HEX;
		return true;
	} else if(strcmp(mode, "md5") == 0){
		HASHING = RHASH_MD5;
		CODE = RHPR_BASE64;
		return true;
	} else if(strcmp(mode, "SHA1") == 0){
		HASHING = RHASH_SHA1;
		CODE = RHPR_HEX;
		return true;	
        } else if(strcmp(mode, "sha1") == 0){
		HASHING = RHASH_SHA1;
		CODE = RHPR_BASE64;
		return true;
	} else if(strcmp(mode, "TTH") == 0){
		HASHING = RHASH_TTH;
		CODE = RHPR_HEX;
		return true;
        } else if(strcmp(mode, "tth") == 0){
		HASHING = RHASH_TTH;
		CODE = RHPR_BASE64;
		return true;
        } else {
		return false;
	}
}

int main(int argc, char *argv[]){
	if(argc != 1){
		fprintf(stderr, "error: no need argv\n");
		return 1;
	}

	const char* msg = "message digest";
	char digest[64];
	char output[130];
	int res;

	FILE *stream = stdin;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	char *mode, *hstring;

	rhash_library_init();  
#ifdef READL
	while((line = readline(NULL)) != NULL){
#else	
	while((nread = getline(&line, &len, stream)) != -1){
#endif	
		mode = strtok(line, " ");
		if(mode == NULL){
			fprintf(stderr, "error: need <mode> <str//file>\n");
			continue;
		}

		hstring = strtok(NULL, " \n");
		if(hstring == NULL){
			fprintf(stderr, "error: need <mode> <str//file>\n");
			continue;
		}

		if(check_mode(mode)){
			if(hstring[0] == '"'){
				hstring++;
				res = rhash_msg(HASHING, hstring, strlen(hstring), digest);
			} else {
				res = rhash_file(HASHING, hstring, digest);
			}

			if(res < 0){
				fprintf(stderr, "message digest calculation error\n");
				continue;
			} else {
				rhash_print_bytes(output, digest, rhash_get_digest_size(HASHING), (CODE));
				printf("%s\n", output);
			}
		} else {
			fprintf(stderr, "error: incorrect <mode>\n");
			continue;
		}
	}
	return 0;
}
