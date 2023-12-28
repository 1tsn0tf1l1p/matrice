/*
Napisati program u kojem korisnik unosi matricu velicine n x m. Za svaku kolonu matrice proveriti da li je palindrom.
Kolona je palindrom ako se brojevi poklapaju kada se cita odozgo na dole i odozdo na gore. Ako kolona nije palindrom,
treba je rotirati k puta, gde je k najveci element te kolone. Na kraju ispisati promenjenu matricu.
5 4
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
#include <limits.h>
#include <math.h>

int reverse(int broj)
{

    int reversed = 0;

    while (broj)
    {
        int digit = broj % 10;
        reversed = reversed * 10 + digit;
        broj /= 10;
    }

    return reversed;
}

int palindrom(int broj)
{
    int reversed = reverse(broj);

    if (broj == reversed)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int najveca_cifra_broja(int broj)
{

    int najveca = INT_MIN;

    while (broj)
    {
        int cifra = broj % 10;
        broj /= 10;

        if (cifra > najveca)
        {
            najveca = cifra;
        }
    }

    return najveca;
}

int velicina_broja(int broj)
{

    int brojac = 0;

    while (broj)
    {
        broj /= 10;
        brojac++;
    }

    return brojac;
}

int rotirati_k_puta(int broj)
{

    int k = najveca_cifra_broja(broj);

    int stepen = velicina_broja(broj);

    for (int i = 0; i < k; i++)
    {
        int cifra = broj % 10;
        broj = cifra * pow(10, 4) + broj / 10;
    }

    return broj;
}

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

    for (int j = 0; j < m; j++)
    {
        int broj = 0;

        for (int i = 0; i < n; i++)
        {
            broj = broj * 10 + mat[i][j];
        }

        if (palindrom(broj))
        {
            continue;
        }
        else
        {
            int obrnuti = reverse(rotirati_k_puta(broj));
            for (int k = 0; k < n; k++)
            {
                int cifra = obrnuti % 10;
                mat[k][j] = cifra;
                obrnuti /= 10;
            }
        }
    }

    printf("\n\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}