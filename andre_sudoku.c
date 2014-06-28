#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int quadro[9][9];

void zeraQuadro(){
	int i, j;
	for(i=0; i<9; i++){
		for(j=0; j<9; j++){
			quadro[i][j]=0;
		}
	}
}

void geraPrimeiroQuadroRand()
{
	int i,j,n,m,num,repetido=0;
	srand( (unsigned)time(NULL));

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			num = 1+rand()%9;
			
			repetido=0;
			for(m=0; m<3; m++){
				for(n=0; n<3; n++){
					if(quadro[m][n]==num){
						repetido=1;
						
					}
				}
			}
			if(repetido==1)
				j--;
			
			else
				quadro[i][j] = num;	
			}
		}	
}

int verificaLinha(int num, int linha){
	int i;
	for(i=0; i<9; i++){
		if(quadro[linha][i]==0)
			return 0;
		
		if(quadro[linha][i]==num)
			return 1;
		
	}
	return 0;
}

int verificaColuna(int num, int coluna){
	int i;
	for(i=0; i<9; i++){
		if(quadro[i][coluna]==0)
			return 0;
		
		if(quadro[i][coluna]==num)
			return 1;
		
	}
	return 0;
}

int verificaQuadrante(int num, int quadrante){
	int i,j;
	switch(quadrante){
		case 1:
			for(i=0;i<3;i++)
				for(j=0;j<3;j++)
					if(quadro[i][j]==num)
						return 1;
			break;
		
		case 2:
			for(i=0;i<3;i++)
				for(j=3;j<6;j++)
					if(quadro[i][j]==num)
						return 1;
			break;
		
		case 3:
			for(i=0;i<3;i++)
				for(j=6;j<9;j++)
					if(quadro[i][j]==num)
						return 1;
			break;
			
		case 4:
			for(i=3;i<6;i++)
				for(j=0;j<3;j++)
					if(quadro[i][j]==num)
						return 1;
			break;
		
		case 5:
			for(i=3;i<6;i++)
				for(j=3;j<6;j++)
					if(quadro[i][j]==num)
						return 1;
			break;
		
		case 6:
			for(i=3;i<6;i++)
				for(j=6;j<9;j++)
					if(quadro[i][j]==num)
						return 1;
			break;
			
		case 7:
			for(i=6;i<9;i++)
				for(j=0;j<3;j++)
					if(quadro[i][j]==num)
						return 1;
			break;
		
		case 8:
			for(i=6;i<9;i++)
				for(j=3;j<6;j++)
					if(quadro[i][j]==num)
						return 1;
			break;
		
		case 9:
			for(i=6;i<9;i++)
				for(j=6;j<9;j++)
					if(quadro[i][j]==num)
						return 1;
			break;
				
		default:
			return -1;
	}
	return 0;
}


void backtracking(int num, int quadrante)
{
    
}

void geraQuadro2()
{
    int i, j, cont=0, repetido, sair=0;
    int num [9] = {0,0,0,0,0,0,0,0,0};
    for(i=0;i<3;i++){
		for(j=3;j<6;j++){
                cont=0;
                repetido=1;
                while(repetido==1 && cont<9){//tenta colocar numeros de 1 a 9 na posicao do quadro i,j
                    if(num[cont]==0 && verificaLinha(cont+1, i)==0 && verificaColuna(cont+1, j)==0){//verifica se o numero pode ser inserido na posicao i j
                        quadro[i][j] = cont + 1;//adiciona o numero na posicao
                        num[cont]=1;//sinaliza como numero já inserido
                        repetido=0;
                    }else
                    {
                        cont++;
                        repetido=1;
                    }
                }  
        }
    }
    
    for(i=0; i<9; i++)
        if(num[i]==0)
            backtracking(num[i],2);
    
}

int main(int argc, char *argv[])
{
		int i,j;
		zeraQuadro();
		geraPrimeiroQuadroRand();
		geraQuadro2();
		
		for(i=0;i<9;i++){
			for(j=0;j<9;j++)
				printf("%d ",quadro[i][j]);
			printf("\n");
		}
		
		system("pause");
		return 0;
}



