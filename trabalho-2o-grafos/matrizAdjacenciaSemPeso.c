#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matrizAdjancenciaSemPeso(FILE *arquivo)
{
    system("cls");

    //Pegar o numero de v�rtice do arquivo
    int numVertice=0;
    fscanf(arquivo, "%d", &numVertice);

   // Aloca mem�ria para a matriz
    int **matriz = (int **)malloc(numVertice * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro na aloca��o de mem�ria.");
        return;
    }

    for (int i = 0; i < numVertice; i++) {
        matriz[i] = (int *)malloc(numVertice * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro na aloca��o de mem�ria.");
            return;
        }
    }

    // Inicializa os elementos da matriz com 0
    for (int i = 0; i < numVertice; i++) {
        for (int j = 0; j < numVertice; j++) {
            matriz[i][j] = 0;
        }
    }

    //Percorre o arquivo e conta o n�mero de arestas e o n�mero de colunas
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

    //Pula a primeira linha(N�mero de v�rtices)
    int auxNumVertice=0;
    fscanf(arquivo, "%d", &auxNumVertice);

    if(aux==2)
    {
        for(int i=0; i<numVertice; i++)
        {
            int origem, destino;
            for(int j=0; j<numVertice; j++)
            {
                fscanf(arquivo, "%d %d", &origem, &destino);
                matriz[origem-1][destino-1] = 1;
                matriz[destino-1][origem-1] = 1;
            }
        }

        printf("Matriz de Adjacencia sem peso:\n\n");

        for(int i=0; i<numVertice; i++)
        {
            for(int j=0; j<numVertice; j++)
            {
                printf("%d\t", matriz[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        for(int i=0; i<numVertice; i++)
        {
            int origem, destino, peso;
            for(int j=0; j<numVertice; j++)
            {
                fscanf(arquivo, "%d %d %d", &origem, &destino, &peso);
                matriz[origem-1][destino-1] = 1;
                matriz[destino-1][origem-1] = 1;
            }
        }
        printf("Matriz de Adjacencia sem peso:\n\n");

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
