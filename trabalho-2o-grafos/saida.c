#include <stdio.h>
#include <stdlib.h>

void saida(int numVertices, int numArestas, int menorGrau, int maiorGrau, double grauMedio, double listaDistribuicaoEmpirica[])
{
    FILE *arquivoSaida = fopen("saida.txt", "w");
    if(arquivoSaida == NULL)
    {
        printf("Erro na criacao do arquivo de saida\n");
        system("pause");
        exit(1);
    }

    fprintf(arquivoSaida, "# n = %d\n", numVertices);
    fprintf(arquivoSaida, "# m = %d\n", numArestas);
    fprintf(arquivoSaida, "# d_medio = %.2f\n", grauMedio);

    int cont=0;
    for(int i=menorGrau; i<=maiorGrau; i++)
    {
        if(listaDistribuicaoEmpirica[cont]==0)
        {
            fprintf(arquivoSaida, "%d %d\n", i, 0);
            cont++;
        }
        else
        {
            fprintf(arquivoSaida, "%d %.6f\n", i, listaDistribuicaoEmpirica[cont]);
            cont++;
        }
    }

    fclose(arquivoSaida);
}
