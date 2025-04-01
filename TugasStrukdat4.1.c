#include <stdio.h>
#include <stdlib.h>

unsigned long long faktorial(unsigned int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * faktorial(n - 1);
    }
}

int main()
{
    unsigned int angka;
    scanf("%u", &angka);

    unsigned long long hasil = faktorial(angka);
    printf("%llu", hasil);

    return 0;
}
