/*
Napisati program koja za unete brojeve n i m formira matricu kao u primeru. Matrica
treba da bude dimenzija m x m, popunjava se spiralno, sa početkom u gornjem desnom
uglu. Prva vrednost koja se upisuje u matricu je broj n. Kada se dođe do ivice matrice,
prelazi se na broj koji je za 2 veći. Posle 9 se prelazi na 1. 0 ≤ n ≤ 9, 1 ≤ m ≤ 9.
n=3 m=5
5 3 3 3 3
5 3 1 1 1
5 3 1 9 9
5 5 5 7 9
7 7 7 7 9
*/

#define SIZE 50

#include <stdio.h>

int isSafe(int i, int j, int m)
{
    if (i >= 0 && i < m && j >= 0 && j < m)
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

    int n, m;
    scanf("%d %d", &n, &m);

    int mat[SIZE][SIZE];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mat[i][j] = -1;
        }
    }

    int smer = 0;
    int brojac = 0;

    int x[4] = {0, 1, 0, -1};
    int y[4] = {-1, 0, 1, 0};

    int trenutnoI = 0;
    int trenutnoJ = m - 1;

    while (brojac < m * m)
    {

        int sledeceI = trenutnoI + x[smer];
        int sledeceJ = trenutnoJ + y[smer];

        if (isSafe(sledeceI, sledeceJ, m) == 1 && mat[trenutnoI][trenutnoJ] == -1 && mat[sledeceI][sledeceJ] == -1)
        {
            mat[trenutnoI][trenutnoJ] = n;
            trenutnoI = trenutnoI + x[smer];
            trenutnoJ = trenutnoJ + y[smer];
        }
        else
        {
            n = (n + 2) % 10;
            mat[trenutnoI][trenutnoJ] = n;
            smer = (smer + 1) % 4;
            trenutnoI = trenutnoI + x[smer];
            trenutnoJ = trenutnoJ + y[smer];
        }
        brojac++;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}