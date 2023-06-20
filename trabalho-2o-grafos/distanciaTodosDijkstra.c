#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int distancia;
    int pai;
} Vertice;

void distanciaTodosDijkstra(FILE *arquivo) {
    int numVertices;

    // Lendo o n�mero de v�rtices do arquivo
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

    int verticeOrigem;
    fscanf(arquivo, "%d", &verticeOrigem);

    // Vetor de v�rtices
    Vertice *vertices = (Vertice *) malloc(numVertices * sizeof(Vertice));

    // Vetor de visitados
    int *visitados = (int *) malloc(numVertices * sizeof(int));

    // Inicializa��o dos v�rtices
    for (int i = 0; i < numVertices; i++) {
        vertices[i].id = i;
        vertices[i].distancia = -1;  // Utilizaremos -1 para representar a dist�ncia infinita
        vertices[i].pai = -1;
        visitados[i] = 0;
    }

    // Atribui��o da dist�ncia e do pai do v�rtice de origem
    vertices[verticeOrigem].distancia = 0;

    // Algoritmo de Dijkstra
    for (int i = 0; i < numVertices - 1; i++) {
        int menorDistancia = -1;
        int verticeAtual = -1;

        // Encontra o v�rtice n�o visitado com a menor dist�ncia
        for (int j = 0; j < numVertices; j++) {
            if (!visitados[j] && (menorDistancia == -1 || vertices[j].distancia < menorDistancia)) {
                menorDistancia = vertices[j].distancia;
                verticeAtual = j;
            }
        }

        if (verticeAtual == -1) {
            break;  // Sai do loop caso n�o haja mais v�rtices n�o visitados
        }

        visitados[verticeAtual] = 1;

        // Atualiza a dist�ncia dos v�rtices adjacentes n�o visitados
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

    // Impress�o dos resultados
    printf("Distancias a partir do vertice %d:\n", verticeOrigem);
    printf("Vertice\t\tDistancia\tCaminho minimo\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d\t\t", i);

        if (vertices[i].distancia == -1) {
            printf("INFINITO\t");
        } else {
            printf("%d\t\t", vertices[i].distancia);
        }

        int verticeAtual = i;
        while (verticeAtual != -1) {
            printf("%d ", verticeAtual);
            verticeAtual = vertices[verticeAtual].pai;
        }
        printf("\n");
    }

    // Libera��o de mem�ria
    for (int i = 0; i < numVertices; i++) {
        free(grafo[i]);
    }
    free(grafo);
    free(vertices);
    free(visitados);
}



