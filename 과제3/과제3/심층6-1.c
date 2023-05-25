#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

int n = 0; //스택 사이즈 전역변수

typedef struct Node {
	int data;
	struct Node* next;
	int min;
}Node;

Node* getnode(int data) { 
	Node* node;
	node = (Node*)malloc(sizeof(Node));
	if (node == NULL) {
		printf("error"); return-1;
	}
	node->data = data;
	node->next = NULL;
	return node;
}

typedef struct Stack {
	Node* top;
}Stack;

Stack* initialize() { //스택 초기화
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (stack == NULL) {
		printf("error"); return-1;
	}
	stack->top = NULL;
	return stack;
}

void push(Stack* s, int data) {
	Node* node = getnode(data);
	if (n == 0) {
		node->min = data;
		s->top = node;
	}
	else {
		if (data < s->top->min) node->min = data;
		else node->min = s->top->min;
		node->next = s->top;
		s->top = node;
	}
	n++;
}

int pop(Stack* s) {
	if (n <= 0) {
		printf("error"); return-1;
	}
	int x = s->top->data;
	Node* p = s->top;
	s->top = s->top->next;
	free(p);
	n--;
	return x;
}

int findMin(Stack* s) {
	if (n <= 0) {
		printf("error"); return-1;
	}
	int x = s->top->min;
	return x;
}

void pushMillion(Stack* s) {
	srand(time(NULL));
	for (int i = 0; i < 1000000; i++) {
		push(s, rand() % 9000 + 1000);
	}
}

void popMillion(Stack* s) {
	if (n < 1000000) {
		printf("error"); return;
	}
	for (int i = 0; i < 1000000; i++) {
		pop(s);
	}
}

void quit(Stack* s) {
	Node* p = s->top;
	Node* remove = s->top;
	while (remove != NULL) {
		p = p->next;
		free(remove);
		remove = p;
	}
}

int main() {
	Stack* s = initialize();
	char order = 0;
	int num = 0, x;
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	while (order != 'q') {
		scanf("%c", &order); getchar();

		switch (order) {
		case 'p':
			scanf("%d", &num); getchar();

			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			push(s, num);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			printf("push %d (%d), cputime = %.10lf\n", num, n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			break;

		case 'P':
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			pushMillion(s);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			printf("pushMillion (%d), cputime = %.10lf\n", n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			break;

		case 'o':
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			x = pop(s);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			printf("pop %d (%d), cputime = %.10lf\n", x, n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			break;

		case 'O':
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			popMillion(s);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			printf("popMillion (%d), cputime = %.10lf\n", n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			break;

		case 'f':
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			x = findMin(s);
			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;

			printf("min %d (%d), cputime = %.10lf\n", x, n, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
			break;

		case 'q':
			quit(s);
			free(s);
			printf("(프로그램 종료)\n");
			break;

		}
	}


	return 0;
}