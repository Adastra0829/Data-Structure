//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h> //동적할당시 꼭 필요함 
//
//int main() {
//	int N;
//	scanf("%d", &N);
//
//	int* x = (int*)malloc(sizeof(int) * N);
//	int* y = (int*)malloc(sizeof(int) * N);
//
//
//	for (int i = 0; i < N; i++) {
//		scanf("%d", x + i);
//	}
//	for (int i = 0; i < N; i++) {
//		scanf("%d", y + i);
//	}
//
//
//	for (int i = 0; i < N; i++) {
//		printf(" %d", *(x + i) + *(y + N-1 - i));
//	}
//
//	free(x);
//	free(y);
//
//	return 0;
//}