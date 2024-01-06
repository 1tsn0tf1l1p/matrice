/*
Napisati program koji ucitava matricu dimenzija NxN, sortira joj elemente po kolonama u neopadajucem poretku, a zatim
sortira cele kolone tako da elementi u poslednjem redu matrice budu u nerastucem poretku.
n = 5
3 6 7 5 3
5 6 2 9 1
2 7 0 9 3
6 0 6 2 6
1 8 7 9 2

2 0 0 1 1
5 6 2 2 2
9 6 6 3 3
9 7 7 5 3
9 8 7 6 6
*/

#define SIZE 50

#include <stdio.h>

void swapelements(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_column_elements(int mat[SIZE][SIZE], int n, int j)
{
    for (int q = 0; q < n - 1; q++)
    {
        for (int p = 0; p < n - q - 1; p++)
        {
            if (mat[p][j] > mat[p + 1][j])
            {
                swapelements(&mat[p][j], &mat[p + 1][j]);
            }
        }
    }
}

void sort_matrix(int mat[SIZE][SIZE], int n)
{

    int i = n - 1;

    for (int z = 0; z < n; z++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (mat[i][j] < mat[i][j + 1])
            {
                for (int f = 0; f < n; f++)
                {
                    swapelements(&mat[f][j], &mat[f][j + 1]);
                }
            }
        }
    }
}

int main()
{

    int n;
    scanf("%d", &n);

    int mat[SIZE][SIZE];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int j = 0; j < n; j++)
    {
        sort_column_elements(mat, n, j);
    }

    sort_matrix(mat, n);

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}