#include <stdio.h>
#include <stdlib.h>

// Struktur Node BST
struct Node {
    long long int data;
    struct Node* left;
    struct Node* right;
};

// Fungsi untuk membuat node baru
struct Node* createNode(long long int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi untuk menyisipkan elemen ke dalam BST
struct Node* insert(struct Node* root, long long int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data > root->data) {
        root->left = insert(root->left, data);
    } else if (data < root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Fungsi untuk mencari indeks dari suatu elemen dalam BST
int findIndex(struct Node* root, long long int data, int index) {
    if (root == NULL) {
        return -1;  // Data tidak ada
    }

    if (data == root->data) {
        return index + 1;  // 1-based indexing
    }

    if (data > root->data) {
        return findIndex(root->left, data, index + 1);
    } else {
        return findIndex(root->right, data, index + 1);
    }
}

// Fungsi untuk membebaskan memori dari BST
void freeBST(struct Node* root) {
    if (root == NULL) {
        return;
    }

    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

int main() {
    int Q;
    scanf("%d", &Q);

    struct Node* root = NULL;

    for (int i = 0; i < Q; i++) {
        int queryType;
        long long int x;
        scanf("%d %lld", &queryType, &x);

        if (queryType == 1) {
            root = insert(root, x);
        } else if (queryType == 2) {
            int index = findIndex(root, x, 0);
            if (index == -1) {
                printf("Data tidak ada\n");
            } else {
                printf("%d\n", index);
            }
        }
    }

    freeBST(root);

    return 0;
}