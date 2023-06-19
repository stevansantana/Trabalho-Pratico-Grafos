#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int A[], int x, int inicio, int fim);
void buscaEmLargura(FILE *arquivo);
void buscaEmProfundidade(FILE *arquivo);
void escolherGrafoBusca();
void escolherModoBusca(FILE *Arquivo);
void escolherComSemPeso(FILE *arquivo);
void escolherGrafoRepresentacao();
void escolherModoRepresentacao(FILE *arquivo);
void lerGrafo();
void lerGrafoComPeso(FILE *arquivo);
void lerGrafoSemPeso(FILE *arquivo);
void listaAjacenciaComPeso(FILE *arquivo);
void listaAdjacenciaSemPeso(FILE *arquivo);
void matrizAdjancenciaComPeso(FILE *arquivo);
void matrizAdjancenciaSemPeso(FILE *arquivo);
void menu();
void saida(int numVertices, int numArestas, int menorGrau, int maiorGrau, double grauMedio, double listaDistribuicaoEmpirica[]);

#endif // LIBRARY_H_INCLUDED
