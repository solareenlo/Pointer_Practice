// リスト構造の構造体それぞれに、2つの構造体ポインタを用いて前後関係を持たせる
#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    struct list *next;
    struct list *prev;
    int data;
} LIST;

int main(void) {
    int i;
    LIST *ima, head;

    head.next = (LIST*)&head; // 初期化
    head.prev = (LIST*)&head; // 初期化

    for(i = 0; i < 3; i++) {
        if((ima = malloc(sizeof(LIST))) == NULL) { // 今参照する構造体を動的に生成
            printf("malloc error\n");
            exit(1);
        }
        ima->data = i; // 今参照してる構造体のdataにiの値を代入
        ima->next = head.next; // head.nextには1つ前の構造体のアドレスが格納されてる
        head.next = ima; // 次生成する構造体のために、今の構造体のアドレスをhead.nextに格納してる
        ima->prev = &head; // 1つ下の操作のための初期化. 次への布石
        ima->next->prev = ima; // 1つ前の構造体のprevに、今の構造体のアドレスを格納
    }

    printf("降順に表示(構造体のサイズ:%lu)\n", sizeof(LIST));
    ima = head.next;
    while(ima != &head) {
        printf("前:%p, 今:%p, 次:%p, データ:%d\n", ima->prev, ima, ima->next, ima->data);
        ima = ima->next;
    }
    printf("\n");

    printf("昇順に表示(構造体のサイズ:%lu)\n", sizeof(LIST));
    ima = head.prev;
    while(ima != &head) {
        printf("前:%p, 今:%p, 次:%p, データ:%d\n", ima->prev, ima, ima->next, ima->data);
        ima = ima->prev;
    }

    return 0;
}
