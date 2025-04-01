#include <stdio.h>
#include <stdlib.h>

// Struktur Node untuk Linked List
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Struktur Linked List
typedef struct List
{
    Node *head;
} List;

// Inisialisasi Linked List
void list_init(List *list)
{
    list->head = NULL;
}

// Menambahkan elemen baru ke Linked List
void list_add(List *list, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL)
    {
        list->head = new_node;
    }
    else
    {
        Node *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Fungsi forEachElement untuk Linked List
void forEachElement(List *list, void (*operation)(int *))
{
    Node *current = list->head;
    while (current != NULL)
    {
        operation(&(current->data));
        current = current->next;
    }
}

// Fungsi cetak elemen
void printElement(int *elem)
{
    printf("%d ", *elem);
}

// Fungsi mengalikan dengan 2
void multiply2(int *elem)
{
    *elem *= 2;
}

// Fungsi membalikkan setiap bilangan
void reverseEach(int *elem)
{
    int reversed = 0;
    int num = *elem;
    while (num != 0)
    {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    *elem = reversed;
}

// Fungsi mengganti elemen dengan penjumlahan digit
void sumDigit(int *elem)
{
    int num = *elem;
    int sum = 0;
    while (num != 0)
    {
        sum += num % 10;
        num /= 10;
    }
    *elem = sum;
}

int main()
{
    List myList;
    list_init(&myList);

    int choice;
    int element;

    printf("Enter elements of the Linked List (Enter -1 to stop):\n");
    while (1)
    {
        scanf("%d", &element);
        if (element == -1)
        {
            break;
        }
        list_add(&myList, element);
    }

    printf("\n");

    while (1)
    {
        printf("1. Print elements of the Linked List\n");
        printf("2. Multiply each element by 2\n");
        printf("3. Reverse each element\n");
        printf("4. Replace each element with the sum of its digits\n");
        printf("Enter your choice (-1 to exit): ");
        scanf("%d", &choice);

        if (choice == -1)
        {
            break;
        }

        printf("\n");

        // Memilih operasi berdasarkan pilihan pengguna
        switch (choice)
        {
        case 1:
            printf("Elements of the list: ");
            forEachElement(&myList, printElement);
            printf("\n");
            break;
        case 2:
            forEachElement(&myList, multiply2);
            printf("Modified elements of the list (multiplied by 2): ");
            forEachElement(&myList, printElement);
            printf("\n");
            break;
        case 3:
            forEachElement(&myList, reverseEach);
            printf("Modified elements of the list (reversed): ");
            forEachElement(&myList, printElement);
            printf("\n");
            break;
        case 4:
            forEachElement(&myList, sumDigit);
            printf("Modified elements of the list (sum of digits): ");
            forEachElement(&myList, printElement);
            printf("\n");
            break;
        default:
            printf("Invalid choice\n");
        }

        printf("\n");
    }

    return 0;
}
