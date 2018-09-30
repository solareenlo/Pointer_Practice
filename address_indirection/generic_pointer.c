// 汎用ポインタの例
#include <stdio.h>

int main(void) {
    int num[3];
    char* words[3];
    void* gp; // これが汎用ポインタ
    int i;

    printf("汎用ポインタの例\n");

    for(i = 0; i < 3; i++)
        num[i] = i;
    for(i = 0; i< 3; i++)
        printf("%d ", num[i]);
    printf("\n");

    words[0] = "Taro";
    words[1] = "Hanako";
    words[2] = "Magoroku";
    for(i = 0; i < 3; i++)
        printf("%s ", words[i]);
    printf("\n");

    gp = num;
    for(i = 0; i < 3; i++) {
        printf("\n配列アドレスは%pです.\n", gp);
        printf("汎用ポインタgpが指し示している内容は%dです.\n", *(int*)gp);
        gp = (int*)gp + 1;
    }

    gp = words;
    for(i = 0; i < 3; i++) {
        printf("\n配列アドレスは%pです.\n", gp);
        printf("汎用ポインタgpが指し示している内容は%sです.\n", *(char**)gp);
        gp = (char**)gp + 1;
    }

    return 0;
}
