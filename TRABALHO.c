  
/*
FUNCOES [\] AlgI - T2 - 2020
> Cassiano Rodrigues
> 06/07/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define MAX 100
#define ESC 27
#define F1 59
#define F2 60
#define F3 61
#define F4 62
#define F5 63
#define F6 64
#define F7 65
#define F8 66
#define F9 67
#define F10 68
#define F11 133
#define F12 134 
// '0' (F1>F10) [] '224' (F11-F12)
#define BAIXO 80
#define CIMA 72
#define ENTER 13
#define DIREITA 77
#define ESQUERDA 75

int L=0,C=0;
int nome[50];
char tecla;
void tela_propriedades(){
    printf("\t-----------------------------------------------------------------------------------------\n");
    printf("\t                 PROPRIEDADE                |                 BOOLEANO                   \n");
    printf("\t-----------------------------------------------------------------------------------------\n");
}
/*> ******************************************************************** <*/
void gotoxy(int x,int y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}
/* > ---------------------=* FUNCOES ELEMENTOS *=----------------------- <*/
void maiuscula(char *frase){
    int i;
    for (i=0;i<strlen(frase);i++){
        frase[i]=toupper(frase[i]);
    }
}
/*> ******************************************************************** <*/
void ler_matriz(int matriz[L][C]){
    printf("\t > DIGITE SUA MATRIZ\n",nome);
    int i,j;
    for (i=0;i<L;i++){
        for (j=0;j<C;j++){
            printf("\tValor de [%d][%d]> ",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }
}
/*> ******************************************************************** <*/
void mostrar_matriz(int matriz[L][C]){
    int i,j;
    printf("\n\t\t<< MATRIZ REGISTRADA >>\n\t");
    for (i=0;i<L;i++){
        for (j=0;j<C;j++){
            printf("[ %3d ]",matriz[i][j]);
        }
        printf("\n\t");
    }
    printf("\n");
}
/*> ******************************************************************** <*/
void trocar_linha(int matriz[L][C]){
    int x,y;
    int i,j,temp;
    printf("\t\t.______________.\n");
    printf("\t\t| Entre 0 e %2d |\n",(L-1));
    printf("\t\t`--------------`\n");

    printf("\tLINHA QUE SERA TROCADA\n\t> ");
    scanf("%d",&x);
    printf("\tLINHA QUE SERA INSERIDA\n\t> ");
    scanf("%d",&y);

    for (i=0;i<C;i++){
        temp=matriz[x][i];
        matriz[x][i]=matriz[y][i];
        matriz[y][i]=temp;
    }
    mon_bijou();
    mostrar_matriz(matriz);
}
/*> ******************************************************************** <*/
void trocar_coluna(int matriz[L][C]){
    int x,y;
    int i,j,temp;
    printf("\t\t.______________.\n");
    printf("\t\t| Entre 0 e %2d |\n",(C-1));
    printf("\t\t`--------------`\n");

    printf("\tCOLUNA QUE SERA TROCADA\n\t> ");
    scanf("%d",&x);
    printf("\tCOLUNA ONDE SERA TROCADA\n\t> ");
    scanf("%d",&y);

    for (i=0;i<L;i++){
        temp=matriz[i][x];
        matriz[i][x]=matriz[i][y];
        matriz[i][y]=temp;
    }
    mon_bijou();
    mostrar_matriz(matriz);
}
/*> ******************************************************************** <*/
void diagonal(int matriz[L][C]){
    int i,j,temp;
    for (i=0,j=C;i<L;j--,i++){
        temp=matriz[i][i];
        matriz[i][i]=matriz[i][j];
        matriz[i][j]=temp;
    }
    mostrar_matriz(matriz);
}
/* > --------------------=* FUNCOES VERIFICACAO *=---------------------- <*/
bool matriz_quadrada(){
    if(L==C){
        return true;
    }
    else{
        return false;
    }
}
/*> ******************************************************************** <*/
bool simetrica(int matriz[L][C]){
    if((matriz_quadrada(matriz))==true){
        int i,j,temp;
        tela_propriedades();
        for (i=0;i<L;i++){
            for (j=0;j<C;j++){
                if(matriz[i][j]!=matriz[j][i]){
                    return false;
                }
                else{
                    return true;
                }
            }
        }
    }
}
/*> ******************************************************************** <*/
bool quadrado_magico(int matriz[L][C]){
    if((matriz_quadrada(matriz))==true){
        int i,j,aux_soma,sair=0;
        int soma_l[C],soma_c[L];
        int soma_d_principal=0,soma_d_secundaria=0;
        tela_propriedades();
        for (i=0;i<L;i++){
            for (j=0;j<C;j++){
                aux_soma+=matriz[i][j];
            }
            soma_l[i]=aux_soma;
        }
        aux_soma=0;
        for (i=0;i<C;i++){
            for (j=0;j<L;j++){
                aux_soma+=matriz[i][j];
            }
            soma_c[i]=aux_soma;
        }
        aux_soma=0;

        /* >------------------------< */

        for (i=0;i<L;i++){
            for (j=0;j<C;j++){
                if (i==j){
                    aux_soma+=matriz[i][j];
                }
            }
        }
        soma_d_principal=aux_soma;
        aux_soma=0;

        for (i=0,j=(C-1);i<L;i++,j--){
            aux_soma+=matriz[i][j];
        }
        soma_d_secundaria=aux_soma;
        aux_soma=0;
        /* > ------------ SOMA DIAGONAIS ------------- < */

        if (soma_d_principal!=soma_d_secundaria){
            return false;
        }
        /* > ----------- SOMA LINHA/COLUNA------------ < */
        for (i=0;i<L;i++){
            for (j=0;j<C;j++){
                if (soma_l[i]=!soma_c[j]){
                    return false;
                }
            }   
        }  
        /* > ----------- SOMA DIAGONAL/LINHA------------ < */
        if (soma_c[0]!=soma_d_secundaria){
            return false;
        }
        return true;
    }
}
/*> ******************************************************************** <*/
bool quadrado_latino(int matriz[L][C]){
    if((matriz_quadrada(matriz))==true){
        tela_propriedades();
        int dim=L;
        int i,j,k,soma[dim];

        for (i=0;i<dim;i++){
            soma[i]=0;
            for (j=0;j<dim;j++){
                soma[i]+=matriz[i][j];
                for (k=0;k<dim;k++){
                    if ((matriz[i][j]==matriz[i][k]) && (j!=k)){
                        return false;
                    }
                }
            }
        }

        for (i=0;i<(dim-1);i++){
            if (soma[i]!=soma[i+1]){
                return false;
            }
        }

        for (j=0;j<dim;j++){
            soma[j]=0;
            for (i=0;i<dim;i++){
                soma[j]+=matriz[i][j];
                for (k=0;k<dim;k++){
                    if ((matriz[i][j]==matriz[k][j]) && (i!=k)){
                        return 0;
                    }
                }
            }
        }
        for (i=0;i<(dim-1);i++){
            if (soma[i]!=soma[i+1]){
                return 0;
            }
        }
        return 1;
    }
}
/* > ---------------------------=* TELAS *=---------------------------- <*/
void tela_loading(){
    int i,j;
    for (i=1;i<3;i++){
        printf("Carregando [%d%%] ",(i*50));
        for (j=0;j<10;j++){
            printf("<>");
            Sleep(100);
        }
        printf("\r");
        for (j=0;j<40;j++){
            printf(" "); /* Apaga a linha anterior */
        }
        printf("\r");
    }
}
/*> ******************************************************************** <*/
void tela_de_inicio(){
    int i;
    printf("\t.----------------------------------------------------------------------------------.\n");
    printf("\t|                                TRABALHO FUNCOES                                  |\n");
    printf("\t|                          ------------------------------                          |\n");
    printf("\t|                         ________________________________                         |\n");
    printf("\t|                        |   TEMA: MATRIZES               |                        |\n");
    printf("\t|                        |      DESENVOLVIDO POR          |                        |\n");
    printf("\t|                        |            CASSIANO RODRIGUES  |                        |\n");
    printf("\t|                        |________________________________|                        |\n");
    printf("\t|                                                                                  |\n");
    printf("\t`----------------------------------------------------------------------------------`\n");
    printf("\t                                 < Digite seu nome >                               \n");
    printf("\t                              -> ");
    gets(nome);
    system("cls");
}
/*> ******************************************************************** <*/
void tela_de_funcoes(int matriz[L][C]){
    int tecla,x=34,y=7;
    printf("\tOLA, \"%s\" ESCOLHA A FUNCAO QUE DESEJA UTILIZAR:\n",nome);
    printf("\t.----------------------------------------------------------------------------------------.\n");
    printf("\t|                                        FUNCOES                                         |\n");
    printf("\t|                            ------------------------------                              |\n");
    printf("\t|  ___________________                                          __________________       |\n");
    printf("\t| |    -ELEMENTOS-    |                                        |  -VERIFICACOES-  |      |\n");
    printf("\t| | TROCA DE LINHAS   | [  ]                                   | SIMETRICA        | [  ] |\n");
    printf("\t| | TROCA DE COLUNAS  | [  ]                                   | QUADRADO MAGICO  | [  ] |\n");
    printf("\t| | TROQUE DIAGONAIS  | [  ]                                   | QUADRADO LATINO  | [  ] |\n");
    printf("\t| | TROCAR ELEMENTOS  | [  ]                                   | PERMUTACAO       | [  ] |\n");
    printf("\t| |___________________|                                        |__________________|      |\n");
    printf("\t|                                                                                        |\n");
    printf("\t`----------------------------------------------------------------------------------------`\n");
    printf("\t < TECLE F1 PARA AJUDA >                                       < TECLE ESC PARA SAIR >    \n");

    do{
	    tecla=getch(); //capturamos a tecla digitada
		switch(tecla){
		 	case BAIXO: /* > Se pressionarmos a tecla seta para BAIXO < */
				gotoxy(x,y); /* > Movendo no eixo X(VAR) */
				putchar(' ');
				if(y==10){ /* > Ele testa se estamos na posição 15 no eixo y < */
					y=7;  /* > Se sim retornamos a posição 12 < */
				}
				else{
					y++; /* > vamos mais para baixo <*/
				}
		 		gotoxy(x,y); 
		 		putchar('<'); /* > Imprime um cursor para nos localizarmos < */
		 		break; 
		 	
		 	case CIMA: /* > Se pressionarmos a tecla seta para CIMA < */
		 		gotoxy(x,y); 
				putchar(' '); 
		 		if(y==7){/* > Se estamos na posição 12 < */
		 			y=10; /* > Se sim vamos para a posição 18 < */ 
		 		}
		 		else{
		 			y--; /* > Vamos para cima < */
		 		}
		 		gotoxy(x,y); 
		 		putchar('<');
		 		break;
		 	case DIREITA:
                x=94;
                gotoxy(34,y);
                putchar(' ');
                gotoxy(x,y); 
		 		putchar('<');
                break;
            case ESQUERDA:
                x=34;
                gotoxy(94,y);
                putchar(' ');
                gotoxy(x,y); 
		 		putchar('<');
                break;
		 	case ENTER: /* > Se pressionarmos a tecla ENTER < */
			 	if(x==34){
                    switch(y){ /* > posição no eixo Y < */
				 	    case 7:
                            mon_bijou();
					 	    trocar_linha(matriz);
					 	    break;
					    case 8:
                            mon_bijou();
						    trocar_coluna(matriz);
						    break;
					    case 9:
                            mon_bijou();
						    diagonal(matriz);
                            break;
                        case 10:
                            mon_bijou();
						    ler_matriz(matriz);
                            break;
				    }
                }
                if(x==94){
                    switch(y){ /* > posição no eixo Y < */
				 	    case 7:
                            gotoxy(1,14);{
					 	        if((simetrica(matriz))==true){
                                    printf("\t             > MATRIZ SIMETRICA                               VERDADEIRO\n");
                                }
						        else{
                                    printf("\t             > MATRIZ SIMETRICA                                 FALSO   \n");
                                }
                            }
					 	    break;
					    case 8:
                            gotoxy(1,14);{
                                if((quadrado_magico(matriz))==true){
                                    printf("\t             > QUADRADO MAGICO                               VERDADEIRO\n");
                                }
						        else{
                                    printf("\t             > QUADRADO MAGICO                                 FALSO   \n");
                                }
                            }
						    break;
					    case 9:
                            gotoxy(1,14);{
                                if((quadrado_latino(matriz))==true){
                                    printf("\t             > QUADRADO LATINO                               VERDADEIRO\n");
                                }
						        else{
                                    printf("\t             > QUADRADO LATINO                                 FALSO   \n");
                                }
                            }
                            break;

                        /* case 10:
                            mon_bijou();
						    permutacao(matriz);
                            break; */
				    }
                }
		 	default:
		 		break;
		}
		
	}while(1<2); //nossa condição para continuar o loop

    // if(kbhit){
    //     tecla = getch();
    // }
    //     //se for 0, le novamente --> TECLA DE FUNCAO
    // if(tecla==0){
    //     tecla=getch();
    // }
}
/*> ******************************************************************** <*/
void mon_bijou(){
    system("cls");
}
/*> ******************************************************************** <*/

/* > Main <*/
main(){
    tela_de_inicio();
    maiuscula(nome);

    /* - ORDEM MATRIZ - */

    printf("   %s\n\t [] QUANTIDADE DE LINHAS > ",nome);
    scanf("%d",&L); 
    printf("\t [] QUANTIDADE DE COLUNAS: ");
    scanf("%d",&C);
    printf("\n");

    /* - PADRAO - */

    int matriz[L][C];
    ler_matriz(matriz);
    mon_bijou();
    mostrar_matriz(matriz);

    /* - INTERFACE - */
    tela_loading();
    system("cls");
    tela_de_funcoes(matriz);


    /* if(tecla==F2){
        trocar_linha(matriz);
        mostrar_matriz(matriz);
    }
    else if(tecla==F3){
        trocar_coluna(matriz);
        mostrar_matriz(matriz);
    }
    else if(tecla==F4){
        diagonal(matriz);
        mostrar_matriz(matriz);
    } */

    // tela_propriedades();

    /* else if(tecla==F5){
        tela_propriedades();
        if((simetrica(matriz))==true){
            printf("\t             > MATRIZ SIMETRICA                             VERDADEIRO\n");
        }
        else{
            printf("\t             > MATRIZ SIMETRICA                                  FALSO\n");
        }
    }
    else if(tecla==F6){
        tela_propriedades();
        if((quadrado_magico(matriz))==true){
            printf("\t             > QUADRADO MAGICO                             VERDADEIRO\n");
        }
        else{
            printf("\t             > QUADRADO MAGICO                                   FALSO\n");
        }
    }
    else if(tecla==F7){
        tela_propriedades();
        if((quadrado_latino(matriz))==true){
            printf("\t             > QUADRADO LATINO                              VERDADEIRO\n");
        }
        else{
            printf("\t             > QUADRADO LATINO                                   FALSO\n");
        }
    }
    else if(tecla==F8){
        tela_propriedades();
        if((matriz_quadrada(matriz))==true){
            printf("\t             > QUADRADO LATINO                              VERDADEIRO\n");
        }
        else{
            printf("\t             > QUADRADO LATINO                                   FALSO\n");
        }
    } */
    
    /*
    * trocar_coluna(matriz);
    * mostrar_matriz(matriz);
    */

system("pause");}