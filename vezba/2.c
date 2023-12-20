/*Napisati funkciju koja od date matrice pravi novu matricu tako što svaki element
matrice zamenjuje minimumom iz kolone i vrste u kojoj se nalazi element. Napraviti testni program
koji učitava matricu od korisnika i ispisuje rezultat. Primer:

2 3 5 7 5     1 2 2 2 2
3 5 9 2 8     1 2 2 2 2
1 8 2 5 6     1 1 1 1 1
7 3 4 5 4     1 3 2 2 3
1 3 9 6 5     1 1 1 1 1

2 3 5 7 5
3 5 9 2 8
1 8 2 5 6
7 3 4 5 4
1 3 9 6 5




*/

#define SIZE 50

#include <stdio.h>
#include <limits.h>

int minimum_vrsta(int mat[SIZE][SIZE], int i, int n)
{
    int najmanji = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        if (mat[i][j] < najmanji)
        {
            najmanji = mat[i][j];
        }
    }

    return najmanji;
}

int minimum_kolona(int mat[SIZE][SIZE], int j, int n)
{
    int najmanji = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][j] < najmanji)
        {
            najmanji = mat[i][j];
        }
    }

    return najmanji;
}

int main()
{

    int n;
    scanf("%d", &n);

    int mat[n][n];
    int nova[n][n];

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
            if (minimum_kolona(&mat, i, n) < minimum_vrsta(&mat, j, n))
            {
                nova[i][j] = minimum_kolona(&mat, i, n);
            }
            else if (minimum_kolona(&mat, i, n) > minimum_vrsta(&mat, j, n))
            {
                nova[i][j] = minimum_vrsta(&mat, j, n);
            }
            else
            {
                nova[i][j] = minimum_kolona(&mat, i, n);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", nova[i][j]);
        }
        printf("\n");
    }

    return 0;
}