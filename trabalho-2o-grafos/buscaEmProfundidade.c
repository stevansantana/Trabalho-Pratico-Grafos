#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void buscaEmProfundidadeAux(int vertice, int **matriz, bool *visitados, int *niveis, int *pais, int numVertices, FILE *arquivoSaida)
{
    visitados[vertice] = true;

    for (int i = 0; i < numVertices; i++)
    {
        if (matriz[vertice][i] && !visitados[i])
        {
            niveis[i] = niveis[vertice] + 1;
            pais[i] = vertice;
            fprintf(arquivoSaida, "Vertice: %d - Nivel: %d - Pai: %d\n", i, niveis[i], vertice);
            buscaEmProfundidadeAux(i, matriz, visitados, niveis, pais, numVertices, arquivoSaida);
        }
    }
}

void buscaEmProfundidade(FILE *arquivo)
{
    // Pegar o número de vértices do arquivo
    int numVertices = 0;
    fscanf(arquivo, "%d", &numVertices);

    // Ler o vértice inicial para a busca
    int verticeInicial = 0;
    printf("Digite o vertice inicial para a busca em profundidade: ");
    scanf("%d", &verticeInicial);

    // Alocar matriz de adjacência
    int **matriz = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++)
    {
        matriz[i] = (int *)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++)
        {
            fscanf(arquivo, "%d", &matriz[i][j]);
        }
    }

    // Vetor de visitados
    bool *visitados = (bool *)malloc(numVertices * sizeof(bool));
    for (int i = 0; i < numVertices; i++)
        visitados[i] = false;

    // Vetor de níveis
    int *niveis = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++)
        niveis[i] = -1;

    // Vetor de pais
    int *pais = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++)
        pais[i] = -1;

    FILE *arquivoSaida = fopen("resultados/saida.txt", "a");
    if (arquivoSaida == NULL)
    {
        printf("Erro ao abrir o arquivo de saída!\n");
        return;
    }

    fprintf(arquivoSaida, "\nBusca em Profundidade:\n");
    fprintf(arquivoSaida, "Vértice: %d - Nível: 0 - Pai: -\n", verticeInicial);

    buscaEmProfundidadeAux(verticeInicial, matriz, visitados, niveis, pais, numVertices, arquivoSaida);

    fclose(arquivoSaida);
    free(visitados);
    free(niveis);
    free(pais);
    for (int i = 0; i < numVertices; i++)
        free(matriz[i]);
    free(matriz);
}





