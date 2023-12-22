/*
Napisati program koja učitava kvadratnu matricu brojeva od 0 do 9 i posmatra
redom elemente po kolonama matrice u vidu “zmije”, prvo se posmatra prva kolona od
gore na dole, zatim druga od dole na gore, treća opet od gore na dole, itd. Program
treba da izbroji i ispiše koliki je najduži uzastopni broj pojavljivanja istog broja u
opisanom redosledu posmatranja elemenata matrice. Ispisati broj ponavljanja.
Primer matrice:
3 2 1 6
1 6 9 8
5 3 6 1
2 2 1 1
elemente posmatramo u sledećem redosledu: 3 1 5 2 3 6 2 4 1 9 6 1 1 1 8 6
Ispis: broj ponavljanja:3
*/

#define SIZE 50

#include <stdio.h>

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

    int prosli = 0;
    int broj_ponavljanja = 1;

    int max_broj_ponavljanja = 0;

    printf("elemente posmatramo u sledecem redosledu: ");

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if ((j % 2) == 0)
            {
                printf("%d ", mat[i][j]);

                if (mat[i][j] == prosli)
                {
                    broj_ponavljanja++;
                    if (broj_ponavljanja >= max_broj_ponavljanja)
                    {
                        max_broj_ponavljanja = broj_ponavljanja;
                    }
                    /// printf("Prosli= %d, broj ponavljanja = %d, maks = %d\n", prosli, broj_ponavljanja, max_broj_ponavljanja);
                }
                else
                {
                    prosli = mat[i][j];
                    broj_ponavljanja = 1;
                    if (broj_ponavljanja >= max_broj_ponavljanja)
                    {
                        max_broj_ponavljanja = broj_ponavljanja;
                    }
                    /// printf("Prosli= %d, broj ponavljanja = %d, maks =%d\n", prosli, broj_ponavljanja, max_broj_ponavljanja);
                }
            }
            else
            {
                printf("%d ", mat[n - i - 1][j]);

                if (mat[n - i - 1][j] == prosli)
                {
                    broj_ponavljanja++;
                    if (broj_ponavljanja >= max_broj_ponavljanja)
                    {
                        max_broj_ponavljanja = broj_ponavljanja;
                    }
                    /// printf("Prosli= %d, broj ponavljanja = %d , maks = %d\n", prosli, broj_ponavljanja, max_broj_ponavljanja);
                }
                else
                {
                    prosli = mat[n - i - 1][j];
                    broj_ponavljanja = 1;
                    if (broj_ponavljanja >= max_broj_ponavljanja)
                    {
                        max_broj_ponavljanja = broj_ponavljanja;
                    }
                    /// printf("Prosli= %d, broj ponavljanja = %d, maks = %d\n", prosli, broj_ponavljanja, max_broj_ponavljanja);
                }
            }
        }
    }

    printf("\n");

    printf("broj ponavljanja: %d", max_broj_ponavljanja);

    return 0;
}