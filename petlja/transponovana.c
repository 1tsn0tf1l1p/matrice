#include <stdio.h>

myswap(int *a, int *b)
{
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int transponovana[m][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(&a[i][j], &a[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}