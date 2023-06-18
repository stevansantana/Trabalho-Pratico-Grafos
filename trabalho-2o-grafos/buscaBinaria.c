#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int A[], int x, int inicio, int fim)
{
    if (inicio >= fim)
    {
        return -1; // Condição de parada quando o intervalo se torna inválido
    }

    int meio = (inicio+fim)/2;

    if(x==A[meio])
    {
       return 0;
    }
    else
    {
        if(x<A[meio])
        {
           return buscaBinaria(A, x, inicio, meio);
        }
        else
        {
            if(x>A[meio])
            {
                return buscaBinaria(A, x, meio+1, fim);
            }
            else
            {
                return 1;
            }
        }
    }
}
