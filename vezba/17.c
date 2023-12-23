/*
Napisati program koji za unetu kvadratnu matricu veličine n generiše drugu
matricu po sledećem principu: Glavna dijagonala prve matrice treba da postane
sporedna dijagonala nove matrice. Isto važi i za sporednu dijagonalu (glavna i
sporedna dijagonala menjaju mesta). Obratite pažnju da obe dijagonale
posmatramo s leva na desno. Polja koja se ne nalaze na dijagonalama treba da
dobiju vrednost maksimalnog parnog suseda polja na istoj poziciji prve matrice
(susedi su elementi koji se nalaze ispod, iznad, levo i desno u odnosu na
posmatrani element). Ako neko polje nema parne susede, upisuje se 0. Na kraju
ispisati novu matricu.
Ulaz: Izlaz:

4
2 6 1 4    9 2 6 7
3 5 6 8    4 1 8 6
4 1 8 0    0 5 6 8
9 6 3 7    2 0 8 4

2 6 1 4
3 5 6 8
4 1 8 0
9 6 3 7
*/

#define SIZE 50

#include <stdio.h>

int isSafe(int i, int j, int n)
{
    if (i >= 0 && i < n && j < n && j >= 0)
    {
        return 1;
    }
    else
    {
        return 0;
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

    int max_paran_sused = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j == n - 1)
            {
                nova[n - i - 1][i] = mat[i][i];
            }
            else if (i == j)
            {
                nova[i][i] = mat[n - i - 1][i];
            }
            else if ((i + j != n - 1) || (i != j))
            {
                if (isSafe(i - 1, j, n) && (mat[i - 1][j] % 2 == 0))
                {
                    if (mat[i - 1][j] > max_paran_sused)
                    {
                        max_paran_sused = mat[i - 1][j];
                        nova[i][j] = max_paran_sused;
                    }
                }
                if (isSafe(i + 1, j, n) && (mat[i + 1][j] % 2 == 0))
                {
                    if (mat[i + 1][j] > max_paran_sused)
                    {
                        max_paran_sused = mat[i + 1][j];
                        nova[i][j] = max_paran_sused;
                    }
                }
                if (isSafe(i, j + 1, n) && (mat[i][j + 1] % 2 == 0))
                {
                    if (mat[i][j + 1] > max_paran_sused)
                    {
                        max_paran_sused = mat[i][j + 1];
                        nova[i][j] = max_paran_sused;
                    }
                }
                if (isSafe(i, j - 1, n) && (mat[i][j - 1] % 2 == 0))
                {
                    if (mat[i][j - 1] > max_paran_sused)
                    {
                        max_paran_sused = mat[i][j - 1];
                        nova[i][j] = max_paran_sused;
                    }
                }
            }
            max_paran_sused = 0;
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