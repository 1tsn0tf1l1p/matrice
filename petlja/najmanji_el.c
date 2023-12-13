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

    int najmanji_element = INT_MAX;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (mat[i][j] < najmanji_element)
            {
                najmanji_element = mat[i][j];
            }
        }
    }

    printf("%d", najmanji_element);

    return 0;
}