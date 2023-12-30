/*
Napisati program koji učitava četvorocifeni ceo broj n i matricu koja
sadrži cifre od 0 do 9. Program treba da proveri i ispiše koliko ima podmatrica
dimenzije 2X2 u unetoj matrici u kojoj se nalaze sve cifre unetog broja redom
čitajući od gore na dole po kolonama. Neke cifre mogu biti zajedničke u
pojavljivanju, kao u primerima.
Primer 1:
n = 3453
3 5 9 1
4 3 5 4
2 4 3 5
7 4 1 6

Ispis:
2
*/

#define SIZE 50

#include <stdio.h>

void podmatrice(int mat[SIZE][SIZE], int row, int column, int n)
{

    int x = 2;

    int glavni_brojac = 0;

    for (int i = 0; i < row - x + 1; i++)
    {
        for (int j = 0; j < column - x + 1; j++)
        {
            int temp = n;
            int brojac = 0;

            for (int q = j; q < j + x; q++)
            {
                for (int p = i; p < i + x; p++)
                {
                    int cifra = temp % 10;
                    /// printf("cifra: %d, ", cifra);
                    temp /= 10;
                    /// printf("temp: %d, ", temp);

                    if (mat[p][q] == cifra)
                    {
                        brojac++;
                    }
                    /// printf("brojac: %d\n", brojac);
                }
            }

            if (brojac == 4)
            {
                glavni_brojac++;
            }
        }
    }

    printf("%d", glavni_brojac);
}

int reverse(int n)
{

    int nb = 0;

    while (n)
    {
        int cifra = n % 10;
        nb = nb * 10 + cifra;
        n /= 10;
    }

    return nb;
}

int main()
{

    int n;
    scanf("%d", &n);

    int row, column;

    scanf("%d %d", &row, &column);

    int mat[SIZE][SIZE];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    int broj = reverse(n);

    podmatrice(mat, row, column, broj);

    return 0;
}