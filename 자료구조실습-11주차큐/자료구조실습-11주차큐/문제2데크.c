//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct Node {
//    int data;
//    struct Node* prev, * next;
//}Node;
//
//Node* getnode(int data) {
//    Node* new = (Node*)malloc(sizeof(Node));
//    if (new == NULL) printf("error\n");
//    new->data = data;
//    new->prev = new->next = NULL;
//    return new;
//}
//
//typedef struct Deque {
//    Node* front, * rear;
//}Deque;
//
//Deque* initialize() {
//    Deque* new = (Deque*)malloc(sizeof(Deque));
//    if (new == NULL) printf("error\n");
//    new->front = new->rear = NULL;
//    return new;
//}
//
//int emptyDequeException(Deque* d) {
//    return d->front == NULL;
//}
//
//void add_front(Deque* d, int data) {
//    Node* new = getnode(data);
//    if (d->front == NULL) {//빈 데크
//        d->front = d->rear = new;
//    }
//    else {//빈 데크x
//        new->next = d->front;
//        d->front->prev = new;
//        d->front = new;
//    }
//}
//
//void add_rear(Deque* d, int data) {
//    Node* new = getnode(data);
//    if (d->front == NULL) {//빈 데크
//        d->front = d->rear = new;
//    }
//    else {//빈 데크x
//        new->prev = d->rear;
//        d->rear->next = new;
//        d->rear = new;
//    }
//}
//
//int delete_front(Deque* d) {
//    if (emptyDequeException(d)) {//빈 데크
//        printf("underflow");
//        return -1;
//    }
//    else {//빈 데크 x
//        Node* p = d->front;
//        int data = p->data;
//        if (d->front == d->rear) {//노드가 한개 
//            d->front = d->rear = NULL;
//        }
//        else {//노드가 여러개
//            d->front = d->front->next;
//        }
//        free(p);
//        return data;
//    }
//}
//
//int delete_rear(Deque* d) {
//    if (emptyDequeException(d)) {
//        printf("underflow");
//        return -1;
//    }
//    else {//빈 데크 x
//        Node* p = d->rear;
//        int data = p->data;
//        if (d->front == d->rear) {//노드가 한개 
//            d->front = d->rear = NULL;
//        }
//        else {//노드가 여러개
//            d->rear = d->rear->prev;
//            d->rear->next = NULL;
//        }
//        free(p);
//        return data;
//    }
//}
//
//void print(Deque* d) {
//    if (emptyDequeException(d)) {
//        printf("underflow");
//        return;
//    }
//    else {
//        Node* p = d->front;
//        while (p) {
//            printf(" %d", p->data);
//            p = p->next;
//        }
//        printf("\n");
//    }
//}
//
//void finish(Deque* d) {
//    Node* p = d->front;
//    Node* boom;
//    while (p) {
//        boom = p;
//        p = p->next;
//        free(boom);
//    }
//}
//
//int main() {
//    Deque* d = initialize();
//
//
//    char order[2 + 1] = { 0 }; int input, result;
//    int num_of_order; scanf("%d", &num_of_order); getchar();
//
//    for (int i = 0; i < num_of_order; i++) {
//        scanf("%s", order); getchar();//명령 입력
//
//        if (strcmp(order, "AF") == 0) {
//            scanf("%d", &input); getchar();
//            add_front(d, input);
//        }
//
//        else if (strcmp(order, "AR") == 0) {
//            scanf("%d", &input); getchar();
//            add_rear(d, input);
//        }
//
//        else if (strcmp(order, "DF") == 0) {
//            result = delete_front(d);
//        }
//        else if (strcmp(order, "DR") == 0) {
//            result = delete_rear(d);
//        }
//        else if (strcmp(order, "P") == 0) {
//            print(d);
//        }
//
//        if (result == -1) break;
//    }
//
//    finish(d);
//    free(d);
//    return 0;
//} 