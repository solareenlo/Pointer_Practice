// mallocとcallocの違いの例
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char* s;
    int i;
    int* p;

    printf("mallocでchar型の動的配列を確保\n");
    s = (char*)malloc(3 * sizeof(char));
    for(i = 0; i < 3; i++)
        printf("s[%d] = %d\n", i, s[i]);
    free(s);
    printf("\n");

    printf("callocでchar型の動的配列を確保\n");
    s = (char*)calloc(3, sizeof(char));
    for(i = 0; i < 3; i++)
        printf("s[%d] = %d\n", i, s[i]);
    free(s);
    printf("\n");

    printf("mallocでint型の動的配列を確保\n");
    p = (int*)malloc(3 * sizeof(int));
    for(i = 0; i < 3; i++)
        printf("s[%d] = %d\n", i, p[i]);
    free(p);
    printf("\n");

    printf("callocでint型の動的配列を確保\n");
    p = (int*)calloc(3, sizeof(int));
    for(i = 0; i < 3; i++)
        printf("s[%d] = %d\n", i, p[i]);
    free(p);
    printf("\n");

    return 0;
}
