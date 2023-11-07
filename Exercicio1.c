#include <stdio.h>

int main() {
    int array[10];
    int novo_array[10];
    int tamanho = 10;

    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }

    while (tamanho > 1) {
        for (int i = 0; i < tamanho; i++) {
            if (i == tamanho-1){
                printf("%d", array[i]);
            }
            else{
                printf("%d ", array[i]);
            }
            
        }
        printf("\n");

        int novo_tamanho = 0;

        for (int i = 0; i < tamanho - 1; i++) {
            novo_array[novo_tamanho++] = array[i] + array[i + 1];
        }

        tamanho = novo_tamanho;

        for (int i = 0; i < tamanho; i++) {
            array[i] = novo_array[i];
        }
    }

    printf("%d\n", array[0]);

    return 0;
}