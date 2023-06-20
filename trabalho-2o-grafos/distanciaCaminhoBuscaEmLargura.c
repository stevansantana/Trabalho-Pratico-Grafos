#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int distancia;
    int pai;
} Vertice;

int encontrarMenorDistancia(Vertice *vertices, int *visitados, int numVertices) {
    int menorDistancia = -1;
    int verticeAtual = -1;

    for (int j = 0; j < numVertices; j++) {
        if (!visitados[j] && (menorDistancia == -1 || vertices[j].distancia < menorDistancia)) {
            menorDistancia = vertices[j].distancia;
            verticeAtual = j;
        }
    }

    return verticeAtual;
}

void distanciaMSTBuscaEmLargura(FILE *arquivo) {
    int numVertices;

    // Lendo o número de vértices do arquivo
    fscanf(arquivo, "%d", &numVertices);

    int **grafo = (int **) malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        grafo[i] = (int *) malloc(numVertices * sizeof(int));
    }

    // Lendo os valores do arquivo para o grafo
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            fscanf(arquivo, "%d", &grafo[i][j]);
        }
    }

    int verticeOrigem, verticeDestino;
    fscanf(arquivo, "%d %d", &verticeOrigem, &verticeDestino);

    Vertice *vertices = (Vertice *) malloc(numVertices * sizeof(Vertice));
    int *visitados = (int *) malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; i++) {
        vertices[i].id = i;
        vertices[i].distancia = -1;
        vertices[i].pai = -1;
        visitados[i] = 0;
    }

    vertices[verticeOrigem].distancia = 0;

    visitados[verticeOrigem] = 1;
    int *fila = (int *) malloc(numVertices * sizeof(int));
    int frente = 0;
    int tras = 0;
    fila[tras++] = verticeOrigem;

    while (frente < tras) {
        int verticeAtual = fila[frente++];

        if (verticeAtual == verticeDestino) {
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

    if (vertices[verticeDestino].pai != -1) {
        printf("Distância entre o vértice %d e o vértice %d: %d\n", verticeOrigem, verticeDestino, vertices[verticeDestino].distancia);

        printf("Caminho mínimo: ");
        int verticeAtual = verticeDestino;
        while (verticeAtual != -1) {
            printf("%d ", verticeAtual);
            verticeAtual = vertices[verticeAtual].pai;
        }
        printf("\n");
    } else {
        printf("Não foi possível alcançar o vértice de destino a partir do vértice de origem.\n");
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
