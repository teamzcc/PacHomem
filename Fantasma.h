typedef struct s_retangulo{
	int x1, x2, y1, y2;
}retangulo;

int IA_Sentido(personagem p1, personagem p2, int rx, int ry){
	int dx,dy;
	retangulo raio;
	raio.x1=p2.px-rx/2;
	raio.x2=p2.px+rx/2;
	raio.y1=p2.py-ry/2;
	raio.y2=p2.py+ry/2;

	if(p1.px<=raio.x2 && p1.px>=raio.x1 && p1.py<=raio.y2 && p1.py>=raio.y1){
		dx=p2.px-p1.px;
		dy=p2.py-p1.py;
		srand(time(NULL));
		if(dx>0 && dy>0){ //quadrante 1
			if(p1.sentido==1 || p1.sentido==3){
				return 1;
			}else{
				return 4;
			}
		}else{
			if(dx<0 && dy>0){ //quadrante 2
				if(p1.sentido==1||p1.sentido==4){
					return 1;
				}else{
					return 3;
				}
			}else{
				if(dx<0 && dy<0){//quadrante 3
					if(p1.sentido==4||p1.sentido==2){
						return 2;
					}else{
						return 3;
					}
				}else{
					if(dx>0 && dy<0){
						if(p1.sentido==4||p1.sentido==1){
							return 4;
						}else{
							return 2;
						}
					}
				}
			}
		}
		if(dy>0&&dx==0){//Corredor 1
			return 1;
		}else{
			if(dy<0 && dx==0){//Corredor 2
				return 2;
			}else{
				if(dx<0 && dy==0){//Corredor 3
					return 3;
				}else{
					if(dx>0 && dy==0){//Corredor 4
						return 4;
					}
				}
			}
		}
	}else{
		srand(time(NULL));
		return rand()%5+1;
	}
}

void mostraRaio(personagem fantasma, int rx, int ry, char mapa[tx][ty], int y0){
	int i,j;
	setColor(15);
	gotoxy(0,y0);
	for(i=0;i<=rx;i++){
		for(j=0;j<=ry;j++){
			if(fantasma.py+i-rx/2>=tx || fantasma.py+i-rx/2<0 || fantasma.px+j-ry/2>=ty|| fantasma.px+j-ry/2<0){
				printf(" ");
			}else{
				printf("%c",mapa[fantasma.py+i-rx/2][fantasma.px+j-ry/2]);
			}
		}
		printf("\n");
	}
	gotoxy((rx/2),(y0+ry/2));
	setColor(fantasma.cor);
	printf("%c",fantasma.sprite[0]);
}

int quadrante(personagem p1, personagem p2, int rx, int ry){
	int dx,dy;
	retangulo raio;
	raio.x1=p2.px-rx/2;
	raio.x2=p2.px+rx/2;
	raio.y1=p2.py-ry/2;
	raio.y2=p2.py+ry/2;

	if(p1.px<=raio.x2 && p1.px>=raio.x1 && p1.py<=raio.y2 && p1.py>=raio.y1){
		dx=p2.px-p1.px;
		dy=p2.py-p1.py;
		if(dx>0 && dy>0){//quadrante 1
			return 1;
		}else{
			if(dx<0 && dy>0){ //quadrante 2
				return 2;
			}else{
				if(dx<0 && dy<0){//quadrante 3
					return 3;
				}else{
					if(dx>0 && dy<0){//quadrante 4
						return 4;
					}else{
						return -1;
					}
				}
			}
		}
	}else{
		return 0;
	}

}
