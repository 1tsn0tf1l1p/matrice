/*
Za zadatu matricu velicine n*n i vrednost k, obrnuti svaki prsten matrice u
smeru kazaljke na satu za k puta.
Ulaz:                                    Ulaz:
6 8 Izlaz:                            4 2 Izlaz:

3 2 6 4 5 8    4 2 3 4 9 0    8 1 7 5   7 8 8 1
7 4 3 2 7 1    3 2 9 4 9 0    8 7 4 6   0 4 4 7
0 5 6 9 2 3    2 7 6 9 2 7    7 4 4 9   1 4 7 5
0 7 9 4 9 4    9 2 9 4 2 3    0 1 3 7   3 7 9 6
9 2 2 9 4 9    4 3 4 5 7 2
4 3 2 4 3 2    3 1 8 5 4 6

3 2 6 4 5 8
7 4 3 2 7 1
0 5 6 9 2 3
0 7 9 4 9 4
9 2 2 9 4 9
4 3 2 4 3 2

*/

#define SIZE 666

#include <stdio.h>

void prsten(int mat[SIZE][SIZE], int n, int k)
{

    int dubina = 0;
}

int main()
{

    int n, k;
    scanf("%d %d", &n, &k);

    int mat[SIZE][SIZE];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    prsten(mat, n, k);

    return 0;
}