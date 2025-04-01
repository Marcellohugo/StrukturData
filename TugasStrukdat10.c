#include<stdio.h>

#define size 7

int arr[size];

void init()
{   
    int i;
    for(i = 0; i < size; i++)
        arr[i] = -1;
}

void insert(int value)
{
    int key = value % size;
    if(arr[key] == -1)
    {
        arr[key] = value;
        printf("%d masuk pada arr[%d]\n", value, key);
    }
    else
    {
        printf("Terjadi Collision: arr[%d] element %d sudah ada\n", key, arr[key]);
        printf("Insert dibatalkan %d\n", value);
    }
}

void del(int value)
{
    int key = value % size;
    if(arr[key] == value)
        arr[key] = -1;
    else
        printf("%d tidak ada dalam tabel hash\n", value);
}

void search(int value)
{
    int key = value % size;
    if(arr[key] == value)
        printf("Ditemukan\n");
    else
        printf("Tidak ditemukan\n");
}

void print()
{
    int i;
    for(i = 0; i < size; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
}

int main()
{
    init();
    int choice, value;

    do {
        printf("Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Print\n");
        printf("5. Exit\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Masukkan bilangan yang ingin di-insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Masukkan bilangan yang ingin di-delete: ");
                scanf("%d", &value);
                del(value);
                break;
            case 3:
                printf("Masukkan bilangan yang ingin dicari: ");
                scanf("%d", &value);
                search(value);
                break;
            case 4:
                printf("Tabel hash:\n");
                print();
                printf("\n");
                break;
            case 5:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih menu yang valid.\n");
        }

        printf("\n");
    } while (choice != 5);

    return 0;
}
