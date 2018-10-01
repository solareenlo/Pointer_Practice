// 構造体の簡単なリスト構造の例
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    struct list *next;
    int data;
} LIST;

int main(void) {
    int i;
    LIST *head, *temp;

    head = NULL; // 先頭ポインタにNULLを設定

    for(i = 0; i < 3; i++) {
        if((temp = malloc(sizeof(LIST))) == NULL) {
            printf("malloc error\n");
            exit(1);
        }
        temp->data = i;
        // ポインタのつなぎ変え
        temp->next = head; // 今までの先頭ポインタを次ポインタに
        head = temp; // 新たな領域を先頭ポインタに
    }

    temp = head;
    while(temp != NULL) {
        printf("現在のリストは%p, 次のリストは%p, 格納データは%d\n", temp, temp->next, temp->data);
        temp = temp->next;
    }

    return 0;
}
