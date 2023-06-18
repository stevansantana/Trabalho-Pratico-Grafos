#include <stdio.h>
#include <stdlib.h>

void escolherModoRepresentacao(FILE *arquivo)
{
    system("cls");
    int x;

    do
    {
        printf("Aperte:\n\n");
        printf("0 - Para sair da escolha de representacao e finalizar o programa!\n");
        printf("1 - Para representar pela matriz de adjacencia com grafo com peso.\n");
        printf("2 - Para representar pela matriz de adjacencia com grafo sem peso.\n");
        printf("3 - Para representar pela lista de adjacencia com grafo com peso.\n");
        printf("4 - Para representar pela lista de adjacencia com grafo sem peso.\n");

        scanf("%d", &x);
        switch(x)
        {
        case 0:
            {
                system("cls");
                printf("Nenhum representacao foi escolhida! Programa finalizado!\n");
                system("pause");
                system("cls");
                exit(0);
                break;
            }
        case 1:
            {
                matrizAdjancenciaComPeso(arquivo);
                break;
            }
        case 2:
            {
                matrizAdjancenciaSemPeso(arquivo);
                break;
            }
        case 3:
            {
                listaAjacenciaComPeso(arquivo);
                break;
            }
        case 4:
            {
                listaAdjacenciaSemPeso(arquivo);
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

    }while(x<0 || x>4);
}
