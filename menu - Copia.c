#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define tx 22
#define n_valor 2
#define limpa system("cls")

void gotoxy(int x,int y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

void opcoes(){
    int valor=1;
    while(1){
        switch(valor){
            case 1:
                sprite(33,13);
                gotoxy(33,15);
            break;

        }

    }

}
void sprite(int x,int y){
    gotoxy(x,y);printf("<");
    Sleep(500);
    gotoxy(x,y);printf("%c",4);
    Sleep(500);
}

void menu(){
    limpa;
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("%c                                                                       %c\n",186,186);
    printf("%c  ####### ####### #######     ##   ## ####### ##   ## ####### ##   ##  %c\n",186,186);
    printf("%c  ##   ## ##   ## ##          ##   ## ##   ## ### ### ##      ### ###  %c\n",186,186);
    printf("%c  ##   ## ####### ##          ####### ##   ## ####### ####### #######  %c\n",186,186);
    printf("%c  ####### ##   ## ##     #### ##   ## ##   ## ## # ## ##      ## # ##  %c\n",186,186);
    printf("%c  ##      ##   ## ##          ##   ## ##   ## ##   ## ##      ##   ##  %c\n",186,186);
    printf("%c  ##      ##   ## #######     ##   ## ####### ##   ## ####### ##   ##  %c\n",186,186);
    printf("%c                                                                       %c\n",186,186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(33,13);printf("Jogar PAC-HOMEM");
    gotoxy(33,15);printf(" Sair do Jogo");
    getch();
}

int main () {
    menu();

return 0;
}
