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
//		if (member(blist, p->data)) {//a의 data가 b에 있을 때
//			if (p->next == NULL)
//				return 0;//next가 NULL이면 부분집합
//			else
//				p = p->next;//NULL이 아니면 다음 노드 검사
//		}
//		else //원소가 B에 없을 때
//			return p->data;//없는 가장 작은 data 반환
//	}
//}
//
//
//int main() {
//	int a, b, x = 0;//원소개수, 원소
//	Node* alist = NULL, * p = NULL, * blist = NULL, * q = NULL;
//
//	scanf("%d", &a);//a 원소 추가
//	if (a != 0) {
//		scanf("%d", &x);
//		alist = getnode(x);
//		p = alist;
//		for (int i = 0; i < a - 1; i++) {
//			scanf("%d", &x);
//			p->next = getnode(x);//생성후 연결해야한다. 연결후 생성은 의미없다.
//			p = p->next;
//		}
//	}
//
//	scanf("%d", &b);//b 원소 추가
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
//	if (a == 0) {//결괏값 출력
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
//	//메모리 해제
//	Node* remove = NULL;
//
//	if (a != 0) {//a가 공집합이 아닐 때
//		remove = alist; p = alist;//a집합 해제
//		while (p != NULL) {
//			p = p->next;
//			free(remove);
//			remove = p;
//		}
//	}
//	
//	if (b != 0) {//b가 공집합이 아닐 때
//		remove = blist; q = blist;//b집합 해제
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