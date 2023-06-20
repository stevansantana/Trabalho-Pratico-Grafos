#include <stdio.h>
#include <stdlib.h>

void buscaEmLargura(FILE *arquivo)
{
    // Pegar o n�mero de v�rtices do arquivo
    int numVertices = 0;
    fscanf(arquivo, "%d", &numVertices);

    // Alocar matriz de adjac�ncia
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
    int *visitados = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++)
        visitados[i] = 0;

    // Vetor de n�veis
    int *niveis = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++)
        niveis[i] = -1;

    // Vetor de pais
    int *pais = (int *)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++)
        pais[i] = -1;

    // Fila para armazenar os v�rtices a serem visitados
    int *fila = (int *)malloc(numVertices * sizeof(int));
    int frente = 0;
    int tras = 0;

    int verticeInicial;
    printf("Digite o v�rtice inicial para a busca em largura: ");
    scanf("%d", &verticeInicial);

    // Marcar o v�rtice inicial como visitado e definir seu n�vel como 0
    visitados[verticeInicial] = 1;
    niveis[verticeInicial] = 0;
    fila[tras++] = verticeInicial;

    FILE *arquivoSaida = fopen("resultados/saida.txt", "a");
    if (arquivoSaida == NULL)
    {
        printf("Erro ao abrir o arquivo de sa�da!\n");
        return;
    }

    fprintf(arquivoSaida, "\nBusca em Largura:\n");
    fprintf(arquivoSaida, "V�rtice: %d - N�vel: %d - Pai: -\n", verticeInicial, 0);

    while (frente < tras)
    {
        int verticeAtual = fila[frente++];

        // Percorrer os vizinhos do v�rtice atual
        for (int i = 0; i < numVertices; i++)
        {
            if (matriz[verticeAtual][i] && visitados[i] == 0)
            {
                visitados[i] = 1;
                niveis[i] = niveis[verticeAtual] + 1;
                pais[i] = verticeAtual;
                fila[tras++] = i;

                fprintf(arquivoSaida, "V�rtice: %d - N�vel: %d - Pai: %d\n", i, niveis[i], verticeAtual);
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
