#include <stdio.h>

void myswap(int *a, int *b)
{
    int rez = *a;
    *a = *b;
    *b = rez;
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

    for (int col = 0; col < m; col++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0;)
                if (a[i][j] > a[i + 1][j])
                {
                    myswap(&a[i][j], &a[i + 1][j]);
                }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}