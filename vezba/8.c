/*
Korisnik prvo unosi broj N. Zatim unosi matricu N x N . Za svaku vrstu ispisati najvedi neparan broj
u toj vrsti, i koliko se puta on pojavio. Za svaku kolonu ispisati najmanji paran broj u toj koloni, i koliko se
puta on pojavio. Ukoliko se u vrsti ne nalazi ni jedan neparan broj tu vrstu izostaviti u ispisu, takođe ako
se u koloni ne nalazi ni jedan paran tu kolonu izostaviti. Pretpostaviti da je maksimalna dimenzija
matrice 100 x 100.
primer:
4
2 2 13 13
5 1 7  19
0 3 1  3
1 2 3  4
izlaz:

red 1: 13 2
red 2: 19 1
red 3: 3 2
red 4: 3 1
kolona 1: 2 1
kolona 2: 2 2
kolona 4: 4 1
*/

#define SIZE 50

#include <stdio.h>
#include <limits.h>

int max_neparan_vrste(int mat[SIZE][SIZE], int i, int j, int n, int *broj_ponavljanja_neparni)
{

    int max_neparni = INT_MIN;

    for (int k = 0; k < n; k++)
    {
        if (mat[i][j] % 2 != 0)
        {
            if (mat[i][j] > max_neparni)
            {
                max_neparni = mat[i][j];
                *broj_ponavljanja_neparni = 1;
            }
            if (mat[i][j] == max_neparni)
            {
                (*broj_ponavljanja_neparni)++;
            }
        }
        j++;
    }

    return max_neparni;
}

int min_paran_kolone(int mat[SIZE][SIZE], int i, int j, int n, int *broj_ponavljanja_parni)
{

    int min_parni = INT_MAX;

    for (int k = 0; k < n; k++)
    {
        if (mat[i][j] % 2 == 0)
        {
            if (mat[i][j] < min_parni && mat[i][j] > 0)
            {
                min_parni = mat[i][j];
                *broj_ponavljanja_parni = 1;
            }
            if (mat[i][j] == min_parni)
            {
                (*broj_ponavljanja_parni)++;
            }
        }
        i++;
    }

    return min_parni;
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

    for (int i = 0; i < n; i++)
    {
        int broj_ponavljanja_neparni = 0;
        int max_neparni = max_neparan_vrste(mat, i, 0, n, &broj_ponavljanja_neparni);
        if (max_neparni != 0)
        {
            printf("red %d: %d %d\n", i + 1, max_neparni, broj_ponavljanja_neparni - 1);
        }
    }
    for (int j = 0; j < n; j++)
    {
        int broj_ponavljanja_parni = 0;
        int min_parni = min_paran_kolone(mat, 0, j, n, &broj_ponavljanja_parni);
        if (min_parni != INT_MAX)
        {
            printf("kolona %d: %d %d\n", j + 1, min_parni, broj_ponavljanja_parni - 1);
        }
    }

    return 0;
}