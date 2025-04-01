#include <stdio.h>
#include <stdlib.h>

double pangkat(double x, int y)
{
    double hasil = 1;
    int i;

    if (y > 0)
    {
        for (i = 0; i < y; i++)
        {
            hasil *= x;
        }
    }
    else if (y < 0)
    {
        for (i = 0; i < -y; i++)
        {
            hasil /= x;
        }
    }

    return hasil;
}

int main()
{
    double x;
    int y;

    scanf("%lf", &x);
    scanf("%d", &y);

    double hasil = pangkat(x, y);
    printf("%.f", hasil);

    return 0;
}
