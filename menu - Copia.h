#define n_valor 2
#define limpa system("cls")

void gotoxy(int x,int y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

void sprite(int x,int y){
    gotoxy(x,y);printf("<");
    Sleep(500);
    gotoxy(x,y);printf("%c",4);
    Sleep(500);
}

int opcoes(){
    int valor=1;
    char a;
    while(1){
        switch(valor){
            case 1:
                setColor(14);
                gotoxy(31,15);printf(" ");
                sprite(31,13);
            break;
            case 2:
                setColor(14);
                gotoxy(31,13);printf(" ");
                sprite(31,15);
            break;
        }
        if (kbhit()) {
            a=getch();
        }
        if (a=='w'&&valor>1) {
            valor--;
        }else if (a=='s'&&valor<n_valor) {
            valor++;
        }else if (a==13) {
            return valor;
            break;
        }
    }
}

void menu(){
    limpa;
    setColor(01);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("%c                                                                       %c\n",186,186);
    printf("%c  ",186);
    printf("####### ####### #######     ##   ## ####### ##   ## ####### ##   ##  ");
    printf("%c\n",186);
    printf("%c  ",186);
    printf("##   ## ##   ## ##          ##   ## ##   ## ### ### ##      ### ###  ");
    printf("%c\n",186);
    printf("%c  ##   ## ####### ##          ####### ##   ## ####### ####### #######  %c\n",186,186);
    printf("%c  ####### ##   ## ##     #### ##   ## ##   ## ## # ## ##      ## # ##  %c\n",186,186);
    printf("%c  ##      ##   ## ##          ##   ## ##   ## ##   ## ##      ##   ##  %c\n",186,186);
    printf("%c  ##      ##   ## #######     ##   ## ####### ##   ## ####### ##   ##  %c\n",186,186);
    printf("%c                                                                       %c\n",186,186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    setColor(15);
    gotoxy(33,13);printf("Jogar PAC-HOMEM");
    gotoxy(33,15);printf(" Sair do Jogo");
}
