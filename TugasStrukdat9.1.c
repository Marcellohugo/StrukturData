#include <stdio.h>
#include <stdlib.h>

typedef struct mhs
{
    char nrp[10];
    char nama[30];
    int nilai;
    struct mhs *left;
    struct mhs *right;
} mhs;

mhs *input()
{
    mhs *a = (mhs *)malloc(sizeof(mhs));
    printf("nrp   : ");
    scanf("%s", a->nrp);
    printf("nama  : ");
    scanf("%s", a->nama);
    printf("nilai : ");
    scanf("%d", &(a->nilai));
    a->left = NULL;
    a->right = NULL;
    return a;
}

void output(mhs *a)
{
    printf("nrp   = %s\n", a->nrp);
    printf("nama  = %s\n", a->nama);
    printf("nilai = %d\n", a->nilai);
}

void printPreorder(mhs *a)
{
    if (a == NULL)
        return;
    output(a);
    printPreorder(a->left);
    printPreorder(a->right);
}

int main()
{
    mhs *data = NULL;
    data = input();
    data->left = input();
    data->right = input();
    data->left->left = input();
    data->left->right = input();
    printPreorder(data);

    return 0;
}
