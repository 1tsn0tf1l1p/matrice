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

void trougao(int mat[SIZE][SIZE], int n, int m)
{

    for (int x = 2; x <= n; x++)
    {
        for (int y = 2; y <= m; y++)
        {
            /// printf("Uso pre if");
            if (x != y)
            {
                continue;
            }

            /// printf("Uso posle ifa");

            for (int i = 0; i <= n - x; i++)
            {
                for (int j = 0; j <= m - y; j++)
                {
                    int limiter = 1;

                    int brojac_parnih = 0;
                    int broj_elemenata_trougla = 0;

                    for (int p = i; p < i + x; p++)
                    {
                        int brojac = 0;

                        for (int q = j; q < j + y; q++)
                        {
                            if (brojac < limiter)
                            {
                                brojac++;
                                broj_elemenata_trougla++;

                                if (mat[p][q] % 2 == 0)
                                {
                                    brojac_parnih++;
                                }
                            }
                        }
                        limiter++;
                    }

                    if (brojac_parnih > broj_elemenata_trougla / 2)
                    {
                        printf("(%d, %d) - %d (brojac parnih = %d, brojac el tr = %d\n", i + x - 1, j, x, brojac_parnih, broj_elemenata_trougla);
                    }
                }
            }
        }
    }
}

int main()
{

    int n, m;
    scanf("%d %d", &n, &m);

    int mat[SIZE][SIZE];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    trougao(mat, n, m);

    return 0;
}