#include <stdio.h>

int main(){

    int vetor[3] = {1, 2, 3};

    int *ponteiro = &vetor[0];
    printf("%p\n", ponteiro);

    ponteiro = &vetor[1];
    printf("%i\n", *ponteiro);

    ponteiro = &vetor[2];
    printf("%d\n", *ponteiro);

    getchar();
    return 0;
}