#include <stdio.h>
#include <stdlib.h>

void grafoComponenteConexo(FILE *arquivo)
{
    system("cls");

    void dfs(int vertice, int n, int visitados[], int adj[][n])
    {
        visitados[vertice] = 1;

        for (int i = 0; i < n; i++)
        {
            if (adj[vertice][i] && !visitados[i])
            {
                dfs(i, n, visitados, adj);
            }
        }
    }

    int n;
    fscanf(arquivo, "%d", &n);

    int adj[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    int u, v;

    while (fscanf(arquivo, "%d %d", &u, &v) != EOF)
    {
        adj[u-1][v-1] = 1;
        adj[v-1][u-1] = 1;
    }

    fclose(arquivo);

    int visitados[n];
    int componentes = 0;
    int tamanhos[n];

    for (int i = 0; i < n; i++)
    {
        visitados[i] = 0;
        tamanhos[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visitados[i])
        {
            dfs(i, n, visitados, adj);
            componentes++;
        }
    }

    printf("Numero de componentes conexos: %d\n", componentes);
    printf("Tamanho de cada componente:\n");

    for (int i = 0; i < n; i++)
    {
        tamanhos[visitados[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (tamanhos[i] > 0)
        {
            printf("Componente %d: %d vertices\n", i, tamanhos[i]);
            printf("Vertices da componente %d: ", i);
            for (int j = 0; j < n; j++)
            {
                if (visitados[j] == i)
                {
                    printf("%d ", j + 1);
                }
            }
            printf("\n");
        }
    }
}
