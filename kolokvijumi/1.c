#include <stdio.h>
#include <limits.h>
#include <math.h>

/*Korisnik učitava ceo broj N i matricu celih pozitivnih brojeva dimenzije N x N. Napraviti funkciju
koja od unete matrice pravi novu matricu čiji se elementi formiraju na slededi način. Svaki element u
novoj matrici jednak je absolutnoj vrednosti razlike minimalnog elementa iz susednih kolona i
maksimalnog elementa iz susednih vrsta. Pretpostaviti da je maksimalna dimenzija matrice 100 x 100.
Primer:
Uneti dimenzije matice: 3
Uneti elemente matrice:
1 2 3
4 5 6
7 8 9
Izlaz :
4 5 4
7 8 7
4 5 4 */

#define SIZE 50

int isSafe(int j, int n)
{
    if (j >= 0 && j < n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int min(int mat[SIZE][SIZE], int j, int n)
{

    int min = INT_MAX;

    if (isSafe(j - 1, n))
    {
        for (int i = 0; i < n; i++)
        {
            if (mat[i][j - 1] < min)
            {
                min = mat[i][j - 1];
            }
        }
    }
    if (isSafe(j + 1, n))
    {
        for (int i = 0; i < n; i++)
        {
            if (mat[i][j + 1] < min)
            {
                min = mat[i][j + 1];
            }
        }
    }

    return min;
}

int max(int mat[SIZE][SIZE], int i, int n)
{

    int max = INT_MIN;

    if (isSafe(i - 1, n))
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i - 1][j] > max)
            {
                max = mat[i - 1][j];
            }
        }
    }
    if (isSafe(i + 1, n))
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i + 1][j] > max)
            {
                max = mat[i + 1][j];
            }
        }
    }

    return max;
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

    int nova[SIZE][SIZE];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            nova[i][j] = abs(min(mat, j, n) - max(mat, i, n));
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%2d", nova[i][j]);
        }
        printf("\n");
    }

    return 0;
}