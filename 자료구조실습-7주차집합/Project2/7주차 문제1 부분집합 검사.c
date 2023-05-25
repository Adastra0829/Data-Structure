//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Node {
//	int data;
//	struct Node* next;
//}Node;
//
//Node* getnode(int data) {
//	Node* node = (Node*)malloc(sizeof(Node));
//	node->data = data;
//	node->next = NULL;
//	return node;
//}
//
//int member(Node* b, int e) {
//	Node* p = b;
//	while (1) {
//		int a = p->data;
//		if (a < e) {
//			if (p->next == NULL)
//				return 0;
//			else
//				p = p->next;
//		}
//		else if (a > e)
//			return 0;
//
//		else if (a == e)
//			return 1;
//	}
//}
//
//int subset(Node* alist, Node* blist) {
//	Node* p = alist;
//	while (1) {
//		if (member(blist, p->data)) {//a�� data�� b�� ���� ��
//			if (p->next == NULL)
//				return 0;//next�� NULL�̸� �κ�����
//			else
//				p = p->next;//NULL�� �ƴϸ� ���� ��� �˻�
//		}
//		else //���Ұ� B�� ���� ��
//			return p->data;//���� ���� ���� data ��ȯ
//	}
//}
//
//
//int main() {
//	int a, b, x = 0;//���Ұ���, ����
//	Node* alist = NULL, * p = NULL, * blist = NULL, * q = NULL;
//
//	scanf("%d", &a);//a ���� �߰�
//	if (a != 0) {
//		scanf("%d", &x);
//		alist = getnode(x);
//		p = alist;
//		for (int i = 0; i < a - 1; i++) {
//			scanf("%d", &x);
//			p->next = getnode(x);//������ �����ؾ��Ѵ�. ������ ������ �ǹ̾���.
//			p = p->next;
//		}
//	}
//
//	scanf("%d", &b);//b ���� �߰�
//	if (b != 0) {
//		scanf("%d", &x);
//		blist = getnode(x);
//		q = blist;
//		for (int i = 0; i < b - 1; i++) {
//			scanf("%d", &x);
//			q->next = getnode(x);
//			q = q->next;
//		}
//	}
//
//	if (a == 0) {//�ᱣ�� ���
//		printf("0");
//	}
//	else {
//		if (b == 0)
//			printf("%d", alist->data);
//
//		else {
//			printf("%d", subset(alist, blist));
//		}
//
//	}
//
//	//�޸� ����
//	Node* remove = NULL;
//
//	if (a != 0) {//a�� �������� �ƴ� ��
//		remove = alist; p = alist;//a���� ����
//		while (p != NULL) {
//			p = p->next;
//			free(remove);
//			remove = p;
//		}
//	}
//	
//	if (b != 0) {//b�� �������� �ƴ� ��
//		remove = blist; q = blist;//b���� ����
//		while (q != NULL) {
//			q = q->next;
//			free(remove);
//			remove = q;
//		}
//	}
//	
//
//	return 0;
//}