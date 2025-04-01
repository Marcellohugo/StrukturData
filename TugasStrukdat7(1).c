#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct LinkedList
{
    int count;
    struct Node *head;
    struct Node *tail;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void initLinkedList(struct LinkedList *list)
{
    list->count = 0;
    list->head = NULL;
    list->tail = NULL;
}

void addNode(struct LinkedList *list, int data)
{
    struct Node *newNode = createNode(data);
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
    list->count++;
}

void deleteNode(struct LinkedList *list, int data)
{
    struct Node *currentNode = list->head;
    while (currentNode != NULL)
    {
        if (currentNode->data == data)
        {
            if (currentNode == list->head)
            {
                list->head = currentNode->next;
                if (list->head != NULL)
                {
                    list->head->prev = NULL;
                }
            }
            else if (currentNode == list->tail)
            {
                list->tail = currentNode->prev;
                list->tail->next = NULL;
            }
            else
            {
                currentNode->prev->next = currentNode->next;
                currentNode->next->prev = currentNode->prev;
            }
            free(currentNode);
            list->count--;
            return;
        }
        currentNode = currentNode->next;
    }
}

void displayList(struct LinkedList *list)
{
    struct Node *currentNode = list->head;
    printf("List: ");
    while (currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void displayListReverse(struct LinkedList *list)
{
    struct Node *currentNode = list->tail;
    printf("Reversed List: ");
    while (currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->prev;
    }
    printf("\n");
}

void editNode(struct LinkedList *list, int oldData, int newData)
{
    struct Node *currentNode = list->head;
    while (currentNode != NULL)
    {
        if (currentNode->data == oldData)
        {
            currentNode->data = newData;
            return;
        }
        currentNode = currentNode->next;
    }
}

int main()
{
    struct LinkedList list;
    initLinkedList(&list);

    int choice, data, oldData, newData;

    while (1)
    {
        printf("1. Tambah Node\n");
        printf("2. Hapus Node\n");
        printf("3. Lihat List\n");
        printf("4. Lihat List Terbalik\n");
        printf("5. Edit Node\n");
        printf("6. Keluar\n");
        printf("Pilih operasi: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Masukkan data yang ingin ditambahkan: ");
            scanf("%d", &data);
            addNode(&list, data);
            break;
        case 2:
            printf("Masukkan data yang ingin dihapus: ");
            scanf("%d", &data);
            deleteNode(&list, data);
            break;
        case 3:
            displayList(&list);
            break;
        case 4:
            displayListReverse(&list);
            break;
        case 5:
            printf("Masukkan data yang ingin diubah: ");
            scanf("%d", &oldData);
            printf("Masukkan data baru: ");
            scanf("%d", &newData);
            editNode(&list, oldData, newData);
            break;
        case 6:
            exit(0);
        default:
            printf("Pilihan tidak valid!\n");
        }
        printf("\n");
    }

    return 0;
}
