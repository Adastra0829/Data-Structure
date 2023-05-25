#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* getnode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) printf("error");
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

void push(Stack* s, int data) {
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
	if (s->top == NULL) printf("error");
	return s->top->data;
}

int pop(Stack* s) {
	if (s->top == NULL) printf("error");
	Node* remove = s->top;
	int x = remove->data;
	s->top = s->top->next;
	free(remove);
	return x;
}

int isOperand(char o) {
	if (o == '!' || o == '*' || o == '/' || o == '+' || o == '-' || o == '>' || o == '<' || o == '&' || o == '|' ||o=='('||o==')') return 0; //not operand
	else return 1; //operand
}

int doOperator(char p, int b, int a) {
	int result;
	switch (p) {
	case '+':
		result = b + a;
		break;

	case'-':
		result = b - a;
		break;

	case'*':
		result = b * a;
		break;

	case'/':
		result = b / a;
		break;

	}
	return result;
}

int main() {
	Stack* s = initialize();
	int n;
	char input[101] = { 0 }, *p;
	scanf("%d", &n); 

	
	for (int i = 0; i < n; i++) {//n회만큼 수식 입력
		getchar();
		scanf("%s", input); 
		p = input;

		while (*p) {
			if (isOperand(*p)) {
				int c = *p - '0';
				push(s,c);
				p++;
			}
			else if (!isOperand(*p)) {
				int a = pop(s);
				int b = pop(s);
				push(s, doOperator(*p, b, a));
				p++;
			}
		}

		printf("%d\n", pop(s));
	}
	free(s);

	return 0;
}

/*


4 
53*2+63+2*+
234*+ 
72/3-42*+21*-
923*1+2*+


*/