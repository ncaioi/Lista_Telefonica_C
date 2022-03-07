#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Lista_Telefonica.h"

void menu(void);

Contato* cria_lst(Contato *lst){

    Contato *p = lst;

    p = (Contato*) calloc(MAX, sizeof(Contato));
    if(p == NULL){
        printf("\nMem�ria Insuficiente!\n");
        system("pause");
        exit(1);
    }

    return p;

}

void listar(Contato *lst, int num_contatos){

    Contato *p;
    p = lst;
    char s[51]; ///string s do tamanho do nome do tad.
    s[0] = '\0';
    int i = 0, j = num_contatos;

    while(i < j){
        if(strcmp(p[i].nome, s) != 0){
            printf(" (%i) \t%s\t\t\t\t %s \n", i + 1, p[i].nome, p[i].tel);
            i++;
        }else
            i++;
    }


}

void insere(Contato *lst, int pos, int num_contatos){

    int i = pos - 1;
    int j = num_contatos;
    char s[51];
    s[0] = '\0';
    Contato* p = lst;

    if(strcmp(p[i].nome, s) == 0){
        printf("\nDigite o nome do contato: ");
        fflush(stdin);
        scanf("%[^\n]s", p[i].nome);
        printf("\nDigite o n�mero de telefone do %s: ", p[i].nome);
        fflush(stdin);
        scanf("%s", p[i].tel);
    }else{
        while(j > i){
            strcpy(p[j].nome, p[j-1].nome); ///Caso o usu�rio deseje inserir em uma posi��o ja ocupada
            strcpy(p[j].tel, p[j-1].tel);  ///o la�o vai copiando nome e telefone de quem ta acima
            j--;
        }
        printf("\nDigite o nome do contato: ");
        fflush(stdin);
        scanf("%[^\n]s", p[i].nome);
        printf("\nDigite o n�mero de telefone do %s: ", p[i].nome);
        fflush(stdin);
        scanf("%s", p[i].tel);
    }

}

void retira(Contato *lst, int pos, int num_contatos){

    Contato* p = lst;
    int i = pos - 1;
    int n = num_contatos - 1;

    if(i == MAX - 1){
        p[i].nome[0] = '\0'; ///Caso retire na posi��o 49.
        p[i].tel[0] = '\0';
    }
    for(;i < n; i++)
        p[i] = p [i+1]; ///Subindo os contatos 1 por 1, da posi��o removida at� o n�mero de contatos registrados.

    p[i].nome[0] = '\0';
    p[i].tel[0] = '\0';

}

void menu(void){

    printf("\n\n\t1 - Inserir contato na lista telef�nica");
    printf("\n\n\t2 - Listar contato na lista telef�nica");
    printf("\n\n\t3 - Remover contato da lista telef�nica");
    printf("\n\n\t4 - Sair");

}
