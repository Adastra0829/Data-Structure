//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Node {
//	int ele;
//	char gro;
//	struct Node* enext;
//	struct Node* gnext;
//}Node;
//
//typedef struct g {
//	Node* head;
//}g;
//
//typedef struct e {
//	Node* head;
//}e;
//
//void initShare(g group[], e element[], int ne, int ng) {//초기화
//	Node* h;
//	for (int i = 0; i < ne; i++) {
//		h = (Node*)malloc(sizeof(Node));
//		h->gnext = h;
//		element[i].head = h;
//	}
//	for (int i = 0; i < ng; i++) {
//		h = (Node*)malloc(sizeof(Node));
//		h->enext = h;
//		group[i].head = h;
//	}
//}
//
//Node* getnode(int ele, char gro) {//겟노드
//	Node* node = (Node*)malloc(sizeof(Node));
//	node->ele = ele;
//	node->gro = gro;
//}
//
//void addShare(g group[], e element[], int ele, char gro) {
//	Node* new = getnode(ele, gro);
//
//	Node* hg = group[gro - 'A'].head; //세로추가
//	new->enext = hg->enext;
//	hg->enext = new;
//
//	Node* he = element[ele - 1].head; //가로 추가
//	new->gnext = he->gnext;
//	he->gnext = new;
//
//	printf("OK\n");
//}
//
//void removeShare(g group[], e element[], int ele, char gro) {
//	Node* rem;
//	Node* hg = group[gro - 'A'].head;
//	while (1) {
//		if (hg->enext->ele == ele) {
//			rem = hg->enext;
//			break;
//		}
//		hg = hg->enext;
//	}
//	hg->enext = rem->enext;
//	Node* he = element[ele - 1].head;
//	while (1) {
//		if (he->gnext->gro == gro) {
//			rem = he->gnext;
//			break;
//		}
//		he = he->gnext;
//	}
//	he->gnext = rem->gnext;
//	printf("OK\n");
//	free(rem);//해제
//}
//
//void traverseShareElements(g group[], char gro) { // 'e' 엘리먼트 순회
//	Node* hg = group[gro - 'A'].head;
//	Node* p = hg->enext;
//	if (p == hg) {
//		printf("0\n");
//		return;
//	}
//	while (p != hg) {
//		printf("%d ", p->ele);
//		p = p->enext;
//	}
//	printf("\n");
//}
//
//void traverseShareGroups(e element[], int ele) {// 'g' 그룹순회
//	Node* he = element[ele - 1].head;
//	Node* p = he->gnext;
//	if (p == he) {
//		printf("0\n");
//		return;
//	}
//	while (p != he) {
//		printf("%c ", p->gro);
//		p = p->gnext;
//	}
//	printf("\n");
//}
//
//void finish(g group[], e element[]) {
//	for (int i = 0; i < 5; i++) {
//		Node* remove = group[i].head->enext;
//		Node* p = remove;
//		while (p != group[i].head) {
//			free(p);
//			remove = remove->enext;
//			p = remove;
//		}
//		free(p);
//	}
//	for (int i = 0; i < 4; i++) {
//		Node* remove = element[i].head->gnext;
//		Node* p = remove;
//		while (p != element[i].head) {
//			free(p);
//			remove = remove->gnext;
//			p = remove;
//		}
//		free(p);
//	}
//}
//
//
//int main() {
//	char cmd, gro;
//	int ele;
//	g group[5] = { 0 };
//	e element[4] = { 0 };
//	int ne = 4;
//	int ng = 5;
//	initShare(group, element, ne, ng);
//
//	while (1) {
//
//		scanf("%c", &cmd);
//		getchar();
//		switch (cmd) {
//		case'a':
//			scanf("%d %c", &ele, &gro);
//			getchar();
//			addShare(group, element, ele, gro);
//			break;
//
//		case'r':
//			scanf("%d %c", &ele, &gro);
//			getchar();
//			removeShare(group, element, ele, gro);
//			break;
//
//		case'g':
//			scanf("%d", &ele);
//			getchar();
//			traverseShareGroups(element, ele);
//			break;
//
//		case'e':
//			scanf("%c", &gro);
//			getchar();
//			traverseShareElements(group, gro);
//			break;
//
//		case'q':
//
//			break;
//		}
//
//		if (cmd == 'q') break;
//	}
//
//	finish(group, element);
//
//	//해제
//
//	return 0;
//}
//
//
//
///*
//
//a 1 C
//a 4 A
//a 4 E
//a 4 D
//e A
//g 4
//a 2 A
//e A
//r 4 A
//g 4
//e A
//g 1
//r 1 C
//e C
//g 1
//g 3
//
//
//*/