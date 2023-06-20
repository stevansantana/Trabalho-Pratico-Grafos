#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int distancia;
    int pai;
} Vertice;

void distanciaMSTDijkstra(FILE *arquivo) {
    int numVertices;
    fscanf(arquivo, "%d", &numVertices);

    // Alocar matriz de adjacência
    int **grafo = (int **) malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        grafo[i] = (int *) malloc(numVertices * sizeof(int));
    }

    // Ler grafo do arquivo
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            fscanf(arquivo, "%d", &grafo[i][j]);
        }
    }

    int verticeOrigem, verticeDestino;
    fscanf(arquivo, "%d %d", &verticeOrigem, &verticeDestino);

    // Vetor de vértices
    Vertice *vertices = (Vertice *) malloc(numVertices * sizeof(Vertice));

    // Vetor de visitados
    int *visitados = (int *) malloc(numVertices * sizeof(int));

    // Inicialização dos vértices
    for (int i = 0; i < numVertices; i++) {
        vertices[i].id = i;
        vertices[i].distancia = -1;  // Utilizaremos -1 para representar a distância infinita
        vertices[i].pai = -1;
        visitados[i] = 0;
    }

    // Atribuição da distância e do pai do vértice de origem
    vertices[verticeOrigem].distancia = 0;

    // Algoritmo de Dijkstra
    for (int i = 0; i < numVertices - 1; i++) {
        int menorDistancia = -1;
        int verticeAtual = -1;

        // Encontra o vértice não visitado com a menor distância
        for (int j = 0; j < numVertices; j++) {
            if (!visitados[j] && (menorDistancia == -1 || vertices[j].distancia < menorDistancia)) {
                menorDistancia = vertices[j].distancia;
                verticeAtual = j;
            }
        }

        if (verticeAtual == -1) {
            break;  // Sai do loop caso não haja mais vértices não visitados
        }

        visitados[verticeAtual] = 1;

        // Atualiza a distância dos vértices adjacentes não visitados
        for (int j = 0; j < numVertices; j++) {
            if (grafo[verticeAtual][j] && !visitados[j]) {
                int distancia = vertices[verticeAtual].distancia + grafo[verticeAtual][j];

                if (vertices[j].distancia == -1 || distancia < vertices[j].distancia) {
                    vertices[j].distancia = distancia;
                    vertices[j].pai = verticeAtual;
                }
            }
        }
    }

    // Verifica se foi possível alcançar o vértice de destino
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

    // Liberar memória
    for (int i = 0; i < numVertices; i++) {
        free(grafo[i]);
    }
    free(grafo);
    free(vertices);
    free(visitados);
}
