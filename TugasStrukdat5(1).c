#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct LinkedList
{
    struct Node *head;
    struct Node *tail;
};

void initialize(struct LinkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
}

void addData(struct LinkedList *list, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    printf("Data %d telah ditambahkan ke linked list.\n", data);
}

void display(struct LinkedList *list)
{
    if (list->head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }

    struct Node *current = list->head;

    printf("Isi linked list: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void deleteData(struct LinkedList *list, int data)
{
    if (list->head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }

    struct Node *current = list->head;
    struct Node *prev = NULL;

    while (current != NULL)
    {
        if (current->data == data)
        {
            if (prev == NULL)
            {
                list->head = current->next;
                free(current);
            }
            else
            {
                prev->next = current->next;
                if (current == list->tail)
                {
                    list->tail = prev;
                }
                free(current);
            }

            printf("Data %d telah dihapus dari linked list.\n", data);
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Data %d tidak ditemukan dalam linked list.\n", data);
}

void searchData(struct LinkedList *list, int data)
{
    if (list->head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }

    struct Node *current = list->head;
    int position = 1;
    int found = 0;

    while (current != NULL)
    {
        if (current->data == data)
        {
            printf("Data %d ditemukan pada posisi %d dalam linked list.\n", data, position);
            found = 1;
        }
        current = current->next;
        position++;
    }

    if (!found)
    {
        printf("Data %d tidak ditemukan dalam linked list.\n", data);
    }
}

void addAfter(struct LinkedList *list, int afterData, int newData)
{
    if (list->head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }

    struct Node *current = list->head;

    while (current != NULL)
    {
        if (current->data == afterData)
        {
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = newData;
            newNode->next = current->next;
            current->next = newNode;

            if (current == list->tail)
            {
                list->tail = newNode;
            }

            printf("Data %d telah ditambahkan setelah data %d dalam linked list.\n", newData, afterData);
            return;
        }

        current = current->next;
    }

    printf("Data %d tidak ditemukan dalam linked list.\n", afterData);
}

void addBefore(struct LinkedList *list, int beforeData, int newData)
{
    if (list->head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }

    struct Node *current = list->head;
    struct Node *prev = NULL;

    while (current != NULL)
    {
        if (current->data == beforeData)
        {
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = newData;

            if (prev == NULL)
            {
                newNode->next = current;
                list->head = newNode;
            }
            else
            {
                newNode->next = current;
                prev->next = newNode;
            }

            printf("Data %d telah ditambahkan sebelum data %d dalam linked list.\n", newData, beforeData);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Data %d tidak ditemukan dalam linked list.\n", beforeData);
}

int main()
{
    struct LinkedList list;
    initialize(&list);

    int choice, data, afterData, beforeData;

    while (1)
    {
        printf("\nMenu Linked List\n");
        printf("1. Tambah Data\n");
        printf("2. Tampilkan Data\n");
        printf("3. Hapus Data\n");
        printf("4. Cari Data\n");
        printf("5. Tambahkan Node Setelah Data\n");
        printf("6. Tambahkan Node Sebelum Data\n");
        printf("7. Keluar\n");
        printf("Pilih tindakan (1-7): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Masukkan data yang akan ditambahkan: ");
            scanf("%d", &data);
            addData(&list, data);
            break;
        case 2:
            display(&list);
            break;
        case 3:
            printf("Masukkan data yang akan dihapus: ");
            scanf("%d", &data);
            deleteData(&list, data);
            break;
        case 4:
            printf("Masukkan data yang akan dicari: ");
            scanf("%d", &data);
            searchData(&list, data);
            break;
        case 5:
            printf("Masukkan data setelahnya: ");
            scanf("%d", &afterData);
            printf("Masukkan data yang akan ditambahkan: ");
            scanf("%d", &data);
            addAfter(&list, afterData, data);
            break;
        case 6:
            printf("Masukkan data sebelumnya: ");
            scanf("%d", &beforeData);
            printf("Masukkan data yang akan ditambahkan: ");
            scanf("%d", &data);
            addBefore(&list, beforeData, data);
            break;
        case 7:
            exit(0);
        default:
            printf("Pilihan tidak valid. Coba lagi.\n");
        }
    }
    return 0;
}
