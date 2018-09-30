// realloc関数(確保したメモリの割り当てを変更する関数)の例
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char* s;
    char* t;
    int i;

    i = sizeof(char);
    s = (char*)malloc(i);
    strncpy(s, "Taro Yamada", i*8);
    printf("sには%sが入っています.\n", s);
    printf("sのアドレスは%pです.\n", s);

    t = (char*)realloc(s, 12);
    if(s != t) {
        memcpy(t, s, sizeof(char));
        free(s);
    }
    strncpy(t, "Taro Yamada", i*12);
    strcat(t, " is good.");
    printf("tには%sが入っています.\n", t);
    printf("tのアドレスは%pです.\n", t);

    free(t);

    return 0;
}
