// 多重間接参照(ポインタのポインタ)を使って1文字ずつ表示
#include <stdio.h>

int main(void) {
    char* words[3];
    char* pc;
    char** ppc;
    int i;

    printf("char型の多重間接参照の例\n");

    words[0] = "Taro";
    words[1] = "Hanako";
    words[2] = "Magoroku";
    for(i = 0; i < 3; i++)
        printf("%s\n", words[i]);

    printf("\n多重間接参照を使って1文字ずつ表示\n");
    ppc = words;
    for(i = 0; i < 3; i++) {
        ppc = words + i;
        pc = *ppc;
        while(*pc != 0) {
            printf("%c ", *pc);
            pc += 1;
        }
        printf("\n");
    }

    for(i = 0; i < 3; i++) {
        pc = *(words+i);
        while(*pc != 0) {
            printf("%c ", *pc);
            pc += 1;
        }
        printf("\n");
    }

    return 0;
}
