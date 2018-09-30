// sizeofとmallocを使った、動的配列の例
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char* s;
    int size;

    size = sizeof("Thanks");
    printf("'Thanks'のサイズは%dです.\n", size);

    s = (char*)malloc(size);
    if(s == NULL) {
        printf("malloc失敗\n");
        exit(0);
    }

    strncpy(s, "Thanks", size);

    printf("sには%sが代入されています.\n", s);
    s[0] = 'H';
    printf("sには%sが代入されています.\n", s);

    return 0;
}
