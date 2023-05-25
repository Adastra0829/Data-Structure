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

Node* unionset(Node* ahead, Node* bhead) {//������
	Node* uhead = getnode(0), *r=uhead;
	Node* p=ahead->next, * q=bhead->next;
	while (p != NULL && q != NULL) {//�Ѵ� ������ ������ ���� �ʾ��� ��
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

Node* intersect(Node* ahead, Node* bhead) {//������
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
	Node* uni = NULL, * inter = NULL;//������ ���, ������ ���
	int a = 0, b = 0, x = 0;//���Ұ���, ���Һ���

	scanf("%d", &a);//a����
	if (a != 0) {//0�� �ƴҶ�
		p = ahead;
		for (int i = 0; i < a; i++) {
			scanf("%d", &x);//�Է�
			p->next = getnode(x);
			p = p->next;
		}
	}

	scanf("%d", &b);//b����
	if (b != 0) {//0�� �ƴҶ�
		q = bhead;
		for (int i = 0; i < b; i++) {
			scanf("%d", &x);
			q->next = getnode(x);
			q = q->next;
		}
	}

	if (a != 0 && b != 0) {//a,b�Ѵ� ������ �ƴҶ�
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


	else if (a == 0 && b != 0) {//a�� ������
		q = bhead->next;
		while (q != NULL) {
			printf(" %d", q->data);
			q = q->next;
		}
		printf("\n");
		printf(" 0");
	}

	else if (a != 0 && b == 0) {//b�� ������
		p = ahead->next;
		while (p != NULL) {
			printf(" %d", p->data);
			p = p->next;
		}
		printf("\n");
		printf(" 0");
	}

	else if (a == 0 && b == 0) {//�Ѵ� ������
		printf(" 0\n");
		printf(" 0");
	}

	//�޸� ���� - ahead, bhead�� ������ �������װ� uhead, ihead�� a,b�Ѵ� �������� �ƴҶ��� ��������
	Node* remove = NULL;

	remove = ahead, p = ahead;//a ����
	while (p != NULL) {
		p = p->next;
		free(remove);
		remove = p;
	}

	remove = bhead, q = bhead;//b����
	while (q != NULL) {
		q = q->next;
		free(remove);
		remove = q;
	}

	if (a != 0 && b != 0) {
		remove = uni, p = uni;//������ ����
		while (p != NULL) {
			p = p->next;
			free(remove);
			remove = p;
		}

		remove = inter, q = inter;//������ ����
		while (q != NULL) {
			q = q->next;
			free(remove);
			remove = q;
		}
	}

	return 0;                
}