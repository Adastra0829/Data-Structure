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

//함수 호출 전에 원소 개수를 체크해야함. 무조건 원소 있다는 가정 하에 만든 함수
int pop(Queue *q) { //일반 큐 pop 메쏘드
	Node* p = q->front; int x = q->front->data;
	if (p->next == NULL) {//원소가 하나일 때 
		q->front = q->rear = NULL;
	}
	else {//원소가 하나보다 많을 때
		q->front = q->front->next;
	}
	free(p); 
	q->cnt--;
	return x;
}

void push(Queue* q, int data) { //일반 큐 push 메쏘드
	Node* node = getnode(data);
	if (q->cnt==0) {//비어있던 큐
		q->front = q->rear = node;
	}
	else {//비어있지 않던 큐
		q->rear->next = node;
		q->rear = node;
	}
	q->cnt++;
	return;
}

int SisEmpty(Queue *q) {//빈큐 검사 함수
	return q->cnt == 0;
}

int Stop(Queue* q1, Queue* q2) {
	if (q1->cnt == 0) {//비어있을 때
		return -1;
	}
	else {//비어있지 않을 때
		Node* p = q1->front, *move=NULL;
		while (p->next != NULL) {//원소가 하나 남을 때까지
			move = p;
			p = p->next;
			push(q2, move->data);
			pop(q1);
		}
		int data = p->data;//마지막 원소 데이터
		push(q2, p->data);
		pop(q1);//q1 비어있음
		//다시 q2의 원소들을 q1으로 옮겨주기
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
	if (q1->cnt == 0) {//큐가 비어있을 경우
		return -1;
	}
	else {//비어있지 않을 때
		Node* p = q1->front, * move = NULL;
		while (p->next != NULL) {//원소가 하나 남을 때까지
			move = p;
			p = p->next;
			push(q2, move->data);
			pop(q1);
		}
		int data = p->data;//마지막 원소 데이터
		////push(q2, p->data); q2에 push안하고 그냥 pop
		pop(q1);//q1 비어있음

		//다시 q2의 원소들을 q1으로 옮겨주기
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

		case 'p'://숫자 몇개가 들어올지 몰라서 까다로움
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);

			while (scanf("%d", &x))//형식에 맞지 않는 입력 시 0을 반환, 그 값은 buffer에 남아있다.
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