#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void add(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    head->data++;
}

void removeElement(int data)
{
    if (head == NULL)
    {
        printf("Linked list kosong\n");
        return;
    }

    struct Node *current = head;
    struct Node *prev = NULL;

    while (current != NULL && current->data != data)
    {
        prev = current;
        current = current->next;
    }

    if (current != NULL)
    {
        head->data--;

        if (prev != NULL)
        {
            prev->next = current->next;
            if (current->next != NULL)
            {
                current->next->prev = prev;
            }
        }
        else
        {
            head = current->next;
            if (current->next != NULL)
            {
                current->next->prev = NULL;
            }
        }

        free(current);
        printf("Element %d dihapus\n", data);
    }
    else
    {
        printf("Element %d tidak ditemukan\n", data);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("Linked list kosong\n");
        return;
    }

    struct Node *current = head->next;
    printf("Jumlah elements: %d\n", head->data);
    printf("Elements: ");

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void editElement(int data, int newData)
{
    if (head == NULL)
    {
        printf("Linked list kosong\n");
        return;
    }

    struct Node *current = head->next;

    while (current != NULL && current->data != data)
    {
        current = current->next;
    }

    if (current != NULL)
    {
        current->data = newData;
        printf("Element %d diubah menjadi %d\n", data, newData);
    }
    else
    {
        printf("Element %d tidak ditemukan\n", data);
    }
}

void displayReverse()
{
    if (head == NULL)
    {
        printf("Linked list kosong\n");
        return;
    }

    struct Node *current = head->next;

    while (current->next != NULL)
    {
        current = current->next;
    }

    printf("Elements terbalik: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

int main()
{
    int choice, data, newData;

    while (1)
    {
        printf("\n1. Tambah element\n");
        printf("2. Hapus element\n");
        printf("3. Tampilkan elements\n");
        printf("4. Edit element\n");
        printf("5. Tampilkan elements terbalik\n");
        printf("6. Keluar\n");
        printf("Masukan pilihan anda: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Masukan element untuk ditambah: ");
            scanf("%d", &data);
            add(data);
            break;
        case 2:
            printf("Masukan element untuk dihapus: ");
            scanf("%d", &data);
            removeElement(data);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Masukan element untuk diedit: ");
            scanf("%d", &data);
            printf("Masukan element baru: ");
            scanf("%d", &newData);
            editElement(data, newData);
            break;
        case 5:
            displayReverse();
            break;
        case 6:
            exit(0);
        default:
            printf("Pilihan tidak tersedia\n");
        }
    }

    return 0;
}