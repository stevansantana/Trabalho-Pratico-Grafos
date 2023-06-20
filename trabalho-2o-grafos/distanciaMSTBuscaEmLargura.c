#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int distancia;
    int pai;
} Vertice;

void distanciaMSTBuscaEmLargura(FILE *arquivo) {
    int numVertices;

    // Lendo o número de vértices do arquivo
    fscanf(arquivo, "%d", &numVertices);

    int **grafo = (int **) malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        grafo[i] = (int *) malloc(numVertices * sizeof(int));
    }

    // Inicializando a matriz de adjacência com zeros
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            grafo[i][j] = 0;
        }
    }

    // Lendo as arestas do arquivo e preenchendo a matriz de adjacência
    int verticeOrigem, verticeDestino;
    while (fscanf(arquivo, "%d %d", &verticeOrigem, &verticeDestino) == 2) {
        grafo[verticeOrigem - 1][verticeDestino - 1] = 1;
        grafo[verticeDestino - 1][verticeOrigem - 1] = 1;
    }

    Vertice *vertices = (Vertice *) malloc(numVertices * sizeof(Vertice));
    int *visitados = (int *) malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; i++) {
        vertices[i].id = i;
        vertices[i].distancia = -1;
        vertices[i].pai = -1;
        visitados[i] = 0;
    }

    // Lendo o vértice de origem e destino
    fscanf(arquivo, "%d %d", &verticeOrigem, &verticeDestino);

    vertices[verticeOrigem - 1].distancia = 0;

    visitados[verticeOrigem - 1] = 1;
    int *fila = (int *) malloc(numVertices * sizeof(int));
    int frente = 0;
    int tras = 0;
    fila[tras++] = verticeOrigem - 1;

    while (frente < tras) {
        int verticeAtual = fila[frente++];

        if (verticeAtual == verticeDestino - 1) {
            break;
        }

        for (int i = 0; i < numVertices; i++) {
            if (grafo[verticeAtual][i] && !visitados[i]) {
                visitados[i] = 1;
                vertices[i].distancia = vertices[verticeAtual].distancia + 1;
                vertices[i].pai = verticeAtual;
                fila[tras++] = i;
            }
        }
    }

    if (vertices[verticeDestino - 1].pai != -1) {
        printf("Distancia entre o vertice %d e o vertice %d: %d\n", verticeOrigem, verticeDestino, vertices[verticeDestino - 1].distancia);

        printf("Caminho minimo: ");
        int verticeAtual = verticeDestino - 1;
        while (verticeAtual != -1) {
            printf("%d ", verticeAtual + 1);
            verticeAtual = vertices[verticeAtual].pai;
        }
        printf("\n");
    } else {
        printf("Nao foi possivel alcancar o vertice de destino a partir do vertice de origem.\n");
    }

    // Liberação de memória
    for (int i = 0; i < numVertices; i++) {
        free(grafo[i]);
    }
    free(grafo);
    free(vertices);
    free(visitados);
    free(fila);
}

