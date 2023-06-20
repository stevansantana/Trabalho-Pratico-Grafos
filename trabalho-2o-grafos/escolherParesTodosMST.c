#include <stdio.h>
#include <stdlib.h>

void escolherParesTodosMST(FILE *arquivo)
{
    system("cls");
    int x;

    do
    {
        printf("Aperte:\n\n");
        printf("0 - Para sair da escolha de caminho minimo e finalizar o programa!\n");
        printf("1 - Para encontrar distancia e caminho com largura usando pares de vertice em grafo sem peso.\n");
        printf("2 - Para encontrar distancia e caminho com dijkstra usando pares em grafo com peso.\n");
        printf("3 - Para encontrar distancia e caminho com largura usando todos os vertices em grafo sem peso.\n");
        printf("4 - Para encontrar distancia e caminho com dijkstra usando todos os vertices em grafo com peso.\n");

        scanf("%d", &x);
        switch(x)
        {
        case 0:
            {
                system("cls");
                printf("Nenhuma opcao de distancia foi escolhida! Programa finalizado!\n");
                system("pause");
                system("cls");
                exit(0);
                break;
            }
        case 1:
            {
                distanciaMSTBuscaEmLargura(arquivo);
                break;
            }
        case 2:
            {
                distanciaMSTDijkstra(arquivo);
                break;
            }
        case 3:
            {
                distanciaTodosBuscaEmLargura(arquivo);
                break;
            }
        case 4:
            {
                distanciaTodosDijkstra(arquivo);
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
