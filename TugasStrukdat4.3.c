#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrima(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void tampilkanBilanganPrima(int batasBawah, int batasAtas)
{
    for (int i = batasBawah; i <= batasAtas; i++)
    {
        if (isPrima(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main()
{
    int batasBawah, batasAtas;

    scanf("%d", &batasBawah);
    scanf("%d", &batasAtas);

    tampilkanBilanganPrima(batasBawah, batasAtas);

    return 0;
}
