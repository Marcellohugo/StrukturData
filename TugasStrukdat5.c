#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
} LinkedList;

void initializeList(LinkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addData(LinkedList *list, int data)
{
    Node *newNode = createNode(data);
    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    printf("Data %d berhasil ditambahkan.\n", data);
}

void viewData(LinkedList *list)
{
    if (list->head == NULL)
    {
        printf("Linked List kosong.\n");
    }
    else
    {
        Node *current = list->head;
        printf("Data dalam Linked List: ");
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void deleteData(LinkedList *list, int data)
{
    if (list->head == NULL)
    {
        printf("Linked List kosong.\n");
        return;
    }
    Node *current = list->head;
    while (current != NULL)
    {
        if (current->data == data)
        {
            if (current == list->head && current == list->tail)
            {
                list->head = NULL;
                list->tail = NULL;
            }
            else if (current == list->head)
            {
                list->head = current->next;
                list->head->prev = NULL;
            }
            else if (current == list->tail)
            {
                list->tail = current->prev;
                list->tail->next = NULL;
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            printf("Data %d berhasil dihapus.\n", data);
            return;
        }
        current = current->next;
    }
    printf("Data %d tidak ditemukan dalam Linked List.\n", data);
}

void searchData(LinkedList *list, int data)
{
    if (list->head == NULL)
    {
        printf("Linked List kosong.\n");
        return;
    }
    Node *current = list->head;
    int found = 0;
    int index = 0;
    while (current != NULL)
    {
        if (current->data == data)
        {
            printf("Data %d ditemukan pada indeks %d.\n", data, index);
            found = 1;
        }
        current = current->next;
        index++;
    }
    if (!found)
    {
        printf("Data %d tidak ditemukan dalam Linked List.\n", data);
    }
}

void addNodeAfter(LinkedList *list, int data, int target)
{
    if (list->head == NULL)
    {
        printf("Linked List kosong.\n");
        return;
    }
    Node *current = list->head;
    while (current != NULL)
    {
        if (current->data == target)
        {
            Node *newNode = createNode(data);
            newNode->prev = current;
            newNode->next = current->next;
            if (current == list->tail)
            {
                list->tail = newNode;
            }
            else
            {
                current->next->prev = newNode;
            }
            current->next = newNode;
            printf("Data %d berhasil ditambahkan setelah data %d.\n", data, target);
            return;
        }
        current = current->next;
    }
    printf("Data %d tidak ditemukan dalam Linked List.\n", target);
}

void addNodeBefore(LinkedList *list, int data, int target)
{
    if (list->head == NULL)
    {
        printf("Linked List kosong.\n");
        return;
    }
    Node *current = list->head;
    while (current != NULL)
    {
        if (current->data == target)
        {
            Node *newNode = createNode(data);
            newNode->prev = current->prev;
            newNode->next = current;
            if (current == list->head)
            {
                list->head = newNode;
            }
            else
            {
                current->prev->next = newNode;
            }
            current->prev = newNode;
            printf("Data %d berhasil ditambahkan sebelum data %d.\n", data, target);
            return;
        }
        current = current->next;
    }
    printf("Data %d tidak ditemukan dalam Linked List.\n", target);
}

int main()
{
    LinkedList list;
    initializeList(&list);

    int choice, data, target;

    do
    {
        printf("\nLinked List Menu:\n");
        printf("1. Tambah Data\n");
        printf("2. Lihat Data\n");
        printf("3. Hapus Data\n");
        printf("4. Cari Data\n");
        printf("5. Tambah Node Setelah Data Tertentu\n");
        printf("6. Tambah Node Sebelum Data Tertentu\n");
        printf("0. Keluar\n");

        printf("Pilih tindakan: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Masukkan data yang ingin ditambahkan: ");
            scanf("%d", &data);
            addData(&list, data);
            break;
        case 2:
            viewData(&list);
            break;
        case 3:
            printf("Masukkan data yang ingin dihapus: ");
            scanf("%d", &data);
            deleteData(&list, data);
            break;
        case 4:
            printf("Masukkan data yang ingin dicari: ");
            scanf("%d", &data);
            searchData(&list, data);
            break;
        case 5:
            printf("Masukkan data yang ingin ditambahkan: ");
            scanf("%d", &data);
            printf("Masukkan data target: ");
            scanf("%d", &target);
            addNodeAfter(&list, data, target);
            break;
        case 6:
            printf("Masukkan data yang ingin ditambahkan: ");
            scanf("%d", &data);
            printf("Masukkan data target: ");
            scanf("%d", &target);
            addNodeBefore(&list, data, target);
            break;
        case 0:
            printf("Program selesai.\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
