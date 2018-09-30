// 動的にメモリを確保
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* string_func(char*);

int main(void) {
    printf("%s", string_func("山田"));
    printf("%s",string_func("aaaaaaaaaaaaaaaaaaaaaaa"));
    return 0;
}

char* string_func(char* string) {
    char* s;
    s = (char*)malloc(128);
    s[0] = 0;
    strcat(s, "Hello ");
    strcat(s, string);
    strcat(s, "\n");
    return s;
}
