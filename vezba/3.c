/*
Napisati funkciju koja od date matrice pravi novu matricu tako što svaki element
matrice zamenjuje zbirom njemu susednih elemenata u vrsti, ako element ima samo jedan susedni
element onda je zbir jednak tom elementu. Napraviti testni program koji učitava matricu od
korisnika i ispisuje učitanu matricu i rezultat. Primer:

2 3 5 2 1     3 7 5 6 2
3 5 1 2 1     5 4 7 2 2
1 2 2 5 3     2 3 7 5 5
7 3 2 5 4     3 9 8 6 5
1 3 3 1 5     3 4 4 8 1

2 3 5 2 1
3 5 1 2 1
1 2 2 5 3
7 3 2 5 4
1 3 3 1 5


*/

#define SIZE 50

#include <stdio.h>

int isSafe(int i, int j, int n)
{

    if (i >= 0 && i < n && j >= 0 && j < n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int zbir_susednih(int mat[SIZE][SIZE], int i, int j, int n)
{

    int zbir = 0;
    int levi;
    int desni;

    if (isSafe(i, j - 1, n))
    {
        levi = mat[i][j - 1];
    }
    else
    {
        levi = 0;
    }

    if (isSafe(i, j + 1, n))
    {
        desni = mat[i][j + 1];
    }
    else
    {
        desni = 0;
    }

    zbir = levi + desni;

    return zbir;
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
            nova[i][j] = zbir_susednih(mat, i, j, n);
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