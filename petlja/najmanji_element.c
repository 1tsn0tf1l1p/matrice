#include <stdio.h>
#include <limits.h>

int main()
{

    int n, m;
    scanf("%d %d", &n, &m);

    int mat[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    int najmanji = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] < najmanji)
            {
                najmanji = mat[i][j];
            }
        }
    }

    printf("%d", najmanji);

    return 0;
}