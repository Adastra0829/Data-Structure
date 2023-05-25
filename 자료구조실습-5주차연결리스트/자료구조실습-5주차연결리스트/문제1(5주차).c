#pragma warning(disable:4996)//이중연결리스트
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {//노드 정의
	char data;//원소
	struct Node* prev;//이전노드 가리키는 링크
	struct Node* next;//다음노드 가리키는 링크
}Node;

Node* getnode(char data) {//새로운 노드 생성 함수
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

typedef struct List {
	int node_cnt; //원소 개수
	Node* head, * tail;//헤더 및 트레일러 노드
}List;

List* initialize() {//새로운 리스트 생성 함수, 초기화
	List* list = (List*)malloc(sizeof(List));
	Node* H = getnode(0), * T = getnode(0);
	list->head = H, list->tail = T;
	H->next = T, T->prev = H;
	list->node_cnt = 0;
	return list;
}

void addNodeBefore(Node* p, char data ) {
	Node* q = getnode(data);
	q->prev = p->prev;
	q->next = p;
	p->prev->next = q;
	p->prev = q;
	return;
}

void add(List* list, int r, char e) {//추가
	if ((r < 1) || (r > list->node_cnt + 1)) {//삽입하려는 k번째가 list내 원소개수보다 많은 경우
		printf("invalid position\n"); return;
	}
	Node* p = list->head;
	for (int i = 1; i <= r; i++) p = p->next;
	addNodeBefore(p, e);
	list->node_cnt++;
	return;
}
char removeNode(Node* p) {
	char e = p->data;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
	return e;
}

char removee(List *list, int r) {//삭제  
	if ((r < 1) || (r > list->node_cnt)) {
		printf("invalid position\n"); return 0;//이 부분때문에 애먹었다.
	}//아예 void 함수로 짰어도 괜찮을 것 같다
	Node* p = list->head;
	for (int i = 1; i <= r; i++) p = p->next;
	char e = removeNode(p);
	list->node_cnt--;
	return e;
}

char get(List* list, int r) {
	if ((r < 1) || (r > list->node_cnt)) {
		printf("invalid position\n"); return 0;
	}
	Node* p = list->head;
	for (int i = 1; i <= r; i++) p = p->next;
	int e = p->data;
	return e;
}

void print(List* list) {//리스트 원소 출력 함수
	Node* p = list->head->next;
	while (p != list->tail) {
		printf("%c", p->data);
		p = p->next;
	}
	return;
}


int main() {
	int N, i, r;
	char x, e;
	List* list = initialize();//리스트 생성

	scanf("%d", &N);
	getchar();

	for (i = 0; i < N; i++) {
		scanf("%c", &x);
		if (x == 'A') {
			scanf("%d", &r); getchar(); scanf("%c", &e); getchar();
			add(list, r, e);
		}
		else if (x == 'D') {
			scanf("%d", &r); getchar();
			char k = removee(list, r);
		}
		else if (x == 'G') {
			scanf("%d", &r); getchar();
			char k = get(list, r);
			if (k!=0)
			printf("%c\n", k);
		}
		else if (x == 'P') {
			getchar();
			print(list);
			printf("\n");
		}
	} 
	return 0;
}

/*

5
A 1 S
A 2 t
A 3 r
A 3 a
P

9
A 1 D
A 2 a
A 3 y
D 1
P
G 3
A 1 S
P
G 3

*/