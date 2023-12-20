/*Napisati funkciju koja za uneti broj n pravi matricu kao u primeru za n=45371.
Poslednja vrsta su cifre broja, a svaka slededa gornja vrsta uvedava broj naizmenično za 2 i 1.
Prilikom sabiranja kada se dođe do 9, krede se opet od 0. Implementirati odgovarajude ispise matrice
radi testiranja.

0 1 9 3 7
9 0 8 2 6
7 8 6 0 4
6 7 5 9 3
4 5 3 7 1*/

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
        mat[velicina_broja - 1][j] = n % 10;
        n /= 10;
    }

    int flag = 2;

    for (int i = velicina_broja - 2; i >= 0; i--)
    {
        for (int j = 0; j < velicina_broja; j++)
        {
            mat[i][j] = mat[i + 1][j] + flag;
            if (mat[i][j] > 9)
            {
                mat[i][j] -= 10;
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