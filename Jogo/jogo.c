#include <stdlib.h>
#include <stdio.h>

#define FIM 9
#define COLUNA 3
#define LINHA 3

enum pecas {X, O};

int checagem (int checa_grafico[][3], int checa_P1, int checa_P2){
    //CASO: P1 GANHE (HORIZONTALMENTE)
    if(checa_grafico[0][0] == checa_P1 && checa_grafico[0][1] == checa_P1 && checa_grafico[0][2] == checa_P1 || checa_grafico[1][0] == checa_P1 && checa_grafico[1][1] == checa_P1 && checa_grafico[1][2] == checa_P1 || checa_grafico[2][0] == checa_P1 && checa_grafico[2][1] == checa_P1 && checa_grafico[2][2] == checa_P1){
        return 1;
    }

    //CASO: P1 GANHE (VERTICALMENTE)
    if(checa_grafico[0][0] == checa_P1 && checa_grafico[1][0] == checa_P1 && checa_grafico[2][0] == checa_P1 || checa_grafico[0][1] == checa_P1 && checa_grafico[1][1] == checa_P1 && checa_grafico[2][1] == checa_P1 || checa_grafico[0][2] == checa_P1 && checa_grafico[1][2] == checa_P1 && checa_grafico[2][2] == checa_P1){
        return 1;
    }

    //CASO: P1 GANHE (DIAGONALMENTE)
    if(checa_grafico[0][0] == checa_P1 && checa_grafico[1][1] == checa_P1 && checa_grafico[2][2] == checa_P1 || checa_grafico[0][2] == checa_P1 && checa_grafico[1][1] == checa_P1 && checa_grafico[2][0] == checa_P1){
        return 1;
    }

    //CASO: P2 GANHE (HORIZONTALMENTE)
    if(checa_grafico[0][0] == checa_P2 && checa_grafico[0][1] == checa_P2 && checa_grafico[0][2] == checa_P2 || checa_grafico[1][0] == checa_P2 && checa_grafico[1][1] == checa_P2 && checa_grafico[1][2] == checa_P2 || checa_grafico[2][0] == checa_P2 && checa_grafico[2][1] == checa_P2 && checa_grafico[2][2] == checa_P2){
        return 2;
    }

    //CASO: P2 GANHE (VERTICALMENTE)
    if(checa_grafico[0][0] == checa_P2 && checa_grafico[1][0] == checa_P2 && checa_grafico[2][0] == checa_P2 || checa_grafico[0][1] == checa_P2 && checa_grafico[1][1] == checa_P2 && checa_grafico[2][1] == checa_P2 || checa_grafico[0][2] == checa_P2 && checa_grafico[1][2] == checa_P2 && checa_grafico[2][2] == checa_P2){
        return 2;
    }

     //CASO: P2 GANHE (DIAGONALMENTE)
    if(checa_grafico[0][0] == checa_P2 && checa_grafico[1][1] == checa_P2 && checa_grafico[2][2] == checa_P2 || checa_grafico[0][2] == checa_P2 && checa_grafico[1][1] == checa_P2 && checa_grafico[2][0] == checa_P2){
        return 2;
    }

    return 0;
}


void grafico (int grafico_matriz[][3]){
    printf("       1        2        3\n");
    for(int i = 0; i < LINHA ; i++){
        printf("%d", (i + 1));
        for(int j = 0; j < COLUNA; j++){
        if(grafico_matriz[i][j] == O){
            printf("    | O |");
        }else if(grafico_matriz[i][j] == X){
            printf("    | X |");
        }else{
            printf("    |   |");
        }
      }
      printf("\n");
      }
}


