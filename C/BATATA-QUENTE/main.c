#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>

int novojogo(int *batata,int *posicao, int *primeiro,int *jogadores);
int erro(int *batata,int *posicao, int *primeiro,int *jogadores);
int venceu(int *batata,int *posicao, int *primeiro,int *jogadores);
int perdeu(int *batata,int *posicao, int *primeiro,int *jogadores);
int jogo(int *batata,int *posicao, int *primeiro,int *jogadores);
int randm(int *batata,int *posicao, int *primeiro,int *jogadores);

int novojogo(int *batata,int *posicao, int *primeiro,int *jogadores){
    char esc;
    system("cls");
    printf("\n\tjogar novamente - S/ENTER \n\tsair - demais teclas \n\n\n\tescolha: ");
    Sleep(1000);
    fflush(stdin);
    scanf("%c",&esc);
    ((esc=='S' || esc =='s') || esc =='\n')?randm(batata,posicao,primeiro,jogadores):erro(batata,posicao,primeiro,jogadores);
    return 0;
}
int erro(int *batata,int *posicao, int *primeiro,int *jogadores){
    system("color 09");
    system("cls");
    for(int j=0;j<=2;j++){
        printf("\nOPÇÃO INVÁLIDA");
        Sleep(300);
    }
    novojogo(batata,posicao,primeiro,jogadores);
    return 0;
}
int venceu(int *batata,int *posicao, int *primeiro,int *jogadores){
    Sleep(2500);
    system("color 02");
    system("cls");
    printf("\n\tVOCÊ VENCEU\n");
    Sleep(2700);
    novojogo(batata,posicao,primeiro,jogadores);
    return 0;
}
int perdeu(int *batata,int *posicao, int *primeiro,int *jogadores){
    Sleep(2500);
    system("cls");
    system("color 04");
    printf("\n\n\tSua batata assou. Obrigado por participar");
    Sleep(2700);
    novojogo(batata,posicao,primeiro,jogadores);
    return 0;
}
int jogo(int *batata,int *posicao, int *primeiro,int *jogadores){
    do{
        (*primeiro==1)?printf("Sua vez\n"):printf("rival %d\n",*primeiro-1);
        (*primeiro==1)?system("pause"):*primeiro;
        Sleep(300);
        if(*batata==*posicao){
            if(*primeiro==1){
                system("color 04");
                printf("queimou\n\n");
                perdeu(batata,posicao,primeiro,jogadores);
            }else {
                system("color 09");
                printf("queimou\n\n");
                venceu(batata,posicao,primeiro,jogadores);
            }
        }else {
            if(*primeiro==1){
            printf("jogador tenta passar\n");
            Sleep(300);
            printf("passou a batata\n\n");
            printf("***********************************************\n\n");
        }else {
            printf("rival %d tenta passar\n",*primeiro-1);
            Sleep(300);
            printf("passou a batata\n\n");
            printf("***********************************************\n\n");
        }
            *posicao-=1;
            (*posicao==0)?*posicao=6:*posicao;
        }
        *primeiro-=1;
        (*primeiro==0)?*primeiro = *jogadores:*primeiro;
        Sleep(200);
    }while(1);
    return 0;
}
int randm(int *batata,int *posicao, int *primeiro,int *jogadores){
    int aux1;
    system("cls");
    system("color 02");
    printf("BATATA-QUENTE - O CONFRONTO FINAL\n\tDESENVOLVEDOR: RENATO COSTA\n\n");
    Sleep(300);
    printf("REGRA: Passe a batata antes que ela fique quente, na sua vez aperte qualquer botão\n\tQuantos jogadores?\n\t(de 3 ou 4):  ");
        fflush(stdin);
        scanf("%d",&aux1);
        *jogadores=aux1;
            printf("***********************************************\n\n");
    (*jogadores==3 || *jogadores==4)?*jogadores:erro(batata,posicao,primeiro,jogadores);
    srand(time(NULL));
    *batata = rand();
    while(*batata>5 && *batata!=0){
        *batata-=3;
            (*batata<0 && *batata!=0)?*batata+=3:*batata;
    }
    *posicao = rand();
    while(*posicao>11 && *posicao!=0){
        *posicao-=2;
        (*posicao<0 && *posicao!=0)?*posicao+=7:*posicao;
    }
    *primeiro = rand();
    while(*primeiro>*jogadores && *primeiro!=0){
        *primeiro-=3;
        (*primeiro<0 && *primeiro!=0)?*primeiro+=2:*primeiro;
    }
    jogo(batata,posicao,primeiro,jogadores);
    return 0;
}
int main(){
    system("TITLE BATATA-QUENTE - O CONFRONTO FINAL \nv0.1");
    HWND console = GetConsoleWindow();
    ShowWindow(console, SW_MAXIMIZE);
    setlocale(LC_ALL,"");
    int jogadores,batata,posicao,primeiro;
    system("color 02");
    randm(&batata,&posicao,&primeiro,&jogadores);
    return 0;
}
