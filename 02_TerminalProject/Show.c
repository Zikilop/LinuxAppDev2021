#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define DX 3
#define ESC 27

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Error input!\n");
        return 0;
    }

    FILE *fd = fopen(argv[1], "r");
    if (!fd){
        printf("Can't open this file!\n");
        return 0;
    }


    WINDOW *win;
    initscr();
    cbreak();
    noecho();

    printw("Filename: %s\n", argv[1]);
    refresh();

    win = newwin(LINES - 2 * DX, COLS - 2 * DX, DX, DX);
    keypad(win, TRUE);
    scrollok (win, TRUE);

    char temp_c = ' ';
    int point = 0;
    size_t len = 1;
    size_t wide = COLS - 2 * DX - 1;

    while(fscanf(fd, "%c", &temp_c) != EOF){
        if(temp_c == '\n'){
            ++len;
        };
    }
    fseek(fd, 0, 0);


    char file[len+1][wide+1];
    for(size_t i = 0; i < len; ++i){
        for (size_t j = 0; j < wide; j++) {
            file[i][j] = '\n';
        }
    }
////////////////////////////////////////////////////////////TEST///////////////////////////////////////////////////////////////////////LONGTEST////////////////////////////////////////VERYLONG////////////
    for(size_t i = 0; i < len; ++i){
        point = 0;
        for(int j = 0; j < wide; j++) {
            fscanf(fd, "%c", &temp_c);
            file[i][point++] = temp_c;
            if(temp_c == '\n'){
                break;
            }
        }
    }
    fclose(fd);

    size_t begin = 0, h = LINES - 3 * DX;
    size_t end = begin + h;
    size_t k;

    while(1){
        werase(win);
        box(win, 0, 0);
        printw("Filename: %s\n", argv[1]);
        for(size_t i = begin; i < end; ++i){
            for (size_t j = 0; j < wide; ++j){
                mvwaddch(win, i+1 - begin, j+1, file[i][j]);
                if(file[i][j] == '\n'){
                    break;
                }
            }
        }
        box(win, 0, 0);
        wrefresh(win);

        k = wgetch(win);
        if(k == ESC){
            break;
        } else if(k == ' '){
            if(end != len){
                begin += 1;
                end += 1;
            }
        }
    }

    endwin();
    return 0;
}
