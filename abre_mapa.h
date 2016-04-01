#define tx 22
#define ty 19
#define limpa system("cls")

void gera_mapa(char mapa[tx][ty]){
    int i,j;
    char aux;
    FILE *a;
    a = fopen("default.map","r");
    for( i=0; i<tx; i++){
        for( j=0; j<ty; j++){
            fscanf(a,"%c",&aux);
            mapa[i][j]=aux;
        }
    }
    for( i=0; i<tx; i++){
        for( j=0; j<ty; j++){
			if(mapa[i][j]==46 || mapa[i][j]==-49){
				setColor(15);
			}else{
				setColor(9);
			}
            printf("%c",mapa[i][j]);
        }
        printf("\n");
    }
}
/**
205 ═ ═ :10
186 = ║ :2
187 = ╗ :3
188 = ╝ :4
200 = ╚ :5
201 = ╔ :6
185 = ╣ :1
202 = ╩ :7
204 = ╠ :9
203 = ╦ :8
206 = ╬ :11
*/
