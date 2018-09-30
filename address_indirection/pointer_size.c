// 色々な型のポインタのサイズの確認
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i[2];
    float f[2];
    double d[2];
    long long int lli[2];
    short int si[2];
    long int li[2];

    int* pi;
    float* pf;
    double* pd;
    long long int* plli;
    short int* psi;
    long int* pli;

    int j;

    printf("それぞれの型のサイズは(単位はbyte)\n");
    printf("int : %lu\n", sizeof(int));
    printf("float : %lu\n", sizeof(float));
    printf("doulbe : %lu\n", sizeof(double));
    printf("long long int : %lu\n", sizeof(long long int));
    printf("short int : %lu\n", sizeof(short int));
    printf("long int : %lu\n", sizeof(long int));
    printf("\n");

    pi = i;
    pf = f;
    pd = d;
    plli = lli;
    psi = si;
    pli = li;

    for(j = 0; j < 2; j++) {
        i[j] = j;
        f[j] = (float)j;
        d[j] = (double)j;
        lli[j] = j;
        si[j] = j;
        li[j] = j;
    }

    pi += 1;
    pf += 1;
    pd += 1;
    plli += 1;
    psi += 1;
    pli += 1;

    printf("iのアドレス : %p[%d]\n", i, i);
    printf("piの値      : %p[%d]\n", pi, pi);
    printf("piが指し示している値 : %d\n\n", *pi);
    printf("fのアドレス : %p[%d]\n", f, f);
    printf("pfの値      : %p[%d]\n", pf, pf);
    printf("pfが指し示している値 : %f\n\n", *pf);
    printf("dのアドレス : %p[%d]\n", d, d);
    printf("pdの値      : %p[%d]\n", pd, pd);
    printf("pdが指し示している値 : %lf\n\n", *pd);
    printf("lliのアドレス : %p[%d]\n", lli, lli);
    printf("plliの値      : %p[%d]\n", plli, plli);
    printf("plliが指し示している値 : %lld\n\n", *plli);
    printf("siのアドレス : %p[%d]\n", si, si);
    printf("psiの値      : %p[%d]\n", psi, psi);
    printf("psiが指し示している値 : %hd\n\n", *psi);
    printf("liのアドレス : %p[%d]\n", li, li);
    printf("pliの値      : %p[%d]\n", pli, pli);
    printf("pliが指し示している値 : %ld\n\n", *pli);

    return 0;
}
