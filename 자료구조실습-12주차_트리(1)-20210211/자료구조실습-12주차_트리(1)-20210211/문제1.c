#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int data;
	struct Node* left, * right;
}Node;

Node* getnode(int data) {
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}
int main() {
	Node* F[8];
	F[7] = getnode(80);
	F[6] = getnode(130);
	F[5] = getnode(120); 
	F[4] = getnode(90);
	F[3] = getnode(70);
	F[2] = getnode(50); 
	F[1] = getnode(30); 
	F[0] = getnode(20); 
	F[5]->left = F[6]; F[5]->right = F[7];
	F[2]->right = F[5];
	F[1]->left = F[3]; F[1]->right = F[4];
	F[0]->left = F[1]; F[0]->right = F[2];
	
	int x; scanf("%d", &x);
	if (x >= 1 && x <= 8) {
		printf("%d ", F[x - 1]->data);
		if (F[x - 1]->left != NULL) printf("%d ", F[x - 1]->left->data);
		if (F[x - 1]->right != NULL) printf("%d ", F[x - 1]->right->data);
	}
	else printf("-1");

	//메모리해제
	for (int i = 0; i < 8; i++)
		free(F[i]);

	return 0;
}