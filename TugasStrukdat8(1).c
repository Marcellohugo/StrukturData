#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void addAtBeginning(int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;

    if (head == NULL)
    {
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }

    printf("Data %d ditambahkan di awal linked list.\n", newData);
}

void addAtEnd(int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;

    if (head == NULL)
    {
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;
        tail = newNode;
    }

    printf("Data %d ditambahkan di akhir linked list.\n", newData);
}

void displayForward()
{
    if (head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }

    struct Node *current = head;
    printf("Data dalam linked list (dari head ke tail): ");
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

void displayBackward()
{
    if (head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }

    struct Node *current = tail;
    printf("Data dalam linked list (dari tail ke head): ");
    do
    {
        printf("%d ", current->data);
        current = current->prev;
    } while (current != tail);
    printf("\n");
}

int searchData(int key)
{
    if (head == NULL)
    {
        return 0;
    }

    struct Node *current = head;
    do
    {
        if (current->data == key)
        {
            return 1;
        }
        current = current->next;
    } while (current != head);

    return 0;
}

int searchDataCircular(int key)
{
    if (head == NULL)
    {
        return 0;
    }

    struct Node *forward = head;
    struct Node *backward = tail;
    do
    {
        if (forward->data == key || backward->data == key)
        {
            return 1;
        }
        forward = forward->next;
        backward = backward->prev;
    } while (forward != head && backward != tail);

    return 0;
}

void deleteNode(int key)
{
    if (head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }

    struct Node *current = head;
    struct Node *prevNode = NULL;

    while (current->data != key)
    {
        if (current->next == head)
        {
            printf("Data %d tidak ditemukan dalam linked list.\n", key);
            return;
        }

        prevNode = current;
        current = current->next;
    }

    if (current == head && current->next == head)
    {
        head = NULL;
        tail = NULL;
        free(current);
        printf("Data %d dihapus dari linked list.\n", key);
        return;
    }

    if (current == head)
    {
        prevNode = tail;
        tail->next = head->next;
        head = head->next;
        head->prev = tail;
    }
    else if (current == tail)
    {
        prevNode->next = head;
        tail = prevNode;
        head->prev = tail;
    }
    else
    {
        prevNode->next = current->next;
        current->next->prev = prevNode;
    }

    free(current);
    printf("Data %d dihapus dari linked list.\n", key);
}

void deleteAll()
{
    if (head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }

    struct Node *current = head;
    struct Node *nextNode = NULL;

    do
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != head);

    head = NULL;
    tail = NULL;
    printf("Semua data dihapus dari linked list.\n");
}

int main()
{
    int choice, data, key;

    do
    {
        printf("1. Tambah Data di Awal\n");
        printf("2. Tambah Data di Akhir\n");
        printf("3. Tampilkan Data (dari head ke tail)\n");
        printf("4. Tampilkan Data (dari tail ke head)\n");
        printf("5. Cari Data (dari head ke tail)\n");
        printf("6. Cari Data (dari head ke tail dan tail ke head)\n");
        printf("7. Hapus Data\n");
        printf("8. Hapus Semua Data\n");
        printf("9. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Masukkan data: ");
            scanf("%d", &data);
            addAtBeginning(data);
            break;
        case 2:
            printf("Masukkan data: ");
            scanf("%d", &data);
            addAtEnd(data);
            break;
        case 3:
            displayForward();
            break;
        case 4:
            displayBackward();
            break;
        case 5:
            printf("Masukkan data yang ingin dicari: ");
            scanf("%d", &key);
            if (searchData(key))
            {
                printf("Data %d ditemukan dalam linked list (dari head ke tail).\n", key);
            }
            else
            {
                printf("Data %d tidak ditemukan dalam linked list (dari head ke tail).\n", key);
            }
            break;
        case 6:
            printf("Masukkan data yang ingin dicari: ");
            scanf("%d", &key);
            if (searchDataCircular(key))
            {
                printf("Data %d ditemukan dalam linked list (dari head ke tail dan tail ke head).\n", key);
            }
            else
            {
                printf("Data %d tidak ditemukan dalam linked list (dari head ke tail dan tail ke head).\n", key);
            }
            break;
        case 7:
            printf("Masukkan data yang ingin dihapus: ");
            scanf("%d", &key);
            deleteNode(key);
            break;
        case 8:
            deleteAll();
            break;
        case 9:
            printf("Terima kasih!\n");
            break;
        default:
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }

        printf("\n");
    } while (choice != 9);

    return 0;
}
