#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Lista_Telefonica.h"

int main()
{
    setlocale(LC_ALL, "");

    Contato* lst;
    lst = cria_lst(lst);
    int qtd_contatos = 0;
    char s[30];
    int x, v;

    while(1){
        system("cls");
        menu();
        do{
            printf("\n\nDigite o que deseja: ");
            fflush(stdin);
            gets(s);
            x = atoi(s);
        }while(x < 1 || x > 4);

        if(x == 1){
            system("cls");
            listar(lst, qtd_contatos);
            qtd_contatos++;
            do{
                printf("\n\nEntre com a posi��o que deseja inserir o contato na lista: ");
                fflush(stdin);
                gets(s);
                v = atoi(s);
            }while(v < 1 || v > 50);

            insere(lst, v, qtd_contatos);

            printf("\n");
            system("pause");
            continue;
        }
        if(x == 2){
           system("cls");
           if(qtd_contatos == 0){
                printf("\nN�o tem nenhum contato na lista telef�nica...\n\n");
                system("pause");
                continue;
            }

           listar(lst, qtd_contatos);

           printf("\n");
           system("pause");
           continue;
        }
        if(x == 3){
            system("cls");
            if(qtd_contatos == 0){
                printf("\nN�o tem nenhum contato na lista telef�nica...\n\n");
                system("pause");
                continue;
            }

            listar(lst, qtd_contatos);
            do{
                printf("\nDigite qual contato deseja retirar: ");
                gets(s);
                v = atoi(s);
            }while(v < 1 || v > qtd_contatos);

            retira(lst, v, qtd_contatos);

            printf("\n");
            system("pause");
            continue;
        }
        if(x == 4)
            break;
    }

    return 0;
}
