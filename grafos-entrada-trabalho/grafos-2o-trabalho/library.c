#include <stdio.h>
#include <stdlib.h>

int menu()
{
    system("cls");
    int x;
    do
    {
        printf("\t\t\t\t\t\tMENU - TRABALHO PRATICO DE ALGORITMO DE GRAFOS\n");
        printf("Aperte:\n\n");
        printf("0 - Para sair do programa.\n");
        printf("1 - Para ler um grafo a partir de um arquivo texto.\n");
        printf("2 - Para gerar um arquivo texto com as informações do respectivo grafo.\n");
        printf("3 - Para representar o grafo.\n");
        printf("4 - Para percorrer o grafo.\n");
        printf("5 - Para descobrir os componentes conexos do respectivo grafo.\n");

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
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
            default:
            {
                system("cls");
                printf("\nDigito invalido! Informe novamente:\n");
                system("pause");
                system("cls");
                break;
            }
        }

    } while (x!=0);

    return x;
}

void entrada()
{
    FILE *f = fopen("grafo_1.txt", "r");
    if(f == NULL)
    {
        printf("Erro na abertura do arquivo grafo_1.txt");
        system("pause");
        exit(1);
    }



    fclose(f);
}