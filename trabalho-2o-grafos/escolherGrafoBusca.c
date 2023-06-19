#include <stdio.h>
#include <stdlib.h>

void escolherGrafoBusca()
{
    system("cls");
    int x;

    do
    {
        printf("\t\t\t\t\t\tMENU - ESCOLHA DE GRAFOS\n");
        printf("Aperte:\n\n");
        printf("0 - Para sair do percorrimento de grafos e finalizar o programa.\n");
        printf("1 - Para percorrer o grafo_1.txt.\n");
        printf("2 - Para percorrer o grafo_2.txt.\n");
        printf("3 - Para percorrer o grafo_3.txt.\n");
        printf("4 - Para percorrer o grafo_4.txt.\n");
        printf("5 - Para percorrer o grafo-teste.txt.\n");

        scanf("%i", &x);

        switch(x)
        {
            case 0:
            {
                system("cls");
                printf("Nenhum grafo foi escolhido! Programa finalizado!\n");
                system("pause");
                system("cls");
                exit(0);
                break;
            }
            case 1:
            {
                system("cls");
                FILE *grafo1 = fopen("grafo_1.txt", "r");

                if(grafo1 != NULL)
                {
                    escolherModoBusca(grafo1);
                }
                else
                {
                    system("cls");
                    printf("Erro ao abrir o arquivo grafo_1.txt!\n");
                    system("pause");
                    system("cls");
                    exit(1);
                }
                break;
            }
            case 2:
            {
                system("cls");
                FILE *grafo2 = fopen("grafo_2.txt", "r");

                if(grafo2 != NULL)
                {
                    escolherModoBusca(grafo2);
                }
                else
                {
                    system("cls");
                    printf("Erro ao abrir o arquivo grafo_2.txt!\n");
                    system("pause");
                    system("cls");
                    exit(1);
                }
                break;
            }
            case 3:
            {
                system("cls");
                FILE *grafo3 = fopen("grafo_3.txt", "r");

                if(grafo3 != NULL)
                {
                    escolherModoBusca(grafo3);
                }
                else
                {
                    system("cls");
                    printf("Erro ao abrir o arquivo grafo_3.txt!\n");
                    system("pause");
                    system("cls");
                    exit(1);
                }
                break;
            }
            case 4:
            {
                system("cls");
                FILE *grafo4 = fopen("grafo_4.txt", "r");

                if(grafo4 != NULL)
                {
                    escolherModoBusca(grafo4);
                }
                else
                {
                    system("cls");
                    printf("Erro ao abrir o arquivo grafo_4.txt!\n");
                    system("pause");
                    system("cls");
                    exit(1);
                }
                break;
            }
            case 5:
            {
                system("cls");
                FILE *grafoTeste = fopen("grafo-teste.txt", "r");

                if(grafoTeste != NULL)
                {
                    escolherModoBusca(grafoTeste);
                }
                else
                {
                    system("cls");
                    printf("Erro ao abrir o arquivo grafo-teste.txt!\n");
                    system("pause");
                    system("cls");
                    exit(1);
                }
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
    } while (x<0 || x>5);

}
