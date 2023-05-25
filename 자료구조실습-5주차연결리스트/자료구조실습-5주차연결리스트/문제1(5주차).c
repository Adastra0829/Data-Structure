#pragma warning(disable:4996)//���߿��Ḯ��Ʈ
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {//��� ����
	char data;//����
	struct Node* prev;//������� ����Ű�� ��ũ
	struct Node* next;//������� ����Ű�� ��ũ
}Node;

Node* getnode(char data) {//���ο� ��� ���� �Լ�
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

typedef struct List {
	int node_cnt; //���� ����
	Node* head, * tail;//��� �� Ʈ���Ϸ� ���
}List;

List* initialize() {//���ο� ����Ʈ ���� �Լ�, �ʱ�ȭ
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

void add(List* list, int r, char e) {//�߰�
	if ((r < 1) || (r > list->node_cnt + 1)) {//�����Ϸ��� k��°�� list�� ���Ұ������� ���� ���
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

char removee(List *list, int r) {//����  
	if ((r < 1) || (r > list->node_cnt)) {
		printf("invalid position\n"); return 0;//�� �κж����� �ָԾ���.
	}//�ƿ� void �Լ��� ®� ������ �� ����
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

void print(List* list) {//����Ʈ ���� ��� �Լ�
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
	List* list = initialize();//����Ʈ ����

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