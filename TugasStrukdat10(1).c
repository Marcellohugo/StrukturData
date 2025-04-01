#include <stdio.h>
#include <stdlib.h>

typedef struct tipeS
{
    struct tipeS *Left;  // Pointer ke vertex anak kiri
    int INFO;            // Informasi yang disimpan dalam vertex
    struct tipeS *Right; // Pointer ke vertex saudara kanan
} simpul;

simpul *P, *FIRST, *LAST, *PVertex, *PEdge, *Q, *R, *S;
simpul *PointS[5];

int main()
{
    int A[5][5] = {{0, 5, 0, 2, 0},
                   {6, 0, 3, 0, 0},
                   {0, 0, 0, 0, 9},
                   {0, 0, 12, 0, 7},
                   {0, 14, 0, 0, 0}};
    char NmS[5] = {'A', 'B', 'C', 'D', 'E'};
    int I, J;

    // Simpul Vertex yang pertama
    I = 0;
    J = 0;
    P = (simpul *)malloc(sizeof(simpul)); // Alokasikan memori untuk sebuah vertex
    P->INFO = NmS[0];                     // Tetapkan label untuk vertex
    FIRST = P;                            // FIRST menunjuk ke vertex pertama
    LAST = P;                             // LAST menunjuk ke vertex terakhir
    P->Left = NULL;                       // Inisialisasi pointer anak kiri
    P->Right = NULL;                      // Inisialisasi pointer saudara kanan
    PointS[0] = P;                        // Simpan vertex pada array
    printf("%c", P->INFO);                // Cetak label dari vertex
    printf(" alamat %p ", PointS[0]);     // Cetak alamat memori dari vertex

    // Simpul Vertex yang berikutnya
    for (I = 1; I <= 4; I++)
    {
        P = (simpul *)malloc(sizeof(simpul)); // Alokasikan memori untuk sebuah vertex
        P->INFO = NmS[I];                     // Tetapkan label untuk vertex
        LAST->Left = P;                       // Sambungkan vertex baru ke kiri vertex terakhir
        LAST = LAST->Left;                    // Perbarui pointer vertex terakhir
        P->Left = NULL;                       // Inisialisasi pointer anak kiri
        P->Right = NULL;                      // Inisialisasi pointer saudara kanan
        PointS[I] = P;                        // Simpan vertex pada array
        printf("\n%c ", P->INFO);             // Cetak label dari vertex
        printf("alamat %p ", PointS[I]);      // Cetak alamat memori dari vertex
    }

    // Simpul Edge untuk semua Vertex
    Q = FIRST; // Mulai dari vertex pertama
    for (I = 0; I <= 4; I++)
    {
        R = Q;                                // R menunjuk ke vertex saat ini
        printf("\nVertex %c .... ", Q->INFO); // Cetak label dari vertex saat ini
        for (J = 0; J <= 4; J++)
        {
            if (A[I][J] != 0)
            {
                P = (simpul *)malloc(sizeof(simpul));             // Alokasikan memori untuk sebuah edge
                P->INFO = A[I][J];                                // Tetapkan bobot untuk edge
                R->Right = P;                                     // Sambungkan edge ke kanan vertex saat ini
                P->Left = PointS[J];                              // Tetapkan pointer anak kiri edge ke vertex terkait
                printf("berhubungan dengan %c: ", P->Left->INFO); // Cetak label dari vertex terhubung
                printf("bobot %d;", P->INFO);                     // Cetak bobot dari edge
                P->Right = NULL;                                  // Inisialisasi pointer saudara kanan edge
                R = P;                                            // Perbarui pointer vertex saat ini
            }
        }
        printf("\n");
        Q = Q->Left; // Pindah ke vertex berikutnya dalam linked list
    }

    return 0;
}

/*A alamat 2126
B alamat 238
C alamat 222
D alamat 206
E alamat 190
Vertex A .... berhubungan dengan B: bobot 5;berhubungan dengan D: bobot 2;
Vertex B .... berhubungan dengan A: bobot 6;berhubungan dengan C: bobot 3;
Vertex C .... berhubungan dengan E: bobot 9;
Vertex D .... berhubungan dengan C: bobot 12;berhubungan dengan E: bobot 7;
Vertex E .... berhubungan dengan B: bobot 14;*/