typedef struct personagem_s{
    int sprite[5];
    int px,py;
    int sentido;
    int cor;
    float sound;
    int tamanho_raio_x;
    int tamanho_raio_y;
}personagem;

personagem cria_personagem(personagem p, int sprite_fechado, int sprite_cima, int sprite_baixo, int sprite_direita, int sprite_esquerda, int x, int y, int sentido, int cor,float sound){
    p.sprite[0] = sprite_fechado;
    p.sprite[1] = sprite_cima;
    p.sprite[2] = sprite_baixo;
    p.sprite[3] = sprite_direita;
    p.sprite[4] = sprite_esquerda;
    p.px = x;
    p.py = y;
    p.sentido = sentido;
    p.cor = cor;
    p.sound = sound;
    return p;
}
void teleporte(personagem *person){
	if((person ->px==0)&&(person->py==10)){
		person->px=ty-1;
	}
	else{
		if((person->px==ty-1)&&(person->py==10)){
			person->px=0;
		}
	}

}

void movimento(personagem *person){
    if(person -> sentido == 1){
        --(person -> py);
    }else{
    	if(person -> sentido == 2){
			++(person -> py);
		}else{
			if(person -> sentido == 3){
				++(person -> px);
			}else{
				if(person -> sentido == 4){
					--(person -> px);
				}
			}
		}
    }
    teleporte(person);
}

void gif(int *gif,personagem pac_man){
    if(*gif == 0){
        gotoxy (pac_man . px,pac_man . py);
        printf("%c",pac_man . sprite[0]);
        *gif = 1;
    }else{
        gotoxy (pac_man . px,pac_man . py);
        printf("%c",pac_man . sprite[pac_man . sentido]);
        *gif = 0;
    }
}
int colisao_parede(personagem p, char mapa[tx][ty]){
    movimento(&p);
    if(mapa[p.py][p.px] == 32 || mapa[p.py][p.px] == 46 || mapa[p.py][p.px] == -49){
        return 0;
    }else{
        return 1;
    }
}
void rastro(personagem p,char mapa[tx][ty]){
    gotoxy (p.px,p.py);
    printf("%c",mapa[p.py][p.px]);
}

void atualiza_matriz(personagem p, char mapa[tx][ty], int* score, int *powerup){
    if(mapa[p.py][p.px]==46){
        mapa[p.py][p.px]=' ';
        (*score)++;
    }else{
    	if(mapa[p.py][p.px]==-49){
			mapa[p.py][p.px]=' ';
			(*score)+=10;
			(*powerup)=1;
		}
    }
}

int colisao_fantasma(personagem p1, personagem p2, int powerup){
    if(p1.px==p2.px && p1.py==p2.py){
        if(powerup==0){
            return 1;
        }else{
            return 2;
        }
    }else{
        return 0;
    }
}

void muda_sentido(personagem *p,int teclapertada,char mapa[tx][ty]){
	int sentidotemp;
	if(teclapertada == 'w' || teclapertada == 'W' || teclapertada == 1 || teclapertada == KEY_UP){
		sentidotemp = p ->sentido;
		p ->sentido = 1;
		if(colisao_parede(*p,mapa)){
			p ->sentido = sentidotemp;
		}
	}
	if(teclapertada == 's' || teclapertada == 'S' || teclapertada == 2 || teclapertada == KEY_DOWN){
		sentidotemp = p ->sentido;
		p ->sentido = 2;
		if(colisao_parede(*p,mapa)){
			p ->sentido = sentidotemp;
		}
	}
	if(teclapertada == 'd' || teclapertada == 'D' || teclapertada == 3 || teclapertada == KEY_RIGHT){
		sentidotemp = p ->sentido;
		p ->sentido = 3;
		if(colisao_parede(*p,mapa)){
			p ->sentido = sentidotemp;
		}
	}
	if(teclapertada == 'a' || teclapertada == 'A' || teclapertada == 4 || teclapertada == KEY_LEFT){
		sentidotemp = p ->sentido;
		p ->sentido = 4;
		if(colisao_parede(*p,mapa)){
			p ->sentido = sentidotemp;
		}
	}
}
