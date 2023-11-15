#ifndef MATRIZES_H
#define MATRIZES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{

    int **matrixA;
    int **matrixB;
    int **matrixC;
    int rowsA;
    int colsA;
    int rowsB;
    int colsB;

} Matrizes;

void printMatrix(int rows, int cols, int **matrix);
void entrada(Matrizes *m);
int ehpossivel(int colsA, int rowsB);
int allocABC(Matrizes *m);

#endif // serve para n bugar o cabeçalho

// mais encrementado quando se tem varios .h e eles acabam entrando em 'colapso'