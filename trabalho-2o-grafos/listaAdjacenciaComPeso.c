#include <stdio.h>
#include <stdlib.h>

void listaAdjacenciaComPeso(FILE *arquivo)
{
    system("cls");

    // Defini��o da estrutura de n�
    typedef struct No
    {
        int vertice;
        float peso;
        struct No* proximo;
    } No;

    // Fun��o para criar um novo n�
    No* criarNo(int v, float p)
    {
        No* novoNo = (No*)malloc(sizeof(No));
        novoNo->vertice = v;
        novoNo->peso = p;
        novoNo->proximo = NULL;
        return novoNo;
    }

    // Fun��o para adicionar uma aresta ao grafo
    void adicionarAresta(No* adj[], int origem, int destino, float peso)
    {
        // Adicionando a aresta da origem para o destino
        No* novoNo = criarNo(destino, peso);
        novoNo->proximo = adj[origem];
        adj[origem] = novoNo;

        // Adicionando a aresta do destino para a origem (grafo n�o direcionado)
        novoNo = criarNo(origem, peso);
        novoNo->proximo = adj[destino];
        adj[destino] = novoNo;
    }

    // Fun��o para imprimir a lista de adjac�ncia ordenada
    void imprimirLista(No* adj[], int vertices)
    {

        int i;
        printf("Lista de Adjacencia com peso:\n\n");
        for (i = 1; i <= vertices; i++) {

            printf("%d: -> ", i);

            No* temp = adj[i];

            // Imprime os v�rtices e seus pesos
            while (temp)
            {
                if(temp->proximo==NULL)
                {
                    printf("%d(%.1f)", temp->vertice, temp->peso);
                    temp = temp->proximo;
                }
                else
                {
                    printf("%d(%.1f) -> ", temp->vertice, temp->peso);
                    temp = temp->proximo;
                }

            }

            printf("\n");
        }
    }

    // Leitura do n�mero de v�rtices do arquivo
    int vertices;
    fscanf(arquivo, "%d", &vertices);

    int c, cont = 0, aux = 0;

    // Contagem do n�mero de valores por linha para determinar se o arquivo cont�m peso nas arestas ou n�o
    while ((c = fgetc(arquivo)) != EOF)
    {
        if (c == '\n')
        {
            aux = cont;
            cont = 0;
        }
        if (c != ' ' && c != '\n')
        {
            cont++;
        }
    }

    //Volta para o inicio do arquivo
    fseek(arquivo, 0, SEEK_SET);

    //Pula a primeira linha(N�mero de v�rtices)
    char buffer[100];
    fgets(buffer, sizeof(buffer), arquivo);

    if (aux == 2)
    {
        system("cls");
        printf("\nVoce esta tentando representar uma lista de adjacencia sem peso no modo de representacao de lista adjacencia com peso!\n");
        printf("Reinicie o programa e escolha o modo de representacao de lista de adjacencia sem peso!\n\n");
        system("pause");
        system("cls");
        exit(1);
    }
    else
    {
        // Grafo com peso nas arestas
        No* adj[vertices + 1];

        for (int i = 1; i <= vertices; i++)
            adj[i] = NULL;

        int origem, destino;
        float peso;
        while (fscanf(arquivo, "%d %d %f", &origem, &destino, &peso) != EOF)
        {
            adicionarAresta(adj, origem, destino, peso);
        }

        fclose(arquivo);

        imprimirLista(adj, vertices);
    }
}
