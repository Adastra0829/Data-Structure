#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* getnode(int data) {
	Node* node;
	node = (Node*)malloc(sizeof(Node));
	if (node == NULL) { printf("error"); }
	node->data = data;
	node->next = NULL;
	return node;
}

typedef struct Queue {
	Node* front;
	Node* rear;
	int cnt;
}Queue;

Queue* initialize() {
	Queue* que = (Queue*)malloc(sizeof(Queue));
	if (que == NULL) {printf("error"); }
	que->front = que->rear = NULL; 
	que->cnt = 0;
	return que;
}

//�Լ� ȣ�� ���� ���� ������ üũ�ؾ���. ������ ���� �ִٴ� ���� �Ͽ� ���� �Լ�
int pop(Queue *q) { //�Ϲ� ť pop �޽��
	Node* p = q->front; int x = q->front->data;
	if (p->next == NULL) {//���Ұ� �ϳ��� �� 
		q->front = q->rear = NULL;
	}
	else {//���Ұ� �ϳ����� ���� ��
		q->front = q->front->next;
	}
	free(p); 
	q->cnt--;
	return x;
}

void push(Queue* q, int data) { //�Ϲ� ť push �޽��
	Node* node = getnode(data);
	if (q->cnt==0) {//����ִ� ť
		q->front = q->rear = node;
	}
	else {//������� �ʴ� ť
		q->rear->next = node;
		q->rear = node;
	}
	q->cnt++;
	return;
}

int SisEmpty(Queue *q) {//��ť �˻� �Լ�
	return q->cnt == 0;
}

int Stop(Queue* q1, Queue* q2) {
	if (q1->cnt == 0) {//������� ��
		return -1;
	}
	else {//������� ���� ��
		Node* p = q1->front, *move=NULL;
		while (p->next != NULL) {//���Ұ� �ϳ� ���� ������
			move = p;
			p = p->next;
			push(q2, move->data);
			pop(q1);
		}
		int data = p->data;//������ ���� ������
		push(q2, p->data);
		pop(q1);//q1 �������
		//�ٽ� q2�� ���ҵ��� q1���� �Ű��ֱ�
		p = q2->front, move = NULL;
		while (p != NULL) {
			move = p;
			p = p->next;
			push(q1, move->data);
			pop(q2);
		}
		return data;
	}
}
void pushMillion(Queue* q1) {
	srand(time(NULL));
	for (int i = 0; i < 1000000; i++) {
		push(q1, rand()%90+10 );
	}
}

int Spop(Queue* q1, Queue* q2) {
	if (q1->cnt == 0) {//ť�� ������� ���
		return -1;
	}
	else {//������� ���� ��
		Node* p = q1->front, * move = NULL;
		while (p->next != NULL) {//���Ұ� �ϳ� ���� ������
			move = p;
			p = p->next;
			push(q2, move->data);
			pop(q1);
		}
		int data = p->data;//������ ���� ������
		////push(q2, p->data); q2�� push���ϰ� �׳� pop
		pop(q1);//q1 �������

		//�ٽ� q2�� ���ҵ��� q1���� �Ű��ֱ�
		p = q2->front, move = NULL;
		while (p != NULL) {
			move = p;
			p = p->next;
			push(q1, move->data);
			pop(q2);
		}
		return data;
	}
}
void quit(Queue* q) {
	Node* p = q->front, * remove=NULL;
	while (p != NULL) {
		remove = p;
		p = p->next;
		free(remove);
	}
}
int main() {
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	Queue *q1 = initialize();
	Queue *q2 = initialize();

	char order=0; int x=0, result=0;
	while (order != 'q') {
		scanf("%c", &order);
		switch (order) {
		case 'S':
			getchar();
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);

			result = SisEmpty(q1);

			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			if (result) 
				printf("Empty (%d), cputime = %.10lf\n", q1->cnt, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			else 
				printf("Nonempty (%d), cputime = %.10lf\n", q1->cnt, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			
			break;

		case 't':
			getchar();
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);

			result = Stop(q1, q2);

			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			if(result == -1) 
				printf("Empty Stack Exception!! (%d), cputime = %.10lf\n", q1->cnt, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			else
				printf("%d (%d), cputime = %.10lf\n",result, q1->cnt, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

			break;

		case 'p'://���� ��� ������ ���� ��ٷο�
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);

			while (scanf("%d", &x))//���Ŀ� ���� �ʴ� �Է� �� 0�� ��ȯ, �� ���� buffer�� �����ִ�.
				push(q1, x);

			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			printf("OK (%d), cputime = %.10lf\n", q1->cnt, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

			break;

		case 'P':
			getchar();
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);

			pushMillion(q1);

			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			printf("OK (%d), cputime = %.10lf\n", q1->cnt, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

			break;

		case 'o':
			getchar();
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);

			result = Spop(q1, q2);

			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			if (result == -1)
				printf("Empty Stack Exception!! (%d), cputime = %.10lf\n", q1->cnt, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			else
				printf("%d (%d), cputime = %.10lf\n", result, q1->cnt, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

			break;
		case 'q':
			quit(q1); quit(q2);
			free(q1); free(q2);
			break;
		}
	}
	

	return 0;
}