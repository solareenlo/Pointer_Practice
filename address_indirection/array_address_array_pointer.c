#include <stdio.h>

int main(void) {
    char str1[] = "Hello";
    char *str2 = "Good";

    printf("%sのアドレス, %sのアドレス, %sの中身\n", str1, str1, str1);
    printf("%p, %p, %s\n", &str1, str1, str1);
    printf("\n");

    printf("%sのポインタのアドレス, %sの先頭のアドレス, %sの中身\n", str2, str2, str2);
    printf("%p, %p, %s\n", &str2, str2, str2);

    return 0;
}
