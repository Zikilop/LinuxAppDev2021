#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
void help(){
	//double a = 0.001;
	//printf("%f \n", a);
	setlocale(LC_ALL, "Rus");
	//printf("%f \n", a);
	printf("Это хелп!\n");	
	printf("Чтобы запустить программу необходимо ввести параметры командной строки.\n");
	printf("Запуск с одним параметром N -- выводит в столбик последовательность [0, 1, ..., N-1]\n");
	printf("Запуск с двумя параметрами M, N -- выводит в столбик последовательность [M, M+1, ..., N-1]\n");
	printf("Запуск с тремя параметрами M, N, S -- выводит в столбик последовательность [M, M+S, M+2S ..., N-1]\n");
	setlocale(LC_ALL, "");
	//printf("%f \n", a);
	return;
}


int main(int argc, char **argv){
	int M = 0, N = 0, S = 1, i = -1;
	switch(argc){
	case 1:
		help();
		return 0;
	case 2:
		N = atoi(argv[1]);
		break;
	case 3:
		N = atoi(argv[2]);
		M = atoi(argv[1]);
		break;
	case 4:
		N = atoi(argv[2]);
		M = atoi(argv[1]);
		S = atoi(argv[3]);
		break;
	}
	for(i = M; i < N; i += S){
		printf("%d\n", i);
	}
	return 0;
}
