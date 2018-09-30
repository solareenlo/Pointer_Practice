#include <stdio.h>

int main(void) {
    char str[] = "Hello World";

    // 配列の中身、配列の先頭の値、配列の中身のアドレス、配列の先頭の値のアドレス、配列のアドレス
    printf("%s, %c, %p, %p, %p\n", str, str[0], &str, &str[0], str);

    return 0;
}
