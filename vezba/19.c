/*
Napisati program u kojem korisnik unosi matricu velicine n x m. Za svaku kolonu matrice proveriti da li je palindrom.
Kolona je palindrom ako se brojevi poklapaju kada se cita odozgo na dole i odozdo na gore. Ako kolona nije palindrom,
treba je rotirati k puta, gde je k najveci element te kolone. Na kraju ispisati promenjenu matricu.
4 5
1 2 2 2
6 3 1 1
5 8 1 1
6 3 3 1
7 2 1 2

6 2 1 2
7 3 3 1
1 8 1 1
6 3 2 1
5 2 1 2
*/

#define SIZE 50

#include <stdio.h>

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

    for (int j = 0; j < n; j++)
    {
        int broj = 0;

        for (int i = 0; i < m; i++)
        {
            broj = broj * 10 + mat[i][j];
            printf("Broj je: %d\n", broj);
        }
    }

    return 0;
}