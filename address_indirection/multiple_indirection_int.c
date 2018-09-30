// int型におけるポインタのポインタの説明
#include <stdio.h>

int main(void) {
    int data[3];
    int i;
    int* pi;
    int** ppi;

    printf("int型における多重間接参照の例\n");
    for(i = 0; i < 3; i++)
        data[i]=i;
    for(i = 0; i < 3; i++)
        printf("%d\n", data[i]);

    pi = data;
    ppi = &pi;

    for(i = 0; i < 3; i++) {
        printf("\ndata[%d]の配列アドレスは%pです.\n", i, data);
        printf("ポインタpiが指し示している内容(data[%d]の値)は%dです.\n", i, *pi);
        printf("ポインタpiのポインタppiが指し示している内容(ポインタpiが持っている値=data[%d]のアドレス)は%pで,\n", i, *ppi);
        printf("2重間接参照によってppiが指し示している内容は%dです.\n\n", **ppi);
        printf("ポインタpi自体のアドレスは%pで, ppiはポインタpiのアドレス(値は%p)を持っています.\n\n", &pi, ppi);
        printf("ポインタpiが持っている値は%pで,ポインタpiは%dを指し示しています.\n\n", pi, *pi);
        pi += 1;
    }

    return 0;
}
