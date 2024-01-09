/*
Napisati program koji učitava kvadratnu matricu sastavljenu od brojeva 1 do 9.
Program treba da u unetoj matrici pronađe najveći pravougaonik koji sadrži samo parne
ili samo neparne brojeve. Ispisati dimenziju pravougaonika i indekse vrste i kolone
gornjeg levog ugla pronađenog pravougaonika (ako ima više rešenja dovoljno je ispisati
samo jedno).
Primer:

2 1 3 4 5
6 1 9 3 1
2 1 1 1 1
2 2 2 2 6
3 1 2 4 1
ispis: dimenzija:2X4, gornji levi ugao: 1,1
*/

#define SIZE 50

#include <stdio.h>

int povrsina(int x, int y)
{

    return x * y;
}

void pravougaonik(int mat[SIZE][SIZE], int n)
{
    int gornji_levi_row = 0;
    int gornji_levi_column = 0;
    int dimenzija_x = 0;
    int dimenzija_y = 0;
    int velicina_pravougaonika = 0;

    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            for (int i = 0; i <= n - x; i++)
            {
                for (int j = 0; j <= n - y; j++)
                {
                    int parnost = mat[i][j] % 2;
                    int flag = 0;

                    for (int p = i; p < i + x; p++)
                    {
                        for (int q = j; q < j + y; q++)
                        {
                            if (mat[p][q] % 2 != parnost)
                            {
                                flag = 1;
                                break;
                            }
                        }
                        if (flag)
                            break;
                    }

                    int velp = povrsina(x, y);

                    if (!flag && (velp >= velicina_pravougaonika))
                    {
                        gornji_levi_row = i;
                        gornji_levi_column = j;
                        dimenzija_x = x;
                        dimenzija_y = y;
                        velicina_pravougaonika = velp;
                    }
                }
            }
        }
    }

    printf("dimenzija:%dX%d, gornji levi ugao: %d,%d\n", dimenzija_x, dimenzija_y, gornji_levi_row, gornji_levi_column);
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

    pravougaonik(mat, n);

    /// printf("%d", povrsina(5, 5));

    return 0;
}