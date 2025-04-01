#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

// Struktur data untuk simpul AVL
struct AVLNode
{
    int data;
    AVLNode *left, *right;
    int height;
};

// Struktur data untuk AVL Tree
struct AVL
{
private:
    AVLNode *_root; // Pointer ke root node
    unsigned _size; // Jumlah elemen dalam tree

    // Fungsi untuk membuat simpul baru dengan nilai tertentu
    AVLNode *_avl_createNode(int value)
    {
        AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->height = 1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    // Fungsi untuk mencari simpul dengan nilai tertentu dalam AVL Tree
    AVLNode *_search(AVLNode *root, int value)
    {
        while (root != NULL)
        {
            if (value < root->data)
                root = root->left;
            else if (value > root->data)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    // Fungsi untuk mendapatkan tinggi dari suatu simpul
    int _getHeight(AVLNode *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    // Fungsi untuk mencari maksimum dari dua bilangan
    int _max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    // Fungsi untuk melakukan rotasi ke kanan terhadap simpul pivot
    AVLNode *_rightRotate(AVLNode *pivotNode)
    {
        AVLNode *newParent = pivotNode->left;
        pivotNode->left = newParent->right;
        newParent->right = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left),
                                 _getHeight(pivotNode->right)) +
                            1;
        newParent->height = _max(_getHeight(newParent->left),
                                 _getHeight(newParent->right)) +
                            1;

        return newParent;
    }

    // Fungsi untuk melakukan rotasi ke kiri terhadap simpul pivot
    AVLNode *_leftRotate(AVLNode *pivotNode)
    {
        AVLNode *newParent = pivotNode->right;
        pivotNode->right = newParent->left;
        newParent->left = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left),
                                 _getHeight(pivotNode->right)) +
                            1;
        newParent->height = _max(_getHeight(newParent->left),
                                 _getHeight(newParent->right)) +
                            1;

        return newParent;
    }

    // Fungsi untuk menangani kasus rotasi ke kiri
    AVLNode *_leftCaseRotate(AVLNode *node)
    {
        return _rightRotate(node);
    }

    // Fungsi untuk menangani kasus rotasi ke kanan
    AVLNode *_rightCaseRotate(AVLNode *node)
    {
        return _leftRotate(node);
    }

    // Fungsi untuk menangani kasus rotasi kiri-kanan
    AVLNode *_leftRightCaseRotate(AVLNode *node)
    {
        node->left = _leftRotate(node->left);
        return _rightRotate(node);
    }

    // Fungsi untuk menangani kasus rotasi kanan-kiri
    AVLNode *_rightLeftCaseRotate(AVLNode *node)
    {
        node->right = _rightRotate(node->right);
        return _leftRotate(node);
    }

    // Fungsi untuk mendapatkan faktor keseimbangan suatu simpul
    int _getBalanceFactor(AVLNode *node)
    {
        if (node == NULL)
            return 0;
        return _getHeight(node->left) - _getHeight(node->right);
    }

    // Fungsi rekursif untuk memasukkan suatu nilai ke dalam AVL Tree
    AVLNode *_insert_AVL(AVLNode *node, int value)
    {

        if (node == NULL)
            return _avl_createNode(value);
        if (value < node->data)
            node->left = _insert_AVL(node->left, value);
        else if (value > node->data)
            node->right = _insert_AVL(node->right, value);

        node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

        int balanceFactor = _getBalanceFactor(node);

        // Menangani kasus ketidakseimbangan
        if (balanceFactor > 1 && value < node->left->data)
            return _leftCaseRotate(node);
        if (balanceFactor > 1 && value > node->left->data)
            return _leftRightCaseRotate(node);
        if (balanceFactor < -1 && value > node->right->data)
            return _rightCaseRotate(node);
        if (balanceFactor < -1 && value < node->right->data)
            return _rightLeftCaseRotate(node);

        return node;
    }

