//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>////////
//#include <time.h>
//#include <windows.h>
//
//int* prefixAverages1(int X[], int n);
//int* prefixAverages2(int X[], int n);
//
//int main() {
//	LARGE_INTEGER ticksPerSec;
//	LARGE_INTEGER start, end, diff;
//	srand(time(NULL));
//	int n, * p, * q, * arr;
//	scanf("%d", &n);
//	arr = (int*)malloc(sizeof(int) * n);
//
//	for (int i = 0; i < n; i++) {
//		*(arr + i) = rand() % 10000 + 1;
//	}
//	
//	QueryPerformanceFrequency(&ticksPerSec);
//	QueryPerformanceCounter(&start);
//	p = prefixAverages1(arr, n);////
//	QueryPerformanceCounter(&end);
//	diff.QuadPart = end.QuadPart - start.QuadPart;
//	printf("%.9fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart)*1000);
//
//
//	QueryPerformanceFrequency(&ticksPerSec);
//	QueryPerformanceCounter(&start);
//	q = prefixAverages2(arr, n);////
//	QueryPerformanceCounter(&end);
//	diff.QuadPart = end.QuadPart - start.QuadPart;
//	printf("%.9fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);
//
//
//	free(arr), free(p), free(q);
//	return 0;
//}
//
////a에 대한 해제는 어떻게 해야하는 거지??
//int* prefixAverages1(int X[], int n) {
//	int* A = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++) {
//		float sum = 0;
//		for (int j = 0; j <= i; j++) {
//			sum += X[j];
//		}
//		A[i] = (int)(sum / (i + 1) + 0.5);
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