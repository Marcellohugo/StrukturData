#include <stdio.h>
#include <stdbool.h>

// Fungsi untuk mencetak array
void cetak(int max, int x[])
{
    int d;
    for (d = 0; d < max; d++)
        printf("%2d ", x[d]);
    printf("\n");
}

// Fungsi untuk menukar dua elemen dalam array
void swap(int x, int y, int datanya[])
{
    int tmp;
    tmp = datanya[x];
    datanya[x] = datanya[y];
    datanya[y] = tmp;
}

// Fungsi untuk melakukan bubble sort pada array
void bubbleSort(int max, int a[])
{
    int i, j, count = 1;
    bool swapped;
    for (i = 0; i < max - 1; i++)
    {
        swapped = false;
        for (j = 0; j < max - i - 1; j++)
        {
            // Jika elemen saat ini lebih besar dari elemen berikutnya,
            // lakukan pertukaran menggunakan fungsi swap
            if (a[j] > a[j + 1])
            {
                swap(j, j + 1, a);
                printf("swap ke %2d \t", count++);
                cetak(max, a);
                swapped = true;
            }
        }
        // Jika tidak ada pertukaran yang dilakukan pada iterasi ini,
        // berarti array sudah terurut, sehingga keluar dari loop
        if (!swapped)
            break;
    }
}

int main()
{
    int data[] = {77, 33, 44, 11, 88, 22, 66, 55};
    int max = 8;
    printf("Data awal:\t");
    cetak(max, data);
    bubbleSort(max, data);
    printf("Data terurut:\t");
    cetak(max, data);
    return 0;
}
