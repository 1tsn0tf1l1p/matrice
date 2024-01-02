/*
Napisati program koji u datoj pravougaonoj matrici pronalazi sve zamišljene
jednakokrake pravougaone trouglove sa pravim uglom dole levo kao na slici (polovina
kvadratne matrice ispod glavne dijagonale uključujući i dijagonalu) koje čine elementi
takvi da je barem polovina elemenata parno. Ispisati indekse vrste i kolone temena
pravog ugla i dužinu kateta za sve pronađene trouglove.
Primer:
1 3 1 4 3 1
2 1 3 4 9 7
1 4 7 1 2 1
2 7 7 1 1 1
2 3 4 5 1 2

Ispis:
(4,0) - 2
(4,0) - 3
(4,0) - 4
(3,0) - 3
(1,3) - 2

*/

#define SIZE 50

#include <stdio.h>

void podtrougao(int mat[SIZE][SIZE], int n, int m)
{

    for (int x = 2; x <= n; x++)
    {
        for (int y = 2; y <= m; y++)
        {
            if (x == y)
            {
                for (int i = 0; i < n - x + 1; i++)
                {
                    for (int j = 0; j < m - y + 1; j++)
                    {
                        int broj_el = (x * y) / 2;
                        int brojac = 0;

                        for (int p = 0; p < i + x; p++)
                        {
                            for (int q = 0; q < j + y; q++)
                            {
                                if (p >= q)
                                {
                                    if (mat[p][q] % 2 == 0)
                                    {
                                        brojac++;
                                    }
                                }
                            }
                        }

                        if (brojac >= broj_el)
                        {
                            printf("(%d, %d) - %d\n", i + x, j, x);
                        }
                    }
                }
            }
        }
    }
}

int main()
{

    int n;
    int m;
    scanf("%d %d", &n, &m);

    int mat[SIZE][SIZE];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    podtrougao(mat, n, m);

    return 0;
}