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

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initLinkedList(struct LinkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
}

void addData(struct LinkedList *list, int data)
{
    struct Node *newNode = createNode(data);

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

    printf("Data berhasil ditambahkan.\n");
}

void displayData(struct LinkedList *list)
{
    if (list->head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }

    struct Node *current = list->head;
    printf("Linked List: ");
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
    struct Node *previous = NULL;
    int found = 0;

    while (current != NULL)
    {
        if (current->data == data)
        {
            if (previous == NULL)
            {
                list->head = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            if (current == list->tail)
            {
                list->tail = previous;
            }

            free(current);
            found = 1;
            break;
        }

        previous = current;
        current = current->next;
    }

    if (found)
    {
        printf("Data berhasil dihapus.\n");
    }
    else
    {
        printf("Data tidak ditemukan dalam linked list.\n");
    }
}

void searchByHead(struct LinkedList *list, int data)
{
    if (list->head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }

    struct Node *current = list->head;
    int found = 0;

    while (current != NULL)
    {
        if (current->data == data)
        {
            printf("Data %d ditemukan dalam linked list.\n", data);
            found = 1;
            break;
        }
        current = current->next;
    }

    if (!found)
    {
        printf("Data %d tidak ditemukan dalam linked list.\n", data);
    }
}

void searchByHeadAndTail(struct LinkedList *list, int data)
{
    if (list->head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }

    struct Node *currentHead = list->head;
    struct Node *currentTail = list->tail;
    int found = 0;

    while (currentHead != NULL && currentTail != NULL)
    {
        if (currentHead->data == data || currentTail->data == data)
        {
            printf("Data %d ditemukan dalam linked list.\n", data);
            found = 1;
            break;
        }

        if (currentHead == currentTail)
        {
            break;
        }

        currentHead = currentHead->next;
        currentTail = currentTail->next;
    }

    if (!found)
    {
        printf("Data %d tidak ditemukan dalam linked list.\n", data);
    }
}

void insertAfter(struct LinkedList *list, int data, int newData)
{
    if (list->head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }

    struct Node *current = list->head;
    int found = 0;

    while (current != NULL)
    {
        if (current->data == data)
        {
            struct Node *newNode = createNode(newData);
            newNode->next = current->next;
            current->next = newNode;
            if (current == list->tail)
            {
                list->tail = newNode;
            }
            found = 1;
            printf("Data berhasil dimasukan.\n");
            break;
        }
        current = current->next;
    }

    if (!found)
    {
        printf("Data %d tidak ditemukan dalam linked list.\n", data);
    }
}

void insertBefore(struct LinkedList *list, int data, int newData)
{
    if (list->head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }

    struct Node *current = list->head;
    struct Node *previous = NULL;
    int found = 0;

    while (current != NULL)
    {
        if (current->data == data)
        {
            struct Node *newNode = createNode(newData);
            newNode->next = current;
            if (previous == NULL)
            {
                list->head = newNode;
            }
            else
            {
                previous->next = newNode;
            }
            found = 1;
            printf("Data berhasil dimasukan.\n");
            break;
        }
        previous = current;
        current = current->next;
    }

    if (!found)
    {
        printf("Data %d tidak ditemukan dalam linked list.\n", data);
    }
}

int main()
{
    struct LinkedList list;
    initLinkedList(&list);

    int choice;
    int data;
    int newData;

    while (1)
    {
        printf("1. Masukan data\n");
        printf("2. Tampilkan Data\n");
        printf("3. Hapus Data\n");
        printf("4. Cari dari Head\n");
        printf("5. Cari dari Head and Tail\n");
        printf("6. Masukan setelah\n");
        printf("7. Masukan sebelum\n");
        printf("8. Keluar\n");
        printf("Masukan pilihan anda: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Masukan data untuk ditambah: ");
            scanf("%d", &data);
            addData(&list, data);
            break;
        case 2:
            displayData(&list);
            break;
        case 3:
            printf("Masukan data untuk dihapus: ");
            scanf("%d", &data);
            deleteData(&list, data);
            break;
        case 4:
            printf("Masukan data untuk dicari: ");
            scanf("%d", &data);
            searchByHead(&list, data);
            break;
        case 5:
            printf("Masukan data untuk dicari: ");
            scanf("%d", &data);
            searchByHeadAndTail(&list, data);
            break;
        case 6:
            printf("Masukan data untuk dimasukan setelah: ");
            scanf("%d", &data);
            printf("Masukan data untuk ditambah: ");
            scanf("%d", &newData);
            insertAfter(&list, data, newData);
            break;
        case 7:
            printf("Masukan data untuk dimasukan sebelum: ");
            scanf("%d", &data);
            printf("Masukan data untuk ditambah: ");
            scanf("%d", &newData);
            insertBefore(&list, data, newData);
            break;
        case 8:
            exit(0);
        default:
            printf("Pilihan tidak tersedia, pilihlah option yang tersedia.\n");
        }
    }

    return 0;
}
