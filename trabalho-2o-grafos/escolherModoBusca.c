#include <stdio.h>
#include <stdlib.h>

void escolherModoBusca(FILE *arquivo)
{
    system("cls");
    int x;

    do
    {
        printf("Aperte:\n\n");
        printf("0 - Para sair da escolha de busca e finalizar o programa!\n");
        printf("1 - Para realizar a busca em largura no grafo.\n");
        printf("2 - Para realizar a busca em profundidade no grafo.\n");

        scanf("%d", &x);
        switch(x)
        {
        case 0:
            {
                system("cls");
                printf("Nenhuma busca foi selecionada! Programa finalizado!\n");
                system("pause");
                system("cls");
                exit(0);
                break;
            }
        case 1:
            {
                buscaEmLargura(arquivo);
                break;
            }
        case 2:
            {
                buscaEmProfundidade(arquivo);
                break;
            }
        default:
            {
                system("cls");
                printf("Digito invalido! Digite novamente!\n");
                system("pause");
                system("cls");
                break;
            }
        }

    } while(x < 0 || x > 2);
}
