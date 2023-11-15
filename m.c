#include <stdio.h>
#include <stdlib.h>
#include "m.h"

Matrizes m;

void printMatrix(int rows, int cols, int **matrix)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
}

void entrada(Matrizes *m)
{

    // entrada de dados do ususario

    printf("Entre com as dimensoes da matriz A (linhas colunas): ");
    scanf("%d %d", &m->rowsA, &m->colsA);
    printf("Entre com as dimensoes da matriz B (linhas colunas): ");
    scanf("%d %d", &m->rowsB, &m->colsB);
}

int ehpossivel(int colsA, int rowsB)
{

    // Verificar se a multiplicacao e possivel

    if (colsA != rowsB)
    {
        printf("A multiplicacao nao e possivel!!\n");
        return 0;
    }
    return 1;
}

int allocABC(Matrizes *m)
{

    // alocar dinamicamente as matrizes
    m->matrixA = (int **)malloc(m->rowsA * sizeof(int *));
    m->matrixB = (int **)malloc(m->rowsB * sizeof(int *));
    m->matrixC = (int **)malloc(m->rowsA * sizeof(int *));

    if (!(m->matrixA) || !(m->matrixB) || !(m->matrixC))
    {
        return 0; // Falha na alocação
    }

    for (int i = 0; i < m->rowsA; i++)
    {
        m->matrixA[i] = (int *)malloc(m->colsA * sizeof(int));
        m->matrixC[i] = (int *)malloc(m->colsB * sizeof(int));

        if (!((m->matrixA)[i]) || !((m->matrixC)[i]))
        {
            return 0; // Falha na alocação
        }
    }
    for (int i = 0; i < m->rowsB; i++)
    {
        m->matrixB[i] = (int *)malloc(m->colsB * sizeof(int));

        if (!((m->matrixB)[i]))
        {
            return 0; // Falha na alocação
        }
    }
    return 1; // sucesso
}

void lermatriz(Matrizes *m)
{

    // Leitura dos elementos da matriz A
    printf("Entre com os elementos da matriz A:\n");
    for (int i = 0; i < m->rowsA; i++)
    {
        for (int j = 0; j < m->colsA; j++)
        {
            scanf("%d", &m->matrixA[i][j]);
        }
    }

    // Leitura dos elementos da matriz B

    printf("Entre com os elementros da matriz B:\n");
    for (int i = 0; i < m->rowsB; i++)
    {
        for (int j = 0; j < m->colsB; j++)
        {
            scanf("%d", &m->matrixB[i][j]);
        }
    }
}

int multiplica(Matrizes *m)
{

    // Multiplicação das matrizes

    for (int i = 0; i < m->rowsA; i++)
    {
        for (int j = 0; j < m->colsB; j++)
        {
            m->matrixC[i][j] = 0;
            for (int k = 0; k < m->colsA; k++)
            {
                m->matrixC[i][j] += m->matrixA[i][k] * m->matrixB[k][j];
            }
        }
    }
}

void libera(Matrizes *m)
{

    // Liberação da memória alocada
    for (int i = 0; i < m->rowsA; i++)
    {
        free(m->matrixA[i]);
        free(m->matrixC[i]);
    }
    for (int i = 0; i < m->rowsB; i++)
    {
        free(m->matrixB[i]);
    }
    free(m->matrixA);
    free(m->matrixB);
    free(m->matrixC);
}

int main()
{

    entrada(&m);

    if (!ehpossivel(m.colsA, m.rowsB))
    {
        return 1;
    }

    if (!allocABC(&m))
    {
        printf("Erro na alocação de memoria\n");
        return 1;
    }

    lermatriz(&m);

    multiplica(&m);

    printf("Matriz A:\n");
    printMatrix(m.rowsA, m.colsA, m.matrixA);
    printf("Matriz B:\n");
    printMatrix(m.rowsB, m.colsB, m.matrixB);
    printf("Matriz C (A x B):\n");
    printMatrix(m.rowsA, m.colsB, m.matrixC);

    libera(&m);
}