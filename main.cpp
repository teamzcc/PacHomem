#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include "utils.h"
#include "abre_mapa.h"
#include "Personagem.h"
#include "Fantasma.h"
#include "menu.h"

#define max_score 188
#define num_fantasmas 4

int jogo(int *score,int n_partida){
    system("cls");
    int y0=25;
    int i,j;
    int rx=10,ry=20;
    int powerup=0,endgame=0,score_tmp=(*score),gifi = 0, gifif=0,teclapertada,ciclospowerup=0;

    char mapa[tx][ty];
    gera_mapa(mapa);

    personagem pac_man=cria_personagem(pac_man,260,118,94,60,62,9,16,0,14,440);

    personagem fantasma[num_fantasmas];
    fantasma[0]=cria_personagem(fantasma[0],'A','A','A','A','A',9,8,1,12,0);
    for(i=1;i<num_fantasmas;i++){
		fantasma[i]=cria_personagem(fantasma[i],'A','A','A','A','A',7+i,10,0,15,0);
    }
    fantasma[1].cor=2;
    fantasma[2].cor=13;
    fantasma[3].cor=11;

    int raios[4][num_fantasmas];
    for(i=0;i<2;i++){
		for(j=0;j<num_fantasmas;j++){
			raios[i][j]=(2*j+2)+(2*n_partida-2);
			raios[2][j]=0;
			raios[3][j]=0;
		}
    }
    raios[2][0]=2;

    gotoxy( pac_man.px,pac_man.py );printf("%c",pac_man.sprite[0]);

    while((score_tmp)<max_score*n_partida){
		setColor(15);
        gotoxy(0,22);printf("Pontuacao: %d/%d %d",score_tmp,max_score*n_partida, powerup);
        //Sleep(150);

		if(powerup==1){
			ciclospowerup++;
			if(ciclospowerup>30){
				powerup=0;
				ciclospowerup=0;
			}
		}

		//MOVIMENTAÇÃO PAC-MAN
        if(kbhit()){
			teclapertada = getkey();
			muda_sentido(&pac_man,teclapertada,mapa);
        }

        rastro(pac_man,mapa);
        if(!colisao_parede(pac_man,mapa)){
            movimento(&pac_man);
            atualiza_matriz(pac_man,mapa,&score_tmp, &powerup);
            rastro(pac_man,mapa);
        }
        setColor(14);
        gif(&gifi,pac_man);
        setColor(15);
        Beep(pac_man.sound,150);
        for(i=0;i<num_fantasmas;i++){
			if(colisao_fantasma(pac_man,fantasma[i],powerup)==1){
				score_tmp=0;
				return 0;
			}else{
				if(colisao_fantasma(pac_man,fantasma[i],powerup)==2){
					fantasma[i].px=9;
					fantasma[i].py=10;
					raios[2][i]=1;
					raios[3][i]=0;
				}
			}
        }

		for(i=0;i<num_fantasmas;i++){
        	if(raios[3][i]==15 && raios[2][i]==1){
				raios[3][i]=0;
				raios[2][i]=2;
				fantasma[i].py-=2;
			}else{
				raios[3][i]++;
			}
        }
        //Liberando Fantasmas
        if(score_tmp==47*n_partida && raios[2][1]==0){
			rastro(fantasma[1],mapa);
			fantasma[1].py-=2;
			raios[2][1]=2;
        }else{
        	if(score_tmp==94*n_partida && raios[2][2]==0){
				rastro(fantasma[2],mapa);
				fantasma[2].py-=2;
				raios[2][2]=2;
        	}else{
        		if(score_tmp==141*n_partida && raios[2][3]==0){
					rastro(fantasma[3],mapa);
					fantasma[3].py-=2;
					raios[2][3]=2;
        		}
        	}
        }
        //MOVIMENTAÇÃO FANTASMA
        for(i=0;i<num_fantasmas;i++){
			rastro(fantasma[i],mapa);
			srand(time(NULL));
			fantasma[i].sentido=IA_Sentido(pac_man,fantasma[i],rx,ry);

			/**=========DEBUG MOSTRANDO O RAIO DOS FANTASMAS=========**/
			y0=25;
			for(j=0;j<num_fantasmas;j++){
				mostraRaio(fantasma[j],raios[0][j],raios[1][j],mapa,y0);
				y0=y0+(raios[1][j])+2;
			}
			/**======================================================**/

			while(colisao_parede(fantasma[i],mapa)){
				muda_sentido(&fantasma[i],rand()%5+1,mapa);
			}

			/**TO-DO:
				Algumas vezes, os fantasmas se juntam e andam na mesma posição.
				O Codigo comentado abaixo tenta resolver isso sem sucesso (pra alguns casos desconhecidos)**
			for(j=i+1;j<num_fantasmas;j++){
				if(raios[2][j]==2){
					while(colisao_fantasma(fantasma[i],fantasma[j],0)){
						gotoxy(tx+2,0);
						printf("Fantasma/Fantasma");
						muda_sentido(&fantasma[i],rand()%5+1,mapa);
					}
				}
			}
			/****/
			movimento(&fantasma[i]);
			if(powerup==1){
				setColor(9);
			}else{
				setColor(fantasma[i].cor);
			}
			gif(&gifif,fantasma[i]);
			if(colisao_fantasma(pac_man,fantasma[i],powerup)==1){
				score_tmp=0;
				return 0;
			}else{
				if(colisao_fantasma(pac_man,fantasma[i],powerup)==2){
					fantasma[i].px=9;
					fantasma[i].py=10;
					raios[2][i]=1;
					raios[3][i]=0;
				}
			}
			setColor(15);
			gifif=0;
        }
        /*
        for(i=0;i<num_fantasmas;i++){
        	if(raios[3][i]==15 && raios[2][i]==1){
				raios[3][i]=0;
				raios[2][i]=2;
				fantasma[i].py-=2;
			}else{
				raios[3][i]++;
			}
        }
        //Liberando Fantasmas
        if(score_tmp==5*n_partida && raios[2][1]==0){
			fantasma[1].py-=2;
			raios[2][1]=2;
        }else{
        	if(score_tmp==10*n_partida && raios[2][2]==0){
				fantasma[2].py-=2;
				raios[2][2]=2;
        	}else{
        		if(score_tmp==15*n_partida && raios[2][3]==0){
					fantasma[3].py-=2;
					raios[2][3]=2;
        		}
        	}
        }*/

    }
    (*score)=score_tmp;
    return 1;
}

int main(){
    int score = 0, rodada=1,opcao;

    /*for(int cor = 0;cor < 20;cor++){
		setColor(cor);printf("Cor numero %d\n",cor);
    }*/

	while(1){
		system("cls");
		menu();
		opcao=opcoes();
		system("cls");
		switch(opcao){
			case 1:
				while(jogo(&score,rodada)){
					rodada++;
				}
				break;
			case 2:
				creditos();
				getch();
				break;
			case 3:
				return 0;
		}
	}

    //system("pause");

	gotoxy(0,35);
	getchar();
    return 0;
}
