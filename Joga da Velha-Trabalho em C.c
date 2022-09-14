#include <stdio.h>
#include <math.h>

void mostratabuleiro(char matriz[3][3]);
void checavitoria(char m[3][3],int *jogada,char jogador1[20],char jogador2[20]);

int main(){
    srand((unsigned)time(NULL));
    char jogador1[20],jogador2[20];
    char m[3][3],vezes;
    int i,j,jogada,linha,coluna;

    do{
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                m[i][j] = ' ';
            }
        }
        printf ("\nO jogador 1 usara X e o jogador 2 usara O\n\n");
        printf ("Digite o nome do jogador 1 : ");
        scanf ("%s",&jogador1);
        printf ("Digite o nome do jogador 2 : ");
        scanf ("%s",&jogador2);
        int a = (rand()%2) + 1;
        if(a == 1){
            printf ("\nO jogador %s comeca jogando\n",jogador1);
        }
        else{
            printf ("\nO jogador %s comeca jogando\n",jogador2);
        }
        jogada = 1;
        do{
            if(a == 1){
                if(jogada % 2 == 0){
                    printf ("\nSua vez %s\n",jogador2);
                }
                else{
                    printf ("\nSua vez %s\n",jogador1);
                }
            }
            if(a == 2){
                if(jogada % 2 == 0){
                    printf ("\nSua vez %s\n",jogador1);
                }
                else{
                    printf ("\nSua vez %s\n",jogador2);
                }
            }

            mostratabuleiro(m);

            printf ("Digite a linha : ");
            scanf ("%d",&linha);
            printf ("Digite a coluna : ");
            scanf ("%d",&coluna);
            if(m[linha - 1][coluna - 1] == 'O' || m[linha - 1][coluna - 1] == 'X'){
                printf ("\nLocal ocupado! Escolha outro.\n");
                jogada--;
            }
            if(linha > 3 || coluna > 3){
                printf ("\nLocal Inexistente! Tente de novo.\n");
                jogada--;
            }
            if(a == 1){
                if(jogada % 2 == 0){
                    m[linha - 1][coluna - 1] = 'O';
                }
                else{
                    m[linha - 1][coluna - 1] = 'X';
                }
                //checavitoria(m,&jogada,jogador1,jogador2);
            }
            if(a == 2){
                if(jogada % 2 == 0){
                    m[linha - 1][coluna - 1] = 'X';
                }
                else{
                    m[linha - 1][coluna - 1] = 'O';
                }
                //checavitoria(m,&jogada,jogador1,jogador2);
            }
            checavitoria(m,&jogada,jogador1,jogador2);

            jogada++;

        }while(jogada <= 9);
        printf ("Deseja jogar novamente S-Sim N-Nao : ");
        scanf ("%s",&vezes);
    }while (vezes == 'S' || vezes == 's');

    return 0;
}

void mostratabuleiro(char m[3][3]){
    int i,j;

    for(i = 0; i <3; i++){
        for(j = 0; j < 3; j++){
            printf (" %c |",m[i][j]);
        }
        printf ("\n");
    }
}

void checavitoria(char m[3][3],int *jogada,char jogador1[20],char jogador2[20]){
    int resultado;
    if(*jogada % 2 == 0){
        if(m[0][0] == 'O' && m[0][1] == 'O' && m[0][2] == 'O'){
            resultado = 2;
        }
        if(m[1][0] == 'O' && m[1][1] == 'O' && m[1][2] == 'O'){
            resultado = 2;
        }
        if(m[2][0] == 'O' && m[2][1] == 'O' && m[2][2] == 'O'){
            resultado = 2;
        }
        if(m[0][0] == 'O' && m[1][0] == 'O' && m[2][0] == 'O'){
            resultado = 2;
        }
        if(m[0][1] == 'O' && m[1][1] == 'O' && m[2][1] == 'O'){
            resultado = 2;
        }
        if(m[0][2] == 'O' && m[1][2] == 'O' && m[2][2] == 'O'){
            resultado = 2;
        }
        if(m[0][0] == 'O' && m[1][1] == 'O' && m[2][2] == 'O'){
            resultado = 2;
        }
        if(m[0][2] == 'O' && m[1][1] == 'O' && m[2][0] == 'O'){
            resultado = 2;
        }
    }
    if(*jogada % 2 != 0){
        if(m[0][0] == 'X' && m[0][1] == 'X' && m[0][2] == 'X'){
            resultado = 1;
        }
        if(m[1][0] == 'X' && m[1][1] == 'X' && m[1][2] == 'X'){
            resultado = 1;
        }
        if(m[2][0] == 'X' && m[2][1] == 'X' && m[2][2] == 'X'){
            resultado = 1;
        }
        if(m[0][0] == 'X' && m[1][0] == 'X' && m[2][0] == 'X'){
            resultado = 1;
        }
        if(m[0][1] == 'X' && m[1][1] == 'X' && m[2][1] == 'X'){
            resultado = 1;
        }
        if(m[0][2] == 'X' && m[1][2] == 'X' && m[2][2] == 'X'){
            resultado = 1;
        }
        if(m[0][0] == 'X' && m[1][1] == 'X' && m[2][2] == 'X'){
            resultado = 1;
        }
        if(m[0][2] == 'X' && m[1][1] == 'X' && m[2][0] == 'X'){
            resultado = 1;
        }
    }

    if(resultado == 2){
        printf ("\n%s venceu!\n\n",jogador2);
        *jogada = 9;
    }
    if(resultado == 1){
        printf ("\n%s venceu!\n\n",jogador1);
        mostratabuleiro(m);
        *jogada = 9;
    }
    if(resultado != 2 && resultado != 1 && *jogada >= 9){
        printf ("\nJogo empatado!\n\n");
        mostratabuleiro(m);
    }
}
