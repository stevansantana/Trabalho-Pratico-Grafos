#include <stdio.h>
#include <stdlib.h>

void listaAdjacenciaSemPeso(FILE *arquivo)
{
    system("cls");

    // Defini��o da estrutura de n�
    typedef struct No
    {
        int vertice;
        struct No* proximo;

    }No;

    // Fun��o para criar um novo n�
    No* criarNo(int v)
    {
        No* novoNo = (No*)malloc(sizeof(No));
        novoNo->vertice = v;
        novoNo->proximo = NULL;
        return novoNo;
    }

    // Fun��o para adicionar uma aresta ao grafo
    void adicionarAresta(No* adj[], int origem, int destino)
    {
        // Adicionando a aresta da origem para o destino
        No* novoNo = criarNo(destino);
        novoNo->proximo = adj[origem];
        adj[origem] = novoNo;

        // Adicionando a aresta do destino para a origem (grafo n�o direcionado)
        novoNo = criarNo(origem);
        novoNo->proximo = adj[destino];
        adj[destino] = novoNo;
    }

    // Fun��o para imprimir a lista de adjac�ncia ordenada
    void printGraph(No* adj[], int vertices)
    {
        int i;
        printf("Lista de Adjacencia sem peso:\n\n");
        for (i = 1; i <= vertices; i++) {

            printf("%d: -> ", i);

            No* temp = adj[i];
            int* tempArray = (int*)malloc(vertices * sizeof(int));
            int index = 0;

            // Armazena os valores da lista de adjac�ncia em um array tempor�rio
            while (temp)
            {
                tempArray[index++] = temp->vertice;
                temp = temp->proximo;
            }

            // Ordena��o dos valores em ordem crescente usando o algoritmo de ordena��o Insertion Sort
            for (int j = 1; j < index; j++)
            {
                int chave = tempArray[j];
                int k = j - 1;
                while (k >= 0 && tempArray[k] > chave)
                {
                    tempArray[k + 1] = tempArray[k];
                    k--;
                }
                tempArray[k + 1] = chave;
            }

            // Imprime os valores ordenados
            for (int j = 0; j < index; j++)
            {

                if(j==index-1)
                {
                    printf("%d", tempArray[j]);
                }
                else
                {
                    printf("%d -> ", tempArray[j]);
                }
            }

            free(tempArray);
            printf("\n");
        }
    }

    // Leitura do n�mero de v�rtices do arquivo
    int vertices;
    fscanf(arquivo, "%d", &vertices);

    int c, cont=0, aux=0;

     // Contagem do n�mero de valores por linha para determinar se o arquivo cont�m peso nas arestas ou n�o
    while ((c = fgetc(arquivo)) != EOF)
    {
        if (c == '\n')
        {
            aux = cont;
            cont=0;
        }
        if(c != ' ' && c != '\n')
        {
            cont++;
        }
    }

    //Volta para o inicio do arquivo
    fseek(arquivo, 0, SEEK_SET);

    //Pula a primeira linha(N�mero de v�rtices)
    char buffer[100];
    fgets(buffer, sizeof(buffer), arquivo);

    if(aux==2)
    {
        // Grafo sem peso nas arestas
        No* adj[vertices + 1];

        for (int i = 1; i <= vertices; i++)
            adj[i] = NULL;

        int origem, destino;
        while (fscanf(arquivo, "%d %d", &origem, &destino) != EOF)
        {
            adicionarAresta(adj, origem, destino);
        }

        fclose(arquivo);

        printGraph(adj, vertices);

    }
    else
    {
        // Grafo com peso nas arestas
        No* adj[vertices + 1];

        for (int i = 1; i <= vertices; i++)
            adj[i] = NULL;

        int origem, destino, peso;
        while (fscanf(arquivo, "%d %d %d", &origem, &destino,&peso) != EOF)
        {
            adicionarAresta(adj, origem, destino);
        }

        fclose(arquivo);

        printGraph(adj, vertices);

    }
}
