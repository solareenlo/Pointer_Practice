// コマンドラインで入力したときの引数の多重間接参照の例
#include <stdio.h>

int main(int argc, char* argv[]) {
//int main(int argc, char** argv) { // これでも可能
    int i;

    printf("文字列の個数：%d\n", argc);
    for(i = 0; i < argc; i++)
        printf("%d番目の文字列：%s\n", i, argv[i]);
    printf("\n");

    printf("文字列の個数：%d\n", argc);
    for(i = 0; i < argc; i++) {
        printf("%d番目の文字列：%s\n", i, *argv);
        argv++;
    }

    return 0;
}
