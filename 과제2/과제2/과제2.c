//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Node {//���
//	int ele;
//	char gro;
//	struct Node* nextelement, * prevelement;
//	struct Node* nextgroup, * prevgroup;
//}Node;
//
//Node* getnode(int ele, int gro) {//�ٳ��
//	Node* node = (Node*)malloc(sizeof(Node));
//	node->ele = ele;
//	node->gro = gro;
//	node->nextelement = NULL; node->prevelement = NULL; //����
//	node->nextgroup = NULL; node->prevgroup = NULL; //����
//	return node;
//}
//
//typedef struct eleList {//��������Ʈ: �����ִ� �������Ʈ
//	int data;
//	int node_cnt;
//	Node* head, *tail;
//}eleList;
//
//typedef struct groList {//�������Ʈ: �����ִ� ��������Ʈ
//	char data;
//	int node_cnt;
//	Node* head, *tail;
//}groList;
//
//void initShare(eleList* elements[], groList* groups[], int NE, int NG) {//�ʱ�ȭ
//	Node* H,* T;
//	for (int i = 0; i < NE; i++) {
//		elements[i] = (eleList*)malloc(sizeof(eleList));
//		H = getnode(0, 0); T = getnode(0, 0);
//		elements[i]->head = H;
//		elements[i]->tail = T;
//		elements[i]->node_cnt = 0;
//	}
//	for (int i = 0; i < NG; i++) {
//		groups[i] = (groList*)malloc(sizeof(groList));
//		H = getnode(0, 0); T = getnode(0, 0);
//		groups[i]->head = H;
//		groups[i]->tail = T;
//		groups[i]->node_cnt = 0;
//	}
//	return;
//}
//
//void traverseShareElements(groList* groups[], char g) {//���� ��ȸ
//	if (groups[(int)(g - 'A')]->node_cnt == 0) {
//		printf("0\n"); return;
//	}
//	Node* p = groups[(int)(g - 'A')]->head->nextelement;
//	while (p != groups[(int)(g - 'A')]->tail) {
//		printf("%d ", p->ele);
//		p = p->nextelement;
//	}
//	printf("\n");
//	return;
//}
//
//void traverseShareGroups(groList* elements[], int e) {//�̿��� ��ȸ
//	if (elements[e]->node_cnt == 0) {
//		printf("0\n"); return;
//	}
//	Node* p = elements[e]->head->nextgroup;
//	while (p != elements[e]->tail) {
//		printf("%c ", p->gro);
//		p = p->nextgroup;
//	}
//	printf("\n");
//	return;
//}
//
//void addShare(eleList *elements[], groList* groups[], int e, char g) {//���� ����
//	if ((e < 1) || (e > 4) || (int)(g - 'A') < 0 || (int)(g - 'A') > 5) {
//		printf("invaild position\n"); return;
//	}
//	Node* p = getnode(e, g);
//	if (elements[e]->node_cnt == 0) {//0���϶�
//		p->prevgroup = elements[e]->head;
//		p->nextgroup = elements[e]->tail;
//		elements[e]->head->nextgroup = p;
//		elements[e]->tail->prevgroup = p;
//		elements[e]->node_cnt++;
//	}
//	else {//0�� �ƴҶ�
//		Node* h = elements[e]->head->nextgroup;
//		while (g < h->gro && h != elements[e]->tail)
//			h = h->nextgroup;
//		p->prevgroup = h->prevgroup;
//		p->nextgroup = h;
//		h->prevgroup->nextgroup = p;
//		h->prevgroup = p;
//		elements[e]->node_cnt++;
//		
//	}
//	if (groups[(int)(g - 'A')]->node_cnt == 0) {//0���϶�
//		p->prevelement = groups[(int)(g - 'A')]->tail;
//		p->nextelement = groups[(int)(g - 'A')]->tail;
//		groups[(int)(g - 'A')]->head->nextelement = p;
//		groups[(int)(g - 'A')]->tail->prevelement = p;
//		groups[(int)(g - 'A')]->node_cnt++;
//	}
//	else {//0�� �ƴҶ�
//		groups[(int)(g - 'A')]->node_cnt++;
//		Node* h = groups[(int)(g - 'A')]->head->nextelement;
//		while (e < h->ele && h != groups[(int)(g - 'A')]->tail)
//			h = h->nextelement;
//		p->prevelement = h->prevelement;
//		p->nextelement = h;
//		h->prevelement->nextelement = p;
//		h->prevelement = p;
//		groups[(int)(g - 'A')]->node_cnt++;
//	}
//	printf("OK\n");
//	return;
//}
//
//void removeShare(eleList* elements[], groList* groups[], int e, char g) {//���� ����
//	if ((e < 1) || (e > 4) || (int)(g - 'A') < 0 || (int)(g - 'A') > 5) {
//		printf("invaild position\n"); return;
//	}
//	Node* p = elements[e]->head;
//	while (p->gro != g) {//
//		p = p->nextgroup;
//	}
//	p->prevgroup->nextgroup = p->nextgroup;
//	p->nextgroup->prevgroup = p->prevgroup;
//	p->prevelement->nextelement = p->nextelement;
//	p->nextelement->prevelement = p->prevelement;
//	printf("OK\n");
//	free(p);
//}
//
//int main() {//����
//	char cmd, g;
//	int e;
//	eleList* elements[4] = { 0 };
//	groList* groups[5] = { 0 };
//
//	for (int i = 0; i < 4; i++)
//		elements[i]->data = i + 1;
//
//	for (int i = 0; i < 5; i++)
//		groups[i]->data = 'A' + i;
//
//	initShare(elements, groups, 4, 5);
//
//	while(1) {
//		scanf("%c", &cmd);
//		switch (cmd) {
//		case'a':
//			scanf("%d %c", &e, &g);
//			addShare(elements, groups, e, g);
//			getchar();//
//			break;
//		case'r':
//			scanf("%d %c", &e, &g);
//			removeShare(elements, groups, e, g);
//			getchar();//
//			break;
//		case'e':
//			scanf("%c", &g);
//			traverseShareElements(groups, g);//���� ��ȸ
//			getchar();//
//			break;
//		case'g':
//			scanf("%d", &e);
//			traverseShareGroups(elements, e);//�̿��� ��ȸ
//			getchar();//
//			break;
//		case'q':
//			break;
//		}
//		if (cmd == 'q') break;
//	}
//
//	return 0;
//}