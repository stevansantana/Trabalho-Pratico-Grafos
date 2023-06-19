#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matrizAdjancenciaComPeso(FILE *arquivo)
{
    system("cls");

    //Pegar o numero de vértice do arquivo
    int numVertice=0;
    fscanf(arquivo, "%d", &numVertice);

   // Aloca memória para a matriz
    int **matriz = (int **)malloc(numVertice * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro na alocação de memória.");
        return;
    }

    for (int i = 0; i < numVertice; i++) {
        matriz[i] = (int *)malloc(numVertice * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro na alocação de memória.");
            return;
        }
    }

    // Inicializa os elementos da matriz com 0
    for (int i = 0; i < numVertice; i++) {
        for (int j = 0; j < numVertice; j++) {
            matriz[i][j] = 0;
        }
    }

    //Percorre o arquivo e conta o número de arestas e o número de colunas
    int c, aux=0, cont=0;
    while ((c = fgetc(arquivo)) != EOF)
    {
        if (c == '\n')
        {
            aux = cont;
            cont=0;

            if(aux>2)
                break;
        }
        if(c != ' ' && c != '\n')
        {
            cont++;
        }
    }

    //Volta para o inicio do arquivo
    fseek(arquivo, 0, SEEK_SET);

    //Pula a primeira linha(Número de vértices)
    int auxNumVertice=0;
    fscanf(arquivo, "%d", &auxNumVertice);

    if(aux==2)
    {
        system("cls");
        printf("\nVoce esta tentando representar uma matriz de adjacencia sem peso no modo de representacao de matriz adjacencia com peso!\n");
        printf("Reinicie o programa e escolha o modo de representacao de matriz de adjacencia sem peso!\n\n");
        system("pause");
        system("cls");
        exit(1);
    }
    else
    {
        for(int i=0; i<numVertice; i++)
        {
            int origem, destino, peso;
            for(int j=0; j<numVertice; j++)
            {
                fscanf(arquivo, "%d %d %d", &origem, &destino, &peso);
                matriz[origem-1][destino-1] = peso;
                matriz[destino-1][origem-1] = peso;
            }
        }
        printf("Matriz de Adjacencia com peso:\n\n");

        for(int i=0; i<numVertice; i++)
        {
            for(int j=0; j<numVertice; j++)
            {
                printf("%d\t", matriz[i][j]);
            }
            printf("\n");
        }
    }

    free(matriz);
    fclose(arquivo);
}
