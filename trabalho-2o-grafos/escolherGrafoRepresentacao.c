#include <stdio.h>
#include <stdlib.h>

void escolherGrafoRepresentacao()
{
    system("cls");
    int x;

    do
    {
        printf("\t\t\t\t\t\tMENU - ESCOLHA DE GRAFOS\n");
        printf("Aperte:\n\n");
        printf("0 - Para sair da representacao de grafos e finalizar o programa.\n");
        printf("1 - Para representar o grafo_1.txt.\n");
        printf("2 - Para representar o grafo_2.txt.\n");
        printf("3 - Para representar o grafo_3.txt.\n");
        printf("4 - Para representar o grafo_4.txt.\n");
        printf("5 - Para representar o grafo-teste.txt.\n");

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
                    escolherModoRepresentacao(grafo1);
                }
                else
                {
                    system("cls");
                    printf("Erro ao abrir o aquivo grafo_2.txt!\n");
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
                    escolherModoRepresentacao(grafo2);
                }
                else
                {
                    system("cls");
                    printf("Erro ao abrir o aquivo grafo_2.txt!\n");
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
                    escolherModoRepresentacao(grafo3);
                }
                else
                {
                    system("cls");
                    printf("Erro ao abrir o aquivo grafo_3.txt!\n");
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
                    escolherModoRepresentacao(grafo4);
                }
                else
                {
                    system("cls");
                    printf("Erro ao abrir o aquivo grafo_4.txt!\n");
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
                    escolherModoRepresentacao(grafoTeste);
                }
                else
                {
                    system("cls");
                    printf("Erro ao abrir o aquivo grafo_4.txt!\n");
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
