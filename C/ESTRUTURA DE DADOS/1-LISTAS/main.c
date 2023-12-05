#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

typedef struct No{
    char nome[150];
    char CPF[16];
    struct No *proximo;
}NO;

NO* inicia(){
    return NULL;
}
NO* incluir(NO* pessoa){
    NO* NO_NOVO = (NO*)malloc(sizeof(NO));
    char nome_t[150];
    char cpf_t[15];
    system("cls");
    printf("digite nome: ");
        fflush(stdin);
        scanf("%149[^\n]",nome_t);
        fflush(stdin);
    printf("digite o CPF: ");
        fflush(stdin);
        scanf("%15[^\n]",cpf_t);
        fflush(stdin);
    strcpy(NO_NOVO->nome,nome_t);
    strcpy(NO_NOVO->CPF,cpf_t);
    NO_NOVO->proximo=pessoa;
    return NO_NOVO;
}
NO* retirar(NO* pessoa){
    NO* anterior = NULL;
    NO* aux = pessoa;
    char nomeaux[149];
    printf("digite o nome para retirar: \n");
        fflush(stdin);
        scanf("%149[^\n]",nomeaux);
        fflush(stdin);
        while(aux !=NULL && strcmp(aux->nome,nomeaux)){
            anterior = aux;
            aux = aux->proximo;
        }
        if(aux == NULL){
            return pessoa;
        }
        if(anterior == NULL){
            pessoa = aux->proximo;
        }else{
            anterior->proximo = aux->proximo;
        }
    free(aux);
    return pessoa;
}
int busca(NO* pessoa){
    NO* aux;
    system("cls");
    char nomeaux[149];
    printf("digite o nome para busca: \n");
        fflush(stdin);
        scanf("%149[^\n]",nomeaux);
        fflush(stdin);
        printf("buscando...");
    for(aux=pessoa;aux!=NULL;aux=aux->proximo){
        if(strcmp(aux->nome,nomeaux)){

        }else{
            printf("nome: %s",aux->nome);
            printf("\nCPF: %s\n\n",aux->CPF);
        }
    }
    free(aux);
    system("pause");
    return 0;
}
int imprime(NO *pessoa){
    NO *aux = pessoa;
    system("cls");
    while(aux!=NULL){
        printf("nome: %s",aux->nome);
        printf("\nCPF: %s\n\n",aux->CPF);
        aux=aux->proximo;
    }
    free(aux);
    system("pause");
    return 0;
}
NO* limpa(NO* pessoa){
    NO* aux=pessoa;
    while(aux!=NULL){
        NO* prox_pessoa = aux->proximo;
        free(aux);
        aux=prox_pessoa;
    }
    inicia(aux);
    return aux;
}
int menu(NO* pessoa){
    int opM;
    system("cls");
    printf("SELECIONE: \n");
    printf("aqui está uma linha de código, teste ç e ă");
    printf("1 - NOVO CADASTRO     \n2 - RETIRAR CADASTRO     \n3 - BUSCAR     \n4 - MOSTRAR LISTA     \n5 - LIMPAR LISTA     \n6 - SAIR\n\n");
    printf("escolha: ");
        fflush(stdin);
            scanf("%d",&opM);
        switch(opM){
            case 1:
                pessoa=incluir(pessoa);
            break;
            case 2:
                retirar(pessoa);
            break;
            case 3:
                busca(pessoa);
            break;
            case 4:
                imprime(pessoa);
            break;
            case 5:
                limpa(pessoa);
            break;
            case 6:
                return 0;
            break;
            default:
                printf("\n\nopçăo inválida");
                Sleep(350);
                system("cls");
                menu(pessoa);
        }
        menu(pessoa);
    return 0;
}
int main(){
    system("TITLE LISTAS LIGADAS ");
    setlocale(LC_ALL,"Portuguese");;
    system("color 02");
    NO *pessoa;
    pessoa=inicia();
    menu(pessoa);
    return 0;
}
