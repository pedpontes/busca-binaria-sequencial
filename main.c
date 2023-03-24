#include <stdio.h>
#include <malloc.h>
#include <time.h>

typedef struct
{
    long long int id_product;
    double quantidade;
} Product;

int *gerarVetorOrd(long long int size)
{
    int *vet;
    vet = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        vet[i] = i + 1;

    return vet;
}

Product *gerarStruct(long long int size)
{

    Product *vet = (Product *)malloc(size * sizeof(Product));
    for (int i = 0; i < size; i++)
    {
        vet[i].id_product = i + 1;
        vet[i].quantidade = i % 10000;
    }

    return vet;
}

int searchSeq(int *vet, long long int size, int key)
{
    int *aux;
    for (int i = 0; i < size; i++)
    {
        if (vet[i] == key)
            return i;
    }
    return -1;
}

int searchBinnary(int *vet, long long int size, int key)
{
    int max = size - 1;
    int min = 0;
    int mid;
    while (min <= max)
    {
        mid = (max + min) / 2;
        if (vet[mid] > key)
            max = mid - 1;
        else if (vet[mid] < key)
            min = mid + 1;
        else
            return mid;
    }
    return -1;
}

int searchBseq(Product *vet, long long int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (vet[i].id_product == key)
            return i;
    }
    return -1;
}

int searchBstruct(Product *vet, long long int size, int key)
{
    int max = size - 1;
    int min = 0;
    int mid;
    while (min <= max)
    {
        mid = (max + min) / 2;
        if (vet[mid].id_product > key)
            max = mid - 1;
        else if (vet[mid].id_product < key)
            min = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    Product *estrut;
    int key = 15000000;
    long long int size = 15000000;
    int index;
    double time_spent = 0;
    int *vet;

    // vet = gerarVetorOrd(size);

    // clock_t begin = clock(); // inicio da contagem

    // index = searchSeq(vet, size, key); // operação binaria

    // clock_t end = clock(); // fim da contagem

    // printf("%d", index);

    // time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    // printf("\n%f segundos duraram a execução.", time_spent);

    estrut = gerarStruct(size);

    index = searchBstruct(estrut, size, key);

    printf("%d", index);


    return 0;
}