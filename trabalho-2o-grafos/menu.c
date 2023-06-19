#include <stdio.h>
#include <stdlib.h>

void menu()
{
    system("cls");
    int x;
    do
    {
        printf("\t\t\t\t\tMENU - TRABALHO PRATICO DE ALGORITMO DE GRAFOS\n");
        printf("Aperte:\n\n");
        printf("0 - Para sair do programa.\n");
        printf("1 - Para ler um grafo e gerar um arquivo texto com as informacoes do grafo.\n");
        printf("2 - Para representar um grafo.\n");
        printf("3 - Para percorrer um grafo.\n");
        printf("4 - Para descobrir os componentes conexos de um respectivo grafo.\n");

        scanf("%i", &x);

        switch(x)
        {
            case 0:
            {
                system("cls");
                printf("Programa finalizado.\n");
                system("pause");
                system("cls");
                break;
            }
            case 1:
            {
                lerGrafo();
                break;
            }
            case 2:
            {
                escolherGrafoRepresentacao();
                break;
            }
            case 3:
            {
                escolherGrafoBusca();
                break;
            }
            case 4:
            {
                break;
            }
            default:
            {
                system("cls");
                printf("\nDigito invalido! Digite novamente:\n");
                system("pause");
                system("cls");
                break;
            }
        }

    } while (x<0 || x>4);
}
