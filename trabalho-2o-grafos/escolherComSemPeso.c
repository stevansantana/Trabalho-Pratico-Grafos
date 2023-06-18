#include <stdio.h>
#include <stdlib.h>

void escolherComSemPeso(FILE *arquivo)
{
    system("cls");
    int x=0;

    do
    {
        printf("\t\t\t\t\t\tMENU - ESCOLHA DE PESO\n");
        printf("Aperte:\n\n");
        printf("0 - Para sair do programa\n");
        printf("1 - Para ler o grafo selecionado com peso\n");
        printf("2 - Para ler o grafo selecionado sem peso\n");

        scanf("%i", &x);

        switch(x)
        {
            case 0:
            {
                system("cls");
                printf("Programa finalizado!\n");
                system("pause");
                system("cls");
                exit(0);
                break;
            }
            case 1:
            {
                system("cls");
                printf("Leitura de grafo com peso selecionada!\n");
                system("pause");
                lerGrafoComPeso(arquivo);
                break;
            }
            case 2:
            {
                system("cls");
                printf("Leitura de grafo sem peso selecionada!\n");
                system("pause");
                lerGrafoSemPeso(arquivo);
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

    }while(x<0 || x>2);
}
