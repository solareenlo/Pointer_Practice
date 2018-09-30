// 構造体ポインタを使う際の注意点
// パディングがあるので構造体のサイズは変化し、
// データの格納の仕方が違います.
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
    void* v;
    int i;

    printf("構造体1のサイズは%luです.\n", sizeof(KOUZOU1));
    p = (KOUZOU1*)calloc(3, sizeof(KOUZOU1));
    for(i = 0; i < 3; i++) {
        p[i].a = i;
        p[i].b = i * 10;
        p[i].c = 1000000000.0 + i;
        p[i].d = 1234567890 + i;
    }

    v = p + 2;

    printf("構造体1のデータの入り方\n");
    for(i = 0; i < sizeof(KOUZOU1)/sizeof(int); i++)
        printf("v[%d] = %d\n", i, ((int*)v)[i]);
    free(p);

    printf("\n");

    printf("構造体2のサイズは%luです.\n", sizeof(KOUZOU2));
    q = (KOUZOU2*)calloc(3, sizeof(KOUZOU2));
    for(i = 0; i < 3; i++) {
        q[i].a = i;
        q[i].b = i * 10;
        q[i].c = 1000000000.0 + i;
        q[i].d = 1234567890 + i;
    }

    v = q + 2;

    printf("構造体2のデータの入り方\n");
    for(i = 0; i < sizeof(KOUZOU2)/sizeof(int); i++)
        printf("v[%d] = %d\n", i, ((int*)v)[i]);
    free(q);

    return 0;
}
