//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//
//void maxfind(int arr[], int i, int n, int result);
//
//int main() {
//	int N, * p, i = 0;
//	scanf("%d", &N);
//	p = (int*)malloc(sizeof(int) * N);
//	for (int i = 0; i < N; i++) {
//		scanf("%d", p + i);
//	}
//	int result = *p;
//	maxfind(p, i, N, result);
//	free(p);
//	return 0;
//}
//
//void maxfind(int arr[], int i, int n, int result) {
//	//printf("**");
//	if (i == n)
//		printf("%d", result);
//	else {
//		//printf("**");
//		if (arr[i] > result) result = arr[i];
//		maxfind(arr, ++i, n, result);
//	}
//}