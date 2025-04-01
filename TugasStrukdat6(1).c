#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    printf("Data berhasil ditambahkan di awal linked list.\n");
}

void insertAtEnd(int data)
{
    if (head == NULL)
    {
        insertAtBeginning(data);
        return;
    }
    struct Node *newNode = createNode(data);
    tail->next = newNode;
    tail = newNode;
    tail->next = head;
    printf("Data berhasil ditambahkan di akhir linked list.\n");
}

void display()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }
    printf("Data dalam linked list: ");
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
    printf("\n");
}

int searchByHead(int data)
{
    struct Node *temp = head;
    int pos = 0;
    while (temp->next != head)
    {
        if (temp->data == data)
        {
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    if (temp->data == data)
    {
        return pos;
    }
    return -1;
}

int searchByHeadAndTail(int data)
{
    struct Node *temp = head;
    int pos = 0;
    while (temp->next != head)
    {
        if (temp->data == data)
        {
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    if (temp->data == data)
    {
        return pos;
    }
    pos = 0;
    temp = tail;
    while (temp->next != head)
    {
        if (temp->data == data)
        {
            return -pos - 1;
        }
        temp = temp->next;
        pos++;
    }
    if (temp->data == data)
    {
        return -pos - 1;
    }
    return -1;
}

void deleteNode(int data)
{
    if (head == NULL)
    {
        printf("Linked list kosong.\n");
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp->next != head && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp->data != data)
    {
        printf("Data tidak ditemukan dalam linked list.\n");
        return;
    }
    if (temp == head && temp->next == head)
    {
        head = NULL;
        tail = NULL;
        free(temp);
        printf("Data berhasil dihapus dari linked list.\n");
        return;
    }
    if (temp == head)
    {
        head = head->next;
        tail->next = head;
        free(temp);
        printf("Data berhasil dihapus dari linked list.\n");
        return;
    }
    if (temp == tail)
    {
        tail = prev;
        tail->next = head;
        free(temp);
        printf("Data berhasil dihapus dari linked list.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Data berhasil dihapus dari linked list.\n");
}

void insertAfter(int data, int newData)
{
    struct Node *temp = head;
    while (temp->next != head && temp->data != data)
    {
        temp = temp->next;
    }
    if (temp->data != data)
    {
        printf("Data tidak ditemukan dalam linked list.\n");
        return;
    }
    struct Node *newNode = createNode(newData);
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == tail)
    {
        tail = newNode;
    }
    printf("Data berhasil disisipkan setelah data tertentu.\n");
}

void insertBefore(int data, int newData)
{
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp->next != head && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp->data != data)
    {
        printf("Data tidak ditemukan dalam linked list.\n");
        return;
    }
    struct Node *newNode = createNode(newData);
    newNode->next = temp;
    if (prev == NULL)
    {
        head = newNode;
        tail->next = head;
    }
    else
    {
        prev->next = newNode;
    }
    printf("Data berhasil disisipkan sebelum data tertentu.\n");
}

int main()
{
    int choice, data, searchData, deleteData, insertAfterData, insertBeforeData;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Tambah Data di Awal\n");
        printf("2. Tambah Data di Akhir\n");
        printf("3. Tampilkan Data\n");
        printf("4. Cari Data (ber-Head)\n");
        printf("5. Cari Data (ber-Head dan Tail)\n");
        printf("6. Hapus Data\n");
        printf("7. Sisipkan Node Setelah Data\n");
        printf("8. Sisipkan Node Sebelum Data\n");
        printf("9. Keluar\n");
        printf("Pilih operasi: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Masukkan data: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 2:
            printf("Masukkan data: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Masukkan data yang dicari: ");
            scanf("%d", &searchData);
            if (searchByHead(searchData) != -1)
            {
                printf("Data ditemukan di posisi %d (ber-Head).\n", searchByHead(searchData));
            }
            else
            {
                printf("Data tidak ditemukan (ber-Head).\n");
            }
            break;
        case 5:
            printf("Masukkan data yang dicari: ");
            scanf("%d", &searchData);
            if (searchByHeadAndTail(searchData) >= 0)
            {
                printf("Data ditemukan di posisi %d (ber-Head).\n", searchByHeadAndTail(searchData));
            }
            else if (searchByHeadAndTail(searchData) < 0)
            {
                printf("Data ditemukan di posisi %d (ber-Tail).\n", -searchByHeadAndTail(searchData) - 1);
            }
            else
            {
                printf("Data tidak ditemukan.\n");
            }
            break;
        case 6:
            printf("Masukkan data yang akan dihapus: ");
            scanf("%d", &deleteData);
            deleteNode(deleteData);
            break;
        case 7:
            printf("Masukkan data yang akan disisipkan setelah: ");
            scanf("%d", &insertAfterData);
            printf("Masukkan data baru: ");
            scanf("%d", &insertBeforeData);
            insertAfter(insertAfterData, insertBeforeData);
            break;
        case 8:
            printf("Masukkan data yang akan disisipkan sebelum: ");
            scanf("%d", &insertBeforeData);
            printf("Masukkan data baru: ");
            scanf("%d", &insertAfterData);
            insertBefore(insertBeforeData, insertAfterData);
            break;
        case 9:
            printf("Keluar dari program.\n");
            exit(0);
        default:
            printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}
