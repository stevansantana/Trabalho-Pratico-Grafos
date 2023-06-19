#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void buscaEmLargura(FILE *arquivo)
{
    // Pegar o número de vértices do arquivo
    int numVertices = 0;
    fscanf(arquivo, "%d", &numVertices);

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

    // Fila para armazenar os vértices a serem visitados
    int *fila = (int *)malloc(numVertices * sizeof(int));
    int frente = 0;
    int tras = 0;

    int verticeInicial;
    printf("Digite o vertice inicial para a busca em largura: ");
    scanf("%d", &verticeInicial);

    // Marcar o vértice inicial como visitado e definir seu nível como 0
    visitados[verticeInicial] = true;
    niveis[verticeInicial] = 0;
    fila[tras++] = verticeInicial;

    FILE *arquivoSaida = fopen("resultados/saida.txt", "a");
    if (arquivoSaida == NULL)
    {
        printf("Erro ao abrir o arquivo de saída!\n");
        return;
    }

    // Cabeçalho do arquivo de saída
    fprintf(arquivoSaida, "\nBusca em Largura:\n");
    fprintf(arquivoSaida, "Vertice\t\tNivel\t\tPai\n");
    fprintf(arquivoSaida, "%d\t\t%d\t\t-\n", verticeInicial, 0);

    while (frente < tras)
    {
        int verticeAtual = fila[frente++];

        // Percorrer os vizinhos do vértice atual
        for (int i = 0; i < numVertices; i++)
        {
            if (matriz[verticeAtual][i] && !visitados[i])
            {
                visitados[i] = true;
                niveis[i] = niveis[verticeAtual] + 1;
                pais[i] = verticeAtual;
                fila[tras++] = i;

                fprintf(arquivoSaida, "Vértice: %d - Nível: %d - Pai: %d\n", i, niveis[i], verticeAtual);
            }
        }
    }

    fclose(arquivoSaida);
    free(fila);
    free(visitados);
    free(niveis);
    free(pais);
    for (int i = 0; i < numVertices; i++)
        free(matriz[i]);
    free(matriz);
}
