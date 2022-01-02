#include <stdio.h>
#include <errno.h>


int safe_end(FILE *in, FILE *out, char *out_name, char *del, int delISout){
	int my_err;
	errno = 0;
	if(my_err = fclose(out)){
		fclose(in);
		remove(out_name);
		return my_err;
	}
	errno = 0;
	if(my_err = fclose(in)){
		remove(out_name);
		return my_err;
	}
	errno = 0;
	if(remove(del)){
		my_err = errno;
		if(!delISout){
			remove(out_name);
		}
		return my_err;
	}

	return 0;
}

int main(int argc, char *argv[]){
	if(argc != 3){
		fprintf(stderr, "Few arguments, needed: %s <input> <output>\n", argv[0]);
		return 3;
	}
	int my_err;

	errno = 0;
	FILE *input = fopen(argv[1], "r");
	if(input == NULL){
		return errno;
	}

	errno = 0;
	FILE *output = fopen(argv[2], "w");
	if(output == NULL){
		my_err = errno;
		fclose(input);
		return my_err;
	}

	char c;
	while((c = fgetc(input)) != EOF){
		errno = 0;
		if(fputc(c, output) == EOF){
			my_err = errno;
			safe_end(input, output, argv[2], argv[2], 1);
			return my_err;
		}
	}
	if(errno){
		my_err = errno;
		safe_end(input, output, argv[2], argv[2], 1);
		return my_err;
	}
	return safe_end(input, output, argv[2], argv[1], 0);
}
