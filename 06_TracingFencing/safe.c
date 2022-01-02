#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

typedef int (*fclose_type)(FILE *filename);

int fclose(FILE *filename){	
	fclose_type orig_fclose;
	orig_fclose = (fclose_type)dlsym(RTLD_NEXT, "fclose");
	errno = 0;
	orig_fclose(filename);
	if(errno){ perror("fclose fail");}
	return errno;	
}

typedef FILE* (*fopen_type)(const char *fname, const char *modeopen);

FILE* fopen(const char *fname, const char *modeopen){
	fopen_type orig_fopen;
	orig_fopen = (fopen_type)dlsym(RTLD_NEXT, "fopen");
	errno = 0;
	FILE *fd = orig_fopen(fname, modeopen);
	if(fd == NULL){ perror("fopen fail");}
	return fd;
}

typedef int (*remove_type)(const char *pathname);

int remove(const char *pathname){
	remove_type orig_remove;
	orig_remove = (remove_type)dlsym(RTLD_NEXT, "remove");
	if(strstr(pathname, "PROTECT")){
		return 0;
	}
	errno = 0;
	orig_remove(pathname);
	if(errno){ perror("remove fail");}
	return errno;
}

typedef int (*fgetc_type)(FILE *stream);

int fgetc(FILE *stream){
	fgetc_type orig_fgetc;
	orig_fgetc = (fgetc_type)dlsym(RTLD_NEXT, "fgetc");
	int temp = orig_fgetc(stream);
	errno = ferror(stream);
	if(errno){ perror("fgetc fail");}
	return temp;
}

typedef int (*fputc_type)(int c, FILE *stream);

int fputc(int c, FILE *stream){
	fputc_type orig_fputc;
	orig_fputc = (fputc_type)dlsym(RTLD_NEXT, "fputc");
	int temp = orig_fputc(c, stream);
	if(temp == EOF){ perror("fputc fail");}
	return temp;
}
