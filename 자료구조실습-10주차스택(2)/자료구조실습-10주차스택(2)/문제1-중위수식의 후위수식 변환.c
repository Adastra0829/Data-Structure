#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
	char data;
	char *wh;
	struct Node* next;
}Node;

Node* getnode(char data) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) return -1;
	node->data = data;
	node->next = NULL;
	return node;
}

typedef struct Stack {
	Node* top;
}Stack;

Stack* initialize() {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	if (s == NULL) return -1;
	s->top = NULL;
	return s;
}

void push(Stack* s, char data) {
	Node* n = getnode(data);
	if (s->top == NULL) {
		s->top = n;
	}
	else {
		n->next = s->top;
		s->top = n;
	}
}

int top(Stack* s) {
	if (s->top == NULL) return -1;
	else return s->top->data;
}

void pop(Stack* s) {
	if (s->top == NULL) return -1;
	Node* p = s->top;
	s->top = s->top->next;
	free(p);
}

int isOperand(char o) {
	if (o == '!' || o == '*' || o == '/' || o == '+' || o == '-' || o == '>' || o == '<' || o == '&' || o == '|' || o == '(' || o == ')') return 0; //not operand
	else return 1; //operand
}

int priority(char* input, char* p, char o) {
	if (o == '!') return 6;
	else if (o == '+' || o == '-') {
		if ( input<p && !isOperand(*(p - 1)) && *(p - 1) != ')' && isOperand (*(p + 1))) return 6;
		// 2°�ڸ����� �չ��ڰ� )�� �ƴ� operator�̰� �������ڰ� operand�϶�
		// ���� ) �̰� ������ + �� -�� ���� �װ� ���׿�����
		if (input == p) return 6;
		//�Ǿպ��� + �� -
		else return 4;
	}
	else if (o == '*' || o == '/')return 5;
	else if (o == '>' || o == '<')return 3;
	else if (o == '&') return 2;
	else if (o == '|') return 1;
	else if (o == '(') return 0;
}


int main() {
	Stack* s = initialize();
	int n;
	char input[101] = { 0 }, * p;


	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", input); getchar();
		p = input;

		while (*p) {//���� ������


			if (isOperand(*p)) {
				printf("%c", *p);
				p++;
			}

			else if (*p == '(') {
				push(s, *p);
				s->top->wh = p;
				p++;
			}
			else if (*p == ')') {
				while (top(s) != '(') {
					if (top(s) == '&') {
						printf("&&");  pop(s);
					}
					else if (top(s) == '|') {
						printf("||");  pop(s);
					}
					else {
						printf("%c", top(s)); pop(s);
					}
				}
				pop(s);
				p++;
			}
			else {
				while (s->top != NULL && priority(input, p, *p) <= priority(input, s->top->wh, top(s))) {//������ �켱���� �߿�
					if (top(s) == '&') {
						printf("&&");  pop(s);
					}
					else if (top(s) == '|') {
						printf("||");  pop(s);
					}
					else {
						printf("%c", top(s)); pop(s);
					}
				}
				push(s, *p);
				s->top->wh = p;
				if (*p == '&' || *p == '|') p += 2;
				else p++;
			}


		}


		while (s->top != NULL) {
			if (top(s) == '&') {
				printf("&&");  pop(s);
			}
			else if (top(s) == '|') {
				printf("||");  pop(s);
			}
			else {
				printf("%c", top(s)); pop(s);
			}
		}


		printf("\n");

	}

	free(s);
	return 0;
}

/*



5
A*B+C+(D+E)*F
A+B*C
A/B-C+D*E-F*G
A+(B*C+D)*E
A&&B||C||!(E>F)


*/