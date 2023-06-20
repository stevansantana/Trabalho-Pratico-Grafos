#include <stdio.h>
#include <stdlib.h>

void lerGrafoComPeso(FILE *arquivo)
{
    system("cls");

    //Fun��o para comparar v�rtices e graus
    int compare(const void* a, const void* b) {
        return (*(int*)a - *(int*)b);
    }

    //Estrutura que representa uma Aresta sem peso
    typedef struct
    {
        int origem;
        int destino;

    }Aresta;

    int numVertice, numArestas = 0, c, cont=0, aux=0;
    fscanf(arquivo, "%d", &numVertice);

    //Percorre o arquivo e conta o n�mero de arestas e o n�mero de colunas
    while ((c = fgetc(arquivo)) != EOF)
    {
        if (c == '\n')
        {
            numArestas++;
            aux = cont;
            cont=0;
        }
        if(c != ' ' && c != '\n')
        {
            cont++;
        }
    }
    numArestas = numArestas - 1;

    //Volta para o inicio do arquivo
    fseek(arquivo, 0, SEEK_SET);

    //Pula a primeira linha(N�mero de v�rtices)
    char buffer[100];
    fgets(buffer, sizeof(buffer), arquivo);

    //Aloca mem�ria para um vetor de arestas
    Aresta *arestas = (Aresta*) malloc(numArestas * sizeof(Aresta));
    if (arestas == NULL) {
        printf("Erro ao alocar mem�ria para a leitura do grafo sem peso.\n");
        fclose(arquivo);
        exit(1);
    }

    //Se colunas = 2 l� grafo sem peso
    if(aux == 2)
    {
        system("cls");
        printf("\nVoce esta tentando representar uma matriz de adjacencia sem peso no modo de representacao de matriz adjacencia com peso!\n");
        printf("Reinicie o programa e escolha o modo de representacao de matriz de adjacencia sem peso!\n\n");
        system("pause");
        system("cls");
        exit(1);
    }
    //Se colunas != 2 l� grafo com peso ignorando os pesos no momento da impress�o
    else
    {
        for(int i=0; i<numArestas; i++)
        {
            int x, y;
            double z;
            fscanf(arquivo, "%d %d %f", &x, &y, &z);

            arestas[i].origem = x;
            arestas[i].destino = y;
        }
    }

    //Lista de v�rtices
    int *listaVertices = (int*)malloc((numArestas*2)*sizeof(int));

    if(listaVertices==NULL)
    {
        printf("Erro ao alocar memoria para o array listaVertices");
        system("pause");
        exit(1);
    }

    //Coloca todos os v�rtices num array
    int j=0;
    for(int i=0; i<numArestas; i++)
    {
        listaVertices[j++] = arestas[i].origem;
        listaVertices[j++] = arestas[i].destino;
    }

    // Ordena o array de v�rtices
    qsort(listaVertices, numArestas*2, sizeof(int), compare);

    // array de graus dos v�rtices
    int *grauVertice = (int*)malloc(numVertice*sizeof(int));
    if(grauVertice==NULL)
    {
        printf("Erro ao alocar memoria para o array grauVertice");
        system("pause");
        exit(1);
    }

    //Coloca os graus dos v�rtices com repeti��o
    int cont2=0;
    for(int i=0; i<numArestas*2; i++)
    {
        int elemento = listaVertices[i], qtdElemento=0;

        while(elemento == listaVertices[i])
        {
            qtdElemento++;
            i++;
        }
        grauVertice[cont2] = qtdElemento;
        cont2++;
        i--;
    }
    qsort(grauVertice, numVertice, sizeof(int), compare);

    int maiorGrau = grauVertice[numVertice-1];
    int menorGrau = grauVertice[0];

    // Soma os graus dos v�rtices e divide pelo n�mero de v�rtices para o grau m�dio
    double somaGraus=0, qtdMedia=0;
    for(int i=0; i<numVertice; i++)
    {
        somaGraus+=grauVertice[i];
        qtdMedia++;
    }
    double grauMedio = somaGraus/qtdMedia;

    double *listaDistruibuicaoEmpirica = (double*)malloc(maiorGrau*sizeof(double));

    int k=0, variavelExistente=0, posicaoListaEmpirica=0;
    for(int i=menorGrau; i<=maiorGrau; i++)
    {
        double distribuicaoEmpirica=0;

        variavelExistente = i;
        int verificaExistencia = buscaBinaria(grauVertice, variavelExistente, 0, numVertice);

        if(variavelExistente == -1)
        {
            printf("Intervalo invalido!");
        }
        if(verificaExistencia==1)
        {
            int elemento = grauVertice[k], qtdElemento=0;
            while(elemento == grauVertice[k])
            {
                qtdElemento++;
                k++;
            }
            distribuicaoEmpirica = (double)qtdElemento/numVertice;
        }
        else
        {
            distribuicaoEmpirica = 0;
        }
        listaDistruibuicaoEmpirica[posicaoListaEmpirica] = distribuicaoEmpirica;
        posicaoListaEmpirica++;
    }

    saida(numVertice, numArestas, menorGrau, maiorGrau, grauMedio, listaDistruibuicaoEmpirica);
    printf("Arquivo de saida gerado!\n");

    free(listaVertices);
    free(grauVertice);
    free(arestas);

    free(listaDistruibuicaoEmpirica);
    fclose(arquivo);

    system("pause");
    system("cls");
    printf("Programa finalizado!\n");
    system("pause");
    system("cls");
    exit(0);

}
