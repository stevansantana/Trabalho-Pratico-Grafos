#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int distancia;
    int pai;
} Vertice;

void distanciaMSTDijkstra(FILE *arquivo) {
    int numVertices;
    if (fscanf(arquivo, "%d", &numVertices) != 1) {
        printf("Erro ao ler o n�mero de vertices do arquivo.\n");
        return;
    }

    // Alocar matriz de adjac�ncia
    int **grafo = (int **) malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++) {
        grafo[i] = (int *) malloc(numVertices * sizeof(int));
    }

    // Ler grafo do arquivo
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (fscanf(arquivo, "%d", &grafo[i][j]) != 1) {
                printf("Erro ao ler os valores do grafo do arquivo.\n");
                return;
            }
        }
    }

    int verticeOrigem, verticeDestino;
    if (fscanf(arquivo, "%d %d", &verticeOrigem, &verticeDestino) != 2) {
        printf("Erro ao ler os vertices de origem e destino do arquivo.\n");
        return;
    }

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
            if (grafo[verticeAtual][j] != 0 && !visitados[j]) {
                int distancia = vertices[verticeAtual].distancia + grafo[verticeAtual][j];

                if (vertices[j].distancia == -1 || distancia < vertices[j].distancia) {
                    vertices[j].distancia = distancia;
                    vertices[j].pai = verticeAtual;
                }
            }
        }
    }

    // Verifica se foi poss�vel alcan�ar o v�rtice de destino
    if (vertices[verticeDestino].pai != -1) {
        printf("Distancia entre o vertice %d e o vertice %d: %d\n", verticeOrigem, verticeDestino, vertices[verticeDestino].distancia);

        printf("Caminho minimo: ");
        int verticeAtual = verticeDestino;
        while (verticeAtual != -1) {
            printf("%d ", verticeAtual);
            verticeAtual = vertices[verticeAtual].pai;
        }
        printf("\n");
    } else {
        printf("Nao foi possivel alcancar o vertice de destino a partir do vertice de origem.\n");
    }

    // Liberar mem�ria
    for (int i = 0; i < numVertices; i++) {
        free(grafo[i]);
    }
    free(grafo);
    free(vertices);
    free(visitados);
}

