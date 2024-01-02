/*
Napisati program koji učitava kvadratnu matricu sastavljenu od brojeva 1 do 9 i
broj n koji je manji ili jednak dimenziji matrice. Program treba da u unetoj matrici
pronađe koliko ima podmatrica dimenzije nXn koji se sastoje samo od parnih ili samo od
neparnih brojeva. Ispisati broj takvih podmatrica i indekse vrste i kolone gornjeg levog
elementa svih pronađenih podmatrica.
Primer:
n=2
2 1 3 4 5
6 1 9 3 1
2 1 1 1 1
2 2 2 2 6
3 1 2 4 8
ispis: broj podmatrica: 6 (0,1) (1,1) (1,2) (1,3) (3,2) (3,3)
*/

#define SIZE 50

#include <stdio.h>

void podmatrica(int mat[SIZE][SIZE], int n, int dim_mat)
{
    int brojac = 0;

    for (int i = 0; i <= dim_mat - n; i++)
    {
        for (int j = 0; j <= dim_mat - n; j++)
        {
            int parnost = mat[i][j] % 2;
            int flag = 1;
            for (int p = 0; p < i + n; p++)
            {
                for (int q = 0; q < j + n; q++)
                {
                    if (mat[p][q] % 2 != parnost)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (!flag)
                {
                    break;
                }
            }

            if (flag)
            {
                brojac++;
            }
        }
    }

    printf("%d", brojac);
}

int main()
{

    int dim_mat;
    int n;
    scanf("%d %d", &dim_mat, &n);

    int mat[SIZE][SIZE];

    for (int i = 0; i < dim_mat; i++)
    {
        for (int j = 0; j < dim_mat; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    podmatrica(mat, n, dim_mat);

    return 0;
}