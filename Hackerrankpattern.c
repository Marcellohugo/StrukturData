#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int size = 2 * n - 1;
    int pattern[size][size];

    int i, j, min;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            min = i < j ? i : j;
            min = min < size - i ? min : size - i - 1;
            min = min < size - j - 1 ? min : size - j - 1;

            pattern[i][j] = n - min;
        }
    }

    // Print the pattern
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", pattern[i][j]);
        }
        printf("\n");
    }

    return 0;
}
