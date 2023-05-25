#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {//노드 정의
	int coef;//항의 계수
	int exp;//항의 차수
	struct Node* next;//다음 노드 링크
}Node;

Node* getnode(int coef, int exp) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->coef = coef;
	node->exp = exp;
	node->next = NULL;
	return node;
}

typedef struct List {
	int node_cnt; //원소 개수
	Node* head;//헤더 노드
}List;

List* initialize() {//새로운 리스트 생성 함수, 초기화
	List* list = (List*)malloc(sizeof(List));
	Node* H = getnode(0, 0);
	list->head = H;
	H->next = NULL;
	list->node_cnt = 0;
	return list;
}

void appendTerm(Node* k, int c, int e) {//마지막항,계수,차수
	Node* t = getnode(c,e);
	t->next = NULL;
	k->next = t; 
	//k = t;//흐음 이부분...
	return;
}

Node* addPoly(Node* x, Node* y) {
	Node* result = getnode(0,0);//List result의 헤더
	result->next = NULL;
	Node* i = x->next, * j = y->next;
	Node* k = result;
	while ((i != NULL) && (j != NULL)) {
		if (i->exp > j->exp) {
			appendTerm(k, i->coef, i->exp);
			i = i->next;
			k = k->next;
		}
		else if (i->exp < j->exp) {
			appendTerm(k, j->coef, j->exp);
			j = j->next;
			k = k->next;
		}
		else if(i->exp == j->exp) {
			int sum = i->coef + j->coef;
			if (sum != 0) {
				appendTerm(k, sum, i->exp);
				k = k->next;
			}
			i = i->next;
			j = j->next;
		}
	}
	while (i != NULL) {
		appendTerm(k, i->coef, i->exp);
		i = i->next;
		k = k->next;
	}
	while (j != NULL) {
		appendTerm(k, j->coef, j->exp);
		j = j->next;
		k = k->next;
	}
	return result;
}


int main() {
	List* exp1 = initialize();//다항식1
	Node* last1 = exp1->head;
	List* exp2 = initialize();//다항식2
	Node* last2 = exp2->head;
	List* result = initialize();//결과
	int p1, p2, coef, exp;

	scanf("%d", &p1);//다항식1
	for (int i = 0; i < p1; i++) {
		scanf("%d %d", &coef, &exp);
		appendTerm(last1, coef, exp);
		last1 = last1->next;
	}

	scanf("%d", &p2);//다항식2
	for (int i = 0; i < p2; i++) {
		scanf("%d %d", &coef, &exp);
		appendTerm(last2, coef, exp);
		last2 = last2->next;
	}
	
	result->head = addPoly(exp1->head, exp2->head);
	Node* p = result->head->next;
	while (p != NULL) {
		printf(" %d %d", p->coef, p->exp);
		p = p->next;
	}
	
	Node* remove = exp1->head;//exp1해제
	p = exp1->head;
	while (p != NULL) {
		remove = p->next;
		free(p);
		p = remove;
	}
	free(exp1);

	remove = exp2->head;//exp2해제
	p = exp2->head;
	while (p != NULL) {
		remove = p->next;
		free(p);
		p = remove;
	}
	free(exp2);

	remove = result->head;//result 해제
	p = result->head;
	while (p != NULL) {
		remove = p->next;
		free(p);
		p = remove;
	}
	free(result);


	return 0;
}

/*

3
5 3 3 2 3 1
3
2 6 2 3 1 0

2
2 7 3 0
3
-3 10 3 7 -3 0

*/