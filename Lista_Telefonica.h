#ifndef LISTA_TELEFONICA_H_INCLUDED
#define LISTA_TELEFONICA_H_INCLUDED
#define MAX 50

typedef struct lista_tel{
    char nome[51];
    char tel[10];
}Contato;

Contato* cria_lst(Contato *lst);
int Testa_lst(Contato *lst);
void listar(Contato *lst, int num_contatos);
void insere(Contato *lst, int pos, int num_contatos);
void retira(Contato *lst, int pos, int num_contatos);

#endif // LISTA_TELEFONICA_H_INCLUDED
