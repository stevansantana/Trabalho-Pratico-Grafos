#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int distancia;
    int pai;
} Vertice;

void distanciaTodosBuscaEmLargura(FILE *arquivo) {
    int numVertices;
    fscanf(arquivo, "%d", &numVertices);

    // Vetor de vértices
    Vertice *vertices = (Vertice *) malloc(numVertices * sizeof(Vertice));

    // Vetor de visitados
    int *visitados = (int *) malloc(numVertices * sizeof(int));

    // Inicialização dos vértices
    for (int i = 0; i < numVertices; i++) {
        vertices[i].id = i;
        vertices[i].distancia = -1;
        vertices[i].pai = -1;
        visitados[i] = 0;
    }

    int verticeOrigem;
    fscanf(arquivo, "%d", &verticeOrigem);

    // Atribuição da distância e do pai do vértice de origem
    vertices[verticeOrigem].distancia = 0;

    // Algoritmo de busca em largura
    visitados[verticeOrigem] = 1;
    int fila[numVertices];
    int frente = 0;
    int tras = 0;
    fila[tras++] = verticeOrigem;

    while (frente < tras) {
        int verticeAtual = fila[frente++];

        for (int i = 0; i < numVertices; i++) {
            int adjacencia;
            fscanf(arquivo, "%d", &adjacencia);

            if (adjacencia && !visitados[i]) {
                visitados[i] = 1;
                vertices[i].distancia = vertices[verticeAtual].distancia + 1;
                vertices[i].pai = verticeAtual;
                fila[tras++] = i;
            }
        }
    }

    // Impressão dos resultados para todos os vértices
    printf("Distancias a partir do vertice %d:\n", verticeOrigem);
    printf("Vertice\t\tDistancia\tCaminho minimo\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d\t\t%d\t\t", i, vertices[i].distancia);
        int verticeAtual = i;
        while (verticeAtual != -1) {
            printf("%d ", verticeAtual);
            verticeAtual = vertices[verticeAtual].pai;
        }
        printf("\n");
    }

    // Liberação de memória
    free(vertices);
    free(visitados);
}
