
#include "algorithms.h"

void inputArray(int *a, size_t size){
    for(size_t i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
}

void outputArray(int *a, size_t size){
    for(size_t i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}