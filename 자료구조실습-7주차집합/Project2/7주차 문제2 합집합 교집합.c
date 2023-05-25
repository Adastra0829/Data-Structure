#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* getnode(data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
}

Node* unionset(Node* ahead, Node* bhead) {//합집합
	Node* uhead = getnode(0), *r=uhead;
	Node* p=ahead->next, * q=bhead->next;
	while (p != NULL && q != NULL) {//둘다 마지막 노드까지 가지 않았을 때
		int a = p->data, b = q->data;
		if (a < b) {
			r->next = getnode(a);
			r = r->next;//
			p = p->next;
		}
		else if (a > b) {
			r->next = getnode(b);
			r = r->next;
			q = q->next;
		}
		else {//a==b
			r->next = getnode(a);
			r = r->next;
			p = p->next;
			q = q->next;
		}
	}
	while (p != NULL) {
		int a = p->data;
		r->next = getnode(a);
		r = r->next;
		p = p->next;
	}
	while (q != NULL) {
		int b = q->data;
		r->next = getnode(b);
		r = r->next;
		q = q->next;
	}
	return uhead;
}

Node* intersect(Node* ahead, Node* bhead) {//교집합
	Node* ihead = getnode(0), * r = ihead;
	Node* p = ahead->next, * q = bhead->next;
	while (p != NULL && q != NULL) {
		int a = p->data, b = q->data;
		if (a < b) {
			p = p->next;
		}
		else if (a > b) {
			q = q->next;
		}
		else {//a==b
			r->next = getnode(a);
			r = r->next;
			p = p->next;
			q = q->next;
		}
	}
	return ihead;
}

int main() {
	Node* ahead = getnode(0), * bhead = getnode(0), * p = NULL, * q = NULL;
	Node* uni = NULL, * inter = NULL;//합집합 헤더, 교집합 헤더
	int a = 0, b = 0, x = 0;//원소개수, 원소변수

	scanf("%d", &a);//a개수
	if (a != 0) {//0이 아닐때
		p = ahead;
		for (int i = 0; i < a; i++) {
			scanf("%d", &x);//입력
			p->next = getnode(x);
			p = p->next;
		}
	}

	scanf("%d", &b);//b개수
	if (b != 0) {//0이 아닐때
		q = bhead;
		for (int i = 0; i < b; i++) {
			scanf("%d", &x);
			q->next = getnode(x);
			q = q->next;
		}
	}

	if (a != 0 && b != 0) {//a,b둘다 공집합 아닐때
		uni = unionset(ahead, bhead)->next;
		while (uni != NULL) {
			printf(" %d", uni->data);
			uni = uni->next;
		}
		printf("\n");
		inter = intersect(ahead, bhead)->next;
		while (inter != NULL) {
			printf(" %d", inter->data);
			inter = inter->next;
		}
	}


	else if (a == 0 && b != 0) {//a만 공집합
		q = bhead->next;
		while (q != NULL) {
			printf(" %d", q->data);
			q = q->next;
		}
		printf("\n");
		printf(" 0");
	}

	else if (a != 0 && b == 0) {//b만 공집합
		p = ahead->next;
		while (p != NULL) {
			printf(" %d", p->data);
			p = p->next;
		}
		printf("\n");
		printf(" 0");
	}

	else if (a == 0 && b == 0) {//둘다 공집합
		printf(" 0\n");
		printf(" 0");
	}

	//메모리 해제 - ahead, bhead는 무조건 생성시켰고 uhead, ihead는 a,b둘다 공집합이 아닐때만 생성했음
	Node* remove = NULL;

	remove = ahead, p = ahead;//a 해제
	while (p != NULL) {
		p = p->next;
		free(remove);
		remove = p;
	}

	remove = bhead, q = bhead;//b해제
	while (q != NULL) {
		q = q->next;
		free(remove);
		remove = q;
	}

	if (a != 0 && b != 0) {
		remove = uni, p = uni;//합집합 해제
		while (p != NULL) {
			p = p->next;
			free(remove);
			remove = p;
		}

		remove = inter, q = inter;//교집합 해제
		while (q != NULL) {
			q = q->next;
			free(remove);
			remove = q;
		}
	}

	return 0;                
}