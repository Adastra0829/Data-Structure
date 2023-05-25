#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

void push(char* s, char c, int* t);
char pop(char* s, int* t);
void peek(char* s, int* t);
void duplicate(char* s, int* t);
void uprotate(char* s, int n, int* t);
void downrotate(char* s, int n, int* t);
void print(char* s, int* t);

int main() {
	int x, t = -1, n;//연산횟수, 인덱스, 로테이트 개수
	char order[6] = { 0 }, c, pp = 0;//명령어, 넣을 문자, pop해서 반환받을 문자
	scanf("%d", &n);//스택 크기

	char* s = (char*)malloc(sizeof(char) * n);//배열 동적할당
	if (s == null) 
		puts("fail");

	scanf("%d", &x);//연산횟수
	getchar();

	for (int i = 0; i < x; i++) {
		scanf("%s", order);
		if (strcmp(order, "pop") == 0) {
			pp =pop(s, &t);
		}
		else if (strcmp(order, "push") == 0) {getchar(); //getchar()안해서 애먹음
			scanf("%c", &c);
			push(s,c,&t);
		}
		else if (strcmp(order, "peek") == 0) {
			peek(s, &t);
		}
		else if (strcmp(order, "dup") == 0) {
			duplicate(s, &t);
		}
		else if (strcmp(order, "upr") == 0) {
			scanf("%d", &n);
			uprotate(s, n, &t);
		}
		else if (strcmp(order, "downr") == 0) {
			scanf("%d", &n);
			downrotate(s, n, &t);
		}
		else if (strcmp(order, "print") == 0) {
			print(s, &t);
		}
		getchar();
	}

	free(s);//메모리 해제
	return 0;
}

void push(char* s, char c, int* t) {
	if (*t == n - 1)
		printf("stack full\n");
	else {
		*t += 1;
		s[*t] = c;
	}
	return;
}
char pop(char* s, int* t) {
	if (*t == -1) {
		printf("stack empty\n"); return 0;
	}
	else {
		*t -= 1;
		return s[*t + 1];
	}
}
void peek(char* s, int* t) {
	if (*t == -1) {
		printf("stack empty\n"); return;
	}
	else {
		printf("%c\n", s[*t]); return;
	}
}
void duplicate(char* s, int* t) {
	if (*t == n - 1) {
		printf("stack full\n"); return;
	}
	else {
		*t += 1;
		s[*t] = s[*t - 1]; return;
	}
}
void uprotate(char* s, int n, int* t) {
	if (n > (*t + 1)) return;   //입력된 문자 개수보다 크면 동작하지 않게 
	char tmp;
	tmp = s[*t];
	for (int i = *t; i > *t - n + 1; i--) {
		s[i] = s[i - 1];
	}
	s[*t - n + 1] = tmp;
	return;
}
void downrotate(char* s, int n, int* t) {
	if (n > (*t + 1)) return;  //입력된 문자 개수보다 크면 동작하지 않게 
	char tmp;
	tmp = s[*t - n + 1];
	for (int i = *t - n + 1; i <= *t - 1; i++) {
		s[i] = s[i + 1];
	}
	s[*t] = tmp;
	return;
}
void print(char* s, int* t) {
	for (int i = *t; i >= 0; i--) {
		printf("%c", s[i]);
	}
	printf("\n");
	return;
}