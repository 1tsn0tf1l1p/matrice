/*
Napisati program koja učitava kvadratnu matricu brojeva od 0 do 9 i posmatra redom
elemente po vrstama matrice u vidu “zmije”, prvo se posmatra prva vrstu sa leva na
desno, zatim druga sa desna na levo, treća opet sa leva na desno itd. Program treba da
izbroji i ispiše kolika je najduža sekvenca brojeva koji su poređani redom rastuće u
opisanom redosledu posmatranja elemenata matrice. Ispisati dužinu sekvence.
Primer matrice:
3 4 1 6
2 1 3 1
3 4 5 5
2 3 4 5
elemente posmatramo u sledećem redosledu: 3 4 1 6 1 3 1 2 3 4 5 5 5 4 3 2
Ispis: duzina sekvence: 5
*/

#define SIZE 50

#include <stdio.h>
#include <limits.h>

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

    printf("elemente posmatramo u sledećem redosledu: ");

    int prosli = mat[0][0];
    int brojac = 1;
    int max_brojac = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i % 2 == 0)
            {
                printf("%d ", mat[i][j]);

                if (mat[i][j] == prosli + 1)
                {
                    prosli = mat[i][j];
                    brojac++;
                }
                else
                {
                    prosli = mat[i][j];
                    brojac = 1;
                }
            }
            else
            {
                printf("%d ", mat[i][n - j - 1]);

                if (mat[i][n - j - 1] == prosli + 1)
                {
                    prosli = mat[i][n - j - 1];
                    brojac++;
                }
                else
                {
                    prosli = mat[i][n - j - 1];
                    brojac = 1;
                }
            }

            if (brojac > max_brojac)
            {
                max_brojac = brojac;
            }
        }

        /// printf("brojac = %d, max = %d\n", brojac, max_brojac);
    }

    printf("\nDuzina sekvence: %d\n", max_brojac);

    return 0;
}