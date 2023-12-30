/*
Za zadatu matricu velicine m x n izdvojiti sve kvadratne podmatrice (3 x 3 ili vece) ciji se ugaoni elementi ne
pojavljuju u ostatku te podmatrice. Za svaku podmatricu ispisati koordinate njenog gornjeg levog ugla i velicinu.
4 6
1 2 3 4 1 3
3 1 4 1 5 9
2 4 1 7 6 8
5 5 3 1 9 2

(0, 3) dimenzija 3 x 3
(1, 2) dimenzija 3 x 3
(0, 2) dimenzija 4 x 4
*/

#define SIZE 50

#include <stdio.h>

void podmatrice(int mat[SIZE][SIZE], int m, int n)
{

    for (int x = 3; x <= m; x++)
    {
        for (int y = 3; y <= n; y++)
        {
            if (x != y)
            {
                continue;
            }
            for (int i = 0; i < m - x + 1; i++)
            {
                for (int j = 0; j < n - y + 1; j++)
                {
                    int brojac = 0;

                    int top_left = mat[i][j];
                    int top_right = mat[i][j + x - 1];
                    int bottom_left = mat[i + x - 1][j];
                    int bottom_right = mat[i + x - 1][j + x - 1];

                    for (int p = i; p < i + x; p++)
                    {
                        for (int q = j; q < j + x; q++)
                        {

                            if (mat[p][q] == top_left || mat[p][q] == top_right || mat[p][q] == bottom_left || mat[p][q] == bottom_right)
                            {
                                brojac++;
                            }
                        }
                    }

                    if (brojac == 4)
                    {
                        printf("(%d, %d) dimenzija %d x %d\n", i, j, x, x);
                    }
                }
            }
        }
    }
}

int main()
{

    int m, n;
    scanf("%d %d", &m, &n);

    int mat[SIZE][SIZE];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    podmatrice(mat, m, n);

    return 0;
}