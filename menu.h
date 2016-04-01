#define n_valor 3
#define limpa system("cls")

void sprite(int x,int y){
    gotoxy(x,y);printf("<");
    Sleep(400);
    gotoxy(x,y);printf("%c",4);
    Sleep(400);
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
                gotoxy(31,17);printf(" ");
                sprite(31,15);
            break;
            case 3:
                setColor(14);
                gotoxy(31,15);printf(" ");
                sprite(31,17);
            break;
        }
        if (kbhit()) {
            a=getkey();
			if ((a=='w' || a==KEY_UP)&&valor>1) {
				valor--;
			}else if ((a=='s' || a==KEY_DOWN)&&valor<n_valor) {
				valor++;
			}else if (a==KEY_ENTER) {
				return valor;
				break;
			}
        }
    }
}

void menu(){
    limpa;
    setColor(01);
    setColor(01);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    setColor(01);printf("%c                                                                       %c\n",186,186);
    setColor(01);printf("%c  ",186);
    setColor(14);printf("####### ####### #######     ##   ## ####### ##   ## ####### ##   ##  ");
    setColor(01);printf("%c\n",186);
    setColor(01);printf("%c  ",186);
    setColor(14);printf("##   ## ##   ## ##          ##   ## ##   ## ### ### ##      ### ###  ");
    setColor(01);printf("%c\n",186);
    setColor(01);printf("%c  ",186);
    setColor(14);printf("##   ## ####### ##          ####### ##   ## ####### ####### #######  ");
    setColor(01);printf("%c\n",186);
    setColor(01);printf("%c  ",186);
    setColor(14);printf("####### ##   ## ##     #### ##   ## ##   ## ## # ## ##      ## # ##  ");
    setColor(01);printf("%c\n",186);
    setColor(01);printf("%c  ",186);
    setColor(14);printf("##      ##   ## ##          ##   ## ##   ## ##   ## ##      ##   ##  ");
    setColor(01);printf("%c\n",186);
    setColor(01);printf("%c  ",186);
    setColor(14);printf("##      ##   ## #######     ##   ## ####### ##   ## ####### ##   ##  ");
    setColor(01);printf("%c\n",186);
    setColor(01);printf("%c                                                                       %c\n",186,186);
    setColor(01);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    setColor(15);
    gotoxy(33,13);printf("Jogar PAC-HOMEM");
    gotoxy(33,15);printf("   Creditos");
    gotoxy(33,17);printf(" Sair do Jogo");
}

void creditos(){
	setColor(15);
    printf("Mapa por:\n"
			"Jao1\nJao2\nJao3\n\n"
			"Movimentacao:\n"
			"Ze1\nZe2\nZe3\n\n"
			"IA:\n"
			"Doidin1\nDoidin2\nDoidin3\n\n"
			"Ajuda Tecnica Suprema:\n"
			"Ramon O Sabio (Mestre do Davi)");
}
