/*Napisati funkciju koja za uneti broj n pravi matricu kao u primeru za n=45371. Prva
vrsta matrice su cifre broja, svaka sledeća donja vrsta umanjuje broj iz gornje vrste naizmenično za 1
i 2. Prilikom oduzimanja kada se dođe do 0, kreće se opet od 9. Implementirati odgovarajuće ispise
matrice radi testiranja.

4 5 3 7 1
3 4 2 6 0
1 2 0 4 8
0 1 9 3 7
8 9 7 1 6*/

#define SIZE 50

#include <stdio.h>

int broj_cifara(int n)
{

    int brojac = 0;

    while (n)
    {
        brojac++;
        n /= 10;
    }

    /// printf("%d", brojac);

    return brojac;
}

int main()
{

    int n;
    scanf("%d", &n);

    int mat[SIZE][SIZE];

    int velicina_broja = broj_cifara(n);

    for (int j = velicina_broja - 1; j >= 0; j--)
    {
        mat[0][j] = n % 10;
        n /= 10;
    }

    int flag = 1;

    for (int i = 1; i < velicina_broja; i++)
    {

        for (int j = 0; j < velicina_broja; j++)
        {
            mat[i][j] = mat[i - 1][j] - flag;
            if (mat[i][j] < 0)
            {
                mat[i][j] += 10;
            }
        }
        flag = (flag + 2) % 2 + 1;
    }

    for (int i = 0; i < velicina_broja; i++)
    {
        for (int j = 0; j < velicina_broja; j++)
        {
            printf("%2d", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}