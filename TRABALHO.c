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

int setcolor (char color){
	HANDLE h;
	h = GetStdHandle (STD_OUTPUT_HANDLE);
	return SetConsoleTextAttribute (h,color);
    /* Função pega na Internet -- */
}
/*> ******************************************************************** <*/
void tamanho(){
    int j;
    printf("\t VAMOS PREENCHER SUA MATRIZ\n\tDIGITE UM NUMERO ENTRE 0 E 20\n");
    do{
        printf("\t [] QUANTIDADE DE LINHAS > ");
        setcolor(2);
        scanf("%d",&L);
        setcolor(7);
        if((L>20)||(L<=0)){
            printf("\tENTRADA INVALIDA\n");
        }
    }while((L>20)||(L<=0));
    do{
        printf("\t [] QUANTIDADE DE COLUNAS: ");
        setcolor(2);
        scanf("%d",&C);
        setcolor(7);
        if((C>20)||(C<=0)){
            printf("\tENTRADA INVALIDA\n");
        }
    }while((C>20)||(C<=0));
}
/*> ******************************************************************** <*/
void tela_propriedades(){
    printf("\t-----------------------------------------------------------------------------------------\n");
    printf("\t                 PROPRIEDADE                |                 BOOLEANO                   \n");
    printf("\t-----------------------------------------------------------------------------------------\n");
}
/*> ******************************************************************** <*/
void gotoxy(int x,int y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
    /* Função pega na Internet -- */
}
/*> ******************************************************************** <*/
bool matriz_quadrada(){
    if(L==C){
        return true;
    }
    else{
        return false;
    }
}
/* > ---------------------=* FUNCOES ELEMENTOS *=----------------------- <*/
void maiuscula(char *frase){
    int i;
    for (i=0;i<strlen(frase);i++){
        if(frase[i]=='\0'){
            break;
        }
        frase[i]=toupper(frase[i]);
    }
}
/*> ******************************************************************** <*/
void ler_matriz(int matriz[L][C]){
    printf("\t > DIGITE SUA MATRIZ\n");
    int i,j;
    for (i=0;i<L;i++){
        for (j=0;j<C;j++){
            do{
                printf("\tValor de [%d][%d]> ",i,j);
                setcolor(2);
                scanf("%d",&matriz[i][j]);
                setcolor(7);
                if((matriz[i][j]>999)||(matriz[i][j]<-999)){printf("\t\t[] ENTRADA INVALIDA\n");}
            }while((matriz[i][j]>999)||(matriz[i][j]<-999));
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
void mostrar_matriz_diagonal(int matriz[L][C]){
    int i,j;
    printf("\n\t\t<< MATRIZ REGISTRADA >>\n\t");
    for (i=0;i<L;i++){
        for (j=0;j<C;j++){
            if(i==j){
                setcolor(5);
                printf("[ %3d ]",matriz[i][j]);
                setcolor(7);
            }
            else if(j==((C-1)-i)){
                setcolor(1);
                printf("[ %3d ]",matriz[i][j]);
                setcolor(7);
            }
            else{
                printf("[ %3d ]",matriz[i][j]);
            }
        }
        printf("\n\t");
    }
    printf("\n");
}
/*> ******************************************************************** <*/
void mostra_matriz_linha(int matriz[L][C],int x,int y){
    int i,j;
    printf("\n\t\t<< MATRIZ REGISTRADA >>\n\t");
    for (i=0;i<L;i++){
        for (j=0;j<C;j++){
            if(i==x){
                setcolor(5);
                printf("[ %3d ]",matriz[i][j]);    
                setcolor(7);
            }
            else if(i==y){
                setcolor(1);
                printf("[ %3d ]",matriz[i][j]);    
                setcolor(7);
            }
            else{
                printf("[ %3d ]",matriz[i][j]);
            }
        }
        printf("\n\t");
    }
}
/*> ******************************************************************** <*/
void mostrar_matriz_coluna(int matriz[L][C],int x,int y){
    int i,j;
    printf("\n\t\t<< MATRIZ REGISTRADA >>\n\t");
    for (i=0;i<L;i++){
        for (j=0;j<C;j++){
            if(j==x){
                setcolor(5);
                printf("[ %3d ]",matriz[i][j]);    
                setcolor(7);
            }
            else if(j==y){
                setcolor(1);
                printf("[ %3d ]",matriz[i][j]);    
                setcolor(7);
            }
            else{
                printf("[ %3d ]",matriz[i][j]);
            }
        }
        printf("\n\t");
    }
}
/*> ******************************************************************** <*/
void trocar_linha(int matriz[L][C]){
    int x,y;
    int i,j,temp;
    printf("\t\t.______________.\n");
    printf("\t\t| Entre 0 e %2d |\n",(L-1));
    printf("\t\t`--------------`\n");

    printf("\tLINHA QUE SERA TROCADA\n\t> ");
    setcolor(1);
    scanf("%d",&x);
    setcolor(7);
    printf("\tLINHA QUE SERA INSERIDA\n\t> ");
    setcolor(5);
    scanf("%d",&y);
    setcolor(7);
    for (i=0;i<C;i++){
        temp=matriz[x][i];
        matriz[x][i]=matriz[y][i];
        matriz[y][i]=temp;
    }
    mostra_matriz_linha(matriz,x,y);
}
/*> ******************************************************************** <*/
void trocar_coluna(int matriz[L][C]){
    int x,y;
    int i,j,temp;
    printf("\t\t.______________.\n");
    printf("\t\t| Entre 0 e %2d |\n",(C-1));
    printf("\t\t`--------------`\n");

    printf("\tCOLUNA QUE SERA TROCADA\n\t> ");
    setcolor(1);
    scanf("%d",&x);
    setcolor(7);
    printf("\tCOLUNA ONDE SERA TROCADA\n\t> ");
    setcolor(5);
    scanf("%d",&y);
    setcolor(7);

    for (i=0;i<L;i++){
        temp=matriz[i][x];
        matriz[i][x]=matriz[i][y];
        matriz[i][y]=temp;
    }
    mostrar_matriz_coluna(matriz,x,y);
}
/*> ******************************************************************** <*/
void diagonal(int matriz[L][C]){
    if((matriz_quadrada())==true){
        int i,j,temp;
        for (i=0,j=(C-1);i<L;j--,i++){
            temp=matriz[i][i];
            matriz[i][i]=matriz[i][j];
            matriz[i][j]=temp;
        }
        mostrar_matriz_diagonal(matriz);
    }
}
/* > --------------------=* FUNCOES VERIFICACAO *=---------------------- <*/
bool simetrica(int matriz[L][C]){
    if((matriz_quadrada(matriz))==true){
        int i,j,temp;
        tela_propriedades();
        for (i=0;i<L;i++){
            for (j=0;j<C;j++){
                if(matriz[i][j]!=matriz[j][i]){
                    return false;
                }
            } 
        }
        return true;
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
/*> ******************************************************************** <*/
bool permutacao(int matriz[L][C]){
    if((matriz_quadrada())==true){
        int i,j,dim=L;
        int soma_coluna[C],aux_soma;
        tela_propriedades();
        /* Somatório da colunas */
        for(i=0;i<dim;i++){
            soma_coluna[i] = 0;
        }
        for(i=0;i<dim;i++){
            /* Somatório da linhas */
            aux_soma=0;
            for(j=0;j<dim;j++){
                /* Verifica se os valores são 0 e 1 */
                if((matriz[i][j]!=1) && (matriz[i][j]!=0)){                  
                    return false;
                }
                else{
	                soma_coluna[j]+=matriz[i][j];
	                aux_soma+=matriz[i][j];
                }
            }
            /* Teste de soma em uma linha */
            if(aux_soma!=1){
                return false;
            }
        }
        /* teste da soma das colunas */
        for(i=0;i<dim;i++){
            if(soma_coluna[i]!=1){
                return false;
            }
        }
        return true;
    }
    return false;
}
/* > ---------------------------=* TELAS *=---------------------------- <*/
void tela_loading(int x, int y){
    int i,j;
    for (i=1;i<=2;i++){
        gotoxy(x,y);
        setcolor(7);
        printf("[ Carregando %3d%% ]\n",(i*50));
        gotoxy((x-6),(y+1));
        for (j=0;j<15;j++){
            setcolor(4);
            printf("<>");
            Sleep(100);
        }
        printf("\r");
        for (j=0;j<30;j++){
            printf(" "); /* Apaga a linha anterior */
        }
        printf("\r");
    }
    setcolor(7);
}
/*> ******************************************************************** <*/
void tela_de_inicio(){
    printf("\t.----------------------------------------------------------------------------------.\n");
    printf("\t|                                ");
    setcolor(9);
    printf(" TRABALHO FUNCOES");
    setcolor(7);
    printf("                                 |\n");
    printf("\t|                          ------------------------------                          |\n");
    printf("\t|                         ________________________________                         |\n");
    printf("\t|                        |   TEMA: MATRIZES               |                        |\n");
    printf("\t|                        |      DESENVOLVIDO POR          |                        |\n");
    printf("\t|                        |            CASSIANO RODRIGUES  |                        |\n");
    printf("\t|                        |________________________________|                        |\n");
    printf("\t|                                                                                  |\n");
    printf("\t`----------------------------------------------------------------------------------`\n");
    printf("\t                                 < Digite seu nome >                               \n");
    printf("\t                              ->  ");
    setcolor(2);
    gets(nome);
    setcolor(7);
    system("cls");
}
/*> ******************************************************************** <*/
void tela_ajuda(){
    setcolor(9);
    printf("\t[AJUDA]");
    setcolor(6);
    printf("\n\t\t<> USE AS SETAS DO TECLADO PARA SE MOVIMENTAR SOBRE A INTERFACE\n");
    setcolor(2);
    printf("\n\t\t[] TROCA DE LINHAS");
    setcolor(7);
    printf("\n\t\tAo escolher essa opcao, voce podera escolher entre as linhas\n\t\tpresentes na sua matriz, duas linhas que irao trocar de lugar.\n");
    setcolor(2);
    printf("\n\t\t[] TROCA DE COLUNAS");
    setcolor(7);
    printf("\n\t\tAo escolher essa opcao, voce podera escolher entre as colunas\n\t\texistentes na sua matriz, duas colunas para serem trocadas.\n");
    setcolor(2);
    printf("\n\t\t[] TROCAR DIAGONAIS");
    setcolor(7);
    printf("\n\t\tAo selecionar essa opcao, a diagonal principal e a secundaria,\n\t\tirao se inverter.\n");
    setcolor(2);
    printf("\n\t\t[] TROCAR MATRIZ");
    setcolor(7);
    printf("\n\t\tAo selecionar essa opcao, voce vai reescrever sua matriz do zero,\n\t\tseja o tamanho dela, quanto os elementos.\n");
    setcolor(2);
    printf("\n\t\t[] MATRIZ SIMETRICA");
    setcolor(7);
    printf("\n\t\tAo selecionar essa opcao, ira verificar se a matriz transposta,\n\t\teh equivalente, a sua matriz.\n");
    setcolor(2);
    printf("\n\t\t[] QUADRADO MAGICO");
    setcolor(7);
    printf("\n\t\tAo selecionar essa opcao, ira verificar se a sua matriz eh um \n\t\tquadrado magico, ou seja a soma das linhas e colunas sao iguais\n\t\to mesmo vale a sua diagonal principal e a sua diagonal secundaria.\n");
    setcolor(2);
    printf("\n\t\t[] QUADRADO LATINO");
    setcolor(7);
    printf("\n\t\tAo selecionar essa opcao, ira verificar se os numeros dispostos\n\t\tsobre a matriz sejam pertencentes a dimensao, e se em cada linha\n\t\te coluna aparecam apenas uma vez os mesmos.\n");
    setcolor(2);
    printf("\n\t\t[] MATRIZ DE PERMUTACAO");
    setcolor(7);
    printf("\n\t\tAo selecionar essa opcao, ira verificar se a sua matriz,\n\t\ttem somente \"0\" e \"1\" sendo o \"1\" presente somente uma vez em cada\n\t\tlinha e coluna.\n");
}
/*> ******************************************************************** <*/
void tela_de_funcoes(){
    printf("\tOLA, \"%s\" ESCOLHA A FUNCAO QUE DESEJA UTILIZAR:\n",nome);
    printf("\t.----------------------------------------------------------------------------------------.\n");
    printf("\t|                                        FUNCOES                                         |\n");
    printf("\t|                            ------------------------------                              |\n");
    printf("\t|  ___________________                                          __________________       |\n");
    printf("\t| |    ");
    setcolor(2);
    printf("-ELEMENTOS-");
    setcolor(7);
    printf("    |                                        |  ");
    setcolor(2);
    printf("-VERIFICACOES-");
    setcolor(7);
    printf("  |      |\n");
    printf("\t| | TROCA DE LINHAS   | [  ]                                   | SIMETRICA        | [  ] |\n");
    printf("\t| | TROCA DE COLUNAS  | [  ]                                   | QUADRADO MAGICO  | [  ] |\n");
    printf("\t| | TROCAR DIAGONAIS  | [  ]                                   | QUADRADO LATINO  | [  ] |\n");
    printf("\t| | TROCAR MATRIZ     | [  ]                                   | PERMUTACAO       | [  ] |\n");
    printf("\t| |___________________|                                        |__________________|      |\n");
    printf("\t|                                                                                        |\n");
    printf("\t`----------------------------------------------------------------------------------------`\n");
    printf("\t < TECLE ");
    setcolor(9);
    printf("F1");
    setcolor(7);
    printf(" PARA AJUDA >                                         < TECLE ");
    setcolor(9);
    printf("ESC");
    setcolor(7);
    printf(" PARA SAIR > \n");
}
/*> ******************************************************************** <*/
void tela_fim(){
    printf("\tOK, \"%s\" VOCE FINALIZOU '-'\n",nome);
    printf("\t.----------------------------------------------------------------------------------------.\n");
    printf("\t|                                        ");
    setcolor(9);
    printf("OBRIGADO");
    setcolor(7);
    printf("                                        |\n");
    printf("\t|                              -----------------------------                             |\n");
    printf("\t|  ____________________________________________________________________________________  |\n");
    printf("\t| |                                    [REALIZACAO]                                    | |\n");
    printf("\t| |                        ");
    setcolor(2);
    printf("CASSIANO HENRIQUE APARECIDO RODRIGUES");
    setcolor(7);
    printf("                       | |\n");
    printf("\t| |                                        [RA]                                        | |\n");
    printf("\t| |                                      201020891                                     | |\n");
    printf("\t| |____________________________________________________________________________________| |\n");
    printf("\t|                                                                                        |\n");
    printf("\t|                                                                                        |\n");
    printf("\t`----------------------------------------------------------------------------------------`\n");
}
/*> ******************************************************************** <*/
void escolha(int matriz[L][C]){
    int tecla,x=34,y=7;
    char opcao;

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
                system("cls");
                tela_de_funcoes();
			 	if(x==34){
                    switch(y){ /* > posição no eixo Y < */
				 	    case 7:
                            gotoxy(1,16);{
					 	        trocar_linha(matriz);
                                printf("\t [] ASSIM QUE DESEJAR SAIR, USE AS SETAS PARA MOVER\n");
                                opcao=getch();
                            }
                            break;
					    case 8:
                            gotoxy(1,16);{
						        trocar_coluna(matriz);
                                printf("\t [] ASSIM QUE DESEJAR SAIR, USE AS SETAS PARA MOVER\n");
                                opcao=getch();
                            }
                            break;
					    case 9:
                            gotoxy(1,16);{
                                if((matriz_quadrada())==true){
						            diagonal(matriz);
                                    printf("\t [] ASSIM QUE DESEJAR SAIR, USE AS SETAS PARA MOVER\n");
                                }
                                else{
                                    printf("\t [] SUA MATRIZ NAO EH QUADRADA :(\n");
                                }
                                opcao=getch();
                            }
                            break;
                        case 10:
                            gotoxy(1,16);{
						        tamanho();
                                ler_matriz(matriz);
                                mostrar_matriz(matriz);
                                printf("\t [] ASSIM QUE DESEJAR SAIR, USE AS SETAS PARA MOVER\n");
                                opcao=getch();
                            }
                            break;
				    }
                }
                if(x==94){
                    switch(y){ /* > posição no eixo Y < */
				 	    case 7:
                            gotoxy(1,16);{
					 	        if((simetrica(matriz))==true){
                                    setcolor(9);
                                    printf("\t             > MATRIZ SIMETRICA");
                                    setcolor(2);
                                    printf("                              VERDADEIRO\n");
                                    setcolor(7);
                                }
						        else{
                                    setcolor(9);
                                    printf("\t             > MATRIZ SIMETRICA");
                                    setcolor(4);
                                    printf("                                FALSO   \n");
                                    setcolor(7);
                                }
                            }
					 	    break;
					    case 8:
                            gotoxy(1,16);{
                                if((quadrado_magico(matriz))==true){
                                    setcolor(9);
                                    printf("\t             > QUADRADO MAGICO");
                                    setcolor(2);
                                    printf("                               VERDADEIRO\n");
                                    setcolor(7);
                                }
						        else{
                                    setcolor(9);
                                    printf("\t             > QUADRADO MAGICO");
                                    setcolor(4);
                                    printf("                                 FALSO   \n");
                                    setcolor(7);
                                }
                            }
						    break;
					    case 9:
                            gotoxy(1,16);{
                                if((quadrado_latino(matriz))==true){
                                    setcolor(9);
                                    printf("\t             > QUADRADO LATINO");
                                    setcolor(2);
                                    printf("                               VERDADEIRO\n");
                                    setcolor(7);
                                }
						        else{
                                    setcolor(9);
                                    printf("\t             > QUADRADO LATINO");
                                    setcolor(4);
                                    printf("                                 FALSO   \n");
                                    setcolor(7);
                                }
                            }
                            break;

                        case 10:
                            gotoxy(1,16);
                                if((permutacao(matriz))==true){
                                    setcolor(9);
                                    printf("\t             > MATRIZ PERMUTACAO");
                                    setcolor(2);
                                    printf("                             VERDADEIRO\n");
                                    setcolor(7);
                                }
                                else{
                                    setcolor(9);
                                    printf("\t             > MATRIZ PERMUTACAO");
                                    setcolor(4);
                                    printf("                               FALSO   \n");
                                    setcolor(7);
                                }
						        
                            break;
				    }
                }
                break;
		 	case F1:
                system("cls");
                tela_de_funcoes();
                gotoxy(1,16);
                /* MENU AJUDA */
                tela_ajuda();
                break;
            default:
		 		break;
		}
		
	 }while(tecla!=ESC); /* Condição para continuar o loop */

    // if(kbhit){
    //     tecla = getch();
    // }
    //     //se for 0, le novamente --> TECLA DE FUNCAO
    // if(tecla==0){
    //     tecla=getch();
    // }
}
/*> ******************************************************************** <*/

/* > Main <*/
main(){
    tela_de_inicio();
    maiuscula(nome);
    /* - ORDEM MATRIZ - */
    tamanho();
    /* - PADRAO - */
    int matriz[L][C];
    ler_matriz(matriz);
    system("cls");
    mostrar_matriz(matriz);
    /* - INTERFACE FUNÇÕES - */
    tela_loading(24,30);
    
    system("cls");
    tela_de_funcoes();
    escolha(matriz);

    /* - INTERFACE FINAL - */
    system("cls");
    tela_fim();
    tela_loading(44,15);
    exit(0);
system("pause");}