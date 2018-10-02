// データを2つの構造体のポインタを使って、リスト構造で格納し、
// データを先入れ先出しと、先入れ後出しを行う
// データの先出しと後出しはそれぞれコメントアウトしながら入れ替えて使う
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    struct list *next;
    struct list *prev;
    int data;
} LIST;

typedef struct {
    struct list *first;
    struct list *last;
} HEADER;
HEADER head;

void enqueue(LIST *ima);
LIST *dequeue(); // データ先出し用の関数
LIST *aoqueue(); // データ後出し用の関数

int main(void) {
    int i;
    LIST *ima;

    head.first = (LIST*)&head;
    head.last = (LIST*)&head;

    // ima構造体にデータを先入れ
    for(i = 0; i < 9; i++) {
        ima = malloc(sizeof(LIST));
        ima->data = i;
        enqueue(ima);
        printf("前:%p, 今:%p, 次:%p, データ:%d\n", ima->prev, ima, ima->next, ima->data);
    }

    printf("first item = %d\n", head.first->data);
    printf("last item = %d\n", head.last->data);

    printf("普通に降順で出力\n");
    while(ima != (LIST*)&head) {
        printf("前:%p, 今:%p, 次:%p, データ:%d\n", ima->prev, ima, ima->next, ima->data);
        ima = ima->prev;
    }

    printf("普通に昇順で出力\n");
    ima = head.first;
    while(ima != (LIST*)&head) {
        printf("前:%p, 今:%p, 次:%p, データ:%d\n", ima->prev, ima, ima->next, ima->data);
        ima = ima->next;
    }

    // ima構造体からデータを先出し
    /* printf("データを先出し\n"); */
    /* do { */
    /*     ima = dequeue(); */
    /*     if(ima != NULL) { */
    /*         printf("前:%p, 今:%p, 次:%p, データ:%d\n", ima->prev, ima, ima->next, ima->data); */
    /*         free(ima); */
    /*     } */
    /* } while(ima != NULL); */

    // ima構造体からデータを後出し
    printf("データを後出し\n");
    do {
        ima = aoqueue();
        if(ima != NULL) {
            printf("前:%p, 今:%p, 次:%p, データ:%d\n", ima->prev, ima, ima->next, ima->data);
            free(ima);
        }
    } while(ima != NULL);

    return 0;
}

// データ先出し用の関数
LIST *dequeue() {
    LIST *temp;
    temp = head.first;
    if(temp == (LIST*)&head) {
        temp = NULL;
    } else {
        head.first = temp->next;
        head.first->prev = (LIST*)&head;
    }
    return temp;
}

// データ後出し用の関数
LIST *aoqueue() {
    LIST *temp;
    temp = head.last;
    if(temp == (LIST*)&head) {
        temp = NULL;
    } else {
        head.last = temp->prev;
        head.last->next = (LIST*)&head;
    }
    return temp;
}

// データをリスト構造でリンク付けしつつ、
// リスト構造の最初と最後のアドレスをhead.firstとhead.lastに格納
void enqueue(LIST *ima) {
    LIST *temp; // 飛び石用の構造体ポインタ生成
    temp = head.last; // tempに1つ前の構造体のアドレスを代入
    head.last = ima; // 今のアドレスを代入して、次の構造体が参照できる用に
    ima->prev = temp; // 今のprevに1つ前の構造体のアドレスを代入
    ima->next = (LIST*)&head; //今のnextにheadのアドレスを代入して初期化
    temp->next = ima; // 1つ前の構造体のnextに今のアドレスを代入
}
