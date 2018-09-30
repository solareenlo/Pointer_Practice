// 構造体ポインタを使う際の注意点
// パディングがあるので構造体のサイズは変化します
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
    double c;
    long long int d;
} KOUZOU1;

typedef struct {
    int a;
    double c;
    int b;
    long long int d;
} KOUZOU2;

int main(void) {
    KOUZOU1 *p;
    KOUZOU2 *q;

    printf("構造体1のサイズは%luです.\n", sizeof(KOUZOU1));
    printf("構造体2のサイズは%luです.\n", sizeof(KOUZOU2));

    return 0;
}