void jogo(){
    int victory = 0, rodada, P1, P2, turno, linha, coluna, status, posicao, P1_check = 0;
    int matriz[][3] = {
         {2, 3, 4},
         {5, 6, 7},
         {8, 9, 10}
    };
    while(P1_check == 0){
    system("cls");
    printf("Que peca sera o primeiro jogador? (1 - X | 2 - O)\n");
    scanf("%d", &P1);
    if(P1 != 1 || P1 != 2){

    }
    switch (P1){
    case 1:
        P1 = X;
        P2 = O;
        P1_check = 1;
        break;

    case 2:
        P1 = O;
        P2 = X;
        P1_check = 1;
        break;
    default:
        printf("\nESCOLHA INVALIDA, tente novamente...");
        getch();
        break;
    }
    }

    turno = 1;

    while(victory == 0){
        for(rodada = 0; rodada < FIM; rodada++){
           //Rodada P1
           if(turno == 1){
            //desenho
            system("cls");
            grafico(matriz);
            //Posicao P1
            printf("\nRodada: %d\n\n", (rodada + 1));
            posicao = 0;
            while(posicao == 0){
            printf("(JOGADOR 1) Linha: ");
            scanf("%d", &linha);
            printf("(JOGADOR 1) Coluna ");
            scanf("%d", &coluna);
            if((linha - 1) > 2 || (linha - 1) < 0){
                printf("\nPOSICAO INVALIDA, TENTE NOVAMENTE\n\n");
            }else if((coluna - 1) > 2 || (coluna - 1) < 0){
                printf("\nPOSICAO INVALIDA, TENTE NOVAMENTE\n\n");
            }else if(matriz[(linha - 1)][(coluna - 1)] == P1 || matriz[(linha - 1)][(coluna - 1)] == P2){
                printf("\nPOSICAO JA OCUPADA, TENTE NOVAMENTE\n\n");
            }else{
                posicao = 1;
            }
            }
            matriz[(linha - 1)][(coluna - 1)] = P1;
            printf("FIM DO TURNO %d...",(rodada + 1));
            getch();
            turno = 2;


           //Rodada P2
            }else if(turno == 2){
            //desenho
            system("cls");
            grafico(matriz);
            //Posicao P2
            printf("\nRodada: %d\n\n", (rodada + 1));
            posicao = 0;
            while(posicao == 0){
            printf("(JOGADOR 2) Linha: ");
            scanf("%d", &linha);
            printf("(JOGADOR 2) Coluna ");
            scanf("%d", &coluna);
            if((linha - 1) > 2 || (linha - 1) < 0){
                printf("\nPOSICAO INVALIDA, TENTE NOVAMENTE\n\n");
            }else if((coluna - 1) > 2 || (coluna - 1) < 0){
                printf("\nPOSICAO INVALIDA, TENTE NOVAMENTE\n\n");
            }else if(matriz[(linha - 1)][(coluna - 1)] == P1 || matriz[(linha - 1)][(coluna - 1)] == P2){
                printf("\nPOSICAO JA OCUPADA, TENTE NOVAMENTE\n\n");
            }else{
                posicao = 1;
            }
            }
            matriz[(linha - 1)][(coluna - 1)] = P2;
            printf("FIM DO TURNO %d...",(rodada + 1));
            getch();
            turno = 1;
           }

           //checagem
           if(rodada == 2 || rodada > 2){
            status = checagem(matriz,P1,P2);
            if(status != 0){
              //VITORIA P1 X e O
              if(status == 1){
                 victory = 1;
                 rodada = 999;
              }
               //VITORIA P2 X e O
              if(status == 2){
                victory = 2;
                rodada = 999;
              }
            }else if(rodada == 8 ){
                victory = -1;
              }}
           }
        }

    //Resultado
    switch (victory){
    case -1:
        system("cls");
        grafico(matriz);
        printf("\nEMPATE\n");
        break;
    case 1:
        system("cls");
        grafico(matriz);
        printf("\nJOGADOR 1 GANHOU\n");
        break;
    case 2:
        system("cls");
        grafico(matriz);
        printf("\nJOGADOR 2 GANHOU\n");
        break;
    }
    printf("\n\nPrecione qualquer coisa para continuar...");
    getch();
}

void creditos(){
    system("cls");
    printf("                   CREDITOS\n\n");
    printf("Criado em 4 dias por: Vitor Roca Pontes.\n\nPlayerTest: Sirlei Roca");
    printf("\n\n\n\n\n\nPrecione qualquer coisa para continuar...");
    getch();
}

int main(){
    //Introducao
    int menu, menu_loop = 1;
    while(menu_loop == 1){
    printf("Bem-Vindo ao jogo da velha\n\n");
    printf("Escolha uma das seguintes opcao: \n");
    printf("1 - COMECAR PARTIDA\n");
    printf("2 - CREDITOS\n");
    printf("3 - FECHAR PROGRAMA\n\n");
    printf("OPCAO: ");
    scanf("%d", &menu);
    if(menu == 1){
       jogo();
       system("cls");
    }else if(menu == 2){
       creditos();
       system("cls");
    }else if(menu == 3){
        menu_loop = 0 ;
    }else{
        printf("\nERRO: OPCAO INVALIDA\n");
        printf("\n\nPrecione qualquer coisa para continuar...");
        getch();
        system("cls");
    }
    }
    return 0;
}
