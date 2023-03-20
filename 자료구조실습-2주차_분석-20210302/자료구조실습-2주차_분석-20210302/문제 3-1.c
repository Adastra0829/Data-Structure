//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>////////
//
//int* prefixAverages1(int X[], int n);
//int* prefixAverages2(int X[], int n);
//
//int main() {
//	int n,* p, * q, *arr;
//	scanf("%d", &n);
//	arr = (int *)malloc(sizeof(int) * n);
//
//	for (int i = 0; i < n; i++) {
//		scanf("%d", (arr+i));
//	}
//	/*for (int i = 0; i < n; i++) {
//		printf("%d ", *(arr + i));
//	}*/
//
//	p = prefixAverages1(arr, n);
//	for (int i = 0; i < n; i++) {
//		printf("%d ", p[i]);
//	}
//	printf("\n");
//	q = prefixAverages2(arr, n);
//	for (int i = 0; i < n; i++) {
//		printf("%d ", q[i]);
//	}
//
//	free(arr);
//	return 0;
//}
//
////A에 대한 해제는 어떻게 해야하는 거지??
//int* prefixAverages1(int X[], int n) {
//	int* A = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++) {
//		float sum = 0;
//		for (int j = 0; j <= i; j++) {
//			sum += X[j];
//		}
//		A[i] = (int)(sum / (i + 1)+0.5);
//	}
//	return A;
//}
//int* prefixAverages2(int X[], int n) {
//	int* A = (int*)malloc(sizeof(int) * n);
//	float sum = 0;
//	for (int i = 0; i < n; i++) {
//		sum += X[i];
//		A[i] = (int)(sum / (i + 1) + 0.5);
//	}
//	return A;
//}