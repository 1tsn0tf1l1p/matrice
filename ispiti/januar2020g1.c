/*Napisati program koji učitava kvadratnu matricu sastavljenu od nula i jedinica.
Program treba da u unetoj matrici pronađe najveću kvadratnu podmatricu koji se sastoji
samo od nula ili samo od jedinica. Ispisati dimenziju podmatrice i indekse vrste i kolone
gornjeg levog ugla (ako ima više rešenja dovoljno je ispisati samo jedno).
Primer:

1 1 1 0 1 0
1 0 0 0 1 1
1 1 1 1 0 1
0 1 1 1 0 1
1 1 1 1 0 1
1 1 1 0 0 1
ispis: dimenzija:3X3, gornji levi ugao: 2,1
*/

#define SIZE 50

#include <stdio.h>

void podmatrice(int mat[SIZE][SIZE], int n)
{

    int gornji_levi_ugao_i;
    int gornji_levi_ugao_j;

    int dimenzija;

    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            if (x != y)
            {
                continue;
            }
            for (int i = 0; i < n - x + 1; i++)
            {
                for (int j = 0; j < n - y + 1; j++)
                {
                    int prethodni = mat[i][j];
                    int trenutni;
                    int flag = 1;
                    for (int p = i; p < i + x; p++)
                    {
                        for (int q = j; q < j + y; q++)
                        {
                            trenutni = mat[p][q];
                            if (trenutni != prethodni)
                            {
                                flag = 0;
                                break;
                            }
                            /// printf("%d", mat[p][q]);
                        }
                        if (!flag)
                        {
                            break;
                        }
                        /// printf("\n");
                    }
                    if (flag)
                    {
                        gornji_levi_ugao_i = i;
                        gornji_levi_ugao_j = j;
                        dimenzija = x;
                    }
                    /// printf("\n\n");
                }
            }
        }
    }

    printf("dimenzija:%dX%d, gornji levi ugao: %d,%d\n", dimenzija, dimenzija, gornji_levi_ugao_i, gornji_levi_ugao_j);
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

    podmatrice(mat, n);

    return 0;
}