#include <stdio.h>

// Fungsi untuk menukar dua elemen
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk mempartisi array dan mengembalikan indeks pivot
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Memilih pivot sebagai elemen terakhir
    int i = (low - 1);     // Indeks dari elemen yang lebih kecil

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]); // Menukar elemen ke-i dengan elemen ke-j jika elemen ke-j lebih kecil dari atau sama dengan pivot
        }
    }
    swap(&arr[i + 1], &arr[high]); // Menukar elemen setelah elemen terakhir yang lebih kecil dengan pivot
    return (i + 1);                // Mengembalikan indeks pivot
}

// Fungsi rekursif untuk mengurutkan array menggunakan Quick Sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // Memanggil fungsi partition untuk membagi array menjadi dua bagian dan mendapatkan indeks pivot
        quickSort(arr, low, pi - 1);        // Mengurutkan bagian array sebelum pivot
        quickSort(arr, pi + 1, high);       // Mengurutkan bagian array setelah pivot
    }
}

// Fungsi untuk mencetak elemen-elemen array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Masukkan jumlah elemen dalam array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Masukkan elemen-elemen array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array sebelum diurutkan: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1); // Memanggil fungsi quickSort untuk mengurutkan array

    printf("Array setelah diurutkan menggunakan Quick Sort: ");
    printArray(arr, n);

    return 0;
}