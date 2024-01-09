/*
Na osnovu date kvadratne matrice napraviti novu matricu formirajući njene
prstenove na osnovu prstenova polazne matrice. Prsten nove matrice treba da sadrži
najveći element istog prstena originalne matrice.
Primer:
3 4 3 4 7 5
2 4 2 5 5 4
1 3 4 1 6 1
1 2 3 1 5 2
2 3 1 4 5 5
1 4 5 1 2 3
*/

#define SIZE 100

#include <stdio.h>
#include <limits.h>

int retrun_max(int niz[SIZE], int trenutni)
{

    int max = INT_MIN;

    for (int i = 0; i < trenutni; i++)
    {
        if (niz[i] > max)
        {
            max = niz[i];
        }
    }

    return max;
}

void prsten(int mat[SIZE][SIZE], int nova[SIZE][SIZE], int n)
{

    int niz[SIZE];

    int trenutni = 0;
    int offset = 0;

    while (offset <= n / 2)
    {

        for (int j = offset; j < n - offset; j++)
        {
            niz[trenutni++] = mat[offset][j];
        }
        for (int i = offset + 1; i < n - offset; i++)
        {
            niz[trenutni++] = mat[i][n - offset - 1];
        }
        for (int j = n - offset - 2; j >= offset; j--)
        {
            niz[trenutni++] = mat[n - offset - 1][j];
        }
        for (int i = n - offset - 2; i >= offset + 1; i--)
        {
            niz[trenutni++] = mat[i][offset];
        }

        int maximalan_broj = retrun_max(niz, trenutni);

        trenutni = 0;

        for (int j = offset; j < n - offset; j++)
        {
            nova[offset][j] = maximalan_broj;
        }
        for (int i = offset + 1; i < n - offset; i++)
        {
            nova[i][n - offset - 1] = maximalan_broj;
        }
        for (int j = n - offset - 2; j >= offset; j--)
        {
            nova[n - offset - 1][j] = maximalan_broj;
        }
        for (int i = n - offset - 2; i >= offset + 1; i--)
        {
            nova[i][offset] = maximalan_broj;
        }

        trenutni = 0;
        offset++;
    }

    printf("\n\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", nova[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int n;
    scanf("%d", &n);

    int mat[SIZE][SIZE];
    int nova[SIZE][SIZE];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            nova[i][j] = -1;
        }
    }

    prsten(mat, nova, n);

    return 0;
}