    // Fungsi untuk mencari simpul dengan nilai minimum pada suatu subtree
    AVLNode *_findMinNode(AVLNode *node)
    {
        AVLNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }

    // Fungsi rekursif untuk menghapus suatu nilai dari AVL Tree
    AVLNode *_remove_AVL(AVLNode *node, int value)
    {
        if (node == NULL)
            return node;
        if (value > node->data)
            node->right = _remove_AVL(node->right, value);
        else if (value < node->data)
            node->left = _remove_AVL(node->left, value);
        else
        {
            AVLNode *temp;
            if ((node->left == NULL) || (node->right == NULL))
            {
                temp = NULL;
                if (node->left == NULL)
                    temp = node->right;
                else if (node->right == NULL)
                    temp = node->left;

                if (temp == NULL)
                {
                    temp = node;
                    node = NULL;
                }
                else
                    *node = *temp;

                free(temp);
            }
            else
            {
                temp = _findMinNode(node->right);
                node->data = temp->data;
                node->right = _remove_AVL(node->right, temp->data);
            }
        }

        if (node == NULL)
            return node;

        node->height = _max(_getHeight(node->left), _getHeight(node->right)) + 1;

        int balanceFactor = _getBalanceFactor(node);

        // Menangani kasus ketidakseimbangan setelah penghapusan
        if (balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
            return _leftCaseRotate(node);
        if (balanceFactor > 1 && _getBalanceFactor(node->left) < 0)
            return _leftRightCaseRotate(node);
        if (balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
            return _rightCaseRotate(node);
        if (balanceFactor < -1 && _getBalanceFactor(node->right) > 0)
            return _rightLeftCaseRotate(node);

        return node;
    }

    // Fungsi untuk melakukan penelusuran inorder pada AVL Tree
    void _inorder(AVLNode *node)
    {
        if (node)
        {
            _inorder(node->left);
            printf("%d ", node->data);
            _inorder(node->right);
        }
    }

public:
    // Inisialisasi tree
    void init()
    {
        _root = NULL;
        _size = 0U;
    }

    // Cek apakah tree kosong
    bool isEmpty()
    {
        return _root == NULL;
    }

    // Cari nilai pada tree
    bool find(int value)
    {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;

        if (temp->data == value)
            return true;
        else
            return false;
    }

    // Masukkan nilai ke dalam tree
    void insert(int value)
    {
        if (!find(value))
        {
            _root = _insert_AVL(_root, value);
            _size++;
        }
    }

    // Hapus nilai dari tree
    void remove(int value)
    {
        if (find(value))
        {
            _root = _remove_AVL(_root, value);
            _size--;
        }
    }

    // Penelusuran inorder pada tree
    void inorder()
    {
        this->_inorder(_root);
    }

    // Mengembalikan nilai root dari tree
    int root()
    {
        if (_root != NULL)
            return _root->data;
        else
            return -1; // Atau nilai lain yang sesuai untuk menandakan bahwa tree kosong.
    }

    // Mengembalikan tinggi tree
    int height()
    {
        return _getHeight(_root);
    }
};

int main(int argc, char const *argv[])
{
    AVL set;
    set.init();

    // Simpan nilai input dalam sebuah vektor
    std::vector<int> values = {3, 5, 8, 20, 18, 13, 22};

    // Urutkan vektor secara ascending
    std::sort(values.begin(), values.end());

    // Masukkan nilai-nilai yang sudah diurutkan ke dalam AVL tree
    for (int val : values)
    {
        set.insert(val);
    }

    // Penelusuran inorder pada tree
    set.inorder();
    std::cout << "\n";

    // Cetak nilai root dari tree
    if (!set.isEmpty())
        std::cout << "Root: " << set.root() << "\n";
    else
        std::cout << "Tree kosong.\n";

    // Cetak tinggi dari tree
    std::cout << "Tinggi: " << set.height() << "\n";

    return 0;
}