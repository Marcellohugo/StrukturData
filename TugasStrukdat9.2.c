#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int searchNode(Node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->data == data)
    {
        return 1;
    }
    else if (data <= root->data)
    {
        return searchNode(root->left, data);
    }
    else
    {
        return searchNode(root->right, data);
    }
}

int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
}

int height(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

int main()
{
    Node *root = NULL;
    int choice, data;
    int exitProgram = 0;

    do
    {
        printf("Menu:\n");
        printf("1. Tambahkan node\n");
        printf("2. Cari node\n");
        printf("3. Jumlah node dalam pohon\n");
        printf("4. Tinggi pohon\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Masukkan data node: ");
            scanf("%d", &data);
            root = insertNode(root, data);
            break;
        case 2:
            printf("Masukkan data yang ingin dicari: ");
            scanf("%d", &data);
            if (searchNode(root, data))
            {
                printf("%d ditemukan dalam pohon.\n", data);
            }
            else
            {
                printf("%d tidak ditemukan dalam pohon.\n", data);
            }
            break;
        case 3:
            printf("Jumlah node dalam pohon: %d\n", countNodes(root));
            break;
        case 4:
            printf("Tinggi pohon: %d\n", height(root));
            break;
        case 5:
            exitProgram = 1;
            break;
        default:
            printf("Pilihan tidak valid.\n");
            break;
        }

        printf("\n");

        if (exitProgram)
        {
            break;
        }
    } while (1);

    return 0;
}
