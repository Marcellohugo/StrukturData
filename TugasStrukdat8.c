#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addData(struct Node **head, struct Node **tail, int data)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }

    printf("Data %d berhasil ditambahkan.\n", data);
}

void viewData(struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }

    struct Node *temp = head;
    printf("Data dalam linked list: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void deleteData(struct Node **head, struct Node **tail, int data)
{
    if (*head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (temp != NULL && temp->data == data)
    {
        *head = temp->next;
        free(temp);
        printf("Data %d berhasil dihapus.\n", data);
        return;
    }

    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Data %d tidak ditemukan.\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);

    if (prev->next == NULL)
        *tail = prev;

    printf("Data %d berhasil dihapus.\n", data);
}

void searchData(struct Node *head, int data)
{
    if (head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }

    struct Node *temp = head;
    int position = 0;
    int found = 0;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("Data %d ditemukan pada posisi %d.\n", data, position);
            found = 1;
        }

        temp = temp->next;
        position++;
    }

    if (!found)
        printf("Data %d tidak ditemukan.\n", data);
}

void reverseData(struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }

    if (head->next != NULL)
    {
        reverseData(head->next);
    }

    printf("%d ", head->data);
}

int main()
{
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int choice, data;

    do
    {
        printf("1. Tambah Data\n");
        printf("2. Lihat Data\n");
        printf("3. Hapus Data\n");
        printf("4. Cari Data\n");
        printf("5. Tampilkan Terbalik\n");
        printf("6. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Masukkan data: ");
            scanf("%d", &data);
            addData(&head, &tail, data);
            break;
        case 2:
            viewData(head);
            break;
        case 3:
            printf("Masukkan data yang akan dihapus: ");
            scanf("%d", &data);
            deleteData(&head, &tail, data);
            break;
        case 4:
            printf("Masukkan data yang akan dicari: ");
            scanf("%d", &data);
            searchData(head, data);
            break;
        case 5:
            printf("Data dalam linked list (terbalik): ");
            reverseData(head);
            printf("\n");
            break;
        case 6:
            printf("Terima kasih!\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
        }
    } while (choice != 6);

    return 0;
}
